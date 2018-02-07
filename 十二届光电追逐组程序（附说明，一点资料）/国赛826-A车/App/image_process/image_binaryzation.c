#include "include.h"
#include "common.h"

/***********************************************************************************************************************************/

uint8 img_data[CAMERA_H][ CAMERA_W ];

uint8 gray_start=0;
uint8 gray_end=255;
uint16 gray_wide=256;



image_pixel pixel_sort[256];

uint8 img_threshold;
uint8 img_threshold0;
uint8 img_thresholdbu;
uint8 Step_yu=0xFF;
uint8 Step=1;
uint8 erzhi_flag=0;
double black_sum_pro=0;
double white_sum_pro=0;
double deltaTmp;
double gray_mean;
double u0;//��һ���ƽ���Ҷ� ����
double u1; //�ڶ����ƽ���Ҷ�  ǰ��
double gray_add_pro=0.0;

/***********************************************************************************************************************************/

uint8 binary_process(uint8 location,uint8 height_start,uint8 height_end);     //ͼ���ֵ������ֵ�㷨
void img_binary();                                                           //ͼ���ֵ��������
void bubble_sort( uint16 n);                                                 //ð��������

/***********************************************************************************************************************************/

void img_binary()        //ͼ���ֵ��������
{
      img_threshold=binary_process(1,0,CAMERA_H);
      if(img_threshold<other4_c*100)
      {img_threshold=other4_c*100;}
      img_threshold0=img_threshold+other4_a*100;
      gray_wide=gray_end-gray_start;
      
      for( uint8 ii=HEIGHT_STRAT ; ii<HEIGHT_END ; ii++ )
      {
            for( uint8 jj=0 ; jj< CAMERA_W ; jj++ )
            {
                  if( img_barrel[ii][jj]>img_threshold0 )
                  {
                        img_data[ii][jj]=255;
                  }
                  else
                  {
                        img_data[ii][jj]=0;
                  }
            }    
      } 
}


/***********************************************************************************************************************************/

