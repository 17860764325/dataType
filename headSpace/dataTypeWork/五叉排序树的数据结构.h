//
// Created by lihaoran on 2024/2/1.
//

#ifndef UNTITLED1_五叉排序树的数据结构_H
#define UNTITLED1_五叉排序树的数据结构_H

typedef int ElemType;
struct Node{
ElemType keys[4]; /// 做多四 个关键字
struct Node * child[5]; /// 最多五个孩子
int num; /// 节点中有几个关键字
};

#endif//UNTITLED1_五叉排序树的数据结构_H
