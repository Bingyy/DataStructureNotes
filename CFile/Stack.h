#define STACK_INIT_SIZE 100
#define STACKINCREMENT 50
#define Status int 
#define OK 1
#define ERROR -1
typedef struct 
{
	SElemType *base; //栈底
	SElemType *top; //栈顶
	int stacksize;
}SqStack;

//栈的算法描述
Status InitStack(SqStack &S)
{
	S.base = (SElemType*) malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(!S.base) exit(ERROR); // 存储分配失败
	S.top = base; //初始时top和base都指向同一个位置
	S.stacksize = STACK_INIT_SIZE; 
	return OK;
} 

Status GetTop(SqStack &S, SElemType &e)
{
	if(S.top == S.base) return ERROR; //栈空
	e = *(S.top - 1);
	return OK;
}

Status Push(SqStack &S,SElemType e)
{
	//如果栈满，追加存储空间
	if(S.top - S.base >= S.stacksize){
		S.base = (SElemType*)remalloc(S.base,(S.stacksize + STACKINCREMENT)*sizeof(SElemType));
		if(!S.base) return ERROR; //存储分配失败
		S.top = S.base + S.stacksize; //调整top的位置
	}
	*S.top = e;
	S.top++;
	return OK;
}

Status Pop(SqStack &S, SElemType &e)
{
	if(S.base == S.top) return ERROR;
	S.top--;
	e = *(S.top);//此时的top指向的当前栈顶的上一个位置，是上一个状态的栈顶
	return OK;
}
