#include "include.h"
#include "common.h"

/***********************************************************************************************************************************/

Site_t site     = {0, 0};                      //��ʾͼ�����Ͻ�λ��
Size_t imgsize  = {COL, ROW};                  //ͼ���С
Size_t imgsize2  = {CAMERA_W,CAMERA_H};        //��ȡ��ͼ���С
Size_t imgsize_erzhi = {CAMERA_W,CAMERA_H};
Size_t size;                                   //��ʾ����ͼ���С

/***********************************************************************************************************************************/

void LCD1_init();                  //Һ������ʼ������

void LCD_CAMERA_show();            //����ͷ�ɼ�ԭͼ����ʾ����
void LCD_CAMERA_erzhiSHOW();       //��ֵ��ͼ����ʾ����
void LCD_CAMERA_BARREL_show();     //ͼ��Ͱ��ʧ�������ʾ����

/***********************************************************************************************************************************/

void LCD1_init()     //Һ������ʼ������
{
      LCD_init();
      //LCD_str            (site,"Cam init ing",FCOLOUR,BCOLOUR);
      size.H = LCD_H;
      size.W = LCD_W;
      //LCD_str            (site,"Cam init OK!",FCOLOUR,BCOLOUR);
}

/***********************************************************************************************************************************/

void LCD_CAMERA_BARREL_show()
{
      barrel_rectification();     //Ͱ��ʧ���������
      site.x=0;
      site.y=0;
      LCD_Img_gray_Z(site, size, (uint8 *) img_barrel,imgsize2);
      site.x=64;
      site.y=64;
      LCD_cross(site,128,RED);
}

/***********************************************************************************************************************************/

void LCD_CAMERA_show()
{
      site.x=0;
      site.y=0;
      LCD_Img_gray_Z(site, size, (uint8 *)img,imgsize);
          site.x=64;
      site.y=64;
      LCD_cross(site,128,RED);
}

/***********************************************************************************************************************************/

void LCD_CAMERA_erzhiSHOW()
{
      edge_add();
      midline_add();
      jizhun_add();
      site.x=0;
      site.y=0;
      LCD_Img_gray_Z(site, size, (uint8 *)img_data,imgsize_erzhi);
}

/***********************************************************************************************************************************/




