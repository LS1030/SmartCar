#ifndef _ULTRASONIC1_H_
#define _ULTRASONIC1_H_

/*------------------------------�궨��ö��-----------------------------*/


#define CHAOSHENGBODELAY_TIME1  2
#define PORT_CSB      PTD2
/*----------------------------------------------------------------------*/

/*------------------------------����������------------------------------*/
extern uint8 chaoshengbo_flag;
extern int8 open;
extern int32 car_distance;    //����
extern int32 car_distance0[10];
extern uint32 timevar;         //��ʱ������ֵ��ת����ʱ��
extern int16 chaoshengbo_delay_cnt1;

/*----------------------------------------------------------------------*/

/*------------------------------����������------------------------------*/

extern void ultrasonic_init();     //��������ʼ������
extern void chaoshengbo(void);

/*----------------------------------------------------------------------*/


#endif //