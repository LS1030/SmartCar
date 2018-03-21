#include "SD5.h"
#include "PID.h"

struct _pid SD5_pid;
uint8    SD5_flag = SD5_Normal;     //���״̬

/*
*  @brief      SD5��ʼ������������ֵ
*/
void SD5_Init()
{
	ftm_pwm_init(SD5_FTM, SD5_FTM_CH, SD5_FTM_Freq, SD5_Duty_Middle);
}

/*
*  @brief      SD5ת������
*  @param      Duty         ռ�ձ�
*/
void SD5_Turn(uint16 Duty)
{
	ftm_pwm_duty(SD5_FTM, SD5_FTM_CH, Duty);
}

/*
*  @brief      SD5_PID��ʼ������
*  @param      
*/
void SD5_PID_Init()
{
	SD5_pid.SetSpeed = 0;
	SD5_pid.increment = 0.0;
	SD5_pid.err = 0;
	SD5_pid.err_next = 0;
	SD5_pid.err_last = 0;
	SD5_pid.Kp = 0.5;
	SD5_pid.Ki = 0.35;
	SD5_pid.Kd = 0.01;
}

/*
*  @brief      SD5_PID��ȡ����
*  @param      �ڲ�����kp,ki,kd,���·����־
*/
void  Get_SD5_PID(void)
{
	if (cross_flag)              //ʮ��
	{
		SD5_pid.Kp = 0.5;
		SD5_pid.Ki = 0.35;
		SD5_pid.Kd = 0.01;

		cross_flag = 0;
	} 
	else if (L_Sharp_turn_flag)    //����
	{
		SD5_pid.Kp = 0.5;
		SD5_pid.Ki = 0.35;
		SD5_pid.Kd = 0.01;

		L_Sharp_turn_flag = 0;
	} 
	else if (R_Sharp_turn_flag)    //�Ҽ���
	{
		SD5_pid.Kp = 0.5;
		SD5_pid.Ki = 0.35;
		SD5_pid.Kd = 0.01;

		R_Sharp_turn_flag = 0;
	}
	else if (Big_Turn_flag)      //����
	{
		SD5_pid.Kp = 0.5;
		SD5_pid.Ki = 0.35;
		SD5_pid.Kd = 0.01;

		Big_Turn_flag = 0;
	}
	else if (S_flag)             //����SС��
	{
		SD5_pid.Kp = 0.5;
		SD5_pid.Ki = 0.35;
		SD5_pid.Kd = 0.01;

		S_flag = 0;
	}
	else if (Barrier_flag)       //�ϰ�
	{
		SD5_pid.Kp = 0.5;
		SD5_pid.Ki = 0.35;
		SD5_pid.Kd = 0.01;

		Barrier_flag = 0;
	}
	else if (L_Loop_flag)          //��໷��
	{
		SD5_pid.Kp = 0.5;
		SD5_pid.Ki = 0.35;
		SD5_pid.Kd = 0.01;

		L_Loop_flag = 0;
	}
	else if (R_Loop_flag)          //��໷��
	{
		SD5_pid.Kp = 0.5;
		SD5_pid.Ki = 0.35;
		SD5_pid.Kd = 0.01;

		R_Loop_flag = 0;
	}
	else                         //����
	{
		SD5_pid.Kp = 0.5;
		SD5_pid.Ki = 0.35;
		SD5_pid.Kd = 0.01;
	}
}

/*
*  @brief      SD5_PID���㺯��
*  @param      actual_err ��ǰƫ��
*/
float SD5_PID(int16 actual_err)
{
	float PID;

	SD5_pid.err = actual_err;

	SD5_pid.increment = SD5_pid.Kp*(SD5_pid.err - SD5_pid.err_next) + SD5_pid.Ki*SD5_pid.err + SD5_pid.Kd*(SD5_pid.err - 2 * SD5_pid.err_next + SD5_pid.err_last);
	SD5_pid.err_last = SD5_pid.err_next;
	SD5_pid.err_next = SD5_pid.err;

	if (abs(SD5_pid.increment) <= 10)
	{
		PID = 6 * SD5_pid.increment;
	} 
	else if (abs(SD5_pid.increment > 10 && abs(SD5_pid.increment) <= 30))
	{
		PID = 7 * SD5_pid.increment;
	}
	else if(abs(SD5_pid.increment > 30 && abs(SD5_pid.increment) <=60))
	{
		PID = 9 * SD5_pid.increment;
	}
	else if (abs(SD5_pid.increment) > 60 && abs(SD5_pid.increment) <= 80)
	{
		PID = 10 * SD5_pid.increment;
	}
	

	return PID;
}

void  SD5_Contral(int16 average)
{
	int16 SD5_Duty;              //���ռ�ձ�

	if (SD5_flag == SD5_Normal)  //���ƫ����������Χ
	{
		SD5_Duty = (int16)SD5_PID(average) + SD5_Duty_Middle;
		                                                              //��������ռ�ձȵ������Сֵ
		if (SD5_Duty >= SD5_Left_max && SD5_Duty <= SD5_Right_max)    
		{
			SD5_Turn(SD5_Duty);
		}
		else if (SD5_Duty <= SD5_Left_max)                            
		{
			SD5_Turn(SD5_Left_max);
		}
		else                                                         
		{
			SD5_Turn(SD5_Right_max);
		}
	}
	else if (SD5_flag == SD5_Left)    //���ƫ��Ӧ�ö��������
	{
		SD5_Turn(SD5_Left_max);

	}
	else                              //���ƫ��Ӧ�ö��������
	{
		SD5_Turn(SD5_Right_max);

	}
}