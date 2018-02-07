#include "include.h"
#include "common.h"

/***********************************************************************************************************************************/

uint8 car_flag=0,car_start_flag=1;                      //ǰ�󳵱�־λ
uint8  double_car_flag=0;            //˫��
uint8 send_error_flag=0,send_start_flag=0;
CAR_STATUS car_status=CAR_WAIT;
//uint8 car_run=0;
//uint8 run_time=0;
//float OutData[4];
uint8 servo_enable,motor_enable;
/***********************************************************************************************************************************/

void car_init();   //�ж����ȼ����ú���
void car_wait();

/***********************************************************************************************************************************/

void car_init()    //�ж����ȼ����ú���
{
      NVIC_SetPriority(PORTB_IRQn,0);   //���жϽ����жϷ����� 
      NVIC_SetPriority(DMA0_IRQn,1);    //DMA�ɼ�����жϷ�����
      NVIC_SetPriority(PORTC_IRQn,2);   //�������жϷ�����
      NVIC_SetPriority(PORTD_IRQn,3); //����ͨ��
      NVIC_SetPriority(PIT0_IRQn,4);    //�������жϷ�����
      NVIC_SetPriority(PIT1_IRQn,5);    //�������жϷ�����
      NVIC_SetPriority(PIT3_IRQn,6);    //�������жϷ�����
      ftm_quad_init(FTM2);       //������ʼ��
      pit_init_ms(PIT0,20);      //��ʼ��PIT0����ʱʱ��Ϊ�� 20ms�����ڿ��ƶ�����
      pit_init_ms(PIT1,20);      //��ʼ��PIT1����ʱʱ��Ϊ�� 20ms�����ڿ��Ƶ�����
      pit_init_ms(PIT3,20);   //��ʱ
}

/***********************************************************************************************************************************/

void car_wait()
{
      enable_irq (PORTB_IRQn);   //ʹ��PORTB�жϣ����ж��źŽ����жϣ�
      enable_irq (PORTD_IRQn);   //ʹ��PORTB�жϣ����ж��źŽ����жϣ�
      enable_irq (PORTC_IRQn);
      enable_irq (PIT3_IRQn);    //ʹ��PIT3�жϣ���־λ��ʱ�жϣ�
      enable_irq (PIT0_IRQn);    //ʹ��PIT0�жϣ�������������ʱ�жϣ�
      enable_irq (PIT1_IRQn);    //ʹ��PIT1�жϣ�������������ʱ�жϣ�
      EnableInterrupts;          //ʹ��ȫ���ж�
      
      DELAY_MS(1000);
      car_status=CAR_RUN;        //С��״̬��Ϊ��ʻ
      car_start_flag=1;
      if(!double_car_flag)
      {
            servo_enable=1;
            motor_enable=1;
            car_start_flag=0;
      }
      else
      {
            car_judge();
      }
}

/***********************************************************************************************************************************/
void car_judge()
{
      //----------------------ȷ��ǰ��-----------------------//
      while(car_start_flag)
      {//�ó���������ʹ�������������ߺ��ϰ���
            if(1 || mt9v032_finish_flag )         //������ͷ�ɼ���һ��ͼ��
            {
//                  uint16 copy;                //�����ڱߣ�ʹ���ڴ��ƶ�����������ұ߸�����һ��
//                  for( copy=0 ; copy<120 ; copy++ )     //��Լ200US
//                  {
//                        memmove(&img[copy][0],&image_h[copy][0],188);  //���ٿ�������ͷ�ɼ���ͼ��
//                  }
//                  mt9v032_finish_flag=0;      //����ͷ�ɼ���ɱ�־λ��  0
//                  barrel_rectification();     //Ͱ��ʧ���������ȡ������ͼ��
//                  img_binary();               //ͼ���ֵ������
//                  edge_extract();             //������ȡ
//                  if(END_LINE_TEMP==1)
//                  {
//                        if(QianChe_extract()==1)
//                        {
//                              car_flag=1;
//                        }
//                        else
//                        {
//                              car_flag=0;
//                        }
//                  }
//                  else
//                  {
//                        if((L_barrier_flag && (L_barrier_down_row>15)) || (R_barrier_flag && (R_barrier_down_row>15)))
//                        {
//                              car_flag=1;
//                        }
//                        else
//                        {
//                              car_flag=0;
//                        }
//                  }//�Ժ����ֱ�Ӹ�˫��ʶ������ˣ�����
                  if(chaoshengbo_flag && car_distance<=300)
                  {
                        car_flag=1;
                  }
                  else if(!chaoshengbo_flag)
                  {
                        car_flag=0;
                  }
                  //----------------------ͨѶȷ��ǰ��--------------------//
                  qipao_tongxin();
                  
            }
            
            if(round(other1_f)!=0)//�ñ�־λ�ֶ�����
            {
                  if(round(other1_f)==1)
                  {
                        car_flag=0;
                  }
                  else
                  {
                        car_flag=1;
                  }
                  car_start_flag=0;
            }
      }
      
      if(car_flag)
      {
            gpio_set (PORT_CSB, 0);//�رշ��ͳ�����
            barrier_able=0; //ʹ�������ϰ���
      }
      else
      {
            barrier_able=1; //ʹ�������ϰ���
            Bee_flag=1;
      }
      overtake_start_flag=1;//��ʼ��Ϊ����ģʽ������ģʽ���ֱ�ӽ�������ģʽ��
      send_start_flag=0;
      servo_enable=1;
      motor_enable=1;
}

uint8 QianChe_extract()
{
      int16 x,y,z;
      double aa;
      Site_xy1 xy1;
      uint8 QianChe_see_flag=0;
      if( end_line_row!=-1 )
      {
            aa=inv_distance[end_line_row]-40;
            xy1=get_invinv_img(aa , 0 );
      }
      else
      {
            xy1.x=ROW_END;
      }
      for(x=ROW_END;x>xy1.x ;x--)
      {
            for(y=left_edge[x];y<=right_edge[x]-5;y++)
            {
                  if(y<=(COL_END-3) && img_data[x][y]==DOT_W && img_data[x][y+1]==DOT_W && img_data[x][y+2]==DOT_B && img_data[x][y+3]==DOT_B)
                  {
                        QianChe_see_flag=1;
                        break;
                  }
            }
            if(QianChe_see_flag==1)
                  break;
      }
      if(QianChe_see_flag==1)
      {
            return 1;
      }
      else
      {
            return 0;
      }
}

void qipao_tongxin()
{
      if(!car_flag)
      { 
            while(!nrf_send_finish_flag)
            {
                  send_start_flag=1;
                  A_send_B0();
                  if(send_error_flag && !nrf_send_finish_flag)
                        break;
            }
            send_start_flag=0;
            send_error=0;
            send_error_flag=0;
            while(!nrf_read_finish_flag && nrf_send_finish_flag)
            {
                  send_start_flag=1;
                  A_read_B0();
                  if(send_error_flag && !nrf_read_finish_flag)
                        break;
            }
            send_start_flag=0;
            send_error=0;
            send_error_flag=0;
            nrf_send_finish_flag=0;
            nrf_read_finish_flag=0;
      }
      else
      {
            while(!nrf_read_finish_flag)
            {
                  send_start_flag=1;
                  B_read_A0();
                  if(send_error_flag)
                        break;
            }
            send_start_flag=0;
            send_error=0;
            send_error_flag=0;
            nrf_send_finish_flag=0;
            nrf_read_finish_flag=0;
      }
}