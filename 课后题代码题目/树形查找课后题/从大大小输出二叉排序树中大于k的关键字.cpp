//
// Created by lihaoran on 2024/1/31.
//

#include "../../headSpace/dataTypeWork/从大大小输出二叉排序树中大于k的关键字.h"

void 从大大小输出二叉排序树中大于k的关键字::function(BSTree b, int k) {
    /// 便利顺序 右根左 递归
    if (b == NULL) {
        return;
    }
    if (b->rchild != NULL) {
        function(b->rchild, k); /// 递归右子树节点
    }
    if (b->key > k) {
        cout << b->key << endl; /// 打印节点值
    }
    if (b->rchild != NULL) {
        function(b->lchild, k); /// 递归左子树节点
    }
}