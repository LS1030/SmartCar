#include "include.h"
#include "common.h"

/***********************************************************************************************************************************/
uint32 jizhun_step=1;
uint32 JIZHUN_ROW=30;      //����Ȩֵ��
uint32 JIZHUN_UP=11;       //����ƫ������߽�ȡ���ֵ��ϱ߽�14
uint32 JIZHUN_DOWN=31;     //����ƫ������߽�ȡ���ֵ��±߽�34

uint32 servo_m_step=1;
uint32 SERVO_MID=718;      // 656
uint32 SERVO_L=789;        //�������  (��ʽ�����
uint32 SERVO_R=645;        //����Ҽ��� ����ʽ�����

double servo_step=1;
double servo_a=0.15;
double servo_b=0.95;
double servo_c=2.0;
double servo_d=2.0;
double servo_e=0;
double servo_f=1.2;
/***********************************************************************************************************************************/

double servo_Kp;           //��� Pϵ��
double servo_Ki;           //��� Iϵ��
double servo_Kd;           //��� Dϵ��
double L_R_servo_K=0;      //��� ����ת����ϵ��
double middle_Error[2]={0x0,0x0};    //���ƫ��洢����
double midline_avg;        //������ƽ��ֵ
double midline_sum;        //�������ۼ�ֵ
double inv_wide[CAMERA_H];  //��������Ȩֵ�м����
double inv_weight[CAMERA_H];//������Ȩֵ����
int16 midline_use_cnt=0;    //��ƫ��������ʹ�ø���

int16 servo_adj=718;        //�������м����
int16 servo_out=718;        //������ֵ

int16 pull_over_row;        //С������ͣ��ǰհ��
int16 pull_over_row_cross;
int16 pull_over_row_po;
int16 pull_over_row_barrier;
int16 pull_over_row_qi;
uint32 JIZHUN_UP_TEMP;     //����ƫ������߽�ȡ���ֵ��ϱ߽�26
uint32 JIZHUN_DOWN_TEMP;   //����ƫ������߽�ȡ���ֵ��±߽�35
/***********************************************************************************************************************************/

void servo_control();   //�������������
void get_weight();      //������Ȩֵ��ȡ����
void middle_avg();      //�����߼�Ȩƽ����ƫ���
void PID_control();     //���PID����
/***********************************************************************************************************************************/

void servo_control()
{ 
  middle_avg();
  if( midline_use_cnt>=3 )
  {
    PID_control();
    
    if( servo_adj<=SERVO_L && servo_adj>=SERVO_R )
    {
      servo_adj=round(servo_adj);
    }
    else
    {
      if( servo_adj>SERVO_L )
      {
        servo_adj=SERVO_L;
      }
      if( servo_adj<SERVO_R )
      {
        servo_adj=SERVO_R;
      }
    }
  }
  else    //����������������ʱ
  {
    if( L_TURN )   //���ж�Ϊ����ʱ�������
    {
      servo_adj=SERVO_L;
    }
    else
    {
      if( R_TURN )    //���ж�Ϊ����ʱ���Ҵ���
      {
        servo_adj=SERVO_R;
      }
      else    //��δ�жϳ�������ʱ
      {
        if( R_EDGE_NUM>L_EDGE_NUM )    //�ұ��ض����ж�Ϊ����
        {
          servo_adj=SERVO_L;
        }
        else
        {
          if( L_EDGE_NUM>R_EDGE_NUM )    //����ض����ж�Ϊ����
          {
            servo_adj=SERVO_R;
          }
        }
      }
    }
  }
  servo_out=servo_adj;
}

/***********************************************************************************************************************************/

