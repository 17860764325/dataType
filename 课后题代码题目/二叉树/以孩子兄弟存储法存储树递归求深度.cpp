//
// Created by lihaoran on 2024-04-28.
//

#include "../../headSpace/dataTypeWork/以孩子兄弟存储法存储树递归求深度.h"
// p185 综合题5
int 以孩子兄弟存储法存储树递归求深度::fun(BSTNode *T) {
    if (T != NULL) {
        int num1 = fun(T->lchild);
        int num2 = fun(T->rchild);
        if (T->lchild != NULL) {
            return num1 > num2 ? num1 + 1 : num2 + 1;
        } else {
            return num1 > num2 ? num1 : num2;
        }
    }else{
        return 0;
    }
}

void createTree(BSTNode **T)  //传入一个Btree的指针的地址
{
    int data;
    scanf("%d", &data);

    if(data == -1) {    //-1代表终端节点值
        *T = NULL;
    } else {
        *T = (BSTNode *)malloc(sizeof(struct BSTNode));
        (*T)->key = data;
        printf("请输入%d的左孩子节点：", data);
        createTree(&((*T)->lchild));
        printf("请输入%d的右孩子节点：", data);
        createTree(&((*T)->rchild));
    }
}

int main() {
    以孩子兄弟存储法存储树递归求深度 a;
    BSTNode *T = (BSTNode *) malloc(sizeof(LNode));
    createTree(&T);
    int num = a.fun(T);
    cout<< num << endl;

}