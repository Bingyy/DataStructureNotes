//数制转换:十进制转为8进制
#include<"Stack.h">
#include<stdio.h>


void conversion()
{
	InitStack(S);//构造空栈
	scanf("%d",&N);
	while(N)
	{
		Push(S,N % 8)；
		N = N / 8;
	}
	while(!StackEmpty)
	{
		Pop(S,e);
		printf("%d",e);
	}
}