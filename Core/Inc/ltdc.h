/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    ltdc.h
  * @brief   This file contains all the function prototypes for
  *          the ltdc.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LTDC_H__
#define __LTDC_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#include "ili9341.h"
#include "fonts.h"
#include "lcd_io.h"
/* USER CODE END Includes */

extern LTDC_HandleTypeDef hltdc;

/* USER CODE BEGIN Private defines */
#define LCD_H 320
#define LCD_W 240

typedef struct _tTXT_confg{
uint16_t backcolor;
uint16_t textcolor;
sFONT *font;

} TXT_conf;

extern TXT_conf string_conf;
extern uint16_t frame_buff[LCD_H*LCD_W];

/* USER CODE END Private defines */

void MX_LTDC_Init(void);

/* USER CODE BEGIN Prototypes */

void LCD_draw_pixel(uint16_t x, uint16_t y, uint16_t c);
void LCD_draw_rectangle(uint16_t x, uint16_t y,uint16_t w, uint16_t h, uint16_t c);
void LCD_draw_string(char *str, uint16_t x, uint16_t y,uint8_t length ,TXT_conf *conf);
void LCD_Config();
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __LTDC_H__ */

