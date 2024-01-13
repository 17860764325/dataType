//
// Created by lihaoran on 2024/1/13.
//

#ifndef UNTITLED1_十字链表法存储有向图_H
#define UNTITLED1_十字链表法存储有向图_H

/// 最大顶点数
#define MaxVertexNum 100

class 十字链表法存储有向图 {
private:
    /// info的类型
    typedef int EdgeType;

    /// 弧的结构表示
    typedef struct ArcBox
    {
        /// 弧头，弧尾
        int tailvex, headvex;
        /// 权值
        EdgeType  *info;
        /// hlink弧头相同的下一条弧，CA，DA
        /// tlink弧尾相同的下一条弧，AC，AD
        struct ArcBox  *hlink, *tlink;
    } ArcBox;

    /// 顶点的结构表示
    typedef struct VexNode
    {
        /// 顶点值
        EdgeType  data;
        /// firstin第一个 弧头为顶点值的弧 CA，DA
        /// firstout第一个 弧尾为顶点值的弧 AC，AB
        ArcBox  *firstin, *firstout;
    } VexNode;

    /// 十字链表存储结构
    typedef struct
    {
        /// 顶点结点(表头向量)
        VexNode  xlist[MaxVertexNum];
        /// 有向图的当前顶点数和弧数
        int   vexnum, arcnum;
    } OLGraph;

public:
};


#endif//UNTITLED1_十字链表法存储有向图_H
