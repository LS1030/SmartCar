#ifndef _KEY_H_
#define _KEY_H_

#define USE_KEY      zhuban

/***********************************************************************************************************************************/

#define UP              (1u)
#define DOWN            (2u)
#define LEFT            (3u)
#define RIGHT           (4u)
#define OK              (5u)

#define zhuban      1
#define LCD         2

#if (USE_KEY==LCD)
//���� ����  ��
  /*LCD�Դ��İ���*/
#define UP_KEY       gpio_get(PTA29)
#define DOWN_KEY     gpio_get(PTB8)
#define LEFT_KEY     gpio_get(PTA26)
#define RIGHT_KEY    gpio_get(PTA24)
#define OK_KEY       gpio_get(PTB9)

#else
  /*���尴��*/
#define UP_KEY       gpio_get(PTD15)
#define DOWN_KEY     gpio_get(PTD11)
#define LEFT_KEY     gpio_get(PTD12)
#define RIGHT_KEY    gpio_get(PTD13)
#define OK_KEY       gpio_get(PTD14)
#endif

//���뿪��
#define DIP0       gpio_get(PTD9)
#define DIP1       gpio_get(PTD8)
#define DIP2       gpio_get(PTD1)
#define DIP3       gpio_get(PTD0)
#define DIP4       gpio_get(PTC19)
#define DIP5       gpio_get(PTC18)
#define DIP6       gpio_get(PTC17)
#define DIP7       gpio_get(PTC16)

#define KEY_DELAY       DELAY_MS(10)

/***********************************************************************************************************************************/

extern uint8 once_check_key();     //������һ����������

/***********************************************************************************************************************************/

#endif