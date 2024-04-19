//
// Created by lihaoran on 2024/1/31.
//

#include "../../headSpace/dataTypeWork/查找二叉排序树中做大最小关键字.h"


int 查找二叉排序树中做大最小关键字::maxfunction(BSTree bt) {
    while(bt ->lchild != NULL){
        bt = bt -> lchild;
    }
    return bt -> key;
}

int 查找二叉排序树中做大最小关键字::minfunction(BSTree bt) {
    while(bt -> rchild != NULL){
        bt = bt -> rchild;
    }
    return bt -> key;
}