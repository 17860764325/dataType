//
// Created by lihaoran on 2024/1/15.
//

#include "dataTypeWork/图的广度优先遍历.h"

/// 访问节点
void visit(int node){
    // 打印节点
    std::cout<< node<<std::endl;
}

/// 入队列
void 图的广度优先遍历::Enqueue(LinkQueue G,int v){

}

/// 出队列
void 图的广度优先遍历::Dequeue(LinkQueue G){

}

/// 找寻节点的第一个邻接点
int 图的广度优先遍历::FirstNeighbor(MGraphWithPower G,int v){

}
/// 找寻节点的下一个邻接点
int 图的广度优先遍历::NextNeighbor(MGraphWithPower G,int v,int w){

}


/// 广度优先遍历
void 图的广度优先遍历::BFS(MGraphWithPower G,int v) {
    /// 访问节点
    visit(v);
    /// 标记已经访问过
    visited[v] = true;
    /// 顶点入栈队列
    Enqueue(Q,v);
    /// 找相邻的节点
    while(!IsEmptyHead(Q)){
        /// 出队一个节点
        Dequeue(Q);
        /// 找寻相邻的节点并添加到队列
        for (int w = FirstNeighbor(G,v) ; w >= 0 ; w= NextNeighbor(G,v,w) ) {
            /// 检查找的的邻接点是否北方问过
            if (!visited[w]){
                /// 访问邻接点
                visit(w);
                /// 标记已经被访问过
                visited[w] = true;
            }
        }
    }
}
/// 对图的广度优先遍历
void 图的广度优先遍历::BFSraverse(图的广度优先遍历::MGraphWithPower G) {
    /// 循环遍历数组，进行初始化赋值
    for (int i = 0; i < G.vexnum; ++i) {
        visited[i] = false;
    }
    /// 从0开始遍历
    for (int i = 0; i < G.vexnum; ++i) {
        /// 如果没遍历过就进行遍历，防止非连通图，有没有遍历到的图
        if(!visited[i]){
            BFS(G,i);
        }
    }
}

