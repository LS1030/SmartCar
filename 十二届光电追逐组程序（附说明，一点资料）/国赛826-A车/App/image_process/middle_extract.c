#include "include.h"
#include "common.h"

/***********************************************************************************************************************************/

double wide=180;          //��͸��ͼ��������ȱ���
int16 midlinebu_row=15;    //���߲�������ȱ���

uint8 midline_cnt;         //���߸���
int16 mid_temp_row;        //���ߵ�ǰ������
int16 mid_temp_row;        //���ߵ�ǰ������
int16 mid_down_pot[2];     //��������ͼ�����·��㣨���ڵײ�ͼ�����ߣ�

int16 midline[CAMERA_H];             //ԭʼͼ��������
Site_xy inv_left_edge[CAMERA_H];     //��͸��ͼ���������������
Site_xy inv_right_edge[CAMERA_H];    //��͸��ͼ���ұ�����������
Site_xy inv_midline[CAMERA_H];       //��͸��ͼ��������������

uint8 midline_down_num;                      //������ȡ���ص�ʵ�ʸ���
Site_xy midline_down_inv[MIDDLE_DOWN_NUM];   //������ȡ���ص���͸������
int16 midline_down_x[MIDDLE_DOWN_NUM];       //������ȡ���ص�ԭʼ����
int16 midline_down_y[MIDDLE_DOWN_NUM];       //������ȡ���ص�ԭʼ����

Site_xy1 mid_end;
Site_xy1 mid_end_jizhun;
Site_xy  inv_mid_end;
uint8 mid_end_jizhun_flag;

double  loop_range_col[CAMERA_H];   //�ϰ���������Χ����
/***********************************************************************************************************************************/

void midline_extract();            //��ȡ����������
void midline_search();             //��͸�ӻ�ȡ���ߺ�������С���˷���������ͨ����
void midline_search_over();        //��͸�ӻ�ȡ���ߺ�������С���˷������ڿ���ͣ��
void midline_search_loop();        //��͸�ӻ�ȡ���ߺ�������С���˷������ڻ�������
void midline_bu();                 //���߲��ϵ㺯���������м���ɢ���ߣ�
void midline_bu_end();             //���߲��ϵ㺯�������ڲ����ĩβ���ߣ�

void midline_jizhun_search(int16 i);   //��׼������������
void middle_down();     //��ȡ�������ߺ���
void edge_edge_lvbo();  //�����˲�����
void midline_lvbo();    //�����˲�����

void tingche();         //����ͣ������
void tingche2();        //����ͣ������2

void edge_add();        //������Ӻ���
void midline_add();     //������Ӻ���
void jizhun_add();      //��׼����Ӻ���

void get_inv_edge();    //��ȡ��͸�ӱ������꺯��
void bar_range_loop();
Site_xy get_inv_img(int16 xxx ,int16 yyy);          //��͸�ӣ�xxxΪͼ���У�yyyΪ�У�
Site_xy1 get_invinv_img(double xxx,double yyy);   //����͸�ӣ�xxxΪʵ���У�yyyΪ�У�
/***********************************************************************************************************************************/
void bar_range_loop() 
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
    xy1=get_invinv_img( inv_distance[x] , ROAD_LOOP_WIDE/2 );
    loop_range_col[x]=abs(xy1.y-79.5 );
  }
}
/***********************************************************************************************************************************/

void midline_extract()                //��ȡ����������
{
      midline_cnt=0;        //���߸�����  0
      mid_temp_row=-1;      //���ߵ�ǰ�������������
      mid_down_pot[0]=-1;   //��������ͼ�����·�����  -1
      mid_down_pot[1]=-1;   //��������ͼ�����·�����  -1
      
      if( car_L_pull_over_flag || car_R_pull_over_flag )    //�����ڳ���ʱ
      {
            midline_search_over();
            midline_bu();
      }
      else
      {
            if( LOOP_TEMP )    //�����ڻ�������ʱ
            {
                  int16 i;
                  if( LOOP_IN==0 )  //����δ���뻷��
                  {
                        if( loop_l_r_flag==1 )   //������Ϊ��ת
                        {
                              for( i=ROW_END ; i>=ROW_START ; i-- )
                              {
                                    if( i>=LOOP_IN_ROW )      //����������·�ʱ
                                    {
                                          if( left_edge[i]!=-1 && right_edge[i]!=-1 )
                                          {
                                                midline[i]=(left_edge[i]+right_edge[i])/2;
                                                midline_cnt++;
                                                mid_temp_row=i;
                                          }
                                          else
                                          {
                                                if( left_edge[i]!=-1 )
                                                {
                                                      midline[i]=left_edge[i]+loop_range_col[i];
                                                      if( midline[i]>COL_END )
                                                      {
                                                            midline[i]=COL_END;
                                                      }
                                                      midline_cnt++;
                                                      mid_temp_row=i;
                                                }
                                                else
                                                {
                                                      midline[i]=loop_range_col[i];
                                                      midline_cnt++;
                                                      mid_temp_row=i;
                                                }
                                          }
                                    }
                                    else      //����������Ϸ�ʱ
                                    {
                                          if( left_edge[i]!=-1 )
                                          {
                                                midline[i]=left_edge[i]+loop_in_k*bar_range_col[i];
                                                if( midline[i]>COL_END )
                                                {
                                                      midline[i]=COL_END;
                                                }
                                                midline_cnt++;
                                                mid_temp_row=i;
                                          }
                                          else
                                          {
                                                midline[i]=loop_in_k_1*bar_range_col[i];
                                                midline_cnt++;
                                                mid_temp_row=i;
                                          }
                                    }
                              }
                        }
                        else   //������Ϊ��ת
                        {
                              for( i=ROW_END ; i>=ROW_START ; i-- )
                              {
                                    if( i>=LOOP_IN_ROW )      //����������·�ʱ
                                    {
                                          if( left_edge[i]!=-1 && right_edge[i]!=-1 )
                                          {
                                                midline[i]=(left_edge[i]+right_edge[i])/2;
                                                midline_cnt++;
                                                mid_temp_row=i;
                                          }
                                          else
                                          {
                                                if( right_edge[i]!=-1 )
                                                {
                                                      midline[i]=right_edge[i]-loop_range_col[i];
                                                      if( midline[i]<COL_START )
                                                      {
                                                            midline[i]=COL_START;
                                                      }
                                                      midline_cnt++;
                                                      mid_temp_row=i;
                                                }
                                                else
                                                {
                                                      midline[i]=COL_END-loop_range_col[i];
                                                      midline_cnt++;
                                                      mid_temp_row=i;
                                                }
                                          }
                                    }
                                    else      //����������Ϸ�ʱ
                                    {
                                          if( right_edge[i]!=-1 )
                                          {
                                                midline[i]=right_edge[i]-loop_in_k*bar_range_col[i];
                                                if( midline[i]<COL_START )
                                                {
                                                      midline[i]=COL_START;
                                                }
                                                midline_cnt++;
                                                mid_temp_row=i;
                                          }
                                          else
                                          {
                                                midline[i]=COL_END-loop_in_k_1*bar_range_col[i];
                                                midline_cnt++;
                                                mid_temp_row=i;
                                          }
                                    }
                              }
                        }
                        midline_bu();
                  }
                  else  //�����뻷��
                  {
                        if( LOOP_OUT==0 )   //���ڻ�����
                        {
                              if( out_row[0]==-1 )    //��δ�����õ�������
                              {
                                    if( loop_l_r_flag==1 )   //������Ϊ��ת
                                    {
                                          for( i=ROW_START ; i<=ROW_END ; i++ )
                                          {
                                                if( left_edge[i]!=-1 )
                                                {
                                                      for( i=i+1 ; i<=ROW_END ; i++ )
                                                      {
                                                            if( left_edge[i]==-1 )
                                                            {
                                                                  midline[i]=COL_START;
                                                                  midline_cnt++;
                                                            }
                                                      }
                                                }
                                          }
                                    }
                                    else   //������Ϊ��ת
                                    {
                                          for( i=ROW_START ; i<=ROW_END ; i++ )
                                          {
                                                if( right_edge[i]!=-1 )
                                                {
                                                      for( i=i+1 ; i<=ROW_END ; i++ )
                                                      {
                                                            if( right_edge[i]==-1 )
                                                            {
                                                                  midline[i]=COL_END;
                                                                  midline_cnt++;
                                                            }
                                                      }
                                                }
                                          }
                                    }
                                    midline_search_loop();
                                    midline_bu();
                              }
                              else    //�������õ�������
                              {
                                    midline_search_loop();
                                    midline_bu();
                                    if( loop_l_r_flag==1 )   //������Ϊ��ת
                                    {
                                          if( out_row[0]>30 )
                                          {
                                                if( mid_temp_row!=-1 )
                                                {
                                                      for( i=mid_temp_row-1 ; i>=ROW_START ; i-- )
                                                      {
                                                            if( left_edge[i]!=-1 )
                                                            {
                                                                  midline[i]=left_edge[i]+bar_range_col[i];
                                                                  if( midline[i]>COL_END )
                                                                  {
                                                                        midline[i]=COL_END;
                                                                  }
                                                                  midline_cnt++;
                                                            }
                                                            else
                                                            {
                                                                  midline[i]=loop_in_k_1*bar_range_col[i];
                                                                  midline_cnt++;
                                                            }
                                                      }
                                                }
                                                else
                                                {
                                                      for( i=ROW_END ; i>=ROW_START ; i-- )
                                                      {
                                                            if( left_edge[i]!=-1 )
                                                            {
                                                                  midline[i]=left_edge[i]+bar_range_col[i];
                                                                  if( midline[i]>COL_END )
                                                                  {
                                                                        midline[i]=COL_END;
                                                                  }
                                                                  midline_cnt++;
                                                            }
                                                            else
                                                            {
                                                                  midline[i]=loop_in_k_1*bar_range_col[i];
                                                                  midline_cnt++;
                                                            }
                                                      }
                                                }
                                          }
                                          else
                                          {
                                                if( mid_temp_row!=-1 && midline[mid_temp_row]<60 )
                                                {
                                                      for( i=mid_temp_row-1 ; i>=ROW_START ; i-- )
                                                      {
                                                            if( left_edge[i]!=-1 )
                                                            {
                                                                  midline[i]=left_edge[i]+bar_range_col[i];
                                                                  if( midline[i]>COL_END )
                                                                  {
                                                                        midline[i]=COL_END;
                                                                  }
                                                                  midline_cnt++;
                                                            }
                                                            else
                                                            {
                                                                  midline[i]=loop_in_k_1*bar_range_col[i];
                                                                  midline_cnt++;
                                                            }
                                                      }
                                                }
                                          }
                                    }
                                    else   //������Ϊ��ת
                                    {
                                          if( out_row[0]>30 )
                                          {
                                                if( mid_temp_row!=-1 )
                                                {
                                                      for( i=mid_temp_row-1 ; i>=ROW_START ; i-- )
                                                      {
                                                            if( right_edge[i]!=-1 )
                                                            {
                                                                  midline[i]=right_edge[i]-bar_range_col[i];
                                                                  if( midline[i]<COL_START )
                                                                  {
                                                                        midline[i]=COL_START;
                                                                  }
                                                                  midline_cnt++;
                                                            }
                                                            else
                                                            {
                                                                  midline[i]=COL_END-loop_in_k_1*bar_range_col[i];
                                                                  midline_cnt++;
                                                            }
                                                      }
                                                }
                                                else
                                                {
                                                      for( i=ROW_END ; i>=ROW_START ; i-- )
                                                      {
                                                            if( right_edge[i]!=-1 )
                                                            {
                                                                  midline[i]=right_edge[i]-bar_range_col[i];
                                                                  if( midline[i]<COL_START )
                                                                  {
                                                                        midline[i]=COL_START;
                                                                  }
                                                                  midline_cnt++;
                                                            }
                                                            else
                                                            {
                                                                  midline[i]=COL_END-loop_in_k_1*bar_range_col[i];
                                                                  midline_cnt++;
                                                            }
                                                      }
                                                }
                                          }
                                          else
                                          {
                                                if( mid_temp_row!=-1 && midline[mid_temp_row]>100 )
                                                {
                                                      for( i=mid_temp_row-1 ; i>=ROW_START ; i-- )
                                                      {
                                                            if( right_edge[i]!=-1 )
                                                            {
                                                                  midline[i]=right_edge[i]-bar_range_col[i];
                                                                  if( midline[i]<COL_START )
                                                                  {
                                                                        midline[i]=COL_START;
                                                                  }
                                                                  midline_cnt++;
                                                            }
                                                            else
                                                            {
                                                                  midline[i]=COL_END-loop_in_k_1*bar_range_col[i];
                                                                  midline_cnt++;
                                                            }
                                                      }
                                                }
                                          }
                                    }
                              }
                        }
                        else   //��Ҫ���뻷��
                        {
                              midline_search();
                              if( midline_cnt>=3 )
                              {
                                    midline_bu();
                              }
                        }
                  }
                  
                  if( mid_temp_row!=-1 )
                  {
                        if( loop_l_r_flag==1 )   //������Ϊ��ת
                        {
                              for( i=ROW_END ; i>=mid_temp_row ; i-- )
                              {
                                    if( midline[i]==-1 )
                                    {
                                          midline[i]=COL_START;
                                          midline_cnt++;
                                    }
                              }
                        }
                        else   //������Ϊ��ת
                        {
                              for( i=ROW_END ; i>=mid_temp_row ; i-- )
                              {
                                    if( midline[i]==-1 )
                                    {
                                          midline[i]=COL_END;
                                          midline_cnt++;
                                    }
                              }
                        }
                  }
            }
            else    //��������ͨ����ʱ
            {
                  midline_search();
                  if( midline_cnt>=3 )
                  {
                        midline_bu();
                        midline_bu_end();
                  }
            }
      }
}

