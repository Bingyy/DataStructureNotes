//介于C与伪码之间
Status ListInsert_L(LinkList &L, int i, ElemType e){
	//在带头结点的单线性链表L中第i个位置之前插入元素e
	p = L;//不用L->next是因为更好看些，用的话就少一次循环，没什么不同
	j = 0；
	//指针流到第i-1个结点
	while(p && j < i - 1){
		p = p->next;
		++j;
	}
	if(!p || j > i - 1) return ERROR;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;

	return OK;
}//ListInsert_L