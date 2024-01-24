//
// Created by lihaoran on 2024/1/24.
//
int MAXNUMBER =  100;
#include "dataTypeWork/图的基本操作.h"
int 图的基本操作::MNextNeighbor(图的基本操作::MGraphWithoutPower G, int x, int y) {
    if (x!=-1 && y!=-1){
        for (int col = 0; col < G.vexnum; ++col) {
            if (G.Edge[x][col]>0 && G.Edge[x][col] < MAXNUMBER){
                return col;
            }
        }
        return -1;
    }
}
int 图的基本操作::ALNextNeighbor(图的基本操作::ALGraph G, int x, int y) {
    if(x!=1){
        ArcNode  *p = G.vertices[x].first;
        while(p!= NULL && p->adjvex!= y){
            p = p->next;
        }
        if (p !=NULL && p-> next !=NULL){
            return p->next->adjvex;
        }
        return -1;
    }
}
