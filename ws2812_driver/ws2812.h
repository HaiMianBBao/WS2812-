/* <WS2812��������
����PWM��DMA����
> */
#pragma once
/* <include__________> */
#include "stm32f1xx_hal.h"
/* <ʱ�����> */
#define WS2812_0  29        /* <0��> */               
#define WS2812_1  60        /* <1��> */
                            /* <����800Khz ʱ��涨 ���ɵ���> */
/* <����������> */
#define WS2812_NUM  16*16

/* <����Ӳ������> */
extern TIM_HandleTypeDef htim2;
#define WS2812_TIM       htim2
#define WS2812_Chanel    TIM_CHANNEL_2

/* <��������֡> */
typedef struct 
{
     uint16_t Head[3];              /* <��ͷ������0  �ȴ�dma�����ȶ�> */
     uint16_t Data[WS2812_NUM*24];  /* <��ʵ��RGB����  ws2812Ϊ GRB> */
     uint16_t End;                  /* <ĩβ����0    �ȶ���һ֡����> */
}WS2812_Frame;
                                    /* <��ÿˢ��һ֡  DMA������  ��3+WS2812_NUM*24+1�����ֽ�> */

/* <��������֡��С> */
#define WS2812_SEND_BUF_SIZE  (3+24*WS2812_NUM+1)

typedef struct 
{
    uint8_t g;
    uint8_t r;
    uint8_t b;
}WS2812_RGB;   /* <ÿһλ�������е�����> */

typedef struct 
{
    uint8_t h;
    uint8_t s;
    uint8_t v;
}WS2812_HSV;

/* <������> */
extern WS2812_Frame   WS2812_SEND_BUF;            /* <���ͻ�����> */
extern WS2812_RGB     WS2812_RGB_BUF[WS2812_NUM]; /* <RGB���ݻ�����> */
extern WS2812_HSV     WS2812_HSV_BUF[WS2812_NUM]; /* <HSV���ݻ�����> */
extern uint16_t       *WS2812_Frame_Data;         /* <��ɫ���ݻ�����> */

/* <ws2812������غ���> */
void lg_ws2812_clear          (void);             /* <��������> */
void lg_ws2812_init           (void);             /* <��ʼ������> */
void lg_ws2812_write_send_buf (void);             /* <����������д��> */
void lg_ws2812_start_send_buf (void);             /* <��ʼ��������> */
void lg_ws2812_stop_send_buf  (void);             /* <ֹͣ��������> */
void lg_ws2812_callback       (void);             /* <������һ֡���ݲ����Ļص�> */


void lg_ws2812_write_data     (WS2812_RGB *data, uint16_t *add);                  /* <дһ���ֽ�����> */
void lg_ws2812_set_rgb        (uint16_t number,uint8_t r,uint8_t g, uint8_t b);   /* <ָ��һ���Ƶ�RGB����> */
void lg_ws2812_set_all_rgb    (uint8_t r,uint8_t g, uint8_t b);                   /* <�趨���еƵ�RGB����> */
        

