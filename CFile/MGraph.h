// -----图的数组存储（邻接矩阵）表示
#define INF INT_MAX
#define MAX_VERTEX_NUM 20
#define OK 1
typedef enum 
{
	DG,DN,UDG,UDN //有向图，有向网，无向图，无向网
}GraphKind;

typedef struct ArcCell
{
	VRType adj; //顶点关系类型，无权图：用0或1表示是否相邻，带权图，则为权值类型
	InfoType *info; //该弧相关信息的指针	
} ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];


typedef struct{
    VertexType vexs[MAX_VERTEX_NUM];//顶点向量，一维数组
    AdjMatrix arcs; //边的信息，邻接矩阵,二维数组
    int vexnum, arcnum;//图的当前顶点数和弧数
    GraphKind kind; //图的种类标志
} MGraph;


Status CreateGraph(MGraph &G){
    //使用数组（邻接矩阵表示法）构造图G
    scanf(&G.kind);
    switch(G.kind){
    	case DG: return CreateDG(G); //构造有向图G
    	case DN: return CreateDN(G); //构造有向网G
    	case UDG: return CreateUDG(G); //构造无向图G
    	case UDN: return CreateUDN(G); //构造无向网G
    	default : return ERROR;
    }
} // CreateGraph

//具体的创建算法

Status CreateUDN(MGraph &G){
	//使用数组（邻接矩阵表示法）构造无向网 G
	scanf(&G.vexnum,&G.arcnum,&IncInfo);//IncInfo为0则各弧不含其它信息
	for(int i = 0; i < G.vexnum; i++){
		scanf(&G.vexs[i]);//输入顶点的信息
	}
	for(int i = 0; i < G.vexnum; i++){
		for(int j = 0; j < G.vexnum; j++){
			G.arcs[i][j] = {INFINITY,NULL}; //初始化边的信息，两个值分别对应VRType, InfoType
		}
	}
	// 构造邻接矩阵,面向边构造此矩阵
	for(int k = 0; k < G.arcnum; k++){
		scanf(&v1,&v2,&w); //输入的是边依附的顶点和权值，输入的v1,v2是值而不是下标
		int i = LocateVex(G,v1);
		int j = LocateVex(G,v2);//根据v的值确定在G中的位置
		G.arcs[i][j].adj = w; // 弧<vi,vj>的权值， adj表示连接的边
		if(IncInfo) Input(*G.arcs[i][j].info); //若弧含有相关信息，则输入
		G.arcs[j][i] = G.arcs[i][j];//这个是无向网，所以有对称弧
	}
	return OK;
} //CreateUDN

