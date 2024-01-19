//
// Created by lihaoran on 2024/1/19.
//

#ifndef UNTITLED1_拓扑排序_H
#define UNTITLED1_拓扑排序_H
#include "stdio.h"
#include "stdlib.h"


#define MaxVertexNum 100

class 拓扑排序 {
private:
    typedef char VertexType; /// 顶点数据类型
    typedef int EdgeType; /// 权值数据类型

    /// 边/弧
    typedef struct ArcNode{
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

    // 初始化一个链栈
    typedef struct LinkNode{
        int data;
        struct LinkNode *next;
    }LinkNode, *LStack;

    // 初始化一个链栈 带头节点
    bool InitWithHead(LStack &L){
        printf("初始化带头节点\n");
        L = (LStack)malloc(sizeof(LStack));
        L->next = NULL;
        return true;
    }

    // 判断是否为空 ,判断链表是否为空---带头节点
    bool isEmptyHead(LStack L){
        if (L -> next == NULL) {
            printf("带头节点栈为空\n");
            return true;
        }
        printf("带头节点栈不为空\n");
        return false ;
    }

    // 进栈操作--带头节点
    bool PushHead(LStack &L,int x){
        printf("带头节点进栈操作：%d\n",x);
        LStack p = (LinkNode *)malloc(sizeof(LinkNode));
        p->data = x;
        p->next = L->next;
        L ->next = p;
        return true;
    }


    // 出栈操作--带头节点
    bool PopHead(LStack &L,int &x){
        if (L->next == NULL) {
            return false ;
        }
        x = L->next->data;
        printf("带头节点出栈操作：%d\n",x);
        L->next  = L->next->next;
        return true;
    }

    // 存储节点度的一个数组
    int indegree[MaxVertexNum];
    // 存储拓扑排序顺序的一个数组
    int print[MaxVertexNum];
public:
    LStack s;

    /// 找寻节点的第一个邻接点
    int FirstNeighbor(ALGraph G,int v){
        return 0;
    }
    /// 找寻节点的下一个邻接点
    int NextNeighbor(ALGraph G,int v,int w){
        return 0;
    }

    bool TopologicalSort(ALGraph &G);

};


#endif//UNTITLED1_拓扑排序_H
