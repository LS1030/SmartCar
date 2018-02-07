#include "include.h"

void correspond_init();
void correspond_send();
void correspond_read();
void  A_send_B();
void  B_send_A();
void  A_read_B();
void  B_read_A();


uint32 i=0;
uint8 relen;
uint8 buff_tx[DATA_PACKET];//(1,0,0,1)Ϊǰ��������,(1,0,1,0)Ϊ��ǰ��������ǰ��,(0,1,1,0)Ϊ�󳵷���ǰ��,
//����λΪ�µ���������λ������λΪֱ������λ,����λΪ����,�ڰ�λΪ��������,�ھ�λΪͣ������ʮλΪ����ͣ��
uint8 buff_rx[DATA_PACKET];
uint8 nrf_flag=0;
uint8 nrf_send_finish_flag=0;
uint8 nrf_read_finish_flag=0;

uint8 nrf_send_delay_flag1;
int16 nrf_send_delay_cnt1;
uint8 STOP_OUT_able=0;
uint8 Q_loop_able=0;

void correspond_init()
{
      while(!nrf_init())                 //��ʼ��NRF24L01+ ,�ȴ���ʼ���ɹ�Ϊֹ
      {
            Site_t site = {10,20};   //x = 10 ,y = 20
            LCD_str(site,"NRF error!!!", BLUE,RED);
      }
      nrf_flag = 1;
      
}
void correspond_send()
{
      
      
      if(nrf_tx(buff_tx,DATA_PACKET) == 1 )          //����һ�����ݰ���buff����Ϊ32�ֽڣ�
      {
            while(nrf_tx_state() == NRF_TXING);//�ȴ��������
            if( NRF_TX_OK == nrf_tx_state () )
            {
                  nrf_send_finish_flag=1;
            }
            else
            {
                  nrf_send_finish_flag=0;
            }
      }
      else
      {
            nrf_send_finish_flag=0;
      }
}
void correspond_read()
{    
      nrf_read_finish_flag=0;  
      relen = nrf_rx(buff_rx,DATA_PACKET);               //�ȴ�����һ�����ݰ������ݴ洢��buff��
      if(relen != 0)
      {
            nrf_read_finish_flag=1;            //��ӡ���յ�������
      } 
}

