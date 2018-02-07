#include "include.h"
#include "common.h"

/***********************************************************************************************************************************/
uint8 chaoshengbo_flag=0;
int8 open=0;
int32 car_distance;      //����
int32 car_distance0[10];
int32 car_distance_temp; //����
uint32 timevar;           //��ʱ������ֵ��ת����ʱ��
int16 chaoshengbo_delay_cnt1=0;
/***********************************************************************************************************************************/

void ultrasonic_init();      //��������ʼ������
void chaoshengbo(void);

/***********************************************************************************************************************************/

void ultrasonic_init()       //��������ʼ������
{
  port_init(PTD7,ALT1|IRQ_EITHER| PF |PULLUP);
//  port_init(PTD6,ALT1|PULLUP);
//  gpio_init(PTD6,GPO,1);
  port_init(PORT_CSB,ALT1|PULLUP);
  gpio_init(PORT_CSB,GPO,1);
}

/***********************************************************************************************************************************/

void chaoshengbo(void)
{     
  //      chaoshengbo_flag=0;
  if(PTD7_IN==1&&open==0)      //�ߵ�ƽ��ȡ
  {
    pit_time_start(PIT2);
    open=1;
  }
  else if(PTD7_IN==0&&open==1)
  {
    uint32 time=pit_time_get(PIT2);
    if(time != ~0)       //û��ʱ
    {
      timevar =1000*time/bus_clk_khz;                 //ʱ��Ϊ΢��
      //car_distance=1500;
      car_distance_temp = timevar * 340  / 1000;      //����Ϊ����
      if(car_distance_temp>=50 && car_distance_temp<=3000)
      {                 
        car_distance = car_distance_temp;
        chaoshengbo_delay_cnt1=0;
        chaoshengbo_flag=1;
      }
    }
    pit_close(PIT2);
    open=0;
  }
}

/***********************************************************************************************************************************/



