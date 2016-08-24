// --------图的邻接存储表示
//Author: Rick
//Time ： 2016-8-24 22：00
//参考：严版数据结构

#define MAX_VERTEX_NUM 20
typedef VertexType char;

//链表中结点
typedef struct ArcNode
{
	int adjvex; //该弧指向的顶点位置，在数组中的位置
	struct ArcNode *nextarc; //指向下一条弧的指针
}ArcNode;

//头结点
typedef struct VNode
{
	VertexType data; //顶点信息
	ArcNode *firstarc; // 指向第一条依附于该顶点的弧的指针
} VNode,AdjList[MAX_VERTEX_NUM];

typedef struct 
{
	AdjList vertices;
	int vexnum,arcnum; //图的当前顶点数和弧数
} ALGraph;

void CreateGraph(ALGraph &G)
{
	printf("输入图的顶点数，边数： \n");
	scanf("%d%d"，&G.vexnum,&G.arcnum);

	
	printf("输入每个顶点的信息\n");
	//根据结点数目构造顶点表
	for(int i = 0; i < G.vexnum; i++)
	{
		scanf("%c",&G.vertices[i].data);
		G.vertices[i].firstarc = NULL;//初始化指针,注意这里用的是. 不是->
	}

	printf("输入各弧：\n");
	//根据构造表结点
	for(int i = 0; i < G.arcnum;i++)
	{
		VertexType c1, c2;
		//输入边的两个结点的data值
		scanf("%c%c",&c1, &c2);
		int start = LocateVex(G,c1);
		int end = LocateVex(G,c2);

		ArcNode *p;
		// 如果输入的这条边的起点在顺序表中，firstarc还是空的，就为它赋值
		if(G.vertices[start].firstarc == NULL)
		{
			ArcNode *a = (ArcNode *)malloc(sizeof(ArcNode));
			G.vertices[start].firstarc = a;
			p = a;
		}
		else //链表的插入
		{
			p = G.vertices[start].firstarc;//获取头结点的表头指针
			//这个时候不该把新的结点插在firstarc后面，而是在尾巴处插入,将p滑动到单链表尾巴处，等待插入新的ArcNode
			for(int j = 0; j < G.arcnum;j++,p = p->next){
				if(!p->next){
					break;
				}
			}
			ArcNode *a =(ArcNode *)malloc(sizeof(ArcNode));  
            p->nextarc = a; //将该边（弧）加入到链表中  
            p = p->nextarc; 
		}

		p->adjvex = end;
		p = p->NULL;
	}
}

int LocateVex(ALGraph &G,VertexType c)
{
	for(int i = 0; i < G.vexnum; i++)
	{
		if(G.vertices[i].data == c){
			return i;
		}
	}
	return 0;
}

// DFS搜索待完成


