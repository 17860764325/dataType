//
// Created by lihaoran on 2024/2/7.
//

#include "dataTypeWork/简单选择排序.h"

void 简单选择排序::SelectSort(int A[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < n; j++) {    /// 选择除了排序好的子式意外的最小的一个
            if (A[j] < A[min]) {
                min = j;
            }
            if (min != i) swap(A[i], A[min]);
        }
    }
}