typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct 
{
	QueuePtr front;
	QueuePtr rear;
} LinkQueue;

//基本操作算法 --部分

Status Destroy(LinkQueue &Q)
{
	//销毁队列
	while(Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}

Status EnQueue(LinkQueue &Q, QElemType e)
{
	//插入元素e为Q的新元素
	p = (QueuePtr)malloc(sizeof(QNode));
	if(!p) exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q->rear = p;
	return OK;
}

Status DeQueue(LinkQueue &Q, QElemType &e)
{
	if(Q.front == Q.rear) return ERROR;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if(Q.rear == p)
	{
		Q.rear= Q.front;
	}
	free(p);
	return OK;
}