/***********************************************************************************************************************************/

void midline_search()                 //��͸�ӻ�ȡ���ߺ�������С���˷���������ͨ����
{
      double xxx,yyy;         //��͸����������
      double x_angle,y_angle; //����ص���ֱ��ˮƽƫ��
      double xx1,yy1,xx2,yy2,xx3,yy3;  //������͸������
      double k;               //��͸�ӱ��ؼ���б��
      double uSrcImg,vSrcImg; //����͸������
      int16 mid_x,mid_y;       //����͸�ӵ�����ֵ
      int16 row_mid=-1;        //����ĩβ��ֵ
      
      wide=ROAD_WIDE/2;
      
      if( left_edge[ROW_START]!=-1 && right_edge[ROW_START]!=-1 )
      {
            midline[ROW_START]=(left_edge[ROW_START]+right_edge[ROW_START])/2;
            midline_cnt++;
      }
      if( left_edge[ROW_START+1]!=-1 && right_edge[ROW_START+1]!=-1 )
      {
            midline[ROW_START+1]=(left_edge[ROW_START+1]+right_edge[ROW_START+1])/2;
            midline_cnt++;
      }
      if( left_edge[ROW_END]!=-1 && right_edge[ROW_END]!=-1 )
      {
            midline[ROW_END]=(left_edge[ROW_END]+right_edge[ROW_END])/2;
            mid_temp_row=ROW_END;
            midline_cnt++;
      }
      if( left_edge[ROW_END-1]!=-1 && right_edge[ROW_END-1]!=-1 )
      {
            midline[ROW_END-1]=(left_edge[ROW_END-1]+right_edge[ROW_END-1])/2;
            mid_temp_row=ROW_END-1;
            midline_cnt++;
      }
      for( int16 i=ROW_END-ROW_INTERVAL ; i>= ROW_START+ROW_INTERVAL ; i-- )
      {
            wide=(1.0*ROAD_WIDE+(inv_distance[i])/20)/2;
            
            if( left_edge[i]!=-1 )
            {
                  if( right_edge[i]!=-1 )   //������ұ��ض���
                  {
                        midline[i]=(left_edge[i]+right_edge[i])/2;
                        midline_cnt++;
                        row_mid=i;
                        mid_temp_row=-1;
                  }
                  else   //���ֻ������أ�����͸��
                  {
                        if( inv_left_edge[i+ROW_INTERVAL].x!=-1 && inv_left_edge[i].x!=-1 && inv_left_edge[i-ROW_INTERVAL].x!=-1 )
                        {
                              xx1=inv_left_edge[i+ROW_INTERVAL].x;
                              yy1=inv_left_edge[i+ROW_INTERVAL].y;
                              xx2=inv_left_edge[i].x;
                              yy2=inv_left_edge[i].y;
                              xx3=inv_left_edge[i-ROW_INTERVAL].x;
                              yy3=inv_left_edge[i-ROW_INTERVAL].y;
                              
                              /*��С���˷���ȡ���ط���б�ʣ�ƽ���������һ��*/
                              k = (-1.0)*(xx1*yy1+xx2*yy2+xx3*yy3-(xx1+xx2+xx3)*(yy1+yy2+yy3)/3)/(xx1*xx1+xx2*xx2+xx3*xx3-(xx1+xx2+xx3)*(xx1+xx2+xx3)/3);
                              
                              if((k==0)|| (isnan(k)==1) || (isnan(k)==-1))  //ˮƽ
                              {
                                    xxx=xx2;
                                    yyy=yy2+wide;
                              }
                              else if((isinf(k)==1) || (isinf(k)==-1))     //��ֱ
                              {
                                    xxx=xx2-wide;
                                    yyy=yy2;
                              }
                              else
                              {
                                    y_angle=wide/sqrtf(1+k*k);   //����ص�ˮƽƫ��
                                    x_angle=y_angle*fabsf(k);        //����ص���ֱƫ��
                                    if(k>0)
                                    {
                                          xxx=xx2+x_angle;
                                          yyy=yy2+y_angle;
                                    }
                                    if(k<0)
                                    {
                                          xxx=xx2-x_angle;
                                          yyy=yy2+y_angle;
                                    }
                              }
                              
                              /*����͸��*/
                              uSrcImg =(INV_B*INV_F - INV_C*INV_E + INV_E*yyy - INV_B*xxx - INV_F*INV_H*yyy + INV_C*INV_H*xxx)/(INV_A*INV_E - INV_B*INV_D + INV_D*INV_H*yyy - INV_E*INV_G*yyy - INV_A*INV_H*xxx + INV_B*INV_G*xxx);
                              vSrcImg =-(INV_A*INV_F - INV_C*INV_D + INV_D*yyy - INV_A*xxx - INV_F*INV_G*yyy + INV_C*INV_G*xxx)/(INV_A*INV_E - INV_B*INV_D + INV_D*INV_H*yyy - INV_E*INV_G*yyy - INV_A*INV_H*xxx + INV_B*INV_G*xxx);
                              
                              mid_x=round(vSrcImg-1);
                              mid_y=round(uSrcImg-1);
                              if( mid_temp_row==-1 )
                              {
                                    if( mid_x>=ROW_START && mid_x>=i-20 )
                                    {
                                          if( mid_x<=ROW_END )
                                          {
                                                if( mid_y>=COL_START && mid_y<=COL_END )
                                                {
                                                      midline[mid_x]=mid_y;
                                                      midline_cnt++;
                                                      mid_temp_row=mid_x;
                                                }
                                          }
                                          else
                                          {
                                                if( mid_y>=COL_START && mid_y<=COL_END && mid_x<=ROW_END+10 )
                                                {
                                                      if( mid_down_pot[0]==-1 )
                                                      {
                                                            mid_down_pot[0]=mid_x;
                                                            mid_down_pot[1]=mid_y;
                                                      }
                                                      else
                                                      {
                                                            if( mid_x<=mid_down_pot[0] )
                                                            {
                                                                  mid_down_pot[0]=mid_x;
                                                                  mid_down_pot[1]=mid_y;
                                                            }
                                                      }
                                                }
                                          }
                                    }
                              }
                              else
                              {
                                    if( mid_x>=ROW_START && mid_x<=ROW_END && mid_x>=mid_temp_row-10 && mid_x<=mid_temp_row+3 )
                                    {
                                          if( mid_y>=COL_START && mid_y<=COL_END )
                                          {
                                                if( mid_y>=midline[mid_temp_row]-3 )
                                                {
                                                      midline[mid_x]=mid_y;
                                                      midline_cnt++;
                                                      mid_temp_row=mid_x;
                                                }
                                          }
                                          else
                                          {
                                                if( mid_y<=COL_END+20 )
                                                {
                                                      if( mid_y>=midline[mid_temp_row]-3 )
                                                      {
                                                            midline[mid_x]=COL_END;
                                                            midline_cnt++;
                                                            mid_temp_row=mid_x;
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
                  if( right_edge[i]!=-1 )   //���ֻ���ұ��أ�����͸��
                  {
                        if(inv_right_edge[i+ROW_INTERVAL].x!=-1 && inv_right_edge[i].x!=-1 && inv_right_edge[i-ROW_INTERVAL].x!=-1 )
                        {
                              xx1=inv_right_edge[i+ROW_INTERVAL].x;
                              yy1=inv_right_edge[i+ROW_INTERVAL].y;
                              xx2=inv_right_edge[i].x;
                              yy2=inv_right_edge[i].y;
                              xx3=inv_right_edge[i-ROW_INTERVAL].x;
                              yy3=inv_right_edge[i-ROW_INTERVAL].y;
                              
                              /*��С���˷���ȡ���ط���б�ʣ�ƽ���������һ��*/
                              k=(-1.0)*(xx1*yy1+xx2*yy2+xx3*yy3-(xx1+xx2+xx3)*(yy1+yy2+yy3)/3)/(xx1*xx1+xx2*xx2+xx3*xx3-(xx1+xx2+xx3)*(xx1+xx2+xx3)/3);
                              
                              if( k==0 || (isnan(k)==1) || (isnan(k)==-1) )  //ˮƽ
                              {
                                    xxx=xx2;
                                    yyy=yy2-wide;
                              }
                              else if( (isinf(k)==1) || (isinf(k)==-1) )  //��ֱ
                              {
                                    xxx=xx2-wide;
                                    yyy=yy2;
                              }        
                              else
                              {
                                    y_angle=wide/sqrtf(1+k*k); //����ص�ˮƽƫ��
                                    x_angle=y_angle*fabsf(k);      //����ص���ֱƫ��
                                    if(k>0)
                                    {
                                          xxx=xx2-x_angle;
                                          yyy=yy2-y_angle;
                                    }
                                    if(k<0)
                                    {
                                          xxx=xx2+x_angle;
                                          yyy=yy2-y_angle;
                                    }
                              }
                              
                              /*����͸��*/
                              uSrcImg =(INV_B*INV_F - INV_C*INV_E + INV_E*yyy - INV_B*xxx - INV_F*INV_H*yyy + INV_C*INV_H*xxx)/(INV_A*INV_E - INV_B*INV_D + INV_D*INV_H*yyy - INV_E*INV_G*yyy - INV_A*INV_H*xxx + INV_B*INV_G*xxx);
                              vSrcImg =-(INV_A*INV_F - INV_C*INV_D + INV_D*yyy - INV_A*xxx - INV_F*INV_G*yyy + INV_C*INV_G*xxx)/(INV_A*INV_E - INV_B*INV_D + INV_D*INV_H*yyy - INV_E*INV_G*yyy - INV_A*INV_H*xxx + INV_B*INV_G*xxx);
                              
                              mid_x=round(vSrcImg-1);
                              mid_y=round(uSrcImg-1);
                              if( mid_temp_row==-1 )
                              {
                                    if( mid_x>=ROW_START && mid_x<=ROW_END && mid_x>=i-20 )
                                    {
                                          if( mid_x<=ROW_END )
                                          {
                                                if( mid_y>=COL_START && mid_y<=COL_END )
                                                {
                                                      midline[mid_x]=mid_y;
                                                      midline_cnt++;
                                                      mid_temp_row=mid_x;
                                                }
                                          }
                                          else
                                          {
                                                if( mid_y>=COL_START && mid_y<=COL_END && mid_x<=ROW_END+10 )
                                                {
                                                      if( mid_down_pot[0]==-1 )
                                                      {
                                                            mid_down_pot[0]=mid_x;
                                                            mid_down_pot[1]=mid_y;
                                                      }
                                                      else
                                                      {
                                                            if( mid_x<=mid_down_pot[0] )
                                                            {
                                                                  mid_down_pot[0]=mid_x;
                                                                  mid_down_pot[1]=mid_y;
                                                            }
                                                      }
                                                }
                                          }
                                    }
                              }
                              else
                              {
                                    if( mid_x>=ROW_START && mid_x<=ROW_END && mid_x>=mid_temp_row-10 && mid_x<=mid_temp_row+3 )
                                    {
                                          if( mid_y>=COL_START && mid_y<=COL_END )
                                          {
                                                if( mid_y<=midline[mid_temp_row]+3 )
                                                {
                                                      midline[mid_x]=mid_y;
                                                      midline_cnt++;
                                                      mid_temp_row=mid_x;
                                                }
                                          }
                                          else
                                          {
                                                if( mid_y>=COL_START-20 )
                                                {
                                                      if( mid_y<=midline[mid_temp_row]+3 )
                                                      {
                                                            midline[mid_x]=COL_START;
                                                            midline_cnt++;
                                                            mid_temp_row=mid_x;
                                                      }
                                                }
                                          }
                                    }
                              }
                        }
                  }
            }
      }
      
      if( row_mid!=-1 )
      {
            if( mid_temp_row!=-1 )
            {
                  if( row_mid<mid_temp_row )
                  {
                        mid_temp_row=row_mid;
                  }
            }
            else
            {
                  mid_temp_row=row_mid;
            }
            
      }
}

/***********************************************************************************************************************************/

void midline_search_over()            //��͸�ӻ�ȡ���ߺ�������С���˷������ڿ���ͣ��
{
      double xxx,yyy;         //��͸����������
      double x_angle,y_angle; //����ص���ֱ��ˮƽƫ��
      double xx1,yy1,xx2,yy2,xx3,yy3;  //������͸������
      double k;               //��͸�ӱ��ؼ���б��
      double uSrcImg,vSrcImg; //����͸������
      int16 mid_x,mid_y;       //����͸�ӵ�����ֵ
      wide=ROAD_WIDE/4;
      if(speedout_val_cross_flag && car_stop_flag && !car_flag)
      {
         wide=ROAD_WIDE/4*1.2;
      }
      if(car_L_pull_over_flag)    //��Ϊ�������ͣ��״̬ʱ
      {
            for( int16 i=ROW_END-ROW_INTERVAL ; i>= ROW_START+ROW_INTERVAL ; i-- )
            {
                  if( inv_left_edge[i+ROW_INTERVAL].x!=-1 && inv_left_edge[i].x!=-1 && inv_left_edge[i-ROW_INTERVAL].x!=-1 )
                  {
                        xx1=inv_left_edge[i+ROW_INTERVAL].x;
                        yy1=inv_left_edge[i+ROW_INTERVAL].y;
                        xx2=inv_left_edge[i].x;
                        yy2=inv_left_edge[i].y;
                        xx3=inv_left_edge[i-ROW_INTERVAL].x;
                        yy3=inv_left_edge[i-ROW_INTERVAL].y;
                        
                        /*��С���˷���ȡ���ط���б�ʣ�ƽ���������һ��*/
                        k = (-1.0)*(xx1*yy1+xx2*yy2+xx3*yy3-(xx1+xx2+xx3)*(yy1+yy2+yy3)/3)/(xx1*xx1+xx2*xx2+xx3*xx3-(xx1+xx2+xx3)*(xx1+xx2+xx3)/3);
                        
                        if((k==0)|| (isnan(k)==1) || (isnan(k)==-1))  //ˮƽ
                        {
                              xxx=xx2;
                              yyy=yy2+wide;
                        }
                        else if((isinf(k)==1) || (isinf(k)==-1))     //��ֱ
                        {
                              xxx=xx2-wide;
                              yyy=yy2;
                        }
                        else
                        {
                              y_angle=wide/sqrtf(1+k*k);   //����ص�ˮƽƫ��
                              x_angle=y_angle*fabsf(k);        //����ص���ֱƫ��
                              if(k>0)
                              {
                                    xxx=xx2+x_angle;
                                    yyy=yy2+y_angle;
                              }
                              if(k<0)
                              {
                                    xxx=xx2-x_angle;
                                    yyy=yy2+y_angle;
                              }
                        }
                        /*����͸��*/
                        uSrcImg =(INV_B*INV_F - INV_C*INV_E + INV_E*yyy - INV_B*xxx - INV_F*INV_H*yyy + INV_C*INV_H*xxx)/(INV_A*INV_E - INV_B*INV_D + INV_D*INV_H*yyy - INV_E*INV_G*yyy - INV_A*INV_H*xxx + INV_B*INV_G*xxx);
                        vSrcImg =-(INV_A*INV_F - INV_C*INV_D + INV_D*yyy - INV_A*xxx - INV_F*INV_G*yyy + INV_C*INV_G*xxx)/(INV_A*INV_E - INV_B*INV_D + INV_D*INV_H*yyy - INV_E*INV_G*yyy - INV_A*INV_H*xxx + INV_B*INV_G*xxx);
                        
                        mid_x=round(vSrcImg-1);
                        mid_y=round(uSrcImg-1);
                        if( mid_temp_row==-1 )
                        {
                              if( mid_x>=ROW_START && mid_x>=i-20 )
                              {
                                    if( mid_x<=ROW_END )
                                    {
                                          if( mid_y>=COL_START && mid_y<=COL_END )
                                          {
                                                midline[mid_x]=mid_y;
                                                midline_cnt++;
                                                mid_temp_row=mid_x;
                                          }
                                    }
                                    else
                                    {
                                          if( mid_y>=COL_START && mid_y<=COL_END && mid_x<=ROW_END+10 )
                                          {
                                                if( mid_down_pot[0]==-1 )
                                                {
                                                      mid_down_pot[0]=mid_x;
                                                      mid_down_pot[1]=mid_y;
                                                }
                                                else
                                                {
                                                      if( mid_x<=mid_down_pot[0] )
                                                      {
                                                            mid_down_pot[0]=mid_x;
                                                            mid_down_pot[1]=mid_y;
                                                      }
                                                }
                                          }
                                    }
                              }
                        }
                        else
                        {
                              if( mid_x>=ROW_START && mid_x<=ROW_END && mid_x>=mid_temp_row-10 && mid_x<=mid_temp_row+3 )
                              {
                                    if( mid_y>=COL_START && mid_y<=COL_END )
                                    {
                                          if( mid_y>=midline[mid_temp_row]-3 )
                                          {
                                                midline[mid_x]=mid_y;
                                                midline_cnt++;
                                                mid_temp_row=mid_x;
                                          }
                                    }
                                    else
                                    {
                                          if( mid_y<=COL_END+20 )
                                          {
                                                if( mid_y>=midline[mid_temp_row]-3 )
                                                {
                                                      midline[mid_x]=COL_END;
                                                      midline_cnt++;
                                                      mid_temp_row=mid_x;
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
            if(car_R_pull_over_flag)    //��Ϊ�����Ҳ�ͣ��״̬ʱ
            {
                  for( int16 i=ROW_END-ROW_INTERVAL ; i>= ROW_START+ROW_INTERVAL ; i-- )
                  {
                        if(inv_right_edge[i+2].x!=-1 && inv_right_edge[i].x!=-1 && inv_right_edge[i-2].x!=-1 )
                        {
                              xx1=inv_right_edge[i+ROW_INTERVAL].x;
                              yy1=inv_right_edge[i+ROW_INTERVAL].y;
                              xx2=inv_right_edge[i].x;
                              yy2=inv_right_edge[i].y;
                              xx3=inv_right_edge[i-ROW_INTERVAL].x;
                              yy3=inv_right_edge[i-ROW_INTERVAL].y;
                              
                              /*��С���˷���ȡ���ط���б�ʣ�ƽ���������һ��*/
                              k=(-1.0)*(xx1*yy1+xx2*yy2+xx3*yy3-(xx1+xx2+xx3)*(yy1+yy2+yy3)/3)/(xx1*xx1+xx2*xx2+xx3*xx3-(xx1+xx2+xx3)*(xx1+xx2+xx3)/3);
                              
                              if( k==0 || (isnan(k)==1) || (isnan(k)==-1) )  //ˮƽ
                              {
                                    xxx=xx2;
                                    yyy=yy2-wide;
                              }
                              else if( (isinf(k)==1) || (isinf(k)==-1) )  //��ֱ
                              {
                                    xxx=xx2-wide;
                                    yyy=yy2;
                              }        
                              else
                              {
                                    y_angle=wide/sqrtf(1+k*k); //����ص�ˮƽƫ��
                                    x_angle=y_angle*fabsf(k);      //����ص���ֱƫ��
                                    if(k>0)
                                    {
                                          xxx=xx2-x_angle;
                                          yyy=yy2-y_angle;
                                    }
                                    if(k<0)
                                    {
                                          xxx=xx2+x_angle;
                                          yyy=yy2-y_angle;
                                    }
                              }
                              
                              /*����͸��*/
                              uSrcImg =(INV_B*INV_F - INV_C*INV_E + INV_E*yyy - INV_B*xxx - INV_F*INV_H*yyy + INV_C*INV_H*xxx)/(INV_A*INV_E - INV_B*INV_D + INV_D*INV_H*yyy - INV_E*INV_G*yyy - INV_A*INV_H*xxx + INV_B*INV_G*xxx);
                              vSrcImg =-(INV_A*INV_F - INV_C*INV_D + INV_D*yyy - INV_A*xxx - INV_F*INV_G*yyy + INV_C*INV_G*xxx)/(INV_A*INV_E - INV_B*INV_D + INV_D*INV_H*yyy - INV_E*INV_G*yyy - INV_A*INV_H*xxx + INV_B*INV_G*xxx);
                              
                              mid_x=round(vSrcImg-1);
                              mid_y=round(uSrcImg-1);
                              if( mid_temp_row==-1 )
                              {
                                    if( mid_x>=ROW_START && mid_x<=ROW_END && mid_x>=i-20 )
                                    {
                                          if( mid_x<=ROW_END )
                                          {
                                                if( mid_y>=COL_START && mid_y<=COL_END )
                                                {
                                                      midline[mid_x]=mid_y;
                                                      midline_cnt++;
                                                      mid_temp_row=mid_x;
                                                }
                                          }
                                          else
                                          {
                                                if( mid_y>=COL_START && mid_y<=COL_END && mid_x<=ROW_END+10 )
                                                {
                                                      if( mid_down_pot[0]==-1 )
                                                      {
                                                            mid_down_pot[0]=mid_x;
                                                            mid_down_pot[1]=mid_y;
                                                      }
                                                      else
                                                      {
                                                            if( mid_x<=mid_down_pot[0] )
                                                            {
                                                                  mid_down_pot[0]=mid_x;
                                                                  mid_down_pot[1]=mid_y;
                                                            }
                                                      }
                                                }
                                          }
                                    }
                              }
                              else
                              {
                                    if( mid_x>=ROW_START && mid_x<=ROW_END && mid_x>=mid_temp_row-10 && mid_x<=mid_temp_row+3 )
                                    {
                                          if( mid_y>=COL_START && mid_y<=COL_END )
                                          {
                                                if( mid_y<=midline[mid_temp_row]+3 )
                                                {
                                                      midline[mid_x]=mid_y;
                                                      midline_cnt++;
                                                      mid_temp_row=mid_x;
                                                }
                                          }
                                          else
                                          {
                                                if( mid_y>=COL_START-20 )
                                                {
                                                      if( mid_y<=midline[mid_temp_row]+3 )
                                                      {
                                                            midline[mid_x]=COL_START;
                                                            midline_cnt++;
                                                            mid_temp_row=mid_x;
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

void midline_search_loop()            //��͸�ӻ�ȡ���ߺ�������С���˷������ڻ�������
{
      double xxx,yyy;         //��͸����������
      double x_angle,y_angle; //����ص���ֱ��ˮƽƫ��
      double xx1,yy1,xx2,yy2,xx3,yy3;  //������͸������
      double k;               //��͸�ӱ��ؼ���б��
      double uSrcImg,vSrcImg; //����͸������
      int16 mid_x,mid_y;       //����͸�ӵ�����ֵ
      
      wide=ROAD_WIDE/2;
      
      
      if( loop_l_r_flag==1 )   //������Ϊ��ת
      {
            for( int16 i=ROW_END-ROW_INTERVAL ; i>= ROW_START+ROW_INTERVAL ; i-- )
            {
                  wide=(1.0*ROAD_WIDE+(inv_distance[i])/20)/2;
                  
                  if( inv_left_edge[i+ROW_INTERVAL].x!=-1 && inv_left_edge[i].x!=-1 && inv_left_edge[i-ROW_INTERVAL].x!=-1 )
                  {
                        xx1=inv_left_edge[i+ROW_INTERVAL].x;
                        yy1=inv_left_edge[i+ROW_INTERVAL].y;
                        xx2=inv_left_edge[i].x;
                        yy2=inv_left_edge[i].y;
                        xx3=inv_left_edge[i-ROW_INTERVAL].x;
                        yy3=inv_left_edge[i-ROW_INTERVAL].y;
                        
                        /*��С���˷���ȡ���ط���б�ʣ�ƽ���������һ��*/
                        k=(-1.0)*(xx1*yy1+xx2*yy2+xx3*yy3-(xx1+xx2+xx3)*(yy1+yy2+yy3)/3)/(xx1*xx1+xx2*xx2+xx3*xx3-(xx1+xx2+xx3)*(xx1+xx2+xx3)/3);
                        
                        if( (k==0)|| (isnan(k)==1) || (isnan(k)==-1) )  //ˮƽ
                        {
                              xxx=xx2;
                              yyy=yy2+wide;
                        }
                        else
                        {
                              if( (isinf(k)==1) || (isinf(k)==-1) )  //��ֱ
                              {
                                    xxx=xx2-wide;
                                    yyy=yy2;
                              }
                              else
                              {
                                    y_angle=wide/sqrtf(1+k*k); //����ص�ˮƽƫ��
                                    x_angle=y_angle*fabsf(k);  //����ص���ֱƫ��
                                    if(k>0)
                                    {
                                          xxx=xx2+x_angle;
                                          yyy=yy2+y_angle;
                                    }
                                    if(k<0)
                                    {
                                          xxx=xx2-x_angle;
                                          yyy=yy2+y_angle;
                                    }
                              }
                        }
                        
                        /*����͸��*/
                        uSrcImg =(INV_B*INV_F - INV_C*INV_E + INV_E*yyy - INV_B*xxx - INV_F*INV_H*yyy + INV_C*INV_H*xxx)/(INV_A*INV_E - INV_B*INV_D + INV_D*INV_H*yyy - INV_E*INV_G*yyy - INV_A*INV_H*xxx + INV_B*INV_G*xxx);
                        vSrcImg =-(INV_A*INV_F - INV_C*INV_D + INV_D*yyy - INV_A*xxx - INV_F*INV_G*yyy + INV_C*INV_G*xxx)/(INV_A*INV_E - INV_B*INV_D + INV_D*INV_H*yyy - INV_E*INV_G*yyy - INV_A*INV_H*xxx + INV_B*INV_G*xxx);
                        
                        mid_x=round(vSrcImg-1);
                        mid_y=round(uSrcImg-1);
                        if( midline[mid_x]==-1 )
                        {
                              if( mid_temp_row==-1 )
                              {
                                    if( mid_x>=ROW_START && mid_x>=i-20 )
                                    {
                                          if( mid_x<=ROW_END )
                                          {
                                                if( mid_y>=COL_START && mid_y<=COL_END )
                                                {
                                                      midline[mid_x]=mid_y;
                                                      midline_cnt++;
                                                      mid_temp_row=mid_x;
                                                }
                                          }
                                          else
                                          {
                                                if( mid_y>=COL_START && mid_y<=COL_END && mid_x<=ROW_END+10 )
                                                {
                                                      if( mid_down_pot[0]==-1 )
                                                      {
                                                            mid_down_pot[0]=mid_x;
                                                            mid_down_pot[1]=mid_y;
                                                      }
                                                      else
                                                      {
                                                            if( mid_x<=mid_down_pot[0] )
                                                            {
                                                                  mid_down_pot[0]=mid_x;
                                                                  mid_down_pot[1]=mid_y;
                                                            }
                                                      }
                                                }
                                          }
                                    }
                              }
                              else
                              {
                                    if( mid_x>=ROW_START && mid_x<=ROW_END && mid_x<=mid_temp_row+3 )
                                    {
                                          if( mid_y>=COL_START && mid_y<=COL_END )
                                          {
                                                midline[mid_x]=mid_y;
                                                midline_cnt++;
                                                mid_temp_row=mid_x;
                                          }
                                          else
                                          {
                                                if( mid_y<=COL_END+20 )
                                                {
                                                      midline[mid_x]=COL_END;
                                                      midline_cnt++;
                                                      mid_temp_row=mid_x;
                                                }
                                          }
                                    }
                              }
                        }
                  }
            }
      }
      else   //������Ϊ��ת
      {
            for( int16 i=ROW_END-ROW_INTERVAL ; i>= ROW_START+ROW_INTERVAL ; i-- )
            {
                  wide=(1.0*ROAD_WIDE+(inv_distance[i])/20)/2;
                  
                  if(inv_right_edge[i+ROW_INTERVAL].x!=-1 && inv_right_edge[i].x!=-1 && inv_right_edge[i-ROW_INTERVAL].x!=-1 )
                  {
                        xx1=inv_right_edge[i+ROW_INTERVAL].x;
                        yy1=inv_right_edge[i+ROW_INTERVAL].y;
                        xx2=inv_right_edge[i].x;
                        yy2=inv_right_edge[i].y;
                        xx3=inv_right_edge[i-ROW_INTERVAL].x;
                        yy3=inv_right_edge[i-ROW_INTERVAL].y;
                        
                        /*��С���˷���ȡ���ط���б�ʣ�ƽ���������һ��*/
                        k=(-1.0)*(xx1*yy1+xx2*yy2+xx3*yy3-(xx1+xx2+xx3)*(yy1+yy2+yy3)/3)/(xx1*xx1+xx2*xx2+xx3*xx3-(xx1+xx2+xx3)*(xx1+xx2+xx3)/3);
                        
                        if( k==0 || (isnan(k)==1) || (isnan(k)==-1) )  //ˮƽ
                        {
                              xxx=xx2;
                              yyy=yy2-wide;
                        }
                        else if( (isinf(k)==1) || (isinf(k)==-1) )  //��ֱ
                        {
                              xxx=xx2-wide;
                              yyy=yy2;
                        }        
                        else
                        {
                              y_angle=wide/sqrtf(1+k*k); //����ص�ˮƽƫ��
                              x_angle=y_angle*fabsf(k);  //����ص���ֱƫ��
                              if(k>0)
                              {
                                    xxx=xx2-x_angle;
                                    yyy=yy2-y_angle;
                              }
                              if(k<0)
                              {
                                    xxx=xx2+x_angle;
                                    yyy=yy2-y_angle;
                              }
                        }
                        
                        /*����͸��*/
                        uSrcImg =(INV_B*INV_F - INV_C*INV_E + INV_E*yyy - INV_B*xxx - INV_F*INV_H*yyy + INV_C*INV_H*xxx)/(INV_A*INV_E - INV_B*INV_D + INV_D*INV_H*yyy - INV_E*INV_G*yyy - INV_A*INV_H*xxx + INV_B*INV_G*xxx);
                        vSrcImg =-(INV_A*INV_F - INV_C*INV_D + INV_D*yyy - INV_A*xxx - INV_F*INV_G*yyy + INV_C*INV_G*xxx)/(INV_A*INV_E - INV_B*INV_D + INV_D*INV_H*yyy - INV_E*INV_G*yyy - INV_A*INV_H*xxx + INV_B*INV_G*xxx);
                        
                        mid_x=round(vSrcImg-1);
                        mid_y=round(uSrcImg-1);
                        if( mid_x>=ROW_START && mid_x<=ROW_END && mid_y>=COL_START && mid_y<=COL_END && mid_x>=i-30 )
                        {
                              if( midline[mid_x]==-1 && mid_x<mid_temp_row+3 )
                              {
                                    midline[mid_x]=mid_y;
                                    midline_cnt++;
                                    mid_temp_row=mid_x;
                              }
                        }
                        if( midline[mid_x]==-1 )
                        {
                              if( mid_temp_row==-1 )
                              {
                                    if( mid_x>=ROW_START && mid_x>=i-20 )
                                    {
                                          if( mid_x<=ROW_END )
                                          {
                                                if( mid_y>=COL_START && mid_y<=COL_END )
                                                {
                                                      midline[mid_x]=mid_y;
                                                      midline_cnt++;
                                                      mid_temp_row=mid_x;
                                                }
                                          }
                                          else
                                          {
                                                if( mid_y>=COL_START && mid_y<=COL_END && mid_x<=ROW_END+10 )
                                                {
                                                      if( mid_down_pot[0]==-1 )
                                                      {
                                                            mid_down_pot[0]=mid_x;
                                                            mid_down_pot[1]=mid_y;
                                                      }
                                                      else
                                                      {
                                                            if( mid_x<=mid_down_pot[0] )
                                                            {
                                                                  mid_down_pot[0]=mid_x;
                                                                  mid_down_pot[1]=mid_y;
                                                            }
                                                      }
                                                }
                                          }
                                    }
                              }
                              else
                              {
                                    if( mid_x>=ROW_START && mid_x<=ROW_END && mid_x<=mid_temp_row+3 )
                                    {
                                          if( mid_y>=COL_START && mid_y<=COL_END )
                                          {
                                                midline[mid_x]=mid_y;
                                                midline_cnt++;
                                                mid_temp_row=mid_x;
                                          }
                                          else
                                          {
                                                if( mid_y>=COL_START-20 )
                                                {
                                                      midline[mid_x]=COL_START;
                                                      midline_cnt++;
                                                      mid_temp_row=mid_x;
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

void midline_bu()                     //���߲��ϵ㺯���������м���ɢ���ߣ�
{
      int16 x,i,xx;    //ѭ������
      int16 mid_down=-1,mid_up=-1,mid;   //����������ɢ����ֵ
      double mid_row,mid_col,mid_start; //б�ʼ������
      if( S_FLAG==0 && LOOP_TEMP==0 )
      {
            midlinebu_row=MID_ADD;             //�趨���߷�Χ
      }
      else
      {
            if( L_s_temp==1 || R_s_temp==1 )
            {
                  midlinebu_row=MID_ADD+120;             //�趨���߷�Χ
            }
            else
            {
                  if( LOOP_TEMP==1 )
                  {
                        midlinebu_row=MID_ADD+120;             //�趨���߷�Χ
                  }
            }
      }
      
      for( x=ROW_END ; x>=mid_temp_row ; x-- )   //�������ߣ���ɲ���
      {
            if( midline[x]!=-1 )
            {
                  mid_down=x;
            }
            else
            {
                  if( mid_down!=-1 )
                  {
                        for( i=x-1 ; i>=mid_temp_row ; i-- )   //������������
                        {
                              if( midline[i]!=-1 )
                              {
                                    mid_up=i;
                                    break;
                              }
                        }
                        if( mid_up==-1 )
                        {
                              break;   //�����������ߣ����������
                        }
                        else
                        {
                              if( inv_distance[mid_up]-inv_distance[mid_down]<midlinebu_row )  //�������õ������ߣ����ڷ�Χ�ڣ����в���
                              {
                                    mid_row=mid_down-mid_up;
                                    mid_col=midline[mid_down]-midline[mid_up];
                                    mid_col=mid_col/mid_row;
                                    mid_start=midline[mid_down];
                                    for( xx=mid_down-1 ; xx>mid_up ; xx-- )
                                    {
                                          mid_start=mid_start-mid_col;
                                          mid=round(mid_start);
                                          midline[xx]=mid;
                                          midline_cnt++;
                                    }
                                    mid_down=mid_up;
                                    x=mid_up+1;
                                    mid_up=-1;
                              }
                              else   //�����������õ������ߣ����ڷ�Χ�ڣ���������
                              {
                                    x=mid_up+1;
                                    mid_down=mid_up;
                                    mid_up=-1;
                              }
                        }
                  }
            }
      }
      
      mid_down=-1;
      for( x=ROW_END ; x>ROW_END-25 ; x-- )   //�������ߣ���ɵײ�����
      {
            if( midline[x]!=-1 )
            {
                  if( x==ROW_END )
                  {
                        break;
                  }
                  else
                  {
                        if( mid_down_pot[0]==-1 )    //δ������ͼ�����·���
                        {
                              mid_down=x;
                              mid_up=0;
                              for( x=mid_down-1 ; x>=mid_down-6 ; x-- )   //�������ߣ���ɵײ�����
                              {
                                    if( midline[x]!=-1 )
                                    {
                                          mid_up++;
                                    }
                                    else
                                    {
                                          break;
                                    }
                              }
                              if( mid_up>=6 )
                              {
                                    mid_row=6;
                                    mid_col=midline[mid_down]-midline[mid_down-6];
                                    mid_col=mid_col/mid_row;
                                    if( fabsf(mid_col)>1 )
                                    {
                                          if( mid_col<0 )
                                          {
                                                mid_col=-1;
                                          }
                                          else
                                          {
                                                mid_col=1;
                                          }
                                    }
                                    mid_start=midline[mid_down-3];
                                    for( xx=mid_down-2 ; xx<=ROW_END ; xx++ )
                                    {
                                          mid_start=mid_start+mid_col;
                                          mid=round(mid_start);
                                          if( mid<COL_START || mid>COL_END )
                                          {
                                                if( mid<COL_START )
                                                {
                                                      for( i=xx ; i<=ROW_END ; i++ )
                                                      {
                                                            midline[xx]=COL_START;
                                                            midline_cnt++;
                                                      }
                                                }
                                                else
                                                {
                                                      for( i=xx ; i<=ROW_END ; i++ )
                                                      {
                                                            midline[xx]=COL_END;
                                                            midline_cnt++;
                                                      }
                                                }
                                                break;
                                          }
                                          midline[xx]=mid;
                                          midline_cnt++;
                                    }
                                    break;
                              }
                        }
                        else    //������ͼ�����·���
                        {
                              mid_row=mid_down_pot[0]-x;
                              mid_col=mid_down_pot[1]-midline[x];
                              mid_col=mid_col/mid_row;
                              mid_start=midline[x];
                              for( xx=x+1 ; xx<=ROW_END ; xx++ )
                              {
                                    mid_start=mid_start+mid_col;
                                    mid=round(mid_start);
                                    if( mid<COL_START || mid>COL_END )
                                    {
                                          if( mid<COL_START )
                                          {
                                                for( i=xx ; i<=ROW_END ; i++ )
                                                {
                                                      midline[xx]=COL_START;
                                                      midline_cnt++;
                                                }
                                          }
                                          else
                                          {
                                                for( i=xx ; i<=ROW_END ; i++ )
                                                {
                                                      midline[xx]=COL_END;
                                                      midline_cnt++;
                                                }
                                          }
                                          break;
                                    }
                                    midline[xx]=mid;
                                    midline_cnt++;
                              }
                              break;
                        }
                  }
            }
      }
      
      if( mid_temp_row!=-1 )
      {
            mid_down=mid_temp_row;
            for( x=mid_temp_row+1 ; x<=ROW_END ; x++ )   //�������ߣ�����м䶪ʧ���߸�ֵ
            {
                  if( midline[x]==-1 )
                  {
                        if( midline[mid_down]<=50 && left_edge[x]==-1 )
                        {
                              midline[x]=COL_START;
                              mid_down=x;
                        }
                        if( midline[x-1]>=110 && right_edge[x]==-1 )
                        {
                              midline[x]=COL_END;
                              mid_down=x;
                        }
                  }
                  else
                  {
                        mid_down=x;
                  }
            }
      }
}

/***********************************************************************************************************************************/

void midline_bu_end()                 //���߲��ϵ㺯�������ڲ����ĩβ���ߣ�
{
      mid_end_jizhun_flag=0;
      if(R_TURN)
      {
            for(int16 j= COL_END ;j>= COL_END-20;j--)
            {
                  midline_jizhun_search(j);
                  if( mid_end_jizhun_flag)
                  {
                        break;
                  }
            }
            inv_mid_end=get_inv_img(mid_end_jizhun.x ,mid_end_jizhun.y);
            inv_mid_end.x=inv_mid_end.x-((1.0*ROAD_WIDE+(inv_distance[mid_end_jizhun.x])/20)/2);
            mid_end=get_invinv_img(inv_mid_end.x,inv_mid_end.y);
            
      }
      else  if(L_TURN)
      {
            for(int16 j= 0 ;j<= 20;j++)
            {
                  midline_jizhun_search(j);
                  if( mid_end_jizhun_flag)
                  {
                        break;
                  }
            }
            inv_mid_end=get_inv_img(mid_end_jizhun.x ,mid_end_jizhun.y);
            inv_mid_end.x=inv_mid_end.x-((1.0*ROAD_WIDE+(inv_distance[mid_end_jizhun.x])/20)/2);
            mid_end=get_invinv_img(inv_mid_end.x,inv_mid_end.y);
      }
      if( mid_end_jizhun_flag)
      {
            double line_k,line_b;
            int16 mid_x,mid_y;
            line_k=(1.0)*(midline[mid_temp_row]-mid_end.y)/(mid_temp_row-mid_end.x);
            line_b=(-1.0)*(midline[mid_temp_row]-mid_end.y)/(mid_temp_row-mid_end.x)*mid_end.x + mid_end.y;
            for(int16 i = mid_temp_row;i>= mid_end.x;i--)
            {
                  mid_x=i;
                  mid_y =round( line_k *mid_x + line_b);
                  if(( mid_x >=ROW_START) && (mid_x <= ROW_END) && (mid_y>=COL_START) && (mid_y <= COL_END))
                  {
                        midline[mid_x]=mid_y;
                        //mid_temp_row=mid_x;            
                  }
            }
      }
}

/***********************************************************************************************************************************/

void midline_jizhun_search(int16 i)   //��׼������������
{
      //�һ�׼
      for(int16 ii=10;ii<CAMERA_H;ii++)//�ҵ����ұ��Ǹ���
      {
            if(img_data[ii][i]==0&&img_data[ii-1][i]==0&&img_data[ii+1][i]==255&&img_data[ii+10][i]==255)
            {
                  mid_end_jizhun.x=ii;
                  mid_end_jizhun.y=i;
                  mid_end_jizhun_flag=1;
                  break;
            }
      }
}

/***********************************************************************************************************************************/

void middle_down()                    //��ȡ�������ߺ���
{
      int16 down_row,down_col,down_edge_num,xx;
      float x,y;
      midline_down_num=0;         //������ȡ���ظ�����  0
      
      if( L_TURN==1 &&  R_end_row!=-1 )     //���ж�����Ϊ��ת�������ұ��ؽ����д��ڣ���ʼ��������������
      {
            down_edge_num=0;                     //�����½����ظ�����  0
            down_row=R_end_row-1;                //����ʼ�и���ֵ
            for( xx=R_end_row ; xx<ROW_END ;xx++ )
            {
                  if( right_edge[xx+1]-right_edge[xx]>=END_COL )    //ȷ�������ʼ��
                  {
                        down_row++;
                  }
                  else
                  {
                        break;
                  }
            }
            down_col=right_edge[down_row+1];      //����ʼ�и���ֵ
            for( midline_down_num=0 ;  midline_down_num<MIDDLE_DOWN_NUM ; midline_down_num++ )
            {
                  down_col=down_col-DOWN_COL;     //�����ƶ�����
                  if( down_row>ROW_END || down_col<COL_START )        //����ͼ��Χ��ֹͣ����
                  {
                        midline_down_num--;
                        
                        break;
                  }
                  if( down_edge_num<R_LINK_NUM )  //��ǰ�������½����ص�
                  {
                        if( down_col>right_down_edge[down_edge_num] )   //δ����ǰ���½����ص�
                        {
                              midline_down_inv[midline_down_num].y = (INV_A*down_col+INV_B*down_row+INV_C)/(INV_G*down_col+INV_H*down_row+1);    //����������͸������
                              midline_down_inv[midline_down_num].x = (INV_D*down_col+INV_E*down_row+INV_F)/(INV_G*down_col+INV_H*down_row+1);    //����������͸������
                              midline_down_inv[midline_down_num].x=midline_down_inv[midline_down_num].x-wide/2;
                              
                              x=midline_down_inv[midline_down_num].x;
                              y=midline_down_inv[midline_down_num].y;
                              
                              midline_down_y[midline_down_num]=(INV_B*INV_F-INV_C*INV_E+INV_E*y-INV_B*x-INV_F*INV_H*y+INV_C*INV_H*x)/(INV_A*INV_E-INV_B*INV_D+INV_D*INV_H*y-INV_E*INV_G*y-INV_A*INV_H*x+INV_B*INV_G*x)-1;     //��������ԭʼ����
                              midline_down_x[midline_down_num]=-(INV_A*INV_F-INV_C*INV_D+INV_D*y-INV_A*x-INV_F*INV_G*y+INV_C*INV_G*x)/(INV_A*INV_E-INV_B*INV_D+INV_D*INV_H*y-INV_E*INV_G*y-INV_A*INV_H*x+INV_B*INV_G*x)-1;    //��������ԭʼ����
                              
                              if( midline_down_x[midline_down_num]<ROW_START || midline_down_x[midline_down_num]>ROW_END || midline_down_y[midline_down_num]<COL_START || midline_down_y[midline_down_num]>COL_END )
                              {
                                    midline_down_x[midline_down_num]=-1;
                                    midline_down_y[midline_down_num]=-1;
                                    midline_down_num--;
                              }
                        }
                        else   //����ǰ���½����ص�
                        {
                              down_row++;        //��ֵ��һ
                              down_edge_num++;   //�����½����ظ�����һ
                              
                              midline_down_inv[midline_down_num].y = (INV_A*down_col+INV_B*down_row+INV_C)/(INV_G*down_col+INV_H*down_row+1);    //����������͸������
                              midline_down_inv[midline_down_num].x = (INV_D*down_col+INV_E*down_row+INV_F)/(INV_G*down_col+INV_H*down_row+1);    //����������͸������
                              midline_down_inv[midline_down_num].x=midline_down_inv[midline_down_num].x-wide/2;
                              
                              x=midline_down_inv[midline_down_num].x;
                              y=midline_down_inv[midline_down_num].y;
                              
                              midline_down_y[midline_down_num]=(INV_B*INV_F-INV_C*INV_E+INV_E*y-INV_B*x-INV_F*INV_H*y+INV_C*INV_H*x)/(INV_A*INV_E-INV_B*INV_D+INV_D*INV_H*y-INV_E*INV_G*y-INV_A*INV_H*x+INV_B*INV_G*x)-1;     //��������ԭʼ����
                              midline_down_x[midline_down_num]=-(INV_A*INV_F-INV_C*INV_D+INV_D*y-INV_A*x-INV_F*INV_G*y+INV_C*INV_G*x)/(INV_A*INV_E-INV_B*INV_D+INV_D*INV_H*y-INV_E*INV_G*y-INV_A*INV_H*x+INV_B*INV_G*x)-1;    //��������ԭʼ����
                              
                              if( midline_down_x[midline_down_num]<ROW_START || midline_down_x[midline_down_num]>ROW_END || midline_down_y[midline_down_num]<COL_START || midline_down_y[midline_down_num]>COL_END )
                              {
                                    midline_down_x[midline_down_num]=-1;
                                    midline_down_y[midline_down_num]=-1;
                                    midline_down_num--;
                              }
                        }
                  }
                  else                            //��ǰ���������½����ص�
                  {
                        midline_down_inv[midline_down_num].y = (INV_A*down_col+INV_B*down_row+INV_C)/(INV_G*down_col+INV_H*down_row+1);    //����������͸������
                        midline_down_inv[midline_down_num].x = (INV_D*down_col+INV_E*down_row+INV_F)/(INV_G*down_col+INV_H*down_row+1);    //����������͸������
                        midline_down_inv[midline_down_num].x=midline_down_inv[midline_down_num].x-wide/2;
                        
                        x=midline_down_inv[midline_down_num].x;
                        y=midline_down_inv[midline_down_num].y;
                        
                        midline_down_y[midline_down_num]=(INV_B*INV_F-INV_C*INV_E+INV_E*y-INV_B*x-INV_F*INV_H*y+INV_C*INV_H*x)/(INV_A*INV_E-INV_B*INV_D+INV_D*INV_H*y-INV_E*INV_G*y-INV_A*INV_H*x+INV_B*INV_G*x)-1;     //��������ԭʼ����
                        midline_down_x[midline_down_num]=-(INV_A*INV_F-INV_C*INV_D+INV_D*y-INV_A*x-INV_F*INV_G*y+INV_C*INV_G*x)/(INV_A*INV_E-INV_B*INV_D+INV_D*INV_H*y-INV_E*INV_G*y-INV_A*INV_H*x+INV_B*INV_G*x)-1;    //��������ԭʼ����
                        
                        if( midline_down_x[midline_down_num]<ROW_START || midline_down_x[midline_down_num]>ROW_END || midline_down_y[midline_down_num]<COL_START || midline_down_y[midline_down_num]>COL_END )
                        {
                              midline_down_x[midline_down_num]=-1;
                              midline_down_y[midline_down_num]=-1;
                              midline_down_num--;
                        }
                  }
            }
            midline_down_num++;    //�ó�ʵ�ʺ��������߸���
      }
      
      if( R_TURN==1 &&  L_end_row!=-1 )     //���ж�����Ϊ��ת����������ؽ����д��ڣ���ʼ��������������
      {
            down_edge_num=0;                     //�����½����ظ�����  0
            down_row=L_end_row-1;                //����ʼ�и���ֵ
            for( xx=L_end_row ; xx<ROW_END ; xx++ )
            {
                  if( left_edge[xx]-left_edge[xx+1]>=END_COL )    //ȷ�������ʼ��
                  {
                        down_row++;
                  }
                  else
                  {
                        break;
                  }
            }
            down_col=left_edge[down_row+1];      //����ʼ�и���ֵ
            for( midline_down_num=0 ;  midline_down_num<MIDDLE_DOWN_NUM ; midline_down_num++ )
            {
                  down_col=down_col+DOWN_COL;     //�����ƶ�����
                  if( down_row>ROW_END || down_col>COL_END )        //����ͼ��Χ��ֹͣ����
                  {
                        midline_down_num--;
                        
                        break;
                  }
                  if( down_edge_num<R_LINK_NUM )  //��ǰ�������½����ص�
                  {
                        if( down_col<left_down_edge[down_edge_num] )   //δ����ǰ���½����ص�
                        {
                              midline_down_inv[midline_down_num].y = (INV_A*down_col+INV_B*down_row+INV_C)/(INV_G*down_col+INV_H*down_row+1);    //����������͸������
                              midline_down_inv[midline_down_num].x = (INV_D*down_col+INV_E*down_row+INV_F)/(INV_G*down_col+INV_H*down_row+1);    //����������͸������
                              midline_down_inv[midline_down_num].x=midline_down_inv[midline_down_num].x-wide/2;
                              
                              x=midline_down_inv[midline_down_num].x;
                              y=midline_down_inv[midline_down_num].y;
                              
                              midline_down_y[midline_down_num]=(INV_B*INV_F-INV_C*INV_E+INV_E*y-INV_B*x-INV_F*INV_H*y+INV_C*INV_H*x)/(INV_A*INV_E-INV_B*INV_D+INV_D*INV_H*y-INV_E*INV_G*y-INV_A*INV_H*x+INV_B*INV_G*x)-1;     //��������ԭʼ����
                              midline_down_x[midline_down_num]=-(INV_A*INV_F-INV_C*INV_D+INV_D*y-INV_A*x-INV_F*INV_G*y+INV_C*INV_G*x)/(INV_A*INV_E-INV_B*INV_D+INV_D*INV_H*y-INV_E*INV_G*y-INV_A*INV_H*x+INV_B*INV_G*x)-1;    //��������ԭʼ����
                              
                              if( midline_down_x[midline_down_num]<ROW_START || midline_down_x[midline_down_num]>ROW_END || midline_down_y[midline_down_num]<COL_START || midline_down_y[midline_down_num]>COL_END )
                              {
                                    midline_down_x[midline_down_num]=-1;
                                    midline_down_y[midline_down_num]=-1;
                                    midline_down_num--;
                              }
                        }
                        else   //����ǰ���½����ص�
                        {
                              down_row++;        //��ֵ��һ
                              down_edge_num++;   //�����½����ظ�����һ
                              
                              midline_down_inv[midline_down_num].y = (INV_A*down_col+INV_B*down_row+INV_C)/(INV_G*down_col+INV_H*down_row+1);    //����������͸������
                              midline_down_inv[midline_down_num].x = (INV_D*down_col+INV_E*down_row+INV_F)/(INV_G*down_col+INV_H*down_row+1);    //����������͸������
                              midline_down_inv[midline_down_num].x=midline_down_inv[midline_down_num].x-wide/2;
                              
                              x=midline_down_inv[midline_down_num].x;
                              y=midline_down_inv[midline_down_num].y;
                              
                              midline_down_y[midline_down_num]=(INV_B*INV_F-INV_C*INV_E+INV_E*y-INV_B*x-INV_F*INV_H*y+INV_C*INV_H*x)/(INV_A*INV_E-INV_B*INV_D+INV_D*INV_H*y-INV_E*INV_G*y-INV_A*INV_H*x+INV_B*INV_G*x)-1;     //��������ԭʼ����
                              midline_down_x[midline_down_num]=-(INV_A*INV_F-INV_C*INV_D+INV_D*y-INV_A*x-INV_F*INV_G*y+INV_C*INV_G*x)/(INV_A*INV_E-INV_B*INV_D+INV_D*INV_H*y-INV_E*INV_G*y-INV_A*INV_H*x+INV_B*INV_G*x)-1;    //��������ԭʼ����
                              
                              if( midline_down_x[midline_down_num]<ROW_START || midline_down_x[midline_down_num]>ROW_END || midline_down_y[midline_down_num]<COL_START || midline_down_y[midline_down_num]>COL_END )
                              {
                                    midline_down_x[midline_down_num]=-1;
                                    midline_down_y[midline_down_num]=-1;
                                    midline_down_num--;
                              }
                        }
                  }
                  else                            //��ǰ���������½����ص�
                  {
                        midline_down_inv[midline_down_num].y = (INV_A*down_col+INV_B*down_row+INV_C)/(INV_G*down_col+INV_H*down_row+1);    //����������͸������
                        midline_down_inv[midline_down_num].x = (INV_D*down_col+INV_E*down_row+INV_F)/(INV_G*down_col+INV_H*down_row+1);    //����������͸������
                        midline_down_inv[midline_down_num].x=midline_down_inv[midline_down_num].x-wide/2;
                        
                        x=midline_down_inv[midline_down_num].x;
                        y=midline_down_inv[midline_down_num].y;
                        
                        midline_down_y[midline_down_num]=(INV_B*INV_F-INV_C*INV_E+INV_E*y-INV_B*x-INV_F*INV_H*y+INV_C*INV_H*x)/(INV_A*INV_E-INV_B*INV_D+INV_D*INV_H*y-INV_E*INV_G*y-INV_A*INV_H*x+INV_B*INV_G*x)-1;     //��������ԭʼ����
                        midline_down_x[midline_down_num]=-(INV_A*INV_F-INV_C*INV_D+INV_D*y-INV_A*x-INV_F*INV_G*y+INV_C*INV_G*x)/(INV_A*INV_E-INV_B*INV_D+INV_D*INV_H*y-INV_E*INV_G*y-INV_A*INV_H*x+INV_B*INV_G*x)-1;    //��������ԭʼ����
                        
                        if( midline_down_x[midline_down_num]<ROW_START || midline_down_x[midline_down_num]>ROW_END || midline_down_y[midline_down_num]<COL_START || midline_down_y[midline_down_num]>COL_END )
                        {
                              midline_down_x[midline_down_num]=-1;
                              midline_down_y[midline_down_num]=-1;
                              midline_down_num--;
                        }
                  }
            }
            midline_down_num++;    //�ó�ʵ�ʺ��������߸���
      }
}

/***********************************************************************************************************************************/

void edge_edge_lvbo()                 //�����˲�����
{
      for(int16 i=ROW_END-10;i>=ROW_START+10;i--)
      {
            if(L_TURN && (left_edge[i+1]==-1)&& (left_edge[i+2]==-1) && (left_edge[i+3]==-1) &&(left_edge[i+10]==-1)&&((left_edge[i-1]==-1)||(left_edge[i-2]==-1)||(left_edge[i-3]==-1)||(left_edge[i-10]==-1)))
            {
                  left_edge[i]=-1;
            }
            if(R_TURN && (right_edge[i+1]==-1) && (right_edge[i+2]==-1) && (right_edge[i+3]==-1) && (right_edge[i+10]==-1)&&((right_edge[i-1]==-1)||(right_edge[i-2]==-1)||(right_edge[i-3]==-1)||(right_edge[i-10]==-1)))
            {
                  right_edge[i]=-1;
            }
      }
}

/***********************************************************************************************************************************/

void midline_lvbo()                   //�����˲�����
{
      int16 row_next, row_now,row_last;
      uint8 row_now_flag,row_next_flag,row_last_flag;
      int16 ii,jj;
      row_next=-1;
      row_now=-1; 
      row_last=-1;
      ii=ROW_START-1;
      if(/*( s_flag==0)&&*/(LOOP_TEMP==0))
      {
            for(ii=ROW_END-1;ii>=ROW_START+1;ii--)
            {
                  row_now_flag=0;
                  if(midline[ii]!=-1)
                  {
                        row_now_flag=1;
                        row_now=ii;
                        row_last_flag=0;
                        for(jj=row_now-1;jj>=row_now-10;jj--)
                        { 
                              if(midline[jj]!=-1)
                              {
                                    row_last = jj;
                                    row_last_flag=1;
                                    break;
                              }
                        }
                        if(row_last_flag==1)
                        {
                              row_next_flag=0;
                              for(jj=row_now+1;jj<=row_now+10;jj++)
                              { 
                                    if(midline[jj]!=-1)
                                    {
                                          row_next = jj;
                                          row_next_flag=1;
                                          break;
                                    }
                              }
                        }    
                  }
                  
                  if((row_now_flag) && (row_next_flag) && (row_last_flag))//����(ֻ��һ�����ʱ��û����)
                  {
                        if((((midline[row_next]-midline[row_now])*(midline[row_now]-midline[row_last])<=0)&&(abs(midline[row_next]+midline[row_last]-2*midline[row_now])>=40)) || (((midline[row_next]-midline[row_now])*(midline[row_now]-midline[row_last])>=0)&&(abs(midline[row_next]+midline[row_last]-2*midline[row_now])>=120)))
                        {
                              midline[row_now]=-1;
                        }
                  }
            }
      }
}

/***********************************************************************************************************************************/

void tingche()                        //����ͣ������
{
      int16 i1=0;
      for(int16 k =CAMERA_H-3;k>CAMERA_H-6;k--)
      {
            for(int16 j=0;j<CAMERA_W;j++)  
            { 
                  if(img_data[k][j]==DOT_B)
                        i1++;
            }
      }
      if(i1 >= CAMERA_W*3-5)
      {
            car_status = CAR_STOPP;
            QAQ_STOP=1;
      }
}

/***********************************************************************************************************************************/

void tingche2()                       //����ͣ������2
{
      int16 i1=0;
      for( int16 k=CAMERA_H-3 ; k>CAMERA_H-6 ; k-- )
      {
            for( int16 j=0 ; j<CAMERA_W ; j++ )  
            { 
                  if( img_barrel[k][j]<=TINGCHE_HUDU )
                  {
                        i1++;
                  }
            }
      }
      if( i1>=CAMERA_W*3-10 )
      {
            car_status=CAR_STOPP;
            QAQ_STOP=1;
      }
}

/***********************************************************************************************************************************/

void edge_add()                       //������Ӻ���
{
      int16 x,y;
      for( x=ROW_END ; x>=ROW_START ; x-- )
      {
            if( left_edge[x]!=-1 && left_edge[x]<=COL_END-5 )            //���˵���־λ-1�ĵ�
            {
                  img_data[x][left_edge[x]+4]=DOT_B;
                  img_data[x][left_edge[x]+5]=DOT_B;
            }
      }
      for( x=ROW_END ; x>=ROW_START ; x-- )
      {
            if( right_edge[x]!=-1 && right_edge[x]>=COL_START+5 )        //���˵���־λ-1�ĵ�
            {
                  img_data[x][right_edge[x]-4]=DOT_B;
                  img_data[x][right_edge[x]-5]=DOT_B;
            }
      }
      
      if( L_down_cross[0]!=-1 && L_down_cross[1]<=COL_END-14 )
      {
            img_data[L_down_cross[0]][L_down_cross[1]+8]=DOT_B;
            img_data[L_down_cross[0]][L_down_cross[1]+10]=DOT_B;
            img_data[L_down_cross[0]][L_down_cross[1]+12]=DOT_B;
            img_data[L_down_cross[0]][L_down_cross[1]+14]=DOT_B;
      }
      if( L_up_cross[0]!=-1 && L_up_cross[1]<=COL_END-14 )
      {
            img_data[L_up_cross[0]][L_up_cross[1]+8]=DOT_B;
            img_data[L_up_cross[0]][L_up_cross[1]+10]=DOT_B;
            img_data[L_up_cross[0]][L_up_cross[1]+12]=DOT_B;
            img_data[L_up_cross[0]][L_up_cross[1]+14]=DOT_B;
      }
      if( R_down_cross[0]!=-1 && R_down_cross[1]>=COL_START+14 )
      {
            img_data[R_down_cross[0]][R_down_cross[1]-8]=DOT_B;
            img_data[R_down_cross[0]][R_down_cross[1]-10]=DOT_B;
            img_data[R_down_cross[0]][R_down_cross[1]-12]=DOT_B;
            img_data[R_down_cross[0]][R_down_cross[1]-14]=DOT_B;
            
      }
      if( R_up_cross[0]!=-1 && R_up_cross[1]>=COL_START+14 )
      {
            img_data[R_up_cross[0]][R_up_cross[1]-8]=DOT_B;
            img_data[R_up_cross[0]][R_up_cross[1]-10]=DOT_B;
            img_data[R_up_cross[0]][R_up_cross[1]-12]=DOT_B;
            img_data[R_up_cross[0]][R_up_cross[1]-14]=DOT_B;
      }
//      if( R_TURN==1 || L_TURN==1 )
//      {
//            if( L_LINK_NUM>0 )
//            {
//                  y=0;
//                  for( x=L_end_row ; x<=L_end_row+L_LINK_NUM-1 ; x++ )
//                  {
//                        if( left_down_edge[y]>=COL_START+5 )
//                        {
//                              img_data[x][left_down_edge[y]-4]=DOT_B;
//                              img_data[x][left_down_edge[y]-5]=DOT_B;
//                              
//                              y++;
//                        }
//                  }
//            }
//            if( R_LINK_NUM>0 )
//            {
//                  y=0;
//                  for( x=R_end_row ; x<=R_end_row+R_LINK_NUM-1 ; x++ )
//                  {
//                        if( right_down_edge[y]<=COL_END-5 )
//                        {
//                              img_data[x][right_down_edge[y]+4]=DOT_B;
//                              img_data[x][right_down_edge[y]+5]=DOT_B;
//                              
//                              y++;
//                        }
//                  }
//            }
//      }
}

/***********************************************************************************************************************************/

void midline_add()                    //������Ӻ���
{
      int16 a,x;
      for(x=ROW_END;x>=ROW_START;x--)
      {
            
            if( midline[x]!=-1 )
            {
                  if(  midline[x]==COL_END )
                  {
                        a=midline[x];
                        img_data[x][a-1]=DOT_B;
                        img_data[x][a]=DOT_B;
                  }
                  else
                  {
                        a=midline[x];
                        img_data[x][a]=DOT_B;
                        img_data[x][a+1]=DOT_B;
                  }
            }
      }
      //      for( x=0 ; x<midline_down_num ; x++ )
      //      {
      //            img_data[midline_down_x[x]][midline_down_y[x]]=DOT_B;
      //            img_data[midline_down_x[x]][midline_down_y[x]+1]=DOT_B;
      //      }
}

/***********************************************************************************************************************************/

void jizhun_add()                     //��׼����Ӻ���
{
      int16 x;
      for(x=JIZHUN_DOWN;x>=JIZHUN_UP;x=x-2)
      {
            img_data[x][CAMERA_W/2]=DOT_B;
            img_data[x][(CAMERA_W/2-1)]=DOT_B;
      }
}

/***********************************************************************************************************************************/

void get_inv_edge()                   //��ȡ��͸�ӱ��غ���
{
//      for(uint8 ii=0;ii<CAMERA_H;ii++)
//      {
//            if( left_edge[ii]!=-1 )
//            {
//                  inv_left_edge[ii]=get_inv_img( ii , left_edge[ii] );
//            }
//            else
//            {
//                  inv_left_edge[ii].y = -1;
//                  inv_left_edge[ii].x = -1;
//            }
//            if( right_edge[ii]!=-1 )
//            {
//                  inv_right_edge[ii]=get_inv_img( ii , right_edge[ii] );
//            }
//            else
//            {
//                  inv_right_edge[ii].y = -1;
//                  inv_right_edge[ii].x = -1;
//            }
//      }
      
      
      
      if( LOOP_TEMP==0 && car_L_pull_over_flag==0 && car_R_pull_over_flag==0 )   //����Ϊ�����ͳ���״̬ʱ
      {
            for(uint8 ii=0;ii<CAMERA_H;ii++)
            {
                  if( left_edge[ii]!=-1 && right_edge[ii]==-1 )
                  {
                        inv_left_edge[ii]=get_inv_img( ii , left_edge[ii] );
                        inv_right_edge[ii].y = -1;
                        inv_right_edge[ii].x = -1;
                  }
                  if( left_edge[ii]==-1 && right_edge[ii]!=-1 )
                  {
                        inv_left_edge[ii].y = -1;
                        inv_left_edge[ii].x = -1;
                        inv_right_edge[ii]=get_inv_img( ii , right_edge[ii] );
                  }
                  if( left_edge[ii]!=-1 && right_edge[ii]!=-1 )
                  {
                        inv_left_edge[ii].y = -1;
                        inv_left_edge[ii].x = -1;
                        inv_right_edge[ii].y = -1;
                        inv_right_edge[ii].x = -1;
                  }
                  if( left_edge[ii]==-1 && right_edge[ii]==-1 )
                  {
                        inv_left_edge[ii].y = -1;
                        inv_left_edge[ii].x = -1;
                        inv_right_edge[ii].y = -1;
                        inv_right_edge[ii].x = -1;
                  }
            }
      }
      else   //��Ϊ�����ͳ���״̬ʱ
      {
            if( LOOP_TEMP==1 )    //��Ϊ����ʱ
            {
                  if( LOOP_IN==1 )   //�����뻷��
                  {
                        if( LOOP_OUT==0 )
                        {
                              if( loop_l_r_flag==1 )   //������Ϊ��ת
                              {
                                    for(uint8 ii=0;ii<CAMERA_H;ii++)
                                    {
                                          if( left_edge[ii]!=-1 )
                                          {
                                                inv_left_edge[ii]=get_inv_img( ii , left_edge[ii] );
                                          }
                                          else
                                          {
                                                inv_left_edge[ii].y = -1;
                                                inv_left_edge[ii].x = -1;
                                          }
                                    }
                                    if( LOOP_OUT==1 )   //��Ҫ���뻷��
                                    {
                                          for(uint8 ii=0;ii<CAMERA_H;ii++)
                                          {
                                                if( right_edge[ii]!=-1 )
                                                {
                                                      inv_right_edge[ii]=get_inv_img( ii , right_edge[ii] );
                                                }
                                                else
                                                {
                                                      inv_right_edge[ii].y = -1;
                                                      inv_right_edge[ii].x = -1;
                                                }
                                          }
                                    }
                              }
                              else   //������Ϊ��ת
                              {
                                    for(uint8 ii=0;ii<CAMERA_H;ii++)
                                    {
                                          if( right_edge[ii]!=-1 )
                                          {
                                                inv_right_edge[ii]=get_inv_img( ii , right_edge[ii] );
                                          }
                                          else
                                          {
                                                inv_right_edge[ii].y = -1;
                                                inv_right_edge[ii].x = -1;
                                          }
                                    }
                                    if( LOOP_OUT==1 )   //��Ҫ���뻷��
                                    {
                                          for(uint8 ii=0;ii<CAMERA_H;ii++)
                                          {
                                                for(uint8 ii=0;ii<CAMERA_H;ii++)
                                                {
                                                      if( left_edge[ii]!=-1 )
                                                      {
                                                            inv_left_edge[ii]=get_inv_img( ii , left_edge[ii] );
                                                      }
                                                      else
                                                      {
                                                            inv_left_edge[ii].y = -1;
                                                            inv_left_edge[ii].x = -1;
                                                      }
                                                }
                                          }
                                    }
                              }
                        }
                        else
                        {
                              for(uint8 ii=0;ii<CAMERA_H;ii++)
                              {
                                    if( left_edge[ii]!=-1 && right_edge[ii]==-1 )
                                    {
                                          inv_left_edge[ii]=get_inv_img( ii , left_edge[ii] );
                                          inv_right_edge[ii].y = -1;
                                          inv_right_edge[ii].x = -1;
                                    }
                                    if( left_edge[ii]==-1 && right_edge[ii]!=-1 )
                                    {
                                          inv_left_edge[ii].y = -1;
                                          inv_left_edge[ii].x = -1;
                                          inv_right_edge[ii]=get_inv_img( ii , right_edge[ii] );
                                    }
                                    if( left_edge[ii]!=-1 && right_edge[ii]!=-1 )
                                    {
                                          inv_left_edge[ii].y = -1;
                                          inv_left_edge[ii].x = -1;
                                          inv_right_edge[ii].y = -1;
                                          inv_right_edge[ii].x = -1;
                                    }
                                    if( left_edge[ii]==-1 && right_edge[ii]==-1 )
                                    {
                                          inv_left_edge[ii].y = -1;
                                          inv_left_edge[ii].x = -1;
                                          inv_right_edge[ii].y = -1;
                                          inv_right_edge[ii].x = -1;
                                    }
                              }
                        }
                  }
            }
            else    //��Ϊ����״̬ʱ
            {
                  if( car_L_pull_over_flag==1 )    //��Ϊ�������ͣ��״̬ʱ
                  {
                        for(uint8 ii=0;ii<CAMERA_H;ii++)
                        {
                              if( left_edge[ii]!=-1 )
                              {
                                    inv_left_edge[ii]=get_inv_img( ii , left_edge[ii] );
                              }
                              else
                              {
                                    inv_left_edge[ii].y = -1;
                                    inv_left_edge[ii].x = -1;
                              }
                        }
                  }
                  else
                  {
                        if( car_R_pull_over_flag==1 )    //��Ϊ�����Ҳ�ͣ��״̬ʱ
                        {
                              for(uint8 ii=0;ii<CAMERA_H;ii++)
                              {
                                    if( right_edge[ii]!=-1 )
                                    {
                                          inv_right_edge[ii]=get_inv_img( ii , right_edge[ii] );
                                    }
                                    else
                                    {
                                          inv_right_edge[ii].y = -1;
                                          inv_right_edge[ii].x = -1;
                                    }
                              }
                        }
                  }
            }
      }
}

/***********************************************************************************************************************************/

Site_xy get_inv_img(int16 xxx ,int16 yyy)        //��͸�ӣ�xxxΪͼ���У�yyyΪ�У�
{
      Site_xy temp;
      xxx++;
      yyy++;
      temp.y = (INV_A*yyy+INV_B*xxx+INV_C)/(INV_G*yyy+INV_H*xxx+1);
      temp.x = (INV_D*yyy+INV_E*xxx+INV_F)/(INV_G*yyy+INV_H*xxx+1);
      return temp;
}

/***********************************************************************************************************************************/

Site_xy1 get_invinv_img(double xxx,double yyy) //����͸�ӣ�xxxΪʵ���У�yyyΪ�У�
{
      Site_xy1 temp;
      double uSrcImg,vSrcImg;//����͸������
      uSrcImg =(INV_B*INV_F - INV_C*INV_E + INV_E*yyy - INV_B*xxx - INV_F*INV_H*yyy + INV_C*INV_H*xxx)/(INV_A*INV_E - INV_B*INV_D + INV_D*INV_H*yyy - INV_E*INV_G*yyy - INV_A*INV_H*xxx + INV_B*INV_G*xxx);
      vSrcImg =-(INV_A*INV_F - INV_C*INV_D + INV_D*yyy - INV_A*xxx - INV_F*INV_G*yyy + INV_C*INV_G*xxx)/(INV_A*INV_E - INV_B*INV_D + INV_D*INV_H*yyy - INV_E*INV_G*yyy - INV_A*INV_H*xxx + INV_B*INV_G*xxx);
      
      temp.x=round(vSrcImg-1);
      temp.y=round(uSrcImg-1);
      return temp;
}

/***********************************************************************************************************************************/



