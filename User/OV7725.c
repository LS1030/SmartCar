#include "OV7725.h"

uint8 imgbuff[CAMERA_SIZE];                         //����洢����ԭʼͼ���һά����
uint8 img[CAMERA_H][CAMERA_W];                      //����洢ת�����ͼ��Ķ�ά����


//�жϺ�������
void PORTA_IRQHandler();          //PA29�ж�
void DMA0_IRQHandler();           //PA27����DMA�ж�

/*
*  @brief      OV7725��ʼ����ͼ��洢��һά����imgbuff��
*  @param      image             ͼ���ַ
*/
void OV7725_Init()
{
	camera_init(imgbuff);

	//�����жϸ�λ����
	set_vector_handler(PORTA_VECTORn, PORTA_IRQHandler);    //����LPTMR���жϸ�λ����Ϊ PORTA_IRQHandler
	set_vector_handler(DMA0_VECTORn, DMA0_IRQHandler);      //����LPTMR���жϸ�λ����Ϊ PORTA_IRQHandler
}


/*
*  @brief      ��ȡͼ�񣬲���ͼ����н�ѹ�����洢����ά����img��
*  @param      image             ͼ���ַ
*/
void Get_img()
{

	camera_get_img();                                       //����ͷ��ȡͼ��

	img_extract(img, imgbuff, OV7725_ImgSize);              //ͼ���ѹ
}

///*
//*  @brief      ���Ž�ѹͼ����ʾ��Һ����Ĭ����ʾ��άͼ��
//*  @param      image             ͼ���ַ
//*/
//void Img_Show_LCD(uint8 *image)
//{
//	Site_t site = { 0, 0 };                              //��ʾͼ�����Ͻ�λ��
//	Size_t imgsize = { 160, 60 };                       //ͼ���С
//	Size_t size = { 128, 128 };                      //��ʾ����ͼ���С
//
//	LCD_Img_gray_Z(site, size, (uint8*)image, imgsize);
//}

///*
//*  @brief      ���Ž�ѹͼ����ʾ����λ����Ĭ����ʾ��άͼ��
//*  @param      image             ͼ���ַ
//*/
//void Img_Show_UART(uint8 *image)
//{
//	vcan_sendimg(image, OV7725_ImgSize);
//}

/*!
*  @brief      PORTA�жϷ�����
*  @since      v5.0
*/
void PORTA_IRQHandler()
{
	uint8  n;    //���ź�
	uint32 flag;

	while (!PORTA_ISFR);
	flag = PORTA_ISFR;
	PORTA_ISFR = ~0;                                   //���жϱ�־λ

	n = 29;                                             //���ж�
	if (flag & (1 << n))                                 //PTA29�����ж�
	{
		camera_vsync();
	}
#if ( CAMERA_USE_HREF == 1 )                            //ʹ�����ж�
	n = 28;
	if (flag & (1 << n))                                 //PTA28�����ж�
	{
		camera_href();
	}
#endif

}

/*!
*  @brief      DMA0�жϷ�����
*  @since      v5.0
*/
void DMA0_IRQHandler()
{
	camera_dma();
}
