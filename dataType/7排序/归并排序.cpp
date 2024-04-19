//
// Created by lihaoran on 2024/2/8.
//

#include "../../headSpace/dataTypeWork/归并排序.h"

int *B = (int *) malloc(20 * sizeof (int)); /// 开辟空间

void 归并排序::Merge(int *A, int low, int mid, int high) {
    int i,j,k;
    for ( k = low ; k < high; ++k) {
        B[k] = A[k]; /// 将A中的元素赋值B中
    }
    for ( i = low ,j = mid + 1,k = i; i <= mid && j <= high ; k++) {
        if (B[i] <= B[j])
            A[k] = B[i++]; /// 将较小值赋值到A中·
        else
            A[k] = B[j++];
    }
    while (i <= mid ) A[k++] = B[i++];
    while (j <= high ) A[k++] = B[j++];
}

void 归并排序::MergeSort(int *A, int low, int high) {
    if (low <high){
        int mid = (low + high)/2; /// 从中间划分
        MergeSort(A,low,mid); /// 对左半部分归并排序
        MergeSort(A,mid+1 ,high); /// 对右半部分归并排序
        Merge(A,low,mid,high); /// 归并
    }
}