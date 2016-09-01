MST(G)
{
	T = NULL;
	do
	{
		最小代价边 = (u,v);//u∈U,v∈(V-U)
		T = T ∪ (u,v); 
	} while(T还未形成一棵生成树)
}

//Prim算法
void Prim(G,T)
{
	T = NULL; //初始化空树
	U = {w}; //添加任一顶点w
	while((V-U) != 0)//树还没有拿到全部结点
	{
		MinEdge = (u,v);//u是U中结点，v是V-U中结点
		T = T + (u,v); //边加入树
		U = U + v; //点加入树
	}
}

//Kruskal算法
void Kruskal(G,T)
{
	T = V;//初始化树T，仅仅包含顶点
	numS = n; // 不连通分量数
	while(nums - 1 > 0)//控制仅选择n-1条边
	{
		e = (u,v); //从E-ET中选择权值最小的边
		if(u和v属于T中不同的连通分量)//加入后不产生回路
		{
			T = T + (u,v);
			numS--; // 不连通分量数减1
		}
	}

}