//
// Created by lihaoran on 2024/1/17.
//

#include "../../headSpace/dataTypeWork/将图的邻接表转换为邻接矩阵.h"

void 将图的邻接表转换为邻接矩阵::Convert(将图的邻接表转换为邻接矩阵::ALGraph alGraph, 将图的邻接表转换为邻接矩阵::MGraphWithoutPower arcs) {
    /// 循环alGraph 邻接表，将扫描到的 点都赋值给 邻接矩阵
    for (int i = 0; i < alGraph.vexnum; ++i) {
        /// 获取节点
        Tarc* node = alGraph.vertices[i].firstarc;
        /// 循环该节点的所有邻接节点
        while (node != NULL){
            /// 找到邻接矩阵与之对应的节点并设置连线
            arcs.Edge[i][node->data] = 1;
            /// 将节点递增下一个
            node = node->nextTarc;
        }
    }
}