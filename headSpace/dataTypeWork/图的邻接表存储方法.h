//
// Created by lihaoran on 2024/1/12.
//

#ifndef UNTITLED1_图的邻接表存储方法_H
#define UNTITLED1_图的邻接表存储方法_H

/// 最大顶点数
#define MaxVertexNum 100


class 图的邻接表存储方法 {
private:
    typedef char VertexType; /// 顶点数据类型
    typedef int EdgeType; /// 权值数据类型

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

};


#endif//UNTITLED1_图的邻接表存储方法_H
