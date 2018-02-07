#include "include.h"
#include "common.h"

/***********************************************************************************************************************************/


        /*���±�������Ҫ�����ⲿ����*/

double cross_wide;                //���ڲ�ʮ�ֱ��ص��м����
double cross_high;                //���ڲ�ʮ�ֱ��ص��м����
double cross_edge;                //���ڲ�ʮ�ֱ��ص��м����

int16 cross_row;                  //���ڼ��ʮ��ֱ�ǹյ���м����
int16 cross_col;                  //���ڼ��ʮ��ֱ�ǹյ���м����

int16 EXTRACT_ROW;                //��ǰ�������ص�����
int16 EXTRACT_COL;                //��ǰ�������ص�����

int16 W_num_row;                  //���ڰ׿�����������꣨Ҳ���������ж�ʱ���м������
int16 W_num_col;                  //���ڰ׿�����������꣨Ҳ���������ж�ʱ���м������
int16 W_num;                      //�׿����ֵ��Ҳ���������ж�ʱ���м������

uint8 L_edge_nearest;             //��һ�������������
uint8 R_edge_nearest;             //��һ���ұ���������

uint8 L_get_flag;                 //����������õ���־
uint8 L_lost_num;                 //�����������ʧ����

uint8 R_get_flag;                 //�ұ��������õ���־
uint8 R_lost_num;                 //�ұ���������ʧ����

uint8 L_trend_in;                 //��������������жϱ�־������ 1 ʱΪ����,���� 0 ʱΪ���㣩
uint8 R_trend_in;                 //�ұ������������жϱ�־������ 1 ʱΪ����,���� 0 ʱΪ���㣩

uint8 l_cross_able;               //���������ʮ��ʹ�ܱ�־
uint8 r_cross_able;               //�����ұ���ʮ��ʹ�ܱ�־
uint8 end_bar_able;               //�յ����ϰ���ʹ�ܱ�־
uint8 car_extract_able;           //ǰ�����ʹ�ܱ�־


        /*���±���������Ҫ�����ⲿ����*/

double angle_aaa[4];

uint8 cross_num=0;                //ʮ�ּ���
uint8 cross_temp=0;               //ʮ��״̬��־
uint8 cross_temp_1;               //ʮ���ݴ��־_1
int16 cross_down[2];              //ʮ�����ݴ�

uint8 L_bar_num=0;                //����ϰ������
uint8 R_bar_num=0;                //�ұ��ϰ������
uint8 bar_temp=0;                 //�ϰ���״̬��־
uint8 bar_temp_1;                 //�ϰ����ݴ��־_1
uint8 bar_temp_2;                 //�ϰ����ݴ��־_2
int16 bar_row[2];                 //�ϰ������ݴ�

uint8 loop_num=0;                 //��������
uint8 end_line_num=0;             //�����߼���

uint8 car_over_able=0;            //����ʶ��ʹ�ܱ�־λ
uint8 car_over_ok=0;              //�����ɹ���־λ
int32 bar_car_val=-1;             //��������
uint8 bar_car_temp_1=0;

uint8 L_EDGE_NUM;                 //����ظ���
uint8 R_EDGE_NUM;                 //�ұ��ظ���

uint8 L_LINK_NUM;                 //��������ظ������������������Ϊ�����������ظ�����
uint8 R_LINK_NUM;                 //�����ұ��ظ������������������Ϊ�����������ظ�����

uint8 L_cross_flag;               //������жϽ���ʮ�ֱ�־
double L_cross_k;                //�����ʮ��б��
uint8 R_cross_flag;               //�ұ����жϽ���ʮ�ֱ�־
double R_cross_k;                //�ұ���ʮ��б��
uint8 cross_flag;                 //�жϽ���ʮ�ֱ�־

uint8 L_search_end;               //���������������־
int16 L_end_row;                  //�������������ʱ����������
int16 L_down_end_row;             //�����������������ʱ����������

uint8 R_search_end;               //�ұ�������������־
int16 R_end_row;                  //�ұ�����������ʱ����������
int16 R_down_end_row;             //�ұ���������������ʱ����������

uint8 loop_able=1;                //��������ʹ�ܱ�־
uint8 LOOP_FLAG;                  //����������־
uint8 LOOP_TEMP=0;                //���������ݴ��־
uint32 LOOP_TEMP_1=0;             //���������ݴ��־_1
uint8 LOOP_IN=0;                  //�������������־
int16 LOOP_IN_1=0;                //�������������־_1
uint8 LOOP_OUT_1=0;               //���������뿪��־_1
uint8 LOOP_OUT=0;                 //����������Ҫ�뿪��־
uint8 loop_l_r_flag;              //��������ת���жϱ�־��Ϊ1ʱ��ת��Ϊ0ʱ��ת��
int16 LOOP_IN_ROW;                //�������������
int16 in_row[2]={-1,-1};          //������������д洢����
int16 LOOP_OUT_ROW;               //��������������
int16 out_row[2]={-1,-1};         //�������������д洢����
int32 loop_val=0;                 //��������

uint8 barrier_able=1;             //ʹ�ܼ���ϰ���־
uint8 L_barrier_flag;             //������ϰ���־
uint8 R_barrier_flag;             //�ұ����ϰ���־
int16 L_barrier_down_row;         //������ϰ����±�����
int16 L_barrier_up_row;           //������ϰ����ϱ�����
int16 R_barrier_down_row;         //�ұ����ϰ����±�����
int16 R_barrier_up_row;           //�ұ����ϰ����ϱ�����
int16 car_extract_row;            //���ǰ��������

uint8 end_line_able=1;            //�յ���ʹ�ܼ���־
uint8 END_LINE_FLAG;              //�յ��߱�־
uint8 END_LINE_TEMP=0;            //�յ����ݴ��־
uint8 END_LINE_TEMP_1;            //�յ����ݴ��־_1
uint8 END_LINE_TEMP_2;            //�յ����ݴ��־_2
int16 end_line_row=-1;            //�յ���������
int32 end_line_val=0;             //�յ������ھ���
int16 end_line_2[2]={-1,-1};      //�յ�������������

uint8 L_TURN;                     //�����������ж�Ϊ��ת���־
uint8 R_TURN;                     //�����������ж�Ϊ��ת���־
int16 curve_in_row;               //��������
int16 curve_car_row;              //���ǰ������

uint8 S_FLAG;                     //S�� ������־
int16 L_s_temp=0;                 //������ж�S�� ������־
int16 R_s_temp=0;                 //�ұ����ж�S�� ������־
int16 L_s_row;                    //������ж�S�� ������
int16 R_s_row;                    //�ұ����ж�S�� ������
int16 s_curve_row;                //S�� ��������
double s_down_dis;               //S�� ������ǰհ����

uint8 ramp_able=1;                //�µ�ʹ�ܼ���־
uint8 RAMP_FLAG;                  //�µ���־
uint8 RAMP_TEMP;                  //�µ��ݴ��־
int32 ramp_val=0;                 //�µ�����

uint8 STRAIGHT_FLAG;              //ֱ����־
uint8 little_s_flag;              //СS�������־

double tan_table[30];
int16 inv_cross[3];               //���ѱ����ж�ʮ��

double inv_distance[CAMERA_H];    //��͸�ӻ�ȡÿ��ʵ�ʾ�������
double bar_range_col[CAMERA_H];   //�ϰ���������Χ����
double car_col[CAMERA_H];         //��ģ·��ʶ������

/*ʮ��ֱ�ǹյ�����*/
int16 L_down_cross[2];            //�����ʮ���·�ֱ�ǹյ����飨[0]Ϊʮ�ֹյ�������ֵ��[1]Ϊʮ�ֹյ�������ֵ��
int16 L_up_cross[2];              //�����ʮ���Ϸ�ֱ�ǹյ����飨[0]Ϊʮ�ֹյ�������ֵ��[1]Ϊʮ�ֹյ�������ֵ��

/*ʮ��ֱ�ǹյ�����*/
int16 R_down_cross[2];            //�ұ���ʮ���·�ֱ�ǹյ����飨[0]Ϊʮ�ֹյ�������ֵ��[1]Ϊʮ�ֹյ�������ֵ��
int16 R_up_cross[2];              //�ұ���ʮ���Ϸ�ֱ�ǹյ����飨[0]Ϊʮ�ֹյ�������ֵ��[1]Ϊʮ�ֹյ�������ֵ��

int16 left_edge[CAMERA_H];              //����ش������
int16 right_edge[CAMERA_H];             //�ұ��ش������

int16 left_down_edge[10];         //�½�����ش������
int16 right_down_edge[10];        //�½��ұ��ش������


uint8 chao_direction[5]={1,1,1,1,1};

/***********************************************************************************************************************************/

void edge_extract();             //�˺���Ϊ������ȡ������

void L_down_cross_judge();       //�˺���Ϊ������·�ֱ�ǹյ��жϺ���������ת��ʱʹ�ã�
void L_up_cross_judge();         //�˺���Ϊ������Ϸ�ֱ�ǹյ��жϺ�������������ͻ��ʱʹ�ã�
void L_up_cross_extract();       //�˺���Ϊ������Ϸ�ֱ�ǹյ��жϺ������ҵ���ʮ�ֺ�����������ʮ�֣�
void L_up_cross_error();         //�˺���Ϊ������Ϸ�ֱ�ǹյ�����������

void R_down_cross_judge();       //�˺���Ϊ�ұ����·�ֱ�ǹյ��жϺ���������ת��ʱʹ�ã�
void R_up_cross_judge();         //�˺���Ϊ�ұ����Ϸ�ֱ�ǹյ��жϺ�������������ͻ��ʱʹ�ã�
void R_up_cross_extract();       //�˺���Ϊ�ұ����Ϸ�ֱ�ǹյ��жϺ������ҵ���ʮ�ֺ�����������ʮ�֣�
void R_up_cross_error();         //�˺���Ϊ�ұ����Ϸ�ֱ�ǹյ�����������

void barrier_down_extract();     //�˺���Ϊ�ϰ����±����м�⺯��
void barrier_up_extract();       //�˺���Ϊ�ϰ����ϱ����м�⺯��

void end_line_extract();         //�˺���Ϊ�յ����м�⺯��

void cross_edge_add();           //�˺���Ϊʮ�ֱ��ز��亯��

void edge_error_process();       //�˺���Ϊ���ش�������

void road_judge();               //�˺���Ϊ���������жϺ���

void bar_process();              //�˺���Ϊ�ϰ�����ز��亯��

void road_num();                 //�˺���Ϊ�������ͼ���������ʮ�֣��ϰ��������

void loop_judge();               //�˺���Ϊ���������жϺ���

void down_extract();             //�˺���Ϊ�½�������������

void bar_car();                  //�˺���Ϊ�����жϺ���

void tan_angle();                //�˺���Ϊб�ʽǶ��Ʊ���

void bar_range();                //�˺���Ϊÿ���ϰ���������Χ��ȡ����


/***********************************************************************************************************************************/

