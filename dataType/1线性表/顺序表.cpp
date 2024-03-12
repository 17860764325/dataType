//
// Created by lihaoran on 2023/2/21.
//
#include <stdio.h>
#include <stdlib.h>

// 定义静态顺序表
#define MaxSize 10
typedef struct {
    int data[MaxSize];
    int length;
} SqeList;

typedef SqeList ele;

typedef struct {
    ele list[MaxSize];
    int length;
}abc;

/// 动态初始化
typedef struct {
    int *data;
    int length, MaxSizeDy;
} SqeListDy;

// 数组初始化
void InitList(SqeList &L) {
    for (int i = 0; i < L.length; i++) {
        L.data[i] = 0;
    }
    L.length = 0;

    abc a;
    a.list[5].data[4];
}
// 动态顺序表初始化
void InitListDy(SqeListDy &l, int initSize) {
    l.data = (int *) malloc(MaxSize * sizeof(int));// 初始化相应的空间
    l.length = 0;
    l.MaxSizeDy = initSize;
}
// 顺序表插入
bool ListInsert(SqeList &L, int i, int e) {
    /// 判断是否在相应的范围内
    if (i < 1 || i > L.length + 1) {
        return false;
    }
    /// 是否已经满了
    if (L.length == MaxSize) {
        return false;
    }
    /// 进行插入操作
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j + 1];
    }
    L.data[i - 1] = e;
    /// 增加长度
    L.length++;
    /// 返回插入成功
    return true;
}

// 顺序表删除
bool ListDelete(SqeList &L, int i, int &e) {
    /// 判断删除的位置是否在相应的范围内
    if (i < 1 || i > L.length)
        return false;
    /// 将要删除的值进行记录
    e = L.data[i - 1];
    /// 移动元素进行删除
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    /// 长度减少
    L.length--;
    /// 返回成功
    return true;
}

//int main() {
//    SqeList L;
//    InitList(L);
//    ListInsert(L, 1, 1);
//    ListInsert(L, 2, 2);
//    ListInsert(L, 3, 3);
//    ListInsert(L, 4, 4);
//    ListInsert(L, 5, 5);
//    ListInsert(L, 6, 6);
//    ListInsert(L, 7, 7);
//    ListInsert(L, 8, 8);
//    for (int i = 0; i < L.length; i++) {
//        printf("data[%d]=%d\n",i,L.data[i]);
//    }
//    return 0;
//}
