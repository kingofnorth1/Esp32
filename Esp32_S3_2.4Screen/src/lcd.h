#ifndef __LCD__H
#define __LCD__H

#include "Arduino.h"
#include "lcd_Font.h"

#define SPI_SCK_0  digitalWrite(3,LOW)             
#define SPI_SCK_1  digitalWrite(3,HIGH) 
#define SPI_SDA_0  digitalWrite(4,LOW)               
#define SPI_SDA_1  digitalWrite(4,HIGH)
#define SPI_RST_0  digitalWrite(5,LOW)               
#define SPI_RST_1  digitalWrite(5,HIGH)
#define SPI_DC_0  digitalWrite(6,LOW)               
#define SPI_DC_1  digitalWrite(6,HIGH)
#define SPI_WR_0  digitalWrite(7,LOW)                 
#define SPI_WR_1  digitalWrite(7,HIGH)

#define     RED          0XF800    //红色
#define     GREEN        0X07E0   //绿色
#define     BLUE         0X001F   //蓝色
#define     WHITE        0XFFFF   //白色

#define TFT_COLUMN_NUMBER 240
#define TFT_LINE_NUMBER 320

#define PIC_NUM 153600     //图片数据大小
const unsigned char  *point;


void IO_init(void );
void delay_us(unsigned int _us_time);
void SPI_SendByte(unsigned  char byte);        //向液晶屏写一个8位数据
void TFT_SEND_CMD(unsigned char o_command);
void TFT_SEND_DATA(unsigned  char o_data);
void TFT_clear(void);
void set_dis_ear(void);
void TFT_full(unsigned int color);
void TFT_init(void);				////ST7789V2
void display_char16_16(unsigned int x,unsigned int y,unsigned long color,unsigned char word_serial_number);
void Picture_Display(void);

#endif