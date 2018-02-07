#include "include.h"
#include "common.h"

/***********************************************************************************************************************************/

int8 m_menu,sub_menu;

/***********************************************************************************************************************************/



/***********************************************************************************************************************************/

void HCI_lcd_open()
{
    //��ʼ��flash
    flash_init();
    //��ʼ�����ᰴ��
    key_init(KEY_U);
    key_init(KEY_D);
    key_init(KEY_L);
    key_init(KEY_R);
    key_init(KEY_A);
    //lcd��ʼ��
    LCD_init();
    m_menu=0;
    sub_menu=0;
    //����ͷ��ʼ��
    //��ɾ��
}

/***********************************************************************************************************************************/

void HCI_lcd_close()
{
    
}

/***********************************************************************************************************************************/

void HCI_lcd_work()
{
    //�������˵�ѡ��
  LCD_clear(WHITE);
            
    int8 s_flag=0;
    Site_t site1;

    while(m_menu==0 && sub_menu==0) //���˵����Ӳ˵�
    {
        site1.x=50;
        site1.y=50;
        //�����м��
        if(key_check(KEY_A)==KEY_DOWN)
        {
            s_flag=1;
            while(s_flag)
            {
                //��
                if(key_check(KEY_U)==KEY_DOWN)
                {
                    m_menu++;
                }
                //��
                if(key_check(KEY_D)==KEY_DOWN)
                {
                    m_menu--;
                }
                //����
                if(key_check(KEY_L)==KEY_DOWN)
                {
                    m_menu=0;
                    s_flag=0;
                }
                //ǰ��
                if(key_check(KEY_R)==KEY_DOWN)
                {
                    s_flag=0;
                }
                //����
                if(key_check(KEY_A)==KEY_DOWN)
                {
                    m_menu=0;
                }
                LCD_num_BC(site1, (uint32)m_menu,5, BLUE, WHITE);
            }
            break;
        }
    }
    while(m_menu==1 && sub_menu==0)
    {
        site1.x=10;
        site1.y=10;
        LCD_num_BC(site1, (uint32)m_menu,5, BLUE, WHITE);
        site1.x=50;
        site1.y=50;
        LCD_num_BC(site1, (uint32)sub_menu,5, BLUE, WHITE);
        if(key_check(KEY_U)==KEY_DOWN)
        {
            //����ͼ����ʾ
            m_menu=1;
            sub_menu=1;
            break;
        }
        if(key_check(KEY_D)==KEY_DOWN)
        {
            //����ͼ����ʾ
            m_menu=1;
            sub_menu=2;
            break;
        }
        if(key_check(KEY_L)==KEY_DOWN)
        {
            //����ͼ����ʾ
            m_menu=1;
            sub_menu=3;
            break;
        }
        if(key_check(KEY_R)==KEY_DOWN)
        {
            //����ͼ����ʾ
            m_menu=1;
            sub_menu=4;
            break;
        }
    }
    while(m_menu==2 && sub_menu==0)
    {
        site1.x=10;
        site1.y=10;
        LCD_num_BC(site1, (uint32)m_menu,5, BLUE, WHITE);
        if(key_check(KEY_U)==KEY_DOWN)
        {
            //����PID��������
            m_menu=2;
            sub_menu=1;
            break;
        }
        if(key_check(KEY_D)==KEY_DOWN)
        {
            //����PID��������
            m_menu=2;
            sub_menu=2;
            break;
        }
        if(key_check(KEY_L)==KEY_DOWN)
        {
            //����PID��������
            m_menu=2;
            sub_menu=3;
            break;
        }
        if(key_check(KEY_R)==KEY_DOWN)
        {
           //����PID��������
            m_menu=2;
            sub_menu=4;
            break;
        }
    }
    while(m_menu==3 && sub_menu==0)
    {
        site1.x=10;
        site1.y=10;
        LCD_num_BC(site1, (uint32)m_menu,5, BLUE, WHITE);
        if(key_check(KEY_U)==KEY_DOWN)
        {
            //����flash��д
            m_menu=3;
            sub_menu=1;
            break;
        }
        if(key_check(KEY_D)==KEY_DOWN)
        {
            //����flash��д
            m_menu=3;
            sub_menu=2;
            break;
        }
        if(key_check(KEY_L)==KEY_DOWN)
        {
            //����flash��д
            m_menu=3;
            sub_menu=3;
            break;
        }
        if(key_check(KEY_R)==KEY_DOWN)
        {
           //����flash��д
            m_menu=3;
            sub_menu=4;
            break;
        }
    }
    
    //ͼ����ʾ 
    if(m_menu==1 && sub_menu!=0)
    {
        switch(sub_menu)
        {
            case 1:
                HCI_lcd_11();
                m_menu=0;
                sub_menu=0;
                break;
            case 2:
                HCI_lcd_12();
                m_menu=0;
                sub_menu=0;
                break;
            case 3:
                HCI_lcd_13();
                 m_menu=0;
                sub_menu=0;
                break;
            case 4:
                HCI_lcd_14();
                m_menu=0;
                sub_menu=0;
                break;
            default:
                break;

        }
    }
    //PID����
    if(m_menu==2 && sub_menu!=0)
    {
        switch(sub_menu)
        {
            case 1:
                HCI_lcd_21();
                m_menu=0;
                sub_menu=0;
                break;
            case 2:
                HCI_lcd_22();
                m_menu=0;
                sub_menu=0;
                break;
            case 3:
                HCI_lcd_23();
                 m_menu=0;
                sub_menu=0;
                break;
            case 4:
                HCI_lcd_24();
                m_menu=0;
                sub_menu=0;
                break;
            default:
                break;

        }
    }
    //дflash
    if(m_menu==3 && sub_menu!=0)
    {
        switch(sub_menu)
        {
            case 1:
                HCI_lcd_31();
                m_menu=0;
                sub_menu=0;
                break;
            case 2:
                HCI_lcd_32();
                m_menu=0;
                sub_menu=0;
                break;
            case 3:
                HCI_lcd_33();
                 m_menu=0;
                sub_menu=0;
                break;
            case 4:
                HCI_lcd_34();
                m_menu=0;
                sub_menu=0;
                break;
            default:
                break;

        }
    }
      
}

