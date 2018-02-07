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
#include "OV7725.h"
#include "SD5.h"
#include "Speed.h"
#include "data_handle.h"

/*��ȡ���ߵ�����*/
#define  midline1_H      28
#define  midline2_H      30
#define  midline3_H      35

extern uint8 img[CAMERA_H][CAMERA_W];                      //����洢ת�����ͼ��Ķ�ά����
extern uint8 imgbuff[CAMERA_SIZE];                         //����洢����ԭʼͼ���һά����
//extern uint8 imgzhongxian[CAMERA_H][CAMERA_W];             //����洢���ߵĶ�ά����
extern uint8  SD5_flag;     //���״̬
 uint8  left_flag,right_flag,SD5_flag1,SD5_flag2;

 
/*!
 *  @brief      main����
 *  @since      v5.3
 *  @note       ɽ������ͷ LCD ����ʵ��
 */
void  main(void)
{
       OV7725_Init();
       LCD_init();
       SD5_Init();
       SD5_PID_Init();
       RS540_Init();

       Site_t site = { 0, 0 };                              //��ʾͼ�����Ͻ�λ��
       Size_t imgsize = { CAMERA_W, CAMERA_H };                       //ͼ���С
       Size_t size = { LCD_W, LCD_H };                      //��ʾ����ͼ���С

       int i,j,left_back,right_back,n;
       uint8 zhongxian[CAMERA_H][CAMERA_W];
	   uint8 midline1_L, midline2_L, midline3_L;            //������ȡ��������������
       float average;
       int SD5_Duty;
       uint8 RS540_Duty = 170;


       
    while(1)
    {
      SD5_flag=SD5_Normal;
       RS540_Turn(RS540_Duty);
	   Get_img();                      //��ȡͼ��

	/***********************��ʾ��ѹ���ͼ��Һ��*******************************/
   
          //zhongxian((uint8*)img,(uint8*)zhongxian);
           for(i=0;i<CAMERA_H;i++)
             for(j=0;j<CAMERA_W;j++)
               zhongxian[i][j]=255;

           
     for(i=CAMERA_H-1;i>CAMERA_H-4;i--)              //��ȡǰ��������
      {
          for(j=CAMERA_W/2;j<CAMERA_W;j++)
          {
            if(img[i][j]==0xff&&img[i][j+1]==0x00)
              {
                   left_back=j;
                   left_flag=1;                   
                  break;
              }
              else 
              {
                left_flag=0;
                left_back=CAMERA_W-10;
              }
          }
          for(j=CAMERA_W/2;j>0;j--)
          {
              if(img[i][j]==0xff&&img[i][j-1]==0x00)
                  {
                    right_back=j;
                    right_flag=1;
                    break;                                                                                                                                        
                  }
              else 
              {
                right_flag=0;
                right_back=10;
              }
          }
//          if(right_flag==1&&left_flag==1)
//          {
          n=(right_back+left_back)/2;
           img[i][n]=0;
           zhongxian[i][n]=0;
          //}
       }
       
        for(i=CAMERA_H-4;i>0;i--)              //��ȡ����
       {
          for(j=left_back-10;j<left_back+10;j++)
          {
            if(img[i][j]==0xff&&img[i][j+1]==0x00)
              {
                   left_back=j;
                   left_flag=1;                   
                  break;
              }
              else left_flag=0;
          }
          for(j=right_back+10;j>right_back-10;j--)
          {
              if(img[i][j]==0xff&&img[i][j-1]==0x00)
                  {
                    right_back=j;
                    right_flag=1;
                    break;                                                                                                                                        
                  }
              else right_flag=0;
          }

          n=(right_back+left_back)/2;
          
          if(i==midline1_H)
          {
            midline1_L=n;
//            if(left_flag==0&&right_flag==1)
//              SD5_flag1=0;
//            if(right_flag==0&&left_flag==1)
//              SD5_flag1=1;
          }
          if(i==midline2_H)
          {
            midline2_L=n;
//            if(left_flag==0&&right_flag==1)
//              SD5_flag2=0;
//            if(right_flag==0&&left_flag==1)
//              SD5_flag2=1;
          }
          if(i==midline3_H)
            midline3_L=n;
          
         
//             if(SD5_flag1==0&&SD5_flag2==0)    //����ؼ�ⲻ��
//               SD5_flag= SD5_Left;          //���������
//             if(SD5_flag1==1&&SD5_flag2==1)    //�ұ��ؼ�ⲻ��
//               SD5_flag= SD5_Right;          //�����Ҵ���
        
         
          average=(midline1_L*0.4+midline2_L*0.3+midline3_L*0.3)-CAMERA_W/2;
          
           if (abs(average) < 10 )
		  {
			  RS540_Duty = 170;
		  }
		  else if (abs(RS540_Duty) > 50)
		  {
			  RS540_Duty = 150;
		  }
		  else
		  {
			  RS540_Duty = 170;
		  }
            
           if(average>10)
              average=average*3.5;
            else
              average=average*2.3;

		 

           img[i][n]=0;
           zhongxian[i][n]=0;

           
       }

          SD5_Contral(average);

	  LCD_Img_gray_Z(site, size,(uint8*) img, imgsize);
	/****************************************************************************/
	
    }
}






