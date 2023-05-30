//
// Created by lihaoran on 2023/2/21.
//
#include <stdio.h>

// 定义静态顺序表
#define MaxSize 10
typedef struct {
    int data[MaxSize];
    int length;
} SqeList;


// 数组初始化
void InitList(SqeList &L) {
    for (int i = 0; i < L.length; i++) {
        L.data[i] = 0;
    }
    L.length = 0;
}

// 顺序表插入
bool ListInsert(SqeList &L, int i, int e) {
    if (i < 1 || i > L.length + 1) {
        return false;
    }
    if (L.length == MaxSize) {
        return false;
    }
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j + 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

// 顺序表删除
bool ListDelete(SqeList &L, int i, int &e) {
    if (i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;

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
