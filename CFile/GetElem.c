Status GetElem_L(LinkList L, int i, ElemType &e){
    //L为带头结点的单链表的头指针
    //当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR

    p = L->next;//指向第一个结点
    j = 1;//计数
    while(p && j < i){
        p = p->next; //指针向后查找，直到p指向第i个元素或者p为空
        ++j;// 若是j++,则在j < i判断后还会加1
    }
    if(!p || j > i) return ERROR;
    e = p->data;
    return OK;
} //GetElem_L
