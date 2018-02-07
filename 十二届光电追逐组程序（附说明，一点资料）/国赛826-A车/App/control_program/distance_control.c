#include "include.h"
#include "common.h"

/************************************************************************************/

double distance_step=1;
double distance_a=16;  //��ֹ��������Ľ�������λ����
double distance_b=38;  //
double distance_c=5;  //��ֹ��������Ľ�������λ����(���ʱ)
double distance_d=8;  //
double distance_e=16;
double distance_f=15;
double distance2_step=1;
double distance2_a=5;
double distance2_b=17;
double distance2_c=3;
double distance2_d=8;
double distance2_e=7;
double distance2_f=10;

int16 motor_goal_temp2=0;           //�������м����
int32 distance_goal=800;    //Ŀ����룬��λ����

uint8 fangzhuang_flag=0,dis_huaxing=0;
int32 Q_distance=0,H_distance[2];
uint8 H_csb_get=0;
uint8 H_QC_get=0;
uint8 keep_stop=0;
uint8 stop_wait_able=0;

void distance_control()
{
      if(double_car_flag)//˫��ģʽ��ʵ�������ٶȵĴ���
      {
            dis_control();
      }
      else//����ģʽ��ʵ�������ٶȵĴ���
      {
            motor_goal_temp2=motor_goal_temp;
      }
      
      //----------������ͣ��----------//
      if(car_stop_ing_flag)
      {
            if(LOOP_TEMP)
            {
                  motor_goal_temp2=speed_hb;
            }
            else if(overtake_po_flag)
            {
                  if(!car_flag)
                  {
                        motor_goal_temp2=speed_poa;
                  }
                  else if(car_flag)
                  {
                        motor_goal_temp2=speed_pob;
                  }
            }
            else if(overtake_cross_flag)
            {
                  if(!car_flag)
                  {
                        motor_goal_temp2=speed_za;
                  }
                  else if(car_flag)
                  {
                        motor_goal_temp2=speed_zb;
                  }
            }
            else if(overtake_start_flag)
            {
                  if(!car_flag)
                  {
                        motor_goal_temp2=speed_za;
                  }
                  else if(car_flag)
                  {
                        motor_goal_temp2=speed_zb;
                  }
            }
      }
      
      if(car_stop_flag)
      {
            motor_goal_temp2=0;
            car_stop_ing_flag=0;
      }
      if(car_status == CAR_STOPP)
      {
            motor_goal_temp2=0;
            qibu_flag=0;
      }
      //-----Ŀ���ٶȸ�ֵ-----//
      motor_goal=motor_goal_temp2;
}

