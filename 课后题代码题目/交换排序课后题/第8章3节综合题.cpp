//
// Created by lihaoran on 2024/2/6.
//

#include "../../headSpace/dataTypeWork/第8章3节综合题1.h"

/// 将一个序列的所有奇数放在偶数前边
void 第8章3节综合题::move(int A[], int len) {
    /// 对表A按奇偶进行一趟划分
    int i = 0,j = len -1;  ///  i表示左边偶数元素的下标，j表示右端奇数元素的下标
    while(i < j){
        while(i < j && A[i]%2!=0) i++;/// 从前往后找一个偶数元素
        while(i < j && A[j]%2!=1) j--;/// 从后往前找一个奇数元素
        if (i < j){
            swap(A[i],A[j]);
            i ++; j--;
        }
    }
}


/// 找寻第k小的元素
int 第8章3节综合题::kth_elem(int *A, int low, int high, int k) {
    int pivot = A[low];
    int low_temp = low;
    int high_temp = high;
    while (low < high){
        while(low < high && A[high] >= pivot) -- high;
        A[low] = A[high];
        while (low < high && A[low] <= pivot) ++low;
        A[high] = A[low];
    }
    A[low] = pivot;

    if (low = k){
        return A[low];
    }else if(low > k){
        return kth_elem(A[],low_temp,low -1,k);
    }else {
        return kth_elem(A,low+1,high_temp,k);
    }
}


/// 红蓝白 ，荷兰国旗 ，一个序列乱序存储着红蓝白三种颜色，现在需要，按照红蓝白将三种颜色分开排序
void 第8章3节综合题::Flag_Arrange(color A[],int n ){
    int i =0,j = 0,k = n-1;
    while (j <= k){
        switch (A[j]) {
            case RED:
                swap(A[i],A[j]); /// 红色 和i交换
                i++;
                j++;
            case WHITE:
                j ++ ; /// 白色不动
                break;
            case BLUE:
                swap(A[j],A[k]);
                k --; /// 蓝色，则和k交换
                /// 这里没有j++语句用来放置急哦啊还后A[j]仍为蓝色。
        }
    }
}


/// 2016统考真题：
/*
 * 已经知道 n(n >= 2) 个正整数构成的集合A = { ak | 0 <= k < n } ，
 * 将其划分为两个不相交的子集A1和A2 元素个数分别是n1和n2，A1和A2中的元素之和分贝斯S1和S2
 * 设计一个尽可高效划分的算法，满足 ｜n1-n2｜最小且|S1-S2|最大。
 */
int 第8章3节综合题::setPartition(int *a, int n) {
    int pivotKey,low = 0,low0 = 0,high = n-1,high0 = n-1,flag = 1,k = n/2,i;
    int s1 = 0,s2 = 0;
    while(flag){
        pivotKey = a [low];
        while (low < high){
            while (low < high && a[high] >= pivotKey) --high;
            if (low != high) a[low] = a[high];
            while (low < high && a[low] <= pivotKey) ++low;
            if (low!=high) a[high] = a[low];
        }
        a[low] = pivotKey;
        if(low == k-1)
            flag = 0;
        else {
            if (low <k-1){
                low0 = ++low;
                high=high0;
            }else {
                high0 = --high;
                low = low0;
            }
        }
    }
    for ( i = 0; i <k ; ++i) s1 +=a[i];
    for ( i = k; i <n ; ++i) s2 +=a[i];
    return s2-s1;
}