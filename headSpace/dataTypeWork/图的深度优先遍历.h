//
// Created by lihaoran on 2024/1/15.
//

#ifndef UNTITLED1_图的深度优先遍历_H
#define UNTITLED1_图的深度优先遍历_H
#include "iostream"

#define MAX_VERTEX_NUM 10
#define MaxVertexNum 100

class 图的深度优先遍历 {
private:
    /// 记录节点是否访问过的一个布尔类型的数组
    bool visited[MAX_VERTEX_NUM];

    /// 带权邻接矩阵存储结构
    typedef char VertexType; /// 顶点数据类型
    typedef int EdgeType; /// 权值数据类型
    typedef  struct {
        VertexType Vex[MaxVertexNum];  /// 顶点
        EdgeType Edge[MaxVertexNum][MaxVertexNum]; /// 边的权
        int vexnum,arcnum; /// 图的当前顶点数和弧数
    } MGraphWithPower;
public:
    void DFS(MGraphWithPower G,int v);
    void DFSTraverse(MGraphWithPower G);
    /// 找寻节点的第一个邻接点
    int FirstNeighbor(MGraphWithPower G,int v);
    /// 找寻节点的下一个邻接点
    int NextNeighbor(MGraphWithPower G,int v,int w);
};


#endif//UNTITLED1_图的深度优先遍历_H
