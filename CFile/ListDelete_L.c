Status ListDelete_L(LinkList &L, int i, ElemType &e){
	//在带头结点的单链表L中，删除第i个元素，并由e返回其值
	p = L;
	j = 0;
	//指向i的前驱
	while(p->next && j < i - 1){
		p = p->next;
		++j;
	}
	if(!(p->next) || j > i - 1)return ERROR;
	q = p->next;//hold the one which will be deleted
	p = p->next->next;
	e = q->data;
	free(q);
	return OK;
} //ListDelete_L