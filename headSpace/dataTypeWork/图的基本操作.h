//
// Created by lihaoran on 2024/1/24.
//

#ifndef UNTITLED1_图的基本操作_H
#define UNTITLED1_图的基本操作_H
/// 最大顶点数
#define MaxVertexNum 100
#include "stdio.h"

class 图的基本操作 {
private:
    /// 非带权邻接矩阵存储结构
    typedef struct {
        char Vex[MaxVertexNum]; /// 顶点表
        int Edge[MaxVertexNum][MaxVertexNum]; /// 领接表，边表
        int vexnum,arcnum; /// 当前顶点数，和，边数/弧数
    } MGraphWithoutPower;

    /// 带权邻接矩阵存储结构
    typedef char VertexType; /// 顶点数据类型
    typedef int EdgeType; /// 权值数据类型
    typedef  struct {
        VertexType Vex[MaxVertexNum];  /// 顶点
        EdgeType Edge[MaxVertexNum][MaxVertexNum]; /// 边的权
        int vexnum,arcnum; /// 图的当前顶点数和弧数
    } MGraphWithPower;


    /// 边/弧
    typedef struct ArcNode {
        int adjvex; /// 边/弧指向那个节点
        struct ArcNode *next; /// 指向下一条弧的指针
        // InfoType info;  /// 边权值
    } ArcNode;

    /// 顶点
    typedef struct VNode{
        VertexType data;
        ArcNode *first;
    } VNode,AdjList[MaxVertexNum];

    /// 用邻接表来表示图
    typedef struct {
        AdjList vertices;
        int vexnum,arcnum;
    } ALGraph;
public:
    int MNextNeighbor(MGraphWithoutPower,int,int);
    int ALNextNeighbor(ALGraph ,int,int);
};


#endif//UNTITLED1_图的基本操作_H
