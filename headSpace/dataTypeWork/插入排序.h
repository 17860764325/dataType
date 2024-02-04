//
// Created by lihaoran on 2024/2/4.
//

#ifndef UNTITLED1_插入排序_H
#define UNTITLED1_插入排序_H
#include "所有的数据结构.h"


class 插入排序 {
private:
    ElemType A[];
public:
    // InssertSort
    void InsertSort(ElemType A[],int n); /// 哨兵模式💂
    void InsertSortWithOut(ElemType A[],int n); /// 普通模式
    void InsertSortMoreBatter(ElemType A[],int n); /// 插入排序优化

};


#endif//UNTITLED1_插入排序_H
