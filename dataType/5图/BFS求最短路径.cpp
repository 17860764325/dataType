//
// Created by lihaoran on 2024/1/16.
//

#include "../../headSpace/dataTypeWork/BFS求最短路径.h"



int BFS求最短路径::NextNeighbor(BFS求最短路径::MGraphWithPower G, int v, int w) {

}
int BFS求最短路径::FirstNeighbor(BFS求最短路径::MGraphWithPower G, int v) {

}

void BFS求最短路径::Dequeue(BFS求最短路径::LinkQueue G) {

}

void BFS求最短路径::Enqueue(BFS求最短路径::LinkQueue G, int v) {

}

/// 广度优先遍历后，处理每个节点的操作，记录最短路径，以及记录前驱节点
void BFS求最短路径::vist(bool flag,int u,int w){
    /// 对单源根节点的操作
    if (flag){
        /// 根节点到根节点的最短路径为0
        d[u] = 0;
        /// 根节点已经被访问过了
        visited[u]= true;
        /// 将根节点入队
        Enqueue(Q,u);
    }else{
        /// 对邻接节点的操作
        /// 增加路径长度
        d[w] = d[u] + 1;
        /// 设置邻接点的前驱，（当前节点到前驱为路径最短）
        path[w] = u;
        /// 设置访问标识
        visited[w] = true;
        /// 将该节点入队
        Enqueue(Q,w);

    }
}


/// 求的最短路径的方法
void BFS求最短路径::BFS_MIN_Distance(BFS求最短路径::MGraphWithPower G, int u) {
    /// d[i] 表示从u到i节点的最短路径
    for (int i = 0; i <G.vexnum ; ++i) {
        /// 设置最大值
        d[i] = 2147483647;
        /// 设置默认值
        path[i] = -1;
    }
    /// 标记访问
    vist(true,u,NULL);
    /// 循环找
    while(!BFS求最短路径::IsEmptyHead(Q)){
        /// 出队操作
        Dequeue(Q);
        /// 寻找邻接节点，
        for (int w = FirstNeighbor(G,u) ;w >= 0 ; w = NextNeighbor(G,u,w)) {
            /// 访问节点操作
            vist(false,u,w);
        }
    }
}