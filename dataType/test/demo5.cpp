//
// Created by lihaoran on 2023/12/1.
//
#include "graph.cpp"
void dispath(MatGraph g,int dist[], int path[],int S[],int v){
    int i,j,k;
    int apath[MAXV],d;
    for (int i = 0; i < g.n; ++i) {
        if(S[i] == 1 && i !=v){
            printf("从顶点%d到定点的路径长度位:%d\t路径位：",v,i,dist[i]);
            d = 0; apath[d] = i;
            k = path[i];
            if(k == -1)
                printf("wulujing\n");
            else
            {
                while(k! = v){
                    d++;apath[d] = k;
                    k = path[k];
                }
                d++;apath[d] = v;
                printf("%d",apath[d]);
                for(j= d -1 ;j >= 0; j --)
                    printf("%d",apath[j]);
                printf("\n");
            }
        }
    }
}
void Dijkstra(MatGraph g, int v){
    int dist[MAXV],path[MAXV];
    int S[MAXV];
    int Mindis,i,j,u;
    for (i=0;i<g.n;i++)
    {
        dist[i]= g.edges[v][i];
        S[i] = 0;
        if(g.edges[v][i] < INF)
            path[i] = v;
        else
            path[i] = -1;
    }
    S[v] = 1;path[v] = 0;
    for(i =0;i<g,n-1;i++)
    {
        Mindis = INF;
        for(j = 0;j<g.n;j++)
        {
            u = j;
            Mindis = dist[j];
        }
        S[u] = 1;
        for (int j = 0; j < g.n ; j++)
            if(S[j] == 0)
                if(g.edges[u][j] < INF && dist[u] + g.edges[u][j] < dist[j])
                {
                    dist[j] = dist[u] + g.edges[u][j];
                    path[j] = u;
                }
    }
    Dispath(g,dist,path,S,v);
}
//int main(){
//    int v =0;
//    MatGraph g;
//    int A[MAXV][MAXV] = {
//            {0,5,INF,7,INF,INF},{INF,0,4,INF,INF,INF},
//            {8,INF,0,INF,INF,9},{INF,INF,5,0,INF,6},
//            {INF,INF,INF,5,0,INF},{3,INF,INF,INF,1,0}
//    };
//    int n =6,e = 10;
//    CreateMat(g,A,n,e);
//    printf("有向图 G 的临接矩阵:\n");DispMat(g);
//    printf("狄克斯特拉算法求解结果:\n");
//    Dijkstra(g,v);
//    return 1;
//}