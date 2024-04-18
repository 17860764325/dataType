//
// Created by lihaoran on 7/5/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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

BiTree  flag;
// 打印节点值为x的所有父亲节点
int function(BiTree t,int x){
    if (t == NULL){
        std::cout << "树空" << std::endl;
    }
    // 声明存储变量

    function(t->lchild,x);
    function(t->rchild,x);

    if (t->data.value == x){
        flag = t;
    }
    if (t->lchild == flag || t->rchild == flag){
        std::cout << t->data.value << std::endl;
    }
    return 0;
}

int main(){
    BiTree A;
    A->data.value = 1;
    BiTNode* B;
    B->data.value = 2;
    BiTNode* C;
    C->data.value = 3;
    BiTNode* D;
    D->data.value = 4;
    BiTNode* E;
    E->data.value = 5;
    BiTNode* F;
    F->data.value = 6;
    BiTNode* G;
    G->data.value = 7;
    A->lchild = B;
    A->rchild=C;
    B->lchild=D;
    B->rchild=E;
    C->lchild=F;
    C->rchild=G;
    function(A,4);

}