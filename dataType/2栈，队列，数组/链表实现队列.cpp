//
//  链表实现队列.cpp
//  dataType
//
//  Created by lihaoran on 2023/3/9.
//

#include <stdio.h>
#include <stdlib.h>

typedef  struct LinkNode{ // 链式队列节点
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct { // 链式队列
    LinkNode *front,*rear; // 队列的头指针和尾指针
}LinkQueue;

// 带头节点进行初始化
void InitQueueHead(LinkQueue &Q){
    // 初始化 front ,rear 都指向头节点
    Q.rear = Q.front = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front -> next = NULL;
}
// 带头节点判空
bool IsEmptyHead(LinkQueue Q){
    if (Q.front == Q.rear) {
        return true;
    }else if(Q.front->next == NULL){
        return true;
    }
    return false;
}
// 不带头节点初始化
void InitQueue(LinkQueue &Q){
    Q.rear = NULL;
    Q.front = NULL;
}

// 不带头节点判空
bool IsEmpty(LinkQueue Q){
    if (Q.front== NULL) {
        return true;
    }
    return false ;
}

// 带头节点入队
void EnQueueHead(LinkQueue &Q,int x){
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s; // 新节点插入到原rear后边
    Q.rear = s; // 将rear执行新的最后一个节点
}

// 不带头节点入队
void EnQueue(LinkQueue &Q,int x){
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s -> data = x;
    s->next=NULL;
    if (Q.front == NULL) {
        Q.front = s;
        Q.rear = s;
    }else{
        Q.rear->next = s;
        Q.rear = s;
    }
}

// 出队操作带头节点
bool DeQueueHead(LinkQueue &Q,int &x){
    // 进行判空
    if (Q.front->next == NULL) {
        return false ;
    }
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    // 判断如果删除到最后一个元素，那么就需要让尾部的指针和头部指向一个节点
    if (Q.rear == p) {
        Q.rear = Q.front;
    }
    free(p);
    return true;
}

// 出队操作不带头节点
bool DeQueue(LinkQueue &Q,int &x){
    // 进行判空
    if (Q.front == NULL) {
        return false ;
    }
    LinkNode *p = Q.front;
    x = p->data;
    Q.front = p->next;
    // 判断如果删除到最后一个元素，那么就需要让尾部的指针和头部指向一个节点
    if (Q.rear == p) {
        Q.rear = NULL;
        Q.front = NULL;
    }
    free(p);
    return true;
}

/*
 如何统计队列长度？
 1. 从队头指针循环到队尾指针，时间复杂度O(n)
 2. 在链队列的里面加一个变量size用来存储长度，进队就++出队就--
 */
