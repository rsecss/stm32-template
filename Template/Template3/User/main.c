#include "stm32f10x.h"                  // Device header
#include "delay.h"
#include "oled.h"

int main()
{
	/* 模块初始化 */
	OLED_Init();		// OLED初始化
	
	/*OLED显示*/
	OLED_ShowChar(1, 1, 'A');				// 1 行 1 列显示字符 A
	
	OLED_ShowString(1, 3, "HelloWorld!");	// 1 行 3 列显示字符串 HelloWorld!
	
	OLED_ShowNum(2, 1, 12345, 5);			// 2 行 1 列显示十进制数字 12345，长度为 5
	
	OLED_ShowSignedNum(2, 7, -66, 2);		// 2 行 7 列显示有符号十进制数字 -66，长度为 2
	
	OLED_ShowHexNum(3, 1, 0xAA55, 4);		// 3 行 1 列显示十六进制数字 0xA5A5，长度为 4
	
	OLED_ShowBinNum(4, 1, 0xAA55, 16);		// 4 行 1 列显示二进制数字 0xA5A5，长度为 16
											// C语言无法直接写出二进制数字，故需要用十六进制表示
	
	while (1)
	{
		
	}
}
