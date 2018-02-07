/*!
*     COPYRIGHT NOTICE
*     Copyright (c) 2013,ɽ��Ƽ�
*     All rights reserved.
*     �������ۣ�ɽ����̳ http://www.vcan123.com
*
*     ��ע�������⣬�����������ݰ�Ȩ����ɽ��Ƽ����У�δ����������������ҵ��;��
*     �޸�����ʱ���뱣��ɽ��Ƽ��İ�Ȩ������
*
* @file       main.c
* @brief      ɽ��K60 ƽ̨������
* @author     ɽ��Ƽ�
* @version    v5.0
* @date       2013-08-28
*/

#include "common.h"
#include "include.h"

/***********************************************************************************************************************************/

uint32 run_time=0;
uint32 time0=0;
uint32 stoptime=0;
uint32 send_error=0;
uint8 zhengpao=0;
/***********************************************************************************************************************************/

void PORTB_IRQHandler(void);    //���жϽ����жϷ�����
void DMA0_IRQHandler(void);     //DMA�ɼ�����жϷ�����

void PIT0_IRQHandler();          //�������жϷ�����
void PIT1_IRQHandler();          //�������жϷ�����
void PIT3_IRQHandler();

void PORTD_IRQHandler(void);    //�������жϷ�����

void PORTC_IRQHandler();         //����ͨ��

/***********************************************************************************************************************************/