void  A_send_B()
{
      uint8 temp[DATA_PACKET]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
      temp[0]=1;temp[1]=0;temp[2]=0;temp[3]=1;
      
      if(Q_H_overtake_po_flag)//�µ�����
      {temp[4]=1;}
      else
      {temp[4]=0;}
      if(Q_H_overtake_cross_flag)//ʮ�ֳ���
      {temp[5]=1;}
      else if(Q_H_stop_ok)//ʮ��ǰ�����߳ɹ�
      {temp[5]=2;}
      else
      {temp[5]=0;}
      if(Q_H_obstacle_flag)//���ϰ�
      {temp[6]=1;}
      else
      {temp[6]=0;}
      if(Q_H_overtake_ring_flag)//ǰ����ͣ
      {temp[7]=1;}
      else
      {temp[7]=0;}
      
      if(STOP_PATTERN)
      {temp[8]=1;}
      else
      {temp[8]=0;}
      if(QAQ_STOP)//����ͣ��
      {temp[9]=1;}
      else
      {temp[9]=0;}
      
      if(LOOP_TEMP)//ʹ�ܺ󳵻������
      {temp[17]=1;}
      else
      {temp[17]=2;}
      if(LOR_turn_flag1)//����ͣ������
      {temp[18]=1;}
      else
      {temp[18]=2;}
      
      memcpy(buff_tx,temp, DATA_PACKET* sizeof( uint8));
      correspond_send();
}
void  B_send_A()//�����������ɹ�
{
      uint8 temp[DATA_PACKET]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
      
      temp[0]=0;temp[1]=1;temp[2]=1;temp[3]=0;
      
      if(H_Q_overtake_ring_flag)//�󳵳���
      {temp[7]=1;}
      else if(H_Q_overtake_outrow_flag)//�󳵿���������
      {temp[7]=2;}
      else
      {temp[7]=0;}
      
      if(QAQ_STOP)//����ͣ��
      {temp[9]=1;}
      else
      {temp[9]=0;}
      
      temp[10]=(((uint16) car_distance) & 0xFF00)>>8;
      temp[11]=((uint16) car_distance) & 0x00FF;
      if(chaoshengbo_flag)
      {temp[12]=1;}
      else
      {temp[12]=2;}
      if((car_extract_row>0) || (END_LINE_TEMP &&(abs(speedout_val)>=4*10000)))
      {temp[13]=1;}
      else
      {temp[13]=2;}
      
      if(overtake_ok_flag)//���ܳ����ɹ�
      {temp[28]=1;}
      else
      {temp[28]=0;}
      if(overtake_start_ok)//�����ϰ������ɹ�
      {temp[29]=1;}
      else
      {temp[29]=0;}
      if(overtake_cross_ok)//ʮ�ֳ����ɹ�
      {temp[30]=1;}
      else
      {temp[30]=0;}
      if(overtake_po_ok)//�µ������ɹ�
      {temp[31]=1;}
      else
      {temp[31]=0;}
      
      memcpy(buff_tx,temp, DATA_PACKET* sizeof( uint8));
      correspond_send();
}
void  A_read_B()
{
      correspond_read();
      uint16 i=0,j=0;
      //------------------------------------����������-----------------------------------//
      if((buff_rx[0]==0)&&(buff_rx[1]==1)&&(buff_rx[2]==1)&&(buff_rx[3]==0)&&(buff_rx[12]==1))
      {
            H_csb_get=1;
            if((buff_rx[0]==0)&&(buff_rx[1]==1)&&(buff_rx[2]==1)&&(buff_rx[3]==0))
            {
                  i=((uint16)buff_rx[10])<<8;
                  j=buff_rx[11];
                  Q_distance=i + j;
            }
      }
      else if((buff_rx[0]==0)&&(buff_rx[1]==1)&&(buff_rx[2]==1)&&(buff_rx[3]==0)&&(buff_rx[12]==2))
      {
            H_csb_get=0;
      }
      if((buff_rx[0]==0)&&(buff_rx[1]==1)&&(buff_rx[2]==1)&&(buff_rx[3]==0)&&(buff_rx[13]==1))
      {
            H_QC_get=1;
      }
      else if((buff_rx[0]==0)&&(buff_rx[1]==1)&&(buff_rx[2]==1)&&(buff_rx[3]==0)&&(buff_rx[13]==2))
      {
            H_QC_get=0;
      }
      //------------------------------------���ܳ����ɹ�-----------------------------------//
      if((buff_rx[0]==0)&&(buff_rx[1]==1)&&(buff_rx[2]==1)&&(buff_rx[3]==0)&&(buff_rx[28]==1))
      {
            overtake_start_flag=0;//�˳�����ģʽ
            
            speedout_val0_flag=0;
            START_LINE_TEMP=0;//���־
            
            car_stop_flag=0;//�������м���ʻ
            car_R_pull_over_flag=0;
            car_L_pull_over_flag=0;
             keep_side=0;
            car_flag=1;//���
            gpio_set(PORT_CSB, 0);
            barrier_able=0;//���ϰ����
            
            nrf_read_finish_flag=1;
      }
      else
            nrf_read_finish_flag=0;
      //-----------------------------------�����ϰ������ɹ�------------------------------------//
      if((buff_rx[0]==0)&&(buff_rx[1]==1)&&(buff_rx[2]==1)&&(buff_rx[3]==0)&&(buff_rx[29]==1))
      {
            overtake_start_flag=0;
            LOR_turn_send_ok=0;
            
            car_stop_flag=0;//�������м���ʻ
            car_R_pull_over_flag=0;
            car_L_pull_over_flag=0;
            keep_side=0;
            car_flag=1;//���
            keep_side=0;
            gpio_set(PORT_CSB, 0);
            barrier_able=0;//���ϰ����
            
            nrf_read_finish_flag=1;
      }
      else
            nrf_read_finish_flag=0;
      //-----------------------------------ʮ�ֳ����ɹ�------------------------------------//
      if((buff_rx[0]==0)&&(buff_rx[1]==1)&&(buff_rx[2]==1)&&(buff_rx[3]==0)&&(buff_rx[30]==1))
      {
            overtake_cross_flag=0;
            overtake_cross_stop=0;
            overtake_cross_stop_over=1;
            bangbang_tingcnt=0;
            Q_overtake_cross=0;
            speedout_val_cross_flag=0;
            speedout_val_cross_ting_flag=0;
            Q_H_stop_ok=0;
            
            car_stop_ing_flag=0;
            car_stop_flag=0;
            cross_jian=0; 
            qibu_flag=1;
            car_R_pull_over_flag=0;
            car_L_pull_over_flag=0;
            keep_side=0;
            car_flag=1;
            gpio_set(PORT_CSB, 0);
            barrier_able=0;//���ϰ����
            
            overtake_cross_sum--;
            
            in_curve_flag=1;
            if(L_TURN )
            {
                  in_L_curve_flag=1;
            }
            else
            {
                  in_R_curve_flag=1;
            }
      }
      else
            nrf_read_finish_flag=0;
      //-----------------------------------�µ������ɹ�------------------------------------//
      if((buff_rx[0]==0)&&(buff_rx[1]==1)&&(buff_rx[2]==1)&&(buff_rx[3]==0)&&(buff_rx[31]==1))
      {
            car_stop_ing_flag=0;
            car_stop_flag=0;
            overtake_po_stop=0;
            overtake_po_stop_over=1;
            qibu_flag=1;
            overtake_po_flag=0;//�������˳�ģʽ
            
            speedout_val_po_flag=0;
            speedout_val_po_flag=0;//���־λ
            car_R_pull_over_flag=0;
            car_L_pull_over_flag=0;
            keep_side=0;       
            po_pull_over=0;
            car_flag=1;//����ǰ��
            gpio_set(PORT_CSB, 0);
            barrier_able=0;
            
            overtake_po_sum--;//���������Լ�
            down_flag=0;
      }
      else
            nrf_read_finish_flag=0;
      
      //-------------------------------------------------------------------------//
      if((buff_rx[0]==0)&&(buff_rx[1]==1)&&(buff_rx[2]==1)&&(buff_rx[3]==0)&&(buff_rx[7]==1))//�󳵳���
      {
            overtake1_ring_ok_flag=1;
            nrf_read_finish_flag=1;
      }
      else if((buff_rx[0]==0)&&(buff_rx[1]==1)&&(buff_rx[2]==1)&&(buff_rx[3]==0)&&(buff_rx[7]==2))//�󳵿���������
      {
            overtake_outrow_flag=1;
            nrf_read_finish_flag=1;
      }
      else
            nrf_read_finish_flag=0;
      
      //-------------------------------------------------------------------------//
      if((buff_rx[0]==0)&&(buff_rx[1]==1)&&(buff_rx[2]==1)&&(buff_rx[3]==0)&&(buff_rx[9]==1))//����ͣ��
      {
            if(STOP_OUT_able)
            {
                  car_status = CAR_STOPP;
            }
            else
            {
                  double_car_flag=0;
                  car_L_pull_over_flag=0;
                  car_R_pull_over_flag=0;
                  car_stop_flag=0;
                  car_stop_ing_flag=0;
                  car_status = CAR_RUN;
            }
      }
      
      clean_buff_rx;
}