void edge_extract()       //�˺���Ϊ������ȡ������
{
      edge_clean();        //��յ�ǰ������ȡ��������
      
      
      /*���±���������Ҫ�����ⲿ����*/
      
      L_EDGE_NUM=0;                //������ظ�������ֵ  0
      R_EDGE_NUM=0;                //���ұ��ظ�������ֵ  0
      
      L_cross_flag=0;              //������жϽ���ʮ�ֱ�־��  0
      R_cross_flag=0;              //�ұ����жϽ���ʮ�ֱ�־��  0
      cross_flag=0;                //�жϽ���ʮ�ֱ�־��  0
      L_cross_k=10;                //�����ʮ��б����  10
      R_cross_k=10;                //�ұ���ʮ��б����  10
      
      L_search_end=0;              //���������������־��  0
      R_search_end=0;              //�ұ�������������־��  0
      L_end_row=-1;                //�������������������  -1
      R_end_row=-1;                //�ұ�����������������  -1
      
      L_down_end_row=-1;           //�����������������������  -1
      R_down_end_row=-1;           //�ұ���������������������  -1
      
      L_barrier_flag=0;            //������ϰ���־��  0
      R_barrier_flag=0;            //�ұ����ϰ���־��  0
      L_barrier_down_row=-1;       //������ϰ����±�������  -1
      L_barrier_up_row=-1;         //������ϰ����ϱ�������  -1
      R_barrier_down_row=-1;       //�ұ����ϰ����±�������  -1
      R_barrier_up_row=-1;         //�ұ����ϰ����ϱ�������  -1
      car_extract_row=-1;          //���ǰ����������  -1
      
      LOOP_FLAG=0;                 //����������־��  0
      
      END_LINE_FLAG=0;             //�յ��߱�־��  0
      
      L_TURN=0;                    //�����־��  0
      R_TURN=0;                    //�����־��  0
      curve_in_row=-1;             //����������  -1
      curve_car_row=-1;            //���ǰ������  -1
      
      S_FLAG=0;                    //S�� ������־��  0
      s_curve_row=-1;              //S�� ����������  0
      
      STRAIGHT_FLAG=0;             //ֱ����־��  0
      little_s_flag=0;             //СS�������־��  0
      RAMP_FLAG=0;                 //�µ���־��  0
      
      
      /*���±�������Ҫ�����ⲿ����*/
      
      L_LINK_NUM=0;        //����������ظ�������ֵ  0
      R_LINK_NUM=0;        //�������ұ��ظ�������ֵ  0
      
      L_get_flag=0;        //����������õ���־��  0
      L_lost_num=1;        //�����������ʧ������  1���ȶ���Ϊ��ʧ���أ�
      
      R_get_flag=0;        //�ұ��������õ���־��  0
      R_lost_num=1;        //�����������ʧ������  1���ȶ���Ϊ��ʧ���أ�
      
      L_trend_in=0;        //��������������жϱ�־��  0
      R_trend_in=0;        //�ұ������������жϱ�־��  0
      
      if( LOOP_TEMP )
      {
            if( out_row[0]!=-1 )
            {
                  double l_out;
                  Site_xy1 xy1;
                  l_out=1.0*(loop_val-abs(speedout_val))/25;
                  xy1=get_invinv_img(l_out,0);
                  LOOP_OUT_ROW=xy1.x;
            }
      }
      
      end_bar_able=1;
      
      if( overtake_cross_flag )
      {
            if(car_L_pull_over_flag && !car_R_pull_over_flag)   //�ж�Ϊ��࿿��
            {
                  l_cross_able=1;
                  r_cross_able=0;
            }
            else
            {
                  if(car_R_pull_over_flag && !car_L_pull_over_flag)   //�ж�Ϊ�Ҳ࿿��
                  {
                        l_cross_able=0;
                        r_cross_able=1;
                  }
                  else
                  {
                        l_cross_able=1;
                        r_cross_able=1;
                  }
            }
      }
      else
      {
            l_cross_able=1;
            r_cross_able=1;
      }
      int16 l_cross_edge=0,r_cross_edge=0,l_cross_1=0,r_cross_1=0;
      
      for( EXTRACT_ROW=ROW_END ; EXTRACT_ROW>=ROW_START ; EXTRACT_ROW-- )       //�������ͼ��ı���
      {
            L_get_flag=0;               //������������õ���־��0
            R_get_flag=0;               //���ұ��������õ���־��0
            
            if( LOOP_TEMP )  //����ʮ��ʹ��
            {
                  if( LOOP_IN )
                  {
                        if( out_row[0]!=-1 )
                        {
                              if( inv_distance[EXTRACT_ROW]<inv_distance[LOOP_IN_ROW]+60 )
                              {
                                    l_cross_able=0;
                                    r_cross_able=0;
                              }
                              else
                              {
                                    if( loop_l_r_flag==1 )
                                    {
                                          l_cross_able=0;
                                          r_cross_able=1;
                                    }
                                    else
                                    {
                                          if( loop_l_r_flag==0 )
                                          {
                                                l_cross_able=1;
                                                r_cross_able=0;
                                          }
                                    }
                              }
                        }
                        else
                        {
                              l_cross_able=0;
                              r_cross_able=0;
                        }
                  }
                  else
                  {
                        if( inv_distance[EXTRACT_ROW]>inv_distance[LOOP_IN_ROW]-60 )
                        {
                              l_cross_able=0;
                              r_cross_able=0;
                        }
                  }
            }
            
            if( END_LINE_TEMP==1 )  //�յ����ϰ�ʹ��
            {
                  if( end_line_row!=-1 )
                  {
                        if( inv_distance[EXTRACT_ROW]>inv_distance[end_line_row]+60 )
                        {
                              end_bar_able=1;
                              l_cross_able=1;
                              r_cross_able=1;
                        }
                        else
                        {
                              end_bar_able=0;
                              l_cross_able=0;
                              r_cross_able=0;
                        }
                  }
                  else
                  {
                        if( inv_distance[EXTRACT_ROW]>100 )
                        {
                              end_bar_able=1;
                              l_cross_able=1;
                              r_cross_able=1;
                        }
                        else
                        {
                              end_bar_able=0;
                              l_cross_able=0;
                              r_cross_able=0;
                        }
                  }
            }
            
            /*���³����Ϊ����ؼ�����*/
            
            if( L_search_end==0 )       //�����������δ����ʱ����
            {
                  if( L_lost_num==0 )         //�������û�ж�ʧʱ���봦��
                  {
                        if( L_LINK_NUM>=3 )   //����������������ڵ���3���жϳ���������ʱ���봦��
                        {
                              if( L_trend_in==1 )    //�����������ʱ���봦��
                              {
                                    if( img_data[EXTRACT_ROW][L_edge_nearest]==DOT_B )     //����һ������ص���Ϸ�һ��Ϊ��
                                    {
                                          for( EXTRACT_COL=L_edge_nearest+1 ; EXTRACT_COL<=L_edge_nearest+L_IN_2_IN ; EXTRACT_COL++ )      //�����������������
                                          {
                                                if( EXTRACT_COL>COL_END )    //����������ͼ��Χʱ����������
                                                {
                                                      break;
                                                }
                                                if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_W )  //�ҵ��ڰ������
                                                {
                                                      left_edge[EXTRACT_ROW]=EXTRACT_COL-1;        //���汾�������������
                                                      
                                                      L_EDGE_NUM++;                                //����ظ�����һ
                                                      
                                                      L_LINK_NUM++;                                //��������ظ�����һ
                                                      
                                                      L_get_flag=1;                                //����������õ���־��  1
                                                      
                                                      L_edge_nearest=EXTRACT_COL-1;                //�洢���һ������ص�������
                                                      
                                                      L_up_cross_judge();                          //�ж��Ƿ�Ϊ��ʮ��ֱ�ǹյ�
                                                      
                                                      break;                                      //�����������������
                                                }
                                          }
                                          
                                          if( inv_distance[EXTRACT_ROW]>120 && left_edge[EXTRACT_ROW]!=-1 && left_edge[EXTRACT_ROW+1]!=-1 )
                                          {
                                                if( left_edge[EXTRACT_ROW]-left_edge[EXTRACT_ROW+1]>=40 )
                                                {
                                                      W_num=0;
                                                      for( EXTRACT_COL=left_edge[EXTRACT_ROW+1]+1 ; EXTRACT_COL<=left_edge[EXTRACT_ROW] ; EXTRACT_COL++ )      //�����������������
                                                      {
                                                            if( img_data[EXTRACT_ROW+1][EXTRACT_COL] == DOT_B )
                                                            {
                                                                  W_num++;
                                                            }
                                                      }
                                                      if( W_num>=0.5*abs(left_edge[EXTRACT_ROW]-left_edge[EXTRACT_ROW+1]) )
                                                      {
                                                            left_edge[EXTRACT_ROW]=-1;
                                                            L_EDGE_NUM--;
                                                            L_LINK_NUM--;
                                                            L_get_flag=0;
                                                      }
                                                      
                                                }
                                          }
                                          
                                          if( L_get_flag==0 )      //���������������δ�ѵ�����
                                          {
                                                if( L_down_cross[0]!=-1 && L_up_cross[0]!=-1 )
                                                {
                                                      W_num=0;
                                                      for( W_num_row=EXTRACT_ROW+1 ; W_num_row<=EXTRACT_ROW+15 ; W_num_row++ )      //�ұ���������������
                                                      {
                                                            if( W_num_row>=ROW_END )
                                                            {
                                                                  break;
                                                            }
                                                            if( left_edge[W_num_row]<left_edge[W_num_row+1] )
                                                            {
                                                                  W_num++;
                                                            }
                                                      }
                                                      if( W_num<=1 )
                                                      {
                                                            W_num=0;
                                                            for( W_num_row=EXTRACT_ROW+1 ; W_num_row<=EXTRACT_ROW+15 ; W_num_row++ )      //�ұ���������������
                                                            {
                                                                  if( W_num_row>=ROW_END )
                                                                  {
                                                                        break;
                                                                  }
                                                                  if( left_edge[W_num_row]<left_edge[W_num_row+1] )
                                                                  {
                                                                        W_num++;
                                                                  }
                                                            }
                                                            if( W_num<=1 )
                                                            {
                                                                  R_TURN=1;                   //�����־��  1
                                                                  
                                                                  L_end_row=EXTRACT_ROW+1;    //����һ�е�����ֵ��������ؽ�������ֵ
                                                                  
                                                                  L_search_end=1;             //�����������ʱ���������������׵㣬�ж�Ϊ�������������
                                                                  R_search_end=1;             //�����������ʱ���������������׵㣬�ж�Ϊ�ұ�����������
                                                            }
                                                      }
                                                }
                                                else
                                                {
                                                      if( L_LINK_NUM>=10 )
                                                      {
                                                            W_num=0;
                                                            for( W_num_row=EXTRACT_ROW+1 ; W_num_row<=EXTRACT_ROW+10 ; W_num_row++ )      //�ұ���������������
                                                            {
                                                                  if( W_num_row>=ROW_END )
                                                                  {
                                                                        break;
                                                                  }
                                                                  if( left_edge[W_num_row]<left_edge[W_num_row+1] )
                                                                  {
                                                                        W_num++;
                                                                  }
                                                            }
                                                            if( W_num<=1 )
                                                            {
                                                                  R_TURN=1;                   //�����־��  1
                                                                  
                                                                  L_end_row=EXTRACT_ROW+1;    //����һ�е�����ֵ��������ؽ�������ֵ
                                                                  
                                                                  L_search_end=1;             //�����������ʱ���������������׵㣬�ж�Ϊ�������������
                                                                  R_search_end=1;             //�����������ʱ���������������׵㣬�ж�Ϊ�ұ�����������
                                                            }
                                                      }
                                                }
                                                
                                                L_LINK_NUM=0;               //��������ظ�����  0
                                                
                                                L_lost_num++;               //��û������������ص�ʱ������ض�ʧ����һ
                                          }
                                    }
                                    else                                                   //����һ������ص���Ϸ�һ��Ϊ��
                                    {
                                          for( EXTRACT_COL=L_edge_nearest-1 ; EXTRACT_COL>=L_edge_nearest-L_IN_2_OUT ; EXTRACT_COL-- )      //�����������������
                                          {
                                                if( EXTRACT_COL<COL_START )    //����������ͼ��Χʱ����������
                                                {
                                                      break;
                                                }
                                                if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_B )
                                                {
                                                      left_edge[EXTRACT_ROW]=EXTRACT_COL;          //���汾�������������
                                                      
                                                      L_EDGE_NUM++;                                //����ظ�����һ
                                                      
                                                      L_LINK_NUM++;                                //��������ظ�����һ
                                                      
                                                      L_get_flag=1;                                //����������õ���־��  1
                                                      
                                                      L_edge_nearest=EXTRACT_COL;                  //�洢���һ������ص�������
                                                      
                                                      L_trend_in=0;                                //������������־��  0
                                                      
                                                      L_down_cross_judge();                        //�ж��Ƿ�Ϊ��ʮ��ֱ�ǹյ�
                                                      
                                                      break;                                      //�����������������
                                                }
                                          }
                                          if( L_get_flag==0 )      //���������������δ�ѵ�����
                                          {
                                                L_LINK_NUM=0;           //��������ظ�����  0
                                                
                                                L_lost_num++;           //��û������������ص�ʱ������ض�ʧ����һ
                                                
                                                L_down_cross_judge();   //�ж��Ƿ�Ϊ��ʮ��ֱ�ǹյ�
                                          }
                                    }
                              }
                              else                   //�����������ʱ���봦��
                              {
                                    if( img_data[EXTRACT_ROW][L_edge_nearest+1]==DOT_B )     //����һ������ص���Ϸ�һ��Ϊ��
                                    {
                                          for( EXTRACT_COL=L_edge_nearest+1 ; EXTRACT_COL<=L_edge_nearest+L_OUT_2_IN ; EXTRACT_COL++ )      //�����������������
                                          {
                                                if( EXTRACT_COL>COL_END )    //����������ͼ��Χʱ����������
                                                {
                                                      break;
                                                }
                                                if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_W )  //�ҵ��ڰ������
                                                {
                                                      left_edge[EXTRACT_ROW]=EXTRACT_COL-1;        //���汾�������������
                                                      
                                                      L_EDGE_NUM++;                                //����ظ�����һ
                                                      
                                                      L_LINK_NUM++;                                //��������ظ�����һ
                                                      
                                                      L_get_flag=1;                                //����������õ���־��  1
                                                      
                                                      L_edge_nearest=EXTRACT_COL-1;                //�洢���һ������ص�������
                                                      
                                                      L_trend_in=1;                                //������������Ʊ�־��  1
                                                      
                                                      break;                                      //�����������������
                                                }
                                          }
                                          if( L_get_flag==0 )      //���������������δ�ѵ�����
                                          {
                                                if( L_LINK_NUM>=10 && L_LINK_NUM>R_LINK_NUM )
                                                {
                                                      L_end_row=EXTRACT_ROW+1;    //����һ�е�����ֵ��������ؽ�������ֵ
                                                      
                                                      L_search_end=1;             //�����������ʱ���������������׵㣬�ж�Ϊ�������������
                                                      R_search_end=1;             //�����������ʱ���������������׵㣬�ж�Ϊ�ұ�����������
                                                }
                                                
                                                L_LINK_NUM=0;               //��������ظ�����  0
                                                
                                                L_lost_num++;               //��û������������ص�ʱ������ض�ʧ����һ
                                          }
                                    }
                                    else          //����һ������ص���Ϸ�һ��Ϊ��
                                    {
                                          if( L_cross_flag==1 )    //�������õ��������ʮ��
                                          {
                                                for( EXTRACT_COL=L_edge_nearest ; EXTRACT_COL>=L_edge_nearest-L_OUT_2_OUT ; EXTRACT_COL-- )     //��ʼ��������
                                                {
                                                      if( EXTRACT_COL<COL_START )    //����������ͼ��Χʱ����������
                                                      {
                                                            break;
                                                      }
                                                      if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_B )
                                                      {
                                                            left_edge[EXTRACT_ROW]=EXTRACT_COL;          //���汾�������������
                                                            
                                                            L_EDGE_NUM++;                                //����ظ�����һ
                                                            
                                                            L_LINK_NUM++;                                //��������ظ�����һ
                                                            
                                                            L_get_flag=1;                                //����������õ���־��  1
                                                            
                                                            L_edge_nearest=EXTRACT_COL;                  //�洢���һ������ص�������
                                                            
                                                            break;                                      //�����������������
                                                      }
                                                }
                                                if( L_get_flag==0 )
                                                {
                                                      L_LINK_NUM=0;                                //��������ظ�����  0
                                                      
                                                      L_lost_num++;                                //�����������ʱ���������������׵㣬����ض�ʧ����һ
                                                }
                                          }
                                          else                     //��δ�����õ��������ʮ��
                                          {
                                                for( EXTRACT_COL=L_edge_nearest-1 ; EXTRACT_COL>=L_edge_nearest-L_OUT_2_OUT ; EXTRACT_COL-- )     //��ʼ��������
                                                {
                                                      if( EXTRACT_COL<COL_START )  //����ֹͣ
                                                      {
                                                            break;
                                                      }
                                                      if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_B )
                                                      {
                                                            W_num=0;            //����׿����ֵ
                                                            for( W_num_col=L_edge_nearest ; W_num_col>=EXTRACT_COL ; W_num_col-- )     //���������ĺڰ�����������һ�������׵㣬�ж��Ƿ�Ϊ��һ�ߵ�
                                                            {
                                                                  if( img_data[EXTRACT_ROW+1][W_num_col] == DOT_W )
                                                                  {
                                                                        W_num++;
                                                                  }
                                                            }
                                                            if( W_num>COL_W_NUM && L_barrier_flag==0 )             //���׿����ֵ������ֵ�����ж�Ϊ����ض�ʧ             /*����� W_num �ķ�ֵ��Ҫ����*/
                                                            {
                                                                  L_search_end=1;             //����������㲢�������ʮ�ֱ�־Ϊ0ʱ�����������쳣���ж�Ϊ�������������
                                                                  L_end_row=EXTRACT_ROW+1;    //����һ�е�����ֵ��������ؽ�������ֵ
                                                                  
                                                                  break;
                                                            }
                                                            
                                                            left_edge[EXTRACT_ROW]=EXTRACT_COL;          //���汾�������������
                                                            
                                                            L_EDGE_NUM++;                                //����ظ�����һ
                                                            
                                                            L_LINK_NUM++;                                //��������ظ�����һ
                                                            
                                                            L_get_flag=1;                                //����������õ���־��  1
                                                            
                                                            L_edge_nearest=EXTRACT_COL;                  //�洢���һ������ص�������
                                                            
                                                            break;                                      //�����������������
                                                      }
                                                }
                                                if( L_get_flag==0 )
                                                {
                                                      L_LINK_NUM=0;                                //��������ظ�����  0
                                                      
                                                      L_lost_num++;                                //�����������ʱ���������������׵㣬����ض�ʧ����һ
                                                }
                                          }
                                    }
                              }
                              
                              if( L_get_flag==1 )         //������������
                              {
                                    L_up_cross_extract();       //����������ʮ��ֱ�ǹյ�
                              }
                        }
                        else                  //�������û���жϳ���������ʱ���봦��
                        {
                              if( img_data[EXTRACT_ROW][L_edge_nearest] == DOT_B )     //����һ������ص���Ϸ�һ��Ϊ��
                              {
                                    for( EXTRACT_COL=L_edge_nearest+1 ; EXTRACT_COL<=L_edge_nearest+L_EDGE_IN ; EXTRACT_COL++ )            //��ʼ��������
                                    {
                                          if( EXTRACT_COL>COL_END-4 )    //����������ͼ��Χʱ����������
                                          {
                                                break;
                                          }
                                          if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL+2] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL+4] == DOT_W )   //�ҵ��ڰ������
                                          {
                                                left_edge[EXTRACT_ROW]=EXTRACT_COL-1;          //���汾�������������
                                                
                                                L_EDGE_NUM++;                                //����ظ�����һ
                                                
                                                L_LINK_NUM++;                                //��������ظ�����һ
                                                
                                                L_get_flag=1;                                //����������õ���־��  1
                                                
                                                L_edge_nearest=EXTRACT_COL-1;                  //�洢���һ������ص�������
                                                
                                                L_up_cross_judge();                    //��������ʮ�ֱ�־��Ϊ1������ʮ��ֱ�ǹյ��ж�
                                                
                                                break;                                      //�����������������
                                          }
                                    }
                                    if( L_get_flag==0 )
                                    {
                                          L_LINK_NUM=0;               //��������ظ�����  0
                                          
                                          L_lost_num++;               //��û������������ص�ʱ������ض�ʧ����һ
                                    }
                              }
                              else     //����һ������ص���Ϸ�һ��Ϊ��
                              {
                                    if(  img_data[EXTRACT_ROW][L_edge_nearest+1] == DOT_W && img_data[EXTRACT_ROW][L_edge_nearest+2] == DOT_W )        //֮������ҲΪ��
                                    {
                                          for( EXTRACT_COL=L_edge_nearest-1 ; EXTRACT_COL>=L_edge_nearest-L_EDGE_OUT ; EXTRACT_COL-- )           //��ʼ���������ڰ������
                                          {
                                                if( EXTRACT_COL<COL_START+2 )    //����������ͼ��Χʱ����������
                                                {
                                                      break;
                                                }
                                                if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_B && img_data[EXTRACT_ROW][EXTRACT_COL-1] == DOT_B && img_data[EXTRACT_ROW][EXTRACT_COL-2] == DOT_B )   //�ҵ��ڰ������
                                                {
                                                      left_edge[EXTRACT_ROW]=EXTRACT_COL;          //���汾�������������
                                                      
                                                      L_EDGE_NUM++;                                //����ظ�����һ
                                                      
                                                      L_LINK_NUM++;                                //��������ظ�����һ
                                                      
                                                      L_get_flag=1;                                //����������õ���־��  1
                                                      
                                                      L_edge_nearest=EXTRACT_COL;                  //�洢���һ������ص�������
                                                      
                                                      break;                                      //�����������������
                                                }
                                          }
                                          if( L_get_flag==0 )
                                          {
                                                L_LINK_NUM=0;       //��������ظ�����  0
                                                
                                                L_lost_num++;       //��û������������ص�ʱ������ض�ʧ����һ
                                          }
                                    }
                                    else           //֮�������кڵ�,���ж�Ϊ����
                                    {
                                          for( EXTRACT_COL=L_edge_nearest+1 ; EXTRACT_COL<=L_edge_nearest+L_EDGE_IN ; EXTRACT_COL++ )            //��ʼ���������ڰ������
                                          {
                                                if( EXTRACT_COL>COL_END-5 )    //����������ͼ��Χʱ����������
                                                {
                                                      break;
                                                }
                                                if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_B && img_data[EXTRACT_ROW][EXTRACT_COL+1] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL+3] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL+5] == DOT_W )   //�ҵ��ڰ������
                                                {
                                                      left_edge[EXTRACT_ROW]=EXTRACT_COL;          //���汾�������������
                                                      
                                                      L_EDGE_NUM++;                                //����ظ�����һ
                                                      
                                                      L_LINK_NUM++;                                //��������ظ�����һ
                                                      
                                                      L_get_flag=1;                                //����������õ���־��  1
                                                      
                                                      L_edge_nearest=EXTRACT_COL;                  //�洢���һ������ص�������
                                                      
                                                      break;                                      //�����������������
                                                }
                                          }
                                          if( L_get_flag==0 )
                                          {
                                                L_LINK_NUM=0;               //��������ظ�����  0
                                                
                                                L_lost_num++;               //��û������������ص�ʱ������ض�ʧ����һ
                                          }
                                    }
                              }
                              
                              if( L_LINK_NUM>=3 )  //����������һ�к��������������ڵ���3
                              {
                                    if(  left_edge[EXTRACT_ROW]>= left_edge[EXTRACT_ROW+1] || left_edge[EXTRACT_ROW]>= left_edge[EXTRACT_ROW+2] )
                                    {
                                          L_trend_in=1;     //�������������������������  1
                                    }
                                    else
                                    {
                                          L_trend_in=0;     //���������������������������  0
                                    }
                              }
                        }
                  }
                  else                        //������ض�ʧʱ���봦��
                  {
                        if( L_cross_flag==1 ) //�������ʮ�ֱ�־Ϊ1ʱ
                        {
                              if( L_down_cross[0]!=-1 )    //����⵽������·�ʮ��ֱ�ǹյ�
                              {
                                    if( L_down_cross[1]-CROSS_ERTRACT>COL_START )
                                    {
                                          W_num_col=L_down_cross[1]-CROSS_ERTRACT;
                                    }
                                    else
                                    {
                                          W_num_col=COL_START;
                                    }
                                    for( EXTRACT_COL=W_num_col ; EXTRACT_COL<=L_down_cross[1]+80 ; EXTRACT_COL++ )    //��ʼ����
                                    {
                                          if( EXTRACT_COL>COL_END-5 )   //����ͼ��Χֹͣ
                                          {
                                                break;
                                          }
                                          if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_B && img_data[EXTRACT_ROW][EXTRACT_COL+1] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL+3] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL+5] == DOT_W )      //���������ڰ������
                                          {
                                                W_num=0;            //����׿����ֵ
                                                for( W_num_col=EXTRACT_ROW-1 ; W_num_col>=EXTRACT_ROW-ROW_W_SUM ; W_num_col-- )     //���������ĺڰ����������������׵㣬�ж��Ƿ�Ϊ���ŵ�
                                                {
                                                      if( W_num_col<ROW_START )   //����ͼ��Χֹͣ
                                                      {
                                                            break;
                                                      }
                                                      if( img_data[W_num_col][EXTRACT_COL] == DOT_W )
                                                      {
                                                            W_num++;
                                                      }
                                                }
                                                if( W_num<ROW_W_NUM )              //���׿����ֵû������ֵ�����ж�Ϊ����ص�          /*����� W_num �ķ�ֵ��Ҫ����*/
                                                {
                                                      L_up_cross_error();                          //������Ϸ�ֱ�ǹյ�������
                                                      
                                                      if( L_get_flag==1 )
                                                      {
                                                            left_edge[EXTRACT_ROW]=EXTRACT_COL;          //���汾�������������
                                                            
                                                            L_EDGE_NUM++;                                //����ظ�����һ
                                                            
                                                            L_LINK_NUM++;                                //��������ظ�����һ
                                                            
                                                            L_edge_nearest=EXTRACT_COL;                  //�洢���һ������ص�������
                                                            
                                                            L_lost_num=0;                                //��������ض�ʧ����0
                                                            
                                                            if( cross_flag==0 && L_up_cross[0]!=-1 )
                                                            {
                                                                  cross_flag=1;                    //ʮ�ֱ�־��  1
                                                            }
                                                      }
                                                      
                                                      break;                                      //�����������������
                                                }
                                          }
                                    }
                                    if( L_get_flag==0 )
                                    {
                                          L_lost_num++;                          //��������ض�ʧ����1
                                    }
                              }
                              else                         //��δ��⵽������·�ʮ��ֱ�ǹյ�
                              {
                                    for( EXTRACT_COL=COL_START ; EXTRACT_COL<=L_LOST ; EXTRACT_COL++ )    //��ʼ����
                                    {
                                          if( EXTRACT_COL>COL_END-5 )   //����ͼ��Χֹͣ
                                          {
                                                break;
                                          }
                                          if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_B && img_data[EXTRACT_ROW][EXTRACT_COL+1] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL+3] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL+5] == DOT_W )      //���������ڰ������
                                          {
                                                L_up_cross_error();                          //������Ϸ�ֱ�ǹյ�������
                                                
                                                if( L_get_flag==1 )
                                                {
                                                      left_edge[EXTRACT_ROW]=EXTRACT_COL;          //���汾�������������
                                                      
                                                      L_EDGE_NUM++;                                //����ظ�����һ
                                                      
                                                      L_LINK_NUM++;                                //��������ظ�����һ
                                                      
                                                      L_edge_nearest=EXTRACT_COL;                  //�洢���һ������ص�������
                                                      
                                                      L_lost_num=0;                                //��������ض�ʧ����0
                                                      
                                                      if( cross_flag==0 && L_up_cross[0]!=-1 )
                                                      {
                                                            cross_flag=1;                    //ʮ�ֱ�־��  1
                                                      }
                                                }
                                                
                                                break;                                                  //�����������������
                                          }
                                    }
                                    if( L_get_flag==0 )
                                    {
                                          L_lost_num++;                          //��������ض�ʧ����1
                                    }
                              }
                        }
                        else                  //�������ʮ�ֱ�־Ϊ0ʱ
                        {
                              if( img_data[EXTRACT_ROW][COL_START] == DOT_W && img_data[EXTRACT_ROW][COL_START+1] == DOT_W && img_data[EXTRACT_ROW][COL_START+2] == DOT_W )    //��ǰ������Ϊ��
                              {
                                    if( LOOP_TEMP==0 )    //�������ڻ���
                                    {
                                          for( EXTRACT_COL=COL_START+3 ; EXTRACT_COL<L_LOST ; EXTRACT_COL++ )    //��ʼ����
                                          {
                                                if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_B && img_data[EXTRACT_ROW][EXTRACT_COL+1] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL+3] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL+5] == DOT_W )      //���������ڰ������
                                                {
                                                      if( EXTRACT_COL>20 && EXTRACT_ROW>40 )      //���������������
                                                      {
                                                            if( img_data[EXTRACT_ROW][EXTRACT_COL-3] == DOT_W || img_data[EXTRACT_ROW][EXTRACT_COL-6] == DOT_W || img_data[EXTRACT_ROW][EXTRACT_COL-9] == DOT_W || img_data[EXTRACT_ROW][EXTRACT_COL-12] == DOT_W || img_data[EXTRACT_ROW][EXTRACT_COL-15] == DOT_W )
                                                            {
                                                                  continue;
                                                            }
                                                      }
                                                      W_num=0;            //����׿����ֵ
                                                      for( W_num_col=EXTRACT_ROW-1 ; W_num_col>=EXTRACT_ROW-ROW_W_SUM ; W_num_col-- )     //���������ĺڰ����������������׵㣬�ж��Ƿ�Ϊ���ŵ�
                                                      {
                                                            if( W_num_col<ROW_START )   //����ͼ��Χֹͣ
                                                            {
                                                                  break;
                                                            }
                                                            if( img_data[W_num_col][EXTRACT_COL] == DOT_W )
                                                            {
                                                                  W_num++;
                                                            }
                                                      }
                                                      if( W_num<ROW_W_NUM )
                                                      {
                                                            left_edge[EXTRACT_ROW]=EXTRACT_COL;          //���汾�������������
                                                            
                                                            L_EDGE_NUM++;                                //����ظ�����һ
                                                            
                                                            L_LINK_NUM++;                                //��������ظ�����һ
                                                            
                                                            L_get_flag=1;                                //����������õ���־��  1
                                                            
                                                            L_edge_nearest=EXTRACT_COL;                  //�洢���һ������ص�������
                                                            
                                                            L_lost_num=0;                                //��������ض�ʧ����0
                                                            
                                                            break;                                      //�����������������
                                                      }
                                                      
                                                }
                                          }
                                          if( L_get_flag==0 )
                                          {
                                                L_lost_num++;             //������ض�ʧʱ���������������ڰ�����㣬�ж�Ϊ����ض�ʧ
                                          }
                                    }
                                    else    //�����ڻ���
                                    {
                                          if( loop_l_r_flag==0 )
                                          {
                                                for( EXTRACT_COL=COL_START+3 ; EXTRACT_COL<L_LOST ; EXTRACT_COL++ )    //��ʼ����
                                                {
                                                      if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_B && img_data[EXTRACT_ROW][EXTRACT_COL+1] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL+3] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL+5] == DOT_W )      //���������ڰ������
                                                      {
                                                            if( EXTRACT_COL>20 && EXTRACT_ROW>40 )      //���������������
                                                            {
                                                                  if( img_data[EXTRACT_ROW][EXTRACT_COL-3] == DOT_W || img_data[EXTRACT_ROW][EXTRACT_COL-6] == DOT_W || img_data[EXTRACT_ROW][EXTRACT_COL-9] == DOT_W || img_data[EXTRACT_ROW][EXTRACT_COL-12] == DOT_W || img_data[EXTRACT_ROW][EXTRACT_COL-15] == DOT_W )
                                                                  {
                                                                        continue;
                                                                  }
                                                            }
                                                            W_num=0;            //����׿����ֵ
                                                            for( W_num_col=EXTRACT_ROW-1 ; W_num_col>=EXTRACT_ROW-ROW_W_SUM ; W_num_col-- )     //���������ĺڰ����������������׵㣬�ж��Ƿ�Ϊ���ŵ�
                                                            {
                                                                  if( W_num_col<ROW_START )   //����ͼ��Χֹͣ
                                                                  {
                                                                        break;
                                                                  }
                                                                  if( img_data[W_num_col][EXTRACT_COL] == DOT_W )
                                                                  {
                                                                        W_num++;
                                                                  }
                                                            }
                                                            if( W_num<ROW_W_NUM )
                                                            {
                                                                  left_edge[EXTRACT_ROW]=EXTRACT_COL;          //���汾�������������
                                                                  
                                                                  L_EDGE_NUM++;                                //����ظ�����һ
                                                                  
                                                                  L_LINK_NUM++;                                //��������ظ�����һ
                                                                  
                                                                  L_get_flag=1;                                //����������õ���־��  1
                                                                  
                                                                  L_edge_nearest=EXTRACT_COL;                  //�洢���һ������ص�������
                                                                  
                                                                  L_lost_num=0;                                //��������ض�ʧ����0
                                                                  
                                                                  break;                                      //�����������������
                                                            }
                                                            
                                                      }
                                                }
                                                if( L_get_flag==0 )
                                                {
                                                      L_lost_num++;             //������ض�ʧʱ���������������ڰ�����㣬�ж�Ϊ����ض�ʧ
                                                }
                                          }
                                          else
                                          {
                                                L_lost_num++;             //������ض�ʧʱ���������������ڰ�����㣬�ж�Ϊ����ض�ʧ
                                          }
                                    }
                              }
                              else         //��ǰ�����㲻ȫΪ��
                              {
                                    if( LOOP_TEMP==1 && loop_l_r_flag==1 )
                                    {
                                          if( L_EDGE_NUM>=3 || EXTRACT_ROW<40 )
                                          {
                                                for( EXTRACT_COL=COL_START ; EXTRACT_COL<=L_LOOP ; EXTRACT_COL++ )    //��ʼ����
                                                {
                                                      if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_B && img_data[EXTRACT_ROW][EXTRACT_COL+1] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL+3] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL+5] == DOT_W )      //���������ڰ������
                                                      {
                                                            left_edge[EXTRACT_ROW]=EXTRACT_COL;        //���汾�������������
                                                            
                                                            L_EDGE_NUM++;                                //����ظ�����һ
                                                            
                                                            L_LINK_NUM++;                                //��������ظ�����һ
                                                            
                                                            L_get_flag=1;                                //����������õ���־��  1
                                                            
                                                            L_edge_nearest=EXTRACT_COL;                //�洢���һ������ص�������
                                                            
                                                            L_lost_num=0;                                //��������ض�ʧ����0
                                                            
                                                            break;                                      //�����������������
                                                      }
                                                }
                                                if( L_get_flag==0 )
                                                {
                                                      L_lost_num++;             //������ض�ʧʱ���������������ڰ�����㣬�ж�Ϊ����ض�ʧ
                                                }
                                          }
                                          else
                                          {
                                                for( EXTRACT_COL=COL_START ; EXTRACT_COL<=L_LOST ; EXTRACT_COL++ )    //��ʼ����
                                                {
                                                      if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_B && img_data[EXTRACT_ROW][EXTRACT_COL+1] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL+3] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL+5] == DOT_W )      //���������ڰ������
                                                      {
                                                            left_edge[EXTRACT_ROW]=EXTRACT_COL;        //���汾�������������
                                                            
                                                            L_EDGE_NUM++;                                //����ظ�����һ
                                                            
                                                            L_LINK_NUM++;                                //��������ظ�����һ
                                                            
                                                            L_get_flag=1;                                //����������õ���־��  1
                                                            
                                                            L_edge_nearest=EXTRACT_COL;                //�洢���һ������ص�������
                                                            
                                                            L_lost_num=0;                                //��������ض�ʧ����0
                                                            
                                                            break;                                      //�����������������
                                                      }
                                                }
                                                if( L_get_flag==0 )
                                                {
                                                      L_lost_num++;             //������ض�ʧʱ���������������ڰ�����㣬�ж�Ϊ����ض�ʧ
                                                }
                                          }
                                    }
                                    else
                                    {
                                          for( EXTRACT_COL=COL_START ; EXTRACT_COL<=L_LOST ; EXTRACT_COL++ )    //��ʼ����
                                          {
                                                if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_B && img_data[EXTRACT_ROW][EXTRACT_COL+1] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL+3] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL+5] == DOT_W )      //���������ڰ������
                                                {
                                                      left_edge[EXTRACT_ROW]=EXTRACT_COL;        //���汾�������������
                                                      
                                                      L_EDGE_NUM++;                                //����ظ�����һ
                                                      
                                                      L_LINK_NUM++;                                //��������ظ�����һ
                                                      
                                                      L_get_flag=1;                                //����������õ���־��  1
                                                      
                                                      L_edge_nearest=EXTRACT_COL;                //�洢���һ������ص�������
                                                      
                                                      L_lost_num=0;                                //��������ض�ʧ����0
                                                      
                                                      break;                                      //�����������������
                                                }
                                          }
                                          if( L_get_flag==0 )
                                          {
                                                L_lost_num++;             //������ض�ʧʱ���������������ڰ�����㣬�ж�Ϊ����ض�ʧ
                                          }
                                    }
                              }
                        }
                  }
            }
            else
            {
                  if( L_TURN==0 && R_TURN==0 )
                  {
                        if( img_data[EXTRACT_ROW][COL_START] == DOT_W && img_data[EXTRACT_ROW][COL_START+2] == DOT_W && img_data[EXTRACT_ROW][COL_START+4] == DOT_W )    //��ǰ������Ϊ��
                        {
                              L_lost_num++;             //�ж�Ϊ����ض�ʧ
                        }
                  }
            }
            
            
            
            /*���³����Ϊ�ұ��ؼ�����*/
            
            if( R_search_end==0 )       //���ұ�������δ����ʱ����
            {
                  if( R_lost_num==0 )         //���ұ���û�ж�ʧʱ���봦��
                  {
                        if( R_LINK_NUM>=3 )   //���ұ������������ڵ���3���жϳ���������ʱ���봦��
                        {
                              if( R_trend_in==1 )       //���ұ�������ʱ���봦��
                              {
                                    if( img_data[EXTRACT_ROW][R_edge_nearest]==DOT_B )     //����һ���ұ��ص���Ϸ�һ��Ϊ��
                                    {
                                          for( EXTRACT_COL=R_edge_nearest-1 ; EXTRACT_COL>=R_edge_nearest-R_IN_2_IN ; EXTRACT_COL-- )      //�ұ���������������
                                          {
                                                if( EXTRACT_COL<COL_START )    //����������ͼ��Χʱ����������
                                                {
                                                      break;
                                                }
                                                if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_W )  //�ҵ��ڰ������
                                                {
                                                      right_edge[EXTRACT_ROW]=EXTRACT_COL+1;       //���汾���ұ���������
                                                      
                                                      R_EDGE_NUM++;                                //�ұ��ظ�����һ
                                                      
                                                      R_LINK_NUM++;                                //�����ұ��ظ�����һ
                                                      
                                                      R_get_flag=1;                                //�ұ��������õ���־��  1
                                                      
                                                      R_edge_nearest=EXTRACT_COL+1;                //�洢���һ���ұ��ص�������
                                                      
                                                      R_up_cross_judge();                          //����ұ���ʮ�ֱ�־��Ϊ1������ʮ��ֱ�ǹյ��ж�
                                                      
                                                      break;                                      //�����ұ�����������
                                                }
                                          }
                                          
                                          if( inv_distance[EXTRACT_ROW]>120 && right_edge[EXTRACT_ROW]!=-1 && right_edge[EXTRACT_ROW+1]!=-1 )
                                          {
                                                if( right_edge[EXTRACT_ROW+1]-right_edge[EXTRACT_ROW]>=40 )
                                                {
                                                      W_num=0;
                                                      for( EXTRACT_COL=right_edge[EXTRACT_ROW+1]-1 ; EXTRACT_COL>=right_edge[EXTRACT_ROW] ; EXTRACT_COL-- )      //�����������������
                                                      {
                                                            if( img_data[EXTRACT_ROW+1][EXTRACT_COL] == DOT_B )
                                                            {
                                                                  W_num++;
                                                            }
                                                      }
                                                      if( W_num>=0.5*abs(right_edge[EXTRACT_ROW]-right_edge[EXTRACT_ROW+1]) )
                                                      {
                                                            right_edge[EXTRACT_ROW]=-1;
                                                            R_EDGE_NUM--;
                                                            R_LINK_NUM--;
                                                            R_get_flag=0;
                                                      }
                                                }
                                          }
                                          
                                          if( R_get_flag==0 )      //���ұ�����������δ�ѵ�����
                                          {
                                                if( R_down_cross[0]!=-1 && R_up_cross[0]!=-1 )
                                                {
                                                      W_num=0;
                                                      for( W_num_row=EXTRACT_ROW+1 ; W_num_row<=EXTRACT_ROW+15 ; W_num_row++ )      //�ұ���������������
                                                      {
                                                            if( W_num_row>=ROW_END )
                                                            {
                                                                  break;
                                                            }
                                                            if( right_edge[W_num_row]>right_edge[W_num_row+1] )
                                                            {
                                                                  W_num++;
                                                            }
                                                      }
                                                      if( W_num<=1 )
                                                      {
                                                            L_TURN=1;                //�����־��  1
                                                            
                                                            R_end_row=EXTRACT_ROW+1; //����һ�е�����ֵ�����ұ��ؽ�������ֵ
                                                            
                                                            R_search_end=1;             //���ұ�������ʱ���������������׵㣬�ж�Ϊ�ұ�����������
                                                            L_search_end=1;             //���ұ�������ʱ���������������׵㣬�ж�Ϊ�������������
                                                      }
                                                }
                                                else
                                                {
                                                      if( R_LINK_NUM>=10 )
                                                      {
                                                            W_num=0;
                                                            for( W_num_row=EXTRACT_ROW+1 ; W_num_row<=EXTRACT_ROW+10 ; W_num_row++ )      //�ұ���������������
                                                            {
                                                                  if( W_num_row>=ROW_END )
                                                                  {
                                                                        break;
                                                                  }
                                                                  if( right_edge[W_num_row]>right_edge[W_num_row+1] )
                                                                  {
                                                                        W_num++;
                                                                  }
                                                            }
                                                            if( W_num<=1 )
                                                            {
                                                                  L_TURN=1;                //�����־��  1
                                                                  
                                                                  R_end_row=EXTRACT_ROW+1; //����һ�е�����ֵ�����ұ��ؽ�������ֵ
                                                                  
                                                                  R_search_end=1;             //���ұ�������ʱ���������������׵㣬�ж�Ϊ�ұ�����������
                                                                  L_search_end=1;             //���ұ�������ʱ���������������׵㣬�ж�Ϊ�������������
                                                            }
                                                      }
                                                }
                                                
                                                R_LINK_NUM=0;               //�����ұ��ظ�����  0
                                                
                                                R_lost_num++;               //��û���������ұ��ص�ʱ���ұ��ض�ʧ����һ
                                          }
                                    }
                                    else                                                   //����һ���ұ��ص���Ϸ�һ��Ϊ��
                                    {
                                          for( EXTRACT_COL=R_edge_nearest+1 ; EXTRACT_COL<=R_edge_nearest+R_IN_2_OUT ; EXTRACT_COL++ )      //�ұ���������������
                                          {
                                                if( EXTRACT_COL>COL_END )    //����������ͼ��Χʱ����������
                                                {
                                                      break;
                                                }
                                                if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_B )
                                                {
                                                      right_edge[EXTRACT_ROW]=EXTRACT_COL;          //���汾���ұ���������
                                                      
                                                      R_EDGE_NUM++;                                //�ұ��ظ�����һ
                                                      
                                                      R_LINK_NUM++;                                //�����ұ��ظ�����һ
                                                      
                                                      R_get_flag=1;                                //�ұ��������õ���־��  1
                                                      
                                                      R_edge_nearest=EXTRACT_COL;                  //�洢���һ���ұ��ص�������
                                                      
                                                      R_trend_in=0;                                //���ұ��������־��  0
                                                      
                                                      R_down_cross_judge();                        //�ж��Ƿ�Ϊʮ��ֱ�ǹյ�
                                                      
                                                      break;                                      //�����ұ�����������
                                                }
                                          }
                                          if( R_get_flag==0 )      //���ұ�����������δ�ѵ�����
                                          {
                                                R_LINK_NUM=0;       //�����ұ��ظ�����  0
                                                
                                                R_lost_num++;       //��û���������ұ��ص�ʱ���ұ��ض�ʧ����һ
                                                
                                                R_down_cross_judge();                        //�ж��Ƿ�Ϊʮ��ֱ�ǹյ�
                                          }
                                    }
                              }
                              else       //���ұ�������ʱ���봦��
                              {
                                    if( img_data[EXTRACT_ROW][R_edge_nearest-1]==DOT_B )     //����һ���ұ��ص���Ϸ�һ��Ϊ��
                                    {
                                          for( EXTRACT_COL=R_edge_nearest-1 ; EXTRACT_COL>=R_edge_nearest-R_OUT_2_IN ; EXTRACT_COL-- )      //�ұ���������������
                                          {
                                                if( EXTRACT_COL<COL_START )    //����������ͼ��Χʱ����������
                                                {
                                                      break;
                                                }
                                                if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_W )  //�ҵ��ڰ������
                                                {
                                                      right_edge[EXTRACT_ROW]=EXTRACT_COL+1;        //���汾���ұ���������
                                                      
                                                      R_EDGE_NUM++;                                //�ұ��ظ�����һ
                                                      
                                                      R_LINK_NUM++;                                //�����ұ��ظ�����һ
                                                      
                                                      R_get_flag=1;                                //�ұ��������õ���־��  1
                                                      
                                                      R_edge_nearest=EXTRACT_COL+1;                //�洢���һ���ұ��ص�������
                                                      
                                                      R_trend_in=1;                                //�ұ����������Ʊ�־��  1
                                                      
                                                      break;                                      //�����ұ�����������
                                                }
                                          }
                                          if( R_get_flag==0 )      //���ұ�����������δ�ѵ�����
                                          {
                                                if( R_LINK_NUM>=10 && R_LINK_NUM>L_LINK_NUM )
                                                {
                                                      R_end_row=EXTRACT_ROW+1; //����һ�е�����ֵ�����ұ��ؽ�������ֵ
                                                      
                                                      R_search_end=1;             //���ұ�������ʱ���������������׵㣬�ж�Ϊ�ұ�����������
                                                      L_search_end=1;             //���ұ�������ʱ���������������׵㣬�ж�Ϊ�������������
                                                }
                                                
                                                R_LINK_NUM=0;               //�����ұ��ظ�����  0
                                                
                                                R_lost_num++;               //��û���������ұ��ص�ʱ���ұ��ض�ʧ����һ
                                          }
                                    }
                                    else          //����һ���ұ��ص���Ϸ�һ��Ϊ��
                                    {
                                          if( R_cross_flag==1 )    //���ұ�����ʮ�������õ�
                                          {
                                                for( EXTRACT_COL=R_edge_nearest ; EXTRACT_COL<=R_edge_nearest+R_OUT_2_OUT ; EXTRACT_COL++ )     //��ʼ��������
                                                {
                                                      if( EXTRACT_COL>COL_END )    //����������ͼ��Χʱ����������
                                                      {
                                                            break;
                                                      }
                                                      if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_B )
                                                      {
                                                            right_edge[EXTRACT_ROW]=EXTRACT_COL;          //���汾���ұ���������
                                                            
                                                            R_EDGE_NUM++;                                //�ұ��ظ�����һ
                                                            
                                                            R_LINK_NUM++;                                //�����ұ��ظ�����һ
                                                            
                                                            R_get_flag=1;                                //�ұ��������õ���־��  1
                                                            
                                                            R_edge_nearest=EXTRACT_COL;                  //�洢���һ���ұ��ص�������
                                                            
                                                            break;                                      //�����ұ�����������
                                                      }
                                                }
                                                if( R_get_flag==0 )
                                                {
                                                      R_LINK_NUM=0;                                //�����ұ��ظ�����  0
                                                      
                                                      R_lost_num++;                                //���ұ�������ʱ���������������׵㣬�ж�Ϊ�ұ��ض�ʧ����
                                                }
                                          }
                                          else                    //���ұ���ʮ�ֱ�־Ϊ0ʱ
                                          {
                                                for( EXTRACT_COL=R_edge_nearest+1 ; EXTRACT_COL<=R_edge_nearest+R_OUT_2_OUT ; EXTRACT_COL++ )     //��ʼ��������
                                                {
                                                      if( EXTRACT_COL>COL_END )  //����ֹͣ
                                                      {
                                                            break;
                                                      }
                                                      if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_B )
                                                      {
                                                            W_num=0;            //����׿����ֵ
                                                            for( W_num_col=R_edge_nearest ; W_num_col<=EXTRACT_COL ; W_num_col++ )     //���������ĺڰ�����������һ�������׵㣬�ж��Ƿ�Ϊ��һ�ߵ�
                                                            {
                                                                  if( img_data[EXTRACT_ROW+1][W_num_col] == DOT_W )
                                                                  {
                                                                        W_num++;
                                                                  }
                                                            }
                                                            if( W_num>COL_W_NUM && R_barrier_flag==0 )             //���׿����ֵ������ֵ�����ж�Ϊ�ұ��ض�ʧ             /*����� W_num �ķ�ֵ��Ҫ����*/
                                                            {
                                                                  R_search_end=1;             //���ұ������㲢���ұ���ʮ�ֱ�־Ϊ0ʱ�����������쳣���ж�Ϊ�ұ�����������
                                                                  R_end_row=EXTRACT_ROW+1;    //����һ�е�����ֵ�����ұ��ؽ�������ֵ
                                                                  
                                                                  break;
                                                            }
                                                            
                                                            right_edge[EXTRACT_ROW]=EXTRACT_COL;          //���汾���ұ���������
                                                            
                                                            R_EDGE_NUM++;                                //�ұ��ظ�����һ
                                                            
                                                            R_LINK_NUM++;                                //�����ұ��ظ�����һ
                                                            
                                                            R_get_flag=1;                                //�ұ��������õ���־��  1
                                                            
                                                            R_edge_nearest=EXTRACT_COL;                  //�洢���һ���ұ��ص�������
                                                            
                                                            break;                                      //�����ұ�����������
                                                      }
                                                }
                                                if( R_get_flag==0 )
                                                {
                                                      R_LINK_NUM=0;                                //�����ұ��ظ�����  0
                                                      
                                                      R_lost_num++;                                //���ұ�������ʱ���������������׵㣬�ж�Ϊ�ұ��ض�ʧ����
                                                }
                                          }
                                    }
                              }
                              
                              if( R_get_flag==1 )               //������������
                              {
                                    R_up_cross_extract();       //����������ʮ��
                              }
                        }
                        else                  //���ұ���û���жϳ���������ʱ���봦��
                        {
                              if( img_data[EXTRACT_ROW][R_edge_nearest] == DOT_B )     //����һ���ұ��ص���Ϸ�һ��Ϊ��
                              {
                                    for( EXTRACT_COL=R_edge_nearest-1 ; EXTRACT_COL>=R_edge_nearest-R_EDGE_IN ; EXTRACT_COL-- )            //��ʼ��������
                                    {
                                          if( EXTRACT_COL<COL_START+4 )    //����������ͼ��Χʱ����������
                                          {
                                                break;
                                          }
                                          if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL-2] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL-4] == DOT_W )   //�ҵ��ڰ������
                                          {
                                                right_edge[EXTRACT_ROW]=EXTRACT_COL+1;          //���汾���ұ���������
                                                
                                                R_EDGE_NUM++;                                //�ұ��ظ�����һ
                                                
                                                R_LINK_NUM++;                                //�����ұ��ظ�����һ
                                                
                                                R_get_flag=1;                                //�ұ��������õ���־��  1
                                                
                                                R_edge_nearest=EXTRACT_COL+1;                  //�洢���һ���ұ��ص�������
                                                
                                                R_up_cross_judge();                    //����ұ���ʮ�ֱ�־��Ϊ1������ʮ��ֱ�ǹյ��ж�
                                                
                                                break;                                      //�����ұ�����������
                                          }
                                    }
                                    if( R_get_flag==0 )
                                    {
                                          R_LINK_NUM=0;               //�����ұ��ظ�����  0
                                          
                                          R_lost_num++;               //��û���������ұ��ص�ʱ���ұ��ض�ʧ����һ
                                    }
                              }
                              else     //����һ���ұ��ص���Ϸ�һ��Ϊ��
                              {
                                    if(  img_data[EXTRACT_ROW][R_edge_nearest-1] == DOT_W && img_data[EXTRACT_ROW][R_edge_nearest-2] == DOT_W )        //֮������ҲΪ��
                                    {
                                          for( EXTRACT_COL=R_edge_nearest+1 ; EXTRACT_COL<=R_edge_nearest+R_EDGE_OUT ; EXTRACT_COL++ )           //��ʼ���������ڰ������
                                          {
                                                if( EXTRACT_COL>COL_END-2 )    //����������ͼ��Χʱ����������
                                                {
                                                      break;
                                                }
                                                if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_B )   //�ҵ��ڰ������
                                                {
                                                      right_edge[EXTRACT_ROW]=EXTRACT_COL;          //���汾���ұ���������
                                                      
                                                      R_EDGE_NUM++;                                //�ұ��ظ�����һ
                                                      
                                                      R_LINK_NUM++;                                //�����ұ��ظ�����һ
                                                      
                                                      R_get_flag=1;                                //�ұ��������õ���־��  1
                                                      
                                                      R_edge_nearest=EXTRACT_COL;                  //�洢���һ���ұ��ص�������
                                                      
                                                      break;                                      //�����ұ�����������
                                                }
                                          }
                                          if( R_get_flag==0 )
                                          {
                                                R_LINK_NUM=0;       //�����ұ��ظ�����  0
                                                
                                                R_lost_num++;       //��û���������ұ��ص�ʱ���ұ��ض�ʧ����һ
                                          }
                                    }
                                    else           //֮�������кڵ�,���ж�Ϊ����
                                    {
                                          for( EXTRACT_COL=R_edge_nearest-1 ; EXTRACT_COL>=R_edge_nearest-R_EDGE_IN ; EXTRACT_COL-- )            //��ʼ���������ڰ������
                                          {
                                                if( EXTRACT_COL<COL_START+5 )    //����������ͼ��Χʱ����������
                                                {
                                                      break;
                                                }
                                                if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_B && img_data[EXTRACT_ROW][EXTRACT_COL-1] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL-3] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL-5] == DOT_W )   //�ҵ��ڰ������
                                                {
                                                      right_edge[EXTRACT_ROW]=EXTRACT_COL;          //���汾���ұ���������
                                                      
                                                      R_EDGE_NUM++;                                //�ұ��ظ�����һ
                                                      
                                                      R_LINK_NUM++;                                //�����ұ��ظ�����һ
                                                      
                                                      R_get_flag=1;                                //�ұ��������õ���־��  1
                                                      
                                                      R_edge_nearest=EXTRACT_COL;                  //�洢���һ���ұ��ص�������
                                                      
                                                      break;                                      //�����������������
                                                }
                                          }
                                          if( R_get_flag==0 )
                                          {
                                                R_LINK_NUM=0;               //�����ұ��ظ�����  0
                                                
                                                R_lost_num++;               //��û���������ұ��ص�ʱ���ұ��ض�ʧ����һ
                                          }
                                    }
                              }
                              
                              if( R_LINK_NUM>=3 )  //����������һ�к��������������ڵ���3
                              {
                                    if(  right_edge[EXTRACT_ROW]<=right_edge[EXTRACT_ROW+1] || right_edge[EXTRACT_ROW]<=right_edge[EXTRACT_ROW+2] )
                                    {
                                          R_trend_in=1;     //�����������ұ�������������  1
                                    }
                                    else
                                    {
                                          R_trend_in=0;     //�������������ұ�������������  0
                                    }
                              }
                        }
                  }
                  else                        //���ұ��ض�ʧʱ���봦��
                  {
                        if( R_cross_flag==1 ) //���ұ���ʮ�ֱ�־Ϊ1ʱ
                        {
                              if( R_down_cross[0]!=-1 )    //����⵽�ұ����·�ʮ��ֱ�ǹյ�
                              {
                                    if( R_down_cross[1]+CROSS_ERTRACT<COL_END )
                                    {
                                          W_num_col=R_down_cross[1]+CROSS_ERTRACT;
                                    }
                                    else
                                    {
                                          W_num_col=COL_END;
                                    }
                                    for( EXTRACT_COL=W_num_col ; EXTRACT_COL>=R_down_cross[1]-80 ; EXTRACT_COL-- )    //��ʼ����
                                    {
                                          if( EXTRACT_COL<COL_START+5 )   //����ͼ��Χֹͣ
                                          {
                                                break;
                                          }
                                          if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_B && img_data[EXTRACT_ROW][EXTRACT_COL-1] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL-3] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL-5] == DOT_W )      //���������ڰ������
                                          {
                                                W_num=0;            //����׿����ֵ
                                                for( W_num_col=EXTRACT_ROW-1 ; W_num_col>=EXTRACT_ROW-ROW_W_SUM ; W_num_col-- )     //���������ĺڰ����������������׵㣬�ж��Ƿ�Ϊ���ŵ�
                                                {
                                                      if( W_num_col<ROW_START )   //����ͼ��Χֹͣ
                                                      {
                                                            break;
                                                      }
                                                      if( img_data[W_num_col][EXTRACT_COL] == DOT_W )
                                                      {
                                                            W_num++;
                                                      }
                                                }
                                                if( W_num<ROW_W_NUM )              //���׿����ֵû������ֵ�����ж�Ϊ�ұ��ص�          /*����� W_num �ķ�ֵ��Ҫ����*/
                                                {
                                                      R_up_cross_error();                          //�ұ����Ϸ�ֱ�ǹյ�������
                                                      
                                                      if( R_get_flag==1 )
                                                      {
                                                            right_edge[EXTRACT_ROW]=EXTRACT_COL;          //���汾���ұ���������
                                                            
                                                            R_EDGE_NUM++;                                //�ұ��ظ�����һ
                                                            
                                                            R_LINK_NUM++;                                //�����ұ��ظ�����һ
                                                            
                                                            R_edge_nearest=EXTRACT_COL;                  //�洢���һ���ұ��ص�������
                                                            
                                                            R_lost_num=0;                                //�����ұ��ض�ʧ����0
                                                            
                                                            if( cross_flag==0 && R_up_cross[0]!=-1 )
                                                            {
                                                                  cross_flag=1;                          //ʮ�ֱ�־��  1
                                                            }
                                                      }
                                                      
                                                      break;                                      //�����ұ�����������
                                                }
                                          }
                                    }
                                    if( R_get_flag==0 )
                                    {
                                          R_lost_num++;                          //�����ұ��ض�ʧ����1
                                    }
                              }
                              else                         //�����δ���ұ����·�ʮ��ֱ�ǹյ�
                              {
                                    for( EXTRACT_COL=COL_END ; EXTRACT_COL>=R_LOST ; EXTRACT_COL-- )    //��ʼ����
                                    {
                                          if( EXTRACT_COL<COL_START+5 )   //����ͼ��Χֹͣ
                                          {
                                                break;
                                          }
                                          if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_B && img_data[EXTRACT_ROW][EXTRACT_COL-1] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL-3] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL-5] == DOT_W )      //���������ڰ������
                                          {
                                                R_up_cross_error();                          //�ұ����Ϸ�ֱ�ǹյ�������
                                                
                                                if( R_get_flag==1 )
                                                {
                                                      right_edge[EXTRACT_ROW]=EXTRACT_COL;          //���汾���ұ���������
                                                      
                                                      R_EDGE_NUM++;                                //�ұ��ظ�����һ
                                                      
                                                      R_LINK_NUM++;                                //�����ұ��ظ�����һ
                                                      
                                                      R_edge_nearest=EXTRACT_COL;                  //�洢���һ���ұ��ص�������
                                                      
                                                      R_lost_num=0;                                //�����ұ��ض�ʧ����0
                                                      
                                                      if( cross_flag==0 && R_up_cross[0]!=-1 )
                                                      {
                                                            cross_flag=1;                          //ʮ�ֱ�־��  1
                                                      }
                                                }
                                                
                                                break;                                      //�����ұ�����������
                                          }
                                    }
                                    if( R_get_flag==0 )
                                    {
                                          R_lost_num++;                          //�����ұ��ض�ʧ����1
                                    }
                              }
                        }
                        else                  //���ұ���ʮ�ֱ�־Ϊ0ʱ
                        {
                              if( img_data[EXTRACT_ROW][COL_END] == DOT_W && img_data[EXTRACT_ROW][COL_END-1] == DOT_W && img_data[EXTRACT_ROW][COL_END-2] == DOT_W )    //��ǰ������Ϊ��
                              {
                                    if( LOOP_TEMP==0 )    //�������ڻ���
                                    {
                                          for( EXTRACT_COL=COL_END-3 ; EXTRACT_COL>R_LOST ; EXTRACT_COL-- )    //��ʼ����
                                          {
                                                if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_B && img_data[EXTRACT_ROW][EXTRACT_COL-1] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL-3] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL-5] == DOT_W )      //���������ڰ������
                                                {
                                                      if( EXTRACT_COL<139 && EXTRACT_ROW>40 )      //���������������
                                                      {
                                                            if( img_data[EXTRACT_ROW][EXTRACT_COL+3] == DOT_W || img_data[EXTRACT_ROW][EXTRACT_COL+6] == DOT_W || img_data[EXTRACT_ROW][EXTRACT_COL+9] == DOT_W || img_data[EXTRACT_ROW][EXTRACT_COL+12] == DOT_W || img_data[EXTRACT_ROW][EXTRACT_COL+15] == DOT_W )
                                                            {
                                                                  continue;
                                                            }
                                                      }
                                                      W_num=0;            //����׿����ֵ
                                                      for( W_num_col=EXTRACT_ROW-1 ; W_num_col>=EXTRACT_ROW-ROW_W_SUM ; W_num_col-- )     //���������ĺڰ����������������׵㣬�ж��Ƿ�Ϊ���ŵ�
                                                      {
                                                            if( W_num_col<ROW_START )   //����ͼ��Χֹͣ
                                                            {
                                                                  break;
                                                            }
                                                            if( img_data[W_num_col][EXTRACT_COL] == DOT_W )
                                                            {
                                                                  W_num++;
                                                            }
                                                      }
                                                      if( W_num<ROW_W_NUM )
                                                      {
                                                            right_edge[EXTRACT_ROW]=EXTRACT_COL;          //���汾���ұ���������
                                                            
                                                            R_EDGE_NUM++;                                //�ұ��ظ�����һ
                                                            
                                                            R_LINK_NUM++;                                //�����ұ��ظ�����һ
                                                            
                                                            R_get_flag=1;                                //�ұ��������õ���־��  1
                                                            
                                                            R_edge_nearest=EXTRACT_COL;                  //�洢���һ���ұ��ص�������
                                                            
                                                            R_lost_num=0;                                //�����ұ��ض�ʧ����0
                                                            
                                                            break;                                      //�����ұ�����������
                                                      }
                                                      
                                                }
                                          }
                                          if( R_get_flag==0 )
                                          {
                                                R_lost_num++;             //���ұ��ض�ʧʱ���������������ڰ�����㣬�ж�Ϊ�ұ��ض�ʧ
                                          }
                                    }
                                    else    //�����ڻ���
                                    {
                                          if( loop_l_r_flag==1 )
                                          {
                                                for( EXTRACT_COL=COL_END-3 ; EXTRACT_COL>R_LOST ; EXTRACT_COL-- )    //��ʼ����
                                                {
                                                      if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_B && img_data[EXTRACT_ROW][EXTRACT_COL-1] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL-3] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL-5] == DOT_W )      //���������ڰ������
                                                      {
                                                            if( EXTRACT_COL<139 && EXTRACT_ROW>40 )      //���������������
                                                            {
                                                                  if( img_data[EXTRACT_ROW][EXTRACT_COL+3] == DOT_W || img_data[EXTRACT_ROW][EXTRACT_COL+6] == DOT_W || img_data[EXTRACT_ROW][EXTRACT_COL+9] == DOT_W || img_data[EXTRACT_ROW][EXTRACT_COL+12] == DOT_W || img_data[EXTRACT_ROW][EXTRACT_COL+15] == DOT_W )
                                                                  {
                                                                        continue;
                                                                  }
                                                            }
                                                            W_num=0;            //����׿����ֵ
                                                            for( W_num_col=EXTRACT_ROW-1 ; W_num_col>=EXTRACT_ROW-ROW_W_SUM ; W_num_col-- )     //���������ĺڰ����������������׵㣬�ж��Ƿ�Ϊ���ŵ�
                                                            {
                                                                  if( W_num_col<ROW_START )   //����ͼ��Χֹͣ
                                                                  {
                                                                        break;
                                                                  }
                                                                  if( img_data[W_num_col][EXTRACT_COL] == DOT_W )
                                                                  {
                                                                        W_num++;
                                                                  }
                                                            }
                                                            if( W_num<ROW_W_NUM )
                                                            {
                                                                  right_edge[EXTRACT_ROW]=EXTRACT_COL;          //���汾���ұ���������
                                                                  
                                                                  R_EDGE_NUM++;                                //�ұ��ظ�����һ
                                                                  
                                                                  R_LINK_NUM++;                                //�����ұ��ظ�����һ
                                                                  
                                                                  R_get_flag=1;                                //�ұ��������õ���־��  1
                                                                  
                                                                  R_edge_nearest=EXTRACT_COL;                  //�洢���һ���ұ��ص�������
                                                                  
                                                                  R_lost_num=0;                                //�����ұ��ض�ʧ����0
                                                                  
                                                                  break;                                      //�����ұ�����������
                                                            }
                                                            
                                                      }
                                                }
                                                if( R_get_flag==0 )
                                                {
                                                      R_lost_num++;             //���ұ��ض�ʧʱ���������������ڰ�����㣬�ж�Ϊ�ұ��ض�ʧ
                                                }
                                          }
                                          else
                                          {
                                                R_lost_num++;             //���ұ��ض�ʧʱ���������������ڰ�����㣬�ж�Ϊ�ұ��ض�ʧ
                                          }
                                    }
                              }
                              else         //��ǰ�����㲻ȫΪ��
                              {
                                    if( LOOP_TEMP==1 && loop_l_r_flag==0 )
                                    {
                                          if( R_EDGE_NUM>=3 || EXTRACT_ROW<40 )
                                          {
                                                for( EXTRACT_COL=COL_END ; EXTRACT_COL>=R_LOOP ; EXTRACT_COL-- )    //��ʼ����
                                                {
                                                      if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_B && img_data[EXTRACT_ROW][EXTRACT_COL-1] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL-3] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL-5] == DOT_W )      //���������ڰ������
                                                      {
                                                            right_edge[EXTRACT_ROW]=EXTRACT_COL;        //���汾���ұ���������
                                                            
                                                            R_EDGE_NUM++;                                //�ұ��ظ�����һ
                                                            
                                                            R_LINK_NUM++;                                //�����ұ��ظ�����һ
                                                            
                                                            R_get_flag=1;                                //�ұ��������õ���־��  1
                                                            
                                                            R_edge_nearest=EXTRACT_COL;                //�洢���һ���ұ��ص�������
                                                            
                                                            R_lost_num=0;                                //�����ұ��ض�ʧ����0
                                                            
                                                            break;                                      //�����ұ�����������
                                                      }
                                                }
                                                if( R_get_flag==0 )
                                                {
                                                      R_lost_num++;             //���ұ��ض�ʧʱ���������������ڰ�����㣬�ж�Ϊ�ұ��ض�ʧ
                                                }
                                          }
                                          else
                                          {
                                                for( EXTRACT_COL=COL_END ; EXTRACT_COL>=R_LOST ; EXTRACT_COL-- )    //��ʼ����
                                                {
                                                      if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_B && img_data[EXTRACT_ROW][EXTRACT_COL-1] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL-3] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL-5] == DOT_W )      //���������ڰ������
                                                      {
                                                            right_edge[EXTRACT_ROW]=EXTRACT_COL;        //���汾���ұ���������
                                                            
                                                            R_EDGE_NUM++;                                //�ұ��ظ�����һ
                                                            
                                                            R_LINK_NUM++;                                //�����ұ��ظ�����һ
                                                            
                                                            R_get_flag=1;                                //�ұ��������õ���־��  1
                                                            
                                                            R_edge_nearest=EXTRACT_COL;                //�洢���һ���ұ��ص�������
                                                            
                                                            R_lost_num=0;                                //�����ұ��ض�ʧ����0
                                                            
                                                            break;                                      //�����ұ�����������
                                                      }
                                                }
                                                if( R_get_flag==0 )
                                                {
                                                      R_lost_num++;             //���ұ��ض�ʧʱ���������������ڰ�����㣬�ж�Ϊ�ұ��ض�ʧ
                                                }
                                          }
                                    }
                                    else
                                    {
                                          for( EXTRACT_COL=COL_END ; EXTRACT_COL>=R_LOST ; EXTRACT_COL-- )    //��ʼ����
                                          {
                                                if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_B && img_data[EXTRACT_ROW][EXTRACT_COL-1] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL-3] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL-5] == DOT_W )      //���������ڰ������
                                                {
                                                      right_edge[EXTRACT_ROW]=EXTRACT_COL;        //���汾���ұ���������
                                                      
                                                      R_EDGE_NUM++;                                //�ұ��ظ�����һ
                                                      
                                                      R_LINK_NUM++;                                //�����ұ��ظ�����һ
                                                      
                                                      R_get_flag=1;                                //�ұ��������õ���־��  1
                                                      
                                                      R_edge_nearest=EXTRACT_COL;                //�洢���һ���ұ��ص�������
                                                      
                                                      R_lost_num=0;                                //�����ұ��ض�ʧ����0
                                                      
                                                      break;                                      //�����ұ�����������
                                                }
                                          }
                                          if( R_get_flag==0 )
                                          {
                                                R_lost_num++;             //���ұ��ض�ʧʱ���������������ڰ�����㣬�ж�Ϊ�ұ��ض�ʧ
                                          }
                                    }
                              }
                        }
                  }
            }
            else
            {
                  if( L_TURN==0 && R_TURN==0 )
                  {
                        if( img_data[EXTRACT_ROW][COL_END] == DOT_W && img_data[EXTRACT_ROW][COL_END-2] == DOT_W && img_data[EXTRACT_ROW][COL_END-4] == DOT_W )    //��ǰ������Ϊ��
                        {
                              R_lost_num++;             //�ж�Ϊ����ض�ʧ
                        }
                  }
            }
            
            
            
            /*���³����Ϊ���ص��ж���������*/
            
            if( L_get_flag==1 && R_get_flag==1 )
            {
                  if( right_edge[EXTRACT_ROW]-left_edge[EXTRACT_ROW]<=0 )  //��ͬһ���������ض��ɼ������������ұ���λ���쳣ʱ
                  {
                        if( L_up_cross[0]==EXTRACT_ROW || R_up_cross[0]==EXTRACT_ROW )  //���ڴ������ұ����Ϸ�ֱ�ǹյ�ʱ
                        {
                              if( L_down_cross[0]!=-1 && R_down_cross[0]!=-1 )      //���Ѿ��ҵ����ұ����·�ֱ�ǹյ�ʱ
                              {
                                    if( L_up_cross[0]!=-1 && R_up_cross[0]!=-1 )
                                    {
                                          if( abs(L_up_cross[1]-L_down_cross[1]) > abs(R_up_cross[1]-R_down_cross[1]) )
                                          {
                                                left_edge[EXTRACT_ROW]=-1;            //������������������
                                                
                                                L_EDGE_NUM--;                         //����ظ�����һ
                                                
                                                L_LINK_NUM=0;                         //�����������ظ���
                                                
                                                L_lost_num++;                         //������ʧ����ظ�����һ
                                                
                                                L_up_cross[0]=-1;                     //���ʮ�ֹյ�������
                                                
                                                L_up_cross[1]=-1;                     //���ʮ�ֹյ�������
                                                
                                                L_cross_flag=0;                       //��������ʮ�ֱ�־
                                          }
                                          else
                                          {
                                                right_edge[EXTRACT_ROW]=-1;            //������������������
                                                
                                                R_EDGE_NUM--;                         //����ظ�����һ
                                                
                                                R_LINK_NUM=0;                         //�����������ظ���
                                                
                                                R_lost_num++;                         //������ʧ����ظ�����һ
                                                
                                                R_up_cross[0]=-1;                     //���ʮ�ֹյ�������
                                                
                                                R_up_cross[1]=-1;                     //���ʮ�ֹյ�������
                                                
                                                R_cross_flag=0;                       //��������ʮ�ֱ�־
                                          }
                                    }
                              }
                              if( L_down_cross[0]!=-1 && R_down_cross[0]==-1 )      //���Ѿ��ҵ�������·�ֱ�ǹյ�ʱ
                              {
                                    right_edge[EXTRACT_ROW]=-1;           //��������ұ���������
                                    
                                    R_EDGE_NUM--;                         //�ұ��ظ�����һ
                                    
                                    R_LINK_NUM=0;                         //��������ұ��ظ���
                                    
                                    R_lost_num++;                         //������ʧ�ұ��ظ�����һ
                                    
                                    R_up_cross[0]=-1;                     //���ʮ�ֹյ�������
                                    
                                    R_up_cross[1]=-1;                     //���ʮ�ֹյ�������
                                    
                                    R_cross_flag=0;                       //����ұ���ʮ�ֱ�־
                              }
                              if( L_down_cross[0]==-1 && R_down_cross[0]!=-1 )      //���Ѿ��ҵ��ұ����·�ֱ�ǹյ�ʱ
                              {
                                    left_edge[EXTRACT_ROW]=-1;            //������������������
                                    
                                    L_EDGE_NUM--;                         //����ظ�����һ
                                    
                                    L_LINK_NUM=0;                         //�����������ظ���
                                    
                                    L_lost_num++;                         //������ʧ����ظ�����һ
                                    
                                    L_up_cross[0]=-1;                     //���ʮ�ֹյ�������
                                    
                                    L_up_cross[1]=-1;                     //���ʮ�ֹյ�������
                                    
                                    L_cross_flag=0;                       //��������ʮ�ֱ�־
                              }
                              if( L_down_cross[0]==-1 && R_down_cross[0]==-1 )      //��������ʮ����ֱ�ǹյ�ʱ
                              {
                                    if( overtake_cross_flag )   //�ж��Ƿ����ʮ�ֳ���
                                    {
                                          if(car_L_pull_over_flag && !car_R_pull_over_flag)   //�ж�Ϊ��࿿��
                                          {
                                                right_edge[EXTRACT_ROW]=-1;           //��������ұ���������
                                                
                                                R_EDGE_NUM--;                         //�ұ��ظ�����һ
                                                
                                                R_LINK_NUM=0;                         //��������ұ��ظ���
                                                
                                                R_lost_num++;                         //������ʧ�ұ��ظ�����һ
                                                
                                                R_up_cross[0]=-1;                     //���ʮ�ֹյ�������
                                                
                                                R_up_cross[1]=-1;                     //���ʮ�ֹյ�������
                                                
                                                R_cross_flag=0;                       //����ұ���ʮ�ֱ�־
                                          }
                                          else if(car_R_pull_over_flag && !car_L_pull_over_flag)   //�ж�Ϊ�Ҳ࿿��
                                          {
                                                left_edge[EXTRACT_ROW]=-1;            //������������������
                                                
                                                L_EDGE_NUM--;                         //����ظ�����һ
                                                
                                                L_LINK_NUM=0;                         //�����������ظ���
                                                
                                                L_lost_num++;                         //������ʧ����ظ�����һ
                                                
                                                L_up_cross[0]=-1;                     //���ʮ�ֹյ�������
                                                
                                                L_up_cross[1]=-1;                     //���ʮ�ֹյ�������
                                                
                                                L_cross_flag=0;                       //��������ʮ�ֱ�־
                                          }
                                    }
                                    else
                                    {
                                          if( L_up_cross[0]>EXTRACT_ROW )      //���Ѿ��ҵ�������Ϸ�ֱ�ǹյ�ʱ
                                          {
                                                right_edge[EXTRACT_ROW]=-1;           //��������ұ���������
                                                
                                                R_EDGE_NUM--;                         //�ұ��ظ�����һ
                                                
                                                R_LINK_NUM=0;                         //��������ұ��ظ���
                                                
                                                R_lost_num++;                         //������ʧ�ұ��ظ�����һ
                                                
                                                R_up_cross[0]=-1;                     //���ʮ�ֹյ�������
                                                
                                                R_up_cross[1]=-1;                     //���ʮ�ֹյ�������
                                                
                                                R_cross_flag=0;                       //����ұ���ʮ�ֱ�־
                                          }
                                          if( R_up_cross[0]>EXTRACT_ROW )      //���Ѿ��ҵ��ұ����Ϸ�ֱ�ǹյ�ʱ
                                          {
                                                left_edge[EXTRACT_ROW]=-1;            //������������������
                                                
                                                L_EDGE_NUM--;                         //����ظ�����һ
                                                
                                                L_LINK_NUM=0;                         //�����������ظ���
                                                
                                                L_lost_num++;                         //������ʧ����ظ�����һ
                                                
                                                L_up_cross[0]=-1;                     //���ʮ�ֹյ�������
                                                
                                                L_up_cross[1]=-1;                     //���ʮ�ֹյ�������
                                                
                                                L_cross_flag=0;                       //��������ʮ�ֱ�־
                                          }
                                    }
                              }
                        }
                        else   //���ͼ��Ϊ��ͨ����
                        {
                              if( L_LINK_NUM>=3 && R_LINK_NUM>=3 )  //�����ұ�������ʱ���жϱ��ر仯�������
                              {
                                    if( abs(left_edge[EXTRACT_ROW]-left_edge[EXTRACT_ROW+1]) > abs(left_edge[EXTRACT_ROW]-left_edge[EXTRACT_ROW+1]) )
                                    {
                                          left_edge[EXTRACT_ROW]=-1;            //������������������
                                          
                                          L_EDGE_NUM--;                         //����ظ�����һ
                                          
                                          L_LINK_NUM=0;                         //�����������ظ���
                                          
                                          L_lost_num++;                         //������ʧ����ظ�����һ
                                    }
                                    else
                                    {
                                          right_edge[EXTRACT_ROW]=-1;           //��������ұ���������
                                          
                                          R_EDGE_NUM--;                         //�ұ��ظ�����һ
                                          
                                          R_LINK_NUM=0;                         //��������ұ��ظ���
                                          
                                          R_lost_num++;                         //������ʧ�ұ��ظ�����һ
                                    }
                              }
                              else
                              {
                                    W_num_row=0;
                                    W_num_col=0;
                                    for( EXTRACT_COL=EXTRACT_ROW+1 ; EXTRACT_COL<=EXTRACT_COL+5 ; EXTRACT_COL++ )
                                    {
                                          if( EXTRACT_COL>ROW_END )
                                          {
                                                break;
                                          }
                                          if( left_edge[EXTRACT_COL]!=-1 )
                                          {
                                                W_num_row++;
                                          }
                                          if( right_edge[EXTRACT_COL]!=-1 )
                                          {
                                                W_num_col++;
                                          }
                                    }
                                    if( W_num_row>W_num_col )   //��������������ұ߲�������ʱ
                                    {
                                          right_edge[EXTRACT_ROW]=-1;           //��������ұ���������
                                          
                                          R_EDGE_NUM--;                         //�ұ��ظ�����һ
                                          
                                          R_LINK_NUM=0;                         //��������ұ��ظ���
                                          
                                          R_lost_num++;                         //������ʧ�ұ��ظ�����һ
                                    }
                                    else
                                    {
                                          if( W_num_row<W_num_col )   //����߲����������ұ�������ʱ
                                          {
                                                left_edge[EXTRACT_ROW]=-1;            //������������������
                                                
                                                L_EDGE_NUM--;                         //����ظ�����һ
                                                
                                                L_LINK_NUM=0;                         //�����������ظ���
                                                
                                                L_lost_num++;                         //������ʧ����ظ�����һ
                                          }
                                          else    //�����ұ߶���������ʱ
                                          {
                                                if( (left_edge[EXTRACT_ROW]+right_edge[EXTRACT_ROW])<CAMERA_W )
                                                {
                                                      right_edge[EXTRACT_ROW]=-1;           //��������ұ���������
                                                      
                                                      R_EDGE_NUM--;                         //�ұ��ظ�����һ
                                                      
                                                      R_LINK_NUM=0;                         //��������ұ��ظ���
                                                      
                                                      R_lost_num++;                         //������ʧ�ұ��ظ�����һ
                                                }
                                                else
                                                {
                                                      left_edge[EXTRACT_ROW]=-1;            //������������������
                                                      
                                                      L_EDGE_NUM--;                         //����ظ�����һ
                                                      
                                                      L_LINK_NUM=0;                         //�����������ظ���
                                                      
                                                      L_lost_num++;                         //������ʧ����ظ�����һ
                                                }
                                          }
                                    }
                              }
                        }
                  }
                  else
                  {
                        if( double_car_flag==0 )   //���Ϊ����ģʽ
                        {
                              if( EXTRACT_ROW<=30 && EXTRACT_ROW>5 && right_edge[EXTRACT_ROW]-left_edge[EXTRACT_ROW]<=bar_range_col[EXTRACT_ROW] )    //����������쳣��С���жϹ��߸���
                              {
                                    if( L_LINK_NUM>R_LINK_NUM+10 && R_LINK_NUM<5 )
                                    {
                                          if( L_down_cross[0]<EXTRACT_ROW+5 )
                                          {
                                                L_down_cross[0]=-1;
                                                L_down_cross[1]=-1;
                                                L_cross_flag=0;
                                          }
                                          for( W_num_col=right_edge[EXTRACT_ROW] ; W_num_col<=COL_END-3 ; W_num_col++ )   //�������������
                                          {
                                                if( img_data[EXTRACT_ROW][W_num_col] == DOT_B && img_data[EXTRACT_ROW][W_num_col+1] == DOT_W && img_data[EXTRACT_ROW][W_num_col+3] == DOT_W )
                                                {
                                                      left_edge[EXTRACT_ROW]=W_num_col;          //���汾�������������
                                                      
                                                      L_EDGE_NUM++;                                //����ظ�����һ
                                                      
                                                      L_LINK_NUM++;                                //��������ظ�����һ
                                                      
                                                      L_get_flag=1;                                //����������õ���־��  1
                                                      
                                                      L_edge_nearest=W_num_col;                  //�洢���һ������ص�������
                                                      
                                                      L_lost_num=0;                                //��������ض�ʧ����0
                                                      
                                                      R_lost_num++;                                //���ұ��ض�ʧʱ���ж�Ϊ�ұ��ض�ʧ
                                                      
                                                      right_edge[EXTRACT_ROW]=-1;                  //��������ұ���������
                                                      
                                                      break;                                      //�����������������
                                                }
                                          }
                                          if( right_edge[EXTRACT_ROW]!=-1 )   //��Ϊ�����������
                                          {
                                                W_num=0;
                                                for( W_num_row=EXTRACT_ROW+1 ; W_num_row<=EXTRACT_ROW+10 ; W_num_row++ )      //�ұ���������������
                                                {
                                                      if( W_num_row>=ROW_END )
                                                      {
                                                            break;
                                                      }
                                                      if( left_edge[W_num_row]<left_edge[W_num_row+1] )
                                                      {
                                                            W_num++;
                                                      }
                                                }
                                                if( W_num<=1 )
                                                {
                                                      R_TURN=1;                   //�����־��  1
                                                      
                                                      L_end_row=EXTRACT_ROW+1;    //����һ�е�����ֵ��������ؽ�������ֵ
                                                      
                                                      L_search_end=1;             //�����������ʱ���������������׵㣬�ж�Ϊ�������������
                                                      R_search_end=1;             //�����������ʱ���������������׵㣬�ж�Ϊ�ұ�����������
                                                }
                                          }
                                    }
                                    else
                                    {
                                          if( R_LINK_NUM>L_LINK_NUM+10 && L_LINK_NUM<5 )
                                          {
                                                if( R_down_cross[0]<EXTRACT_ROW+5 )
                                                {
                                                      R_down_cross[0]=-1;
                                                      R_down_cross[1]=-1;
                                                      R_cross_flag=0;
                                                }
                                                for( W_num_col=left_edge[EXTRACT_ROW] ; W_num_col>=COL_START+3 ; W_num_col-- )   //�������������
                                                {
                                                      if( img_data[EXTRACT_ROW][W_num_col] == DOT_B && img_data[EXTRACT_ROW][W_num_col-1] == DOT_W && img_data[EXTRACT_ROW][W_num_col-3] == DOT_W )
                                                      {
                                                            right_edge[EXTRACT_ROW]=W_num_col;          //���汾���ұ���������
                                                            
                                                            R_EDGE_NUM++;                                //�ұ��ظ�����һ
                                                            
                                                            R_LINK_NUM++;                                //�����ұ��ظ�����һ
                                                            
                                                            R_get_flag=1;                                //�ұ��������õ���־��  1
                                                            
                                                            R_edge_nearest=W_num_col;                  //�洢���һ���ұ��ص�������
                                                            
                                                            R_lost_num=0;                                //�����ұ��ض�ʧ����0
                                                            
                                                            L_lost_num++;                                //������ض�ʧʱ���ж�Ϊ����ض�ʧ
                                                            
                                                            left_edge[EXTRACT_ROW]=-1;                   //������������������
                                                            
                                                            break;                                      //�����ұ�����������
                                                      }
                                                }
                                                if( left_edge[EXTRACT_ROW]!=-1 )   //��Ϊ�����������
                                                {
                                                      W_num=0;
                                                      for( W_num_row=EXTRACT_ROW+1 ; W_num_row<=EXTRACT_ROW+10 ; W_num_row++ )      //�ұ���������������
                                                      {
                                                            if( W_num_row>=ROW_END )
                                                            {
                                                                  break;
                                                            }
                                                            if( right_edge[W_num_row]>right_edge[W_num_row+1] )
                                                            {
                                                                  W_num++;
                                                            }
                                                      }
                                                      if( W_num<=1 )
                                                      {
                                                            L_TURN=1;                //�����־��  1
                                                            
                                                            R_end_row=EXTRACT_ROW+1; //����һ�е�����ֵ�����ұ��ؽ�������ֵ
                                                            
                                                            R_search_end=1;             //���ұ�������ʱ���������������׵㣬�ж�Ϊ�ұ�����������
                                                            L_search_end=1;             //���ұ�������ʱ���������������׵㣬�ж�Ϊ�������������
                                                      }
                                                }
                                          }
                                    }
                              }
                        }
                        else   //���Ϊ˫��ģʽ
                        {
                              if( car_flag==0 )  //���Ϊǰ��
                              {
                                    if( EXTRACT_ROW<=30 && EXTRACT_ROW>5 && right_edge[EXTRACT_ROW]-left_edge[EXTRACT_ROW]<=bar_range_col[EXTRACT_ROW] )    //����������쳣��С���жϹ��߸���
                                    {
                                          if( L_LINK_NUM>R_LINK_NUM+10 && R_LINK_NUM<5 )
                                          {
                                                if( L_down_cross[0]<EXTRACT_ROW+5 )
                                                {
                                                      L_down_cross[0]=-1;
                                                      L_down_cross[1]=-1;
                                                      L_cross_flag=0;
                                                }
                                                for( W_num_col=right_edge[EXTRACT_ROW] ; W_num_col<=COL_END-3 ; W_num_col++ )   //�������������
                                                {
                                                      if( img_data[EXTRACT_ROW][W_num_col] == DOT_B && img_data[EXTRACT_ROW][W_num_col+1] == DOT_W && img_data[EXTRACT_ROW][W_num_col+3] == DOT_W )
                                                      {
                                                            left_edge[EXTRACT_ROW]=W_num_col;          //���汾�������������
                                                            
                                                            L_EDGE_NUM++;                                //����ظ�����һ
                                                            
                                                            L_LINK_NUM++;                                //��������ظ�����һ
                                                            
                                                            L_get_flag=1;                                //����������õ���־��  1
                                                            
                                                            L_edge_nearest=W_num_col;                  //�洢���һ������ص�������
                                                            
                                                            L_lost_num=0;                                //��������ض�ʧ����0
                                                            
                                                            R_lost_num++;                                //���ұ��ض�ʧʱ���ж�Ϊ�ұ��ض�ʧ
                                                            
                                                            right_edge[EXTRACT_ROW]=-1;                  //��������ұ���������
                                                            
                                                            break;                                      //�����������������
                                                      }
                                                }
                                                if( right_edge[EXTRACT_ROW]!=-1 )   //��Ϊ�����������
                                                {
                                                      W_num=0;
                                                      for( W_num_row=EXTRACT_ROW+1 ; W_num_row<=EXTRACT_ROW+10 ; W_num_row++ )      //�ұ���������������
                                                      {
                                                            if( W_num_row>=ROW_END )
                                                            {
                                                                  break;
                                                            }
                                                            if( left_edge[W_num_row]<left_edge[W_num_row+1] )
                                                            {
                                                                  W_num++;
                                                            }
                                                      }
                                                      if( W_num<=1 )
                                                      {
                                                            R_TURN=1;                   //�����־��  1
                                                            
                                                            L_end_row=EXTRACT_ROW+1;    //����һ�е�����ֵ��������ؽ�������ֵ
                                                            
                                                            L_search_end=1;             //�����������ʱ���������������׵㣬�ж�Ϊ�������������
                                                            R_search_end=1;             //�����������ʱ���������������׵㣬�ж�Ϊ�ұ�����������
                                                      }
                                                }
                                          }
                                          else
                                          {
                                                if( R_LINK_NUM>L_LINK_NUM+10 && L_LINK_NUM<5 )
                                                {
                                                      if( R_down_cross[0]<EXTRACT_ROW+5 )
                                                      {
                                                            R_down_cross[0]=-1;
                                                            R_down_cross[1]=-1;
                                                            R_cross_flag=0;
                                                      }
                                                      for( W_num_col=left_edge[EXTRACT_ROW] ; W_num_col>=COL_START+3 ; W_num_col-- )   //�������������
                                                      {
                                                            if( img_data[EXTRACT_ROW][W_num_col] == DOT_B && img_data[EXTRACT_ROW][W_num_col-1] == DOT_W && img_data[EXTRACT_ROW][W_num_col-3] == DOT_W )
                                                            {
                                                                  right_edge[EXTRACT_ROW]=W_num_col;          //���汾���ұ���������
                                                                  
                                                                  R_EDGE_NUM++;                                //�ұ��ظ�����һ
                                                                  
                                                                  R_LINK_NUM++;                                //�����ұ��ظ�����һ
                                                                  
                                                                  R_get_flag=1;                                //�ұ��������õ���־��  1
                                                                  
                                                                  R_edge_nearest=W_num_col;                  //�洢���һ���ұ��ص�������
                                                                  
                                                                  R_lost_num=0;                                //�����ұ��ض�ʧ����0
                                                                  
                                                                  L_lost_num++;                                //������ض�ʧʱ���ж�Ϊ����ض�ʧ
                                                                  
                                                                  left_edge[EXTRACT_ROW]=-1;                   //������������������
                                                                  
                                                                  break;                                      //�����ұ�����������
                                                            }
                                                      }
                                                      if( left_edge[EXTRACT_ROW]!=-1 )   //��Ϊ�����������
                                                      {
                                                            W_num=0;
                                                            for( W_num_row=EXTRACT_ROW+1 ; W_num_row<=EXTRACT_ROW+10 ; W_num_row++ )      //�ұ���������������
                                                            {
                                                                  if( W_num_row>=ROW_END )
                                                                  {
                                                                        break;
                                                                  }
                                                                  if( right_edge[W_num_row]>right_edge[W_num_row+1] )
                                                                  {
                                                                        W_num++;
                                                                  }
                                                            }
                                                            if( W_num<=1 )
                                                            {
                                                                  L_TURN=1;                //�����־��  1
                                                                  
                                                                  R_end_row=EXTRACT_ROW+1; //����һ�е�����ֵ�����ұ��ؽ�������ֵ
                                                                  
                                                                  R_search_end=1;             //���ұ�������ʱ���������������׵㣬�ж�Ϊ�ұ�����������
                                                                  L_search_end=1;             //���ұ�������ʱ���������������׵㣬�ж�Ϊ�������������
                                                            }
                                                      }
                                                }
                                          }
                                    }
                              }
                              else if( car_flag==1 )  //���Ϊ��
                              {
                                    if( car_extract_able==1 )  //�����������֪�������ͱ���ģʽ�����ǰ��
                                    {
                                          if( EXTRACT_ROW<=40 && right_edge[EXTRACT_ROW]-left_edge[EXTRACT_ROW]<=1.5*bar_range_col[EXTRACT_ROW] )    //����������쳣��С���ж�ǰ������
                                          {
                                                if( left_edge[EXTRACT_ROW]<=40 )
                                                {
                                                      for( W_num_row=EXTRACT_ROW ; W_num_row<=ROW_END ; W_num_row++ )   //������������
                                                      {
                                                            if( fabsf(inv_distance[EXTRACT_ROW]-inv_distance[W_num_row])>60 )
                                                            {
                                                                  break;
                                                            }
                                                            if( left_edge[W_num_row]!=-1 )
                                                            {
                                                                  left_edge[W_num_row]=-1;
                                                                  L_EDGE_NUM--;
                                                                  if( L_down_cross[0]==W_num_row )
                                                                  {
                                                                        L_down_cross[0]=-1;
                                                                        L_down_cross[1]=-1;
                                                                        L_cross_flag=0;
                                                                        cross_flag=0;
                                                                  }
                                                            }
                                                            else
                                                            {
                                                                  break;
                                                            }
                                                      }
                                                      L_LINK_NUM=0;
                                                      L_lost_num++;         //�ж�Ϊ����ض�ʧ
                                                }
                                                else
                                                {
                                                      if( right_edge[EXTRACT_ROW]>=119 )
                                                      {
                                                            for( W_num_row=EXTRACT_ROW ; W_num_row<=ROW_END ; W_num_row++ )   //��������ұ���
                                                            {
                                                                  if( fabsf(inv_distance[EXTRACT_ROW]-inv_distance[W_num_row])>60 )
                                                                  {
                                                                        break;
                                                                  }
                                                                  if( right_edge[W_num_row]!=-1 )
                                                                  {
                                                                        right_edge[W_num_row]=-1;
                                                                        R_EDGE_NUM--;
                                                                        if( R_down_cross[0]==W_num_row )
                                                                        {
                                                                              R_down_cross[0]=-1;
                                                                              R_down_cross[1]=-1;
                                                                              R_cross_flag=0;
                                                                              cross_flag=0;
                                                                        }
                                                                  }
                                                                  else
                                                                  {
                                                                        break;
                                                                  }
                                                            }
                                                            R_LINK_NUM=0;
                                                            R_lost_num++;         //�ж�Ϊ�ұ��ض�ʧ
                                                      }
                                                      else
                                                      {
                                                            if( R_LINK_NUM>L_LINK_NUM+10 )
                                                            {
                                                                  for( W_num_row=EXTRACT_ROW ; W_num_row<=ROW_END ; W_num_row++ )   //������������
                                                                  {
                                                                        if( fabsf(inv_distance[EXTRACT_ROW]-inv_distance[W_num_row])>60 )
                                                                        {
                                                                              break;
                                                                        }
                                                                        if( left_edge[W_num_row]!=-1 )
                                                                        {
                                                                              left_edge[W_num_row]=-1;
                                                                              L_EDGE_NUM--;
                                                                              if( L_down_cross[0]==W_num_row )
                                                                              {
                                                                                    L_down_cross[0]=-1;
                                                                                    L_down_cross[1]=-1;
                                                                                    L_cross_flag=0;
                                                                                    cross_flag=0;
                                                                              }
                                                                        }
                                                                        else
                                                                        {
                                                                              break;
                                                                        }
                                                                  }
                                                                  L_LINK_NUM=0;
                                                                  L_lost_num++;         //�ж�Ϊ����ض�ʧ
                                                            }
                                                            else if( L_LINK_NUM>R_LINK_NUM+10 )
                                                            {
                                                                  for( W_num_row=EXTRACT_ROW ; W_num_row<=ROW_END ; W_num_row++ )   //��������ұ���
                                                                  {
                                                                        if( fabsf(inv_distance[EXTRACT_ROW]-inv_distance[W_num_row])>60 )
                                                                        {
                                                                              break;
                                                                        }
                                                                        if( right_edge[W_num_row]!=-1 )
                                                                        {
                                                                              right_edge[W_num_row]=-1;
                                                                              R_EDGE_NUM--;
                                                                              if( R_down_cross[0]==W_num_row )
                                                                              {
                                                                                    R_down_cross[0]=-1;
                                                                                    R_down_cross[1]=-1;
                                                                                    R_cross_flag=0;
                                                                                    cross_flag=0;
                                                                              }
                                                                        }
                                                                        else
                                                                        {
                                                                              break;
                                                                        }
                                                                  }
                                                                  R_LINK_NUM=0;
                                                                  R_lost_num++;         //�ж�Ϊ�ұ��ض�ʧ
                                                            }
                                                      }
                                                }
                                          }
                                    }
                              }
                        }
                  }
            }
            
            end_line_extract();      //�쳵ͣ����
            barrier_up_extract();    //�ϰ����ϱ����м��
            barrier_down_extract();  //�ϰ����±����м��
            
            if( left_edge[EXTRACT_ROW]==-1 && left_edge[EXTRACT_ROW+1]!=-1 && left_edge[EXTRACT_ROW+1]>L_OUT_END)
            {
                  if( LOOP_TEMP==0 && L_cross_flag==0 && R_cross_flag==0 && L_barrier_flag==0 && R_barrier_flag==0 )
                  {
                        L_search_end=1;
                  }
            }
            
            if( right_edge[EXTRACT_ROW]==-1 && right_edge[EXTRACT_ROW+1]!=-1 && right_edge[EXTRACT_ROW+1]<R_OUT_END)
            {
                  if( LOOP_TEMP==0 && L_cross_flag==0 && R_cross_flag==0 && L_barrier_flag==0 && R_barrier_flag==0 )
                  {
                        R_search_end=1;
                  }
            }
            
            if( inv_distance[EXTRACT_ROW]<60 )    //��������ͼ�������������ʱ��ǿ�Ƽ�������
            {
                  if( L_search_end==1 || R_search_end==1 )
                  {
                        L_search_end=0;
                        R_search_end=0;
                        L_TURN=0;
                        R_TURN=0;
                  }
            }
            
            if( L_lost_num>=5 && R_lost_num>=5 && L_up_cross[0]==-1 && R_up_cross[0]==-1 && l_cross_able==1 && r_cross_able==1 )  //�ж��Ƿ�Ϊʮ��
            {
                  L_search_end=0;
                  R_search_end=0;
                  L_cross_flag=1; //������ұ���ͬʱ���������ڷ�ֵ���Ҳ��ǻ��������ж�Ϊʮ��
                  R_cross_flag=1; //������ұ���ͬʱ���������ڷ�ֵ���Ҳ��ǻ��������ж�Ϊʮ��
                  cross_flag=1;   //������ұ���ͬʱ���������ڷ�ֵ���Ҳ��ǻ��������ж�Ϊʮ��
            }
            if( overtake_cross_flag )   //�ж��Ƿ����ʮ�ֳ���
            {
                  if(car_L_pull_over_flag && !car_R_pull_over_flag)   //�ж�Ϊ��࿿��
                  {
                        if( L_lost_num>=5 && L_up_cross[0]==-1 )  //ʮ�ֳ����ж��Ƿ�Ϊʮ��
                        {
                              L_search_end=0;
                              L_cross_flag=1; //������ұ���ͬʱ���������ڷ�ֵ���Ҳ��ǻ��������ж�Ϊʮ��
                              cross_flag=1;   //������ұ���ͬʱ���������ڷ�ֵ���Ҳ��ǻ��������ж�Ϊʮ��
                        }
                  }
                  else if(car_R_pull_over_flag && !car_L_pull_over_flag)   //�ж�Ϊ�Ҳ࿿��
                  {
                        if( R_lost_num>=5 && R_up_cross[0]==-1 )  //ʮ�ֳ����ж��Ƿ�Ϊʮ��
                        {
                              R_search_end=0;
                              R_cross_flag=1; //������ұ���ͬʱ���������ڷ�ֵ���Ҳ��ǻ��������ж�Ϊʮ��
                              cross_flag=1;   //������ұ���ͬʱ���������ڷ�ֵ���Ҳ��ǻ��������ж�Ϊʮ��
                        }
                  }
            }
            else
            {
                  if( EXTRACT_ROW<=ROW_END-1 )
                  {
                        if( L_down_cross[0]==-1 &&  R_down_cross[0]==-1 )
                        {
                              if( left_edge[EXTRACT_ROW]!=-1 && left_edge[EXTRACT_ROW+1]!=-1 && right_edge[EXTRACT_ROW]!=-1 && right_edge[EXTRACT_ROW+1]!=-1 )
                              {
                                    if( l_cross_able==1 && left_edge[EXTRACT_ROW]<left_edge[EXTRACT_ROW+1] )
                                    {
                                          l_cross_1++;
                                          l_cross_edge=l_cross_edge+abs(left_edge[EXTRACT_ROW+1]-left_edge[EXTRACT_ROW]);
                                          if( l_cross_1>=8 && l_cross_edge>=15 )
                                          {
                                                l_cross_able=0;
                                          }
                                    }
                                    
                                    if( r_cross_able==1 && right_edge[EXTRACT_ROW]>right_edge[EXTRACT_ROW+1] )
                                    {
                                          r_cross_1++;
                                          r_cross_edge=r_cross_edge+abs(right_edge[EXTRACT_ROW]-right_edge[EXTRACT_ROW+1]);
                                          if( r_cross_1>=8 && r_cross_edge>=15 )
                                          {
                                                r_cross_able=0;
                                          }
                                    }
                              }
                        }
                  }
            }
            
            if( loop_able==1 && LOOP_FLAG==0 && LOOP_IN==0 && EXTRACT_ROW>5 && L_barrier_flag==0 && R_barrier_flag==0 && END_LINE_TEMP==0 )    //�ж��Ƿ�Ϊ��������
            {
                  if( L_LINK_NUM>=10 && R_LINK_NUM>=10 )
                  {
                        W_num=0;
                        cross_row=-1;
                        for( W_num_row=EXTRACT_ROW ; W_num_row<=EXTRACT_ROW+10 ; W_num_row++ )
                        {
                              if( W_num_row>ROW_END-2 )
                              {
                                    break;
                              }
                              if( left_edge[W_num_row]!=-1 && left_edge[W_num_row+1]!=-1 )
                              {
                                    if( left_edge[W_num_row+1]-left_edge[W_num_row]>=2 )
                                    {
                                          W_num++;
                                    }
                                    else
                                    {
                                          if( left_edge[W_num_row+2]!=-1 )    //��������
                                          {
                                                if( left_edge[W_num_row]-left_edge[W_num_row+1]>=0 && left_edge[W_num_row+1]-left_edge[W_num_row+2]>=0 )
                                                {
                                                      cross_row=W_num_row;
                                                      break;
                                                }
                                          }
                                    }
                              }
                        }
                        W_num_col=0;
                        cross_col=-1;
                        for( W_num_row=EXTRACT_ROW ; W_num_row<=EXTRACT_ROW+10 ; W_num_row++ )
                        {
                              if( right_edge[W_num_row]!=-1 && right_edge[W_num_row+1]!=-1 )
                              {
                                    if( right_edge[W_num_row]-right_edge[W_num_row+1]>=2 )
                                    {
                                          W_num_col++;
                                    }
                                    else
                                    {
                                          if( right_edge[W_num_row+2]!=-1 )    //��������
                                          {
                                                if( right_edge[W_num_row]-right_edge[W_num_row+1]<=0 && right_edge[W_num_row+1]-right_edge[W_num_row+2]<=0 )
                                                {
                                                      cross_col=W_num_row;
                                                      break;
                                                }
                                          }
                                    }
                              }
                        }
                        
                        if( W_num>=4 && W_num_col>=4 && cross_row!=-1 && cross_col!=-1 )
                        {
                              if( cross_row>cross_col )
                              {
                                    cross_col=0;
                              }
                              else
                              {
                                    cross_row=cross_col;
                                    cross_col=0;
                              }
                              for( W_num_row=cross_row ; W_num_row<=cross_row+10 ; W_num_row++ )
                              {
                                    if( W_num_row>ROW_END )
                                    {
                                          break;
                                    }
                                    if( left_edge[W_num_row]!=-1 && right_edge[W_num_row]!=-1 )
                                    {
                                          if( abs(right_edge[W_num_row]-left_edge[W_num_row])<2.5*bar_range_col[W_num_row] )
                                          {
                                                if( abs(right_edge[W_num_row]-left_edge[W_num_row])>1.5*bar_range_col[W_num_row] )
                                                {
                                                      cross_col++;
                                                }
                                          }
                                    }
                              }
                              if( cross_col>=8 )
                              {
                                    LOOP_FLAG=1;                      //�ж�Ϊ��������
                                    
                                    LOOP_IN_ROW=cross_row;            //������������и�ֵ
                              }
                        }
                  }
            }
      }
      
      cross_edge_add();     //ʮ�ֱ��ز��䣨����ʮ�ִ�����أ�
      
      edge_error_process(); //���ش�����������ͨ����������أ��������ҹգ�ʶ��S�䣩
      
      road_judge();         //�ж��������ͣ�ʶ��ֱ�����µ���СS������ڣ�
      
      bar_car();            //�����ж�
      
      bar_process();        //�ϰ�����ز���
      
      road_num();           //�������ͼ�����ʮ�֣��ϰ��������
      
      loop_judge();         //���������ж�
      
      
      
      
      
      
      /*������*/
      
