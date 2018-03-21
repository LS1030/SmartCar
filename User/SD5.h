#ifndef __SD5_H
#define __SD5_H

#include "include.h"
#include "common.h"
#include "Image_Process.h"  //ͼ����ͷ�ļ�����Ҫ���ڲ�·����ʶ

/************************************************************************/
/*                           ���״̬                                   */
#define	SD5_Normal  0             //����
#define	SD5_Left    1             //����
#define	SD5_Right   2             //����
/************************************************************************/

void SD5_Init(void);
void SD5_Turn(uint16 Duty);
float SD5_PID(int16 actual_err);
void  Get_SD5_PID(void);
void  SD5_Contral(int16 average);

#endif
