#ifndef __IMAGE_PROCESS_H
#define __IMAGE_PROCESS_H

#include "common.h"
#include "include.h"
/************************************************************************/
/*                             ·����ʶ                                 */
extern     uint8      cross_flag;              //ʮ�ֱ�־
extern     uint8      S_flag;                  //����S���־
extern     uint8      L_Sharp_turn_flag;       //�󴫼����־
extern     uint8      R_Sharp_turn_flag;       //�Ҵ������־
extern     uint8      Big_Turn_flag;           //���仺���־
extern     uint8      L_Loop_flag;             //��໷����־
extern     uint8      R_Loop_flag;             //�Ҳ໷����־
extern     uint8      Barrier_flag;            //�ϰ���־
extern     uint8      Stop_flag;               //ֹͣ��־
/************************************************************************/

/************************************************************************/
/*                      �ⲿ���ñ���������                              */
extern uint8 img[CAMERA_H][CAMERA_W];           //����洢ת�����ͼ��Ķ�ά����
extern uint8 imgbuff[CAMERA_SIZE];              //����洢����ԭʼͼ���һά����
/************************************************************************/

/************************************************************************/
/*                      �ڲ��������������                              */
extern uint8  zhongxian[CAMERA_H][CAMERA_W];        //���崢�����ߵ�����
extern uint8  bianyan[CAMERA_H];                    //���崢�������Ϣ����
/************************************************************************/

void Get_MiddleLine(uint8 midline1_H, uint8 midline2_H, uint8 midline3_H);  //��ȡ����,��ȡǰհ�� 
void Get_Road_flag(void);    //��ȡ·������·����־

void Flag_Init(void);
void Buzzer_Init(void);
void Buzzer_NO(void);      //��һ��


#endif
