#include "include.h"


int16 mpu_gyro_x,mpu_gyro_y,mpu_gyro_z;
int16 mpu_acc_x,mpu_acc_y,mpu_acc_z;


//��I2C�豸д��һ���ֽ�����
void Single_WriteI2C_MPU6050(uint8 REG_Address,uint8 REG_data)
{
    IIC_start();                //��ʼ�ź�
    send_ch(MPU6050_ADDR);      //�����豸��ַ+д�ź�
    send_ch(REG_Address);       //�ڲ��Ĵ�����ַ��
    send_ch(REG_data);          //�ڲ��Ĵ������ݣ�
    IIC_stop();                 //����ֹͣ�ź�
}
//��I2C�豸��ȡһ���ֽ�����
uint8 Single_ReadI2C_MPU6050(uint8 REG_Address)
{
    uint8 REG_data;
    IIC_start();                //��ʼ�ź�
    send_ch(MPU6050_ADDR);      //�����豸��ַ+д�ź�
    send_ch(REG_Address);       //���ʹ洢��Ԫ��ַ����0��ʼ	
    IIC_start();                //��ʼ�ź�
    send_ch(MPU6050_ADDR+1);    //�����豸��ַ+���ź�
    REG_data=read_ch();         //�����Ĵ�������
    //I2C_SendACK();            //����Ӧ���ź�
    IIC_stop();                 //ֹͣ�ź�
    return REG_data;
}
//��ʼ��MPU6050
void InitMPU6050(void)
{
    Single_WriteI2C_MPU6050(PWR_MGMT_1, 0x00);	    //�������״̬
    Single_WriteI2C_MPU6050(SMPLRT_DIV, 0x04);      //200HZ������
    Single_WriteI2C_MPU6050(CONFIG, 0x01);          //
    Single_WriteI2C_MPU6050(GYRO_CONFIG, 0x18);     //2000
    Single_WriteI2C_MPU6050(ACCEL_CONFIG, 0x10);    //8g
}
//��ȡ����
int16 GetData(uint8 REG_Address)
{
    uint8 L;   uint16 H ;
    H=Single_ReadI2C_MPU6050(REG_Address);
    L=Single_ReadI2C_MPU6050(REG_Address+1);
    return (H<<8)+L;   //�ϳ�����
}

void Get_AccData(void)
{
    mpu_acc_x = GetData(ACCEL_XOUT_H)>>2;
    mpu_acc_y = GetData(ACCEL_YOUT_H)>>2;
    mpu_acc_z = GetData(ACCEL_ZOUT_H)>>2;
}

uint8 Gyro_y_bijiao(int16 base_zhi)
{
  
     mpu_gyro_y = GetData(GYRO_YOUT_H)>>3;

    //���� һ��
    
    if((base_zhi>0&&mpu_gyro_y>base_zhi)
       ||(base_zhi<0&&mpu_gyro_y<base_zhi))
    {
        mpu_gyro_z = GetData(GYRO_ZOUT_H)>>3;
        if(ABS(mpu_gyro_y)>ABS(mpu_gyro_z))
        {
           mpu_gyro_x = GetData(GYRO_XOUT_H)>>3;
           if(ABS(mpu_gyro_y)>ABS(mpu_gyro_x))
           {
              return 1;
           }
        }
    }
    return 0;
}

int16 Get_Gyro_y()
{
    mpu_gyro_y = GetData(GYRO_YOUT_H)>>3;
    return mpu_gyro_y;
}
int16 Get_Gyro_z()
{
    mpu_gyro_z = GetData(GYRO_ZOUT_H)>>3;
    return mpu_gyro_z;
}
int16 Get_Gyro_x()
{
   mpu_gyro_x = GetData(GYRO_XOUT_H)>>3;
    return mpu_gyro_x;
}