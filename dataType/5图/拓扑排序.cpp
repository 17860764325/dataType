//
// Created by lihaoran on 2024/1/19.
//

#include "../../headSpace/dataTypeWork/拓扑排序.h"


bool 拓扑排序::TopologicalSort(拓扑排序::ALGraph &G) {
    // 初始化栈
    InitWithHead(s);
    // 记录i待会出栈用
    int item = 0;
    // 循环 找到入度为0 的节点放入到栈中
    for (int i = 0; i < G.vexnum; ++i) {
        if(拓扑排序::indegree[i] == 0){
            PushHead(拓扑排序::s,i);
            item = i;
        }
    }
    // 定义一个计数器
    int count = 0;
    while(!isEmptyHead(s)){
        // 出栈
        PopHead(s,item);
        // 将拓扑排序元素放入到print数组当中
        print[count++] = item;
        // 循环所有指向的子节点，去掉子节点身上当前节点指向的入读
        for (ArcNode* p = G.vertices[item].first; p != NULL ; p = p->next ) {
            // 将所有item指向的顶点的入度都减一
            int v= p->adjvex;
            // 先将邻接节点的入度减一，再判断子节点减一后是否为0 是的话入栈
            if(!(--indegree[v])){
                // 入栈
                PushHead(s,v);
            }
        }
    }
    // 循环完成之后判断计数cout是否已经全部拓扑节点，如果没有那就证明有环
    if (count < G.vexnum)
        return false;
    else
        return true;
}
