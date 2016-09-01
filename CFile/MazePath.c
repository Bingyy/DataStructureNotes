#include<"Stack.h">
#include<stdio.h>

typedef struct 
{
	int ord; //通道块咋路径上的序号
	Point seat; //通道块在迷宫中的位置
	int di; //此通道块到下一个通道块的方向
};

Status MazePath(MazeType maze, Point start, Point end)
{
	//若迷宫中存在从入口start到出口end的通道，则求得一条存放在栈中（从栈底到栈顶），并返回true,否则返回false
	InitStack(S);
	curPos = start;//当前位置为入口位置
	curStep = 1; //搜索第一步

	do{
		if(Pass(curPos)){//当前位置可以通过
			FootPrint(curPos); //留下足迹
			e = (curPos,curStep,1); 
			Push(S,e); //加入路径
			if(curPos == end){
				return TRUE;
			}
			curPos = NextPos(curPos,1); //下一位置是东边的邻居
			curStep++; //探索下一步
		}
		else //当前位置不能通过
		{
			if(!StackEmpty(S))
			{
				Pop(S,e);
				while(e.di == 4 && !StackEmpty(S))
				{
					MarkPrint(e.seat);
					Pop(S,e);//标记为不能通过，并退回到下一步
				}
				if(e.di < 4)//如果方向没有走完，再换个方向试试
				{
					e.di++;
					Push(S,e);
					curPos = NextPos(e.seat,e.di);
				}
			}
		}
	} while(!StackEmpty(S));
	return FALSE；
}