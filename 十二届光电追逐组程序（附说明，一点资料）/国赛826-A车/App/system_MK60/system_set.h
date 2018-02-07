#ifndef _SYSTEM_SET_H_
#define _SYSTEM_SET_H_

/*------------------------------�궨��ö��-----------------------------*/

typedef enum
{
      CAR_WAIT,      //С���ȴ�״̬
      CAR_RUN,       //С����ʻ״̬
      CAR_STOPP,     //С��ֹͣ״̬
}CAR_STATUS;         //С��״̬ö�ٱ���

/*----------------------------------------------------------------------*/

/*------------------------------����������------------------------------*/

extern uint8 car_flag;          //ǰ�󳵱�־λ��0Ϊǰ����1Ϊ�󳵣�
extern uint8 car_start_flag;
extern uint8 double_car_flag;   //˫����1����˫��ģʽ��
extern CAR_STATUS car_status;
extern uint8 servo_enable,motor_enable;
extern uint8 send_error_flag,send_start_flag;
extern uint32 send_error;
/*----------------------------------------------------------------------*/

/*------------------------------����������------------------------------*/

extern void car_init();
extern void car_wait();
extern void car_judge();
extern uint8 QianChe_extract();
extern void qipao_tongxin();

/*----------------------------------------------------------------------*/








#endif


