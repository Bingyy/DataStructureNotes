#define LIST_INIT_SIZE 100 //线性表存储空间的初始分配量
#define LISTINCREMENT 10 //存储空间的分配增量

typedef struct 
{
	ElemType *elem;//存储空间基址
	int length;//当前长度
	int listSize; //分配的存储容量（以sizeof(ElemType为单位)）
} SqList;
//动态分配型的顺序表的合并
void MergeList_Sq(SqList La, SqList Lb, SqList &Lc){
	//顺序线性表的合并
	//La,Lb的元素按值非递减顺序排列，归并得到的Lc也是按照值的非递减顺序排列
	pa = La.elem;//elem是：存储空间基址
	pb = Lb.elem;
	Lc.listSize = La.length + Lb.length;
	pc = Lc.elem = (ElemType*)malloc(sizeof(ElemType) * Lc.listSize);//为Lc分配一段内存
	if(!Lc.elem) exit(OVERFLOW); //存储分配失败

	//获取两个顺序表的最后一个元素的地址，用于下面的循环判断
	pa_last = pa + La.length - 1;
	pb_last = pb + Lb.length - 1;

	//归并
	while(pa <= pa_last && pb <= pb_last){
		if(*pa <= *pb){
			*pc++ = *pa++;
		}
		else{
			*pc++ = *pb++;
		}
	}

	while(pa <= pa_last) *pc++ = *pa++;//插入La的剩余元素
	while(pb <= pb_last) *pc++ = *pb++;//插入Lb的剩余元素

}//MergeList_Sq