void  B_read_A()
{
      correspond_read();
      
      //-----------------------------------ʹ�ܺ󳵻������------------------------------------//
      if((buff_rx[0]==1)&&(buff_rx[1]==0)&&(buff_rx[2]==0)&&(buff_rx[3]==1)&&(buff_rx[17]==1))
      {
            Q_loop_able=1;
      }
      else if((buff_rx[0]==1)&&(buff_rx[1]==0)&&(buff_rx[2]==0)&&(buff_rx[3]==1)&&(buff_rx[17]==2))
      {
            Q_loop_able=0;
      }
      //-----------------------------------����ͣ������------------------------------------//
      if((buff_rx[0]==1)&&(buff_rx[1]==0)&&(buff_rx[2]==0)&&(buff_rx[3]==1)&&(buff_rx[18]==1))
      {
            LOR_turn_flag2=1;
      }
      else if((buff_rx[0]==1)&&(buff_rx[1]==0)&&(buff_rx[2]==0)&&(buff_rx[3]==1)&&(buff_rx[18]==2))
      {
            LOR_turn_flag2=0;
      }
      //----------------------------------�µ�����-------------------------------------//
      if((buff_rx[0]==1)&&(buff_rx[1]==0)&&(buff_rx[2]==0)&&(buff_rx[3]==1)&&(buff_rx[4]==1))
      {
            overtake_po_flag=1;
            nrf_read_finish_flag=1;
      }
      else
            nrf_read_finish_flag=0;
      //-----------------------------------ʮ�ֳ���------------------------------------//
      if((buff_rx[0]==1)&&(buff_rx[1]==0)&&(buff_rx[2]==0)&&(buff_rx[3]==1)&&(buff_rx[5]==1))
      {
            overtake_cross_flag=1;
            nrf_read_finish_flag=1;
      }
      else if((buff_rx[0]==1)&&(buff_rx[1]==0)&&(buff_rx[2]==0)&&(buff_rx[3]==1)&&(buff_rx[5]==2))//ʮ��ǰ�����߳ɹ�
      {
            Q_stop_ok=1;
            nrf_read_finish_flag=1;
      }
      else
            nrf_read_finish_flag=0;
      //-----------------------------------��������------------------------------------//
      if((buff_rx[0]==1)&&(buff_rx[1]==0)&&(buff_rx[2]==0)&&(buff_rx[3]==1)&&(buff_rx[6]==1))
      {
            barrier_able_flag=1;//��������
            nrf_read_finish_flag=1;
      }
      else
            nrf_read_finish_flag=0;
      //-----------------------------------������ǰ����ͣ------------------------------------//
      if((buff_rx[0]==1)&&(buff_rx[1]==0)&&(buff_rx[2]==0)&&(buff_rx[3]==1)&&(buff_rx[7]==1))
      {
            ringout_able_flag=1;
            nrf_read_finish_flag=1;
      }
      else
            nrf_read_finish_flag=0;
      
      //-------------------------------------ͣ��-------------------------------------//
      if((buff_rx[0]==1)&&(buff_rx[1]==0)&&(buff_rx[2]==0)&&(buff_rx[3]==1)&&(buff_rx[8]==1))
      {
            STOP_PATTERN=1;
      }
      else
            nrf_read_finish_flag=0;
      
#if 1      //--------------------------------����ͣ��----------------------------------//
      if((buff_rx[0]==1)&&(buff_rx[1]==0)&&(buff_rx[2]==0)&&(buff_rx[3]==1)&&(buff_rx[9]==1))
      {
            if(STOP_OUT_able)
            {
                  car_status = CAR_STOPP;
            }
            else
            {
                  double_car_flag=0;
                  car_L_pull_over_flag=0;
                  car_R_pull_over_flag=0;
                  car_stop_flag=0;
                  car_stop_ing_flag=0;
                  car_status = CAR_RUN;
            }
      }
#endif      
      clean_buff_rx;
}

