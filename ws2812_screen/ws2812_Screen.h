#pragma once
#include "stdint.h"
#include "lg_color.h"
#include "ws2812_Screen_config.h"
typedef struct 
{
    void(*init)         (void);         /* <��Ļ��ʼ������> */
    void(*flush)        (void);         /* <ˢ����Ļ> */
    void(*set_color_all)(void);         /* <���������Ļ> */
	void(*write_cache)  (void);         /* <д�û�����> */
	void(*clear_all)    (void);         /* <����> */
	void(*set_color)    (uint16_t index,uint8_t r,uint8_t g,uint8_t b);/* <ָ��һ����RGB����> */
}Screen_Drive;

extern Screen_Drive screen;                  /* <��Ļ����> */
extern uint8_t X_Y[Screen_ROW][Screen_COL];  /* <������������ӳ�䵽���������� ������ٲ��> */

extern RGB rgb_null;
extern HSV hsv_null;
extern HSV hsv_white;

void Screen_init (void);               /* <��Ļ��ʼ������> */
void Screen_task (void);               /* <��Ļ������> */
void Screen_flush(void);               /* <��Ļˢ�º���> */
void Screen_set_point  (uint8_t x,uint8_t y,HSV hsv);                 /* <ָ�����괦���> */
void Screen_write_line (uint8_t x,uint8_t y,uint8_t length,HSV hsv);  /* <ָ�����꿪ʼ��һ������Ϊlength����> */
void Screen_write_cycle(int8_t  x,int8_t  y,int8_t  rad, HSV hsv);    /* <ָ������ΪԲ�Ļ��뾶rad��Բ> */
void Screen_write_num  (uint8_t x,uint8_t y,uint8_t num,HSV hsv);     /* <ָ��λ����ʾһ������> */

