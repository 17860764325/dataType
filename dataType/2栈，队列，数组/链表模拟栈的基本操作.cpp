//
//  链表模拟栈的基本操作.cpp
//  dataType
//
//  Created by lihaoran on 2023/3/6.
//

#include <stdio.h>
#include <stdlib.h>

// 初始化一个链栈
typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode, *LStack;

// 初始化一个链栈 不带头节点
bool Init(LStack &L){
    printf("初始化不带头节点\n");
    L = NULL;
    return true;
}

// 初始化一个链栈 带头节点
bool InitWithHead(LStack &L){
    printf("初始化带头节点\n");
    L = (LStack)malloc(sizeof(LStack));
    L->next = NULL;
    return true;
}

// 判断是否为空 ,判断链表是否为空---不带头节点
bool isEmpty(LStack L){
    if (L == NULL) {
        printf("不带头节点栈为空\n");
        return true;
    }
    printf("不带头节点栈不为空\n");
    return false ;
}

// 判断是否为空 ,判断链表是否为空---带头节点
bool isEmptyHead(LStack L){
    if (L -> next == NULL) {
        printf("带头节点栈为空\n");
        return true;
    }
    printf("带头节点栈不为空\n");
    return false ;
}

// 进栈操作--不带头节点
bool Push(LStack &L,int x){
    printf("不带头节点进栈操作：%d\n",x);
    LStack p = (LinkNode *)malloc(sizeof(LinkNode));
    p->data = x;
    p->next = L;
    L  = p;
    return true;
}

// 进栈操作--带头节点
bool PushHead(LStack &L,int x){
    printf("带头节点进栈操作：%d\n",x);
    LStack p = (LinkNode *)malloc(sizeof(LinkNode));
    p->data = x;
    p->next = L->next;
    L ->next = p;
    return true;
}

// 出栈操作--不带头节点
bool Pop(LStack &L,int &x){
    if (L == NULL) {
        return false;
    }
    x = L->data;
    printf("不带头节点出栈操作：%d\n",x);
    L = L->next;
    return true;
}

// 出栈操作--带头节点
bool PopHead(LStack &L,int &x){
    if (L->next == NULL) {
        return false ;
    }
    x = L->next->data;
    printf("带头节点出栈操作：%d\n",x);
    L->next  = L->next->next;
    return true;
}

// 带头节点打印
void printNodeHead(LStack L){
    printf("带头节点打印\n");
    LinkNode * p =L->next;
    while (p != NULL) {
        printf("%d\n",p->data);
        p = p->next;
    }
}
// 不带头节点打印
void printNode(LStack L){
    printf("不带头节点打印\n");
    LinkNode * p =L;
    while (p != NULL) {
        printf("%d\n",p->data);
        p= p->next;
    }
}

// 带头节点获取栈顶元素
bool getTopHead(LStack L,int &x){
    if (L->next == NULL) {
        return false;
    }
    x = L->next->data;
    printf("不带头节点，栈顶元素：%d\n",x);
    return true;
}
// 不带头节点获取栈顶元素
bool getTop(LStack L,int &x){
    if (L == NULL) {
        return false;
    }
    x = L->data;
    printf("不带头节点，栈顶元素：%d\n",x);
    return true;
}


// 不带头节点获取栈顶元素

void head(){
    LStack L;
    InitWithHead(L);
    isEmptyHead(L);
    PushHead(L, 1);
    printNodeHead(L);
    PushHead(L, 2);
    printNodeHead(L);
    PushHead(L, 3);
    printNodeHead(L);
    isEmptyHead(L);
    int x ;
    getTopHead(L, x);
    PopHead(L, x);
    printNodeHead(L);
    PopHead(L, x);
    printNodeHead(L);
    PopHead(L, x);
    printNodeHead(L);
    isEmptyHead(L);
}
void withoutHead(){
    LStack L;
    Init(L);
    isEmpty(L);
    Push(L, 1);
    printNode(L);
    Push(L, 2);
    printNode(L);
    Push(L, 3);
    printNode(L);
    isEmpty(L);
    int x ;
    getTop(L, x);
    Pop(L, x);
    printNode(L);
    Pop(L, x);
    printNode(L);
    Pop(L, x);
    printNode(L);
    isEmpty(L);
}
//
//int  main(){
//
//    withoutHead();
//}




