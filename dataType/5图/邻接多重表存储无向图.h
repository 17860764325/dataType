//
// Created by lihaoran on 2024/1/13.
//

#ifndef UNTITLED1_邻接多重表存储无向图_H
#define UNTITLED1_邻接多重表存储无向图_H

#define MAX_VERTEX_NUM 100


class 邻接多重表存储无向图 {
private:
    /// 访问标记
    typedef char VisitIf;
    /// 节点信息
    typedef char InfoType;
    /// 节点类型
    typedef char VertexType;
    /// 边节点
    typedef struct Ebox {
        /// 访问标记
        VisitIf mark;
        /// 该边依附的两个顶点的位置
        int ivex, jvex;
        /// 左节点关系边，右节点关系边
        struct EBox *ilink, *jlink;
        /// 该边信息指针
        InfoType *info;
    } EBox;

    /// 顶点
    typedef struct VexBox {
        /// 顶点内容
        VertexType data;
        /// 指向第一条依附该顶点的边
        EBox *firstedge;
    } VexBox;

    /// 邻接多重表
    typedef struct {
        VexBox adjmulist[MAX_VERTEX_NUM];
        /// 节点数，度数
        int vexnum, edgenum;
    } AMLGraph;
};


#endif//UNTITLED1_邻接多重表存储无向图_H
