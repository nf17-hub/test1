#include "sys.h"  

/*
1.先初始化延时函数，然后延时一秒后再启动小车（所以将小车放在跑道上开机后不会立马启动，而是一秒后才会动）。
2.IO_Init：sys.h中定义的IO口进行初始化
3.TIM3 PWM初始化
4.小车初始化
5.进入while循环，小车开始工作，根据四路循迹模块传回来的数据，hw_scan()返回不同的flag值给drive()，由drive()执行小车的走向。
*/
int main(void)
{
	delay_init();//延时函数初始化
	delay_ms(1000);//先延时1s
	IO_Init();
	TIM3_PWM_Init(899,0);//设置PWM输出
	carInit();//小车初始化
	while(1) 
	{ 
		hw_scan();//传感器检测 
		drive(flag);//驱动 
	}
}


