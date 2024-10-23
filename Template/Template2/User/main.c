#include "stm32f10x.h"                  // Device header

int main()
{
	/* 开启时钟 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	// 开启 GPIOC 的时钟
															// 使用各个外设前必须开启时钟，否则对外设的操作无效
	
	/* GPIO 初始化 */
	GPIO_InitTypeDef GPIO_InitStructure;					// 定义结构体变量
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		// GPIO 模式，赋值为推挽输出模式
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;				// GPIO 引脚，赋值为第 13 号引脚
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		// GPIO 速度，赋值为 50MHz
	
	GPIO_Init(GPIOC, &GPIO_InitStructure);					// 将赋值后的构体变量传递给 GPIO_Init 函数
															// 函数内部会自动根据结构体的参数配置相应寄存器
															// 实现 GPIOC的初始化
	
	/* 设置 GPIO 引脚的高低电平 */
	/* 若不设置 GPIO 引脚的电平，则在 GPIO 初始化为推挽输出后，指定引脚默认输出低电平 */
//	GPIO_SetBits(GPIOC, GPIO_Pin_13);						// 将 PC13 引脚设置为高电平
	GPIO_ResetBits(GPIOC, GPIO_Pin_13);						// 将 PC13 引脚设置为低电平
	
	while (1)
	{
		
	}
}
