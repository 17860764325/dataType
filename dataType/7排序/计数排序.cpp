//
// Created by lihaoran on 2024/2/13.
//

#include "dataTypeWork/计数排序.h"

void 计数排序::CountSort(int *A, int *B, int n, int k) {
    int i,C[k];
    for ( i = 0; i < k ; i++) {
        C[i] = 0; /// 初始化计数数组
    }
    for (i = 0; i < n ; i++) { /// 遍历输入数组，统计每个元素出现的次数
        C[A[i]]++; /// C[A[i]] 保存的是等于A[i]的元素个数
    }
    for (i = 0; i < k ; i++) {
        C[i] = C[i] + C[i-1];/// C[x] 里面保存的是小于护着等于x的元素个数
    }
    for ( i = n - 1 ; i >= 0  ; i--) {
        B[C[A[i]]-1] = A[i];/// 将元素A[i] 放在输出数组B[]的正确位置上
        C[A[i]] -= 1; /// 放置过的就要减去一次
    }
}
