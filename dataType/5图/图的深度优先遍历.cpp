//
// Created by lihaoran on 2024/1/15.
//

#include "dataTypeWork/图的深度优先遍历.h"

/// 访问节点
void visit(int node){
    // 打印节点
    std::cout<< node<<std::endl;
}

int 图的深度优先遍历::NextNeighbor(图的深度优先遍历::MGraphWithPower G, int v, int w) {

}

int 图的深度优先遍历::FirstNeighbor(图的深度优先遍历::MGraphWithPower G, int v) {


}

void 图的深度优先遍历::DFS(图的深度优先遍历::MGraphWithPower G, int v) {
    /// 访问节点
    visit(v);
    /// 将节点标记为已经访问的状态
    visited[v]=true;
    /// 递归循环的找他的邻接节点
    for(int w = FirstNeighbor(G,v);w >=0;w = NextNeighbor(G,v,w)){
        /// 如果没访问过就继续递归找
        if (!visited[w]){
            DFS(G,w);
        }
    }
}

void 图的深度优先遍历::DFSTraverse(图的深度优先遍历::MGraphWithPower G) {
    /// 循环初始化
    for (int i = 0; i < G.vexnum; ++i) {
        visited[i] = false;
    }
    /// 循环遍历，主要解决了非连通图的遍历问题
    for (int i = 0; i < G.vexnum; ++i) {
        if(!visited[i]){
            DFS(G,i);
        }
    }
}