//
// Created by lihaoran on 7/5/23.
//
#include <stdio.h>
struct ElemType {
    int value;
};

typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 使用递归的方式实现树的遍历
// 先序遍历
void PreOrderTraverse(BiTree T) {
    if (T == NULL) {
        return;
    }
    printf("%d", T->data.value); // 先访问根节点
    PreOrderTraverse(T->lchild); // 再访问左子树
    PreOrderTraverse(T->rchild); // 最后访问右子树
}
// 中序遍历
void InOrderTraverse(BiTree T) {
    if (T == NULL) {
        return;
    }
    InOrderTraverse(T->lchild); // 先访问左子树
    printf("%d", T->data.value); // 再访问根节点
    InOrderTraverse(T->rchild); // 最后访问右子树
}
// 后序遍历
void PostOrderTraverse(BiTree T) {
    if (T == NULL) {
        return;
    }
    PostOrderTraverse(T->lchild); // 先访问左子树
    PostOrderTraverse(T->rchild); // 再访问右子树
    printf("%d", T->data.value); // 最后访问根节点
}

// 求树的深度
int TreeDepth(BiTree T) {
    if (T == NULL) {
        return 0;
    }
    int l = TreeDepth(T->lchild); // 先访问左子树
    int r = TreeDepth(T->rchild);// 再访问右子树
    return l > r ? l + 1 : r + 1; // 取最大的一遍 + 1
}