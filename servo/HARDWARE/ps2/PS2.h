#ifndef  PS2_H2_
#define	 PS2_H2_

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "misc.h"
#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h"

 extern void ps2_read(uint8_t Data1,uint8_t Data2,uint8_t Data3,uint8_t Data4,uint8_t Data5,uint8_t Data6);

#define PS2_Left            ((uint8_t)0x7FU)
#define PS2_Down            ((uint8_t)0xBFU)
#define PS2_Right           ((uint8_t)0xDFU)
#define PS2_Up              ((uint8_t)0xEFU)
#define PS2_Square          ((uint8_t)0x7FU)
#define PS2_Cross           ((uint8_t)0xBFU)
#define PS2_Circle          ((uint8_t)0xDFU)
#define PS2_Trigle          ((uint8_t)0xEFU)

#define PS2_R1              ((uint8_t)0xF7U)
#define PS2_L1              ((uint8_t)0xFBU)
#define PS2_R2              ((uint8_t)0xFDU)
#define PS2_L2              ((uint8_t)0xFEU)
#define PS2_Start           ((uint8_t)0xF7U)
#define PS2_Select          ((uint8_t)0xFEU)
#define PS2_R3              ((uint8_t)0xFBU)
#define PS2_L3              ((uint8_t)0xFDU)

typedef struct {
  uint8_t L:1 ; //left
  uint8_t D:1; //down
  uint8_t R:1; //right
  uint8_t U:1; //up
  uint8_t square:1;
  uint8_t X:1;
  uint8_t O:1;
  uint8_t trigle:1;
  uint8_t L1:1;
  uint8_t L2:1;
  uint8_t R1:1;
  uint8_t R2:1;
  uint8_t Start:1;
  uint8_t Select:1;
  uint8_t L3:1;
  uint8_t R3:1;
}PS2_stat;

extern uint8_t RX,RY,LX,LY;
 


#endif







