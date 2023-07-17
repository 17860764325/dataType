//
// Created by lihaoran on 7/10/23.
// 由遍历序列构造二叉树
#include <stdio.h>
#include <stdlib.h>

struct ElemType {
    int value;
};

// 将前序遍历 + 中序遍历的队列转换为二叉树
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
// 将前序遍历 + 中序遍历的队列转换为二叉树
BiTree CreateBiTree(int pre[], int in[], int n) {
    // n 为数组长度
    if (n <= 0) {
        return NULL;
    }
    // 创建根节点
    BiTree T = (BiTree) malloc(sizeof(BiTNode));
    T->data.value = pre[0];
    // 在中序遍历中找到根节点的位置
    int i;
    for (i = 0; i < n; i++) {
        if (in[i] == pre[0]) {
            break;
        }
    }
    // 递归构造左右子树
    T->lchild = CreateBiTree(pre + 1, in, i);
    T->rchild = CreateBiTree(pre + i + 1, in + i + 1, n - i - 1);
    return T;
}