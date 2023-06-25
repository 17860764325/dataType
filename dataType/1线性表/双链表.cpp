//
//  双链表.cpp
//  dataType
//
//  Created by lihaoran on 2023/2/28.
//

#include <stdio.h>
#include <stdlib.h>

// 声明一个双链表
typedef struct DNode{
    int data;
    struct DNode *prior,*next;
}Dnode,*DLinkList;

// 初始化单链表
bool InitdLinkList(DLinkList &L){
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL) {
        return false;
    }
    L -> prior = NULL; // 双链表的头节点的前指针永远指向NULL
    L -> next = NULL; // 头节点之后还没有确定节点
    return true;
}

// 双链表判空操作
bool Isempty(DLinkList L){
    if (L -> next == NULL)
        return true;
    return false;
}

// 双链表插入操作
// 在某个节点后插入一个节点 p 后 插入 s
bool InsertNextNode(DNode *p,DNode *s){
    if (p == NULL || s== NULL) {
        return false;
    }
    s->next = p->next;
    if (p->next != NULL) {
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
    return true;
}

// 双链表删除操作
// 删除p的后边的节点
bool DeleteNextnode(DNode *p){
    if (p == NULL) {
        return false;
    }
    Dnode *s = p->next;
    if (s == NULL) {
        return false;
    }
    p->next = s->next;
    if (s -> next != NULL) {
        s->next->prior = p;
    }
    free(s);
    return true;
}

// 双链表销毁操作
bool DestoryDLinkList(DLinkList &L){
    while (L->next != NULL)
        DeleteNextnode(L);
    free(L);
    return true;
}

// 双链表的遍历
void DLinkListPrint(DLinkList L){
    Dnode *p = L->next;
    // 向后遍历
    while (p!=NULL){
        // 操作
        printf("%d\n",p->data);
        p = p->next;
    }
//    // 向前遍历
//    while(p!=NULL)
//        // 操作
//        p= p->prior;
//    // 向前遍历，跳过头节点
//    while (p->prior != NULL) {
//        // 操作
//        p = p-> prior;
//    }
}


void testDLinkLsit(){
    DLinkList L;
    InitdLinkList(L);
    DNode *p = (Dnode *)malloc(sizeof(DNode));
    p->data = 1;
    InsertNextNode(L,p);
    DLinkListPrint(L);
    
}
//int main(){
//    testDLinkLsit();
//}
