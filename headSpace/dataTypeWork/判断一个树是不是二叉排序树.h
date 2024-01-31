//
// Created by lihaoran on 2024/1/31.
//

#ifndef UNTITLED1_判断一个树是不是二叉排序树_H
#define UNTITLED1_判断一个树是不是二叉排序树_H
#include "stdio.h"

class 判断一个树是不是二叉排序树 {
private:
    typedef int ElemType;
    typedef struct BiTNode {
        ElemType data;
        struct BiTNode *lchild, *rchild;
    } BiTNode, *BiTree;
public:
    ElemType predt = -32767 ;
    int function(BiTree bt);
};


#endif//UNTITLED1_判断一个树是不是二叉排序树_H