//-----------------------------����ͨ��Э��--------------------------------//
#if 1
uint32 A_send_B0_flag=0,B_read_A0_flag=0,B_send_A0_flag=0,A_read_B0_flag=0;

void  A_send_B0()
{
      uint8 temp[DATA_PACKET]={0,0,1,1};//���󷢳�
      A_send_B0_flag++;
      memcpy(buff_tx,temp, 4* sizeof( uint8));
      correspond_send();
}
void  B_read_A0()
{
      B_read_A0_flag++;
      correspond_read();
      if((buff_rx[0]==0)&&(buff_rx[1]==0)&&(buff_rx[2]==1)&&(buff_rx[3]==1))
      {
            while(!nrf_send_finish_flag)
            {
                  send_start_flag=1;
                  B_send_A0();
                  if(send_error_flag && !nrf_send_finish_flag)
                  {
                        nrf_read_finish_flag=0;
                        break;
                  }
            }
            send_start_flag=0;
            send_error=0;
            send_error_flag=0;
            if(nrf_send_finish_flag)
                  car_start_flag=0;
      }
      else
            nrf_read_finish_flag=0;
      clean_buff_rx;
}   
void  B_send_A0()
{
      uint8 temp[DATA_PACKET]={1,1,0,0};//1,0ǰ����0,1���ֺ󳵣�1�����ɹ�
      B_send_A0_flag++;
      memcpy(buff_tx,temp, 4 * sizeof( uint8));
      correspond_send();
}
void  A_read_B0()
{
      A_read_B0_flag++;
      correspond_read();
      if((buff_rx[0]==1)&&(buff_rx[1]==1)&&(buff_rx[2]==0)&&(buff_rx[3]==0))
      {
            car_start_flag=0;
      }
      else
            nrf_read_finish_flag=0;
      clean_buff_rx;
}
#endif