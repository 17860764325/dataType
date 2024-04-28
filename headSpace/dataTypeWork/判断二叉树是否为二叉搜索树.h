//
// Created by lihaoran on 2024-04-23.
//

#ifndef UNTITLED1_判断二叉树是否为二叉搜索树_H
#define UNTITLED1_判断二叉树是否为二叉搜索树_H
#include "所有的数据结构.h"


class 判断二叉树是否为二叉搜索树 {
private:
    typedef struct {
        int SqBiNode[100];
        int ElemNum;
    } SqBiTree;
public:
    bool fun(SqBiTree bt,int k, int *val);
};


#endif//UNTITLED1_判断二叉树是否为二叉搜索树_H
