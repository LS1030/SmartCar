#include "Image_Process.h"

/************************************************************************/
/*                     ����·�����                                     */
uint8                  cross_flag;              //ʮ�ֱ�־
uint8                  S_flag;                  //����S���־
uint8                  L_Sharp_turn_flag;       //�󴫼����־
uint8                  R_Sharp_turn_flag;       //�Ҵ������־
uint8                  Big_Turn_flag;           //���仺���־
uint8                  L_Loop_flag;             //��໷����־
uint8                  R_Loop_flag;             //�Ҳ໷����־
uint8                  Barrier_flag;            //�ϰ���־
uint8                  Stop_flag;               //ֹͣ��־
/************************************************************************/

uint8  zhongxian[CAMERA_H][CAMERA_W];                  //���崢�����ߵ�����
uint8  bianyan[CAMERA_H];                              //���崢�������Ϣ����
uint8  bianyan_flag = 0;                                //�������flag
uint8  midline1_L,midline2_L,midline3_L;

/*
 *  @brief      ·����ʶ��ʼ������
 *  @param
*/
void Flag_Init(void)
{
	cross_flag = 0;
	S_flag = 0;
	L_Sharp_turn_flag = 0;
	R_Sharp_turn_flag = 0;
	Big_Turn_flag = 0;
	L_Loop_flag = 0;
	R_Loop_flag = 0;
	Barrier_flag = 0;
	Stop_flag = 0;
}

/*
*  @brief      ��������ʼ������
*  @param
*/
void Buzzer_Init(void)
{
	gpio_init(Buzzer, GPO, 0);
}

/*
*  @brief      ��������һ������
*  @param
*/
void Buzzer_NO(void)
{
	gpio_set(Buzzer, 1);     //��
	DELAY_MS(100);
	gpio_set(Buzzer, 0);
}


/*
*  @brief      ��ȡ���ߺ�����������ȡ������Ϣ
*  @param      
               ���ص���ȫ�����飺img[CAMERA_H][CAMERA_W]; imgbuff[CAMERA_SIZE];
			   �������ȫ�����飺zhongxian[CAMERA_H][CAMERA_W]; bianyan[CAMERA_H];
			   �������ȫ�ֱ�����bianyan_flag
*/
void Get_MiddleLine(uint8 midline1_H, uint8 midline2_H, uint8 midline3_H)
{
	int i, j, n, left_back, right_back;
	uint8 right_flag, left_flag;
	/************************************************************************/
	/*                          �������鸳��ֵ��ȫ�ף�                      */
	  for (i = 0; i < CAMERA_H; i++)
		 for (j = 0; j < CAMERA_W; j++)
			zhongxian[i][j] = 255;
	/************************************************************************/

   /************************************************************************/
   /*                            ��ȡ����                                  */
	  for (i = CAMERA_H - 1; i > CAMERA_H - 4; i--)          //��ȡǰ��������
	  {
		  for (j = CAMERA_W / 2; j < CAMERA_W; j++)
		  {
			  if (img[i][j] == 0xff && img[i][j + 1] == 0x00)
			  {
				  right_back = j;
				  right_flag = 10;
				  break;
			  }
			  else
			  {
				  right_flag = 0;
				  right_back = CAMERA_W - 5;
			  }
		  }
		  for (j = CAMERA_W / 2; j > 0; j--)
		  {
			  if (img[i][j] == 0xff && img[i][j - 1] == 0x00)
			  {
				  left_back = j;
				  left_flag = 1;
				  break;
			  }
			  else
			  {
				  left_flag = 0;
				  left_back = 5;
			  }
		  }
	  }

	  for (i = CAMERA_H - 4; i > 0; i--)              //��ȡ���߼�������Ϣ
	  {
		  for (j = right_back - 10; j < (MIN((right_back + 10), CAMERA_W)); j++)
		  {
			  if (img[i][j] == 0xff && img[i][j + 1] == 0x00)
			  {
				  right_back = j;
				  right_flag = 10;
				  break;
			  }
			  else right_flag = 0;
		  }
		  for (j = left_back + 10; j > (MAX((left_back - 10), 0)); j--)
		  {
			  if (img[i][j] == 0xff && img[i][j - 1] == 0x00)
			  {
				  left_back = j;
				  left_flag = 1;
				  break;
			  }
			  else left_flag = 0;
		  }
                  
          /*��ȡǰհ��*/
		  if (i == midline1_H)
		  {
			  midline1_L = n;
		  }
		  if (i == midline2_H)
		  {
			  midline2_L = n;
		  }
          if(i==midline3_H)
		  {
			 midline3_L = n;
		  }

		  n = (right_back + left_back) / 2;
		  bianyan_flag = left_flag + right_flag;

		  img[i][n] = 0;
		  zhongxian[i][n] = 0;
		  bianyan[i] = bianyan_flag;
	  }
  /************************************************************************/
}

