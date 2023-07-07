//
// Created by lihaoran on 7/3/23.
// 二叉树的链式存储
#include <stdio.h>
#include <stdlib.h>
struct ElemType {
    int value;
};
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 定义一棵空树
bool InitBiTree(BiTree &T) {
    // 定义一棵空树
    BiTree  root = NULL;
    // 插入根节点
    root = (BiTree) malloc(sizeof(BiTNode));
    root ->data = {1};
    root ->lchild = NULL;
    root ->rchild = NULL;

    // 插入新的节点
    BiTNode  * p = (BiTNode *)malloc(sizeof(BiTNode));
    p->data = {2};
    p->lchild = NULL;
    p->rchild = NULL;
    root->lchild = p;
}
