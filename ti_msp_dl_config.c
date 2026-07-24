/*
 * Copyright (c) 2023, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.c =============
 *  Configured MSPM0 DriverLib module definitions
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */

#include "ti_msp_dl_config.h"

DL_TimerA_backupConfig gmotor_pwmBackup;
DL_TimerG_backupConfig gencoder_qeiBackup;
DL_TimerG_backupConfig gIMU_TIMERBackup;
DL_TimerA_backupConfig gPID_TIMERBackup;

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform any initialization needed before using any board APIs
 */
SYSCONFIG_WEAK void SYSCFG_DL_init(void)
{
    SYSCFG_DL_initPower();
    SYSCFG_DL_GPIO_init();
    /* Module-Specific Initializations*/
    SYSCFG_DL_SYSCTL_init();
    SYSCFG_DL_motor_pwm_init();
    SYSCFG_DL_encoder_qei_init();
    SYSCFG_DL_IMU_TIMER_init();
    SYSCFG_DL_ENCODER_TIMER_init();
    SYSCFG_DL_PID_TIMER_init();
    SYSCFG_DL_OLED_init();
    SYSCFG_DL_imu660rb_init();
    SYSCFG_DL_Debug_UART_init();
    SYSCFG_DL_E220_init();
    SYSCFG_DL_SYSTICK_init();
    /* Ensure backup structures have no valid state */
	gmotor_pwmBackup.backupRdy 	= false;
	gencoder_qeiBackup.backupRdy 	= false;
	gIMU_TIMERBackup.backupRdy 	= false;
	gPID_TIMERBackup.backupRdy 	= false;


}
/*
 * User should take care to save and restore register configuration in application.
 * See Retention Configuration section for more details.
 */
SYSCONFIG_WEAK bool SYSCFG_DL_saveConfiguration(void)
{
    bool retStatus = true;

	retStatus &= DL_TimerA_saveConfiguration(motor_pwm_INST, &gmotor_pwmBackup);
	retStatus &= DL_TimerG_saveConfiguration(encoder_qei_INST, &gencoder_qeiBackup);
	retStatus &= DL_TimerG_saveConfiguration(IMU_TIMER_INST, &gIMU_TIMERBackup);
	retStatus &= DL_TimerA_saveConfiguration(PID_TIMER_INST, &gPID_TIMERBackup);

    return retStatus;
}


SYSCONFIG_WEAK bool SYSCFG_DL_restoreConfiguration(void)
{
    bool retStatus = true;

	retStatus &= DL_TimerA_restoreConfiguration(motor_pwm_INST, &gmotor_pwmBackup, false);
	retStatus &= DL_TimerG_restoreConfiguration(encoder_qei_INST, &gencoder_qeiBackup, false);
	retStatus &= DL_TimerG_restoreConfiguration(IMU_TIMER_INST, &gIMU_TIMERBackup, false);
	retStatus &= DL_TimerA_restoreConfiguration(PID_TIMER_INST, &gPID_TIMERBackup, false);

    return retStatus;
}

SYSCONFIG_WEAK void SYSCFG_DL_initPower(void)
{
    DL_GPIO_reset(GPIOA);
    DL_GPIO_reset(GPIOB);
    DL_TimerA_reset(motor_pwm_INST);
    DL_TimerG_reset(encoder_qei_INST);
    DL_TimerG_reset(IMU_TIMER_INST);
    DL_TimerG_reset(ENCODER_TIMER_INST);
    DL_TimerA_reset(PID_TIMER_INST);
    DL_I2C_reset(OLED_INST);
    DL_I2C_reset(imu660rb_INST);
    DL_UART_Main_reset(Debug_UART_INST);
    DL_UART_Main_reset(E220_INST);


    DL_GPIO_enablePower(GPIOA);
    DL_GPIO_enablePower(GPIOB);
    DL_TimerA_enablePower(motor_pwm_INST);
    DL_TimerG_enablePower(encoder_qei_INST);
    DL_TimerG_enablePower(IMU_TIMER_INST);
    DL_TimerG_enablePower(ENCODER_TIMER_INST);
    DL_TimerA_enablePower(PID_TIMER_INST);
    DL_I2C_enablePower(OLED_INST);
    DL_I2C_enablePower(imu660rb_INST);
    DL_UART_Main_enablePower(Debug_UART_INST);
    DL_UART_Main_enablePower(E220_INST);

    delay_cycles(POWER_STARTUP_DELAY);
}