void dis_control()//˫�������ٶȵ��б����
{
      if( !LOOP_TEMP && !overtake_ring_flag && !overtake_po_flag && !overtake_cross_flag && !STOP_PATTERN)//�����������ģʽ��������ͨ�����ͷ���������˫���ٶȽ������¼���
      {
            if(!car_flag)//ǰ���ؾ� (��������٣�����Զ���٣������Լ�������ȷ���ٶ��޷�)
            {//Q_distance
                  if(!overtake_start_flag)
                  {
                        //                        Q_dis_control();//���������ݶ������ܻ���ִ������
                        motor_goal_temp2=motor_goal_temp;
                  }
                  else
                  {
                        Q_dis_fache();
                  }
            }
            else//����Ǻ�
            {//H_distance
                  //--------------��ȡ���벢�޷�------------//
                  if(car_distance>=100 && car_distance<=3000)
                  {
                        H_distance[0]=car_distance;
                  }
                  if(!END_LINE_TEMP && car_extract_row>0)
                  {
                        H_distance[0]=10*inv_distance[car_extract_row]/4;
                  }
                  else if(!chaoshengbo_flag)
                  {
                        H_distance[0]=1500;
                  }
                  
                  //---------------------------------------//
                  if(!overtake_start_flag)//��ͨ����ʱ
                  {
                        H_dis_control();
                  }
                  else//����ʱ
                  {
                        H_dis_fache();
                  }
            }
      }
      else if(STOP_PATTERN)
      {
            if(!car_flag)
            {
                  if(STOP_PATTERN_able==1)//ģʽ�����ߣ��еȴ�
                  {
                          if(speedout_val5_flag)
                          {
                                motor_goal_temp2=motor_goal_temp;
                                stop_wait=0;
                                qibu_flag=1;
                          }
                          else
                          {
                                motor_goal_temp2=1000*other5_e;
                                if(!stop_wait_able)
                                {
                                      stop_wait=1;
                                      stop_wait_able=1;
                                }
                          }
                          if(keep_stop || H_QC_get)
                          {
                                motor_goal_temp2=motor_goal_temp;
                                qibu_flag=1;
                                keep_stop=1;
                                stop_wait=0;
                          }
                  }
            }
            else
            {
                  if(STOP_PATTERN_able==1)
                  {
                        if(car_status == CAR_STOPP)
                        {
                              stop_wait=1;
                        }
                        else
                        {
                                //--------------��ȡ���벢�޷�------------//
                              if(!END_LINE_TEMP && car_extract_row>0)
                              {
                                    H_distance[0]=10*inv_distance[car_extract_row]/4;
                              }
                              else
                              {
                                    H_distance[0]=1500;
                              }
                              H_dis_control();
                              qibu_flag=1;
                        }
                  }
            }
      }
      else//����ģʽ������Ҫ���������Ŀǰ����
      {
            motor_goal_temp2=motor_goal_temp;
      }
}

