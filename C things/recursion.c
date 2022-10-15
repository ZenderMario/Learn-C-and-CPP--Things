#include <stdio.h>

void to_binary(int a)
{
	if( a >= 2)
		to_binary(a / 2);
	printf("%d", a % 2);
}

void print_strnum(int a)
{


	if (a >= 10)
		print_strnum(a / 10);
	printf("%d", a % 10);
}

int main()
{

	//以上两例发现递归易于处理倒叙问题
	//
	//看二进制位用除二余法,从最后面余数(即最高位)开始打印
	//打印整数从最高位依次除余

	//递归也可分为首递归和尾递归
	// 尾递归可用循环实现(先执行代码后检查条件)
	//区分使用


	return 0;
}
