//
// Created by lihaoran on 2024/2/4.
//

#include "dataTypeWork/插入排序.h"

void 插入排序::InsertSort(ElemType *A, int n) {
    int i, j;
    for (i = 2; i <= n; i++) {                 /// 依次将 2 ～ n插入前面已排序序列
        if (A[i] < A[i - 1]) {                 /// 判断是否需要排序
            A[0] = A[i];                       /// 建立哨兵
            for (j = i - 1; A[0] < A[j]; --j) {/// 进行循环
                A[j + 1] = A[j];               /// 将小于的数值都向后移动
            }
            A[j + 1] = A[0];///  将空值进行赋值
        }
    }
}

/// 不带哨兵模式，和上个同理，
void 插入排序::InsertSortWithOut(ElemType *A, int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        if (A[i] < A[i - 1]) {
            temp = A[i];
            for (j = i - 1; j >= 0 && A[j] > temp; --j) {
                A[j + 1] = A[j];
            }
            A[j + 1] = temp;
        }
    }
}

/// 插入排序优化
void 插入排序::InsertSortMoreBatter(ElemType *A, int n) {
    int i,j,low,high,mid;
    for ( i = 2; i < n ; ++i) {
        A[0] = A[i];
        low = 1;
        high = i -1;
        while (low <= high){
            mid = (low + high)/2;
            if (A[mid]> A[0]){
                high = mid -1;
            }else {
                low = mid + 1;
            }
        }
        for ( j = j -1; j >=high + 1 ; --j) {
            A[j + 1] = A[j];
        }
        A[high + 1] = A[0];
    }
}