//-------------------------------ǰ����ͨ�ٶȸ���------------------------------//
void Q_dis_control()
{//(����˼���ǣ�����̫��ʱ���٣�����̫Զʱ���٣�������벻��)
      if(Q_distance<=distance2_a*100)//����
      {
            if(STRAIGHT_FLAG)//ֱ���޷�50%
            {
                  motor_goal_temp2=limit_z_shang*motor_goal_temp;
            }
            else if(!in_d_curve_flag)//����������޷�10%
            {
                  motor_goal_temp2=limit_pu_shang*motor_goal_temp;
            }
            else//����޷�2%
            {
                  motor_goal_temp2=limit_w_shang*motor_goal_temp;
            }
      }
      else if(Q_distance>=distance2_b*100)//����
      {
            if(STRAIGHT_FLAG)//ֱ���޷�50%
            {
                  motor_goal_temp2=limit_z_xia*motor_goal_temp;
            }
            else if(!in_d_curve_flag)//����������޷�10%
            {
                  motor_goal_temp2=limit_pu_xia*motor_goal_temp;
            }
            else//����޷�2%
            {
                  motor_goal_temp2=limit_w_xia*motor_goal_temp;
            }
      }
      else
      {
            motor_goal_temp2=motor_goal_temp;
      }
}
//------------------------------ǰ�������ٶȸ���------------------------------//
void Q_dis_fache()
{
      if(overtake_start_sum==0)//������ʱ
      {
            motor_goal_temp2=motor_goal_temp;
            overtake_start_flag=0;//�˳�����ģʽ
      }
      else if(overtake_start_sum==1)
      {
            motor_goal_temp2=250;//��������Լ����˳�����ģʽ
      }
      else if(overtake_start_sum==2)
      {
            motor_goal_temp2=400;
      }
}
//-------------------------------����ͨ�ٶȸ���------------------------------//
void H_dis_control()
{
      dis_huaxing=0;
      if((STOP_PATTERN && END_LINE_TEMP) || STRAIGHT_FLAG)//ֱ�����޷�
      {
            if(STOP_PATTERN)
            {
                  distance_speed0(1,3,1);
            }
            else
            {
                  distance_speed(distance_a,distance_b,distance_c);
            }
            if(!fangzhuang_flag)//����ײ���޷�
            {
              if(STOP_PATTERN)
              {
                  if(motor_goal_temp2>other5_d*1000)
                        motor_goal_temp2=other5_d*1000;
              }
              else
              {
                  if(motor_goal_temp2>limit_z_shang*motor_goal_temp)
                        motor_goal_temp2=limit_z_shang*motor_goal_temp;
                  if(motor_goal_temp2<limit_z_xia*motor_goal_temp)
                        motor_goal_temp2=limit_z_xia*motor_goal_temp;
              }
            }
      }
      else if(!in_d_curve_flag)//�������(���������״�����޷�̫С׷���ϣ��޷�̫���ȶ�������Ҫʵ�ʵ��ԣ�)
      {
            if(STOP_PATTERN)
            {
                  distance_speed0(1,3,1);
            }
            else
            {
                  distance_speed(distance_a,distance_b,distance_c);
            }
            if(!fangzhuang_flag)//����ײ���޷�
            {
              if(motor_goal_temp2>limit_pu_shang*motor_goal_temp)
                   motor_goal_temp2=limit_pu_shang*motor_goal_temp;
              if(motor_goal_temp2<limit_pu_xia*motor_goal_temp)
                   motor_goal_temp2=limit_pu_xia*motor_goal_temp;
            }
      }
      else//����޷�2%
      {
            if(STOP_PATTERN)
            {
                  distance_speed0(1,3,1);
            }
            else
            {
                  distance_speed(distance_d,distance_e,distance_f);
            }
            if(motor_goal_temp2>limit_w_shang*motor_goal_temp)
                  motor_goal_temp2=limit_w_shang*motor_goal_temp;
            if(motor_goal_temp2<limit_w_xia*motor_goal_temp)
                  motor_goal_temp2=limit_w_xia*motor_goal_temp;
      }
      //---------------------------------------------------------------------//
      //���������⴦���������̫�����ͻ���뻬��
      if((car_extract_row>0) && (H_distance[0]<1000) && !fangzhuang_flag && !STOP_PATTERN)
      {
            motor_goal_temp2=400;
            dis_huaxing=1;
      }
}
//------------------------------�󳵷����ٶȸ���------------------------------//
uint8 H_overtake_start_flag=0;
void H_dis_fache()
{
      if(overtake_start_sum==0)//���ܲ�����ʱ
      {
            if(H_distance[0]<distance2_c*100)
            {
                  motor_goal_temp2=0;//�����ʱ�ٶ�Ϊ0����ֹ����ʱ���ȶ��������ٶȿ�Ӷ�ײ��ǰ��
            }
            else
            {
                  overtake_start_flag=0;//������ʱ������ﵽҪ��ͻ��˳�����ģʽ���Ӷ�������
                  //����ʱ��������ɻ��Լ��˳�����ģʽ
            }
      }
      else if(overtake_start_sum==1)
      {//���ڳ���ʱ�ؾ࣬�Ժ���Ҫʱ��д
            if(H_distance[0]<2*100 && (!H_overtake_start_flag))
            {
                  motor_goal_temp2=0;//�����ʱ�ٶ�Ϊ0����ֹ����ʱ���ȶ��������ٶȿ�Ӷ�ײ��ǰ��
            }
            else
            {
                  if(houche_speed_flag)//������ɣ��ٶȱ�����
                  {
                        motor_goal_temp2=motor_goal_temp;
                  }
                  else
                  {
                        motor_goal_temp2=350;//���ܳ����Ļ����ٶ�
                  }
                  H_overtake_start_flag=1;
            }
      }
      else if(overtake_start_sum==2)
      {
            if(H_distance[0]<2*100 && (!barrier_over_start))
            {
                  motor_goal_temp2=0;//�����ʱ�ٶ�Ϊ0����ֹ����ʱ���ȶ��������ٶȿ�Ӷ�ײ��ǰ��
            }
            else
            {
                  if(houche_speed_flag)//������ɣ��ٶȱ�����
                  {
                        motor_goal_temp2=motor_goal_temp;
                  }
                  else
                  {
                        motor_goal_temp2=400;//���ܳ����Ļ����ٶ�
                  }
            }
      }
}