void get_weight()
{
  int16 ii;
  double x0=0.0,x1=0.0;
  Site_xy1 xy;
  
  
  for( ii=ROW_START ; ii<=ROW_END ; ii++ )
  {
    inv_weight[ii]=inv_distance[ii];
  }
  
  L_R_servo_K=((double)(SERVO_MID)-(double)(SERVO_R))/((double)(SERVO_L)-(double)(SERVO_MID));
  
  xy=get_invinv_img( pull_over_dis , 0 );
  pull_over_row=xy.x;
  xy=get_invinv_img( pull_over_dis_cross , 0 );
  pull_over_row_cross=xy.x;
  xy=get_invinv_img( pull_over_dis_po , 0 );
  pull_over_row_po=xy.x;
  xy=get_invinv_img( pull_over_dis_qi , 0 );
  pull_over_row_qi=xy.x;
 
}

/***********************************************************************************************************************************/
void middle_avg()      //���߼�Ȩ��ƫ���
{
  uint8 i=0;
  midline_sum=0.0;
  midline_use_cnt=0;
  double x1=0.0;
  if(qibu_flag && (motor_goal>=100))
  {
      if(speedout_count>=-200)
      {
        for( i=ROW_END ; i>=pull_over_row_qi ; i-- ) 
        {
          if( midline[i]!=-1 )
          {
            midline_sum=midline_sum+inv_weight[i]*midline[i];
            x1=x1+inv_weight[i];
            midline_use_cnt++;
          }
          else
          {
            if( L_TURN )
            {
              midline_sum=midline_sum;
              x1=x1+inv_weight[i];
              midline_use_cnt++;
            }
            if( R_TURN )
            {
              midline_sum=midline_sum+inv_weight[i]*COL_END;
              x1=x1+inv_weight[i];
              midline_use_cnt++;
            }
          }
        }
        
      }
      else
      {
        JIZHUN_DOWN_TEMP=round(JIZHUN_DOWN+(motor_goal+speedout_count)/(other2_e*10));
        if(JIZHUN_DOWN_TEMP>=ROW_END)
        {
          JIZHUN_DOWN_TEMP=ROW_END;
        }
        if(JIZHUN_DOWN_TEMP<=JIZHUN_DOWN)
        {
          JIZHUN_DOWN_TEMP=JIZHUN_DOWN;
        }
        JIZHUN_UP_TEMP=round(JIZHUN_UP+(motor_goal+speedout_count)/(other2_e*10));
        if(JIZHUN_UP_TEMP>=pull_over_row_qi)
        {
          JIZHUN_UP_TEMP=pull_over_row_qi;
        }
        if(JIZHUN_UP_TEMP<=JIZHUN_UP)
        {
          JIZHUN_UP_TEMP=JIZHUN_UP;
        }
        
        for( i=JIZHUN_DOWN_TEMP ; i>=JIZHUN_UP_TEMP ; i-- ) 
        {
          if( midline[i]!=-1 )
          {
            midline_sum=midline_sum+inv_weight[i]*midline[i];
            x1=x1+inv_weight[i];
            midline_use_cnt++;
          }
          else
          {
            if( L_TURN )
            {
              midline_sum=midline_sum;
              x1=x1+inv_weight[i];
              midline_use_cnt++;
            }
            if( R_TURN )
            {
              midline_sum=midline_sum+inv_weight[i]*COL_END;
              x1=x1+inv_weight[i];
              midline_use_cnt++;
            }
          }
        }
        
      }
    
  }
  else
  {
    if(car_status==CAR_STOPP)
    {
      if( L_barrier_flag==1 || R_barrier_flag==1 )   //��Ϊ�ϰ�ʱ
      { 
        for( i=JIZHUN_DOWN; i>=JIZHUN_UP; i-- )      //�����߷�Χȡ�ϰ��ﴦ���������߼�Ȩƽ��ֵ
        {
          if( midline[i]!=-1 )
          {
            midline_sum=midline_sum+inv_weight[i]*midline[i];
            x1=x1+inv_weight[i];
            midline_use_cnt++;
          }
          else
          {
            if( L_TURN )
            {
              midline_sum=midline_sum;
              x1=x1+inv_weight[i];
              midline_use_cnt++;
            }
            if( R_TURN )
            {
              midline_sum=midline_sum+inv_weight[i]*COL_END;
              x1=x1+inv_weight[i];
              midline_use_cnt++;
            }
          }
          
        }
      }
      else
      {
        if(speedout_count>=-200)
        {
          for( i=ROW_END ; i>=pull_over_row_qi ; i-- ) 
          {
            if( midline[i]!=-1 )
            {
              midline_sum=midline_sum+inv_weight[i]*midline[i];
              x1=x1+inv_weight[i];
              midline_use_cnt++;
            }
            else
            {
              if( L_TURN )
              {
                midline_sum=midline_sum;
                x1=x1+inv_weight[i];
                midline_use_cnt++;
              }
              if( R_TURN )
              {
                midline_sum=midline_sum+inv_weight[i]*COL_END;
                x1=x1+inv_weight[i];
                midline_use_cnt++;
              }
            }
          }
          
        }
        else
        {
          JIZHUN_DOWN_TEMP=round(JIZHUN_DOWN+(motor_goal+speedout_count)/(other2_e*10));
          if(JIZHUN_DOWN_TEMP>=ROW_END)
          {
            JIZHUN_DOWN_TEMP=ROW_END;
          }
          if(JIZHUN_DOWN_TEMP<=JIZHUN_DOWN)
          {
            JIZHUN_DOWN_TEMP=JIZHUN_DOWN;
          }
          JIZHUN_UP_TEMP=round(JIZHUN_UP+(motor_goal+speedout_count)/(other2_e*10));
          if(JIZHUN_UP_TEMP>=pull_over_row_qi)
          {
            JIZHUN_UP_TEMP=pull_over_row_qi;
          }
          if(JIZHUN_UP_TEMP<=JIZHUN_UP)
          {
            JIZHUN_UP_TEMP=JIZHUN_UP;
          }
          
          for( i=JIZHUN_DOWN_TEMP ; i>=JIZHUN_UP_TEMP ; i-- ) 
          {
            if( midline[i]!=-1 )
            {
              midline_sum=midline_sum+inv_weight[i]*midline[i];
              x1=x1+inv_weight[i];
              midline_use_cnt++;
            }
            else
            {
              if( L_TURN )
              {
                midline_sum=midline_sum;
                x1=x1+inv_weight[i];
                midline_use_cnt++;
              }
              if( R_TURN )
              {
                midline_sum=midline_sum+inv_weight[i]*COL_END;
                x1=x1+inv_weight[i];
                midline_use_cnt++;
              }
            }
          }
          
        }
      }
      
    }
    
    else
    {
      if( LOOP_TEMP==1 )   //��Ϊ����ʱ
      {
        if(car_stop_ing_flag|| car_stop_flag)
        {
          
          for( i=other2_d*10; i>=other2_c*10; i-- )   //�����߷�Χ��ͨ�����������������߼�Ȩƽ��ֵ
          {
            if( midline[i]!=-1 )
            {
              midline_sum=midline_sum+inv_weight[i]*midline[i];
              x1=x1+inv_weight[i];
              midline_use_cnt++;
            }
            else
            {
              if( L_TURN )
              {
                midline_sum=midline_sum;
                x1=x1+inv_weight[i];
                midline_use_cnt++;
              }
              if( R_TURN )
              {
                midline_sum=midline_sum+inv_weight[i]*COL_END;
                x1=x1+inv_weight[i];
                midline_use_cnt++;
              }
            }
          }
          
        }
        else if((LOOP_IN==0) ||( out_row[0]!=-1 ))
        {
          JIZHUN_DOWN_TEMP=JIZHUN_DOWN;//+10;
          if(JIZHUN_DOWN_TEMP>=ROW_END)
          {
            JIZHUN_DOWN_TEMP=ROW_END;
          }
          for( i=JIZHUN_DOWN_TEMP; i>=JIZHUN_UP; i-- )   //�����߷�Χ��ͨ�����������������߼�Ȩƽ��ֵ
          {
            if( midline[i]!=-1 )
            {
              midline_sum=midline_sum+inv_weight[i]*midline[i];
              x1=x1+inv_weight[i];
              midline_use_cnt++;
            }
            else
            {
              if( L_TURN )
              {
                midline_sum=midline_sum;
                x1=x1+inv_weight[i];
                midline_use_cnt++;
              }
              if( R_TURN )
              {
                midline_sum=midline_sum+inv_weight[i]*COL_END;
                x1=x1+inv_weight[i];
                midline_use_cnt++;
              }
            }
          }
        }
        
        else     
        {
          for( i=JIZHUN_DOWN; i>=JIZHUN_UP; i-- )   //�����߷�Χ��ͨ�����������������߼�Ȩƽ��ֵ
          {
            if( midline[i]!=-1 )
            {
              midline_sum=midline_sum+inv_weight[i]*midline[i];
              x1=x1+inv_weight[i];
              midline_use_cnt++;
            }
            else
            {
              if( L_TURN )
              {
                midline_sum=midline_sum;
                x1=x1+inv_weight[i];
                midline_use_cnt++;
              }
              if( R_TURN )
              {
                midline_sum=midline_sum+inv_weight[i]*COL_END;
                x1=x1+inv_weight[i];
                midline_use_cnt++;
              }
            }
          }
        }
      }
      else
      {
        if( car_L_pull_over_flag==1 || car_R_pull_over_flag==1 )   //��Ϊ����ģʽʱ
        {
          if( po_pull_over)   //��Ϊ���»�����ʱ
          {
            for( i=ROW_END ; i>=pull_over_row_po ; i-- )   //�����߷�Χ��ͨ�����������������߼�Ȩƽ��ֵ
            {
              
              if( midline[i]!=-1 )
              {
                midline_sum=midline_sum+inv_weight[i]*midline[i];
                x1=x1+inv_weight[i];
                midline_use_cnt++;
              }   
              
            }
          }
          
          else if(overtake_cross_flag)
          {
            if(!qibu_flag)
            {
              for( i=ROW_END ; i>=pull_over_row_cross ; i-- )   //�����߷�Χ��ͨ�����������������߼�Ȩƽ��ֵ
              {
                if( midline[i]!=-1 )
                {
                  midline_sum=midline_sum+inv_weight[i]*midline[i];
                  x1=x1+inv_weight[i];
                  midline_use_cnt++;
                }
                else
                {
                  if( L_TURN )
                  {
                    midline_sum=midline_sum;
                    x1=x1+inv_weight[i];
                    midline_use_cnt++;
                  }
                  if( R_TURN )
                  {
                    midline_sum=midline_sum+inv_weight[i]*COL_END;
                    x1=x1+inv_weight[i];
                    midline_use_cnt++;
                  }
                }
                
              }
            }
            else
            {
              for( i=ROW_END ; i>=pull_over_row_cross ; i-- )   //�����߷�Χ��ͨ�����������������߼�Ȩƽ��ֵ
              {
                if( midline[i]!=-1 )
                {
                  midline_sum=midline_sum+inv_weight[i]*midline[i];
                  x1=x1+inv_weight[i];
                  midline_use_cnt++;
                }
              }
              
            }
          }
          else
          {
            for( i=ROW_END ; i>=pull_over_row ; i-- )   //�����߷�Χ��ͨ�����������������߼�Ȩƽ��ֵ
            {
              if( midline[i]!=-1 )
              {
                midline_sum=midline_sum+inv_weight[i]*midline[i];
                x1=x1+inv_weight[i];
                midline_use_cnt++;
              }
              else
              {
                if( L_TURN )
                {
                  midline_sum=midline_sum;
                  x1=x1+inv_weight[i];
                  midline_use_cnt++;
                }
                if( R_TURN )
                {
                  midline_sum=midline_sum+inv_weight[i]*COL_END;
                  x1=x1+inv_weight[i];
                  midline_use_cnt++;
                }
              }
            }
          }
        }
        else
        {
          if( up_flag==1 || down_flag==1 )   //��Ϊ���»�����ʱ
          {
            for( i=ROW_END ; i>=pull_over_row_po ; i-- )   //�����߷�Χ��ͨ�����������������߼�Ȩƽ��ֵ
            {
              if( midline[i]!=-1 )
              {
                midline_sum=midline_sum+inv_weight[i]*midline[i];
                x1=x1+inv_weight[i];
                midline_use_cnt++;
              }
              
              
            }
          }
          
          else
          {
            if( L_barrier_flag==1 || R_barrier_flag==1 )   //��Ϊ�ϰ�ʱ
            { 
              for( i=JIZHUN_DOWN; i>=JIZHUN_UP; i-- )      //�����߷�Χȡ�ϰ��ﴦ���������߼�Ȩƽ��ֵ
              {
                if( midline[i]!=-1 )
                {
                  midline_sum=midline_sum+inv_weight[i]*midline[i];
                  x1=x1+inv_weight[i];
                  midline_use_cnt++;
                }
                else
                {
                  if( L_TURN )
                  {
                    midline_sum=midline_sum;
                    x1=x1+inv_weight[i];
                    midline_use_cnt++;
                  }
                  if( R_TURN )
                  {
                    midline_sum=midline_sum+inv_weight[i]*COL_END;
                    x1=x1+inv_weight[i];
                    midline_use_cnt++;
                  }
                }
                
              }
            }
            else
            {
              if( L_s_temp==1 || R_s_temp==1 )
              {
                JIZHUN_DOWN_TEMP=JIZHUN_DOWN+10;
                if(JIZHUN_DOWN_TEMP>=ROW_END)
                {
                  JIZHUN_DOWN_TEMP=ROW_END;
                }
                for( i=JIZHUN_DOWN_TEMP; i>=JIZHUN_UP; i-- )  
                {
                  if( midline[i]!=-1 )
                  {
                    midline_sum=midline_sum+inv_weight[i]*midline[i];
                    x1=x1+inv_weight[i];
                    midline_use_cnt++;
                  }
                  else
                  {
                    if( L_TURN )
                    {
                      midline_sum=midline_sum;
                      x1=x1+inv_weight[i];
                      midline_use_cnt++;
                    }
                    if( R_TURN )
                    {
                      midline_sum=midline_sum+inv_weight[i]*COL_END;
                      x1=x1+inv_weight[i];
                      midline_use_cnt++;
                    }
                  }
                }
              }
              else
              {    
                for( i=JIZHUN_DOWN ; i>=JIZHUN_UP ; i-- )   //ѡȡ���ʵ������߷�Χ���������߼�Ȩƽ��ֵ
                {
                  if( midline[i]!=-1 )
                  {
                    midline_sum=midline_sum+inv_weight[i]*midline[i];
                    x1=x1+inv_weight[i];
                    midline_use_cnt++;
                  }
                  else
                  {
                    if( L_TURN )
                    {
                      midline_sum=midline_sum;
                      x1=x1+inv_weight[i];
                      midline_use_cnt++;
                    }
                    if( R_TURN )
                    {
                      midline_sum=midline_sum+inv_weight[i]*COL_END;
                      x1=x1+inv_weight[i];
                      midline_use_cnt++;
                    }
                  }
                }
                
              }
            }
          }
        }
      }    
    }
    
  }
  
  midline_avg=midline_sum/x1;
}

