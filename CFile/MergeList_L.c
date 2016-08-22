//将两个有序链表合并为一个
typedef LNode* LinkList;
void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc){
	//已知单链表La和Lb的元素值按照非递减排列
	//归并La和Lb到新的单链表Lc,Lc的元素也按照非递减的排列
	pa = La->next;
	pb = Lb->next;
	Lc = pc = la;//用La的头结点作为Lc的头结点

	while(pa && pb){
		if(pa->data <= pb->data){
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa?pa:pb; //插入剩余段：pa非null的话，pb已经null了
	free(Lb); //释放Lb的头结点
}//MergeList_L