#ifndef __FILTER_H_
#define __FILTER_H_

#include <stdint.h>

#define M_PI_FLOAT  3.14159265358979323846f    
// 二阶巴特沃斯滤波器的品质因数Q
#define BIQUAD_Q (1.0f / sqrtf(2.0f))   

// 滤波器的种类
typedef enum 
{
	FILTER_LPF,						// 低通滤波器
	FILTER_NOTCH					// 带通滤波器
}biquadFilterType_e;

// IIR 滤波器的系数
typedef struct biquadFilter_s 
{
	float b0, b1, b2, a1, a2;
	float d1, d2;
}biquadFilter_t;

extern biquadFilter_t imu_biquadFilter_a_x;
extern biquadFilter_t imu_biquadFilter_a_y;
extern biquadFilter_t imu_biquadFilter_a_z;
extern biquadFilter_t imu_biquadFilter_g_x;
extern biquadFilter_t imu_biquadFilter_g_y;
extern biquadFilter_t imu_biquadFilter_g_z;

void init_filter(void);
float Filter_Apply_IMU(float input);

void biquadFilterInitLPF(biquadFilter_t *filter, float filterFreq, uint32_t sampleDeltaUs);
float biquadFilterApply(biquadFilter_t *filter, float input);

#endif
