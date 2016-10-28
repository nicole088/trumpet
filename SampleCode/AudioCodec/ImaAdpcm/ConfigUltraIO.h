/**************************************************************************//**
 * @file     ConfigUltraIO.h
 * @version  V1.00
 * $Revision: 1 $
 * $Date: 14/09/10 03:00p $
 * @brief    Header file of UltraIO configuration.
 *           This file could be generated by NuKeilIDE tool. 
 *
 * Copyright (C) 2014 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#ifndef _CONFIGULTRAIO_H_
#define _CONFIGULTRAIO_H_

#include "Platform.h"
#include "ConfigApp.h"

//%{CodeGen_Block_Start}

/*---------------------------------------------------------------------------------------------------------*/
/* Configurations of UltraIO                                                                               */
/*---------------------------------------------------------------------------------------------------------*/
#define ULTRAIO_TOTAL_CURVE_COUNT		2		// The count of enabled curves(0-32)
#define ULTRAIO_FW_CURVE_COUNT			1 		// The count of enabled curves which use FW PWM(0-32)
#define ULTRAIO_USE_PORTA				0		// 1: port A is used to output curve, 0: port A is not used to output curve
#define ULTRAIO_USE_PORTB				1		// 1: port A is used to output curve, 0: port A is not used to output curve

#define ULTRAIO_LAST_CURVE_NO  			2		// 1-32, the last enabled curve		
#define ULTRAIO_CTRL_CURVE				0		// 1: open control enabled/disabled curve function, 0: close control enabled/disabled curve function.
#define ULTRAIO_CTRL_OUTPUTPIN			0		// 1: open control output pin function, 0: close control output pin function.

#define ULTRAIO_MAX_RESOLUATION			64		// 1/4/16/64/128/256, max resolution of curve.
#define ULTRAIO_FREQUENCY	 			50		// 50-100, the pwm frequency
#define ULTRAIO_HW_PWM_MAX_COUNT		2		// Hardware support max pwm count.

/*---------------------------------------------------------------------------------------------------------*/
/* Configurations of Curve.                                                                                */
/*---------------------------------------------------------------------------------------------------------*/
#define ULTRAIO_CURVE_MAP()			\
const uint8_t g_u8UltraIOCurveMap[ULTRAIO_LAST_CURVE_NO]=\
{0, 1}; 
// curve map to ULTRAIO_CURVE_SETTINGS table. 
// if curve disable, value = ULTRAIO_CURVE_NO_CREATED

// define structure of ultraio setting.
typedef struct
{
	uint8_t	u8Resoluation;		// 1 byte, this curve resoluation
	uint8_t	u8Type:1;			// 1 bits, PWM counter type(E_ULTRAIO_PWM_TYPE)
	uint8_t u8PwmIdx:4;		   	// 4 bits, identify which HW PWM	
}S_ULTRAIO_SETTING;			 	// total 2 bytes.


#define ULTRAIO_CURVE_SETTINGS() \
const S_ULTRAIO_SETTING g_sUltraIOCurveSetting[ULTRAIO_TOTAL_CURVE_COUNT] = {\
{64, E_ULTRAIO_TYPE_FW, 0}, \
{64, E_ULTRAIO_TYPE_HW, BIT1} \
}; 

#define ULTRAIO_CURVE_TO_PORTA_PINS()   
#define ULTRAIO_CURVE_TO_PORTB_PINS()   \
uint16_t g_uiUltraIOCurveToPortBPins[ULTRAIO_FW_CURVE_COUNT] = {BIT4};
// FW pwm no use any port
// #define ULTRAIO_CURVE_TO_PORTA_PINS()
// #define ULTRAIO_CURVE_TO_PORTB_PINS()
// FW pwm use the data type if use Pin0~7 only
// #define ULTRAIO_CURVE_TO_PORTA_PINS() \
// const uint8_t g_uiUltraIOCurveToPortAPins[ULTRAIO_FW_CURVE_COUNT] = {};
// #define ULTRAIO_CURVE_TO_PORTB_PINS() \
// const uint8_t g_uiUltraIOCurveToPortBPins[ULTRAIO_FW_CURVE_COUNT] = {};
// FW pwm use the data type if use Pin0~15
// #define ULTRAIO_CURVE_TO_PORTA_PINS() \
// const uint16_t g_uiUltraIOCurveToPortAPins[ULTRAIO_FW_CURVE_COUNT] = {};
// #define ULTRAIO_CURVE_TO_PORTB_PINS() \
// const uint16_t g_uiUltraIOCurveToPortBPins[ULTRAIO_FW_CURVE_COUNT] = {};