/*
*  @brief      ��ȡ·������·����־����
*  @param
*/
void Get_Road_flag(void)
{
	uint8 Sharp_left_number = 0, Sharp_right_number = 0;
	uint8 cross_number = 0;
	/************************************************************************/
	/*         ********�жϼ������*******                                 */
	/************************************************************************/
	if (bianyan_flag == 1)                 //���������Ϣ��Ϊ1��˵���ұ߶��˱���
	{
		Sharp_right_number++;
		if (Sharp_right_number >= 20)
		{
			R_Sharp_turn_flag = 1;        //�������20���ұ߶����أ����жϴ�ʱΪ�Ҽ���
			Buzzer_NO();
		}
	}
	else Sharp_right_number = 0;

	if (bianyan_flag == 10)                 //���������Ϣ��Ϊ10��˵����߶��˱���
	{
		Sharp_left_number++;
		if (Sharp_left_number >= 20)
		{
			L_Sharp_turn_flag = 1;        //�������20����߶����أ����жϴ�ʱΪ����
			Buzzer_NO();
		}
	}
	else Sharp_left_number = 0;
	/**********�����жϽ���********/


	/************************************************************************/
	/*                             �ж��Ƿ�Ϊʮ��                           */

	/************************************************************************/
	if (bianyan_flag == 0)                 //���������Ϣ��Ϊ0��˵�����߶��˱���
	{
		cross_number++;
		if (cross_number >= 10)
		{
			cross_flag = 1;                  //�������10�����߶����أ����жϴ�ʱΪʮ��
			Buzzer_NO();
		}
	}
	else cross_number = 0;

	/************************************************************************/
	/*                          �ж�����s���                               */
	/*�����ݵ����������ж�����s����������
	��ĳ����������Ϊһ��һά���飬����ȡ��һ��ͼ��ʱ�Ը�������и���ɨ��
	����ɨ���Ŀ�ģ�1����ʡʱ�䣻2�������ֳ���������
	��ɨ���복����������������35-55�С�
	��55�п�ʼ���Ƚ�52�������������55�Ĵ�С�����ܴ���С������¼һ����С��־λ
	�����Ƚϡ���ֱ�����ִ�С��־λ��ͬ�������˴���s���ͻ������
	�ҳ���һ��ͻ������
	��������ͻ����
	/************************************************************************/

	/************************************************************************/
	/*                       �����ж�                                       */

	/* ****** ���ж��󻷵�******/
	/*���������ϢҲ��һ��һά���飬��ÿ�λ�ȡ��һ��ͼ���ɨ������顣
	�ӵ�һ�п�ʼ������һά����
	�������ش���������ʧ���е���� ��¼һ����־λa
	�����ڱ�־λaʱ��ӵ�ǰ�м������������
	������������ز���ʧʱ����¼һ����־λb
	�����ڱ�־λbʱ���ӵ�ǰ�м������������
	��ab��־λ������ʱ���ӵ�ǰ�м����������������������������еس��֣����жϵ�ǰ�Ѿ������󻷵���

	/************************************************************************/

}



