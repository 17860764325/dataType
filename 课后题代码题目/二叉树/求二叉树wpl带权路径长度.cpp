//
// Created by lihaoran on 2024-04-23.
//

#include "../../headSpace/dataTypeWork/求二叉树wpl带权路径长度.h"

int 求二叉树wpl带权路径长度::wpl(BSTree root) {
    return wpl1(root,0);
}

int 求二叉树wpl带权路径长度::wpl1(BSTree root, int d) {
    if (root->lchild ==NULL&&root->rchild ==NULL){
        return root->key*d;
    }else {
        return wpl1(root->lchild,d+1) + wpl1(root->rchild,d+1);
    }
}

int main(){

}