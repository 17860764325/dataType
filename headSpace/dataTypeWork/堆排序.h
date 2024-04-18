//
// Created by lihaoran on 2024/2/7.
//

#ifndef UNTITLED1_堆排序_H
#define UNTITLED1_堆排序_H
#include "所有的数据结构.h"


class 堆排序 {
public:
    /// 创建大根堆
    void BuildMaxHeap(int A[],int len);
    /// 将以k为根的子树调整为大根堆
    void HeadAdjust(int A[],int k,int len);
    /// 对大根堆进行排序
    void HeapSort(int A[],int len);
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
};


#endif//UNTITLED1_堆排序_H