//----------����������ٶ��������㺯��----------//
void distance_speed(double a,double b,double c)
{
      fangzhuang_flag=0;
      distance_goal=100*c;
      if(H_distance[0]<1000)//��ֹ�������
      {
            if(car_extract_row>0)//�����ϰ������Ϊ������Ľ�
            {
                  if(H_distance[0]<=DIS_DANGEROUS)//�޷��������
                  {
                        motor_goal_temp2=MIN_SPEED;
                        fangzhuang_flag=1;
                  }
                  else if(H_distance[0]<=DIS_SHACHE && H_distance[0]>DIS_DANGEROUS)//̫������ɲ��
                  {
                        motor_goal_temp2=1.0*MIN_SPEED*(H_distance[0]-DIS_SHACHE)/(DIS_DANGEROUS-DIS_SHACHE);
                        fangzhuang_flag=1;
                  }
                  else if(H_distance[0]>DIS_SHACHE && H_distance[0]<=a*100)//�Ͻ�������
                  {
                        motor_goal_temp2=1.0*motor_goal_temp*(H_distance[0]-DIS_SHACHE)/(a*100-DIS_SHACHE);
                  }
            }
            else
            {
                  motor_goal_temp2=motor_goal_temp;
            }
      }
      else
      {
            if(H_distance[0]>DIS_SHACHE && H_distance[0]<=a*100)//�Ͻ�������
            {
                  if(car_extract_row>0)//�����ϰ������Ϊ������Ľ�
                  {
                        motor_goal_temp2=1.0*motor_goal_temp*(H_distance[0]-DIS_SHACHE)/(a*100-DIS_SHACHE);
                  }
                  else
                  {
                        motor_goal_temp2=motor_goal_temp;
                  }
            }
            else if(H_distance[0]>a*100 && H_distance[0]<=distance_goal)//�����������
            {
                  motor_goal_temp2=motor_goal_temp;
            }
            else if((H_distance[0]>distance_goal && H_distance[0]<=b*100) && !barrier_able_flag)//Զ�ˣ�����
            {
                  motor_goal_temp2=1.0*(MAX_SPEED-motor_goal_temp)*(H_distance[0]-b*100)/(b*100-distance_goal)+MAX_SPEED;
            }
            else if(!barrier_able_flag)//�޷��������
            {
                  motor_goal_temp2=MAX_SPEED;
            }
      }
}
void distance_speed0(double a,double b,double c)
{
      fangzhuang_flag=0;
      distance_goal=100*c;
      if(H_distance[0]<200)//��ֹ�������
      {
            if(H_distance[0]<=0)//�޷��������
            {
                  motor_goal_temp2=MIN_SPEED;
                  fangzhuang_flag=1;
            }
            else if(H_distance[0]<=10 && H_distance[0]>0)//̫������ɲ��
            {
                  motor_goal_temp2=1.0*MIN_SPEED*(H_distance[0]-10)/(0-10);
                  fangzhuang_flag=1;
            }
            else if(H_distance[0]>10 && H_distance[0]<=a*100)//�Ͻ�������
            {
                  motor_goal_temp2=1.0*motor_goal_temp*(H_distance[0]-10)/(a*100-10);
            }
      }
      else
      {
            if(H_distance[0]>10 && H_distance[0]<=a*100)//�Ͻ�������
            {
                  if(car_extract_row>0)//�����ϰ������Ϊ������Ľ�
                  {
                        motor_goal_temp2=1.0*motor_goal_temp*(H_distance[0]-10)/(a*100-10);
                  }
                  else
                  {
                        motor_goal_temp2=motor_goal_temp;
                  }
            }
            else if(H_distance[0]>a*100 && H_distance[0]<=distance_goal)//�����������
            {
                  motor_goal_temp2=motor_goal_temp;
            }
            else if(H_distance[0]>distance_goal && H_distance[0]<=b*100)//Զ�ˣ�����
            {
                  motor_goal_temp2=1.0*(MAX_SPEED-motor_goal_temp)*(H_distance[0]-b*100)/(b*100-distance_goal)+MAX_SPEED;
            }
            else//�޷��������
            {
                  motor_goal_temp2=MAX_SPEED;
            }
      }
}