//      if( RAMP_TEMP==1 && angle_aaa[0]==0 )   //END_LINE_FLAG    //L_cross_flag==1 || R_cross_flag==1 || cross_flag==1      //RAMP_FLAG   //RAMP_TEMP  //down_flag  //LOOP_FLAG
//      {
//            Bee_flag=1;
//      }
//      if( RAMP_TEMP==0 && angle_aaa[0]==1 )   //END_LINE_FLAG    //L_cross_flag==1 || R_cross_flag==1 || cross_flag==1      //RAMP_FLAG   //RAMP_TEMP  //down_flag  //LOOP_FLAG
//      {
//            Bee_flag=1;
//      }
      
      
      
      
      
      
      /**���ʮ�ֺͻ���**/
//      if( L_down_cross[1]!=-1 && L_cross_k!=10 )
//      {
//            if( R_down_cross[1]!=-1 && R_cross_k!=10 )
//            {
//                  double aa;
//                  Site_xy xy_l,xy_r;
//                  Site_xy1 xy1,xy2;
//                  int16 l_edge,r_edge;
//                  int16 r_start,r_end,b_point,edge_able=0;
//                  xy_l=get_inv_img( L_down_cross[0] , L_down_cross[1] );
//                  xy_r=get_inv_img( R_down_cross[0] , R_down_cross[1] );
//                  
//                  if( xy_l.x<320 && xy_r.x<320 && fabsf(xy_l.y-xy_r.y)>120 && fabsf(xy_l.y-xy_r.y)<200 )
//                  {
//                        aa=0.5*(xy_l.x+xy_l.x)+220;
//                        xy1=get_invinv_img( aa , 0 );
//                        r_start=xy1.x;
//                        if( r_start<0 )
//                        {
//                              r_start=0;
//                        }
//                        aa=0.5*(xy_l.x+xy_l.x)+400;
//                        xy1=get_invinv_img( aa , 0 );
//                        r_end=xy1.x;
//                        if( r_end<0 )
//                        {
//                              r_end=0;
//                        }
//                        
//                        for( W_num_row=r_start ; W_num_row>=r_end ; W_num_row-- )
//                        {
//                              aa=xy_l.y-L_cross_k*fabsf(inv_distance[W_num_row]-xy_l.x);
//                              xy1=get_invinv_img( inv_distance[W_num_row] , aa );
//                              aa=xy_r.y-R_cross_k*fabsf(inv_distance[W_num_row]-xy_r.x);
//                              xy2=get_invinv_img( inv_distance[W_num_row] , aa );
//                              if( xy1.y>=COL_END )
//                              {
//                                    break;
//                              }
//                              else
//                              {
//                                    if( xy1.y<COL_START )
//                                    {
//                                          l_edge=COL_START;
//                                    }
//                                    else
//                                    {
//                                          l_edge=xy1.y;
//                                    }
//                              }
//                              
//                              if( xy2.y<=COL_START )
//                              {
//                                    break;
//                              }
//                              else
//                              {
//                                    if( xy2.y>COL_END )
//                                    {
//                                          r_edge=COL_END;
//                                    }
//                                    else
//                                    {
//                                          r_edge=xy2.y;
//                                    }
//                              }
//                              for( W_num_col=l_edge ; W_num_col<=r_edge ; W_num_col++ )
//                              {
//                                    img_data[W_num_row][W_num_col]=DOT_M;
//                              }
//                        }
//                  }
//            }
//            else
//            {
//                  double xxx=0,yyy=0;
//                  int16 xx;
//                  
//                  Site_xy1 xy2;
//                  Site_xy xy1;
//                  
//                  xy1=get_inv_img( L_down_cross[0] , L_down_cross[1] );
//                  
//                  for( W_num_row=L_down_cross[0] ; W_num_row>=ROW_START+5 ; W_num_row-- )
//                  {
//                        if( fabsf(inv_distance[W_num_row]-xy1.x)>cross_k_2 )
//                        {
//                              //break;
//                        }
//                        else
//                        {
//                              xxx=cross_k_1*fabsf(inv_distance[W_num_row]-xy1.x);
//                        }
//                        yyy=xy1.y-L_cross_k*fabsf(inv_distance[W_num_row]-xy1.x);
//                        xy2=get_invinv_img( inv_distance[W_num_row] , yyy );
//                        if( xy2.y>0 && xy2.y<159 )
//                        {
//                              img_data[W_num_row][xy2.y]=DOT_M;
//                              img_data[W_num_row][xy2.y-1]=DOT_M;
//                        }
//                        
//                        if( fabsf(inv_distance[W_num_row]-xy1.x)>180 && fabsf(inv_distance[W_num_row]-xy1.x)<400 )
//                        {
//                              for( W_num_col=xy2.y ; W_num_col<=xy2.y+2.0*bar_range_col[W_num_row] ; W_num_col++ )
//                              {
//                                    if( W_num_col>0 && W_num_col<159 )
//                                    {
//                                          img_data[W_num_row][W_num_col]=DOT_M;
//                                    }
//                              }
//                        }
//                        
//                        yyy=xy1.y-L_cross_k*fabsf(inv_distance[W_num_row]-xy1.x)+xxx;
//                        xy2=get_invinv_img( inv_distance[W_num_row] , yyy );
//                        if( xy2.y>0 && xy2.y<159 )
//                        {
//                              img_data[W_num_row][xy2.y]=DOT_M;
//                              img_data[W_num_row][xy2.y-1]=DOT_M;
//                        }
//                        
//                        xy2=get_invinv_img( inv_distance[W_num_row] , yyy+cross_k_add );
//                        if( xy2.y>0 && xy2.y<159 )
//                        {
//                              img_data[W_num_row][xy2.y]=DOT_M;
//                              img_data[W_num_row][xy2.y-1]=DOT_M;
//                        }
//                        xy2=get_invinv_img( inv_distance[W_num_row] , yyy-cross_k_add_1 );
//                        if( xy2.y>0 && xy2.y<159 )
//                        {
//                              img_data[W_num_row][xy2.y]=DOT_M;
//                              img_data[W_num_row][xy2.y-1]=DOT_M;
//                        }
//                  }
//            }
//      }
//      else
//      {
//            if( R_down_cross[1]!=-1 && R_cross_k!=10 )
//            {
//                  double xxx=0,yyy=0;
//                  int16 xx;
//                  
//                  Site_xy1 xy2;
//                  Site_xy xy1;
//                  
//                  xy1=get_inv_img( R_down_cross[0] , R_down_cross[1] );
//                  
//                  for( W_num_row=R_down_cross[0] ; W_num_row>=ROW_START ; W_num_row-- )
//                  {
//                        if( fabsf(inv_distance[W_num_row]-xy1.x)>cross_k_2 )
//                        {
//                              //break;
//                        }
//                        else
//                        {
//                              xxx=cross_k_1*fabsf(inv_distance[W_num_row]-xy1.x);
//                        }
//                        yyy=xy1.y-R_cross_k*fabsf(inv_distance[W_num_row]-xy1.x);  //cross_k_add
//                        xy2=get_invinv_img( inv_distance[W_num_row] , yyy );
//                        if( xy2.y>0 && xy2.y<159 )
//                        {
//                              img_data[W_num_row][xy2.y]=DOT_M;
//                              img_data[W_num_row][xy2.y+1]=DOT_M;
//                        }
//                        
//                        if( fabsf(inv_distance[W_num_row]-xy1.x)>180 && fabsf(inv_distance[W_num_row]-xy1.x)<400 )
//                        {
//                              for( W_num_col=xy2.y ; W_num_col>=xy2.y-2.0*bar_range_col[W_num_row] ; W_num_col-- )
//                              {
//                                    if( W_num_col>0 && W_num_col<159 )
//                                    {
//                                          img_data[W_num_row][W_num_col]=DOT_M;
//                                    }
//                              }
//                        }
//                        
//                        yyy=xy1.y-R_cross_k*fabsf(inv_distance[W_num_row]-xy1.x)-xxx;  //cross_k_add
//                        xy2=get_invinv_img( inv_distance[W_num_row] , yyy );
//                        if( xy2.y>0 && xy2.y<159 )
//                        {
//                              img_data[W_num_row][xy2.y]=DOT_M;
//                              img_data[W_num_row][xy2.y+1]=DOT_M;
//                        }
//                        
//                        xy2=get_invinv_img( inv_distance[W_num_row] , yyy-cross_k_add );
//                        if( xy2.y>0 && xy2.y<159 )
//                        {
//                              img_data[W_num_row][xy2.y]=DOT_M;
//                              img_data[W_num_row][xy2.y+1]=DOT_M;
//                        }
//                        xy2=get_invinv_img( inv_distance[W_num_row] , yyy+cross_k_add_1 );
//                        if( xy2.y>0 && xy2.y<159 )
//                        {
//                              img_data[W_num_row][xy2.y]=DOT_M;
//                              img_data[W_num_row][xy2.y+1]=DOT_M;
//                        }
//                  }
//            }
//      }
//      
      
      
      
      
      /**�����͸��**/