/***********************************************************************************************************************************/

//��ʾͼ��
void HCI_lcd_11()
{
    LCD_clear(WHITE);
    Site_t site     = {0, 0};                             //��ʾͼ�����Ͻ�λ��
    Size_t imgsize  = {CAMERA_W, CAMERA_H};               //ͼ���С
    Size_t size;    
    while(1)
    {
         LCD_CAMERA_erzhiSHOW();
    }
}

/***********************************************************************************************************************************/

//��ʾ��������С�棩
void HCI_lcd_12()
{
    LCD_clear(WHITE);
    uint32 a;
    Site_t site     = {0, 0};                             //��ʾͼ�����Ͻ�λ��
    Size_t imgsize  = {CAMERA_W, CAMERA_H};               //ͼ���С
    Size_t size;                                          //��ʾ����ͼ���С
    size.H = LCD_H/2; //50
    size.W = LCD_W/2;  //50
    while(1)//�˴�1���Ըĳ�ĳ������
    {
        LCD_CAMERA_erzhiSHOW();
        site.x=70;
        site.y=10;
        LCD_str(site, "m", BLUE, WHITE);
        site.y=25;
        LCD_str(site, "s", BLUE, WHITE);
        site.y=40;
        LCD_str(site, "t", BLUE, WHITE);
        site.x=90;
        site.y=10;
//        LCD_num_BC(site, (uint32)ekm,5, BLUE, WHITE);
        site.y=25;
//        LCD_num_BC(site, (uint32)eks,5, BLUE, WHITE);
        if(key_get(KEY_U)==KEY_DOWN)
        {
            site.y=40;
            LCD_num_BC(site,(uint32)a,5, BLUE, WHITE);
            a++;
        }
        else if(key_get(KEY_D)==KEY_DOWN)
        {
            site.y=40;
            LCD_num_BC(site,(uint32)a,5, BLUE, WHITE);
            a--;
        }
        else
        {
            site.y=40;
            LCD_num_BC(site,a,5, BLUE, WHITE);
        }
    }
}

/***********************************************************************************************************************************/

//������
void HCI_lcd_13()
{
    LCD_clear(WHITE);  
    uint32 a;
    Site_t site     = {0, 0};                             //��ʾͼ�����Ͻ�λ��
    Size_t imgsize  = {CAMERA_W, CAMERA_H};               //ͼ���С
    Size_t size;                                          //��ʾ����ͼ���С
    while(1)
    {
        LCD_CAMERA_erzhiSHOW();
        site.x=70;
        site.y=10;
        LCD_str(site, "m", BLUE, RED);
        site.y=25;
        LCD_str(site, "s", BLUE, RED);
        site.y=40;
        LCD_str(site, "t", BLUE, RED);
        site.x=90;
        site.y=10;
        LCD_num_BC(site, (uint32)middle_Error[1],5, BLUE, RED);
        site.y=25;
        LCD_num_BC(site, (uint32)middle_Error,5, BLUE, RED);
        //key_get(KEY_U);
        if(key_get(KEY_U)==KEY_DOWN)
        {
            site.y=40;
            LCD_num_BC(site,(uint32)a,5, BLUE, RED);
            a++;
        }
        else if(key_get(KEY_D)==KEY_DOWN)
        {
            site.y=40;
            LCD_num_BC(site,(uint32)a,5, BLUE, RED);
            a--;
        }
        else
        {
            site.y=40;
            LCD_num_BC(site,a,5, BLUE, RED);
        }
    }
}