void  main(void)
{
      /*���õ�Ƭ������ϵͳ��ʼ��*/
      DisableInterrupts;         //��ֹȫ���ж�
      user_init();
      /*�����жϷ�����*/
      if( DIP7)
      {
        user_menu();   //��������ϵͳ
      }
      car_camera_init();             //����ͷ��ʼ��
      DisableInterrupts;         //��ֹȫ���ж�
      set_vector_handler(PORTD_VECTORn ,PORTD_IRQHandler);    //����PORTE���жϸ�λ����Ϊ PORTE_IRQHandler���жϸ�λ����Ϊ ���������պ�����
      set_vector_handler(PORTB_VECTORn,PORTB_IRQHandler);      //����PORTB���жϸ�λ����Ϊ PORTB_IRQHandler���жϸ�λ����Ϊ ���ж��źŽ��պ�����
      set_vector_handler(PORTC_VECTORn,PORTC_IRQHandler); 
      set_vector_handler(DMA0_VECTORn ,DMA0_IRQHandler);       //����DMA0���жϸ�λ����Ϊ DMA0_IRQHandler���жϸ�λ����Ϊ DMA�źŽ��պ�����
      set_vector_handler(PIT0_VECTORn ,PIT0_IRQHandler);       //����PIT0���жϸ�λ����Ϊ PIT0_IRQHandler���жϸ�λ����Ϊ ������ƺ�����
      set_vector_handler(PIT1_VECTORn ,PIT1_IRQHandler);       //����PIT0���жϸ�λ����Ϊ PIT0_IRQHandler���жϸ�λ����Ϊ ������ƺ�����
      set_vector_handler(PIT3_VECTORn ,PIT3_IRQHandler);       //����PIT0���жϸ�λ����Ϊ PIT0_IRQHandler���жϸ�λ����Ϊ ������ƺ�����
      
      /*���ò��뿪��*/
      
//      if(!DIP6)
//      {
//            erase_flash();
//      }
      if(DIP4)
      {
            double_car_flag=0;
      }
      else
      {
            double_car_flag=1;
      }
      if(DIP5)
      {
            zhengpao=1;
      }
      else
      {
            zhengpao=0;
      }
      
      loop_LOR_flag1=round(other1_a);//��������,1Ϊ����
      loop_LOR_flag2=round(other1_b);
      loop_LOR_flag3=round(other1_c);
      
      dir_overtake_po_1=0;//�µ���������1Ϊǰ��������ͣ��
      dir_overtake_po_2=0;
      po_cnt_S=1;//1����һ���µ�����   2���ڶ����µ���
      
      dir_overtake_start=round(other1_d);
      
      STOP_OUT_able=round(other5_a);
      STOP_PATTERN_able=round(other5_b);
      
      
      /*ִ��ѭ�������*/
      
      bar_range();    //��ȡ�ϰ���������Χ����
      bar_range_loop() ;
      get_weight();   //��ȡ������Ȩֵ����
      tan_angle();    //��ȡtan�Ƕȶ��ձ�
      
      barrier_able=1; //ʹ�������ϰ���
      loop_able=1;
      
      overtake_zhi_sum=round(cnt_a);
      overtake_ring_sum=round(cnt_b);
      overtake_po_sum=round(cnt_c);
      overtake_start_sum=round(cnt_d);
      overtake_cross_sum=round(cnt_e);
      
      run_time=0;     //����ִ��ʱ����ֵ��0
      qibu_flag=1;
      overtake_cross_stop_over=1;
      overtake_po_stop_over=1;
      stop_wait_over=1;
      if(loop_l_r_flag)
      {
            END_LINE_TEMP_delay_time2=30;
      }
      else
      {
            END_LINE_TEMP_delay_time2=60;
      }
      if(!DIP2)
      {
            speed_yun_flag=1;
      }
      /*С��������ѭ��*/
      
      while( 1 )
      {
            switch( car_status )
            {
            case CAR_WAIT:
                  {
                        car_wait();     //С���ȴ�״̬����ʱ��ʹ���жϣ�������ʻģʽ��
                  }
                  break;
            case CAR_RUN:
                  if( DIP0==0 )
                  {
                        if( mt9v032_finish_flag )         //������ͷ�ɼ���һ��ͼ��
                        {
                              //          lptmr_time_start_us();      //��ʼ��ʱ(ns)
                              uint16 copy;                //�����ڱߣ�ʹ���ڴ��ƶ�����������ұ߸�����һ��
                              for( copy=0 ; copy<120 ; copy++ )     //��Լ200US
                              {
                                    memmove(&img[copy][0],&image_h[copy][0],188);  //���ٿ�������ͷ�ɼ���ͼ��
                              }
                              mt9v032_finish_flag=0;      //����ͷ�ɼ���ɱ�־λ��  0
                              barrel_rectification();     //Ͱ��ʧ���������ȡ������ͼ��
                              img_binary();               //ͼ���ֵ������
                              tingche();
                              ring_dir();
                              edge_extract();             //������ȡ
                              get_inv_edge();             //��ȡ��͸�Ӻ��������
                              midline_extract();          //������ȡ
                              car_control();
                              podao_jc();
                              servo_control();            //�������
                              motor_control();            //�������
                              distance_control();
                              //          run_time=lptmr_time_get_us();        //��ȡ��ʱʱ��
                        }
                  }
                  else
                  {
                        if( DIP0==1 )
                        {
                              if( mt9v032_finish_flag )         //������ͷ�ɼ���һ��ͼ��
                              {
                                    //  lptmr_time_start_us();      //��ʼ��ʱ(ns) 
                                    
                                    uint16 copy;                //�����ڱߣ�ʹ���ڴ��ƶ�����������ұ߸�����һ��
                                    for( copy=0 ; copy<120 ; copy++ )     //��Լ200US
                                    {
                                          memmove(&img[copy][0],&image_h[copy][0],188);  //���ٿ�������ͷ�ɼ���ͼ��
                                    }
                                    mt9v032_finish_flag=0;      //����ͷ�ɼ���ɱ�־λ��  0
                                    if(DIP1)
                                    {
                                          barrel_rectification();     //Ͱ��ʧ���������ȡ������ͼ��
                                          //normal_extract();
                                          img_binary();               //ͼ���ֵ������
                                          ring_dir();
                                          edge_extract();             //������ȡ
                                          get_inv_edge();             //��ȡ��͸�Ӻ��������
                                          midline_extract();          //������ȡ
                                          car_control();
                                          podao_jc();
                                          servo_control();            //�������
                                          motor_control();            //�������
                                          distance_control();
                                          
                                          LCD_CAMERA_erzhiSHOW();     //��ʾͼ��  
                                          if(!DIP3)
                                          {
                                                seekfree_sendimg();
                                          }
                                          
                                        
                                          
                                          site.x=25;
                                          site.y=10;
                                          LCD_num_BC(site, (uint32)car_flag,1, BLUE, RED);
                                          site.y=25;
                                          LCD_num_BC(site, (uint32)overtake_ring_flag,1, BLUE, RED);
                                          site.y=40;
                                          LCD_num_BC(site, (uint32)overtake_po_flag,1, BLUE, RED);
                                          site.y=55;
                                          LCD_num_BC(site, (uint32)overtake_cross_flag,1, BLUE, RED);
                                          
                                          site.x=45;
                                         
                                          site.y=55;
                                          LCD_num_BC(site, (uint32)LOOP_TEMP,1, BLUE, RED);
                                          site.y=70;
                                          LCD_num_BC(site, (uint32)LOOP_IN,1, BLUE, RED);
                                          
                                          site.x=65;
                                         
                                          site.y=55;
                                          LCD_num_BC(site, (uint32)img_threshold,3, BLUE, RED);
                                          site.y=70;
                                          LCD_num_BC(site, (uint32)fabsf(CAR_position),2, BLUE, RED);
                                          
                                          site.x=80;
                                          site.y=10;
                                          LCD_num_BC(site, (uint32)(fabsf(out_row[0])),3, BLUE, RED);
                                          site.y=25;
                                          LCD_num_BC(site, (uint32)(loop_able),3, BLUE, RED);
                                          ;            
                                          
                                 
                                    }
                                    else
                                    {
                                          if(DIP2)
                                          {
                                                LCD_CAMERA_show();
                                                if(!DIP3)
                                                {
                                                      seekfree_sendimg();
                                                }
                                          }  
                                          else
                                          {
                                                LCD_CAMERA_BARREL_show();
                                                if(!DIP3)
                                                {
                                                      seekfree_sendimg();
                                                }
                                          }
                                    }
                                    //A_send_B1();
                              }
                        }
                  }
                  break;
            case CAR_STOPP:
                  {
                        //                        disable_irq (PIT1_IRQn);                 //�رյ����ʱ�ж�
                        //                        ftm_pwm_duty(MOTOR_FTM, MOTOR1_PWM,0);
                        //                        ftm_pwm_duty(MOTOR_FTM, MOTOR2_PWM,0);
                        //                        ftm_pwm_duty(MOTOR_FTM, MOTOR3_PWM,0);
                        //                        ftm_pwm_duty(MOTOR_FTM, MOTOR4_PWM,0);
                              if( mt9v032_finish_flag )         //������ͷ�ɼ���һ��ͼ��
                              {
                                    uint16 copy;                //�����ڱߣ�ʹ���ڴ��ƶ�����������ұ߸�����һ��
                                    for(copy=0; copy<120; copy++)     //��Լ200US
                                    {
                                          memmove(&img[copy][0],&image_h[copy][0],188);  //���ٿ�������ͷ�ɼ���ͼ��
                                    }
                                    mt9v032_finish_flag=0;      //����ͷ�ɼ���ɱ�־λ��  0
                                    barrel_rectification();     //Ͱ��ʧ���������ȡ������ͼ��
                                    img_binary();               //ͼ���ֵ������
                                    //tingche2();
                                    ring_dir();
                                    
                                    edge_extract();             //������ȡ
                                    get_inv_edge();             //��ȡ��͸�Ӻ��������
                                    midline_extract();          //������ȡ
                                    car_control();
                                   // podao_jc();
                                    servo_control();            //�������
                                    motor_control();            //�������
                                    distance_control();
                                    if(QAQ_STOP)
                                    {
                                          LCD_CAMERA_erzhiSHOW();
                                    }
                                    
                              }
                        }
                  break;
            default:
                  break;
            }
            
            if( END_LINE_TEMP==1 )
            {
                  if(( end_line_row>=50 || end_line_row==-1 ) &&(abs(speedout_val)>=4*10000))
                  {
                        if(!double_car_flag)
                        {
                              //END_LINE_TEMP_delay_flag2=1;
                              car_status = CAR_STOPP;
                              END_LINE_TEMP=0;
                              END_LINE_TEMP_1=0;
                              end_line_row=-1;     //�յ�����������  -1
                        }
                        else
                        {
                              if(!speedout_val5_flag)
                              {
                                    speedout_val5_flag=1;
                                    speedout_val5=speedout_val;
                              }
                        }
                  }
            }
            if(speedout_val5_flag && (((abs(speedout_val-speedout_val5)>=1*10000) && !car_flag) || ((abs(speedout_val-speedout_val5)>=0*10000) && car_flag)))
            {
                  //END_LINE_TEMP_delay_flag2=1;
                  car_status = CAR_STOPP;
                  END_LINE_TEMP=0;
                  END_LINE_TEMP_1=0;
                  end_line_row=-1;     //�յ�����������  -1
            }
      }
}