//      double edge_1[CAMERA_H],edge_2[CAMERA_H],edge_3[CAMERA_H];
//       
//      for( W_num_row=ROW_START ; W_num_row<=ROW_END ; W_num_row++ )
//      {
//            if( right_edge[W_num_row]!=-1 && left_edge[W_num_row]!=-1 )
//            {
//                  edge_1[W_num_row]=1.0*(left_edge[W_num_row]+right_edge[W_num_row])/2;
//                  edge_2[W_num_row]=1.0*(right_edge[W_num_row]-left_edge[W_num_row])/2;
//            }
//            else
//            {
//                  edge_1[W_num_row]=-1;
//                  edge_2[W_num_row]=-1;
//            }
//      }
//      double xxx=0,yyy=0;
//      for( W_num_row=ROW_START+5 ; W_num_row<=ROW_END ; W_num_row++ )
//      {
//            if( edge_1[W_num_row]!=-1 )
//            {
//                  xxx=xxx+edge_1[W_num_row];
//                  yyy++;
//            }
//      }
//      xxx=xxx/yyy;
//      for( W_num_row=ROW_START ; W_num_row<=ROW_END ; W_num_row++ )
//      {
//            if( edge_2[W_num_row]!=-1 )
//            {
//                  edge_3[W_num_row]=2.0*(edge_2[W_num_row]-bar_range_col[W_num_row]);
//            }
//            else
//            {
//                  edge_3[W_num_row]=-1;
//            }
//      }
//      Site_xy xy3;
//      double edge_4[CAMERA_H],edge_5[CAMERA_H];
//      double edge_l=0,edge_r=0,edge_l_f=0,edge_r_f=0;
//      int16 edge_l_num=0,edge_r_num=0;
//      for( W_num_row=ROW_START ; W_num_row<=ROW_END ; W_num_row++ )
//      {
//            if( left_edge[W_num_row]!=-1 )
//            {
//                  xy3=get_inv_img( W_num_row , left_edge[W_num_row] );
//                  edge_4[W_num_row]=xy3.y;
//                  edge_l_f=edge_l_f+fabsf(80.0+edge_4[W_num_row]);
//                  edge_l=edge_l+edge_4[W_num_row];
//                  edge_l_num++;
//            }
//            else
//            {
//                  edge_4[W_num_row]=-1;
//            }
//            if( right_edge[W_num_row]!=-1 )
//            {
//                  xy3=get_inv_img( W_num_row , right_edge[W_num_row] );
//                  edge_5[W_num_row]=xy3.y;
//                  edge_r_f=edge_r_f+fabsf(80.0-edge_5[W_num_row]);
//                  edge_r=edge_r+edge_5[W_num_row];
//                  edge_r_num++;
//            }
//            else
//            {
//                  edge_5[W_num_row]=-1;
//            }
//      }
//      angle_aaa[0]=edge_l/edge_l_num;
//      angle_aaa[1]=edge_r/edge_r_num;
//      angle_aaa[2]=100.0*edge_l_f/60;
//      angle_aaa[3]=100.0*edge_r_f/60;
      
      
}

/***********************************************************************************************************************************/

void L_down_cross_judge()           //�˺���Ϊ������·�ֱ�ǹյ��жϺ���
{
      if( l_cross_able==1 && L_up_cross[0]==-1 && L_down_cross[0]==-1 && left_edge[EXTRACT_ROW+1]>L_LOST_CROSS && EXTRACT_ROW>CROSS_DOWN_ROW && EXTRACT_ROW<=CROSS_START_ROW && L_barrier_flag==0 && R_barrier_flag==0 )      //��Ҫ�жϵĵ��ڷ�Χ��
      {
            W_num=0;            //����׿����ֵ
            for( W_num_row=EXTRACT_ROW+2 ; W_num_row<=EXTRACT_ROW+9 ; W_num_row++ )  //���ǰ8��������
            {
                  if( left_edge[W_num_row]!=-1 )
                  {
                        if( left_edge[W_num_row-1]-left_edge[W_num_row]<0 )
                        {
                              W_num++;
                        }
                  }
                  else
                  {
                        W_num=10;
                        break;
                  }
            }
            
            if( W_num<=1 )   //ǰ������������������㷧ֵ
            {
                  for( W_num=0 ; W_num<=2 ; W_num++ )
                  {
                        inv_cross[W_num]=-1;
                  }
                  uint8 num=0;        //��¼���ߵ����
                  W_num=0;            //��¼��������
                  if( left_edge[EXTRACT_ROW]!=-1 )
                  {
                        if( EXTRACT_ROW>=15 && left_edge[EXTRACT_ROW+1]-left_edge[EXTRACT_ROW]<CROSS_DOWN_COL )
                        {
                              EXTRACT_COL=left_edge[EXTRACT_ROW];
                              for( W_num_row=EXTRACT_ROW-1 ; W_num_row>=EXTRACT_ROW-6 ; W_num_row-- )   //������������
                              {
                                    if( img_data[W_num_row][EXTRACT_COL+1]==DOT_B )
                                    {
                                          W_num++;
                                          continue;
                                    }
                                    for( W_num_col=EXTRACT_COL ; W_num_col>=COL_START ; W_num_col-- )
                                    {
                                          if( img_data[W_num_row][W_num_col]==DOT_B && img_data[W_num_row][W_num_col+1]==DOT_W )
                                          {
                                                EXTRACT_COL=W_num_col;
                                                break;
                                          }
                                    }
                                    if( W_num_col<COL_START )
                                    {
                                          if( img_data[W_num_row][COL_START]==DOT_W && img_data[W_num_row][COL_START+1]==DOT_W )
                                          {
                                                EXTRACT_COL=COL_START;
                                                num++;
                                          }
                                    }
                                    if( (EXTRACT_ROW-W_num_row)==3 )
                                    {
                                          inv_cross[0]=EXTRACT_COL;
                                    }
                                    if( (EXTRACT_ROW-W_num_row)==4 )
                                    {
                                          inv_cross[1]=EXTRACT_COL;
                                    }
                                    if( (EXTRACT_ROW-W_num_row)==5 )
                                    {
                                          inv_cross[2]=EXTRACT_COL;
                                    }
                              }
                        }
                  }
                  else
                  {
                        if( EXTRACT_ROW>=15 )
                        {
                              EXTRACT_COL=COL_START;
                              for( W_num_row=EXTRACT_ROW-1 ; W_num_row>=EXTRACT_ROW-6 ; W_num_row-- )   //������������
                              {
                                    if( img_data[W_num_row][EXTRACT_COL+1]==DOT_B )
                                    {
                                          W_num++;
                                          continue;
                                    }
                                    for( W_num_col=EXTRACT_COL ; W_num_col>=COL_START ; W_num_col-- )
                                    {
                                          if( img_data[W_num_row][W_num_col]==DOT_B && img_data[W_num_row][W_num_col+1]==DOT_W )
                                          {
                                                EXTRACT_COL=W_num_col;
                                                break;
                                          }
                                    }
                                    if( W_num_col<COL_START )
                                    {
                                          if( img_data[W_num_row][COL_START]==DOT_W && img_data[W_num_row][COL_START+1]==DOT_W )
                                          {
                                                EXTRACT_COL=COL_START;
                                                num++;
                                          }
                                    }
                                    if( (EXTRACT_ROW-W_num_row)==3 )
                                    {
                                          inv_cross[0]=EXTRACT_COL;
                                    }
                                    if( (EXTRACT_ROW-W_num_row)==4 )
                                    {
                                          inv_cross[1]=EXTRACT_COL;
                                    }
                                    if( (EXTRACT_ROW-W_num_row)==5 )
                                    {
                                          inv_cross[2]=EXTRACT_COL;
                                    }
                              }
                        }
                  }
                  if( W_num<=1 )   //���Ѱ׵������㷧ֵ
                  {
                        if( left_edge[EXTRACT_ROW]==-1 || left_edge[EXTRACT_ROW+1]-left_edge[EXTRACT_ROW]>=CROSS_DOWN_COL )       //�����ؾ��ұ仯ʱ���ж�Ϊ��ʮ��ֱ��
                        {
                              L_down_cross[0]=EXTRACT_ROW+1;                           //�洢�����ʮ���·�ֱ�ǹյ�������
                              L_down_cross[1]=left_edge[EXTRACT_ROW+1];                //�洢�����ʮ���·�ֱ�ǹյ�������
                              
                              L_cross_flag=1;      //����������ʱ���ж�Ϊ����ͻ�䣬�����ʮ�ֱ�־��  1
                        }
                        else
                        {
                              if( num>=4 )    //���ѱ��������٣�ֱ���ж�Ϊʮ��
                              {
                                    L_down_cross[0]=EXTRACT_ROW+1;                           //�洢�����ʮ���·�ֱ�ǹյ�������
                                    L_down_cross[1]=left_edge[EXTRACT_ROW+1];                //�洢�����ʮ���·�ֱ�ǹյ�������
                                    
                                    L_cross_flag=1;      //����������ʱ���ж�Ϊ����ͻ�䣬�����ʮ�ֱ�־��  1
                              }
                              else              //���ѱ������㹻����͸��У���Ƕ��ж�ʮ��
                              {
                                    int16 k1=0,k2=0,k3=0;
                                    double x=0.0,y=0.0,x1,y1,k=0.0;
                                    Site_xy xy1,xy2;
                                    int16 row_add;
                                    row_add=EXTRACT_ROW/12;
                                    
                                    xy1=get_inv_img( EXTRACT_ROW+1 , left_edge[EXTRACT_ROW+1] );    //��ȡ�յ���͸������
                                    
                                    W_num_row=4;
                                    
                                    for( W_num=1 ; W_num<=W_num_row ; W_num++ )   //��ȡ�յ����µ����б��
                                    {
                                          W_num_col=EXTRACT_ROW+W_num+row_add;
                                          if( W_num_col>ROW_END )
                                          {
                                                break;
                                          }
                                          if( left_edge[W_num_col]!=-1 )
                                          {
                                                xy2=get_inv_img( W_num_col , left_edge[W_num_col] );
                                                x1=xy2.x-xy1.x;
                                                y1=xy2.y-xy1.y;
                                                x=x+x1*y1;
                                                y=y+x1*x1;
                                          }
                                    }
                                    if( x!=0 )
                                    {
                                          k=(-1)*x/y;    //�õ��յ����µ����б��
                                    }
                                    else
                                    {
                                          k==0;
                                    }
                                    if( k>=0 )
                                    {
                                          for( W_num=0 ; W_num<=29 ; W_num++ )
                                          {
                                                if( k<=tan_table[W_num] )
                                                {
                                                      k1=180-3*W_num;
                                                      break;
                                                }
                                          }
                                          if( W_num==30 )
                                          {
                                                k1=90;
                                          }
                                    }
                                    else
                                    {
                                          k=fabsf(k);
                                          for( W_num=0 ; W_num<=29 ; W_num++ )
                                          {
                                                if( k<=tan_table[W_num] )
                                                {
                                                      k1=180+3*W_num;
                                                      break;
                                                }
                                          }
                                          if( W_num==30 )
                                          {
                                                k1=270;
                                          }
                                    }
                                    
                                    x=0.0;
                                    y=0.0;
                                    for( W_num=0 ; W_num<=2 ; W_num++ )   //��ȡ�յ����ϵ����б��
                                    {
                                          if( inv_cross[W_num]!=-1 )
                                          {
                                                xy2=get_inv_img( EXTRACT_ROW-W_num-2 , inv_cross[W_num] );
                                                x1=xy2.x-xy1.x;
                                                y1=xy2.y-xy1.y;
                                                x=x+x1*y1;
                                                y=y+x1*x1;
                                          }
                                    }
                                    if( x!=0 )
                                    {
                                          k=(-1)*x/y;    //�õ��յ����ϵ����б��
                                    }
                                    else
                                    {
                                          k==0;
                                    }
                                    if( k>=0 )
                                    {
                                          for( W_num=0 ; W_num<=29 ; W_num++ )
                                          {
                                                if( k<=tan_table[W_num] )
                                                {
                                                      k2=-3*W_num;
                                                      break;
                                                }
                                          }
                                          if( W_num==30 )
                                          {
                                                k2=-90;
                                          }
                                    }
                                    else
                                    {
                                          k=fabsf(k);
                                          for( W_num=0 ; W_num<=29 ; W_num++ )
                                          {
                                                if( k<=tan_table[W_num] )
                                                {
                                                      k2=3*W_num;
                                                      break;
                                                }
                                          }
                                          if( W_num==30 )
                                          {
                                                k2=90;
                                          }
                                    }
                                    
                                    k3=abs(360+k2-k1);
                                    angle_aaa[0]=k3;
                                    if( k3<=117 )  //ͨ���Ƕ�У���ж�Ϊʮ��
                                    {
                                          L_down_cross[0]=EXTRACT_ROW+1;                           //�洢�����ʮ���·�ֱ�ǹյ�������
                                          L_down_cross[1]=left_edge[EXTRACT_ROW+1];                //�洢�����ʮ���·�ֱ�ǹյ�������
                                          
                                          L_cross_flag=1;      //����������ʱ���ж�Ϊ����ͻ�䣬�����ʮ�ֱ�־��  1
                                    }
                              }
                        }
                        
                        if( L_down_cross[0]!=-1 )
                        {
                              double x=0.0,y=0.0,x1,y1,k=0.0,a;
                              Site_xy xy1,xy2;
                              Site_xy1 xy3;
                              
                              xy1=get_inv_img( L_down_cross[0] , L_down_cross[1] );    //��ȡ�յ���͸������
                              
                              a=xy1.x-50;
                              xy3=get_invinv_img( a , 0 );
                              if( xy3.x-L_down_cross[0]>15 )
                              {
                                    W_num_row=15;
                              }
                              else
                              {
                                    if( xy3.x-L_down_cross[0]<3 )
                                    {
                                          W_num_row=3;
                                    }
                                    else
                                    {
                                          W_num_row=abs(xy3.x-L_down_cross[0]);
                                    }
                              }
                              
                              for( W_num=1 ; W_num<=W_num_row ; W_num++ )   //��ȡ�յ����µ����б��
                              {
                                    W_num_col=EXTRACT_ROW+W_num+1;
                                    if( W_num_col>ROW_END )
                                    {
                                          break;
                                    }
                                    if( left_edge[W_num_col]!=-1 )
                                    {
                                          xy2=get_inv_img( W_num_col , left_edge[W_num_col] );
                                          x1=xy2.x-xy1.x;
                                          y1=xy2.y-xy1.y;
                                          x=x+x1*y1;
                                          y=y+x1*x1;
                                    }
                                    else
                                    {
                                          break;
                                    }
                              }
                              if( x!=0 )
                              {
                                    k=(-1)*x/y;    //�õ��յ����µ����б��
                              }
                              else
                              {
                                    k==0;
                              }
                              
                              L_cross_k=k;        //ȡ�������б��
                        }
                  }
            }
      }
}

/***********************************************************************************************************************************/

void L_up_cross_judge()             //�˺���Ϊ������Ϸ�ֱ�ǹյ��жϺ���
{
      if( l_cross_able==1 && L_cross_flag==1 && EXTRACT_ROW<=CROSS_START_ROW && EXTRACT_ROW>CROSS_UP_ROW )         //�������ʮ�ֱ�Ϊ1ʱ
      {
            if( L_down_cross[0]!=-1 )   //��ȡ��ʮ�ֹյ�
            {
                  if( fabsf(inv_distance[EXTRACT_ROW]-inv_distance[L_down_cross[0]])<cross_k_2 )
                  {
                        if( L_LINK_NUM>=2 && L_LINK_NUM<(L_down_cross[0]-EXTRACT_ROW-1) )     //�������ı��ش���1ʱ
                        {
                              if( L_up_cross[0]!=-1 )
                              {
                                    Site_xy xy1,xy2;
                                    xy1=get_inv_img(EXTRACT_ROW,left_edge[EXTRACT_ROW]);
                                    xy2=get_inv_img(L_up_cross[0],L_up_cross[1]);
                                    if( 2.0*xy1.x-xy1.y<=2.0*xy2.x-xy2.y )     //��������ʱ���ж�Ϊʮ��ֱ�ǹյ�
                                    {
                                          double xx,aa;
                                          xy2=get_inv_img( L_down_cross[0] , L_down_cross[1] );
                                          
                                          if( fabsf(xy1.x-xy2.x)>cross_k_2 )
                                          {
                                                aa=cross_k_1*cross_k_2;
                                          }
                                          else
                                          {
                                                aa=cross_k_1*fabsf(xy1.x-xy2.x);
                                          }
                                          xx=xy2.y-L_cross_k*fabsf(xy1.x-xy2.x)+cross_k_add+aa;
                                          
                                          if( xy1.y<=xx )
                                          {
                                                L_up_cross[0]=EXTRACT_ROW;                        //�洢�����ʮ���·�ֱ�ǹյ�������
                                                L_up_cross[1]=left_edge[EXTRACT_ROW];             //�洢�����ʮ���·�ֱ�ǹյ�������
                                          }
                                    }
                              }
                              else
                              {
                                    double xx,aa;
                                    Site_xy xy1,xy2;
                                    xy1=get_inv_img(EXTRACT_ROW,left_edge[EXTRACT_ROW]);
                                    xy2=get_inv_img( L_down_cross[0] , L_down_cross[1] );
                                    
                                    if( fabsf(xy1.x-xy2.x)>cross_k_2 )
                                    {
                                          aa=cross_k_1*cross_k_2;
                                    }
                                    else
                                    {
                                          aa=cross_k_1*fabsf(xy1.x-xy2.x);
                                    }
                                    xx=xy2.y-L_cross_k*fabsf(xy1.x-xy2.x)+cross_k_add+aa;
                                    
                                    if( xy1.y<=xx )
                                    {
                                          L_up_cross[0]=EXTRACT_ROW;                        //�洢�����ʮ���·�ֱ�ǹյ�������
                                          L_up_cross[1]=left_edge[EXTRACT_ROW];             //�洢�����ʮ���·�ֱ�ǹյ�������
                                    }
                              }
                        }
                  }
                  else
                  {
                        L_cross_flag=0;
                        cross_flag=1;
                  }
            }
            else   //δ��ȡ��ʮ�ֹյ�
            {
                  if( L_up_cross[0]!=-1 )
                  {
                        if( L_LINK_NUM>=2 )     //�������ı��ش���1ʱ
                        {
                              Site_xy xy1,xy2;
                              xy1=get_inv_img(EXTRACT_ROW,left_edge[EXTRACT_ROW]);
                              xy2=get_inv_img(L_up_cross[0],L_up_cross[1]);
                              if( 2.0*xy1.x-xy1.y<=2.0*xy2.x-xy2.y )     //��������ʱ���ж�Ϊʮ��ֱ�ǹյ�
                              {
                                    L_up_cross[0]=EXTRACT_ROW;                        //�洢�����ʮ���·�ֱ�ǹյ�������
                                    L_up_cross[1]=left_edge[EXTRACT_ROW];             //�洢�����ʮ���·�ֱ�ǹյ�������
                              }
                              else
                              {
                                    L_cross_flag=0;
                                    cross_flag=1;
                              }
                        }
                  }
                  else
                  {
                        if( L_LINK_NUM>=2 )     //�������ı��ش���1ʱ
                        {
                              if( left_edge[EXTRACT_ROW]>=L_LOST_CROSS )     //��������ʱ���ж�Ϊʮ��ֱ�ǹյ�
                              {
                                    L_up_cross[0]=EXTRACT_ROW;                        //�洢�����ʮ���·�ֱ�ǹյ�������
                                    L_up_cross[1]=left_edge[EXTRACT_ROW];             //�洢�����ʮ���·�ֱ�ǹյ�������
                              }
                        }
                  }
            }
      }
}

/***********************************************************************************************************************************/

void L_up_cross_extract()           //�˺���Ϊ������Ϸ�ֱ�ǹյ��жϺ������ҵ���ʮ�ֺ�δ���ߣ�����������ʮ�֣�
{
      if( l_cross_able==1 && L_down_cross[0]!=-1 && L_up_cross[0]==-1 && EXTRACT_ROW>CROSS_UP_ROW && fabsf(inv_distance[EXTRACT_ROW]-inv_distance[L_down_cross[0]])<cross_k_2 )
      {
            if( L_LINK_NUM>=(L_down_cross[0]-EXTRACT_ROW) && left_edge[EXTRACT_ROW]!=-1 )
            {
                  if( left_edge[EXTRACT_ROW]<=L_down_cross[1] )
                  {
                        double xxx=0,yyy=0;
                        Site_xy1 xy2,xy3;
                        Site_xy xy1;
                        
                        xy1=get_inv_img( L_down_cross[0] , L_down_cross[1] );
                        xxx=cross_k_1*fabsf(inv_distance[EXTRACT_ROW]-xy1.x);
                        
                        yyy=xy1.y-L_cross_k*fabsf(inv_distance[EXTRACT_ROW]-xy1.x)+cross_k_add+xxx;
                        xy2=get_invinv_img( inv_distance[EXTRACT_ROW] , yyy );
                        yyy=xy1.y-L_cross_k*fabsf(inv_distance[EXTRACT_ROW]-xy1.x)-cross_k_add_1+xxx;
                        xy3=get_invinv_img( inv_distance[EXTRACT_ROW] , yyy );
                        if( xy3.y<L_down_cross[1]+2 )
                        {
                              xy3.y=L_down_cross[1]+2;
                        }
                        
                        for( EXTRACT_COL=xy3.y ; EXTRACT_COL<=xy2.y ; EXTRACT_COL++ )  //����ʮ�ֹյ�
                        {
                              if( EXTRACT_COL>COL_END-3 )    //����������ͼ��Χʱ����������
                              {
                                    break;
                              }
                              if( img_data[EXTRACT_ROW][EXTRACT_COL]==DOT_B && img_data[EXTRACT_ROW][EXTRACT_COL+1]==DOT_W  && img_data[EXTRACT_ROW][EXTRACT_COL+3]==DOT_W )
                              {
                                    W_num=0;            //����׿����ֵ
                                    for( W_num_row=EXTRACT_ROW-1 ; W_num_row>=EXTRACT_ROW-ROW_W_SUM ; W_num_row-- )     //���������ĺڰ���������������Ϸ�����ʮ���㣬�ж��Ƿ�����
                                    {
                                          if( W_num_row<ROW_START )    //����������ͼ��Χʱ����������
                                          {
                                                break;
                                          }
                                          if( img_data[W_num_row][EXTRACT_COL] == DOT_W )
                                          {
                                                W_num++;
                                          }
                                    }
                                    if( W_num<ROW_W_NUM )             //���׿����ֵû������ֵ�����ж�Ϊ�����          /*����� W_num �ķ�ֵ��Ҫ����*/
                                    {
                                          L_up_cross_error();                          //������Ϸ�ֱ�ǹյ�������
                                          
                                          if( L_get_flag==1 )
                                          {
                                                left_edge[EXTRACT_ROW]=EXTRACT_COL;       //���汾�������������
                                                
                                                L_EDGE_NUM++;                                //����ظ�����1
                                                
                                                L_LINK_NUM=1;                                //��������ظ�����  1
                                                
                                                L_edge_nearest=EXTRACT_COL;                  //�洢���һ������ص�������
                                                
                                                if( L_cross_flag==1 && L_up_cross[0]!=-1 )
                                                {
                                                      L_cross_flag=0;                              //��ʮ�ֱ�־��  0
                                                      
                                                      cross_flag=1;                                //ʮ�ֱ�־��  1
                                                }
                                          }
                                          
                                          break;                                      //�����������������
                                    }
                              }
                        }
                  }
                  else
                  {
                        if( inv_distance[EXTRACT_ROW]>120 && fabsf(inv_distance[EXTRACT_ROW]-inv_distance[L_down_cross[0]])<100 )
                        {
                              L_down_cross[0]=-1;
                              L_down_cross[1]=-1;
                              L_cross_flag=0;                              //��ʮ�ֱ�־��  0
                              l_cross_able=0;
                        }
                  }
            }
      }
}

/***********************************************************************************************************************************/

void L_up_cross_error()             //�˺���Ϊ������Ϸ�ֱ�ǹյ�����������
{
      if( l_cross_able==1 && EXTRACT_COL>L_LOST_CROSS && EXTRACT_ROW>CROSS_UP_ROW && L_up_cross[0]==-1 )
      {
            W_num=0;            //����׿����ֵ
            
            if( L_cross_k!=10 && L_down_cross[0]!=-1 )
            {
                  Site_xy xy1,xy2;
                  double xx,yy,aa;
                  xy1=get_inv_img( EXTRACT_ROW , EXTRACT_COL );
                  xy2=get_inv_img( L_down_cross[0] , L_down_cross[1] );
                  
                  aa=cross_k_1*fabsf(xy1.x-xy2.x);
                  
                  xx=xy2.y-L_cross_k*fabsf(xy1.x-xy2.x)+cross_k_add+aa;
                  yy=xy2.y-L_cross_k*fabsf(xy1.x-xy2.x)-cross_k_add_1+aa;
                  
                  if( xy1.y<xx && xy1.y>yy && fabsf(xy1.x-xy2.x)<cross_k_2 )
                  {
                        W_num=10;
                  }
                  if( fabsf(xy1.x-xy2.x)>cross_k_2 )
                  {
                        L_get_flag=0;                    //����������õ���־��  0
                  }
            }
            else
            {
                  for( W_num_row=EXTRACT_ROW-1 ; W_num_row>=EXTRACT_ROW-5 ; W_num_row-- )     //���������ĺڰ����������������׵㣬�ж��Ƿ�Ϊ���ŵ�
                  {
                        for( W_num_col=EXTRACT_COL+1 ; W_num_col<=EXTRACT_COL+20 ; W_num_col++ )     //���������ĺڰ����������������׵㣬�ж��Ƿ�Ϊ���ŵ�
                        {
                              if( W_num_col>COL_END-3 )   //����ͼ��Χֹͣ
                              {
                                    break;
                              }
                              if( img_data[W_num_row][W_num_col] == DOT_B && img_data[W_num_row][W_num_col+1] == DOT_W && img_data[W_num_row][W_num_col+3] == DOT_W )
                              {
                                    W_num++;
                              }
                        }
                  }
            }
            
            if( W_num>=3 )
            {
                  L_up_cross[0]=EXTRACT_ROW;        //�洢ʮ�ֹյ�������
                  L_up_cross[1]=EXTRACT_COL;        //�洢ʮ�ֹյ�������
                  
                  L_get_flag=1;                     //����������õ���־��  1
            }
      }
}

/***********************************************************************************************************************************/