uint8 binary_process(uint8 location,uint8 height_start,uint8 height_end)      //ͼ���ֵ������ֵ�㷨  /*����㷨  ��*/
{
      /**����ͼ�� ֻ��Ҫ����20-60��**/
      
      uint8 width = CAMERA_W; //ͼ���
      uint8 width_start=0;
      uint8 x=0;  
      
      uint16 i, j;  
      uint16 pixelSum=(width-width_start)*(height_end-height_start);    //ͼ�����ص�����
      uint16 pixelCount[256]={0};      //ͼ�����ػҶ��ݶ���ֵͳ������
      double pixelPro[256]={0};        //ͼ�����ػҶ��ݶȱ�����������
      
      uint8 i_left,i_right;
      
      
      /**ͳ��  �Ȳ�  �Ҷȼ���ÿ������������ͼ���еĸ���**/
      
      if( location==1 )
      {
            for( i=height_start ; i<height_end ; i=i+1 )
            {
                  for( j=x ; j<width ; j+=1 )
                  {
                        pixelCount[img_barrel[i][j]&Step_yu]++;
                  }
            }
      }
      else
      {
            for( i=height_start ; i<height_end ; i=i+1 )
            {
                  for( j=x ; j<width ; j+=1 )
                  {
                        pixelCount[img_barrel[i][j]&Step_yu]++;
                  }
            }
      }
      
      uint8 start_ok=0;
      for( i=0 ; i<256 ; i=i+Step )
      {
            if( pixelCount[i] )
            {
                  gray_end=i;
                  start_ok=1;
            }
            else if(!start_ok)
            {
                  gray_start=i;
            }
      }
      
      
      /**����ÿ������������ͼ���еı���**/
      
      gray_mean=0;
      for( i=0; i<=gray_end ; i=i+Step )
      {
            pixelPro[i]=(double)(pixelCount[i])/(double)(pixelSum);
            gray_mean=i*pixelPro[i]+gray_mean;
      }
      
      
      uint8 s_gray_mean=(uint8)gray_mean;
      
      uint32 q_gray_mean=0,h_gray_mean=0;
      uint32 q_sum=0,h_sum=0;
      
      for( i=gray_start ; i<=gray_end ; i=i+Step )
      {
            if( i<s_gray_mean )
            {
                  q_sum=q_sum+pixelCount[i];
                  
                  q_gray_mean=i*pixelCount[i]+q_gray_mean;
            }
            else
            {
                  h_sum=h_sum+pixelCount[i];
                  
                  h_gray_mean=i*pixelCount[i]+h_gray_mean;
            }
      }
      
      q_gray_mean=q_gray_mean/q_sum;
      h_gray_mean=h_gray_mean/h_sum;  
      
      //��ȡƽ���Ҷ�ֵ
      
      
      //����ostu�㷨,�õ�ǰ���ͱ����ķָ�  
      //�����Ҷȼ�[0,255],������������ĻҶ�ֵ,Ϊ�����ֵ  
      double q_w0, q_w1, q_u0tmp, q_u1tmp, q_u0, q_u1, q_u;  
      double h_w0, h_w1, h_u0tmp, h_u1tmp, h_u0, h_u1, h_u; 
      double deltaTmp_left,deltaTmp_right;
      q_w0 = q_w1 = q_u0tmp = q_u1tmp = q_u0 = q_u1 = q_u  = 0;  
      h_w0 = h_w1 = h_u0tmp = h_u1tmp = h_u0 = h_u1 = h_u  = 0;  
      
      
      for(j = gray_start; j <=gray_end; j=j+Step)  
      {  
            if(j <= h_gray_mean) //��������  
            {  
                  //��iΪ��ֵ���࣬��һ���ܵĸ���  
                  h_w0 += pixelPro[j];        
                  h_u0tmp += j * pixelPro[j];  
            }  
            else       //ǰ������  
            {  
                  //��iΪ��ֵ���࣬�ڶ����ܵĸ���  
                  h_w1 += pixelPro[j];        
                  h_u1tmp += j * pixelPro[j];  
            }  
            if(j <= q_gray_mean) //��������  
            {  
                  //��iΪ��ֵ���࣬��һ���ܵĸ���  
                  q_w0 += pixelPro[j];        
                  q_u0tmp += j * pixelPro[j];  
            }  
            else       //ǰ������  
            {  
                  //��iΪ��ֵ���࣬�ڶ����ܵĸ���  
                  q_w1 += pixelPro[j];        
                  q_u1tmp += j * pixelPro[j];  
            }  
      }  
      
      q_u0 = q_u0tmp / q_w0;        //��һ���ƽ���Ҷ�  
      q_u1 = q_u1tmp / q_w1;        //�ڶ����ƽ���Ҷ�  
      q_u =  q_u0tmp + q_u1tmp;      //����ͼ���ƽ���Ҷ� 
      
      h_u0 = h_u0tmp / h_w0;        //��һ���ƽ���Ҷ�  
      h_u1 = h_u1tmp / h_w1;        //�ڶ����ƽ���Ҷ�  
      h_u = h_u0tmp + h_u1tmp;      //����ͼ���ƽ���Ҷ� 
      
      //������䷽�� 
      deltaTmp_left = q_w0 * (q_u0 - q_u)*(q_u0 - q_u) + q_w1 * (q_u1 - q_u)*(q_u1 - q_u);  
      deltaTmp_right= h_w0 * (h_u0 - h_u)*(h_u0 - h_u) + h_w1 * (h_u1 - h_u)*(h_u1 - h_u);  
      
      
      ///�����Ż�    ʹ�ö��ַ�
      double w0, w1, u0tmp, u1tmp, u ; 
      i_left=q_gray_mean;
      i_right=h_gray_mean;
      uint8 i_chaju=8;      
      //����2
      for(i = (i_left+i_right)>>1;i_right-i_left>i_chaju ; i=(i_left+i_right)>>1)  
      {  
            w0 = w1 = u0tmp = u1tmp = u0 = u1 = u = deltaTmp = 0;  
            
            for(j = gray_start; j <= gray_end; j=j+Step)  
            {  
                  if(j <= i) //��������  
                  {                                                                            
                        //��iΪ��ֵ���࣬��һ���ܵĸ���  
                        w0 += pixelPro[j];        
                        u0tmp += j * pixelPro[j];  
                  }  
                  else       //ǰ������  
                  {  
                        //��iΪ��ֵ���࣬�ڶ����ܵĸ���  
                        w1 += pixelPro[j];        
                        u1tmp += j * pixelPro[j];  
                  }  
            }  
            
            u0 = u0tmp / w0;        //��һ���ƽ���Ҷ�  
            u1 = u1tmp / w1;        //�ڶ����ƽ���Ҷ�  
            u = u0tmp + u1tmp;      //����ͼ���ƽ���Ҷ�  
            //������䷽��  
            deltaTmp = w0 * (u0 - u)*(u0 - u) + w1 * (u1 - u)*(u1 - u);  
            //�ҳ������䷽���Լ���Ӧ����ֵ 
            
            if(deltaTmp>=deltaTmp_left&&deltaTmp_right>=deltaTmp_left)
            {
                  //������ ��
                  i_left=i;
                  deltaTmp_left=deltaTmp;
            }
            else if(deltaTmp>=deltaTmp_right&&deltaTmp_left>=deltaTmp_right)
            {
                  //���� �� ��
                  i_right=i;
                  deltaTmp_right=deltaTmp;
            }
            ////�ų����ŵ�����³��ֵ�   �м��ֵ��С��ʱ��  ������ѭ����
            else if(deltaTmp<=deltaTmp_left&&deltaTmp<=deltaTmp_right)
            {
                  // ��������   ȡ����
                  if(deltaTmp_left>=deltaTmp_right)
                  {
                        i_right=i;               //�滻�ұ�
                        deltaTmp_right=deltaTmp;
                  }
                  else
                  {
                        i_left=i;                //�滻���
                        deltaTmp_left=deltaTmp;
                  }
            }
      }  
      black_sum_pro=w0;
      white_sum_pro=w1;
      //���������ֵ;     //i�������Ҷ�ֵ
      return i;
}

/***********************************************************************************************************************************/

void bubble_sort( uint16 n)
{
      uint16 i,j;
      image_pixel temp;
      for (j = 0; j < n - 1; j++)
      {   
            for (i = 0; i < n - 1 - j; i++)
            {
                  if( pixel_sort[i].x > pixel_sort[i+1].x)
                  {
                        temp=pixel_sort[i]; 
                        pixel_sort[i]=pixel_sort[i+1];
                        pixel_sort[i+1]=temp;
                  }
            }
      }
}

/***********************************************************************************************************************************/