/***********************************************************************************************************************************/

void PORTB_IRQHandler(void)     //���жϽ����жϷ�����
{
      PORTB_ISFR = (1<<16);      //ʹ��DMA
      DMA_EN(DMA_CH0); 
      VSYNC();
      
}

/***********************************************************************************************************************************/

void DMA0_IRQHandler(void)      //DMA�ɼ�����жϷ�����
{
      DMA_IRQ_CLEAN(DMA_CH0);
      row_finished();
}

/***********************************************************************************************************************************/

void PIT0_IRQHandler()           //�������жϷ�����
{
      if(servo_enable)
      {
            servo_output();        //�����ȳ�ʼ���Ժ󣬲������PWM��
      }
      
      PIT_Flag_Clear(PIT0);  //���жϱ�־λ
}

/***********************************************************************************************************************************/

void PIT1_IRQHandler()           //�������жϷ�����
{
      speedout_count=ftm_quad_get(FTM2);  //��ȡ  FTM2 ������ ��������
      ftm_quad_clean(FTM2);                 //��λ FTM2 �������� ��������
      speedout_val+=speedout_count;
      if(motor_enable)
      {
            motor_control_pit();        //�������ʽPID����
            motor_output();             //�����ȳ�ʼ���Ժ󣬲������PWM��
      }
      
      PIT_Flag_Clear(PIT1);       //���жϱ�־λ
}

