/*
 * @Description: TM4C
 * @file: ${filename}
 * @brief: ${BRIEF}
 * @Version: 1.0
 * @Autor: PCL
 * @Date: 2023-07-30 12:12:51
 * @Code Reference: cbr wgj wx
 * @LastEditTime: 2023-07-30 12:23:28
 */
/**
 * @file user_queue.h
 * @author cbr (ran13245@outlook.com)
 * @brief 简易队列
 * @version 1.0
 * @date 2023-06-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>

#define Queue( TYPE ) \
typedef struct \
{ \
    TYPE* _queue; \
    unsigned short size; \
    unsigned short head; \
    unsigned short tail; \
}Queue_##TYPE 

Queue( uint8_t );
Queue( char );

#define Queue_init( TYPE ) \
void Queue_##TYPE##_init( Queue_##TYPE* _Queue,TYPE* _queue_address, unsigned short size){ \
    _Queue->_queue=_queue_address; \
    _Queue->size=size; \
    _Queue->head=_Queue->tail=0; \
}
static inline Queue_init(uint8_t)
static inline Queue_init(char)

/**
 * @brief 入队
 * 
 */
#define Queue_enqueue( TYPE ) \
void Queue_##TYPE##_enqueue(Queue_##TYPE* _Queue, TYPE data) { \
    _Queue->_queue[_Queue->tail] = data; \
    uint16_t next_tail = _Queue->tail + 1; \
    if(next_tail >= _Queue->size) \
        next_tail = 0; \
    if(next_tail == _Queue->head) { \
        if(_Queue->head >= _Queue->size - 1) \
            _Queue->head =0; \
        else \
            ++_Queue->head; \
    } \
    _Queue->tail=next_tail; \
}
static inline Queue_enqueue( uint8_t )
static inline Queue_enqueue( char )

/**
 * @brief 出队
 * 
 */
#define Queue_dequeue( TYPE ) \
TYPE Queue_##TYPE##_dequeue( Queue_##TYPE* _Queue ){ \
    if(_Queue->head == _Queue->tail){ \
        unsigned short pos = _Queue->head; \
        if( pos >=1 ) \
            pos -=1; \
        else \
            pos = _Queue->size-1;\
        return _Queue->_queue[pos]; \
    } \
    TYPE data=_Queue->_queue[_Queue->head]; \
    if( _Queue->head >= _Queue->size - 1 ) \
        _Queue->head=0;\
    else \
        ++_Queue->head; \
    return data; \
}
static inline Queue_dequeue( uint8_t )
static inline Queue_dequeue( char )

/**
 * @brief 计算队列中剩余元素个数
 * 
 */
#define Queue_count_remain( TYPE ) \
uint16_t Queue_##TYPE##_count_remain( Queue_##TYPE* _Queue ){ \
    if(_Queue->tail >= _Queue->head) \
        return _Queue->tail - _Queue->head;\
    else \
        return _Queue->tail + _Queue->size - _Queue->head; \
}
static inline Queue_count_remain(uint8_t)
static inline Queue_count_remain(char)