void R_down_cross_judge()           //�˺���Ϊ�ұ����·�ֱ�ǹյ��жϺ���
{
      if( r_cross_able==1 && R_up_cross[0]==-1 && R_down_cross[0]==-1 && right_edge[EXTRACT_ROW+1]<R_LOST_CROSS && EXTRACT_ROW>CROSS_DOWN_ROW && EXTRACT_ROW<=CROSS_START_ROW && L_barrier_flag==0 && R_barrier_flag==0 )     //��Ҫ�жϵĵ��ڷ�Χ��
      {
            W_num=0;
            for( W_num_row=EXTRACT_ROW+2 ; W_num_row<=EXTRACT_ROW+9 ; W_num_row++ )  //���ǰ8��������
            {
                  if( right_edge[W_num_row]!=-1 )
                  {
                        if( right_edge[W_num_row-1]-right_edge[W_num_row]>0 )
                        {
                              W_num++;
                        }
                  }
                  else
                  {
                        W_num=10;
                        break;
                  }
            }
            
            if( W_num<=1 )   //ǰ�����ұ���ȫ����Ϊ����
            {
                  for( W_num=0 ; W_num<=2 ; W_num++ )
                  {
                        inv_cross[W_num]=-1;
                  }
                  uint8 num=0;        //��¼���ߵ����
                  W_num=0;            //��¼��������
                  if( right_edge[EXTRACT_ROW]!=-1 )
                  {
                        if( EXTRACT_ROW>=15 && right_edge[EXTRACT_ROW]-right_edge[EXTRACT_ROW+1]<CROSS_DOWN_COL )
                        {
                              EXTRACT_COL=right_edge[EXTRACT_ROW];
                              for( W_num_row=EXTRACT_ROW-1 ; W_num_row>=EXTRACT_ROW-6 ; W_num_row-- )   //������������
                              {
                                    if( img_data[W_num_row][EXTRACT_COL-1]==DOT_B )
                                    {
                                          W_num++;
                                          continue;
                                    }
                                    for( W_num_col=EXTRACT_COL ; W_num_col<=COL_END ; W_num_col++ )
                                    {
                                          if( img_data[W_num_row][W_num_col]==DOT_B && img_data[W_num_row][W_num_col-1]==DOT_W )
                                          {
                                                EXTRACT_COL=W_num_col;
                                                break;
                                          }
                                    }
                                    if( W_num_col>COL_END )
                                    {
                                          if( img_data[W_num_row][COL_END-1]==DOT_W && img_data[W_num_row][COL_END]==DOT_W )
                                          {
                                                EXTRACT_COL=COL_END;
                                                num++;
                                          }
                                    }
                                    if( (EXTRACT_ROW-W_num_row)==3 )
                                    {
                                          inv_cross[0]=EXTRACT_COL;
                                    }
                                    if( (EXTRACT_ROW-W_num_row)==4 )
                                    {
                                          inv_cross[1]=EXTRACT_COL;
                                    }
                                    if( (EXTRACT_ROW-W_num_row)==5 )
                                    {
                                          inv_cross[2]=EXTRACT_COL;
                                    }
                              }
                        }
                  }
                  else
                  {
                        if( EXTRACT_ROW>=15 )
                        {
                              EXTRACT_COL=COL_END;
                              for( W_num_row=EXTRACT_ROW-1 ; W_num_row>=EXTRACT_ROW-6 ; W_num_row-- )   //������������
                              {
                                    if( img_data[W_num_row][EXTRACT_COL-1]==DOT_B )
                                    {
                                          W_num++;
                                          continue;
                                    }
                                    for( W_num_col=EXTRACT_COL ; W_num_col<=COL_END ; W_num_col++ )
                                    {
                                          if( img_data[W_num_row][W_num_col]==DOT_B && img_data[W_num_row][W_num_col-1]==DOT_W )
                                          {
                                                EXTRACT_COL=W_num_col;
                                                break;
                                          }
                                    }
                                    if( W_num_col>COL_END )
                                    {
                                          if( img_data[W_num_row][COL_END-1]==DOT_W && img_data[W_num_row][COL_END]==DOT_W )
                                          {
                                                EXTRACT_COL=COL_END;
                                                num++;
                                          }
                                    }
                                    if( (EXTRACT_ROW-W_num_row)==3 )
                                    {
                                          inv_cross[0]=EXTRACT_COL;
                                    }
                                    if( (EXTRACT_ROW-W_num_row)==4 )
                                    {
                                          inv_cross[1]=EXTRACT_COL;
                                    }
                                    if( (EXTRACT_ROW-W_num_row)==5 )
                                    {
                                          inv_cross[2]=EXTRACT_COL;
                                    }
                              }
                        }
                  }
                  if( W_num<=1 )   //���Ѱ׵������㷧ֵ
                  {
                        if( right_edge[EXTRACT_ROW]==-1 || right_edge[EXTRACT_ROW]-right_edge[EXTRACT_ROW+1]>=CROSS_DOWN_COL )       //�����ؾ��ұ仯ʱ���ж�Ϊ��ʮ��ֱ��
                        {
                              R_down_cross[0]=EXTRACT_ROW+1;                           //�洢�ұ���ʮ���·�ֱ�ǹյ�������
                              R_down_cross[1]=right_edge[EXTRACT_ROW+1];                //�洢�ұ���ʮ���·�ֱ�ǹյ�������
                              
                              R_cross_flag=1;      //����������ʱ���ж�Ϊ����ͻ�䣬�ұ���ʮ�ֱ�־��  1
                        }
                        else
                        {
                              if( num>=4 )    //���ѱ��������٣�ֱ���ж�Ϊʮ��
                              {
                                    R_down_cross[0]=EXTRACT_ROW+1;                           //�洢�ұ���ʮ���·�ֱ�ǹյ�������
                                    R_down_cross[1]=right_edge[EXTRACT_ROW+1];                //�洢�ұ���ʮ���·�ֱ�ǹյ�������
                                    
                                    R_cross_flag=1;      //����������ʱ���ж�Ϊ����ͻ�䣬�ұ���ʮ�ֱ�־��  1
                              }
                              else              //���ѱ������㹻����͸��У���Ƕ��ж�ʮ��
                              {
                                    int16 k1=0,k2=0,k3=0;
                                    double x=0.0,y=0.0,x1,y1,k=0.0;
                                    Site_xy xy1,xy2;
                                    int16 row_add;
                                    row_add=EXTRACT_ROW/12;
                                    
                                    xy1=get_inv_img( EXTRACT_ROW+1 , right_edge[EXTRACT_ROW+1] );    //��ȡ�յ���͸������
                                    
                                    W_num_row=4;
                                    
                                    for( W_num=1 ; W_num<=W_num_row ; W_num++ )   //��ȡ�յ����µ����б��
                                    {
                                          W_num_col=EXTRACT_ROW+W_num+row_add;
                                          if( W_num_col>ROW_END )
                                          {
                                                break;
                                          }
                                          if( right_edge[W_num_col]!=-1 )
                                          {
                                                xy2=get_inv_img( W_num_col , right_edge[W_num_col] );
                                                x1=xy2.x-xy1.x;
                                                y1=xy2.y-xy1.y;
                                                x=x+x1*y1;
                                                y=y+x1*x1;
                                          }
                                    }
                                    if( x!=0 )
                                    {
                                          k=(-1)*x/y;    //�õ��յ����µ����б��
                                    }
                                    else
                                    {
                                          k==0;
                                    }
                                    if( k>=0 )
                                    {
                                          for( W_num=0 ; W_num<=29 ; W_num++ )
                                          {
                                                if( k<=tan_table[W_num] )
                                                {
                                                      k1=180-3*W_num;
                                                      break;
                                                }
                                          }
                                          if( W_num==30 )
                                          {
                                                k1=90;
                                          }
                                    }
                                    else
                                    {
                                          k=fabsf(k);
                                          for( W_num=0 ; W_num<=29 ; W_num++ )
                                          {
                                                if( k<=tan_table[W_num] )
                                                {
                                                      k1=180+3*W_num;
                                                      break;
                                                }
                                          }
                                          if( W_num==30 )
                                          {
                                                k1=270;
                                          }
                                    }
                                    
                                    x=0.0;
                                    y=0.0;
                                    for( W_num=0 ; W_num<=2 ; W_num++ )   //��ȡ�յ����ϵ����б��
                                    {
                                          if( inv_cross[W_num]!=-1 )
                                          {
                                                xy2=get_inv_img( EXTRACT_ROW-W_num-2 , inv_cross[W_num] );
                                                x1=xy2.x-xy1.x;
                                                y1=xy2.y-xy1.y;
                                                x=x+x1*y1;
                                                y=y+x1*x1;
                                          }
                                    }
                                    if( x!=0 )
                                    {
                                          k=(-1)*x/y;    //�õ��յ����ϵ����б��
                                    }
                                    else
                                    {
                                          k==0;
                                    }
                                    if( k>=0 )
                                    {
                                          for( W_num=0 ; W_num<=29 ; W_num++ )
                                          {
                                                if( k<=tan_table[W_num] )
                                                {
                                                      k2=-3*W_num;
                                                      break;
                                                }
                                          }
                                          if( W_num==30 )
                                          {
                                                k2=-90;
                                          }
                                    }
                                    else
                                    {
                                          k=fabsf(k);
                                          for( W_num=0 ; W_num<=29 ; W_num++ )
                                          {
                                                if( k<=tan_table[W_num] )
                                                {
                                                      k2=3*W_num;
                                                      break;
                                                }
                                          }
                                          if( W_num==30 )
                                          {
                                                k2=90;
                                          }
                                    }
                                    
                                    k3=abs(k1-k2);
                                    angle_aaa[1]=k3;
                                    if( k3<=117 )  //ͨ���Ƕ�У���ж�Ϊʮ��
                                    {
                                          R_down_cross[0]=EXTRACT_ROW+1;                           //�洢�ұ���ʮ���·�ֱ�ǹյ�������
                                          R_down_cross[1]=right_edge[EXTRACT_ROW+1];                //�洢�ұ���ʮ���·�ֱ�ǹյ�������
                                          
                                          R_cross_flag=1;      //����������ʱ���ж�Ϊ����ͻ�䣬�ұ���ʮ�ֱ�־��  1
                                    }
                              }
                        }
                        
                        if( R_down_cross[0]!=-1 )
                        {
                              double x=0.0,y=0.0,x1,y1,k=0.0,a;
                              Site_xy xy1,xy2;
                              Site_xy1 xy3;
                              
                              xy1=get_inv_img( R_down_cross[0] , R_down_cross[1] );    //��ȡ�յ���͸������
                              
                              a=xy1.x-50;
                              xy3=get_invinv_img( a , 0 );
                              if( xy3.x-R_down_cross[0]>15 )
                              {
                                    W_num_row=15;
                              }
                              else
                              {
                                    if( xy3.x-R_down_cross[0]<3 )
                                    {
                                          W_num_row=3;
                                    }
                                    else
                                    {
                                          W_num_row=abs(xy3.x-R_down_cross[0]);
                                    }
                              }
                              
                              for( W_num=1 ; W_num<=W_num_row ; W_num++ )   //��ȡ�յ����µ����б��
                              {
                                    W_num_col=EXTRACT_ROW+W_num+1;
                                    if( W_num_col>ROW_END )
                                    {
                                          break;
                                    }
                                    if( right_edge[W_num_col]!=-1 )
                                    {
                                          xy2=get_inv_img( W_num_col , right_edge[W_num_col] );
                                          x1=xy2.x-xy1.x;
                                          y1=xy2.y-xy1.y;
                                          x=x+x1*y1;
                                          y=y+x1*x1;
                                    }
                                    else
                                    {
                                          break;
                                    }
                              }
                              if( x!=0 )
                              {
                                    k=(-1)*x/y;    //�õ��յ����µ����б��
                              }
                              else
                              {
                                    k==0;
                              }
                              
                              R_cross_k=k;        //ȡ�������б��
                        }
                  }
            }
      }
}

/***********************************************************************************************************************************/

void R_up_cross_judge()             //�˺���Ϊ�ұ����Ϸ�ֱ�ǹյ��жϺ���
{
      if( r_cross_able==1 && R_cross_flag==1 && EXTRACT_ROW<=CROSS_START_ROW && EXTRACT_ROW>CROSS_UP_ROW )         //���ұ���ʮ�ֱ�Ϊ1ʱ
      {
            if( R_down_cross[0]!=-1 )   //��ȡ��ʮ�ֹյ�
            {
                  if( fabsf(inv_distance[EXTRACT_ROW]-inv_distance[R_down_cross[0]])<cross_k_2 )
                  {
                        if( R_LINK_NUM>=2 && R_LINK_NUM<(R_down_cross[0]-EXTRACT_ROW-1) )     //�������ı��ش���3ʱ
                        {
                              if( R_up_cross[0]!=-1 )
                              {
                                    Site_xy xy1,xy2;
                                    xy1=get_inv_img(EXTRACT_ROW,right_edge[EXTRACT_ROW]);
                                    xy2=get_inv_img(R_up_cross[0],R_up_cross[1]);
                                    if( 2.0*xy1.x+xy1.y<=2.0*xy2.x+xy2.y )     //��������ʱ���ж�Ϊʮ��ֱ�ǹյ�
                                    {
                                          double xx,aa;
                                          xy2=get_inv_img( R_down_cross[0] , R_down_cross[1] );
                                          
                                          if( fabsf(xy1.x-xy2.x)>cross_k_2 )
                                          {
                                                aa=cross_k_1*cross_k_2;
                                          }
                                          else
                                          {
                                                aa=cross_k_1*fabsf(xy1.x-xy2.x);
                                          }
                                          xx=xy2.y-R_cross_k*fabsf(xy1.x-xy2.x)-cross_k_add-aa;
                                          
                                          if( xy1.y>=xx )
                                          {
                                                R_up_cross[0]=EXTRACT_ROW;                        //�洢�ұ���ʮ���·�ֱ�ǹյ�������
                                                R_up_cross[1]=right_edge[EXTRACT_ROW];            //�洢�ұ���ʮ���·�ֱ�ǹյ�������
                                          }
                                    }
                              }
                              else
                              {
                                    double xx,aa;
                                    Site_xy xy1,xy2;
                                    xy1=get_inv_img(EXTRACT_ROW,right_edge[EXTRACT_ROW]);
                                    xy2=get_inv_img( R_down_cross[0] , R_down_cross[1] );
                                    
                                    if( fabsf(xy1.x-xy2.x)>cross_k_2 )
                                    {
                                          aa=cross_k_1*cross_k_2;
                                    }
                                    else
                                    {
                                          aa=cross_k_1*fabsf(xy1.x-xy2.x);
                                    }
                                    xx=xy2.y-R_cross_k*fabsf(xy1.x-xy2.x)-cross_k_add-aa;
                                    
                                    if( xy1.y>=xx )
                                    {
                                          R_up_cross[0]=EXTRACT_ROW;                        //�洢�ұ���ʮ���·�ֱ�ǹյ�������
                                          R_up_cross[1]=right_edge[EXTRACT_ROW];            //�洢�ұ���ʮ���·�ֱ�ǹյ�������
                                    }
                              }
                        }
                  }
                  else
                  {
                        R_cross_flag=0;
                        cross_flag=1;
                  }
            }
            else   //δ��ȡ��ʮ�ֹյ�
            {
                  if( R_up_cross[0]!=-1 )
                  {
                        if( R_LINK_NUM>=2 )     //�������ı��ش���1ʱ
                        {
                              Site_xy xy1,xy2;
                              xy1=get_inv_img(EXTRACT_ROW,right_edge[EXTRACT_ROW]);
                              xy2=get_inv_img(R_up_cross[0],R_up_cross[1]);
                              if( 2.0*xy1.x+xy1.y<=2.0*xy2.x+xy2.y )     //��������ʱ���ж�Ϊʮ��ֱ�ǹյ�
                              {
                                    R_up_cross[0]=EXTRACT_ROW;                        //�洢�ұ���ʮ���·�ֱ�ǹյ�������
                                    R_up_cross[1]=right_edge[EXTRACT_ROW];            //�洢�ұ���ʮ���·�ֱ�ǹյ�������
                              }
                              else
                              {
                                    R_cross_flag=0;
                                    cross_flag=1;
                              }
                        }
                  }
                  else
                  {
                        if( R_LINK_NUM>=2 )     //�������ı��ش���1ʱ
                        {
                              if( right_edge[EXTRACT_ROW]<=R_LOST_CROSS )     //��������ʱ���ж�Ϊʮ��ֱ�ǹյ�
                              {
                                    R_up_cross[0]=EXTRACT_ROW;                        //�洢�ұ���ʮ���·�ֱ�ǹյ�������
                                    R_up_cross[1]=right_edge[EXTRACT_ROW];            //�洢�ұ���ʮ���·�ֱ�ǹյ�������
                              }
                        }
                  }
            }
      }
}

/***********************************************************************************************************************************/

void R_up_cross_extract()           //�˺���Ϊ�ұ����Ϸ�ֱ�ǹյ��жϺ������ҵ���ʮ�ֺ�δ���ߣ�����������ʮ�֣�
{
      if( r_cross_able==1 && R_down_cross[0]!=-1 && R_up_cross[0]==-1 && EXTRACT_ROW>CROSS_UP_ROW && fabsf(inv_distance[EXTRACT_ROW]-inv_distance[R_down_cross[0]])<cross_k_2 )
      {
            if( R_LINK_NUM>=(R_down_cross[0]-EXTRACT_ROW) && right_edge[EXTRACT_ROW]!=-1 )
            {
                  if( right_edge[EXTRACT_ROW]>=R_down_cross[1] )
                  {
                        double xxx=0,yyy=0;
                        Site_xy1 xy2,xy3;
                        Site_xy xy1;
                        
                        xy1=get_inv_img( R_down_cross[0] , R_down_cross[1] );
                        xxx=cross_k_1*fabsf(inv_distance[EXTRACT_ROW]-xy1.x);
                        
                        yyy=xy1.y-R_cross_k*fabsf(inv_distance[EXTRACT_ROW]-xy1.x)-cross_k_add-xxx;
                        xy2=get_invinv_img( inv_distance[EXTRACT_ROW] , yyy );
                        yyy=xy1.y-R_cross_k*fabsf(inv_distance[EXTRACT_ROW]-xy1.x)+cross_k_add_1-xxx;
                        xy3=get_invinv_img( inv_distance[EXTRACT_ROW] , yyy );
                        if( xy3.y>R_down_cross[1]-2 )
                        {
                              xy3.y=R_down_cross[1]-2;
                        }
                        
                        for( EXTRACT_COL=xy3.y ; EXTRACT_COL>=xy2.y ; EXTRACT_COL-- )  //����ʮ�ֹյ�
                        {
                              if( EXTRACT_COL<COL_START+3 )    //����������ͼ��Χʱ����������
                              {
                                    break;
                              }
                              if( img_data[EXTRACT_ROW][EXTRACT_COL]==DOT_B && img_data[EXTRACT_ROW][EXTRACT_COL-1]==DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL-3]==DOT_W )
                              {
                                    W_num=0;            //����׿����ֵ
                                    for( W_num_row=EXTRACT_ROW-1 ; W_num_row>=EXTRACT_ROW-ROW_W_SUM ; W_num_row-- )     //���������ĺڰ���������������Ϸ�����ʮ���㣬�ж��Ƿ�����
                                    {
                                          if( W_num_row<ROW_START )    //����������ͼ��Χʱ����������
                                          {
                                                break;
                                          }
                                          if( img_data[W_num_row][EXTRACT_COL] == DOT_W )
                                          {
                                                W_num++;
                                          }
                                    }
                                    if( W_num<ROW_W_NUM )             //���׿����ֵû������ֵ�����ж�Ϊ�����          /*����� W_num �ķ�ֵ��Ҫ����*/
                                    {
                                          R_up_cross_error();                          //�ұ����Ϸ�ֱ�ǹյ�������
                                          
                                          if( R_get_flag==1 )
                                          {
                                                right_edge[EXTRACT_ROW]=EXTRACT_COL;         //���汾���ұ���������
                                                
                                                R_EDGE_NUM++;                                //�ұ��ظ�����1
                                                
                                                R_LINK_NUM=1;                                //�����ұ��ظ�����  1
                                                
                                                R_edge_nearest=EXTRACT_COL;                  //�洢���һ���ұ��ص�������
                                                
                                                if( R_cross_flag==1 && R_up_cross[0]!=-1 )
                                                {
                                                      R_cross_flag=0;                              //��ʮ�ֱ�־��  0
                                                      
                                                      cross_flag=1;                                //ʮ�ֱ�־��  1
                                                }
                                          }
                                          
                                          break;                                      //�����ұ�����������
                                    }
                              }
                        }
                  }
                  else
                  {
                        if( inv_distance[EXTRACT_ROW]>120 && fabsf(inv_distance[EXTRACT_ROW]-inv_distance[R_down_cross[0]])<100 )
                        {
                              R_down_cross[0]=-1;
                              R_down_cross[1]=-1;
                              R_cross_flag=0;                              //��ʮ�ֱ�־��  0
                              r_cross_able=0;
                        }
                  }
            }
      }
}

/***********************************************************************************************************************************/

void R_up_cross_error()             //�˺���Ϊ�ұ����Ϸ�ֱ�ǹյ�����������
{
      if( r_cross_able==1 && EXTRACT_COL<R_LOST_CROSS && EXTRACT_ROW>CROSS_UP_ROW && R_up_cross[0]==-1 )
      {
            W_num=0;            //����׿����ֵ
            
            if( R_cross_k!=10 && R_down_cross[0]!=-1 )
            {
                  Site_xy xy1,xy2;
                  double xx,yy,aa;
                  xy1=get_inv_img( EXTRACT_ROW , EXTRACT_COL );
                  xy2=get_inv_img( R_down_cross[0] , R_down_cross[1] );
                  
                  aa=cross_k_1*fabsf(xy1.x-xy2.x);
                  
                  xx=xy2.y-R_cross_k*fabsf(xy1.x-xy2.x)-cross_k_add-aa;
                  yy=xy2.y-R_cross_k*fabsf(xy1.x-xy2.x)+cross_k_add_1-aa;
                  
                  if( xy1.y>xx && xy1.y<yy && fabsf(xy1.x-xy2.x)<cross_k_2 )
                  {
                        W_num=10;
                  }
                  if( fabsf(xy1.x-xy2.x)>cross_k_2 )
                  {
                        R_get_flag=0;                    //�ұ��������õ���־��  0
                  }
            }
            else
            {
                  for( W_num_row=EXTRACT_ROW-1 ; W_num_row>=EXTRACT_ROW-5 ; W_num_row-- )     //���������ĺڰ����������������׵㣬�ж��Ƿ�Ϊ���ŵ�
                  {
                        for( W_num_col=EXTRACT_COL-1 ; W_num_col>=EXTRACT_COL-20 ; W_num_col-- )     //���������ĺڰ����������������׵㣬�ж��Ƿ�Ϊ���ŵ�
                        {
                              if( W_num_col<COL_START+3 )   //����ͼ��Χֹͣ
                              {
                                    break;
                              }
                              if( img_data[W_num_row][W_num_col] == DOT_B && img_data[W_num_row][W_num_col-1] == DOT_W && img_data[W_num_row][W_num_col-3] == DOT_W )
                              {
                                    W_num++;
                              }
                        }
                  }
            }
            
            if( W_num>=3 )
            {
                  R_up_cross[0]=EXTRACT_ROW;        //�洢ʮ�ֹյ�������
                  R_up_cross[1]=EXTRACT_COL;        //�洢ʮ�ֹյ�������
                  
                  R_get_flag=1;                     //�ұ��������õ���־��  1
            }
      }
}

/***********************************************************************************************************************************/

