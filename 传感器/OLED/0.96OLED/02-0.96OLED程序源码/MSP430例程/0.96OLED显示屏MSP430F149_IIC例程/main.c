//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//�о�԰����
//���̵�ַ��http://shop73023976.taobao.com/?spm=2013.1.0.0.M4PqC2
//
//  �� �� ��   : oled.c
//  �� �� ��   : v2.0
//  ��    ��   : HuangKai
//  ��������   : 2014-0101
//  ����޸�   : 
//  ��������   : 0.96��OLED �ӿ���ʾ����(MSP430F149ϵ��)
//  ����IC     :SSD1309
//              ˵��: 
//              ----------------------------------------------------------------
//              GND    ��Դ��
//              VCC  ��3.3v��Դ
//              D0   P54��ʱ�ӣ�
//              D1   P53�����ݣ�
//              RES  P52 ע��SPI�ӿ���ʾ���ĳ�IIC�ӿ�ʱ��Ҫ��RES����
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
#include <io430.h>
#include "oled.h"
#include "bmp.h"
void init_sysclock(void);
int main( void )
{
  WDTCTL = WDTPW + WDTHOLD;
  init_sysclock();
  u8 t=' ';
  OLED_Init();		//��ʼ��OLED  
  LED_Clr();
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

/*******************************************
�������ƣ�init_sysclock
��    �ܣ�ʹ���ⲿ8M����
��    ������
����ֵ  ����
********************************************/
void init_sysclock(void)
{
  unsigned char i;
  BCSCTL1&=~XT2OFF;     //����XT2����
  BCSCTL2|=SELM_2+SELS;    //ѡ��MCLKʱ��ԴΪXT2CLK��ѡ��SMCLKʱ��ԴΪXT2CLK
  
  do
  {
    IFG1&=~OFIFG;
    for(i=0;i<100;i++)
      _NOP();
  } 
  while((IFG1&OFIFG)!=0);
  IFG1&=~OFIFG;  
}