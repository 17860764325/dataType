#include "stdio.h"
#include "stdlib.h"

typedef int ElemType;
typedef struct LNode{
   ElemType data;           //数据域
   struct LNode *next;      //指针域
}LNode,*LinkList;

/*
 * 头插法 有头结点
 */
LinkList HeadInster(LinkList &L,int n){
    LNode *s;
    int x=1;
    L= (LinkList)malloc(sizeof(LNode));     //创建头结点
    L->next=NULL;                                //初始为空链表
    while(x!=n){
        s=(LNode*) malloc(sizeof(LNode));   //创建新结点
        s->data=x;
        s->next=L->next;
        L->next=s;
        x++;
    }
    return L;
}

/*
 * 头插法 没有头结点
 */
LinkList Headinster(LinkList &L,int n){
    LNode *s;
    int x=1;
    L= (LinkList)malloc(sizeof(LNode));
    L->data=x++;
    L->next=NULL;
    while(x!=n){
        s=(LNode*) malloc(sizeof(LNode));
        s->data=x;
        s->next=L;
        L=s;
        x++;
    }
    return L;
}

/*
 * 尾插法、有结点
 */
LinkList TailInster(LinkList &L,int n){
    int x=1;
    L= (LinkList)malloc(sizeof(LNode));
    LNode *s,*r=L;
    while(x!=n){
        s=(LNode*) malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;
        x++;
    }
    r->next=NULL;
    return L;
}
/*
 * 尾插法、没有结点
 */
LinkList Tailinster(LinkList &L,int n){
    int x=1;
    L= (LinkList)malloc(sizeof(LNode));
    L->data=x++;
    LNode *s,*r=L;
    while(x!=n){
        s=(LNode*) malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;
        x++;
    }
    r->next=NULL;
    return L;
}


/*
 * 便利链表、头结点
 */
void PrintList(LinkList L){
    LNode *s;
    s=L->next;
    while (s!=NULL) {
        printf("%d\t",s->data);
        s=s->next;
    }
}

/*
 * 便利链表
 */
void Print(LinkList L){
    LNode *s;
    s=L;
    while (s!=NULL) {
        printf("%d\t",s->data);
        s=s->next;
    }
}

//int main(){
//    LinkList L,S,P,Q;
//    printf("有头结点的头插法：");
//    HeadInster(L,10);
//    PrintList(L);
//
//    printf("\n无头结点的头插法：");
//    Headinster(P,10);
//    Print(P);
//
//    printf("\n有头结点的尾插法：");
//    Tailinster(S,10);
//    Print(S);
//
//    printf("\n无头结点的尾插法：");
//    Tailinster(Q,10);
//    Print(Q);
//
//}