/*---------------------------------------------------------------------------------------------------------*/
/* Configurations of initiate port mode and pin.                                                           */
/*---------------------------------------------------------------------------------------------------------*/
#define ULTRAIO_INITIATE_PORTA_PIN 
#define ULTRAIO_INITIATE_PORTB_PIN      \
BIT4|BIT5
// For initiate setting, if FW curve pwm no use portA/portB to output
// #define ULTRAIO_INITIATE_PORTA_PIN
// #define ULTRAIO_INITIATE_PORTB_PIN
// For initiate setting, if FW curve pwm use any portA/portB to output
// #define ULTRAIO_INITIATE_PORTA_PIN \
// BIT0|BIT1|BIT2|BIT3|BIT12|BIT13
// #define ULTRAIO_INITIATE_PORTB_PIN \
// BIT6|BIT7|BIT8|BIT9|BIT10|BIT11

/*---------------------------------------------------------------------------------------------------------*/
/* Configurations of Hardware.                                                                             */
/*---------------------------------------------------------------------------------------------------------*/
#define ULTRAIO_INITIATE_HW_PWM_ENABLED \
BIT1
// HW pwm no use gpio multi function pin
// #define ULTRAIO_INITIATE_HW_PWM_ENABLED
// HW pwm use (0-3) gpio multi function pin
// #define ULTRAIO_INITIATE_HW_PWM_ENABLED \
// BIT0|BIT1|BIT2|BIT3

#if( ULTRAIO_USE_STRUCTURE == 0 )
/*---------------------------------------------------------------------------------------------------------*/
/* Declare variable when ULTRAIO_USE_STRUCTURE = 0                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#define ULTRAIO_FW_PWM_COUNTER() \
uint8_t g_u8UltraIOFwPwmCounter = 0;
// No use FW PWM curve
// #define ULTRAIO_CURVE_FW_PWM_COUNTER() 
// use FW PWM curve
// #define ULTRAIO_CURVE_FW_PWM_COUNTER() \
// uint8_t g_u8UltraIOFwPwmCounter = 0;

#define ULTRAIO_CURVE_VALUE() \
uint8_t g_u8UltraIOCurveValue[ULTRAIO_FW_CURVE_COUNT] = {0};
// No use FW PWM curve
// #define ULTRAIO_CURVE_VALUE() 
// use FW PWM curve
// #define ULTRAIO_CURVE_VALUE() \
// uint8_t g_u8UltraIOCurveValue[ULTRAIO_FW_CURVE_COUNT] = {0};

#define ULTRAIO_CURVE_CTRL() \
UINT8 g_uiUltraIOCtrl = 0xFF;
// use UltraIO Curve == 0
// #define DECLARE_ULTRAIO_CURVE_CTRL()
// 0<use UltraIO Curve <=8
// #define DECLARE_ULTRAIO_CURVE_CTRL() \
// UINT8 g_uiUltraIOCtrl = 0xFF;
// 8< use UltraIO Curve <=16
// #define DECLARE_ULTRAIO_CURVE_CTRL() \
// UINT16 g_uiUltraIOCtrl = 0xFFFF;
// use UltraIO Curve >16
// #define DECLARE_ULTRAIO_CURVE_CTRL() \
// UINT32 g_uiUltraIOCtrl = 0xFFFFFFFF;

#endif

//%{CodeGen_Block_End}

#endif
