//
// Created by lihaoran on 2024/1/31.
//

#include "dataTypeWork/章节734的10题.h"

BSTNode *章节734的10题::function(BSTree b, int k) {
    /// 在以t为根的子树上寻找第k小的元素，返回其所在的节点的指针。k从11开始计算
    /// 栽树的节点中增加一个count 数据成员存储以该节点为根的子树的结点的个数
    if (k < 1 || k > b ->count) return NULL;
    if (b -> lchild == NULL){
        if (k == 1 ) return b;
        else return function(b->rchild,k-1);
    }else {
        if (b->lchild->count ==  k-1) return b;
        if (b->lchild->count >  k-1) return function(b->lchild,k);
        if (b->lchild->count <  k-1) return function(b->rchild,k-(b->lchild->count + 1));
    }
}