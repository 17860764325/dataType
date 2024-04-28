//
// Created by lihaoran on 2024-04-23.
//

#include "../../headSpace/dataTypeWork/二叉树中最表达式打印.h"

void 二叉树中最表达式打印::BtreeToE(BSTree root) {
    BtreeToExp(root,1);
}
void 二叉树中最表达式打印::BtreeToExp(BSTree root, int deep) {
    if (root == NULL) return ;
    else if (root ->lchild == NULL && root -> rchild == NULL){
        printf("s%",root->key);
    }else {
        if (deep > 1) printf("(");
        BtreeToExp(root->lchild,deep + 1);
        printf("s%",root->key);
        BtreeToExp(root->rchild,deep + 1);
        if (deep > 1) printf(")");
    }
}
int main(){

}