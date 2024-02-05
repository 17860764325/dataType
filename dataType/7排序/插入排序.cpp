//
// Created by lihaoran on 2024/2/4.
//

#include "dataTypeWork/插入排序.h"

void printArray(ElemType A[]){
    A[0] =0;
    for (int i = 0; i < 9; ++i) {
        cout << A[i] << endl;
    }
};


void createTestData(ElemType A[],int n){
    srand((unsigned int)time(0));//修改种子
    for (int i = 0; i < n; ++i) {
        A[i]= rand() % (100 - 1+1) + 1;
    }
}

void 插入排序::InsertSort(ElemType A[], int n) {
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
void 插入排序::InsertSortWithOut(ElemType A[], int n) {
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
void 插入排序::InsertSortMoreBatter(ElemType A[], int n) {
    int i, j, low, high, mid;
    for (i = 2; i < n; ++i) {
        A[0] = A[i];
        low = 1;
        high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (A[mid] > A[0]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        for (j = j - 1; j >= high + 1; --j) {
            A[j + 1] = A[j];
        }
        A[high + 1] = A[0];
    }
}

/// 希尔排序 子表交替进行步进排序
void 插入排序::ShellSort(ElemType A[], int n) {
    int d, i, j;
    for (d = n / 2; d >= 1; d /= 2) {/// 步长变化
        cout<<" "<<endl;
        cout<<"增量="<<d<<endl;
        for (i = d + 1; i <= n; ++i) {
            cout<< i<<' ';
            if (A[i] < A[i - d]) { /// 将A[i]插入有序增量子表
                A[0] = A[i]; /// 暂存在A[0]
                for (j = i - d; j > 0 && A[0] < A[j]; j -= d) {
                    A[j + d] = A[j]; /// 记录后移，查找插入的位置
                }
                A[j + d] = A[0]; /// 插入
            }
        }
    }
    cout<<" "<<endl;
    cout<<"最终排序:"<<endl;
    printArray(A);
}

/// 希尔排序 子表单独进行步进排序
void 插入排序::ShellSortA(ElemType A[], int n) {
    int d, i, j,k;
    for (d = n / 2; d >= 1; d /= 2) {/// 步长变化
        cout<<" "<<endl;
        cout<<"增量="<<d<<endl;
        for ( k = 1; k < d; ++k) {
            cout<<" "<<endl;
            cout<<"子集="<<k<<endl;
            for (i = d + k; i <= n; i += d) {
                cout<< i<<' ';
                if (A[i] < A[i - d]) {/// 将A[i]插入有序增量子表
                    A[0] = A[i];      /// 暂存在A[0]
                    for (j = i - d; j > 0 && A[0] < A[j]; j -= d) {
                        A[j + d] = A[j];/// 记录后移，查找插入的位置
                    }
                    A[j + d] = A[0];/// 插入
                }
            }
        }
    }
    cout<<" "<<endl;
    cout<<"最终排序:"<<endl;
    printArray(A);

}



void 插入排序::test(){
    ElemType A[9];
    createTestData(A,9);
    ShellSort(A,9);
    cout << "-----" << endl;
    ShellSortA(A,9);

}
