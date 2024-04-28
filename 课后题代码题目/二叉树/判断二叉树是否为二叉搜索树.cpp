//
// Created by lihaoran on 2024-04-23.
//

#include "../../headSpace/dataTypeWork/判断二叉树是否为二叉搜索树.h"

bool 判断二叉树是否为二叉搜索树::fun(判断二叉树是否为二叉搜索树::SqBiTree bt, int k, int *val) {
    if (k < bt.ElemNum && bt.SqBiNode[k] != -1) {
        if (!fun(bt, 2 * k + 1, val)) return false;
        if (bt.SqBiNode[k] <= *val) return false; /// 因为二叉搜索树，是递增的，
        *val = bt.SqBiNode[k]; /// 所以判断最新的值bt.SqBiNode[k]  是否大于原先的最大值 *val
        if (!fun(bt, 2 * k + 2, val)) return false;
    }
}

int main() {
}