#include "include.h"



#define SCL_INIT        gpio_init (SEEKFREE_SCL, GPO,0)
#define SDA_INIT        gpio_init (SEEKFREE_SDA, GPO,0)

#define SCL_PULL_INIT   port_init_NoALT (SEEKFREE_SCL, PULLUP)//ODO
#define SDA_PULL_INIT   port_init_NoALT (SEEKFREE_SDA, PULLUP)

#define SDA             gpio_get (SEEKFREE_SDA)
#define SDA0()          gpio_set (SEEKFREE_SDA, 0)	//IO������͵�ƽ
#define SDA1()          gpio_set (SEEKFREE_SDA, 1)	//IO������ߵ�ƽ  
#define SCL0()          gpio_set (SEEKFREE_SCL, 0)	//IO������͵�ƽ
#define SCL1()          gpio_set (SEEKFREE_SCL, 1)	//IO������ߵ�ƽ
#define DIR_OUT()       gpio_ddr (SEEKFREE_SDA, GPO);   //�������
#define DIR_IN()        gpio_ddr (SEEKFREE_SDA, GPI);   //���뷽��



void mma8451_delay()
{
  uint8 i;   
  for(i=0;i<10;i++) 	   
    asm("nop");
}

//�ڲ����ݶ���
unsigned char IIC_ad_main; //�����ӵ�ַ	    
unsigned char IIC_ad_sub;  //�����ӵ�ַ	   
unsigned char *IIC_buf;    //����|�������ݻ�����	    
unsigned char IIC_num;     //����|�������ݸ���	     

#define ack 1      //��Ӧ��
#define no_ack 0   //��Ӧ��	 

void IIC_start(void)
{
  SCL0();
  SDA1();
  mma8451_delay();
  SCL1();
  mma8451_delay();
  SDA0();
  mma8451_delay();
  SCL0();
}
//************************************************
//��ֹͣλ SDA=0->1
void IIC_stop(void)
{
  SCL0();
  mma8451_delay();
  SDA0();
  mma8451_delay();
  SCL1();
  mma8451_delay();
  SDA1();
  mma8451_delay();
  SCL0();
}
//************************************************
//��Ӧ��(����ack:SDA=0��no_ack:SDA=0)
void IIC_ack_main(unsigned char ack_main)
{
  SCL0();
  if(ack_main) SDA0(); //ack��Ӧ��
  else SDA1();         //no_ack����Ӧ��
  mma8451_delay();
  SCL1();
  mma8451_delay();
  SCL0();
}
//*************************************************
//�ֽڷ��ͳ���
//����c(����������Ҳ���ǵ�ַ)���������մ�Ӧ��
//�����Ǵ�Ӧ��λ
void send_ch(unsigned char c)
{
  unsigned char i;
  for(i=0;i<8;i++)
  {
    SCL0();
    if((c<<i) & 0x80)SDA1(); //�жϷ���λ
    else SDA0();
    mma8451_delay();
    SCL1();
    mma8451_delay();
    SCL0();
  }
  mma8451_delay();
  SDA1();             //������8bit���ͷ�����׼������Ӧ��λ
  mma8451_delay();
  SCL1();
  mma8451_delay();    //sda�����ݼ��Ǵ�Ӧ��λ              
  SCL0();             //�����Ǵ�Ӧ��λ|��Ҫ���ƺ�ʱ��
}
//**************************************************
//�ֽڽ��ճ���
//�����������������ݣ��˳���Ӧ���|��Ӧ����|IIC_ack_main()ʹ��
//return: uint8��1�ֽ�
unsigned char read_ch(void)
{
  unsigned char i;
  unsigned char c;
  c=0;
  SCL0();
  mma8451_delay();
  SDA1();             //��������Ϊ���뷽ʽ
  DIR_IN();
  for(i=0;i<8;i++)
  {
    mma8451_delay();
    SCL0();         //��ʱ����Ϊ�ͣ�׼����������λ
    mma8451_delay();
    SCL1();         //��ʱ����Ϊ�ߣ�ʹ��������������Ч
    mma8451_delay();
    c<<=1;
    if(SDA) c+=1;   //������λ�������յ����ݴ�c
  }
  SCL0();
  DIR_OUT();
  return c;
}
//***************************************************
//�����ӵ�ַ�������͵��ֽ�����
void send_to_ch(unsigned char ad_main,unsigned char c)
{
  IIC_start();
  send_ch(ad_main);   //����������ַ
  send_ch(c);         //��������c
  IIC_stop();
}
//***************************************************
//�����ӵ�ַ�������Ͷ��ֽ�����
void send_to_nch(unsigned char ad_main,unsigned char ad_sub,unsigned char *buf,unsigned char num)
{
  unsigned char i;
  IIC_start();
  send_ch(ad_main);   //����������ַ
  send_ch(ad_sub);    //���������ӵ�ַ
  for(i=0;i<num;i++)
  {
    send_ch(*buf);  //��������*buf
    buf++;
  }
  IIC_stop();
}
//***************************************************
//�����ӵ�ַ���������ֽ�����
//function:������ַ���������ݴ��ڽ��ջ�������ǰ�ֽ�
void read_from_ch(unsigned char ad_main,unsigned char *buf)
{
  IIC_start();
  send_ch(ad_main);           //����������ַ
  *buf=read_ch();
  IIC_ack_main(no_ack);       //����Ӧ��<no_ack=0>
  IIC_stop();
}
//***************************************************
//�����ӵ�ַ����������ֽ�����
//function:
void read_from_nch(unsigned char ad_main,unsigned char ad_sub,unsigned char *buf,unsigned char num)
{
  unsigned char i;
  IIC_start();
  send_ch(ad_main);
  send_ch(ad_sub);
  for(i=0;i<num-1;i++)
  {
    *buf=read_ch();
    IIC_ack_main(ack);      //��Ӧ��<ack=1>
    buf++;
  }
  *buf=read_ch();
  buf++;                      //����ָ����������壬Ŀ���ǲ�����bufָ����һ��ַ
  IIC_ack_main(no_ack);       //����Ӧ��<no_ack=0>
  IIC_stop();
}

void IIC_init(void)
{
  
  SCL_INIT;     
  SDA_INIT;
  SCL_PULL_INIT;
  SDA_PULL_INIT;
  
}