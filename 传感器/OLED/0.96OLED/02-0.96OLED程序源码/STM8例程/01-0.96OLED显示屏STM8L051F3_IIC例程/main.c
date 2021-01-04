//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//�о�԰����
//���̵�ַ��http://shop73023976.taobao.com/?spm=2013.1.0.0.M4PqC2
//
//  �� �� ��   : main.c
//  �� �� ��   : v2.0
//  ��    ��   : HuangKai
//  ��������   : 2019-11-07
//  ����޸�   : 
//  ��������   : OLED 4�ӿ���ʾ����(STM8L051F3)
//              ˵��: 
//              ----------------------------------------------------------------
//              GND    ��Դ��
//              VCC  ��3.3v��Դ
//              D0   PC1
//              D1   PC0
//              RES  PB7 ע��SPI�ӿ���ʾ���ĳ�IIC�ӿ�ʱ��Ҫ��RES����
//                           IIC�ӿ���ʾ���û������         
//              ----------------------------------------------------------------
// �޸���ʷ   :
// ��    ��   : 
// ��    ��   : HuangKai
// �޸�����   : �����ļ�
//��Ȩ���У�����ؾ���
//Copyright(C) �о�԰����2014/3/16
//All rights reserved
//******************************************************************************/
#include "stm8l15x.h"//STM8L051/151��ϵ�й��ÿ⺯��
#include "oled.h"
#include "bmp.h"

void init_sys_clock(void);

void main(void)
{
  u8 t=' ';
  init_sys_clock();
  OLED_Init();//��ʼ��OLED
  LED_Clr();
  OLED_ColorTurn(0);//0������ʾ��1 ��ɫ��ʾ
  OLED_DisplayTurn(0);//0������ʾ 1 ��Ļ��ת��ʾ
  while(1) 
  {		
    OLED_DrawBMP(0,0,128,64,BMP1);
    delay_ms(500);
    OLED_Clear();
    OLED_ShowChinese(0,0,0,16);//��
    OLED_ShowChinese(18,0,1,16);//��
    OLED_ShowChinese(36,0,2,16);//԰
    OLED_ShowChinese(54,0,3,16);//��
    OLED_ShowChinese(72,0,4,16);//��
    OLED_ShowChinese(90,0,5,16);//��
    OLED_ShowChinese(108,0,6,16);//��
    OLED_ShowString(8,2,"ZHONGJINGYUAN",16);
    OLED_ShowString(20,4,"2014/05/01",16);
    OLED_ShowString(0,6,"ASCII:",16);  
    OLED_ShowString(63,6,"CODE:",16);
    OLED_ShowChar(48,6,t,16);
    t++;
    if(t>'~')t=' ';
    OLED_ShowNum(103,6,t,3,16);
    delay_ms(500);
    OLED_Clear();
  }
}

void init_sys_clock(void)
{
  //ʹ���ڲ�HSI 16M ����Ƶ
  CLK_HSICmd(ENABLE);//��ʼ�ڲ���ƵRC
  CLK_SYSCLKSourceConfig(CLK_SYSCLKSource_HSI);//HSIΪϵͳʱ��
  CLK_SYSCLKDivConfig(CLK_SYSCLKDiv_1);//����Ƶ,16M
}


#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