/***********************************************************************************************************************************/

void HCI_lcd_14()
{

}

/***********************************************************************************************************************************/

//PIDֵ����(������)
void HCI_lcd_21()
{
    LCD_clear(WHITE);
    int32 P,I,D;
    int8 c_flag=0;                                          //�м����־λ
    int8 x_zhou=0,y_zhou=0;
    uint32 temp;
    Site_t site     = {0, 0};                             //��ʾͼ�����Ͻ�λ��
    //Size_t imgsize  = {CAMERA_W, CAMERA_H};               //ͼ���С
    //Size_t size;                                          //��ʾ����ͼ���С
    //size.H = LCD_H/2;
    //size.W = LCD_W/2;
    while(1)//�˴�1���Ըĳ�ĳ������
    {
        site.x=0;
        site.y=0;
        
        site.x=70;
        site.y=10;
        LCD_str(site, "P", BLUE, WHITE);//���԰�m,s,t�ĳ�Ҫ��ʾ����ֵ
        site.y=25;
        LCD_str(site, "I", BLUE, WHITE);
        site.y=40;
        LCD_str(site, "D", BLUE, WHITE);
        site.x=90;
        site.y=10;
        if(P>=0&&P<2147483648)
        {
            LCD_num_BC(site, (uint32)P,5, BLUE, WHITE);
        }
        else 
        {
            LCD_str(site, "-", BLUE, WHITE);
            site.x=site.x+2;
            LCD_num_BC(site, (uint32)ABS(P),5, BLUE, WHITE);
            site.x=site.x-2;
        }
        site.y=25;
        if(I>=0&&P<2147483648)
        {
            LCD_num_BC(site, (uint32)I,5, BLUE, WHITE);
        }
        else 
        {
            LCD_str(site, "-", BLUE, WHITE);
            site.x=site.x+2;
            LCD_num_BC(site, (uint32)ABS(I),5, BLUE, WHITE);
            site.x=site.x-2;
        }
        site.y=40;
        if(I>=0&&P<2147483648)
        {
            LCD_num_BC(site, (uint32)D,5, BLUE, WHITE);
        }
        else 
        {
            LCD_str(site, "-", BLUE, WHITE);
            site.x=site.x+2;
            LCD_num_BC(site, (uint32)ABS(D),5, BLUE, WHITE);
            site.x=site.x-2;
        }
        if(key_get(KEY_A)==KEY_DOWN&&c_flag==0)
        {
            c_flag=1;
            x_zhou=1;
            y_zhou=1;
        }
        if(key_get(KEY_U)==KEY_DOWN&&c_flag==1)
        {
            if(y_zhou==1)
            {
                P++;
            }
            if(y_zhou==2)
            {
                I++;
            }
            if(y_zhou==3)
            {
                D++;
            }
        }
        else if(key_get(KEY_D)==KEY_DOWN&&c_flag==1)
        {
            if(y_zhou==1)
            {
                P--;
            }
            if(y_zhou==2)
            {
                I--;
            }
            if(y_zhou==3)
            {
                D--;
            }
        }
        if(key_get(KEY_L)==KEY_DOWN&&c_flag==1)
        {
            y_zhou--;
            if(y_zhou<=0)
            {
                y_zhou=3;
            }
        }
        if(key_get(KEY_R)==KEY_DOWN&&c_flag==1)
        {
            y_zhou++;
            if(y_zhou>=4)
            {
                y_zhou=1;
            }
        }
    }
}

/***********************************************************************************************************************************/

void HCI_lcd_22()
{
    
}

/***********************************************************************************************************************************/

void HCI_lcd_23()
{
    
}

/***********************************************************************************************************************************/

void HCI_lcd_24()
{
    
}

/***********************************************************************************************************************************/

void HCI_lcd_31()
{
    parameter_init();
}

/***********************************************************************************************************************************/

void HCI_lcd_32()
{
    parameter_release();
}

/***********************************************************************************************************************************/

void HCI_lcd_33()
{
    parameter_solidify();
}

/***********************************************************************************************************************************/

void HCI_lcd_34()
{
    
}

/***********************************************************************************************************************************/




