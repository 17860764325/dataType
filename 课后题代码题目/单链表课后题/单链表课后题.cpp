//
// Created by lihaoran on 2024/3/7.
//

#include "dataTypeWork/单链表课后题.h"
void 单链表课后题::title1(LinkList &L, ElemType x) {
    LNode *p  = L->next,* pre = L,*q; // 给p和pre赋值初始值
    while (p!= NULL){
        if (p -> data ==x){
            q = p;
            p = p->next;
            pre ->next = p;
            free(q);
        }else {
            pre = p;
            p = p->next;
        }
    }
}

LinkList 单链表课后题::title2(LinkList &l) {
    LNode *pre = l,*p=pre->next;
    LNode *minpre = pre,*min = p;
    while(p!=NULL){
        if (p->data < min->data){
            min = p;
            minpre = pre;
        }
        pre = p;
        p = p ->next;
    }
    minpre->next = min -> next;
    free(min);
    return l;
}