SYSCONFIG_WEAK void SYSCFG_DL_GPIO_init(void)
{

    DL_GPIO_initPeripheralAnalogFunction(GPIO_HFXIN_IOMUX);
    DL_GPIO_initPeripheralAnalogFunction(GPIO_HFXOUT_IOMUX);

    DL_GPIO_initPeripheralOutputFunction(GPIO_motor_pwm_C0_IOMUX,GPIO_motor_pwm_C0_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_motor_pwm_C0_PORT, GPIO_motor_pwm_C0_PIN);
    DL_GPIO_initPeripheralOutputFunction(GPIO_motor_pwm_C1_IOMUX,GPIO_motor_pwm_C1_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_motor_pwm_C1_PORT, GPIO_motor_pwm_C1_PIN);

    DL_GPIO_initPeripheralInputFunction(GPIO_encoder_qei_PHA_IOMUX,GPIO_encoder_qei_PHA_IOMUX_FUNC);
    DL_GPIO_initPeripheralInputFunction(GPIO_encoder_qei_PHB_IOMUX,GPIO_encoder_qei_PHB_IOMUX_FUNC);

    DL_GPIO_initPeripheralInputFunctionFeatures(GPIO_OLED_IOMUX_SDA,
        GPIO_OLED_IOMUX_SDA_FUNC, DL_GPIO_INVERSION_DISABLE,
        DL_GPIO_RESISTOR_NONE, DL_GPIO_HYSTERESIS_DISABLE,
        DL_GPIO_WAKEUP_DISABLE);
    DL_GPIO_initPeripheralInputFunctionFeatures(GPIO_OLED_IOMUX_SCL,
        GPIO_OLED_IOMUX_SCL_FUNC, DL_GPIO_INVERSION_DISABLE,
        DL_GPIO_RESISTOR_NONE, DL_GPIO_HYSTERESIS_DISABLE,
        DL_GPIO_WAKEUP_DISABLE);
    DL_GPIO_enableHiZ(GPIO_OLED_IOMUX_SDA);
    DL_GPIO_enableHiZ(GPIO_OLED_IOMUX_SCL);
    DL_GPIO_initPeripheralInputFunctionFeatures(GPIO_imu660rb_IOMUX_SDA,
        GPIO_imu660rb_IOMUX_SDA_FUNC, DL_GPIO_INVERSION_DISABLE,
        DL_GPIO_RESISTOR_NONE, DL_GPIO_HYSTERESIS_DISABLE,
        DL_GPIO_WAKEUP_DISABLE);
    DL_GPIO_initPeripheralInputFunctionFeatures(GPIO_imu660rb_IOMUX_SCL,
        GPIO_imu660rb_IOMUX_SCL_FUNC, DL_GPIO_INVERSION_DISABLE,
        DL_GPIO_RESISTOR_NONE, DL_GPIO_HYSTERESIS_DISABLE,
        DL_GPIO_WAKEUP_DISABLE);
    DL_GPIO_enableHiZ(GPIO_imu660rb_IOMUX_SDA);
    DL_GPIO_enableHiZ(GPIO_imu660rb_IOMUX_SCL);

    DL_GPIO_initPeripheralOutputFunction(
        GPIO_Debug_UART_IOMUX_TX, GPIO_Debug_UART_IOMUX_TX_FUNC);
    DL_GPIO_initPeripheralInputFunction(
        GPIO_Debug_UART_IOMUX_RX, GPIO_Debug_UART_IOMUX_RX_FUNC);
    DL_GPIO_initPeripheralOutputFunction(
        GPIO_E220_IOMUX_TX, GPIO_E220_IOMUX_TX_FUNC);
    DL_GPIO_initPeripheralInputFunction(
        GPIO_E220_IOMUX_RX, GPIO_E220_IOMUX_RX_FUNC);

    DL_GPIO_initDigitalOutput(buzzer_gpio_PIN_0_IOMUX);

    DL_GPIO_initDigitalOutput(debug_led_gpio_led_1_IOMUX);

    DL_GPIO_initDigitalInputFeatures(key_gpio_key_center_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(key_gpio_ket_rihgt_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(key_gpio_key_left_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(key_gpio_key_up_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(key_gpio_key_down_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalOutput(motor_dir_AIN1_IOMUX);

    DL_GPIO_initDigitalOutput(motor_dir_AIN2_IOMUX);

    DL_GPIO_initDigitalOutput(motor_dir_BIN1_IOMUX);

    DL_GPIO_initDigitalOutput(motor_dir_BIN2_IOMUX);

    DL_GPIO_initDigitalInputFeatures(track_gpio_track1_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(track_gpio_track2_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(track_gpio_track3_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(track_gpio_track4_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(track_gpio_track5_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(track_gpio_track6_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(track_gpio_track7_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalOutput(debug_led_gpio_led2_IOMUX);

    DL_GPIO_setPins(GPIOA, motor_dir_BIN1_PIN |
		motor_dir_BIN2_PIN);
    DL_GPIO_enableOutput(GPIOA, motor_dir_BIN1_PIN |
		motor_dir_BIN2_PIN);
    DL_GPIO_clearPins(GPIOB, buzzer_gpio_PIN_0_PIN |
		debug_led_gpio_led_1_PIN |
		debug_led_gpio_led2_PIN);
    DL_GPIO_setPins(GPIOB, motor_dir_AIN1_PIN |
		motor_dir_AIN2_PIN);
    DL_GPIO_enableOutput(GPIOB, buzzer_gpio_PIN_0_PIN |
		debug_led_gpio_led_1_PIN |
		motor_dir_AIN1_PIN |
		motor_dir_AIN2_PIN |
		debug_led_gpio_led2_PIN);

}


static const DL_SYSCTL_SYSPLLConfig gSYSPLLConfig = {
    .inputFreq              = DL_SYSCTL_SYSPLL_INPUT_FREQ_32_48_MHZ,
	.rDivClk2x              = 1,
	.rDivClk1               = 0,
	.rDivClk0               = 0,
	.enableCLK2x            = DL_SYSCTL_SYSPLL_CLK2X_DISABLE,
	.enableCLK1             = DL_SYSCTL_SYSPLL_CLK1_DISABLE,
	.enableCLK0             = DL_SYSCTL_SYSPLL_CLK0_ENABLE,
	.sysPLLMCLK             = DL_SYSCTL_SYSPLL_MCLK_CLK0,
	.sysPLLRef              = DL_SYSCTL_SYSPLL_REF_HFCLK,
	.qDiv                   = 3,
	.pDiv                   = DL_SYSCTL_SYSPLL_PDIV_1
};
SYSCONFIG_WEAK void SYSCFG_DL_SYSCTL_init(void)
{

	//Low Power Mode is configured to be SLEEP0
    DL_SYSCTL_setBORThreshold(DL_SYSCTL_BOR_THRESHOLD_LEVEL_0);
    DL_SYSCTL_setFlashWaitState(DL_SYSCTL_FLASH_WAIT_STATE_2);

    
	DL_SYSCTL_setSYSOSCFreq(DL_SYSCTL_SYSOSC_FREQ_BASE);
	/* Set default configuration */
	DL_SYSCTL_disableHFXT();
	DL_SYSCTL_disableSYSPLL();
    DL_SYSCTL_setHFCLKSourceHFXTParams(DL_SYSCTL_HFXT_RANGE_32_48_MHZ,10, true);
    DL_SYSCTL_configSYSPLL((DL_SYSCTL_SYSPLLConfig *) &gSYSPLLConfig);
    DL_SYSCTL_setULPCLKDivider(DL_SYSCTL_ULPCLK_DIV_2);
    DL_SYSCTL_enableMFCLK();
    DL_SYSCTL_setMCLKSource(SYSOSC, HSCLK, DL_SYSCTL_HSCLK_SOURCE_SYSPLL);

}


/*
 * Timer clock configuration to be sourced by  / 8 (10000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   10000000 Hz = 10000000 Hz / (8 * (0 + 1))
 */
static const DL_TimerA_ClockConfig gmotor_pwmClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_8,
    .prescale = 0U
};

static const DL_TimerA_PWMConfig gmotor_pwmConfig = {
    .pwmMode = DL_TIMER_PWM_MODE_EDGE_ALIGN,
    .period = 10001,
    .isTimerWithFourCC = false,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_motor_pwm_init(void) {

    DL_TimerA_setClockConfig(
        motor_pwm_INST, (DL_TimerA_ClockConfig *) &gmotor_pwmClockConfig);

    DL_TimerA_initPWMMode(
        motor_pwm_INST, (DL_TimerA_PWMConfig *) &gmotor_pwmConfig);

    // Set Counter control to the smallest CC index being used
    DL_TimerA_setCounterControl(motor_pwm_INST,DL_TIMER_CZC_CCCTL0_ZCOND,DL_TIMER_CAC_CCCTL0_ACOND,DL_TIMER_CLC_CCCTL0_LCOND);

    DL_TimerA_setCaptureCompareOutCtl(motor_pwm_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_ENABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERA_CAPTURE_COMPARE_0_INDEX);

    DL_TimerA_setCaptCompUpdateMethod(motor_pwm_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERA_CAPTURE_COMPARE_0_INDEX);
    DL_TimerA_setCaptureCompareValue(motor_pwm_INST, 10001, DL_TIMER_CC_0_INDEX);

    DL_TimerA_setCaptureCompareOutCtl(motor_pwm_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_ENABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERA_CAPTURE_COMPARE_1_INDEX);

    DL_TimerA_setCaptCompUpdateMethod(motor_pwm_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERA_CAPTURE_COMPARE_1_INDEX);
    DL_TimerA_setCaptureCompareValue(motor_pwm_INST, 10001, DL_TIMER_CC_1_INDEX);

    DL_TimerA_enableClock(motor_pwm_INST);


    
    DL_TimerA_setCCPDirection(motor_pwm_INST , DL_TIMER_CC0_OUTPUT | DL_TIMER_CC1_OUTPUT );


}


static const DL_TimerG_ClockConfig gencoder_qeiClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_8,
    .prescale = 0U
};


SYSCONFIG_WEAK void SYSCFG_DL_encoder_qei_init(void) {

    DL_TimerG_setClockConfig(
        encoder_qei_INST, (DL_TimerG_ClockConfig *) &gencoder_qeiClockConfig);

    DL_TimerG_configQEI(encoder_qei_INST, DL_TIMER_QEI_MODE_2_INPUT,
        DL_TIMER_CC_INPUT_INV_NOINVERT, DL_TIMER_CC_0_INDEX);
    DL_TimerG_configQEI(encoder_qei_INST, DL_TIMER_QEI_MODE_2_INPUT,
        DL_TIMER_CC_INPUT_INV_NOINVERT, DL_TIMER_CC_1_INDEX);
    DL_TimerG_setLoadValue(encoder_qei_INST, 65535);
    DL_TimerG_enableClock(encoder_qei_INST);
    DL_TimerG_startCounter(encoder_qei_INST);
}



/*
 * Timer clock configuration to be sourced by BUSCLK /  (10000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   100000 Hz = 10000000 Hz / (8 * (99 + 1))
 */
static const DL_TimerG_ClockConfig gIMU_TIMERClockConfig = {
    .clockSel    = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_8,
    .prescale    = 99U,
};

/*
 * Timer load value (where the counter starts from) is calculated as (timerPeriod * timerClockFreq) - 1
 * IMU_TIMER_INST_LOAD_VALUE = (5ms * 100000 Hz) - 1
 */
static const DL_TimerG_TimerConfig gIMU_TIMERTimerConfig = {
    .period     = IMU_TIMER_INST_LOAD_VALUE,
    .timerMode  = DL_TIMER_TIMER_MODE_PERIODIC,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_IMU_TIMER_init(void) {

    DL_TimerG_setClockConfig(IMU_TIMER_INST,
        (DL_TimerG_ClockConfig *) &gIMU_TIMERClockConfig);

    DL_TimerG_initTimerMode(IMU_TIMER_INST,
        (DL_TimerG_TimerConfig *) &gIMU_TIMERTimerConfig);
    DL_TimerG_enableInterrupt(IMU_TIMER_INST , DL_TIMERG_INTERRUPT_ZERO_EVENT);
	NVIC_SetPriority(IMU_TIMER_INST_INT_IRQN, 1);
    DL_TimerG_enableClock(IMU_TIMER_INST);





}

/*
 * Timer clock configuration to be sourced by BUSCLK /  (5000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   50000 Hz = 5000000 Hz / (8 * (99 + 1))
 */
static const DL_TimerG_ClockConfig gENCODER_TIMERClockConfig = {
    .clockSel    = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_8,
    .prescale    = 99U,
};

/*
 * Timer load value (where the counter starts from) is calculated as (timerPeriod * timerClockFreq) - 1
 * ENCODER_TIMER_INST_LOAD_VALUE = (5ms * 50000 Hz) - 1
 */
static const DL_TimerG_TimerConfig gENCODER_TIMERTimerConfig = {
    .period     = ENCODER_TIMER_INST_LOAD_VALUE,
    .timerMode  = DL_TIMER_TIMER_MODE_PERIODIC,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_ENCODER_TIMER_init(void) {

    DL_TimerG_setClockConfig(ENCODER_TIMER_INST,
        (DL_TimerG_ClockConfig *) &gENCODER_TIMERClockConfig);

    DL_TimerG_initTimerMode(ENCODER_TIMER_INST,
        (DL_TimerG_TimerConfig *) &gENCODER_TIMERTimerConfig);
    DL_TimerG_enableInterrupt(ENCODER_TIMER_INST , DL_TIMERG_INTERRUPT_ZERO_EVENT);
	NVIC_SetPriority(ENCODER_TIMER_INST_INT_IRQN, 1);
    DL_TimerG_enableClock(ENCODER_TIMER_INST);





}

/*
 * Timer clock configuration to be sourced by BUSCLK /  (10000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   100000 Hz = 10000000 Hz / (8 * (99 + 1))
 */
static const DL_TimerA_ClockConfig gPID_TIMERClockConfig = {
    .clockSel    = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_8,
    .prescale    = 99U,
};

/*
 * Timer load value (where the counter starts from) is calculated as (timerPeriod * timerClockFreq) - 1
 * PID_TIMER_INST_LOAD_VALUE = (50ms * 100000 Hz) - 1
 */
static const DL_TimerA_TimerConfig gPID_TIMERTimerConfig = {
    .period     = PID_TIMER_INST_LOAD_VALUE,
    .timerMode  = DL_TIMER_TIMER_MODE_PERIODIC,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_PID_TIMER_init(void) {

    DL_TimerA_setClockConfig(PID_TIMER_INST,
        (DL_TimerA_ClockConfig *) &gPID_TIMERClockConfig);

    DL_TimerA_initTimerMode(PID_TIMER_INST,
        (DL_TimerA_TimerConfig *) &gPID_TIMERTimerConfig);
    DL_TimerA_enableInterrupt(PID_TIMER_INST , DL_TIMERA_INTERRUPT_ZERO_EVENT);
	NVIC_SetPriority(PID_TIMER_INST_INT_IRQN, 2);
    DL_TimerA_enableClock(PID_TIMER_INST);





}


static const DL_I2C_ClockConfig gOLEDClockConfig = {
    .clockSel = DL_I2C_CLOCK_BUSCLK,
    .divideRatio = DL_I2C_CLOCK_DIVIDE_1,
};

SYSCONFIG_WEAK void SYSCFG_DL_OLED_init(void) {

    DL_I2C_setClockConfig(OLED_INST,
        (DL_I2C_ClockConfig *) &gOLEDClockConfig);
    DL_I2C_setAnalogGlitchFilterPulseWidth(OLED_INST,
        DL_I2C_ANALOG_GLITCH_FILTER_WIDTH_50NS);
    DL_I2C_enableAnalogGlitchFilter(OLED_INST);

    /* Configure Controller Mode */
    DL_I2C_resetControllerTransfer(OLED_INST);
    /* Set frequency to 100000 Hz*/
    DL_I2C_setTimerPeriod(OLED_INST, 39);
    DL_I2C_setControllerTXFIFOThreshold(OLED_INST, DL_I2C_TX_FIFO_LEVEL_EMPTY);
    DL_I2C_setControllerRXFIFOThreshold(OLED_INST, DL_I2C_RX_FIFO_LEVEL_BYTES_1);
    DL_I2C_enableControllerClockStretching(OLED_INST);


    /* Enable module */
    DL_I2C_enableController(OLED_INST);


}
static const DL_I2C_ClockConfig gimu660rbClockConfig = {
    .clockSel = DL_I2C_CLOCK_BUSCLK,
    .divideRatio = DL_I2C_CLOCK_DIVIDE_1,
};

SYSCONFIG_WEAK void SYSCFG_DL_imu660rb_init(void) {

    DL_I2C_setClockConfig(imu660rb_INST,
        (DL_I2C_ClockConfig *) &gimu660rbClockConfig);
    DL_I2C_setAnalogGlitchFilterPulseWidth(imu660rb_INST,
        DL_I2C_ANALOG_GLITCH_FILTER_WIDTH_50NS);
    DL_I2C_enableAnalogGlitchFilter(imu660rb_INST);

    /* Configure Controller Mode */
    DL_I2C_resetControllerTransfer(imu660rb_INST);
    /* Set frequency to 400000 Hz*/
    DL_I2C_setTimerPeriod(imu660rb_INST, 9);
    DL_I2C_setControllerTXFIFOThreshold(imu660rb_INST, DL_I2C_TX_FIFO_LEVEL_EMPTY);
    DL_I2C_setControllerRXFIFOThreshold(imu660rb_INST, DL_I2C_RX_FIFO_LEVEL_BYTES_1);
    DL_I2C_enableControllerClockStretching(imu660rb_INST);


    /* Enable module */
    DL_I2C_enableController(imu660rb_INST);


}


static const DL_UART_Main_ClockConfig gDebug_UARTClockConfig = {
    .clockSel    = DL_UART_MAIN_CLOCK_MFCLK,
    .divideRatio = DL_UART_MAIN_CLOCK_DIVIDE_RATIO_1
};

static const DL_UART_Main_Config gDebug_UARTConfig = {
    .mode        = DL_UART_MAIN_MODE_NORMAL,
    .direction   = DL_UART_MAIN_DIRECTION_TX_RX,
    .flowControl = DL_UART_MAIN_FLOW_CONTROL_NONE,
    .parity      = DL_UART_MAIN_PARITY_NONE,
    .wordLength  = DL_UART_MAIN_WORD_LENGTH_8_BITS,
    .stopBits    = DL_UART_MAIN_STOP_BITS_ONE
};

SYSCONFIG_WEAK void SYSCFG_DL_Debug_UART_init(void)
{
    DL_UART_Main_setClockConfig(Debug_UART_INST, (DL_UART_Main_ClockConfig *) &gDebug_UARTClockConfig);

    DL_UART_Main_init(Debug_UART_INST, (DL_UART_Main_Config *) &gDebug_UARTConfig);
    /*
     * Configure baud rate by setting oversampling and baud rate divisors.
     *  Target baud rate: 115200
     *  Actual baud rate: 115107.91
     */
    DL_UART_Main_setOversampling(Debug_UART_INST, DL_UART_OVERSAMPLING_RATE_16X);
    DL_UART_Main_setBaudRateDivisor(Debug_UART_INST, Debug_UART_IBRD_4_MHZ_115200_BAUD, Debug_UART_FBRD_4_MHZ_115200_BAUD);


    /* Configure Interrupts */
    DL_UART_Main_enableInterrupt(Debug_UART_INST,
                                 DL_UART_MAIN_INTERRUPT_RX);
    /* Setting the Interrupt Priority */
    NVIC_SetPriority(Debug_UART_INST_INT_IRQN, 3);


    DL_UART_Main_enable(Debug_UART_INST);
}

static const DL_UART_Main_ClockConfig gE220ClockConfig = {
    .clockSel    = DL_UART_MAIN_CLOCK_MFCLK,
    .divideRatio = DL_UART_MAIN_CLOCK_DIVIDE_RATIO_1
};

static const DL_UART_Main_Config gE220Config = {
    .mode        = DL_UART_MAIN_MODE_NORMAL,
    .direction   = DL_UART_MAIN_DIRECTION_TX_RX,
    .flowControl = DL_UART_MAIN_FLOW_CONTROL_NONE,
    .parity      = DL_UART_MAIN_PARITY_NONE,
    .wordLength  = DL_UART_MAIN_WORD_LENGTH_8_BITS,
    .stopBits    = DL_UART_MAIN_STOP_BITS_ONE
};

SYSCONFIG_WEAK void SYSCFG_DL_E220_init(void)
{
    DL_UART_Main_setClockConfig(E220_INST, (DL_UART_Main_ClockConfig *) &gE220ClockConfig);

    DL_UART_Main_init(E220_INST, (DL_UART_Main_Config *) &gE220Config);
    /*
     * Configure baud rate by setting oversampling and baud rate divisors.
     *  Target baud rate: 115200
     *  Actual baud rate: 115107.91
     */
    DL_UART_Main_setOversampling(E220_INST, DL_UART_OVERSAMPLING_RATE_16X);
    DL_UART_Main_setBaudRateDivisor(E220_INST, E220_IBRD_4_MHZ_115200_BAUD, E220_FBRD_4_MHZ_115200_BAUD);


    /* Configure Interrupts */
    DL_UART_Main_enableInterrupt(E220_INST,
                                 DL_UART_MAIN_INTERRUPT_RX);
    /* Setting the Interrupt Priority */
    NVIC_SetPriority(E220_INST_INT_IRQN, 1);


    DL_UART_Main_enable(E220_INST);
}

SYSCONFIG_WEAK void SYSCFG_DL_SYSTICK_init(void)
{
    /*
     * Initializes the SysTick period to 1.00 ms,
     * enables the interrupt, and starts the SysTick Timer
     */
    DL_SYSTICK_config(80000);
}

