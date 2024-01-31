//
// Created by lihaoran on 2024/1/31.
//

#ifndef UNTITLED1_红黑树数据结构_H
#define UNTITLED1_红黑树数据结构_H


class 红黑树数据结构 {
private:
    struct RBNode{
        int key; /// 关键值
        RBNode * parent; /// 父亲节点
        RBNode * lchild; /// 左孩子
        RBNode * rchild; /// 右孩子
        int color; /// 节点颜色，0:黑，1:红

    };
};


#endif//UNTITLED1_红黑树数据结构_H
