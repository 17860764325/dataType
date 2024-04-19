//
// Created by lihaoran on 2024/2/7.
//

#include "../../headSpace/dataTypeWork/堆排序.h"

void 堆排序::BuildMaxHeap(int *A, int len) {
    for (int i = len / 2; i > 0; i--) {/// 从后往前调整所有非终端节点
        HeadAdjust(A, i, len);
    }
}

void 堆排序::HeadAdjust(int *A, int k, int len) {
    A[0] = A[k];/// A[0]暂存子树的根节点
    for (int i = 2 * k; i <= len; i *= 2) { /// 下坠一次，还要判断是否影响下一级的 “根> 左，右”的规则
        if (i < len && A[i] < A[i + 1]) /// 获取到左右子树最大的一个
            i++;
        if (A[0] < A[i]) { /// 最大子树和根节点比较如果根节点小，就交换
            swap(A[k], A[i]);
            k = i;
        } else {
            break; /// 如果根节点不小，那么就返回
        }
    }
    A[k] = A[0]; /// A[k] 为最终“下坠”到的位置，最终将本次下坠的元素放到最终位置。
}


void 堆排序::HeapSort(int *A, int len) {
    BuildMaxHeap(A,len); /// 先进行一次大根堆的创建
    for (int i = len; i > 1  ; i--) { /// n-1趟堆排序的过程
        swap(A[i],A[1]); /// 将最后一个元素和第一个元素交换（这样每次循环就会确定一个最终的最后一个元素）
        HeadAdjust(A,1,i-1);/// 把剩余待排序的元素整理成堆
    }
}