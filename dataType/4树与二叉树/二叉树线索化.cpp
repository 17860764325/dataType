//
// Created by lihaoran on 7/17/23.
// 中序线索二叉树
#include <stdio.h>
#include <stdlib.h>

// 线索二叉树的节点
typedef struct ThreadNode {
    int data;
    struct ThreadNode *lchild, *rchild;
    // 标志位，0 表示左孩子，1 表示前驱
    int ltag, rtag;
} ThreadNode, *ThreadTree;

// 全局变量 pre 指向当前访问节点的前驱
ThreadNode *pre = NULL;


// 中序遍历二叉树
void InThread(ThreadTree T){
    if (T != NULL){
        InThread(T->lchild);
        // 如果当前节点没有左孩子，则将 lchild 指向前驱
        if (T->lchild == NULL){
            T->lchild = pre;
            T->ltag = 1;
        }
        // 如果前驱没有右孩子，则将前驱的 rchild 指向当前节点
        if (pre != NULL && pre->rchild == NULL){
            pre->rchild = T;
            pre->rtag = 1;
        }
        pre = T;
        InThread(T->rchild);
    }
}


// 中序线索化二叉树
void CreateInthread(ThreadTree T){
    pre = NULL;
    if (T != NULL){
        InThread(T);
        if (pre->rchild == NULL){
            pre->rtag = 1;
        }
    }
}

// 先序线索化二叉树
void PreThread(ThreadTree T){
    if (T != NULL){
        // 如果当前节点没有左孩子，则将 lchild 指向前驱
        if (T->lchild == NULL){
            T->lchild = pre;
            T->ltag = 1;
        }
        // 如果前驱没有右孩子，则将前驱的 rchild 指向当前节点
        if (pre != NULL && pre->rchild == NULL){
            pre->rchild = T;
            pre->rtag = 1;
        }
        pre = T;
        // 如果当前节点没有左孩子，则递归线索化右子树
        if (T->ltag == 0){
            PreThread(T->lchild);
        }
        // 如果当前节点没有右孩子，则递归线索化右子树
        if (T->rtag == 0){
            PreThread(T->rchild);
        }
    }
}

// 先序线索化二叉树
void CreatePrethread(ThreadTree T){
    pre = NULL;
    if (T != NULL){
        PreThread(T);
        if (pre->rchild == NULL){
            pre->rtag = 1;
        }
    }
}

// 后序线索化二叉树
void PostThread(ThreadTree T){
    if (T != NULL){
        // 如果当前节点没有左孩子，则递归线索化右子树
            PostThread(T->lchild);
        // 如果当前节点没有右孩子，则递归线索化右子树
            PostThread(T->rchild);
        // 如果当前节点没有左孩子，则将 lchild 指向前驱
        if (T->lchild == NULL){
            T->lchild = pre;
            T->ltag = 1;
        }
        // 如果前驱没有右孩子，则将前驱的 rchild 指向当前节点
        if (pre != NULL && pre->rchild == NULL){
            pre->rchild = T;
            pre->rtag = 1;
        }
        pre = T;
    }
}

// 后序线索化二叉树
void CreatePostthread(ThreadTree T){
    pre = NULL;
    if (T != NULL){
        PostThread(T);
        if (pre->rchild == NULL){
            pre->rtag = 1;
        }
    }
}

