#ifndef _FTM_FUNCTION_H_
#define _FTM_FUNCTION_H_

/*------------------------------�궨����--------------------------------*/

        /*�������궨�����*/

#define SERVO_IO    PTC9           //������ FTM ���ź�

#define SERVO_FTM   FTM3           //������ FTM ģ���
#define SERVO_CH    FTM_CH5        //������ FTM ͨ����
#define SERVO_HZ    (50)           //������ Ƶ�� ��һ��Ϊ 50~100 HZ��


        /*�������궨�����*/

#define MOTOR0_IO   PTD5           //������2 FTM ���ź�
#define MOTOR1_IO   PTD4           //������4 FTM ���ź�

#define MOTOR_FTM   FTM0           //������ FTM ģ���
#define MOTOR0_PWM  FTM_CH5        //��������ת FTM ͨ����
#define MOTOR1_PWM  FTM_CH4        //��������ת FTM ͨ����

//����ģʽ�£�Ƶ��Ӧ���� 30~100��
//����ģʽ�£�Ƶ��Ӧ���� 20k ����

#define MOTOR_HZ    (20*1000)


        /*����������궨�����*/



/*----------------------------------------------------------------------*/

/*------------------------------����������------------------------------*/

extern int16 encoder_in1;      //�������������1
extern int16 encoder_in2;      //�������������2

/*----------------------------------------------------------------------*/

/*------------------------------����������------------------------------*/

extern void servo_init();      //�����ʼ������
extern void servo_output();    //���PWM���������

extern void motor_init();      //�����ʼ������
extern void motor_output();    //���PWM���������

extern void encoder_init();    //��������ʼ������
extern void encoder_input();   //�����������������뺯��

/*----------------------------------------------------------------------*/




#endif


