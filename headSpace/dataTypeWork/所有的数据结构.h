//
// Created by lihaoran on 2024/2/4.
/// 这里面存储了所有的数据结构类型，以后有新的数据结构类型直接从这里添加即可。

#ifndef UNTITLED1_所有的数据结构_H
#define UNTITLED1_所有的数据结构_H

#include "iostream"
#include "stdio.h"
using namespace std;

typedef int ElemType;/// ElemType 的数据结构类型

/// 单链表
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LinkList;

/// 二叉树的数据结构常用
typedef struct BSTNode {
    int key;
    struct BSTNode *lchild, *rchild;
    int count;/// 栽树的节点中增加一个count 数据成员存储以该节点为根的子树的结点的个数
} BSTNode, *BSTree;

/// 单链表
typedef struct LNode {
    int data;          // 该节点的数据
    struct LNode *next;// 该节点的下一个节点
} LNode, *LinkList;

/// 排序交换方法：
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

/// 基数排序的数据结构
typedef  struct {
    LinkNode *front,*rear;/// 队列的队头和队尾指针
}LinkQueue;

#endif//UNTITLED1_所有的数据结构_H