/***********************************************************************************************************************************/

void  PID_control()
{
  /**��ȡ����ƫ��**/
  
  
      middle_Error[0]=79.5-midline_avg;
      if(keep_side)    //����ͣ��ƫ������
      {
            //Bee_flag=1;
            int16 pull_over_side;
            if(car_flag)
            {
                  pull_over_side=5;
            }
            else
            {
                  pull_over_side=10;
            }
            if(car_L_pull_over_flag && !car_R_pull_over_flag)
            {
                  if(middle_Error[0]<-pull_over_side)
                  {
                        keep_side=0;
                  }
                  else
                  {
                        middle_Error[0]=middle_Error[0]+pull_over_side;
                  }
            }
            if(car_R_pull_over_flag && !car_L_pull_over_flag)
            {
                  if(middle_Error[0]>pull_over_side)
                  {
                        keep_side=0;
                  }
                  else
                  {
                        middle_Error[0]=middle_Error[0]-pull_over_side;
                  }
            }
      }
  /**PIDϵ����ȡ**/
  if(dis_huaxing)
  {
    servo_Kp=servo_e;
    servo_Kd=servo_c;
  }
   else if(up_flag||down_flag||(qibu_flag && (motor_goal!=0)))
  {
    servo_Kp=servo_e;
    servo_Kd=0;
  }
  else if(LOOP_TEMP)
  {
       if((LOOP_IN==0) || ( out_row[0]!=-1 ))
      {
       servo_Kp=servo_e;
       servo_Kd=0;
      }
      else
      {
        servo_Kp=servo_e;
        servo_Kd=servo_c;
      }
  }
  else if( car_L_pull_over_flag||car_R_pull_over_flag)
  {
    if(keep_side)
    {
      servo_Kp=(servo_a*70*70/10000+servo_b);
      servo_Kd=0;
    }
    else if(po_pull_over)
    {
      servo_Kp=servo_e;
      servo_Kd=servo_f;
    }
    else
    {
//      servo_Kp=1.5*servo_e;
//      servo_Kd=0;
          if( car_L_pull_over_flag==1 && car_R_pull_over_flag==0 )
          {
                if( middle_Error[0]<0 )
                {
                      servo_Kp=2*servo_e;
                      servo_Kd=0;
                }
                else
                {
                      servo_Kp=servo_e;
                      servo_Kd=0;
                }
          }
          else if( car_L_pull_over_flag==0 && car_R_pull_over_flag==1 )
          {
                if( middle_Error[0]>0 )
                {
                      servo_Kp=2*servo_e;
                      servo_Kd=0;
                }
                else
                {
                      servo_Kp=servo_e;
                      servo_Kd=0;
                }
          }
   
    
    }
  }
  else if(L_barrier_flag|| R_barrier_flag)
  { 
    if((L_barrier_down_row!=-1)&&(inv_distance[L_barrier_down_row]>=0.15*400))
    {
      servo_Kp=servo_a*70*70/10000+servo_b;
      servo_Kd=servo_c;
      
    }
    else
    {
      servo_Kp=(servo_a*70*70/10000+servo_b)*1.5;
      servo_Kd=0; 
    }
  }
  else
  {
      servo_Kp=servo_a*middle_Error[0]*middle_Error[0]/10000+servo_b;
      servo_Kd=0;
    if( L_s_temp==1 || R_s_temp==1 )
    {
      servo_Kp=(servo_a*70*70/10000+servo_b)*servo_d;
      servo_Kd=servo_c;
      if( L_s_temp==1 )
      {
        if( middle_Error[0]>0 )
        {
          L_s_temp=0;
        }
      }
      else
      {
        if( R_s_temp==1 )
        {
          if( middle_Error[0]<0 )
          {
            R_s_temp=0;
          }
        }
      }
    }
  }
  
  /**PID��ö������ֵ**/
  
  double servo_add;
  servo_add=servo_Kp*middle_Error[0]+servo_Kd*(middle_Error[0]-middle_Error[1]);
  
  
  if( servo_add<0 )
  {
    servo_add=L_R_servo_K*servo_add;
  }
  
  servo_adj=round(servo_add+SERVO_MID);
  
  /**��¼ƫ��**/
  
  middle_Error[1]=middle_Error[0];
}

/***********************************************************************************************************************************/


 
