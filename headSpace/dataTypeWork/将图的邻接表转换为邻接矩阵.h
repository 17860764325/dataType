//
// Created by lihaoran on 2024/1/17.
//

#ifndef UNTITLED1_将图的邻接表转换为邻接矩阵_H
#define UNTITLED1_将图的邻接表转换为邻接矩阵_H
/// 最大顶点数
#define MaxVertexNum 100
#include "iostream"

class 将图的邻接表转换为邻接矩阵 {
private:
    /// 邻接表
    typedef struct Tarc {
        int data; /// 节点内容
        Tarc* nextTarc; /// 下一个节点
    } Tarc;

    typedef struct {
        int data; /// 节点内容
        Tarc * firstarc; /// 第一个邻接节点
    } AdjList;

    /// 用邻接表来表示图
    typedef struct {
        AdjList vertices[MaxVertexNum];
        int vexnum,arcnum;
    } ALGraph;


    /// 邻接矩阵
    typedef struct {
        char Vex[MaxVertexNum]; /// 顶点表
        int Edge[MaxVertexNum][MaxVertexNum]; /// 领接表，边表
        int vexnum,arcnum; /// 当前顶点数，和，边数/弧数
    } MGraphWithoutPower;
public:
    /// 转换方法 邻接表--》邻接矩阵
    void Convert(ALGraph,MGraphWithoutPower);
};


#endif//UNTITLED1_将图的邻接表转换为邻接矩阵_H
