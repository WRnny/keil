#ifndef MAIN_H
#define MAIN_H

#include "ti_msp_dl_config.h"

#define WR_TICK_FREQ_DEFAULT 1 // SysTick中断服务函数的定时器频率1kHz
#define WR_MAX_Delay 0xFFFFFFFFU // 最大等待时间

/**
 * @brief 一个任务调度器的宏定义，用于周期性的任务调度。
 * @param task_id 任务的ID。
 * @param dt 任务的周期，单位为毫秒。
 * 
 */
#define WR_TASK_PERIODIC(task_id ,dt) \
        do { \
            static uint32_t task_next_time_##task_id = 0;  \
            uint32_t task_now_time_##task_id = WR_GetTick();  \
            if ((int32_t)(task_now_time_##task_id - task_next_time_##task_id) < 0) return;  \
            task_next_time_##task_id = WR_GetTick() + (uint32_t)(dt); \
        } while(0) // 毫秒级定时器



/**
 * @brief 这个函数用于传递一个全局变量uwTick，作为程序运行时间的基准
 * 
 * @note 默认每1ms执行一次Systick中断服务程序中递增一次
 * 
 */
void WR_IncTik(void);

/**
 * @brief 提供以毫秒为单位的计时值，获取当前程序运行时间
 * 
 * @return uint32_t 
 */
uint32_t WR_GetTick(void);

/**
 * @brief 提供以毫秒为单位的延时功能
 * 
 * @param Delay 
 */
void WR_Delay(uint32_t Delay);


#define USE_FULL_ASSERT 1

#ifdef  USE_FULL_ASSERT
#define assert_param(expr) (!(expr) ? (void)0U : assert_failed(expr))
/* Exported functions ------------------------------------------------------- */
void assert_failed(uint32_t error_code);
typedef enum{
    I2C_PASS = 0U,
    I2C_DATASIZE_ERROR = 1U
}I2C_assert;

#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

#ifdef __cplusplus
}
#endif

#endif // MAIN_H
