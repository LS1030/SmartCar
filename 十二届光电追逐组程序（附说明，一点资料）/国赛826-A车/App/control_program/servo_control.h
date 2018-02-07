#ifndef _SERVO_CONTROL_H_
#define _SERVO_CONTROL_H_

/*------------------------------�궨����--------------------------------*/

//#define JIZHUN_UP       30        //����ƫ������߽�ȡ���ֵ��ϱ߽�26
//#define JIZHUN_DOWN     50        //����ƫ������߽�ȡ���ֵ��±߽�35
//#define JIZHUN_ROW      40        //����Ȩֵ��

#define JIZHUN_COL      79.5        //ͼ�����߻�׼

#define LENGTH_IN       160         //ͼ���������Ȩֵ��Χ����͸�ӵ�λ��
#define LENGTH_OUT      320         //ͼ��Զ������Ȩֵ��Χ����͸�ӵ�λ��
#define pull_over_dis   120         //С������ͣ��ǰհ�趨����͸�ӵ�λ��
#define pull_over_dis_po  160          //С������ͣ��ǰհ�趨����͸�ӵ�λ��
#define pull_over_dis_cross   160         //С������ͣ��ǰհ�趨����͸�ӵ�λ��
#define pull_over_dis_qi  80         //С������ͣ��ǰհ�趨����͸�ӵ�λ��
/*----------------------------------------------------------------------*/

/*------------------------------����������------------------------------*/

extern uint32 jizhun_step;
extern uint32 JIZHUN_ROW;    //����Ȩֵ��
extern uint32 JIZHUN_UP;     //����ƫ������߽�ȡ���ֵ��ϱ߽�26
extern uint32 JIZHUN_DOWN;   //����ƫ������߽�ȡ���ֵ��±߽�35

extern uint32 servo_m_step;
extern uint32 SERVO_MID;     // 637
extern uint32 SERVO_L;       //�������  756(��ʽ�����
extern uint32 SERVO_R;       //����Ҽ���  576����ʽ�����

extern double servo_step;
extern double servo_a;
extern double servo_b;
extern double servo_c;
extern double servo_d;
extern double servo_e;
extern double servo_f;

extern double servo_Kp;           //��� Pϵ��
extern double servo_Ki;           //��� Iϵ��
extern double servo_Kd;           //��� Dϵ��
extern double middle_Error[2];    //���ƫ��洢����
extern double midline_avg;        //������ƽ��ֵ
extern int16 servo_out;            //������ֵ

extern double inv_weight[CAMERA_H];  //������Ȩֵ����

/*----------------------------------------------------------------------*/

/*------------------------------����������------------------------------*/

extern void servo_control();   //�������������
extern void get_weight();      //������Ȩֵ��ȡ����
extern void middle_avg();      //�����߼�Ȩƽ����ƫ���
extern void PID_control();     //���PID����

/*----------------------------------------------------------------------*/




#endif