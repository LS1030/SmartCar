#ifndef _IMAGE_BINARYZATION_H_
#define _IMAGE_BINARYZATION_H_

/*------------------------------�궨����--------------------------------*/

#define ERZHI                50
#define IMG_THRESHOLD_ADD    0
#define HEIGHT_STRAT         0
#define HEIGHT_END           60

/*----------------------------------------------------------------------*/

/*------------------------------����������------------------------------*/

typedef struct 
{
      uint16  x;       //����
      uint16  y;       //�Ҷ�ֵ
}image_pixel;          //�Ҷ��ݶ�ͳ�ƽṹ��
//Ϊ��������Ӱ     ��֮��ȡֵ��ʱ��   ��ȥǰ3��  117��Ϊ����� 30Ϊ��Զ��

extern uint8 img_data[CAMERA_H][ CAMERA_W ];

extern uint8 img_threshold;
extern uint8 img_thresholdbu;
extern uint8 gray_start;//�Ҷ���Сֵ
extern uint8 gray_end;//�Ҷ����ֵ
extern uint16 gray_wide;
extern double deltaTmp;//��󷽲�
extern double gray_mean;//�Ҷ�ƽ��ֵ
extern uint8 erzhi_flag;
extern double u0;//��һ���ƽ���Ҷ� ����
extern double u1; //�ڶ����ƽ���Ҷ�  ǰ��

/*----------------------------------------------------------------------*/

/*------------------------------����������------------------------------*/

extern uint8 binary_process(uint8 location,uint8 height_start,uint8 height_end);     //ͼ���ֵ������ֵ�㷨
extern void img_binary();                                                           //ͼ���ֵ��������
extern void bubble_sort( uint16 n);                                                 //ð��������

/*----------------------------------------------------------------------*/



#endif




