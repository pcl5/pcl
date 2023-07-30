#include <stdint.h>
#include <math.h>
#include "filter.h"
#include "config.h"

biquadFilter_t imu_biquadFilter_a_x;
biquadFilter_t imu_biquadFilter_a_y;
biquadFilter_t imu_biquadFilter_a_z;
biquadFilter_t imu_biquadFilter_g_x;
biquadFilter_t imu_biquadFilter_g_y;
biquadFilter_t imu_biquadFilter_g_z;


void init_filter(void){
    biquadFilterInitLPF(&imu_biquadFilter_a_x, FILTER_FREQ_IMU_AX, TASK_ITV_IMU*1000);
    biquadFilterInitLPF(&imu_biquadFilter_a_y, FILTER_FREQ_IMU_AY, TASK_ITV_IMU*1000);
    biquadFilterInitLPF(&imu_biquadFilter_a_z, FILTER_FREQ_IMU_AZ, TASK_ITV_IMU*1000);
    biquadFilterInitLPF(&imu_biquadFilter_g_x, FILTER_FREQ_IMU_GX, TASK_ITV_IMU*1000);
    biquadFilterInitLPF(&imu_biquadFilter_g_y, FILTER_FREQ_IMU_GY, TASK_ITV_IMU*1000);
    biquadFilterInitLPF(&imu_biquadFilter_g_z, FILTER_FREQ_IMU_GZ, TASK_ITV_IMU*1000);
}


/**
 * @brief ˫�����˲���������
 * @param *filter �˲�������ز���
 * @param filterFreq �˲���������Ƶ��
 * @param sampleDeltaUs �˲����Ĳ���ϵ��
 * @param Q �˲�����Ʒ������
 * @param filterType �˲���������
 * @returns 
 */
static void biquadFilterInit(biquadFilter_t *filter, float filterFreq, uint32_t sampleDeltaUs, float Q, biquadFilterType_e filterType)
{
    // ���ò���Ƶ��
    const float sampleHz = 1 / ((float)sampleDeltaUs * 0.000001f);
    const float omega = 2 * M_PI_FLOAT * filterFreq / sampleHz;
    const float sn = sinf(omega);
    const float cs = cosf(omega);
    const float alpha = sn / (2 * Q);
	// �˲�����ϵ��
    float b0, b1, b2, a0, a1, a2;
	// �˲���������
    switch (filterType) 
		{
        default:
		// ��ͨ�˲���
        case FILTER_LPF:
            b0 = (1 - cs) / 2;
            b1 = 1 - cs;
            b2 = (1 - cs) / 2;
            a0 = 1 + alpha;
            a1 = -2 * cs;
            a2 = 1 - alpha;
            break;
		// ��ͨ�˲���
        case FILTER_NOTCH:
            b0 =  1;
            b1 = -2 * cs;
            b2 =  1;
            a0 =  1 + alpha;
            a1 = -2 * cs;
            a2 =  1 - alpha;
            break;
    }
    // Ԥ�ȼ���ϵ��
    filter->b0 = b0 / a0;
    filter->b1 = b1 / a0;
    filter->b2 = b2 / a0;
    filter->a1 = a1 / a0;
    filter->a2 = a2 / a0;
    // ���ʼ����
    filter->d1 = filter->d2 = 0;
}

/**
 * @author WeiXuan
 * @brief ��ʼ��˫�����˲���
 * @param *filter
 * @param filterFreq �˲���������Ƶ��
 * @param sampleDeltaUs �˲����Ĳ���ϵ��
 * @returns 
 */
void biquadFilterInitLPF(biquadFilter_t *filter, float filterFreq, uint32_t sampleDeltaUs)
{
    biquadFilterInit(filter, filterFreq, sampleDeltaUs, BIQUAD_Q, FILTER_LPF);
}

/**
 * @brief Ӧ��˫�����˲���
 * @param *filter �˲�������ز���
 * @param input �����������
 * @returns 
 */
float biquadFilterApply(biquadFilter_t *filter, float input)
{
    const float result = filter->b0 * input + filter->d1;
    filter->d1 = filter->b1 * input - filter->a1 * result + filter->d2;
    filter->d2 = filter->b2 * input - filter->a2 * result;
    return result;
}
