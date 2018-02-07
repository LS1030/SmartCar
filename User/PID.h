#ifndef __PID_H
#define __PID_H

#include "include.h"
#include "common.h"

struct _pid 
{
	uint16 SetSpeed;           //�����趨ֵ
	int16 err;                 //����ƫ��ֵ
	int16 err_next;            //������һ��ƫ��ֵ
	int16 err_last;            //��������ǰ��ƫ��ֵ
	float Kp, Ki, Kd;          //������������֡�΢��
	float increment;           //��������
};

#endif
