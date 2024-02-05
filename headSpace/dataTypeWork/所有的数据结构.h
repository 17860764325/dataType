//
// Created by lihaoran on 2024/2/4.
/// 这里面存储了所有的数据结构类型，以后有新的数据结构类型直接从这里添加即可。

#ifndef UNTITLED1_所有的数据结构_H
#define UNTITLED1_所有的数据结构_H

#include "stdio.h"
#include "iostream"
using namespace std;

typedef int ElemType; /// ElemType 的数据结构类型

/// 二叉树的数据结构常用
typedef struct BSTNode{
    int key;
    struct BSTNode *lchild,*rchild;
    int count;   /// 栽树的节点中增加一个count 数据成员存储以该节点为根的子树的结点的个数
} BSTNode,*BSTree;

#endif//UNTITLED1_所有的数据结构_H