//
// Created by lihaoran on 2024/2/5.
//

#include "dataTypeWork/冒泡排序.h"

/// 交换方法，每次交换，活进行三次位置移动
void 冒泡排序::swap1(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void 冒泡排序::BubbleSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool flag = false;
        for (int j = n - 1; j > i; j--) {
            if (A[j - 1] > A[j]) {
                swap1(A[j - 1], A[j]);
                flag = true;
            }
            if (!flag) {
                return;
            }
        }
    }
}