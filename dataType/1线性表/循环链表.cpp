//
//  循环链表.cpp
//  dataType
//
//  Created by lihaoran on 2023/2/28.
//

#include <stdio.h>
#include <stdlib.h>

// 定义循环链表-->单链表
typedef struct LNode{
    int data;
    struct LNode * next;
}LNode  ,* LinkList;

//初始化一个循环链表
bool InitLinkList(LinkList &L){
    LNode *p = (LNode *)malloc(sizeof(LNode));
    if (p == NULL) {
        return false; //内存不足
    }
    L = p;
    p->next = L; // 头节点指向自己
    return true;
}

// 循环单链表判断是否为空
bool isEmpty(LinkList L){
    if (L->next == L) {
        return true;
    }
    return false;
}

// 判断p是不是L的最后一个节点
bool isEnd(LinkList L,LNode *p){
    if (p->next == L) {
        return true;
    }
    return false;
}

// 初始化循环双链表
typedef struct DNode{
    int data;
    struct DNode * prior;
    struct DNode * next;
}DNode,*DLinkList;

// 初始化循环双链表
bool DLinkListInsert(DLinkList &L){
    L = (DNode *)malloc(sizeof(LNode));
    if (L==NULL) {
        return false;
    }
    L -> next = L;
    L -> prior = L;
    return true;
}

// 循环双链表判空操作
bool Empty(DLinkList L){
    if(L -> next == L)//👈是否指向链表自身
        return true;
    else
        return false;
}

//在p结点之后插入s结点
bool InsertNextDNode(DNode *p, DNode *s){
    s -> next = p -> next;    //将结点*s插入到结点*pzhiho
    p -> next -> prior = s;    //👈,在双链表中出现错误；但是在循环双链表中不会出现错误
    s -> prior = p;
    p -> next = s;
    return true;
}

//删除p的后继结点q
bool DeleteNextDNode(DNode *p, DNode *q){
    p -> next = q -> next;
    q -> next -> prior = p;//👈,在双链表中出现错误；但是在循环双链表中不会出现错误
    free(q);
    return true;
}