/***********************************************************************************************************************************/

void PIT3_IRQHandler()
{
      
      //----------��ʱͣ��-----------//
      if(!DIP3)
      {
            if(stoptime>=(50*10))
                  car_stop_flag=1;
            
            else
                  stoptime++;
      }
      else
      {
            if(stoptime!=0)
            {
                  car_stop_flag=0;
                  stoptime=0;
            }
      }
      
      
      
      //--------��ʱ�����������--------//
      if(barrier_able_flag)
      {
            if(barrier_time>=BARRIER_TIME1)
            {
                  barrier_time=0;
                  barrier_able_flag=0;
                  barrier_able=0;
                  barrier_ing_flag=0;
            }
            else
                  barrier_time++;
      }
      else
            barrier_time=0;
      
      
      //----------��������־-----------//
      if(chaoshengbo_delay_cnt1== CHAOSHENGBODELAY_TIME1)
      {
            chaoshengbo_flag=0;
      }
      else
            chaoshengbo_delay_cnt1++;
      
      
      //----------����ͨ��ʱ������-------//
      if(send_start_flag)
      {
            if(send_error>=25)
            {
                  send_error_flag=1;
                  send_error=0;
            }
            else
            {
                  send_error++;
                  send_error_flag=0;
            }
      }
      else
      {
            send_error=0;
            send_error_flag=0;
      }
      
      //-----------������-----------//
      if(Bee_flag)
      {
            if(Bee_time>=2)
            {
                  Bee_time=0;
                  Bee_flag=0;
            }
            else
            {
                  Bee_time++;
            }
      }
      
      
      PIT_Flag_Clear(PIT3);       //���жϱ�־λ
}

/***********************************************************************************************************************************/

void PORTD_IRQHandler(void)     //�������ɼ��жϷ�����
{
      PORT_FUNC(D,7,chaoshengbo);
}

/***********************************************************************************************************************************/

void PORTC_IRQHandler()//����ͨ��
{
      uint8  n;    //���ź�
      uint32 flag;
      flag = PORTC_ISFR;
      PORTC_ISFR  = ~0;                                   //���жϱ�־λ
      n = 10;
      if(flag & (1 << n))                                 //PTE27�����ж�
      {
            nrf_handler();
      }
}

/***********************************************************************************************************************************/



