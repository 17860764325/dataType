//
// Created by lihaoran on 2024/1/12.
//

#ifndef UNTITLED1_图的邻接矩阵存储法_H
#define UNTITLED1_图的邻接矩阵存储法_H
/// 最大顶点数
#define MaxVertexNum 100
/// 最大的int值
#define INFINITY

class 图的邻接矩阵存储法 {
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

public:

};



#endif//UNTITLED1_图的邻接矩阵存储法_H
