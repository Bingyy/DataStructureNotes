//使用邻接矩阵存储
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 20 
#define INF 10000 // 表示顶点之间不可达
#define FALSE 0
#define TRUE 1
typedef int bool;

typedef struct ArcCell //若info用不到，可以直接定义AdjMatrix[20][20],这里用最难的方式实现
{
	int adj;//存储边之间的权值
	// int info; //这里用不到
} ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
// 定义图
typedef struct 
{
	int vexs[MAX_VERTEX_NUM];//顶点向量，存储顶点内容
	AdjMatrix arcs;//存储顶点之间的关系
	int vexnum, arcnum;//图的顶点数和边数
}MGraph;

int LocateElem(MGraph *G, int c)
{
	for(int i = 0; i < G->vexnum;i++)
	{
		if(G->vexs[i] == c)
			return i;
	}
	return MAX_VERTEX_NUM; //返回一个矩阵中不用的下标数字即可
}

void CreateGraph(MGraph *G)//构造图
{
	printf("请输入顶点数，边数：\n");
	scanf("%d%d",&G->vexnum,&G->arcnum);//输入图的顶点数目和边数目

	// printf("请输入顶点内容,顶点数为%d\n",G->vexnum);

	for(int i = 0; i < G->vexnum; i++)//初始化图的顶点
	{	
		// printf("输入结点%d: ",i);
		scanf("%d",&G->vexs[i]); //输入顶点信息：a,b,c,d...,假设顶点值各不相同
		// getchar();
	}

	printf("结点内容输入完毕！---\n");
	//初始化邻接矩阵
	for(int i = 0; i < G->vexnum; i++)
	{
		for(int j = 0; j < G->vexnum; j++)
		{
			G->arcs[i][j].adj = INF;//设置顶点间的距离都是INF
		}
	}

	//构造邻接矩阵
	printf("请输入边：\n");
	for(int k = 0; k < G->arcnum; k++)
	{
		// printf("请输入边：\n");
		int u,v;//u,v分别为顶点存储内容
		int w; //w是边的权值
		scanf("%d %d %d",&u,&v,&w); //输入边
		// getchar();
		//根据顶点内容找到结点的下标--在一维数组中寻找
		int i = LocateElem(G,u);
		int j = LocateElem(G,v);
		G->arcs[i][j].adj = w;
		G->arcs[j][i].adj = w; //无向，所以对称边也赋值
	}
}

void Prim(MGraph *MG)
{
	MGraph *G = (MGraph*)malloc(sizeof(MGraph));
	G->vexnum = MG->vexnum;
	G->arcnum = MG->arcnum;
	//清洗掉权值数据，赋值为INF
	for(int i = 0; i < G->vexnum; i++)
	{
		for(int j = 0; j < G->vexnum; j++)
		{
			G->arcs[i][j].adj = INF;//设置顶点间的距离都是INF
		}
	}

	for(int i = 0; i < MG->vexnum;i++)
	{
		G->vexs[i] = MG->vexs[i];
	}

	//设定一个标记数组，标记结点是否在树中
	bool NodeInTree[G->vexnum];
	int count = 0;//记录已经加入到树中的结点数目
	for(int i = 0; i < G->vexnum; i++)
	{
		NodeInTree[i] = FALSE; //初始时没有一个结点在树中
	} 

	//任意选择一个结点
	int u,v;
	u = G->vexnum / 2; //从中间开始进行构造树
	NodeInTree[u] = TRUE; //标记结点选中放到树中
	count++;
	while(count < G->vexnum) //直到加入树中的结点数与G.vexnum相等为止
	{
		int MinEdge = MG->arcs[u][0].adj;

		//寻找U,V-U之间最小边，两层for循环
		for(int i = 0; i < G->vexnum && NodeInTree[i]; i++)//在树中的结点
		{
			for(int j = 0; j < G->vexnum && NodeInTree[j]; j++)//不在树中的结点
			{
				if(MinEdge > MG->arcs[i][j].adj)
				{
					MinEdge = MG->arcs[i][j].adj;
					u = i;
					v = j;
				}
			}
		}
		G->arcs[u][v].adj = MG->arcs[u][v].adj;
		NodeInTree[v] = TRUE;
	}
	MG = G;
}

int main(void)
{
	MGraph *G = (MGraph*)malloc(sizeof(MGraph));
	CreateGraph(G);
	printf("%d %d\n", G->vexnum,G->arcnum);

	Prim(G);//seg 11 .... 需要检查一下！

	for(int i = 0; i < G->vexnum; i++)
	{
		for(int j = 0; j < G->vexnum; j++)
		{
			printf("%d ", G->arcs[i][j].adj);
		}
		printf("\n");
	}
	return 0;
}
