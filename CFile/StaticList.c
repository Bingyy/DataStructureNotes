//借助一维数组来描述线性链表--静态链表
#define MAXSIZE 1000
typedef struct{
	ElemType data;
	int cur;//游标,指示下一个结点的下标
} component, SLinkList[MAXSIZE];

//数组的第0分量作为头结点
//S[0].cur指示第一个结点在数组中的位置
//i = S[i].cur; 等价于指针后移 p = p->next

//定位函数
int LocateElem_SL(SLinkList S, ElemType e){
	//在静态单链表L中查找第1个值为e的元素
	//若找到，返回它在L中的位序，否则返回0
	i = S[0].cur;//指示第一个结点在数组中的位置
	while(i && S[i].data != e){
		i = S[i].cur;//顺链查找
	}
}//LocateElem_SL


void InitSpace_SL(SLinkList &space){
	//将一维数组space中的各分量链成一个备用链表，space[0].cur是头指针
	//"0"表示空指针
	for(int i = 0; i < MAXSIZE - 1; ++i){
		space[i].cur = i + 1;
		space[MAXSIZE - 1] = "0";
	}
}

//需要手动实现malloc
int Malloc_SL(SLinkList &space){
	//若备用链表非空，返回分配的结点下标，否则返回0
	i = space[0].cur;
	if(space[0].cur){
		space[0].cur = space[i].cur;
	}
	return i;
}

//手动实现free
void Free_SL(SLinkList &space, int k){
	//将下标为k的的空闲结点回收到备用链表
	space[k].cur = space[0].cur;
	space[0].cur = k;
}