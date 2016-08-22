//头插法
typedef LNode* LinkList;
void CreateList_L(LinkList &L, int n){
	//逆位序输入n个元素的值，建立带头结点的单链表L
	L = (LinkList)malloc(sizeof(LNode));//头结点，data域不用
	L->next = NULL;
	for(int i = n;i > 0; i--){
		p = (LinkList)malloc(sizeof(LNode));//生成新的结点
		scanf("%d",&p->data);//输入元素值
		p->next = L->next;
		L->next = p;//L最后指向的是最新生成的那个结点
	}
} //CreateList_L