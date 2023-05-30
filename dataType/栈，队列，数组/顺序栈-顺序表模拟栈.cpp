//
//  顺序栈-顺序表模拟栈.cpp
//  dataType
//
//  Created by lihaoran on 2023/3/3.
//

#include <stdio.h>
#include <stdlib.h>

// 初始化一个顺序栈
#define MaxSize 10 // 定义栈中元素的最大个数
typedef struct {
    int data[MaxSize]; // 静态数组存放栈中元素
    int top; // 栈顶指针
} SqStack;

// 初始化栈
void InitStack(SqStack &S){
    S.top = -1; //初始化顶指针
    printf("初始化栈！");
    printf("\n");
}

// 判断栈是否为空
bool IsEmpty(SqStack S){
    if (S.top == -1) {
        printf("栈为空");
        printf("\n");
        return true;
    }
    printf("栈不为空");
    printf("\n");
    return false;
}

// 进栈操作
bool Push(SqStack &S,int x){
    printf("进栈操作%d:",x);
    printf("\n");
    if (S.top == MaxSize -1) {
        printf("栈满不能进栈了");
        printf("\n");
        return false; // 判断栈是否已满
    }
//    S.top += 1;
//    S.data[S.top] = x;
    S.data[++S.top] = x; // 先加加再取值
    return true;
}

// 出栈操作
// x是将删除的元素返回回去，S是要删除的栈
//bool Delete(SqStack &S,int &x){
//    // 看是否是栈底元素，如果已经到了栈底元素那就不能再删除了
//    if (S.top == -1) {
//        printf("栈为空不能出栈");
//        printf("\n");
//        return false ;// 到栈底了，不可以再进行删除了
//    }
////    x = S.data[S.top];
////    S.top -= S.top;
//    x = S.data[S.top--]; // 先取值再减减
//    printf("出栈操作:%d",x);
//    printf("\n");
//    return true;
//}

// 取值操作，获取栈顶元素‘
bool getTop(SqStack S,int &x){
    if (S.top == -1) {
        return false ;
    }
    x = S.data[S.top];
    printf("获取栈顶元素为：%d",x);
    printf("\n");
    return true;
}

//int  main(){
//    SqStack S;
//    InitStack(S);
//    IsEmpty(S);
//    Push(S,1);
//    Push(S,2);
//    Push(S,3);
//    for (int i = 0; i < S.top + 1; i++) {
//        printf("栈的第%d位是：%d",i+1,S.data[i]);
//        printf("\n");
//    }
//
//    IsEmpty(S);
//
//    
//    int h ;
//    getTop(S,h);
//
//
//    int x ;
//    Delete(S, x);
//    Delete(S, x);
//    Delete(S, x);
//    IsEmpty(S);
//
//}
