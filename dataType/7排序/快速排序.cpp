//
// Created by lihaoran on 2024/2/6.
//

#include "dataTypeWork/快速排序.h"

int Partition(int *A,int low,int high){
    int item = A[low]; /// 取中轴，也就是比较的值，基数
    while(low < high){ /// 如果最小指针小于最大指针
        while(low < high && A[high] >= item ) --high; /// 如果high所在的指针 一直都是大于基准数item，那么就high一直往前循环
        A[low] = A[high]; /// 如果出现比小于基准数的数，那么就将这个数值赋值给low
        while (low < high && A[low] <= item) ++low; /// 如果low所在的指针，一直都是小于基准数item，那么就让low一直往后循环
        A[high] = A[low];/// 如果出现比基准数大的数，那么就将这个数值赋值给high
    }
    A[low] = item; /// 这个时候 low==high 证明已经排序完成，所以将基准数值，赋值给low所在的位置（也同样是high所在的位置）
    return low;/// 返回已经排好序的数值的下标位置
}


void 快速排序::QuickSort(int A[], int low, int high) {
    if (low < high){ /// 如果 low < high
        int item = Partition(A,low,high); /// 进行第一次夸书排序
        QuickSort(A,low, item -1); /// 左边的值在进行快速排序
        QuickSort(A,item + 1, high); /// 右边的值在进行快速排序
    }
}


