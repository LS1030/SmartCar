#ifndef __INCLUDE_H__
#define __INCLUDE_H__

#include  "common.h"            //�������������ͺ궨�壨�ڲ��Ѷ���MK60_conf.h��PORT_cfg.h��

/*
 * Include �û��Զ����ͷ�ļ�
 */

/***********************************************************************************************************************************/

#include  "MK60_wdog.h"         //���Ź���������
#include  "MK60_gpio.h"         //IO�ڲ���
#include  "MK60_uart.h"         //����
#include  "MK60_SysTick.h"      //�δ�ʱ������
#include  "MK60_lptmr.h"        //�͹��Ķ�ʱ��(��ʱ)
#include  "MK60_i2c.h"          //I2C
#include  "MK60_spi.h"          //SPI
#include  "MK60_ftm.h"          //FTM
#include  "MK60_pit.h"          //PIT
#include  "MK60_rtc.h"          //RTC
#include  "MK60_adc.h"          //ADC
#include  "MK60_dac.h"          //DAC
#include  "MK60_dma.h"          //DMA
#include  "MK60_FLASH.h"        //FLASH
#include  "MK60_can.h"          //CAN
#include  "MK60_sdhc.h"         //SDHC
#include  "MK60_usb.h"          //usb

/***********************************************************************************************************************************/

#include  "VCAN_LED.H"          //LED
#include  "VCAN_KEY.H"          //KEY
#include  "VCAN_MMA7455.h"      //������ٶ�MMA7455
#include  "VCAN_NRF24L0.h"      //����ģ��NRF24L01+
#include  "VCAN_RTC_count.h"    //RTC ʱ��ת��
#include  "VCAN_camera.h"       //����ͷ��ͷ�ļ�
#include  "VCAN_LCD.h"          //Һ����ͷ�ļ�
#include  "ff.h"                //FatFs
#include  "VCAN_TSL1401.h"      //����CCD
#include  "VCAN_key_event.h"    //������Ϣ����
#include  "VCAN_NRF24L0_MSG.h"  //����ģ����Ϣ����
#include  "VCAN_computer.h"     //�๦�ܵ�������
#include  "VCAN_BMP.h"          //BMP
#include  "VCAN_menu.h"         //ɽ��Һ�����˵�

/***********************************************************************************************************************************/

#include  "vcan_img2sd.h"       //�洢ͼ��sd��һ���ļ�
#include  "vcan_sd_app.h"       //SD��Ӧ�ã���ʾsd����ͼƬ�̼���

#include  "Vcan_touch.h"        //��������

/******************************************�û��Զ����ļ�����app�ļ���ʽд�룩******************************************************/

  /***�����㷨����***/
#include  "motor_control.h"             //��������㷨
#include  "servo_control.h"             //��������㷨
#include  "distance_control.h"          //˫���ؾ�

  /***ͼ�������***/
#include  "edge_extract.h"              //������ȡ�㷨
#include  "middle_extract.h"            //������ȡ�㷨
#include  "fit_curves.h"                //��͸��������ߺ�����
#include  "image_binaryzation.h"        //ͼ���ֵ���㷨
#include  "image_rectification.h"       //ͼ������㷨
#include  "podao.h"

  /***�������ܺ�����***/
#include  "font.h"                      //���ֿ�
#include  "car_skill.h"                 //������

  /***��Ļ FLASH***/
#include  "user.h"   
#include  "key.h"     
#include  "user_v_set_filter.h"
#include  "user_flash.h"

  /***ϵͳMK60����***/
#include  "ftm_function.h"              //FTM���ܺ���������  ���PWM�����  ���PWM�����  �����������������룩
#include  "system_set.h"                //MK60�ж����ȼ����ã���С��״̬����
//#include  "MK60_conf.h"     //ɽ��K60ƽ̨������ͷ�ļ�������common.h�ļ������ã�
//#include  "MK60_it.h"       //ɽ��K60 ƽ̨�жϷ�����
//#include  "PORT_cfg.h"      //�ܽŸ������ã�����common.h�ļ������ã�

  /***ϵͳ���躯��***/
#include  "camera.h"                    //����ͷ������
#include  "LCD.h"                       //Һ����������
#include  "LCD_menu.h"                  //Һ�����˵�����
#include  "SEEKFREE_MT9V032.h"          //��������ó���
#include  "SEEKFREE_IIC.h"              //���������ó���
#include  "SEEKFREE_MPU6050.h"          //���������ó���
#include  "ultrasonic.h"                //��������ó���
#include  "correspond.h"

  /***�ⲿӦ�ú���***/
#include  "DLib_Product_string.h"       //���ٿ�������




/***********************************************************************************************************************************/




#endif








