#ifndef __SPEED_H
#define __SPEED_H

#include "include.h"
#include "common.h"
#include "PID.h"

#define PI   3.14
#define Small_gear  1
#define Big_gear    2
#define Wheel       3     
#define Speed_Test(x)    (((x/512)*2*PI*Wheel)/Big_gear)

//�����ٶȲɼ�״̬
typedef enum
{
	Speed_NOTINIT = 0,
	Speed_FINISH,             //�ٶȲɼ����
	Speed_FAIL,               //�ٶȲɼ�ʧ��(�ɼ���������)
	Speed_GATHER,             //�ٶȲɼ���
	Speed_START,              //��ʼ�ٶȲɼ�
	Speed_STOP,               //��ֹ�ٶȲɼ�
}Speed_STATUS_e;


void Speed_Init(void);       //���������ٳ�ʼ��
void Speed_Get(void);        //�ٶȲɼ���1s�ɼ�һ��
void PIT0_IRQHandler(void);  //PIT0�жϺ���

void RS540_Init(void);
void RS540_Turn(uint16 Duty);

float RS540_PID(float speed, float actualSpeed);

#endif
