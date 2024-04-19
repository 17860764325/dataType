//
// Created by lihaoran on 2024/1/31.
//

#include "../../headSpace/dataTypeWork/判断二叉树是否为平衡二叉树.h"

int 判断二叉树是否为平衡二叉树::functon(BSTree bt, int &balance, int &h) {
    int bl = 0, br = 0, hl = 0, hr = 0; /// 左右子树平衡标记以及高度。
    if (bt == NULL){
        h = 0;
        balance = 1;
    }else if (bt -> lchild == NULL&& bt -> rchild == NULL){
        h =1;
        balance = 1;
    }else {
        functon(bt->lchild,bl,hl); /// 递归判断左子树
        functon(bt->rchild,br,hr);/// 递归判断右子树
        h = (hl > hr? hl:hr) + 1; /// 选择子树最高的那个加一作为本层树高
        if (hl-hr < 2 &&  hl-hr > -2){ /// 如果左右子树差值的绝对值小于 2
            balance = br && bl; /// 左右子树都平衡时候，二叉树平衡
        }else {
            balance = 0; /// 否则不平衡
        }
    }

}