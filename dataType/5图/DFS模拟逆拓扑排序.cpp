//
// Created by lihaoran on 2024/1/19.
//

#include "dataTypeWork/DFS模拟逆拓扑排序.h"

//
// Created by lihaoran on 2024/1/15.
//


/// 访问节点
void visit(int node){
    // 打印节点
    std::cout<< node<<std::endl;
}

int DFS模拟逆拓扑排序::NextNeighbor(DFS模拟逆拓扑排序::MGraphWithPower G, int v, int w) {

}

int DFS模拟逆拓扑排序::FirstNeighbor(DFS模拟逆拓扑排序::MGraphWithPower G, int v) {


}

void DFS模拟逆拓扑排序::DFS(DFS模拟逆拓扑排序::MGraphWithPower G, int v) {
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

    // TODO 添加了一print 打印节点，便是逆拓扑排序的顺序
    std::cout<< v <<std::endl;

}

void DFS模拟逆拓扑排序::DFSTraverse(DFS模拟逆拓扑排序::MGraphWithPower G) {
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

/* 但是当图出现了回路，着呢吗判断是否出现了回路并且停止算法执行：我采取的方式
 * 1. 将visted数组更改变成int类型，里面元素分为三种  0，1，2
 * 0: 未进行访问的节点
 * 1:访问中的节点
 * 2:访问完成的节点
 * 通过以上元素进行标记
 *
 * 当循环的时候，只要访问到一个一个节点有以下三种清光：
 * 0:为访问过的节点-》》那就继续进行访问
 * 1:访问中的节点-》》如果邻接节点有访问中的节点，证明出现了回路，那么暂停算法执行
 * 2:访问结束的节点-》》 不进行操作跳过并返回上级邻接节点--正常DFS操作
 */

// 修改后的节点访问组
int vistedChange[10];
bool flag = false;
void DFS模拟逆拓扑排序::DFS_TP(DFS模拟逆拓扑排序::MGraphWithPower G, int v) {
    /// 判断是否已经遇到回路，遇到的话直直接报错
    if(flag){
        throw ;
    }
    /// 访问节点
    visit(v);
    /// 将节点标记为访问中
    vistedChange[v]=1;
    /// 递归循环的找他的邻接节点
    for(int w = FirstNeighbor(G,v);w >=0;w = NextNeighbor(G,v,w)){
        /// 如果没访问过就继续递归找
        switch (vistedChange[w]) {
            case 0:
                // 未访问节点，继续进行访问
                DFS_TP(G,w);
            case 1:
                // 跳出循环--遇到回路
                flag = true;
            case 2:
                // 不经心操作直接返回
                break;
        }
    }
    vistedChange[v] = 2;

}

/// DFS 模拟逆拓扑排序
/*
 *  由于 DFS深度遍历图，是从最后一个节点开始遍历
 *  所以，在访问节点的时候，添加时间戳，最后比较时间戳 ，
 *  时间越长 的越是拓扑排序靠前的
 *  时间越短 的越是拓扑排序靠后的
 *  这样便能得到拓扑排序的 顺序。
 */