void barrier_down_extract()         //�˺���Ϊ�ϰ����±����м�⺯��
{
      if( L_get_flag==1 && R_get_flag==1 && L_barrier_down_row==-1 && R_barrier_down_row==-1 && LOOP_TEMP==0 && EXTRACT_ROW>=BAR_UP_ROW && EXTRACT_ROW<=50 && end_bar_able==1 )
      {
            if( L_LINK_NUM>=3 && R_trend_in==1 )  //�����ͻ��
            {
                  if( EXTRACT_ROW<=20 )
                  {
                        if( (left_edge[EXTRACT_ROW]-left_edge[EXTRACT_ROW+1])>0.4*bar_range_col[EXTRACT_ROW+1] )
                        {
                              L_barrier_down_row=EXTRACT_ROW;           //����������ϰ����±���
                              
                              if( barrier_able==1 )
                              {
                                    L_barrier_flag=1;                         //������ϰ���־��  1
                              }
                        }
                  }
                  else
                  {
                        if( (left_edge[EXTRACT_ROW]-left_edge[EXTRACT_ROW+2])>0.4*bar_range_col[EXTRACT_ROW+2] )
                        {
                              L_barrier_down_row=EXTRACT_ROW;           //����������ϰ����±���
                              
                              if( barrier_able==1 )
                              {
                                    L_barrier_flag=1;                         //������ϰ���־��  1
                              }
                        }
                  }
            }
            
            if( R_LINK_NUM>=3 && L_trend_in==1 )  //�ұ���ͻ��
            {
                  if( EXTRACT_ROW<=20 )
                  {
                        if( (right_edge[EXTRACT_ROW+1]-right_edge[EXTRACT_ROW])>0.4*bar_range_col[EXTRACT_ROW+1] )
                        {
                              R_barrier_down_row=EXTRACT_ROW;              //�����ұ����ϰ����±���
                              
                              if( barrier_able==1 )
                              {
                                    R_barrier_flag=1;                            //�ұ����ϰ���־��  1
                              }
                        }
                  }
                  else
                  {
                        if( (right_edge[EXTRACT_ROW+2]-right_edge[EXTRACT_ROW])>0.4*bar_range_col[EXTRACT_ROW+2] )
                        {
                              R_barrier_down_row=EXTRACT_ROW;              //�����ұ����ϰ����±���
                              
                              if( barrier_able==1 )
                              {
                                    R_barrier_flag=1;                            //�ұ����ϰ���־��  1
                              }
                        }
                  }
            }
            
            if( L_barrier_down_row==-1 && R_barrier_down_row==-1 )
            {
                  if( abs(right_edge[EXTRACT_ROW]-left_edge[EXTRACT_ROW])<=(1.5*bar_range_col[EXTRACT_ROW]) && EXTRACT_ROW>30 )    //��������ȹ�С���ж�Ϊ�ϰ�
                  {
                        if( up_flag==0 )
                        {
                              if( left_edge[EXTRACT_ROW]-left_edge[EXTRACT_ROW+1]>0.4*bar_range_col[EXTRACT_ROW] && L_LINK_NUM>=5 )  //�������λ��ͻ�䣬�ж�������ϰ���
                              {
                                    if( EXTRACT_ROW>=ROW_END-10 )
                                    {
                                          L_barrier_down_row=EXTRACT_ROW;     //����������ϰ����±���
                                          
                                          if( barrier_able==1 )
                                          {
                                                L_barrier_flag=1;                   //������ϰ���־��  1
                                          }
                                    }
                                    else
                                    {
                                          if( R_LINK_NUM>=10 )
                                          {
                                                L_barrier_down_row=EXTRACT_ROW;     //����������ϰ����±���
                                                
                                                if( barrier_able==1 )
                                                {
                                                      L_barrier_flag=1;                   //������ϰ���־��  1
                                                }
                                          }
                                    }
                              }
                              else
                              {
                                    if( right_edge[EXTRACT_ROW+1]-right_edge[EXTRACT_ROW]>0.4*bar_range_col[EXTRACT_ROW] && R_LINK_NUM>=5 )  //���ұ���λ��ͻ�䣬�ж��ұ����ϰ���
                                    {
                                          if( EXTRACT_ROW>=ROW_END-10 )
                                          {
                                                R_barrier_down_row=EXTRACT_ROW;     //�����ұ����ϰ����±���
                                                
                                                if( barrier_able==1 )
                                                {
                                                      R_barrier_flag=1;                   //�ұ����ϰ���־��  1
                                                }
                                          }
                                          else
                                          {
                                                if( L_LINK_NUM>=10 )
                                                {
                                                      R_barrier_down_row=EXTRACT_ROW;     //�����ұ����ϰ����±���
                                                      
                                                      if( barrier_able==1 )
                                                      {
                                                            R_barrier_flag=1;                   //�ұ����ϰ���־��  1
                                                      }
                                                }
                                          }
                                    }
                                    else
                                    {
                                          if( EXTRACT_ROW>bar_search_end )     //��δ�жϳ�ͻ�䣬��ֵ��־λ
                                          {
                                                L_barrier_down_row=EXTRACT_ROW;
                                                R_barrier_down_row=EXTRACT_ROW;
                                                if( barrier_able==1 )
                                                {
                                                      L_barrier_flag=1;
                                                      R_barrier_flag=1;
                                                }
                                          }
                                    }
                              }
                        }
                  }
                  else    //��������������������ϰ�
                  {
                        if( abs(right_edge[EXTRACT_ROW]-left_edge[EXTRACT_ROW])<=(2.5*bar_range_col[EXTRACT_ROW]) )
                        {
                              int16 l_edge=-1,r_edge=-1;
                              for( EXTRACT_COL=L_edge_nearest+1 ; EXTRACT_COL<=R_edge_nearest-3 ; EXTRACT_COL++ )
                              {
                                    if( img_data[EXTRACT_ROW][EXTRACT_COL]==DOT_B && img_data[EXTRACT_ROW][EXTRACT_COL+1]==DOT_B && img_data[EXTRACT_ROW][EXTRACT_COL+2]==DOT_B )
                                    {
                                          l_edge=EXTRACT_COL;
                                          break;
                                    }
                              }
                              if( l_edge!=-1 )
                              {
                                    for( EXTRACT_COL=R_edge_nearest-1 ; EXTRACT_COL>=l_edge+3 ; EXTRACT_COL-- )
                                    {
                                          if( img_data[EXTRACT_ROW][EXTRACT_COL]==DOT_B && img_data[EXTRACT_ROW][EXTRACT_COL-1]==DOT_B && img_data[EXTRACT_ROW][EXTRACT_COL-2]==DOT_B )
                                          {
                                                r_edge=EXTRACT_COL;
                                                break;
                                          }
                                    }
                                    if( r_edge!=-1 )   //�����Ҷ�����������
                                    {
                                          if( abs(r_edge-l_edge)>0.35*bar_range_col[EXTRACT_ROW] )
                                          {
                                                W_num=0;
                                                W_num_col=(r_edge+l_edge)/2;
                                                for( W_num_row=EXTRACT_ROW-1 ; W_num_row>=EXTRACT_ROW-5 ; W_num_row-- )
                                                {
                                                      if( W_num_row<ROW_START )
                                                      {
                                                            break;
                                                      }
                                                      if( img_data[W_num_row][W_num_col]==DOT_W )
                                                      {
                                                            W_num++;
                                                      }
                                                }
                                                W_num_row=0;
                                                for( W_num_col=l_edge ; W_num_col<=r_edge ; W_num_col++ )
                                                {
                                                      if( img_data[EXTRACT_ROW][W_num_col]==DOT_B )
                                                      {
                                                            W_num_row++;
                                                      }
                                                }
                                                if( W_num<=1 && W_num_row>=(r_edge-l_edge) )    //�ж����ϰ���
                                                {
                                                      if( (l_edge+r_edge)<(L_edge_nearest+R_edge_nearest) )  //�ж�Ϊ���ϰ���
                                                      {
                                                            if( EXTRACT_ROW>=30 )
                                                            {
                                                                  if( abs(right_edge[EXTRACT_ROW]-r_edge)>bar_range_col[EXTRACT_ROW] )
                                                                  {
                                                                        L_barrier_down_row=EXTRACT_ROW;           //����������ϰ����±���
                                                                        
                                                                        if( barrier_able==1 )
                                                                        {
                                                                              left_edge[EXTRACT_ROW]=r_edge;       //���汾�������������
                                                                              
                                                                              L_edge_nearest=r_edge;               //�洢���һ������ص�������
                                                                              
                                                                              L_barrier_flag=1;                         //������ϰ���־��  1
                                                                        }
                                                                  }
                                                                  else
                                                                  {
                                                                        if( car_extract_row==-1 )
                                                                        {
                                                                              car_extract_row=EXTRACT_ROW;
                                                                        }
                                                                  }
                                                            }
                                                            else
                                                            {
                                                                  if( L_LINK_NUM>=5 && R_LINK_NUM>=5 )
                                                                  {
                                                                        if( abs(right_edge[EXTRACT_ROW]-r_edge)>bar_range_col[EXTRACT_ROW] )
                                                                        {
                                                                              L_barrier_down_row=EXTRACT_ROW;           //����������ϰ����±���
                                                                              
                                                                              if( barrier_able==1 )
                                                                              {
                                                                                    left_edge[EXTRACT_ROW]=r_edge;       //���汾�������������
                                                                                    
                                                                                    L_edge_nearest=r_edge;               //�洢���һ������ص�������
                                                                                    
                                                                                    L_barrier_flag=1;                         //������ϰ���־��  1
                                                                              }
                                                                        }
                                                                        else
                                                                        {
                                                                              if( car_extract_row==-1 )
                                                                              {
                                                                                    car_extract_row=EXTRACT_ROW;
                                                                              }
                                                                        }
                                                                  }
                                                            }
                                                      }
                                                      else  //�ж�Ϊ���ϰ���
                                                      {
                                                            if( EXTRACT_ROW>=30 )
                                                            {
                                                                  if( abs(l_edge-left_edge[EXTRACT_ROW])>bar_range_col[EXTRACT_ROW] )
                                                                  {
                                                                        R_barrier_down_row=EXTRACT_ROW;              //�����ұ����ϰ����±���
                                                                        
                                                                        if( barrier_able==1 )
                                                                        {
                                                                              right_edge[EXTRACT_ROW]=l_edge;         //���汾���ұ���������
                                                                              
                                                                              R_edge_nearest=l_edge;                  //�洢���һ���ұ��ص�������
                                                                              
                                                                              R_barrier_flag=1;                            //�ұ����ϰ���־��  1
                                                                        }
                                                                  }
                                                                  else
                                                                  {
                                                                        if( car_extract_row==-1 )
                                                                        {
                                                                              car_extract_row=EXTRACT_ROW;
                                                                        }
                                                                  }
                                                            }
                                                            else
                                                            {
                                                                  if( L_LINK_NUM>=5 && R_LINK_NUM>=5 )
                                                                  {
                                                                        if( abs(l_edge-left_edge[EXTRACT_ROW])>bar_range_col[EXTRACT_ROW] )
                                                                        {
                                                                              R_barrier_down_row=EXTRACT_ROW;              //�����ұ����ϰ����±���
                                                                              
                                                                              if( barrier_able==1 )
                                                                              {
                                                                                    right_edge[EXTRACT_ROW]=l_edge;         //���汾���ұ���������
                                                                                    
                                                                                    R_edge_nearest=l_edge;                  //�洢���һ���ұ��ص�������
                                                                                    
                                                                                    R_barrier_flag=1;                            //�ұ����ϰ���־��  1
                                                                              }
                                                                        }
                                                                        else
                                                                        {
                                                                              if( car_extract_row==-1 )
                                                                              {
                                                                                    car_extract_row=EXTRACT_ROW;
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
                  }
            }
      }
}

/***********************************************************************************************************************************/

void barrier_up_extract()           //�˺���Ϊ�ϰ����ϱ����м�⺯��
{
      if( L_barrier_flag==1 && L_barrier_up_row==-1 )
      {
            if( left_edge[EXTRACT_ROW]!=-1 && left_edge[EXTRACT_ROW+1]!=-1 )
            {
                  W_num_col=left_edge[EXTRACT_ROW];
                  for( W_num_row=EXTRACT_ROW-1 ; W_num_row>=EXTRACT_ROW-3 ; W_num_row-- )
                  {
                        if( W_num_row<ROW_START )
                        {
                              break;
                        }
                        if( img_data[W_num_row][W_num_col]==DOT_B )
                        {
                              continue;
                        }
                        for( EXTRACT_COL=W_num_col ; EXTRACT_COL>=COL_START+3 ; EXTRACT_COL-- )
                        {
                              if( EXTRACT_COL<COL_START+3 )    //����������ͼ��Χʱ����������
                              {
                                    break;
                              }
                              if( img_data[W_num_row][EXTRACT_COL]==DOT_W && img_data[W_num_row][EXTRACT_COL-1]==DOT_B && img_data[W_num_row][EXTRACT_COL-3]==DOT_B )
                              {
                                    W_num_col=EXTRACT_COL;
                                    break;
                              }
                        }
                  }
                  if( left_edge[EXTRACT_ROW+1]-W_num_col>=bar_range_col[EXTRACT_ROW]/3 )
                  {
                        L_barrier_up_row=EXTRACT_ROW+1;              //����������ϰ����ϱ���
                        R_barrier_flag=0;
                  }
            }
            else
            {
                  if( left_edge[EXTRACT_ROW]==-1 && left_edge[EXTRACT_ROW+1]!=-1 && L_search_end==0 )
                  {
                        if( left_edge[EXTRACT_ROW+1]>=COL_START+bar_range_col[EXTRACT_ROW+1]/3 )
                        {
                              L_barrier_up_row=EXTRACT_ROW+1;              //����������ϰ����ϱ���
                              R_barrier_flag=0;
                        }
                  }
            }
      }
      if( R_barrier_flag==1 && R_barrier_up_row==-1 )
      {
            if( right_edge[EXTRACT_ROW]!=-1 && right_edge[EXTRACT_ROW+1]!=-1 )
            {
                  W_num_col=right_edge[EXTRACT_ROW];
                  for( W_num_row=EXTRACT_ROW-1 ; W_num_row>=EXTRACT_ROW-3 ; W_num_row-- )
                  {
                        if( W_num_row<ROW_START )
                        {
                              break;
                        }
                        if( img_data[W_num_row][W_num_col]==DOT_B )
                        {
                              continue;
                        }
                        for( EXTRACT_COL=W_num_col ; EXTRACT_COL<=COL_END-3 ; EXTRACT_COL++ )
                        {
                              if( img_data[W_num_row][EXTRACT_COL]==DOT_W && img_data[W_num_row][EXTRACT_COL+1]==DOT_B && img_data[W_num_row][EXTRACT_COL+3]==DOT_B )
                              {
                                    W_num_col=EXTRACT_COL;
                                    break;
                              }
                        }
                  }
                  if( W_num_col-right_edge[EXTRACT_ROW+1]>=bar_range_col[EXTRACT_ROW]/3 )
                  {
                        R_barrier_up_row=EXTRACT_ROW+1;              //�����ұ����ϰ����ϱ���
                        L_barrier_flag=0;
                  }
            }
            else
            {
                  if( right_edge[EXTRACT_ROW]==-1 && right_edge[EXTRACT_ROW+1]!=-1 && R_search_end==0 )
                  {
                        if( right_edge[EXTRACT_ROW+1]<=COL_END-bar_range_col[EXTRACT_ROW+1]/3 )
                        {
                              R_barrier_up_row=EXTRACT_ROW+1;              //�����ұ����ϰ����ϱ���
                              L_barrier_flag=0;
                        }
                  }
            }
      }
}

/***********************************************************************************************************************************/

void end_line_extract()             //�˺���Ϊ�յ����м�⺯��
{
      if( LOOP_TEMP==0 && L_trend_in==1 && R_trend_in==1 && L_LINK_NUM>=5 && R_LINK_NUM>=5 && EXTRACT_ROW>=end_line_end && END_LINE_FLAG==0 && end_line_able==1 )
      {
            if( left_edge[EXTRACT_ROW]!=-1 && right_edge[EXTRACT_ROW]!=-1 && abs(right_edge[EXTRACT_ROW]-left_edge[EXTRACT_ROW])<2.5*bar_range_col[EXTRACT_ROW] )
            {
                  if( EXTRACT_ROW<30 )
                  {
                        int16 l_edge,r_edge;
                        W_num=0;
                        for( W_num_col=left_edge[EXTRACT_ROW]+2 ; W_num_col<=right_edge[EXTRACT_ROW]-3 ; W_num_col++ )
                        {
                              if( img_data[EXTRACT_ROW][W_num_col]<=img_threshold+end_line_gray_add && img_data[EXTRACT_ROW][W_num_col+1]>img_threshold+end_line_gray_add )
                              {
                                    W_num++;
                                    if( W_num==1 )
                                    {
                                          l_edge=W_num_col;
                                    }
                                    else
                                    {
                                          r_edge=W_num_col;
                                    }
                              }
                        }
                        if( W_num>=5 && abs(r_edge-l_edge)>1.5*bar_range_col[EXTRACT_ROW] )
                        {
                              END_LINE_FLAG=1;
                              
                              END_LINE_TEMP=1;
                              
                              END_LINE_TEMP_1=0;
                              
                              END_LINE_TEMP_2=0;
                              
                              end_line_row=EXTRACT_ROW;
                              
                              end_line_val=abs(speedout_val)+25*inv_distance[end_line_row]+1000;
                        }
                  }
                  else
                  {
                        int16 l_edge,r_edge;
                        W_num=0;
                        for( W_num_col=left_edge[EXTRACT_ROW]+2 ; W_num_col<=right_edge[EXTRACT_ROW]-5 ; W_num_col++ )
                        {
                              if( img_data[EXTRACT_ROW][W_num_col]==DOT_B && img_data[EXTRACT_ROW][W_num_col+1]==DOT_B && img_data[EXTRACT_ROW][W_num_col+2]==DOT_W && img_data[EXTRACT_ROW][W_num_col+3]==DOT_W )
                              {
                                    W_num++;
                                    if( W_num==1 )
                                    {
                                          l_edge=W_num_col;
                                    }
                                    else
                                    {
                                          r_edge=W_num_col;
                                    }
                              }
                        }
                        if( W_num>=5 && abs(r_edge-l_edge)>1.5*bar_range_col[EXTRACT_ROW] )
                        {
                              END_LINE_FLAG=1;
                              
                              END_LINE_TEMP=1;
                              
                              END_LINE_TEMP_1=0;
                              
                              END_LINE_TEMP_2=0;
                              
                              end_line_row=EXTRACT_ROW;
                              
                              end_line_val=abs(speedout_val)+25*inv_distance[end_line_row]+1000;
                        }
                  }
            }
      }
}

/***********************************************************************************************************************************/

void cross_edge_add()               //�˺���Ϊʮ�ֱ��ز��亯��������ʮ�ִ�����أ�
{
      if( L_cross_flag==1 || R_cross_flag==1 || cross_flag==1 )   //������ʮ��
      {
            if( L_up_cross[0]==-1 && R_up_cross[0]==-1 )   //�������ʮ�ֹյ�
            {
                  if( L_down_cross[0]!=-1 )
                  {
                        if( R_down_cross[0]==-1 )
                        {
                              Site_xy xy;
                              Site_xy1 xy1;
                              xy=get_inv_img( L_down_cross[0] , L_down_cross[1] );
                              if( xy.y<40 )
                              {
                                    int16 r_start,r_end;
                                    xy1=get_invinv_img( xy.x-60 , 0 );
                                    r_start=xy1.x;
                                    if( r_start>ROW_END )
                                    {
                                          r_start=ROW_END;
                                    }
                                    xy1=get_invinv_img( xy.x+120 , 0 );
                                    r_end=xy1.x;
                                    if( L_TURN==1 && R_end_row!=-1 )
                                    {
                                          if( R_end_row>r_end )
                                          {
                                                r_end=R_end_row;
                                          }
                                    }
                                    else
                                    {
                                          if( r_end<ROW_START )
                                          {
                                                r_end=ROW_START;
                                          }
                                    }
                                    
                                    W_num=0;
                                    for( W_num_row=r_start-1 ; W_num_row>=r_end ; W_num_row-- )
                                    {
                                          if( right_edge[W_num_row]!=-1 && right_edge[W_num_row+1]!=-1 && right_edge[W_num_row]<=right_edge[W_num_row+1] )
                                          {
                                                continue;
                                          }
                                          else
                                          {
                                                W_num++;
                                          }
                                    }
                                    if( W_num<=2 )
                                    {
                                          L_down_cross[0]=-1;
                                          L_down_cross[1]=-1;
                                          L_cross_flag=0;
                                          cross_flag=0;
                                    }
                              }
                        }
                  }
                  else
                  {
                        if( R_down_cross[0]!=-1 )
                        {
                              Site_xy xy;
                              Site_xy1 xy1;
                              xy=get_inv_img( R_down_cross[0] , R_down_cross[1] );
                              if( xy.y>-40 )
                              {
                                    int16 r_start,r_end;
                                    xy1=get_invinv_img( xy.x-60 , 0 );
                                    r_start=xy1.x;
                                    if( r_start>ROW_END )
                                    {
                                          r_start=ROW_END;
                                    }
                                    xy1=get_invinv_img( xy.x+120 , 0 );
                                    r_end=xy1.x;
                                    if( R_TURN==1 && L_end_row!=-1 )
                                    {
                                          if( R_end_row>r_end )
                                          {
                                                r_end=R_end_row;
                                          }
                                    }
                                    else
                                    {
                                          if( r_end<ROW_START )
                                          {
                                                r_end=ROW_START;
                                          }
                                    }
                                    
                                    W_num=0;
                                    for( W_num_row=r_start-1 ; W_num_row>=r_end ; W_num_row-- )
                                    {
                                          if( left_edge[W_num_row]!=-1 && left_edge[W_num_row+1]!=-1 && left_edge[W_num_row]>=left_edge[W_num_row+1] )
                                          {
                                                continue;
                                          }
                                          else
                                          {
                                                W_num++;
                                          }
                                    }
                                    if( W_num<=2 )
                                    {
                                          R_down_cross[0]=-1;
                                          R_down_cross[1]=-1;
                                          R_cross_flag=0;
                                          cross_flag=0;
                                    }
                              }
                        }
                  }
            }
            
            if( loop_able==1 && LOOP_IN==0 && LOOP_FLAG==0 )    //���������жϣ�б���ж�
            {
                  if( L_down_cross[0]!=-1 )   //ͨ�����������жϻ���
                  {
                        if( R_down_cross[0]!=-1 )
                        {
                              if( L_down_cross[1]<=40 && L_cross_k>0 && inv_distance[L_down_cross[0]]<240 )
                              {
                                    W_num=0;
                                    for( W_num_row=L_down_cross[0]-1 ; W_num_row>=ROW_START ; W_num_row-- )
                                    {
                                          if( left_edge[W_num_row]!=-1 )
                                          {
                                                W_num++;
                                          }
                                          else
                                          {
                                                break;
                                          }
                                    }
                                    if( W_num<=3 )   //��������б�뻷����
                                    {
                                          if( L_up_cross[0]!=-1 )    //����������������
                                          {
                                                double aa;
                                                Site_xy xy1,xy2;
                                                xy1=get_inv_img( L_down_cross[0] , L_down_cross[1] );
                                                
                                                W_num=0;
                                                W_num_col=0;
                                                for( W_num_row=L_up_cross[0] ; W_num_row>=ROW_START ; W_num_row-- )
                                                {
                                                      if( fabs(inv_distance[W_num_row]-inv_distance[L_down_cross[0]])>400 )
                                                      {
                                                            break;
                                                      }
                                                      if( left_edge[W_num_row]!=-1 )
                                                      {
                                                            xy2=get_inv_img( W_num_row , left_edge[W_num_row] );
                                                            aa=xy1.y-L_cross_k*fabsf(inv_distance[W_num_row]-xy1.x);
                                                            if( xy2.y>aa+120 )
                                                            {
                                                                  W_num++;
                                                                  if( W_num>4 )
                                                                  {
                                                                        break;
                                                                  }
                                                            }
                                                            else
                                                            {
                                                                  if( xy2.y<aa+40 )
                                                                  {
                                                                        W_num_col++;
                                                                        if( W_num_col>=7 )
                                                                        {
                                                                              break;
                                                                        }
                                                                  }
                                                            }
                                                      }
                                                }
                                                if( W_num>4 )
                                                {
                                                      LOOP_FLAG=1;                          //�ж�Ϊ��������
                                                      
                                                      LOOP_IN_ROW=L_down_cross[0];            //������������и�ֵ
                                                }
                                          }
                                    }
                              }
                              
                              if( R_down_cross[1]>=119 && R_cross_k<0 && inv_distance[R_down_cross[0]]<240 )
                              {
                                    W_num=0;
                                    for( W_num_row=R_down_cross[0]-1 ; W_num_row>=ROW_START ; W_num_row-- )
                                    {
                                          if( right_edge[W_num_row]!=-1 )
                                          {
                                                W_num++;
                                          }
                                          else
                                          {
                                                break;
                                          }
                                    }
                                    if( W_num<=3 )   //��������б�뻷����
                                    {
                                          if( R_up_cross[0]!=-1 )    //����������������
                                          {
                                                double aa;
                                                Site_xy xy1,xy2;
                                                W_num=0;
                                                xy1=get_inv_img( R_down_cross[0] , R_down_cross[1] );
                                                
                                                
                                                W_num=0;
                                                W_num_col=0;
                                                for( W_num_row=R_up_cross[0] ; W_num_row>=ROW_START ; W_num_row-- )
                                                {
                                                      if( fabs(inv_distance[W_num_row]-inv_distance[R_down_cross[0]])>400 )
                                                      {
                                                            break;
                                                      }
                                                      if( right_edge[W_num_row]!=-1 )
                                                      {
                                                            xy2=get_inv_img( W_num_row , right_edge[W_num_row] );
                                                            aa=xy1.y-R_cross_k*fabsf(inv_distance[W_num_row]-xy1.x);
                                                            if( xy2.y<aa-120 )
                                                            {
                                                                  W_num++;
                                                                  if( W_num>4 )
                                                                  {
                                                                        break;
                                                                  }
                                                            }
                                                            else
                                                            {
                                                                  if( xy2.y>aa-40 )
                                                                  {
                                                                        W_num_col++;
                                                                        if( W_num_col>=7 )
                                                                        {
                                                                              break;
                                                                        }
                                                                  }
                                                            }
                                                      }
                                                }
                                                if( W_num>4 )
                                                {
                                                      LOOP_FLAG=1;                          //�ж�Ϊ��������
                                                      
                                                      LOOP_IN_ROW=R_down_cross[0];            //������������и�ֵ
                                                }
                                          }
                                    }
                              }
                        }
                        else
                        {
                              if( L_down_cross[1]<=40 && L_cross_k>0 && inv_distance[L_down_cross[0]]<240 )
                              {
                                    W_num=0;
                                    for( W_num_row=L_down_cross[0]-1 ; W_num_row>=ROW_START ; W_num_row-- )
                                    {
                                          if( left_edge[W_num_row]!=-1 )
                                          {
                                                W_num++;
                                          }
                                          else
                                          {
                                                break;
                                          }
                                    }
                                    if( W_num<=3 )   //��������б�뻷����
                                    {
                                          if( L_up_cross[0]!=-1 )   //��������ʮ��
                                          {
                                                W_num=0;
                                                for( W_num_row=L_down_cross[0]-3 ; W_num_row>=ROW_START ; W_num_row-- )  //��������Բ��
                                                {
                                                      if( fabs(inv_distance[W_num_row]-inv_distance[L_down_cross[0]])>400 )
                                                      {
                                                            break;
                                                      }
                                                      if( left_edge[W_num_row]!=-1 )
                                                      {
                                                            for( W_num_col=left_edge[W_num_row]-1 ; W_num_col>=COL_START+3 ; W_num_col-- )
                                                            {
                                                                  if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_B && img_data[EXTRACT_ROW][EXTRACT_COL-1] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL-3] == DOT_W )
                                                                  {
                                                                        W_num++;
                                                                        break;
                                                                  }
                                                            }
                                                      }
                                                }
                                                if( W_num>=5 )  //�����õ�����Բ��
                                                {
                                                      LOOP_FLAG=1;                          //�ж�Ϊ��������
                                                      
                                                      LOOP_IN_ROW=L_down_cross[0];            //������������и�ֵ
                                                }
                                                else    //����������������
                                                {
                                                      double aa;
                                                      Site_xy xy1,xy2;
                                                      xy1=get_inv_img( L_down_cross[0] , L_down_cross[1] );
                                                      
                                                      W_num=0;
                                                      W_num_col=0;
                                                      for( W_num_row=L_up_cross[0] ; W_num_row>=ROW_START ; W_num_row-- )
                                                      {
                                                            if( fabs(inv_distance[W_num_row]-inv_distance[L_down_cross[0]])>400 )
                                                            {
                                                                  break;
                                                            }
                                                            if( left_edge[W_num_row]!=-1 )
                                                            {
                                                                  xy2=get_inv_img( W_num_row , left_edge[W_num_row] );
                                                                  aa=xy1.y-L_cross_k*fabsf(inv_distance[W_num_row]-xy1.x);
                                                                  if( xy2.y>aa+120 )
                                                                  {
                                                                        W_num++;
                                                                        if( W_num>4 )
                                                                        {
                                                                              break;
                                                                        }
                                                                  }
                                                                  else
                                                                  {
                                                                        if( xy2.y<aa+40 )
                                                                        {
                                                                              W_num_col++;
                                                                              if( W_num_col>=7 )
                                                                              {
                                                                                    break;
                                                                              }
                                                                        }
                                                                  }
                                                            }
                                                      }
                                                      if( W_num>4 )
                                                      {
                                                            LOOP_FLAG=1;                          //�ж�Ϊ��������
                                                            
                                                            LOOP_IN_ROW=L_down_cross[0];            //������������и�ֵ
                                                      }
                                                }
                                          }
                                    }
                              }
                        }
                  }
                  else
                  {
                        if( R_down_cross[0]!=-1 )
                        {
                              if( R_down_cross[1]>=119 && R_cross_k<0 && inv_distance[R_down_cross[0]]<240 )
                              {
                                    W_num=0;
                                    for( W_num_row=R_down_cross[0]-1 ; W_num_row>=ROW_START ; W_num_row-- )
                                    {
                                          if( right_edge[W_num_row]!=-1 )
                                          {
                                                W_num++;
                                          }
                                          else
                                          {
                                                break;
                                          }
                                    }
                                    if( W_num<=3 )   //��������б�뻷����
                                    {
                                          if( R_up_cross[0]!=-1 )
                                          {
                                                W_num=0;
                                                for( W_num_row=R_down_cross[0]-3 ; W_num_row>=ROW_START ; W_num_row-- )  //��������Բ��
                                                {
                                                      if( fabs(inv_distance[W_num_row]-inv_distance[R_down_cross[0]])>400 )
                                                      {
                                                            break;
                                                      }
                                                      if( right_edge[W_num_row]!=-1 )
                                                      {
                                                            for( W_num_col=right_edge[W_num_row]-1 ; W_num_col<=COL_END-3 ; W_num_col++ )
                                                            {
                                                                  if( img_data[EXTRACT_ROW][EXTRACT_COL] == DOT_B && img_data[EXTRACT_ROW][EXTRACT_COL+1] == DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL+3] == DOT_W )
                                                                  {
                                                                        W_num++;
                                                                        break;
                                                                  }
                                                            }
                                                      }
                                                }
                                                if( W_num>=5 )  //�����õ�����Բ��
                                                {
                                                      LOOP_FLAG=1;                          //�ж�Ϊ��������
                                                      
                                                      LOOP_IN_ROW=R_down_cross[0];            //������������и�ֵ
                                                }
                                                else    //����������������
                                                {
                                                      double aa;
                                                      Site_xy xy1,xy2;
                                                      xy1=get_inv_img( R_down_cross[0] , R_down_cross[1] );
                                                      
                                                      W_num=0;
                                                      W_num_col=0;
                                                      for( W_num_row=R_up_cross[0] ; W_num_row>=ROW_START ; W_num_row-- )
                                                      {
                                                            if( fabs(inv_distance[W_num_row]-inv_distance[R_down_cross[0]])>400 )
                                                            {
                                                                  break;
                                                            }
                                                            if( right_edge[W_num_row]!=-1 )
                                                            {
                                                                  xy2=get_inv_img( W_num_row , right_edge[W_num_row] );
                                                                  aa=xy1.y-R_cross_k*fabsf(inv_distance[W_num_row]-xy1.x);
                                                                  if( xy2.y<aa-120 )
                                                                  {
                                                                        W_num++;
                                                                        if( W_num>4 )
                                                                        {
                                                                              break;
                                                                        }
                                                                  }
                                                                  else
                                                                  {
                                                                        if( xy2.y>aa-40 )
                                                                        {
                                                                              W_num_col++;
                                                                              if( W_num_col>=7 )
                                                                              {
                                                                                    break;
                                                                              }
                                                                        }
                                                                  }
                                                            }
                                                      }
                                                      if( W_num>4 )
                                                      {
                                                            LOOP_FLAG=1;                          //�ж�Ϊ��������
                                                            
                                                            LOOP_IN_ROW=R_down_cross[0];            //������������и�ֵ
                                                      }
                                                }
                                          }
                                    }
                              }
                        }
                  }
                  
                  if( LOOP_FLAG==0 )   //ͨ��ǰ���ڿ��жϻ���
                  {
                        if( L_down_cross[0]!=-1 )
                        {
                              if( R_down_cross[0]!=-1 )
                              {
                                    if( L_up_cross[0]==-1 || R_up_cross[0]==-1 )
                                    {
                                          if( fabsf(inv_distance[L_down_cross[0]]-inv_distance[R_down_cross[0]])<80 )
                                          {
                                                double aa;
                                                Site_xy xy_l,xy_r;
                                                Site_xy1 xy1,xy2;
                                                int16 l_edge,r_edge;
                                                int16 r_start,r_end,b_point,edge_able=0;
                                                xy_l=get_inv_img( L_down_cross[0] , L_down_cross[1] );
                                                xy_r=get_inv_img( R_down_cross[0] , R_down_cross[1] );
                                                
                                                if( xy_l.x<320 && xy_r.x<320 && fabsf(xy_l.y-xy_r.y)>120 && fabsf(xy_l.y-xy_r.y)<200 )
                                                {
                                                      aa=0.5*(xy_l.x+xy_l.x)+220;
                                                      xy1=get_invinv_img( aa , 0 );
                                                      r_start=xy1.x;
                                                      if( r_start<0 )
                                                      {
                                                            r_start=0;
                                                      }
                                                      aa=0.5*(xy_l.x+xy_l.x)+400;
                                                      xy1=get_invinv_img( aa , 0 );
                                                      r_end=xy1.x;
                                                      if( r_end<0 )
                                                      {
                                                            r_end=0;
                                                      }
                                                      
                                                      W_num=0;
                                                      b_point=0;
                                                      for( W_num_row=r_start ; W_num_row>=r_end ; W_num_row-- )
                                                      {
                                                            aa=xy_l.y-L_cross_k*fabsf(inv_distance[W_num_row]-xy_l.x);
                                                            xy1=get_invinv_img( inv_distance[W_num_row] , aa );
                                                            aa=xy_r.y-R_cross_k*fabsf(inv_distance[W_num_row]-xy_r.x);
                                                            xy2=get_invinv_img( inv_distance[W_num_row] , aa );
                                                            if( xy1.y>=COL_END )
                                                            {
                                                                  break;
                                                            }
                                                            else
                                                            {
                                                                  if( xy1.y<COL_START )
                                                                  {
                                                                        l_edge=COL_START;
                                                                  }
                                                                  else
                                                                  {
                                                                        l_edge=xy1.y;
                                                                  }
                                                            }
                                                            
                                                            if( xy2.y<=COL_START )
                                                            {
                                                                  break;
                                                            }
                                                            else
                                                            {
                                                                  if( xy2.y>COL_END )
                                                                  {
                                                                        r_edge=COL_END;
                                                                  }
                                                                  else
                                                                  {
                                                                        r_edge=xy2.y;
                                                                  }
                                                            }
                                                            for( W_num_col=l_edge ; W_num_col<=r_edge ; W_num_col++ )
                                                            {
                                                                  W_num++;
                                                                  if( img_data[W_num_row][W_num_col]==DOT_B )
                                                                  {
                                                                        b_point++;
                                                                  }
                                                            }
                                                      }
                                                      if( W_num==0)
                                                      {
                                                            aa=0;
                                                      }
                                                      else
                                                      {
                                                            aa=100.0*b_point/W_num;
                                                      }
                                                      
                                                      //angle_aaa[0]=aa;
                                                      //angle_aaa[1]=b_point;
                                                      //angle_aaa[2]=W_num;
                                                      
                                                      if( aa>loop_per && W_num>=250 )
                                                      {
                                                            LOOP_FLAG=1;                          //�ж�Ϊ��������
                                                            
                                                            LOOP_IN_ROW=L_down_cross[0];            //������������и�ֵ
                                                      }
                                                }
                                          }
                                    }
                              }
                              else
                              {
                                    if( L_up_cross[0]==-1 )
                                    {
                                          double aa;
                                          Site_xy xy;
                                          Site_xy1 xy1;
                                          int16 r_start,r_end,b_point,edge_able=0;
                                          xy=get_inv_img( L_down_cross[0] , L_down_cross[1] );
                                          
                                          if( xy.x<320 && xy.y<40 )
                                          {
                                                if( xy.x>240 )
                                                {
                                                      edge_able=1;
                                                }
                                                
                                                aa=xy.x+220;
                                                xy1=get_invinv_img( aa , 0 );
                                                r_start=xy1.x;
                                                if( r_start<0 )
                                                {
                                                      r_start=0;
                                                }
                                                aa=xy.x+400;
                                                xy1=get_invinv_img( aa , 0 );
                                                r_end=xy1.x;
                                                if( r_end<0 )
                                                {
                                                      r_end=0;
                                                }
                                                
                                                W_num=0;
                                                b_point=0;
                                                for( W_num_row=r_start ; W_num_row>=r_end ; W_num_row-- )
                                                {
                                                      if( L_TURN==1 && R_end_row!=-1 && W_num_row<R_end_row )
                                                      {
                                                            break;
                                                      }
                                                      
                                                      if( fabsf(inv_distance[W_num_row]-xy.x)>cross_k_2 )
                                                      {
                                                            aa=cross_k_1*cross_k_2;
                                                      }
                                                      else
                                                      {
                                                            aa=cross_k_1*fabsf(inv_distance[W_num_row]-xy.x);
                                                      }
                                                      aa=xy.y-L_cross_k*fabsf(inv_distance[W_num_row]-xy.x)+aa;
                                                      xy1=get_invinv_img( inv_distance[W_num_row] , aa );
                                                      if( xy1.y>=COL_END )
                                                      {
                                                            break;
                                                      }
                                                      if( edge_able==1 )
                                                      {
                                                            if( right_edge[W_num_row]!=-1 &&  xy1.y>right_edge[W_num_row] )
                                                            {
                                                                  break;
                                                            }
                                                      }
                                                      
                                                      for( W_num_col=xy1.y ; W_num_col<=xy1.y+2*bar_range_col[W_num_row] ; W_num_col++ )
                                                      {
                                                            if( W_num_col>COL_END )
                                                            {
                                                                  break;
                                                            }
                                                            W_num++;
                                                            if( img_data[W_num_row][W_num_col]==DOT_B )
                                                            {
                                                                  b_point++;
                                                            }
                                                      }
                                                }
                                                if( W_num==0)
                                                {
                                                      aa=0;
                                                }
                                                else
                                                {
                                                      aa=100.0*b_point/W_num;
                                                }
                                                
                                                //angle_aaa[0]=aa;
                                                //angle_aaa[1]=b_point;
                                                //angle_aaa[2]=W_num;
                                                
                                                if( aa>loop_per && W_num>=250 )
                                                {
                                                      LOOP_FLAG=1;                          //�ж�Ϊ��������
                                                      
                                                      LOOP_IN_ROW=L_down_cross[0];            //������������и�ֵ
                                                }
                                          }
                                    }
                              }
                        }
                        else
                        {
                              if( R_down_cross[0]!=-1 && R_up_cross[0]==-1 )
                              {
                                    double aa;
                                    Site_xy xy;
                                    Site_xy1 xy1;
                                    int16 r_start,r_end,b_point,edge_able=0;
                                    xy=get_inv_img( R_down_cross[0] , R_down_cross[1] );
                                    
                                    if( xy.x<320 && xy.y>-40 )
                                    {
                                          if( xy.x>240 )
                                          {
                                                edge_able=1;
                                          }
                                          aa=xy.x+220;
                                          xy1=get_invinv_img( aa , 0 );
                                          r_start=xy1.x;
                                          if( r_start<0 )
                                          {
                                                r_start=0;
                                          }
                                          aa=xy.x+400;
                                          xy1=get_invinv_img( aa , 0 );
                                          r_end=xy1.x;
                                          if( r_end<0 )
                                          {
                                                r_end=0;
                                          }
                                          
                                          W_num=0;
                                          b_point=0;
                                          for( W_num_row=r_start ; W_num_row>=r_end ; W_num_row-- )
                                          {
                                                if( R_TURN==1 && L_end_row!=-1 && W_num_row<L_end_row )
                                                {
                                                      break;
                                                }
                                                
                                                if( fabsf(inv_distance[W_num_row]-xy.x)>cross_k_2 )
                                                {
                                                      aa=cross_k_1*cross_k_2;
                                                }
                                                else
                                                {
                                                      aa=cross_k_1*fabsf(inv_distance[W_num_row]-xy.x);
                                                }
                                                aa=xy.y-R_cross_k*fabsf(inv_distance[W_num_row]-xy.x)-aa;
                                                xy1=get_invinv_img( inv_distance[W_num_row] , aa );
                                                if( xy1.y<=COL_START )
                                                {
                                                      break;
                                                }
                                                if( edge_able==1 )
                                                {
                                                      if( left_edge[W_num_row]!=-1 &&  xy1.y<left_edge[W_num_row] )
                                                      {
                                                            break;
                                                      }
                                                }
                                                
                                                for( W_num_col=xy1.y ; W_num_col>=xy1.y-2*bar_range_col[W_num_row] ; W_num_col-- )
                                                {
                                                      if( W_num_col<COL_START )
                                                      {
                                                            break;
                                                      }
                                                      W_num++;
                                                      if( img_data[W_num_row][W_num_col]==DOT_B )
                                                      {
                                                            b_point++;
                                                      }
                                                }
                                          }
                                          if( W_num==0)
                                          {
                                                aa=0;
                                          }
                                          else
                                          {
                                                aa=100.0*b_point/W_num;
                                          }
                                          
                                          //angle_aaa[0]=aa;
                                          //angle_aaa[1]=b_point;
                                          //angle_aaa[2]=W_num;
                                          
                                          if( aa>loop_per && W_num>=250 )
                                          {
                                                LOOP_FLAG=1;                          //�ж�Ϊ��������
                                                
                                                LOOP_IN_ROW=R_down_cross[0];            //������������и�ֵ
                                          }
                                    }
                              }
                        }
                  }
            }
            
            
            if( L_up_cross[0]!=-1 )  //�������ʮ�����д���
            {
                  double aa=0;
                  W_num=0;
                  for(  W_num_row=L_up_cross[0]-1 ; W_num_row>=L_up_cross[0]-10 ; W_num_row--  )  //ѡȡ���ʵ����¹յ�
                  {
                        if( W_num_row<ROW_START )
                        {
                              break;
                        }
                        if( left_edge[W_num_row]!=-1 )
                        {
                              W_num++;
                              aa=aa+fabsf(inv_distance[W_num_row]-inv_distance[W_num_row+1]);
                        }
                  }
                  if( W_num<=4 && aa<100 )
                  {
                        L_up_cross[0]=-1;
                        L_up_cross[1]=-1;
                        L_cross_flag=0;
                        cross_flag=0;
                  }
            }
            if( R_up_cross[0]!=-1 )  //�ұ�����ʮ�����д���
            {
                  double aa=0;
                  W_num=0;
                  for(  W_num_row=R_up_cross[0]-1 ; W_num_row>=R_up_cross[0]-10 ; W_num_row--  )  //ѡȡ���ʵ����¹յ�
                  {
                        if( W_num_row<ROW_START )
                        {
                              break;
                        }
                        if( right_edge[W_num_row]!=-1 )
                        {
                              W_num++;
                              aa=aa+fabsf(inv_distance[W_num_row]-inv_distance[W_num_row+1]);
                        }
                  }
                  if( W_num<=4 && aa<100 )
                  {
                        R_up_cross[0]=-1;
                        R_up_cross[1]=-1;
                        R_cross_flag=0;
                        cross_flag=0;
                  }
            }
            
            /*��Q��ʱ*/
            if( L_up_cross[0]==-1 && L_down_cross[1]!=-1 && L_down_cross[1]>=110 && L_down_cross[0]<40 )  //����������
            {
                  L_TURN=0;
                  R_TURN=1;
                  L_up_cross[0]=-1;
                  L_up_cross[1]=-1;
                  L_end_row=-1;
                  R_end_row=-1;
                  for(  W_num_row=L_down_cross[0]-1 ; W_num_row>=ROW_START ; W_num_row--  )
                  {
                        if( left_edge[W_num_row]!=-1 )
                        {
                              left_edge[W_num_row]=-1;
                              L_EDGE_NUM--;
                        }
                        if( right_edge[W_num_row]!=-1 )
                        {
                              right_edge[W_num_row]=-1;
                              R_EDGE_NUM--;
                        }
                  }
                  
                  /*ʮ��Ψһ��������*/
                  if( L_cross_k!=10 )   //���������õ�б��
                  {
                        double aa;
                        Site_xy1 xy2;
                        Site_xy xy1;
                        
                        xy1=get_inv_img( L_down_cross[0] , L_down_cross[1] );
                        
                        for( cross_row=L_down_cross[0]-1 ; cross_row>=ROW_START ; cross_row-- )
                        {
                              aa=xy1.y-L_cross_k*fabsf(inv_distance[cross_row]-xy1.x);
                              xy2=get_invinv_img( inv_distance[cross_row] , aa );
                              
                              if( xy2.y>COL_END )
                              {
                                    break;
                              }
                              
                              left_edge[cross_row]=xy2.y;
                              L_EDGE_NUM++;
                        }
                  }
            }
            else
            {
                  if( L_down_cross[0]<20 && L_up_cross[0]==-1 )
                  {
                        for(  W_num_row=L_down_cross[0]-1 ; W_num_row>=ROW_START ; W_num_row--  )
                        {
                              if( left_edge[W_num_row]!=-1 )
                              {
                                    left_edge[W_num_row]=-1;
                                    L_EDGE_NUM--;
                              }
                        }
                  }
            }
            if( R_up_cross[0]==-1 && R_down_cross[1]!=-1 && R_down_cross[1]<=50 && R_down_cross[0]<40 )  //����������
            {
                  L_TURN=1;
                  R_TURN=0;
                  R_up_cross[0]=-1;
                  R_up_cross[1]=-1;
                  L_end_row=-1;
                  R_end_row=-1;
                  for(  W_num_row=R_down_cross[0]-1 ; W_num_row>=ROW_START ; W_num_row--  )
                  {
                        if( left_edge[W_num_row]!=-1 )
                        {
                              left_edge[W_num_row]=-1;
                              L_EDGE_NUM--;
                        }
                        if( right_edge[W_num_row]!=-1 )
                        {
                              right_edge[W_num_row]=-1;
                              R_EDGE_NUM--;
                        }
                  }
                  
                  /*ʮ��Ψһ��������*/
                  if( R_cross_k!=10 )   //���������õ�б��
                  {
                        double aa;
                        Site_xy1 xy2;
                        Site_xy xy1;
                        
                        xy1=get_inv_img( R_down_cross[0] , R_down_cross[1] );
                        
                        for( cross_row=R_down_cross[0]-1 ; cross_row>=ROW_START ; cross_row-- )
                        {
                              aa=xy1.y-R_cross_k*fabsf(inv_distance[cross_row]-xy1.x);
                              xy2=get_invinv_img( inv_distance[cross_row] , aa );
                              
                              if( xy2.y<COL_START )
                              {
                                    break;
                              }
                              
                              right_edge[cross_row]=xy2.y;
                              R_EDGE_NUM++;
                        }
                  }
            }
            else
            {
                  if( R_down_cross[0]<20 && R_up_cross[0]==-1 )
                  {
                        for(  W_num_row=R_down_cross[0]-1 ; W_num_row>=ROW_START ; W_num_row--  )
                        {
                              if( right_edge[W_num_row]!=-1 )
                              {
                                    right_edge[W_num_row]=-1;
                                    R_EDGE_NUM--;
                              }
                        }
                  }
            }
            
            /*���³����Ϊ�����ʮ�ֲ��߳���*/
            
            if( L_down_cross[0]!=-1 && L_up_cross[0]!=-1 )   //���������ʮ��ֱ�ǹյ����
            {
                  int16 down_edge[2]={-1,-1},up_edge[2]={-1,-1};
                  for(  W_num_row=L_down_cross[0]+2 ; W_num_row<=L_down_cross[0]+4 ; W_num_row++  )  //ѡȡ���ʵ����¹յ�
                  {
                        if( W_num_row>ROW_END )
                        {
                              break;
                        }
                        if( left_edge[W_num_row]!=-1 )
                        {
                              down_edge[0]=W_num_row;
                              
                              down_edge[1]=left_edge[W_num_row];
                              
                              break;
                        }
                  }
                  if( down_edge[0]==-1 )
                  {
                        down_edge[0]=L_down_cross[0];
                        down_edge[1]=L_down_cross[1];
                  }
                  for(  W_num_row=L_up_cross[0]-2 ; W_num_row>=L_up_cross[0]-4 ; W_num_row--  )  //ѡȡ���ʵ����¹յ�
                  {
                        if( W_num_row<ROW_START )
                        {
                              break;
                        }
                        if( left_edge[W_num_row]!=-1 && left_edge[W_num_row]-L_up_cross[1]>=0 )
                        {
                              up_edge[0]=W_num_row;
                              
                              up_edge[1]=left_edge[W_num_row];
                              
                              break;
                        }
                  }
                  if( up_edge[0]==-1 )
                  {
                        up_edge[0]=L_up_cross[0];
                        up_edge[1]=L_up_cross[1];
                  }
                  
                  cross_high=down_edge[0]-up_edge[0];
                  cross_wide=up_edge[1]-down_edge[1];
                  cross_wide=cross_wide/cross_high;   //Ϊ��ֵ
                  cross_edge=down_edge[1];
                  for( cross_row=down_edge[0]-1 ; cross_row>up_edge[0] ; cross_row-- )
                  {
                        cross_edge=cross_edge+cross_wide;
                        cross_col=round(cross_edge);
                        left_edge[cross_row]=cross_col;
                        L_EDGE_NUM++;
                  }
            }
            else    //���������ʮ��ֱ�ǹյ�δȫ������
            {
                  if( L_down_cross[0]==-1 && L_up_cross[0]!=-1 )  //ֻ���������ʮ��ֱ�ǹյ����
                  {
                        Site_xy1 xy1;
                        xy1=get_invinv_img(inv_distance[L_up_cross[0]]-120,0);
                        if( xy1.x<ROW_END )
                        {
                              W_num=0;
                              for( W_num_row=ROW_END ; W_num_row>=xy1.x ; W_num_row-- )
                              {
                                    if( left_edge[W_num_row]!=-1 && left_edge[W_num_row-1]!=-1 )
                                    {
                                          if( left_edge[W_num_row]<=left_edge[W_num_row-1] && left_edge[W_num_row]+5>=left_edge[W_num_row-1] )
                                          {
                                                L_down_cross[0]=W_num_row-1;
                                                L_down_cross[1]=left_edge[W_num_row-1];
                                          }
                                          else
                                          {
                                                W_num++;
                                                if( W_num>=4 )
                                                {
                                                      break;
                                                }
                                          }
                                    }
                                    else
                                    {
                                          if( L_down_cross[0]!=-1 )
                                          {
                                                W_num++;
                                                if( W_num>=4 )
                                                {
                                                      break;
                                                }
                                          }
                                    }
                              }
                        }
                        
                        if( L_down_cross[0]==-1 )
                        {
                              int16 up_edge[2]={-1,-1};
                              for( W_num_row=L_up_cross[0]-2 ; W_num_row>=L_up_cross[0]-4 ; W_num_row-- )  //ѡȡ���ʵ����¹յ�
                              {
                                    if( W_num_row<ROW_START )
                                    {
                                          break;
                                    }
                                    if( left_edge[W_num_row]!=-1 )
                                    {
                                          up_edge[0]=W_num_row;
                                          
                                          up_edge[1]=left_edge[W_num_row];
                                          
                                          break;
                                    }
                              }
                              if( up_edge[0]==-1 )
                              {
                                    up_edge[0]=L_up_cross[0];
                                    up_edge[1]=L_up_cross[1];
                              }
                              
                              double x=0.0,y=0.0,x1,y1,k=0.0,a;
                              Site_xy xy1,xy2;
                              Site_xy1 xy3;
                              
                              xy1=get_inv_img( up_edge[0] , up_edge[1] );    //��ȡ�յ���͸������
                              
                              a=xy1.x+50;
                              xy3=get_invinv_img( a , 0 );
                              if( up_edge[0]-xy3.x>15 )
                              {
                                    W_num_row=15;
                              }
                              else
                              {
                                    if( up_edge[0]-xy3.x<3 )
                                    {
                                          W_num_row=3;
                                    }
                                    else
                                    {
                                          W_num_row=abs(up_edge[0]-xy3.x);
                                    }
                              }
                              
                              for( W_num=1 ; W_num<=W_num_row ; W_num++ )   //��ȡ�յ����µ����б��
                              {
                                    W_num_col=up_edge[0]-W_num;
                                    if( W_num_col<ROW_START )
                                    {
                                          break;
                                    }
                                    if( left_edge[W_num_col]!=-1 )
                                    {
                                          xy2=get_inv_img( W_num_col , left_edge[W_num_col] );
                                          x1=xy2.x-xy1.x;
                                          y1=xy2.y-xy1.y;
                                          x=x+x1*y1;
                                          y=y+x1*x1;
                                    }
                                    else
                                    {
                                          break;
                                    }
                              }
                              if( x!=0 )
                              {
                                    k=(-1)*x/y;    //�õ��յ����µ����б��
                              }
                              else
                              {
                                    k==0;
                              }
                              cross_wide=k;        //ȡ�������б��
                              
                              cross_edge=up_edge[1];
                              for( cross_row=up_edge[0]+1 ; cross_row<=ROW_END ; cross_row++ )
                              {
                                    a=xy1.y+cross_wide*fabsf(inv_distance[cross_row]-xy1.x);
                                    xy3=get_invinv_img( inv_distance[cross_row] , a );
                                    if( xy3.y<COL_START )
                                    {
                                          break;
                                    }
                                    
                                    left_edge[cross_row]=xy3.y;
                                    L_EDGE_NUM++;
                              }
                        }
                        else
                        {
                              int16 up_edge[2]={-1,-1};
                              for(  W_num_row=L_up_cross[0]-2 ; W_num_row>=L_up_cross[0]-4 ; W_num_row--  )  //ѡȡ���ʵ����¹յ�
                              {
                                    if( W_num_row<ROW_START )
                                    {
                                          break;
                                    }
                                    if( left_edge[W_num_row]!=-1 )
                                    {
                                          up_edge[0]=W_num_row;
                                          
                                          up_edge[1]=left_edge[W_num_row];
                                          
                                          break;
                                    }
                              }
                              if( up_edge[0]==-1 )
                              {
                                    up_edge[0]=L_up_cross[0];
                                    up_edge[1]=L_up_cross[1];
                              }
                              
                              cross_high=L_down_cross[0]-up_edge[0];
                              cross_wide=up_edge[1]-left_edge[L_down_cross[0]];
                              cross_wide=cross_wide/cross_high;   //Ϊ��ֵ
                              cross_edge=left_edge[L_down_cross[0]];
                              for( cross_row=L_down_cross[0]-1 ; cross_row>up_edge[0] ; cross_row-- )
                              {
                                    cross_edge=cross_edge+cross_wide;
                                    cross_col=round(cross_edge);
                                    left_edge[cross_row]=cross_col;
                                    L_EDGE_NUM++;
                              }
                        }
                  }
            }
            
            /*���³����Ϊ�ұ���ʮ�ֲ��߳���*/
            
            if( R_down_cross[0]!=-1 && R_up_cross[0]!=-1 )   //�ұ�������ʮ��ֱ�ǹյ����
            {
                  int16 down_edge[2]={-1,-1},up_edge[2]={-1,-1};
                  for(  W_num_row=R_down_cross[0]+2 ; W_num_row<=R_down_cross[0]+4 ; W_num_row++  )  //ѡȡ���ʵ����¹յ�
                  {
                        if( W_num_row>ROW_END )
                        {
                              break;
                        }
                        if( right_edge[W_num_row]!=-1 )
                        {
                              down_edge[0]=W_num_row;
                              
                              down_edge[1]=right_edge[W_num_row];
                              
                              break;
                        }
                  }
                  if( down_edge[0]==-1 )
                  {
                        down_edge[0]=R_down_cross[0];
                        down_edge[1]=R_down_cross[1];
                  }
                  for(  W_num_row=R_up_cross[0]-2 ; W_num_row>=R_up_cross[0]-4 ; W_num_row--  )  //ѡȡ���ʵ����¹յ�
                  {
                        if( W_num_row<ROW_START )
                        {
                              break;
                        }
                        if( right_edge[W_num_row]!=-1 && right_edge[W_num_row]-R_up_cross[1]<=0 )
                        {
                              up_edge[0]=W_num_row;
                              
                              up_edge[1]=right_edge[W_num_row];
                              
                              break;
                        }
                  }
                  if( up_edge[0]==-1 )
                  {
                        up_edge[0]=R_up_cross[0];
                        up_edge[1]=R_up_cross[1];
                  }
                  
                  cross_high=down_edge[0]-up_edge[0];
                  cross_wide=up_edge[1]-down_edge[1];
                  cross_wide=cross_wide/cross_high;
                  cross_edge=down_edge[1];
                  for( cross_row=down_edge[0]-1 ; cross_row>up_edge[0] ; cross_row-- )
                  {
                        cross_edge=cross_edge+cross_wide;
                        cross_col=round(cross_edge);
                        right_edge[cross_row]=cross_col;
                        R_EDGE_NUM++;
                  }
            }
            else    //�ұ�������ʮ��ֱ�ǹյ�δȫ������
            {
                  if( R_down_cross[0]==-1 && R_up_cross[0]!=-1 )  //ֻ���ұ�����ʮ��ֱ�ǹյ����
                  {
                        Site_xy1 xy1;
                        xy1=get_invinv_img(inv_distance[R_up_cross[0]]-120,0);
                        if( xy1.x<ROW_END )
                        {
                              W_num=0;
                              for( W_num_row=ROW_END ; W_num_row>=xy1.x ; W_num_row-- )
                              {
                                    if( right_edge[W_num_row]!=-1 && right_edge[W_num_row-1]!=-1 )
                                    {
                                          if( right_edge[W_num_row]>=right_edge[W_num_row-1] && right_edge[W_num_row]<=right_edge[W_num_row-1]+5 )
                                          {
                                                R_down_cross[0]=W_num_row-1;
                                                R_down_cross[1]=right_edge[W_num_row-1];
                                          }
                                          else
                                          {
                                                W_num++;
                                                if( W_num>=4 )
                                                {
                                                      break;
                                                }
                                          }
                                    }
                                    else
                                    {
                                          if( R_down_cross[0]!=-1 )
                                          {
                                                W_num++;
                                                if( W_num>=4 )
                                                {
                                                      break;
                                                }
                                          }
                                    }
                              }
                        }
                        
                        if( R_down_cross[0]==-1 )
                        {
                              int16 up_edge[2]={-1,-1};
                              for(  W_num_row=R_up_cross[0]-2 ; W_num_row>=R_up_cross[0]-4 ; W_num_row--  )  //ѡȡ���ʵ����¹յ�
                              {
                                    if( W_num_row<ROW_START )
                                    {
                                          break;
                                    }
                                    if( right_edge[W_num_row]!=-1 )
                                    {
                                          up_edge[0]=W_num_row;
                                          
                                          up_edge[1]=right_edge[W_num_row];
                                          
                                          break;
                                    }
                              }
                              if( up_edge[0]==-1 )
                              {
                                    up_edge[0]=R_up_cross[0];
                                    up_edge[1]=R_up_cross[1];
                              }
                              
                              double x=0.0,y=0.0,x1,y1,k=0.0,a;
                              Site_xy xy1,xy2;
                              Site_xy1 xy3;
                              
                              xy1=get_inv_img( up_edge[0] , up_edge[1] );    //��ȡ�յ���͸������
                              
                              a=xy1.x+50;
                              xy3=get_invinv_img( a , 0 );
                              if( up_edge[0]-xy3.x>15 )
                              {
                                    W_num_row=15;
                              }
                              else
                              {
                                    if( up_edge[0]-xy3.x<3 )
                                    {
                                          W_num_row=3;
                                    }
                                    else
                                    {
                                          W_num_row=abs(up_edge[0]-xy3.x);
                                    }
                              }
                              
                              for( W_num=1 ; W_num<=W_num_row ; W_num++ )   //��ȡ�յ����µ����б��
                              {
                                    W_num_col=up_edge[0]-W_num;
                                    if( W_num_col<ROW_START )
                                    {
                                          break;
                                    }
                                    if( right_edge[W_num_col]!=-1 )
                                    {
                                          xy2=get_inv_img( W_num_col , right_edge[W_num_col] );
                                          x1=xy2.x-xy1.x;
                                          y1=xy2.y-xy1.y;
                                          x=x+x1*y1;
                                          y=y+x1*x1;
                                    }
                                    else
                                    {
                                          break;
                                    }
                              }
                              if( x!=0 )
                              {
                                    k=(-1)*x/y;    //�õ��յ����µ����б��
                              }
                              else
                              {
                                    k==0;
                              }
                              cross_wide=k;        //ȡ�������б��
                              
                              cross_edge=up_edge[1];
                              for( cross_row=up_edge[0]+1 ; cross_row<=ROW_END ; cross_row++ )
                              {
                                    a=xy1.y+cross_wide*fabsf(inv_distance[cross_row]-xy1.x);
                                    xy3=get_invinv_img( inv_distance[cross_row] , a );
                                    if( xy3.y>COL_END )
                                    {
                                          break;
                                    }
                                    
                                    right_edge[cross_row]=xy3.y;
                                    R_EDGE_NUM++;
                              }
                        }
                        else
                        {
                              int16 up_edge[2]={-1,-1};
                              for(  W_num_row=R_up_cross[0]-2 ; W_num_row>=R_up_cross[0]-4 ; W_num_row--  )  //ѡȡ���ʵ����¹յ�
                              {
                                    if( W_num_row<ROW_START )
                                    {
                                          break;
                                    }
                                    if( right_edge[W_num_row]!=-1 )
                                    {
                                          up_edge[0]=W_num_row;
                                          
                                          up_edge[1]=right_edge[W_num_row];
                                          
                                          break;
                                    }
                              }
                              if( up_edge[0]==-1 )
                              {
                                    up_edge[0]=R_up_cross[0];
                                    up_edge[1]=R_up_cross[1];
                              }
                              
                              cross_high=R_down_cross[0]-up_edge[0];
                              cross_wide=up_edge[1]-right_edge[R_down_cross[0]];
                              cross_wide=cross_wide/cross_high;
                              cross_edge=right_edge[R_down_cross[0]];
                              for( cross_row=R_down_cross[0]-1 ; cross_row>up_edge[0] ; cross_row-- )
                              {
                                    cross_edge=cross_edge+cross_wide;
                                    cross_col=round(cross_edge);
                                    right_edge[cross_row]=cross_col;
                                    R_EDGE_NUM++;
                              }
                        }
                  }
            }
      }
}

/***********************************************************************************************************************************/

void edge_error_process()           //�˺���Ϊ���ش���������������ͨ����������أ��������ҹգ�ʶ��S�䣩
{
      /*�ϰ��ﴦ��*/
      if( L_barrier_down_row==-1 || L_barrier_up_row==-1 || fabsf(inv_distance[L_barrier_down_row]-inv_distance[L_barrier_up_row])>180 )
      {
            L_barrier_flag=0;
      }
      if( R_barrier_down_row==-1 || R_barrier_up_row==-1 || fabsf(inv_distance[R_barrier_down_row]-inv_distance[R_barrier_up_row])>180 )
      {
            R_barrier_flag=0;
      }
      if( L_TURN==1 && R_end_row!=-1 )
      {
            if( L_barrier_flag==1 )
            {
                  if( L_barrier_down_row!=-1 )
                  {
                        if( fabsf(inv_distance[L_barrier_down_row]-inv_distance[R_end_row])<400 )
                        {
                              L_barrier_flag=0;
                        }
                  }
            }
            if( R_barrier_flag==1 )
            {
                  if( R_barrier_down_row!=-1 )
                  {
                        if( fabsf(inv_distance[R_barrier_down_row]-inv_distance[R_end_row])<400 )
                        {
                              R_barrier_flag=0;
                        }
                  }
            }
      }
      else
      {
            if( R_TURN==1 && L_end_row!=-1 )
            {
                  if( L_barrier_flag==1 )
                  {
                        if( L_barrier_down_row!=-1 )
                        {
                              if( fabsf(inv_distance[L_barrier_down_row]-inv_distance[L_end_row])<400 )
                              {
                                    L_barrier_flag=0;
                              }
                        }
                  }
                  if( R_barrier_flag==1 )
                  {
                        if( R_barrier_down_row!=-1 )
                        {
                              if( fabsf(inv_distance[R_barrier_down_row]-inv_distance[L_end_row])<400 )
                              {
                                      R_barrier_flag=0;
                              }
                        }
                  }
            }
      }
      
      if( LOOP_TEMP==0 && L_barrier_flag==0 && R_barrier_flag==0 )
      {
            int16 row_1=-1,row_2=-1,x=-1;
            /*����Ϊ��������س���*/
            for( W_num_row=ROW_END ; W_num_row>=ROW_START ; W_num_row-- )  //��ʼ���������ز�����
            {
                  if( left_edge[W_num_row]==-1 )
                  {
                        row_1=W_num_row;
                        break;
                  }
            }
            for( W_num_row=row_1 ; W_num_row>=ROW_START ; W_num_row-- )   //�ӵ�һ�����������ؿ�ʼ����
            {
                  if( left_edge[W_num_row]!=-1 )  //�ҵ�����������ʼ��
                  {
                        row_1=W_num_row;
                        row_2=W_num_row;
                        for( W_num_row=row_1-1 ; W_num_row>=ROW_START ; W_num_row-- )
                        {
                              if( W_num_row==ROW_START )
                              {
                                    if( row_2==row_1 )
                                    {
                                          row_2=ROW_START;
                                          break;
                                    }
                              }
                              else
                              {
                                    if( left_edge[W_num_row]==-1 )  //�ҵ���������������
                                    {
                                          row_2=W_num_row;
                                          break;
                                    }
                              }
                        }
                        if( row_1-row_2<=4 )   //����������̫�̣�ֱ��ȥ��
                        {
                              for( x=row_1 ; x>row_2 ; x-- )
                              {
                                    left_edge[x]=-1;
                                    L_EDGE_NUM--;
                              }
                        }
                        else   //�����������㹻�����ж�ȥ�����
                        {
                              W_num=0;
                              for( x=row_1-6 ; x>row_1-10 ; x-- )
                              {
                                    if( x<=row_2 )
                                    {
                                          break;
                                    }
                                    if( abs(left_edge[x-1]-left_edge[x])<=2 )
                                    {
                                          W_num++;
                                    }
                              }
                              if( W_num>=3 )
                              {
                                    for( x=row_1 ; x>row_2 ; x-- )
                                    {
                                          if( abs(left_edge[x-1]-left_edge[x])>=4 )
                                          {
                                                left_edge[x]=-1;
                                                L_EDGE_NUM--;
                                          }
                                          else
                                          {
                                                break;
                                          }
                                    }
                              }
                        }
                  }
            }
            
            /*����Ϊ�����ұ��س���*/
            for( W_num_row=ROW_END ; W_num_row>=ROW_START ; W_num_row-- )  //��ʼ���������ز�����
            {
                  if( right_edge[W_num_row]==-1 )
                  {
                        row_1=W_num_row;
                        break;
                  }
            }
            for( W_num_row=row_1 ; W_num_row>=ROW_START ; W_num_row-- )   //�ӵ�һ�����������ؿ�ʼ����
            {
                  if( right_edge[W_num_row]!=-1 )  //�ҵ�����������ʼ��
                  {
                        row_1=W_num_row;
                        row_2=W_num_row;
                        for( W_num_row=row_1-1 ; W_num_row>=ROW_START ; W_num_row-- )
                        {
                              if( W_num_row==ROW_START )
                              {
                                    if( row_2==row_1 )
                                    {
                                          row_2=ROW_START;
                                          break;
                                    }
                              }
                              else
                              {
                                    if( right_edge[W_num_row]==-1 )  //�ҵ���������������
                                    {
                                          row_2=W_num_row;
                                          break;
                                    }
                              }
                        }
                        if( row_1-row_2<=4 )   //����������̫�̣�ֱ��ȥ��
                        {
                              for( x=row_1 ; x>row_2 ; x-- )
                              {
                                    right_edge[x]=-1;
                                    R_EDGE_NUM--;
                              }
                        }
                        else   //�����������㹻�����ж�ȥ�����
                        {
                              W_num=0;
                              for( x=row_1-6 ; x>row_1-10 ; x-- )
                              {
                                    if( x<=row_2 )
                                    {
                                          break;
                                    }
                                    if( abs(right_edge[x-1]-right_edge[x])<=2 )
                                    {
                                          W_num++;
                                    }
                              }
                              if( W_num>=3 )
                              {
                                    for( x=row_1 ; x>row_2 ; x-- )
                                    {
                                          if( abs(right_edge[x-1]-right_edge[x])>=4 )
                                          {
                                                right_edge[x]=-1;
                                                R_EDGE_NUM--;
                                          }
                                          else
                                          {
                                                break;
                                          }
                                    }
                              }
                        }
                  }
            }
            
            
            /*����Ϊ����ת�������*/
            
            if( L_cross_flag==0 && R_cross_flag==0 && cross_flag==0 && up_flag==0 && down_flag==0 )   //δʶ��ʮ�֣��ϰ����µ�������S��ʶ��
            {
                  if( L_s_temp==1 || R_s_temp==1 )    //ʶ���S��
                  {
                        if( L_s_temp==1 )  //�����ʶ���S��
                        {
                              W_num=0;
                              for( EXTRACT_ROW=ROW_END ; EXTRACT_ROW>=ROW_START ; EXTRACT_ROW-- )      //�����쳣����
                              {
                                    if( left_edge[EXTRACT_ROW]!=-1 )
                                    {
                                          if( s_curve_row==-1 )
                                          {
                                                s_curve_row=EXTRACT_ROW;
                                                W_num=0;
                                          }
                                          else
                                          {
                                                if( left_edge[EXTRACT_ROW]>=left_edge[s_curve_row] )
                                                {
                                                      s_curve_row=EXTRACT_ROW;
                                                      W_num=0;
                                                }
                                                else
                                                {
                                                      W_num++;
                                                }
                                          }
                                    }
                                    if( W_num>=5 )
                                    {
                                          break;
                                    }
                              }
                              if( s_curve_row!=-1 )
                              {
                                    L_s_row=s_curve_row;
                              }
                        }
                        else
                        {
                              if( R_s_temp==1 )  //�ұ���ʶ���S��
                              {
                                    W_num=0;
                                    for( EXTRACT_ROW=ROW_END ; EXTRACT_ROW>=ROW_START ; EXTRACT_ROW-- )      //�����쳣����
                                    {
                                          if( right_edge[EXTRACT_ROW]!=-1 )
                                          {
                                                if( s_curve_row==-1 )
                                                {
                                                      s_curve_row=EXTRACT_ROW;
                                                      W_num=0;
                                                }
                                                else
                                                {
                                                      if( right_edge[EXTRACT_ROW]<=right_edge[s_curve_row] )
                                                      {
                                                            s_curve_row=EXTRACT_ROW;
                                                            W_num=0;
                                                      }
                                                      else
                                                      {
                                                            W_num++;
                                                      }
                                                }
                                          }
                                          if( W_num>=5 )
                                          {
                                                break;
                                          }
                                    }
                                    if( s_curve_row!=-1 )
                                    {
                                          R_s_row=s_curve_row;
                                    }
                              }
                        }
                  }
                  else    //δʶ���S��
                  {
                        if( L_TURN==1 && R_TURN==0 && R_end_row!=-1 )    //����������������ʶ��S��
                        {
                              W_num=0;
                              for( EXTRACT_ROW=ROW_END ; EXTRACT_ROW>=R_end_row ; EXTRACT_ROW-- )      //�����쳣����
                              {
                                    if( left_edge[EXTRACT_ROW]!=-1 )
                                    {
                                          if( s_curve_row==-1 )
                                          {
                                                s_curve_row=EXTRACT_ROW;
                                                W_num=0;
                                          }
                                          else
                                          {
                                                if( left_edge[EXTRACT_ROW]>=left_edge[s_curve_row] )
                                                {
                                                      s_curve_row=EXTRACT_ROW;
                                                      W_num=0;
                                                }
                                                else
                                                {
                                                      W_num++;
                                                }
                                          }
                                    }
                                    else
                                    {
                                          if( s_curve_row!=-1 )
                                          {
                                                W_num++;
                                          }
                                    }
                                    if( W_num>=5 )
                                    {
                                          break;
                                    }
                              }
                              if( s_curve_row!=-1 && left_edge[s_curve_row]>=80 )
                              {
                                    S_FLAG=1;
                                    L_s_temp=1;
                                    L_s_row=s_curve_row;
                              }
                        }
                        else
                        {
                              if( L_TURN==0 && R_TURN==1 && L_end_row!=-1 )    //����������������ʶ��S��
                              {
                                    W_num=0;
                                    for( EXTRACT_ROW=ROW_END ; EXTRACT_ROW>=L_end_row ; EXTRACT_ROW-- )      //�����쳣����
                                    {
                                          if( right_edge[EXTRACT_ROW]!=-1 )
                                          {
                                                if( s_curve_row==-1 )
                                                {
                                                      s_curve_row=EXTRACT_ROW;
                                                      W_num=0;
                                                }
                                                else
                                                {
                                                      if( right_edge[EXTRACT_ROW]<=right_edge[s_curve_row] )
                                                      {
                                                            s_curve_row=EXTRACT_ROW;
                                                            W_num=0;
                                                      }
                                                      else
                                                      {
                                                            W_num++;
                                                      }
                                                }
                                          }
                                          else
                                          {
                                                if( s_curve_row!=-1 )
                                                {
                                                      W_num++;
                                                }
                                          }
                                          if( W_num>=5 )
                                          {
                                                break;
                                          }
                                    }
                                    if( s_curve_row!=-1 && right_edge[s_curve_row]<=80 )
                                    {
                                          S_FLAG=1;
                                          R_s_temp=1;
                                          R_s_row=s_curve_row;
                                    }
                              }
                              else    //ʶ��S��
                              {
                                    int16 s_row=-1;
                                    if( L_EDGE_NUM>R_EDGE_NUM+5 )
                                    {
                                          W_num=0;
                                          for( EXTRACT_ROW=ROW_END ; EXTRACT_ROW>=ROW_START ; EXTRACT_ROW-- )      //�����쳣����
                                          {
                                                if( left_edge[EXTRACT_ROW]!=-1 )
                                                {
                                                      if( s_row==-1 )
                                                      {
                                                            s_row=EXTRACT_ROW;
                                                            W_num=0;
                                                      }
                                                      else
                                                      {
                                                            if( left_edge[EXTRACT_ROW]>=left_edge[s_row] )
                                                            {
                                                                  s_row=EXTRACT_ROW;
                                                                  W_num=0;
                                                            }
                                                            else
                                                            {
                                                                  W_num++;
                                                            }
                                                      }
                                                }
                                                if( W_num>=5 )
                                                {
                                                      s_curve_row=s_row;
                                                      break;
                                                }
                                          }
                                          if( s_curve_row!=-1 && left_edge[s_curve_row]>=80 )
                                          {
                                                S_FLAG=1;
                                                L_s_temp=1;
                                                L_s_row=s_curve_row;
                                          }
                                    }
                                    else
                                    {
                                          if( R_EDGE_NUM>L_EDGE_NUM+5 )
                                          {
                                                W_num=0;
                                                for( EXTRACT_ROW=ROW_END ; EXTRACT_ROW>=ROW_START ; EXTRACT_ROW-- )      //�����쳣����
                                                {
                                                      if( right_edge[EXTRACT_ROW]!=-1 )
                                                      {
                                                            if( s_row==-1 )
                                                            {
                                                                  s_row=EXTRACT_ROW;
                                                                  W_num=0;
                                                            }
                                                            else
                                                            {
                                                                  if( right_edge[EXTRACT_ROW]<=right_edge[s_row] )
                                                                  {
                                                                        s_row=EXTRACT_ROW;
                                                                        W_num=0;
                                                                  }
                                                                  else
                                                                  {
                                                                        W_num++;
                                                                  }
                                                            }
                                                      }
                                                      if( W_num>=5 )
                                                      {
                                                            s_curve_row=s_row;
                                                            break;
                                                      }
                                                }
                                                if( s_curve_row!=-1 && right_edge[s_curve_row]<=80 )
                                                {
                                                      S_FLAG=1;
                                                      R_s_temp=1;
                                                      R_s_row=s_curve_row;
                                                }
                                          }
                                    }
                              }
                        }
                  }
                  
                  if( L_s_temp==1 )   //�����ʶ���S��
                  {
                        if( L_s_row!=-1 )
                        {
                              Site_xy s_xy;
                              s_xy=get_inv_img( L_s_row , left_edge[L_s_row] );
                              s_down_dis=s_xy.x;
                              if( s_xy.x<100 )
                              {
                                    L_s_temp=0;
                              }
                              L_s_row=-1;
                        }
                        else
                        {
                              L_s_temp=0;
                        }
                  }
                  else
                  {
                        if( R_s_temp==1 )   //�ұ���ʶ���S��
                        {
                              if( R_s_row!=-1 )
                              {
                                    Site_xy s_xy;
                                    s_xy=get_inv_img( R_s_row , right_edge[R_s_row] );
                                    s_down_dis=s_xy.x;
                                    if( s_xy.x<100 )
                                    {
                                          R_s_temp=0;
                                    }
                                    R_s_row=-1;
                              }
                              else
                              {
                                    R_s_temp=0;
                              }
                        }
                  }
                  
                  
                  if( L_TURN==0 && R_TURN==0 )
                  {
                        if( L_EDGE_NUM-R_EDGE_NUM>=15 )
                        {
                              R_TURN=1;
                        }
                        if( R_EDGE_NUM-L_EDGE_NUM>=15 )
                        {
                              L_TURN=1;
                        }
                  }
                  
                  if( L_s_temp==0 && R_s_temp==0 )    //�������ǰ����������������
                  {
                        if( R_TURN==1 )
                        {
                              if( L_end_row!=-1 )
                              {
                                    double xx;
                                    Site_xy1 yy;
                                    xx=inv_distance[L_end_row];
                                    xx=xx-curve_div;
                                    yy=get_invinv_img( xx , 0 );
                                    if( yy.x>59 )
                                    {
                                          yy.x=59;
                                    }
                                    
                                    for( EXTRACT_ROW=L_end_row ; EXTRACT_ROW<=yy.x ; EXTRACT_ROW++ )      //ȥ���쳣�ұ���
                                    {
                                          if( right_edge[EXTRACT_ROW]!=-1 )
                                          {
                                                right_edge[EXTRACT_ROW]=-1;
                                                R_EDGE_NUM--;
                                          }
                                    }
                              }
                        }
                        else
                        {
                              if( L_TURN==1 )
                              {
                                    if( R_end_row!=-1 )
                                    {
                                          double xx;
                                          Site_xy1 yy;
                                          xx=inv_distance[R_end_row];
                                          xx=xx-curve_div;
                                          yy=get_invinv_img( xx , 0 );
                                          if( yy.x>59 )
                                          {
                                                yy.x=59;
                                          }
                                          
                                          for( EXTRACT_ROW=R_end_row ; EXTRACT_ROW<=yy.x ; EXTRACT_ROW++ )      //ȥ���쳣�ұ���
                                          {
                                                if( left_edge[EXTRACT_ROW]!=-1 )
                                                {
                                                      left_edge[EXTRACT_ROW]=-1;
                                                      L_EDGE_NUM--;
                                                }
                                          }
                                    }
                              }
                        }
                  }
            }
      }
}

/***********************************************************************************************************************************/

void road_judge()                   //�˺���Ϊ���������жϺ�����ʶ��ֱ�����µ�������ڣ�СS��
{
      if( end_line_row>=30 && END_LINE_FLAG==0 )     //�ж��յ��߶�ʧ
      {
            END_LINE_TEMP_2++;
            if( END_LINE_TEMP_2>=2 )
            {
                  end_line_row=-1;
                  END_LINE_TEMP_2=0;
            }
      }
      if( END_LINE_TEMP==1 )
      {
            if( abs(speedout_val)>end_line_val )
            {
                  END_LINE_TEMP=0;
                  end_line_row=-1;
                  end_line_num++;
                  Bee_flag=1;     //������
            }
      }
      if( RAMP_TEMP==1 )
      {
            Bee_flag=1;     //������
            if( abs(speedout_val)>ramp_val )
            {
                  RAMP_TEMP=0;
            }
      }
      
      if( LOOP_TEMP==0 && L_barrier_flag==0 && R_barrier_flag==0 )       //�������ڻ����������ϰ�
      {
            uint8 xx=0,yy=0;
            for( EXTRACT_ROW=straight_start ; EXTRACT_ROW>=straight_end ; EXTRACT_ROW-- )      //��¼���ұ��ظ���
            {
                  if( left_edge[EXTRACT_ROW]!=-1 )
                  {
                        xx++;
                  }
                  else
                  {
                        xx=0;
                        break;
                  }
                  if( right_edge[EXTRACT_ROW]!=-1 )
                  {
                        yy++;
                  }
                  else
                  {
                        yy=0;
                        break;
                  }
            }
            if( xx!=0 && yy!=0 )    //����ȡ���󲿷����ұ��أ��ж��Ƿ�Ϊֱ��
            {
                  W_num=0;
                  W_num_row=0;
                  W_num_col=0;
                  for( EXTRACT_ROW=straight_start ; EXTRACT_ROW>straight_end ; EXTRACT_ROW-- )      //��¼���ұ���������
                  {
                        if( left_edge[EXTRACT_ROW-1]-left_edge[EXTRACT_ROW]>=0 )
                        {
                              W_num_row++;
                        }
                        else
                        {
                              W_num++;
                        }
                        
                        if( right_edge[EXTRACT_ROW]-right_edge[EXTRACT_ROW-1]>=0 )
                        {
                              W_num_col++;
                        }
                        else
                        {
                              W_num++;
                        }
                  }
                  if( W_num_row>=straight_start-straight_end-3 && W_num_col>=straight_start-straight_end-3 && W_num<=3 )   //�����ұ������������ڷ�ֵ���ж�Ϊֱ��
                  {
                        STRAIGHT_FLAG=1;    //ֱ����־��  1
                  }
            }
            if( L_cross_flag==0 && R_cross_flag==0 && cross_flag==0 && up_enable_flag==1 )   //�ж��Ƿ�Ϊ�µ�
            {
                  uint8 xx=0,yy=0;
                  for( EXTRACT_ROW=ROW_END ; EXTRACT_ROW>=ROW_START ; EXTRACT_ROW-- )      //��¼���ұ��ظ���
                  {
                        if( left_edge[EXTRACT_ROW]!=-1 )
                        {
                              xx++;
                        }
                        if( right_edge[EXTRACT_ROW]!=-1 )
                        {
                              yy++;
                        }
                  }
                  if( xx+yy>=90 )
                  {
                        W_num_row=0;
                        W_num_col=0;
                        
                        W_num=-1;
                        for( EXTRACT_ROW=ROW_END ; EXTRACT_ROW>=ROW_START+1 ; EXTRACT_ROW-- )      //��¼���ұ���������
                        {
                              if( left_edge[EXTRACT_ROW]!=-1 && left_edge[EXTRACT_ROW-1]!=-1 )
                              {
                                    W_num=EXTRACT_ROW;
                                    break;
                              }
                        }
                        if( W_num!=-1 )
                        {
                              for( EXTRACT_ROW=W_num ; EXTRACT_ROW>=ROW_START+1 ; EXTRACT_ROW-- )      //��¼���ұ���������
                              {
                                    if( left_edge[EXTRACT_ROW-1]!=-1 )
                                    {
                                          if( left_edge[EXTRACT_ROW-1]<left_edge[EXTRACT_ROW] )
                                          {
                                                W_num_row++;
                                          }
                                    }
                                    else
                                    {
                                          W_num_col=10;
                                          break;
                                    }
                              }
                        }
                        W_num=-1;
                        for( EXTRACT_ROW=ROW_END ; EXTRACT_ROW>=ROW_START+1 ; EXTRACT_ROW-- )      //��¼���ұ���������
                        {
                              if( right_edge[EXTRACT_ROW]!=-1 && right_edge[EXTRACT_ROW-1]!=-1 )
                              {
                                    W_num=EXTRACT_ROW;
                                    break;
                              }
                        }
                        if( W_num!=-1 )
                        {
                              for( EXTRACT_ROW=W_num ; EXTRACT_ROW>=ROW_START+1 ; EXTRACT_ROW-- )      //��¼���ұ���������
                              {
                                    if( right_edge[EXTRACT_ROW-1]!=-1 )
                                    {
                                          if( right_edge[EXTRACT_ROW-1]>right_edge[EXTRACT_ROW] )
                                          {
                                                W_num_col++;
                                          }
                                    }
                                    else
                                    {
                                          W_num_col=10;
                                          break;
                                    }
                              }
                        }
                        if( W_num_row<=3 && W_num_col<=3 )   //��ʶ���ֱ�����ж��Ƿ�Ϊ�µ�
                        {
                              int16 aa;
                              W_num=0;
                              
                              for( EXTRACT_ROW=ROW_START ; EXTRACT_ROW<=ROW_START+20 ; EXTRACT_ROW++ )      //�������أ��ж��Ƿ�Ϊ�µ�
                              {
                                    aa=2.0*bar_range_col[EXTRACT_ROW]+17-EXTRACT_ROW/4;
                                    if( abs(left_edge[EXTRACT_ROW]-right_edge[EXTRACT_ROW])>=aa )
                                    {
                                          W_num++;
                                    }
                              }
                              if( W_num>=7 )    //�ж�Ϊ�µ�
                              {
                                    RAMP_TEMP=1;
                                    ramp_val=abs(speedout_val)+4000;
                              }
                        }
                  }
            }
            
            if( STRAIGHT_FLAG==0 )    //����Ϊֱ��������������
            {
                  if( L_TURN==1 )
                  {
                        W_num=0;
                        for( W_num_row=ROW_END ; W_num_row>=10 ; W_num_row-- )
                        {
                              if( left_edge[W_num_row]!=-1 )
                              {
                                    W_num=0;
                                    if( curve_in_row==-1 )
                                    {
                                          curve_in_row=W_num_row;
                                    }
                                    else
                                    {
                                          if( left_edge[W_num_row]>=left_edge[curve_in_row] )
                                          {
                                                curve_in_row=W_num_row;
                                          }
                                    }
                              }
                              else
                              {
                                    W_num++;
                              }
                              if( W_num>=10 )
                              {
                                    break;
                              }
                        }
                  }
                  else
                  {
                        if( R_TURN==1 )
                        {
                              W_num=0;
                              for( W_num_row=ROW_END ; W_num_row>=10 ; W_num_row-- )
                              {
                                    if( right_edge[W_num_row]!=-1 )
                                    {
                                          W_num=0;
                                          if( curve_in_row==-1 )
                                          {
                                                curve_in_row=W_num_row;
                                          }
                                          else
                                          {
                                                if( right_edge[W_num_row]<=right_edge[curve_in_row] )
                                                {
                                                      curve_in_row=W_num_row;
                                                }
                                          }
                                    }
                                    else
                                    {
                                          W_num++;
                                    }
                                    if( W_num>=10 )
                                    {
                                          break;
                                    }
                              }
                        }
                  }
            }
      }
}

/***********************************************************************************************************************************/

void bar_process()                  //�˺���Ϊ�ϰ�����ز��亯��
{
      if( L_cross_flag==1 || R_cross_flag==1 || cross_flag==1 || up_flag==1 )   //�жϳ�ʮ�ֻ��µ�ȡ���ϰ��ﴦ��
      {
            L_barrier_flag=0;
            R_barrier_flag=0;
      }
      
      /*���³����Ϊ�ϰ��ﲹ�߳���*/
      
      int16 up=-1,down=-1;  //���ж����ϰ���
      
      if( L_barrier_flag==1 )
      {
            int16 x;
            x=(L_barrier_down_row+L_barrier_up_row)/2;
            for( W_num_row=L_barrier_down_row ; W_num_row>=L_barrier_up_row ; W_num_row-- )
            {
                  if( left_edge[W_num_row]!=-1 )
                  {
                        left_edge[W_num_row]=left_edge[W_num_row]+other4_e*bar_range_col[W_num_row];
                        if( left_edge[W_num_row]>COL_END )
                        {
                              left_edge[W_num_row]=COL_END;
                        }
                  }
            }
            
            if( L_barrier_down_row!=-1 )
            {
                  down=L_barrier_down_row;
                  for( W_num_row=L_barrier_down_row+5 ; W_num_row<=ROW_END-1 ; W_num_row++ )
                  {
                        if( left_edge[W_num_row]!=-1 )
                        {
                              down=W_num_row;
                              if( left_edge[W_num_row+1]==-1 || abs(left_edge[W_num_row]-left_edge[W_num_row+1])>=5 )
                              {
                                    break;
                              }
                        }
                  }
                  cross_high=down-L_barrier_down_row;
                  cross_wide=left_edge[down]-left_edge[L_barrier_down_row];
                  cross_wide=cross_wide/cross_high;   //Ϊ��ֵ
                  cross_edge=left_edge[L_barrier_down_row];
                  for( cross_row=L_barrier_down_row+1 ; cross_row<down ; cross_row++ )
                  {
                        cross_edge=cross_edge+cross_wide;
                        cross_col=round(cross_edge);
                        left_edge[cross_row]=cross_col;
                  }
            }
            if( L_barrier_up_row!=-1 )
            {
                  up=L_barrier_up_row;
                  for( W_num_row=L_barrier_up_row-5 ; W_num_row>=ROW_START+1 ; W_num_row-- )
                  {
                        if( left_edge[W_num_row]!=-1 )
                        {
                              up=W_num_row;
                              if( left_edge[W_num_row-1]==-1 || abs(left_edge[W_num_row]-left_edge[W_num_row-1])>=5 )
                              {
                                    break;
                              }
                        }
                  }
                  cross_wide=0;
                  for( W_num_row=L_barrier_up_row ; W_num_row<=L_barrier_up_row+5 ; W_num_row++ )
                  {
                        if( left_edge[W_num_row]!=-1 && right_edge[W_num_row]!=-1 )
                        {
                              cross_wide=1.0-1.0*abs(left_edge[W_num_row]-left_edge[W_num_row])/(2.0*bar_range_col[W_num_row]);
                              break;
                        }
                  }
                  if( cross_wide!=0 && cross_wide>0 )
                  {
                        left_edge[up]=left_edge[up]+round(cross_wide*bar_range_col[up]);
                  }
                  
                  cross_high=up-L_barrier_up_row;
                  cross_wide=left_edge[up]-left_edge[L_barrier_up_row];
                  cross_wide=cross_wide/cross_high;   //Ϊ��ֵ
                  cross_edge=left_edge[L_barrier_up_row];
                  for( cross_row=L_barrier_up_row-1 ; cross_row>up ; cross_row-- )
                  {
                        cross_edge=cross_edge-cross_wide;
                        cross_col=round(cross_edge);
                        left_edge[cross_row]=cross_col;
                  }
            }
      }
      else
      {
            if( R_barrier_flag==1 )
            {
                  int16 x;
                  x=(R_barrier_down_row+R_barrier_up_row)/2;
                  for( W_num_row=R_barrier_down_row ; W_num_row>=R_barrier_up_row ; W_num_row-- )
                  {
                        if( right_edge[W_num_row]!=-1 )
                        {
                              right_edge[W_num_row]=right_edge[W_num_row]-other4_f*bar_range_col[W_num_row];
                              if( right_edge[W_num_row]<COL_START )
                              {
                                    right_edge[W_num_row]=COL_START;
                              }
                        }
                  }
                  if( R_barrier_down_row!=-1 )
                  {
                        down=R_barrier_down_row;
                        for( W_num_row=R_barrier_down_row+5 ; W_num_row<=ROW_END-1 ; W_num_row++ )
                        {
                              if( right_edge[W_num_row]!=-1 )
                              {
                                    down=W_num_row;
                                    if( right_edge[W_num_row+1]==-1 || abs(right_edge[W_num_row]-right_edge[W_num_row+1])>=5 )
                                    {
                                          break;
                                    }
                              }
                        }
                        cross_high=down-R_barrier_down_row;
                        cross_wide=right_edge[down]-right_edge[R_barrier_down_row];
                        cross_wide=cross_wide/cross_high;   //Ϊ��ֵ
                        cross_edge=right_edge[R_barrier_down_row];
                        for( cross_row=R_barrier_down_row+1 ; cross_row<down ; cross_row++ )
                        {
                              cross_edge=cross_edge+cross_wide;
                              cross_col=round(cross_edge);
                              right_edge[cross_row]=cross_col;
                        }
                  }
                  if( R_barrier_up_row!=-1 )
                  {
                        up=R_barrier_up_row;
                        for( W_num_row=R_barrier_up_row-5 ; W_num_row>=ROW_START+1 ; W_num_row-- )
                        {
                              if( right_edge[W_num_row]!=-1 )
                              {
                                    up=W_num_row;
                                    if( right_edge[W_num_row-1]==-1 || abs(right_edge[W_num_row]-right_edge[W_num_row-1])>=5 )
                                    {
                                          break;
                                    }
                              }
                        }
                        cross_wide=0;
                        for( W_num_row=R_barrier_up_row ; W_num_row<=R_barrier_up_row+5 ; W_num_row++ )
                        {
                              if( left_edge[W_num_row]!=-1 && right_edge[W_num_row]!=-1 )
                              {
                                    cross_wide=1.0-1.0*abs(left_edge[W_num_row]-left_edge[W_num_row])/(2.0*bar_range_col[W_num_row]);
                                    break;
                              }
                        }
                        if( cross_wide!=0 && cross_wide>0 )
                        {
                              right_edge[up]=right_edge[up]-round(cross_wide*bar_range_col[up]);
                        }
                        
                        cross_high=up-R_barrier_up_row;
                        cross_wide=right_edge[up]-right_edge[R_barrier_up_row];
                        cross_wide=cross_wide/cross_high;   //Ϊ��ֵ
                        cross_edge=right_edge[R_barrier_up_row];
                        for( cross_row=R_barrier_up_row-1 ; cross_row>up ; cross_row-- )
                        {
                              cross_edge=cross_edge-cross_wide;
                              cross_col=round(cross_edge);
                              right_edge[cross_row]=cross_col;
                        }
                  }
            }
      }
}

/***********************************************************************************************************************************/

void road_num()                     //�˺���Ϊ�������ͼ���������ʮ�֣��ϰ��������
{
      if( cross_temp==0 )     //ʮ�ּ�¼����  cross_num
      {
            if( L_down_cross[0]!=-1 || R_down_cross[0]!=-1 )
            {
                  cross_temp_1++;
            }
            else
            {
                  cross_temp_1=0;
            }
            if( cross_temp_1>=2 )
            {
                  cross_temp=1;
                  cross_temp_1=0;
                  
                  if( L_down_cross[0]!=-1 )
                  {
                        cross_down[0]=L_down_cross[0];
                  }
                  else
                  {
                        cross_down[0]=-1;
                  }
                  if( R_down_cross[0]!=-1 )
                  {
                        cross_down[1]=R_down_cross[0];
                  }
                  else
                  {
                        cross_down[1]=-1;
                  }
            }
      }
      else
      {
            if( cross_temp==1 )
            {
                  if( L_up_cross[0]!=-1 )
                  {
                        cross_temp_1++;
                        if( cross_temp_1>=2 )
                        {
                              cross_temp=2;
                              cross_temp_1=0;
                        }
                  }
                  else
                  {
                        if( R_up_cross[0]!=-1 )
                        {
                              cross_temp_1++;
                              if( cross_temp_1>=2 )
                              {
                                    cross_temp=2;
                                    cross_temp_1=0;
                              }
                        }
                        else
                        {
                              if( L_down_cross[0]==-1 && R_down_cross[0]==-1 )
                              {
                                    cross_temp_1++;
                                    if( cross_temp_1>=2 )
                                    {
                                          cross_temp=0;
                                          cross_temp_1=0;
                                    }
                              }
                        }
                  }
            }
            else
            {
                  if( cross_temp==2 )
                  {
                        if( L_up_cross[0]!=-1 && R_up_cross[0]!=-1 )
                        {
                              W_num=0;
                              W_num_col=0;
                              for( W_num_row=ROW_END ; W_num_row>=40 ; W_num_row-- )      //��¼���ұ��ظ���
                              {
                                    if( left_edge[W_num_row]!=-1 )
                                    {
                                          W_num++;
                                    }
                                    if( right_edge[W_num_row]!=-1 )
                                    {
                                          W_num_col++;
                                    }
                              }
                              if( W_num>=15 && W_num_col>=15 )
                              {
                                    cross_temp_1++;
                              }
                              if( cross_temp_1>=2 )
                              {
                                    cross_num++;
                                    cross_temp=3;
                                    cross_temp_1=0;
                                    //Bee_flag=1;     //������
                              }
                        }
                        else
                        {
                              if( L_up_cross[0]==-1 && R_up_cross[0]==-1 )
                              {
                                    cross_temp_1++;
                                    cross_temp=0;
                                    cross_temp_1=0;
                              }
                        }
                  }
                  else
                  {
                        if( cross_temp==3 )
                        {
                              if( inv_distance[L_up_cross[0]]<80 )
                              {
                                    cross_temp_1++;
                              }
                              if( inv_distance[R_up_cross[0]]<80 )
                              {
                                    cross_temp_1++;
                              }
                              if( cross_temp_1>=2 )
                              {
                                    cross_temp=4;
                                    cross_temp_1=0;
                              }
                        }
                        else
                        {
                              if( cross_temp==4 )
                              {
                                    if( L_up_cross[0]==-1 && R_up_cross[0]==-1 )
                                    {
                                          cross_temp_1++;
                                    }
                                    if( cross_temp_1>=3 )
                                    {
                                          cross_temp=0;
                                          cross_temp_1=0;
                                          //Bee_flag=1;     //������
                                    }
                              }
                        }
                  }
            }
      }
      
      if( bar_temp==0 )     //�ϰ����¼����  bar_num
      {
            if( L_barrier_flag==1 )
            {
                  bar_temp_1++;
                  if( bar_temp_1>=3 )
                  {
                        bar_temp=1;
                        bar_row[0]=1;   //��ʾ����ϰ���
                        bar_row[1]=L_barrier_down_row;
                        bar_temp_1=0;
                  }
            }
            else
            {
                  bar_temp_1=0;
            }
            
            if( R_barrier_flag==1 )
            {
                  bar_temp_2++;
                  if( bar_temp_2>=3 )
                  {
                        bar_temp=1;
                        bar_row[0]=2;   //��ʾ�ұ��ϰ���
                        bar_row[1]=R_barrier_down_row;
                        bar_temp_2=0;
                  }
            }
            else
            {
                  bar_temp_2=0;
            }
      }
      else
      {
            if( bar_temp==1 )
            {
                  if( bar_row[0]==1 )
                  {
                        if( L_barrier_flag==1 )
                        {
                              if( inv_distance[bar_row[1]]<80 )
                              {
                                    bar_temp=2;
                                    L_bar_num++;
                                    //Bee_flag=1;     //������
                              }
                              else
                              {
                                    if( L_barrier_down_row>bar_row[1] )
                                    {
                                          bar_row[1]=L_barrier_down_row;
                                    }
                              }
                        }
                        else
                        {
                              bar_temp_1++;
                              if( bar_temp_1>=2 )
                              {
                                    bar_temp=0;
                                    bar_temp_1=0;
                              }
                        }
                  }
                  else
                  {
                        if( bar_row[0]==2 )
                        {
                              if( R_barrier_flag==1 )
                              {
                                    if( inv_distance[bar_row[1]]<80 )
                                    {
                                          bar_temp=2;
                                          R_bar_num++;
                                          //Bee_flag=1;     //������
                                    }
                                    else
                                    {
                                          if( R_barrier_down_row>bar_row[1] )
                                          {
                                                bar_row[1]=R_barrier_down_row;
                                          }
                                    }
                              }
                              else
                              {
                                    bar_temp_2++;
                                    if( bar_temp_2>=2 )
                                    {
                                          bar_temp=0;
                                          bar_temp_2=0;
                                    }
                              }
                        }
                  }
            }
            else
            {
                  if( bar_temp==2 )
                  {
                        if( bar_row[0]==1 )
                        {
                              if( L_barrier_flag==0 )
                              {
                                    bar_temp_1++;
                                    if( bar_temp_1>=3 )
                                    {
                                          bar_temp=0;
                                          bar_temp_1=0;
                                          //Bee_flag=1;     //������
                                    }
                              }
                        }
                        else
                        {
                              if( bar_row[0]==2 )
                              {
                                    if( R_barrier_flag==0 )
                                    {
                                          bar_temp_2++;
                                          if( bar_temp_2>=3 )
                                          {
                                                bar_temp=0;
                                                bar_temp_2=0;
                                                //Bee_flag=1;     //������
                                          }
                                    }
                              }
                        }
                  }
            }
      }
}

/***********************************************************************************************************************************/

void loop_judge()                   //�˺���Ϊ���������жϺ���
{
      if( LOOP_TEMP==0 )       //��δ���ڻ�������
      {
            if( LOOP_FLAG==1 )
            {
                  LOOP_TEMP_1++;
                  //Bee_flag=1;     //������
            }
            else
            {
                  LOOP_TEMP_1=0;
            }
            if( LOOP_TEMP_1>=1 )   //�����жϳ��������ж�Ϊ����
            {
                  LOOP_TEMP=1;
                  Bee_flag=1;     //������
                  loop_val=25*inv_distance[LOOP_IN_ROW]+300+abs(speedout_val);
                  loop_num++;
                  LOOP_TEMP_1=0;
                  LOOP_IN=0;
                  LOOP_OUT=0;
                  out_row[0]=-1;
                  out_row[1]=-1;
                  loop_l_r_flag=loop_LR2_flag;
            }
      }
      else       //�����ڻ�������
      {
            if( LOOP_IN==0 )   //��δ���뻷������ʱ
            {
                  if( LOOP_FLAG==1 )
                  {
                        int32 l_val;
                        
                        l_val=25*inv_distance[LOOP_IN_ROW]+300+abs(speedout_val);
                        if( l_val<loop_val+1000 )
                        {
                              loop_val=l_val;
                        }
                        else
                        {
                              double l_in_row;
                              Site_xy1 xy1;
                              l_in_row=1.0*(loop_val-abs(speedout_val)-300)/25;
                              xy1=get_invinv_img(l_in_row,0);
                              LOOP_IN_ROW=xy1.x;
                              if( LOOP_IN_ROW>59 )
                              {
                                    LOOP_IN_ROW=59;
                              }
                        }
                  }
                  else
                  {
                        double l_in_row;
                        Site_xy1 xy1;
                        l_in_row=1.0*(loop_val-abs(speedout_val)-300)/25;
                        xy1=get_invinv_img(l_in_row,0);
                        LOOP_IN_ROW=xy1.x;
                        if( LOOP_IN_ROW>59 )
                        {
                              LOOP_IN_ROW=59;
                        }
                  }
                  //angle_aaa[0]=loop_val;
                  if( abs(speedout_val)>loop_val )   //����һ�ξ��룬�ж�Ϊ���뻷��
                  {
                        LOOP_IN=1;
                        Bee_flag=1;     //������
                        LOOP_TEMP_1=0;
                        LOOP_IN_1=0;
                        LOOP_OUT_1=0;
                        loop_val=0;
                  }
                  
                  if( loop_l_r_flag==1 )    //������������
                  {
                        int16 row=-1;
                        if( LOOP_IN_ROW<=55 )
                        {
                              row=LOOP_IN_ROW-5;
                        }
                        else
                        {
                              row=50;
                        }
                        W_num_col=-1;
                        
                        for( W_num_row=row ; W_num_row<=ROW_END ; W_num_row++ )
                        {
                              if( left_edge[W_num_row]!=-1 )
                              {
                                    if( W_num_col==-1 )
                                    {
                                          W_num_col=W_num_row;
                                    }
                                    else
                                    {
                                          if( left_edge[W_num_row]>=left_edge[W_num_col] )
                                          {
                                                W_num_col=W_num_row;
                                          }
                                    }
                              }
                        }
                        if( W_num_col==-1 )
                        {
                              for( W_num_row=LOOP_IN_ROW ; W_num_row>=ROW_START ; W_num_row-- )
                              {
                                    if( left_edge[W_num_row]!=-1 )
                                    {
                                          left_edge[W_num_row]=-1;
                                          L_EDGE_NUM--;
                                    }
                              }
                        }
                        else
                        {
                              row=-1;
                              W_num=0;
                              for( W_num_row=W_num_col-1 ; W_num_row>=ROW_START ; W_num_row-- )
                              {
                                    if( left_edge[W_num_row]==-1 )
                                    {
                                          W_num++;
                                          if( W_num>=2 )
                                          {
                                                row=W_num_row;
                                                break;
                                          }
                                    }
                                    else
                                    {
                                          if( left_edge[W_num_row]>=left_edge[W_num_col] )
                                          {
                                                W_num_col=W_num_row;
                                          }
                                    }
                              }
                              if( W_num>=2 )
                              {
                                    for( W_num_row=row-1 ; W_num_row>=ROW_START ; W_num_row-- )
                                    {
                                          if( left_edge[W_num_row]!=-1 && left_edge[W_num_row]>=left_edge[W_num_col] )
                                          {
                                                left_edge[W_num_row]=-1;
                                                L_EDGE_NUM--;
                                          }
                                    }
                              }
                        }
                  }
                  else
                  {
                        if( loop_l_r_flag==0 )    //������������
                        {
                              int16 row=-1;
                              if( LOOP_IN_ROW<=55 )
                              {
                                    row=LOOP_IN_ROW-5;
                              }
                              else
                              {
                                    row=50;
                              }
                              W_num_col=-1;
                              
                              for( W_num_row=row ; W_num_row<=ROW_END ; W_num_row++ )
                              {
                                    if( right_edge[W_num_row]!=-1 )
                                    {
                                          if( W_num_col==-1 )
                                          {
                                                W_num_col=W_num_row;
                                          }
                                          else
                                          {
                                                if( right_edge[W_num_row]<=right_edge[W_num_col] )
                                                {
                                                      W_num_col=W_num_row;
                                                }
                                          }
                                    }
                              }
                              if( W_num_col==-1 )
                              {
                                    for( W_num_row=LOOP_IN_ROW ; W_num_row>=ROW_START ; W_num_row-- )
                                    {
                                          if( right_edge[W_num_row]!=-1 )
                                          {
                                                right_edge[W_num_row]=-1;
                                                R_EDGE_NUM--;
                                          }
                                    }
                              }
                              else
                              {
                                    row=-1;
                                    W_num=0;
                                    for( W_num_row=W_num_col-1 ; W_num_row>=ROW_START ; W_num_row-- )
                                    {
                                          if( right_edge[W_num_row]==-1 )
                                          {
                                                W_num++;
                                                if( W_num>=2 )
                                                {
                                                      row=W_num_row;
                                                      break;
                                                }
                                          }
                                          else
                                          {
                                                if( right_edge[W_num_row]<=right_edge[W_num_col] )
                                                {
                                                      W_num_col=W_num_row;
                                                }
                                          }
                                    }
                                    if( W_num>=2 )
                                    {
                                          for( W_num_row=row-1 ; W_num_row>=ROW_START ; W_num_row-- )
                                          {
                                                if( right_edge[W_num_row]!=-1 && right_edge[W_num_row]<=right_edge[W_num_col] )
                                                {
                                                      right_edge[W_num_row]=-1;
                                                      R_EDGE_NUM--;
                                                }
                                          }
                                    }
                              }
                        }
                  }
            }
            else   //�����뻷������ʱ
            {
                  if( out_row[0]==-1 )  //���ոս��뻷������
                  {
                        int16 out_start;
                        Site_xy1 xy1;
                        xy1=get_invinv_img(80,0);
                        out_start=xy1.x;
                        angle_aaa[0]=0;
                        angle_aaa[1]=0;
                        angle_aaa[2]=0;
                        if( loop_l_r_flag==1 ) //���жϳ���������ת
                        {
                              W_num_col=-1;
                              for( W_num_row=ROW_END ; W_num_row>=loop_out_end+3 ; W_num_row-- )
                              {
                                    if( left_edge[W_num_row]!=-1 && left_edge[W_num_row-1]!=-1 && left_edge[W_num_row-2]!=-1 )
                                    {
                                          W_num_col=W_num_row;
                                          break;
                                    }
                              }
                              if( W_num_col!=-1 )
                              {
                                    W_num=0;
                                    for( W_num_row=W_num_col-1 ; W_num_row>=W_num_col-10 ; W_num_row-- )
                                    {
                                          if( left_edge[W_num_row]!=-1 && left_edge[W_num_row]>=left_edge[W_num_col] && left_edge[W_num_row]<left_edge[W_num_col]+30 )
                                          {
                                                W_num++;
                                          }
                                    }
                                    if( W_num>=5 )
                                    {
                                          LOOP_OUT_ROW=W_num_col;
                                          W_num=0;
                                          for( W_num_row=W_num_col ; W_num_row>=loop_out_end ; W_num_row-- )
                                          {
                                                if( left_edge[W_num_row]!=-1 )
                                                {
                                                      if( left_edge[W_num_row]>=left_edge[LOOP_OUT_ROW] )
                                                      {
                                                            W_num=0;
                                                            LOOP_OUT_ROW=W_num_row;
                                                      }
                                                      else
                                                      {
                                                            W_num++;
                                                            if( W_num>=6 )
                                                            {
                                                                  break;
                                                            }
                                                      }
                                                }
                                                else
                                                {
                                                      W_num++;
                                                      if( W_num>=3 )
                                                      {
                                                            break;
                                                      }
                                                }
                                          }
                                          
                                          if( LOOP_OUT_ROW<out_start )
                                          {
                                                W_num=0;
                                                W_num_col=0;
                                                for( W_num_row=LOOP_OUT_ROW-1 ; W_num_row>=ROW_START ; W_num_row-- )
                                                {
                                                      if( left_edge[W_num_row]!=-1 )
                                                      {
                                                            if( left_edge[W_num_row]<=left_edge[W_num_row+1] )
                                                            {
                                                                  W_num++;
                                                                  if( W_num>=5 )
                                                                  {
                                                                        break;
                                                                  }
                                                            }
                                                      }
                                                      else
                                                      {
                                                            break;
                                                      }
                                                }
                                                for( W_num_row=LOOP_OUT_ROW+1 ; W_num_row<=ROW_END ; W_num_row++ )
                                                {
                                                      if( left_edge[W_num_row]!=-1 )
                                                      {
                                                            if( left_edge[W_num_row]<=left_edge[W_num_row-1] )
                                                            {
                                                                  W_num_col++;
                                                                  if( W_num_col>=8 )
                                                                  {
                                                                        break;
                                                                  }
                                                            }
                                                      }
                                                      else
                                                      {
                                                            break;
                                                      }
                                                }
                                                
                                                if( W_num>=5 && W_num_col>=8 )
                                                {
                                                      out_row[0]=LOOP_OUT_ROW;
                                                      out_row[1]=left_edge[LOOP_OUT_ROW];
                                                      
                                                      Site_xy xy;
                                                      xy=get_inv_img(out_row[0],out_row[1]);
                                                      loop_val=25*sqrt(fabsf(xy.x*xy.x)+fabsf(xy.y*xy.y))+loop_out_l+abs(speedout_val);
                                                }
                                          }
                                    }
                              }
                        }
                        else //���жϳ���������ת
                        {
                              W_num_col=-1;
                              for( W_num_row=ROW_END ; W_num_row>=loop_out_end+3 ; W_num_row-- )
                              {
                                    if( right_edge[W_num_row]!=-1 && right_edge[W_num_row-1]!=-1 && right_edge[W_num_row-2]!=-1 )
                                    {
                                          W_num_col=W_num_row;
                                          break;
                                    }
                              }
                              if( W_num_col!=-1 )
                              {
                                    W_num=0;
                                    for( W_num_row=W_num_col-1 ; W_num_row>=W_num_col-10 ; W_num_row-- )
                                    {
                                          if( right_edge[W_num_row]!=-1 && right_edge[W_num_row]<=right_edge[W_num_col] && right_edge[W_num_row]>right_edge[W_num_col]-30 )
                                          {
                                                W_num++;
                                          }
                                    }
                                    if( W_num>=5 )
                                    {
                                          LOOP_OUT_ROW=W_num_col;
                                          W_num=0;
                                          for( W_num_row=W_num_col ; W_num_row>=loop_out_end ; W_num_row-- )
                                          {
                                                if( right_edge[W_num_row]!=-1 )
                                                {
                                                      if( right_edge[W_num_row]<=right_edge[LOOP_OUT_ROW] )
                                                      {
                                                            W_num=0;
                                                            LOOP_OUT_ROW=W_num_row;
                                                      }
                                                      else
                                                      {
                                                            W_num++;
                                                            if( W_num>=6 )
                                                            {
                                                                  break;
                                                            }
                                                      }
                                                }
                                                else
                                                {
                                                      W_num++;
                                                      if( W_num>=3 )
                                                      {
                                                            break;
                                                      }
                                                }
                                          }
                                          angle_aaa[2]=LOOP_OUT_ROW;
                                          if( LOOP_OUT_ROW<out_start )
                                          {
                                                W_num=0;
                                                W_num_col=0;
                                                for( W_num_row=LOOP_OUT_ROW-1 ; W_num_row>=ROW_START ; W_num_row-- )
                                                {
                                                      if( right_edge[W_num_row]!=-1 )
                                                      {
                                                            if( right_edge[W_num_row]>=right_edge[W_num_row+1] )
                                                            {
                                                                  W_num++;
                                                                  if( W_num>=5 )
                                                                  {
                                                                        break;
                                                                  }
                                                            }
                                                      }
                                                      else
                                                      {
                                                            break;
                                                      }
                                                }
                                                for( W_num_row=LOOP_OUT_ROW+1 ; W_num_row<=ROW_END ; W_num_row++ )
                                                {
                                                      if( right_edge[W_num_row]!=-1 )
                                                      {
                                                            if( right_edge[W_num_row]>=right_edge[W_num_row-1] )
                                                            {
                                                                  W_num_col++;
                                                                  if( W_num_col>=8 )
                                                                  {
                                                                        break;
                                                                  }
                                                            }
                                                      }
                                                      else
                                                      {
                                                            break;
                                                      }
                                                }
                                                angle_aaa[0]=W_num;
                                                angle_aaa[1]=W_num_col;
                                                if( W_num>=5 && W_num_col>=8 )
                                                {
                                                      out_row[0]=LOOP_OUT_ROW;
                                                      out_row[1]=right_edge[LOOP_OUT_ROW];
                                                      
                                                      Site_xy xy;
                                                      xy=get_inv_img(out_row[0],out_row[1]);
                                                      loop_val=25*sqrt(fabsf(xy.x*xy.x)+fabsf(xy.y*xy.y))+loop_out_l+abs(speedout_val);
                                                }
                                          }
                                    }
                              }
                        }
                  }
                  else  //�����뻷������һ��ʱ��
                  {
                        if( out_row[0]+30>ROW_END-4 )
                        {
                              LOOP_IN_1=ROW_END-4;
                        }
                        else
                        {
                              LOOP_IN_1=out_row[0]+30;
                        }
                        LOOP_OUT_ROW=-1;
                        
                        if( inv_distance[out_row[0]]<=120 )   //������С��30����ʱ
                        {
                              if( loop_l_r_flag==1 ) //���жϳ���������ת
                              {
                                    for( W_num_row=LOOP_IN_1 ; W_num_row>=loop_out_end ; W_num_row-- )
                                    {
                                          if( W_num_row<ROW_START+4)
                                          {
                                                break;
                                          }
                                          if( left_edge[W_num_row]!=-1 )
                                          {
                                                if( left_edge[W_num_row+4]!=-1 && left_edge[W_num_row+2]!=-1 )
                                                {
                                                      if( left_edge[W_num_row]>left_edge[W_num_row+4] && left_edge[W_num_row]>left_edge[W_num_row+2] )
                                                      {
                                                            if( left_edge[W_num_row-2]!=-1 )
                                                            {
                                                                  if( left_edge[W_num_row]>left_edge[W_num_row-2] )
                                                                  {
                                                                        if( left_edge[W_num_row-4]!=-1 )
                                                                        {
                                                                              if( left_edge[W_num_row]>left_edge[W_num_row-4] )
                                                                              {
                                                                                    LOOP_OUT_ROW=W_num_row;
                                                                                    break;
                                                                              }
                                                                        }
                                                                        else
                                                                        {
                                                                              if( left_edge[W_num_row]<=60 )
                                                                              {
                                                                                    LOOP_OUT_ROW=W_num_row;
                                                                                    break;
                                                                              }
                                                                        }
                                                                  }
                                                            }
                                                            else
                                                            {
                                                                  if(  left_edge[W_num_row-4]==-1 && left_edge[W_num_row]<=60 )
                                                                  {
                                                                        LOOP_OUT_ROW=W_num_row;
                                                                        break;
                                                                  }
                                                            }
                                                      }
                                                }
                                          }
                                    }
                              }
                              else //���жϳ���������ת
                              {
                                    for( W_num_row=LOOP_IN_1 ; W_num_row>=loop_out_end ; W_num_row-- )
                                    {
                                          if( W_num_row<ROW_START+4)
                                          {
                                                break;
                                          }
                                          if( right_edge[W_num_row]!=-1 )
                                          {
                                                if( right_edge[W_num_row+4]!=-1 && right_edge[W_num_row+2]!=-1 )
                                                {
                                                      if( right_edge[W_num_row]<right_edge[W_num_row+4] && right_edge[W_num_row]<right_edge[W_num_row+2] )
                                                      {
                                                            if( right_edge[W_num_row-2]!=-1 )
                                                            {
                                                                  if( right_edge[W_num_row]<right_edge[W_num_row-2] )
                                                                  {
                                                                        if( right_edge[W_num_row-4]!=-1 )
                                                                        {
                                                                              if( right_edge[W_num_row]<right_edge[W_num_row-4] )
                                                                              {
                                                                                    LOOP_OUT_ROW=W_num_row;
                                                                                    break;
                                                                              }
                                                                        }
                                                                        else
                                                                        {
                                                                              if( right_edge[W_num_row]>=100 )
                                                                              {
                                                                                    LOOP_OUT_ROW=W_num_row;
                                                                                    break;
                                                                              }
                                                                        }
                                                                  }
                                                            }
                                                            else
                                                            {
                                                                  if(  right_edge[W_num_row-4]==-1 && right_edge[W_num_row]>=100 )
                                                                  {
                                                                        LOOP_OUT_ROW=W_num_row;
                                                                        break;
                                                                  }
                                                            }
                                                      }
                                                }
                                          }
                                    }
                              }
                        }
                        else
                        {
                              if( loop_l_r_flag==1 ) //���жϳ���������ת
                              {
                                    for( W_num_row=LOOP_IN_1 ; W_num_row>=loop_out_end ; W_num_row-- )
                                    {
                                          if( W_num_row<ROW_START+4)
                                          {
                                                break;
                                          }
                                          if( left_edge[W_num_row]!=-1 )
                                          {
                                                if( left_edge[W_num_row+4]!=-1 && left_edge[W_num_row+2]!=-1 && left_edge[W_num_row-2]!=-1 && left_edge[W_num_row-4]!=-1 )
                                                {
                                                      if( left_edge[W_num_row]>left_edge[W_num_row+4] && left_edge[W_num_row]>left_edge[W_num_row+2] && left_edge[W_num_row]>left_edge[W_num_row-2] && left_edge[W_num_row]>left_edge[W_num_row-4] )
                                                      {
                                                            LOOP_OUT_ROW=W_num_row;
                                                            break;
                                                      }
                                                }
                                          }
                                    }
                              }
                              else //���жϳ���������ת
                              {
                                    for( W_num_row=LOOP_IN_1 ; W_num_row>=loop_out_end ; W_num_row-- )
                                    {
                                          if( W_num_row<ROW_START+4)
                                          {
                                                break;
                                          }
                                          if( right_edge[W_num_row]!=-1 )
                                          {
                                                if( right_edge[W_num_row+4]!=-1 && right_edge[W_num_row+2]!=-1 && right_edge[W_num_row-2]!=-1 && right_edge[W_num_row-4]!=-1 )
                                                {
                                                      if( right_edge[W_num_row]<right_edge[W_num_row+4] && right_edge[W_num_row]<right_edge[W_num_row+2] && right_edge[W_num_row]<right_edge[W_num_row-2] && right_edge[W_num_row]<right_edge[W_num_row-4] )
                                                      {
                                                            LOOP_OUT_ROW=W_num_row;
                                                            break;
                                                      }
                                                }
                                          }
                                    }
                              }
                        }
                        
                        
                        if( LOOP_OUT_ROW==-1 )   //����������δ�ѵ�������
                        {
                              LOOP_TEMP_1++;
                              if( LOOP_TEMP_1>=4 )
                              {
                                    if( out_row[0]<30 )
                                    {
                                          out_row[0]=-1;
                                          out_row[1]=-1;
                                    }
                                    else
                                    {
                                          if( abs(speedout_val)>loop_val )
                                          {
                                                LOOP_TEMP=0;   //�������������������ж�Ϊ������
                                                LOOP_IN=0;     //�뻷��־��  0
                                                out_row[0]=-1;
                                                out_row[1]=-1;
                                                Bee_flag=1;     //������
                                          }
                                    }
                              }
                              else
                              {
                                    if( abs(speedout_val)>loop_val )
                                    {
                                          LOOP_TEMP=0;   //�������������������ж�Ϊ������
                                          LOOP_IN=0;     //�뻷��־��  0
                                          out_row[0]=-1;
                                          out_row[1]=-1;
                                          Bee_flag=1;     //������
                                    }
                              }
                        }
                        else   //�����������ѵ�������
                        {
                              LOOP_TEMP_1=0;
                              
                              Site_xy xy;
                              int32 l_val,val_add;
                              
                              l_val=loop_val-loop_out_l-abs(speedout_val);
                              if( l_val<3000 )
                              {
                                    val_add=1000;
                              }
                              else
                              {
                                    if( l_val>10000 )
                                    {
                                          val_add=4000;
                                    }
                                    else
                                    {
                                          val_add=1000+3*(l_val-3000)/7;
                                    }
                              }
                              if( loop_l_r_flag==1 )
                              {
                                    xy=get_inv_img(LOOP_OUT_ROW,left_edge[LOOP_OUT_ROW]);
                                    
                                    l_val=25*sqrt(fabsf(xy.x*xy.x)+fabsf(xy.y*xy.y))+loop_out_l+abs(speedout_val);
                                    
                                    if( l_val-loop_val<val_add )   //���������ĳ������������洢��������
                                    {
                                          loop_val=l_val;
                                          out_row[0]=LOOP_OUT_ROW;
                                          out_row[1]=left_edge[LOOP_OUT_ROW];
                                          //Bee_flag=1;     //������
                                    }
                              }
                              else
                              {
                                    xy=get_inv_img(LOOP_OUT_ROW,right_edge[LOOP_OUT_ROW]);
                                    
                                    l_val=25*sqrt(fabsf(xy.x*xy.x)+fabsf(xy.y*xy.y))+loop_out_l+abs(speedout_val);
                                    if( l_val-loop_val<val_add )   //���������ĳ������������洢��������
                                    {
                                          loop_val=l_val;
                                          out_row[0]=LOOP_OUT_ROW;
                                          out_row[1]=right_edge[LOOP_OUT_ROW];
                                    }
                              }
                              
                              if( abs(speedout_val)>loop_val )
                              {
                                    LOOP_TEMP=0;   //�������������������ж�Ϊ������
                                    LOOP_IN=0;     //�뻷��־��  0
                                    out_row[0]=-1;
                                    out_row[1]=-1;
                                    Bee_flag=1;     //������
                              }
                        }
                  }
            }
      }
}

/***********************************************************************************************************************************/

void down_extract()                 //�˺���Ϊ�½�������������
{
      L_LINK_NUM=0;        //������½����ظ�������
      R_LINK_NUM=0;        //�ұ����½����ظ�������
      if( L_search_end==1 || R_search_end==1 )
      {
            if( L_TURN==1 && R_end_row!=-1 )    //��ͼ��Ϊ���䣬������ȡ���ұ��ؽ����У��ұ�����������
            {
                  R_edge_nearest=right_edge[R_end_row]-1;    //������ʼ����λ��
                  for( EXTRACT_ROW=R_end_row ; EXTRACT_ROW<=R_end_row+9 ; EXTRACT_ROW++ )
                  {
                        if( EXTRACT_ROW>ROW_END )
                        {
                              break;
                        }
                        
                        R_get_flag=0;                        //���ұ��������õ���־��0
                        if( img_data[EXTRACT_ROW][R_edge_nearest]==DOT_B )      //������е���һ��Ϊ��ʱ��ֹͣ����
                        {
                              break;
                        }
                        else      //������е���һ�㲻Ϊ��ʱ����ʼ����
                        {
                              for( EXTRACT_COL=R_edge_nearest-1 ; EXTRACT_COL>=COL_START ; EXTRACT_COL-- )
                              {
                                    if( img_data[EXTRACT_ROW][EXTRACT_COL]==DOT_B )       //�����ҵ����кڵ�
                                    {
                                          right_down_edge[R_LINK_NUM]=EXTRACT_COL;        //�洢���б��ص�
                                          
                                          R_LINK_NUM++;                                   //���ص������һ
                                          
                                          R_edge_nearest=EXTRACT_COL;                     //�洢���һ���ұ��ص�������
                                          
                                          R_get_flag=1;                                   //�����ҵ��½����ص�
                                          
                                          break;                                         //������������
                                    }
                              }
                        }
                        if( R_get_flag==0 )      //�������δ�ҵ����ص㣬ֹͣ����
                        {
                              break;
                        }
                  }
                  
                  if( L_end_row!=-1 )    //��ͼ��Ϊ���䣬������ȡ������ؽ����У��������������
                  {
                        L_edge_nearest=left_edge[L_end_row];       //������ʼ����λ��
                        for( EXTRACT_ROW=L_end_row ; EXTRACT_ROW<=L_end_row+9 ; EXTRACT_ROW++ )
                        {
                              if( EXTRACT_ROW>ROW_END )
                              {
                                    break;
                              }
                              
                              L_get_flag=0;                        //������������õ���־��0
                              for( EXTRACT_COL=L_edge_nearest ; EXTRACT_COL>=COL_START+1 ; EXTRACT_COL-- )
                              {
                                    if( img_data[EXTRACT_ROW][EXTRACT_COL-1]==DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL]==DOT_B )       //�����ҵ����кڰ������
                                    {
                                          left_down_edge[L_LINK_NUM]=EXTRACT_COL;         //�洢���б��ص�
                                          
                                          L_LINK_NUM++;                                   //���ص������һ
                                          
                                          L_edge_nearest=EXTRACT_COL-1;                   //�洢���һ������ص�������
                                          
                                          L_get_flag=1;                                   //�����ҵ��½����ص�
                                          
                                          break;                                         //������������
                                    }
                              }
                              if( L_get_flag==0 )      //�������δ�ҵ����ص㣬ֹͣ����
                              {
                                    break;
                              }
                        }
                  }
            }
            
            if( R_TURN==1 && L_end_row!=-1 )    //��ͼ��Ϊ���䣬������ȡ������ؽ����У��������������
            {
                  L_edge_nearest=left_edge[L_end_row]+1;     //������ʼ����λ��
                  for( EXTRACT_ROW=L_end_row ; EXTRACT_ROW<=L_end_row+9 ; EXTRACT_ROW++ )
                  {
                        if( EXTRACT_ROW>ROW_END )
                        {
                              break;
                        }
                        
                        L_get_flag=0;                        //������������õ���־��0
                        if( img_data[EXTRACT_ROW][L_edge_nearest]==DOT_B )      //������е���һ��Ϊ��ʱ��ֹͣ����
                        {
                              break;
                        }
                        else      //������е���һ�㲻Ϊ��ʱ����ʼ����
                        {
                              for( EXTRACT_COL=L_edge_nearest+1 ; EXTRACT_COL<=COL_END ; EXTRACT_COL++ )
                              {
                                    if( img_data[EXTRACT_ROW][EXTRACT_COL]==DOT_B )       //�����ҵ����кڵ�
                                    {
                                          left_down_edge[L_LINK_NUM]=EXTRACT_COL;         //�洢���б��ص�
                                          
                                          L_LINK_NUM++;                                   //���ص������һ
                                          
                                          L_edge_nearest=EXTRACT_COL;                     //�洢���һ������ص�������
                                          
                                          L_get_flag=1;                                   //�����ҵ��½����ص�
                                          
                                          break;                                         //������������
                                    }
                              }
                        }
                        if( L_get_flag==0 )      //�������δ�ҵ����ص㣬ֹͣ����
                        {
                              break;
                        }
                  }
                  
                  if( R_end_row!=-1 )    //��ͼ��Ϊ���䣬������ȡ���ұ��ؽ����У��ұ�����������
                  {
                        R_edge_nearest=right_edge[R_end_row];      //������ʼ����λ��
                        for( EXTRACT_ROW=R_end_row ; EXTRACT_ROW<=R_end_row+9 ; EXTRACT_ROW++ )
                        {
                              if( EXTRACT_ROW>ROW_END )
                              {
                                    break;
                              }
                              
                              R_get_flag=0;                        //���ұ��������õ���־��0
                              for( EXTRACT_COL=R_edge_nearest ; EXTRACT_COL<=COL_END-1 ; EXTRACT_COL++ )
                              {
                                    if( img_data[EXTRACT_ROW][EXTRACT_COL+1]==DOT_W && img_data[EXTRACT_ROW][EXTRACT_COL]==DOT_B )       //�����ҵ����кڰ������
                                    {
                                          right_down_edge[R_LINK_NUM]=EXTRACT_COL;        //�洢���б��ص�
                                          
                                          R_LINK_NUM++;                                   //���ص������һ
                                          
                                          R_edge_nearest=EXTRACT_COL+1;                   //�洢���һ���ұ��ص�������
                                          
                                          R_get_flag=1;                                   //�����ҵ��½����ص�
                                          
                                          break;                                         //������������
                                    }
                              }
                              if( R_get_flag==0 )      //�������δ�ҵ����ص㣬ֹͣ����
                              {
                                    break;
                              }
                        }
                  }
            }
      }
}

/***********************************************************************************************************************************/

void bar_car()                    //�˺���Ϊ�����жϺ���
{
      if( double_car_flag==1 )   //���Ϊ˫��ģʽ
      {
            if( car_over_able==1 )
            {
                  if( car_flag==0 )  //���Ϊǰ��
                  {
                        if( car_over_ok==0 )
                        {
                              W_num=0;
                              for( W_num_row=ROW_END ; W_num_row>=30 ; W_num_row-- )
                              {
                                    if( left_edge[W_num_row]!=-1 && right_edge[W_num_row]!=-1 )       //�����ҵ����кڰ������
                                    {
                                          if( abs(left_edge[W_num_row]-right_edge[W_num_row])<1.5*bar_range_col[W_num_row] )
                                          {
                                                W_num++;
                                          }
                                    }
                              }
                              if( W_num>=10 )
                              {
                                    bar_car_temp_1++;
                                    if( bar_car_temp_1>=3 )
                                    {
                                          bar_car_temp_1=0;
                                          car_over_ok=1;
                                    }
                              }
                              else
                              {
                                    bar_car_temp_1=0;
                              }
                        }
                  }
                  else if( car_flag==1 )  //���Ϊ��
                  {
                        if( car_over_ok==0 )
                        {
                              int16 down_row=-1,up_row=-1,aa=0;
                              W_num=0;
                              for( W_num_row=ROW_END ; W_num_row>=20 ; W_num_row-- )
                              {
                                    if( left_edge[W_num_row]!=-1 && right_edge[W_num_row]!=-1 )       //�����ҵ����кڰ������
                                    {
                                          if( abs(left_edge[W_num_row]-right_edge[W_num_row])<1.5*bar_range_col[W_num_row] )
                                          {
                                                aa=0;
                                                W_num++;
                                                if( down_row==-1 )
                                                {
                                                      down_row=W_num_row;
                                                }
                                                else
                                                {
                                                      up_row=W_num_row;
                                                }
                                          }
                                          else
                                          {
                                                if( W_num>0 )
                                                {
                                                      aa++;
                                                }
                                          }
                                    }
                                    else
                                    {
                                          if( W_num>0 )
                                          {
                                                aa++;
                                          }
                                    }
                                    if( aa>=5 )
                                    {
                                          break;
                                    }
                              }
                              if( W_num>=10 )
                              {
                                    if( bar_car_val==-1 )
                                    {
                                          bar_car_temp_1++;
                                          if( bar_car_temp_1>=2 )
                                          {
                                                bar_car_temp_1=0;
                                                bar_car_val=25*inv_distance[up_row]+abs(speedout_val);
                                          }
                                    }
                                    else
                                    {
                                          if( bar_car_val-abs(speedout_val)>3000 )
                                          {
                                                bar_car_val=25*inv_distance[up_row]+abs(speedout_val);
                                          }
                                          else
                                          {
                                                int32 val_1;
                                                val_1=25*inv_distance[up_row]+abs(speedout_val);
                                                if( val_1<bar_car_val+2000 )
                                                {
                                                      bar_car_val=val_1;
                                                }
                                          }
                                    }
                              }
                              else
                              {
                                    if( bar_car_val==-1 )
                                    {
                                          bar_car_temp_1=0;
                                    }
                              }
                              if( bar_car_val!=-1 )
                              {
                                    if( abs(speedout_val)>bar_car_val )
                                    {
                                          car_over_ok=1;
                                    }
                              }
                        }
                  }
            }
      }
}

/***********************************************************************************************************************************/

void tan_angle()                    //�˺���Ϊб�ʽǶ��Ʊ���
{
      uint8 x;
      for( x=0 ; x<=29 ; x++ )
      {
            tan_table[x]=tan((double)x*PI/60);
      }
}

/***********************************************************************************************************************************/

void bar_range()                    //�˺���Ϊÿ���ϰ���������Χ��ȡ����
{
      uint8 x;
      Site_xy xy_1,xy_2;
      Site_xy1 xy1;
      for( x=ROW_START ; x<=ROW_END ; x++ )
      {
            xy_1=get_inv_img( x , 79 );
            xy_2=get_inv_img( x , 80 );
            inv_distance[x]=(xy_1.x+xy_2.x)/2;
      }
      
      for( x=ROW_START ; x<=ROW_END ; x++ )
      {
            xy1=get_invinv_img( inv_distance[x] , ROAD_WIDE/2 );
            bar_range_col[x]=abs(xy1.y-79.5 );
      }
      
      for( x=ROW_START ; x<=ROW_END ; x++ )
      {
            xy1=get_invinv_img( inv_distance[x] , ROAD_WIDE/4 );
            car_col[x]=abs(xy1.y-79.5 );
      }
}

/***********************************************************************************************************************************/




