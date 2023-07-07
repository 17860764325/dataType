//
// Created by lihaoran on 7/7/23.
//

#include <stdio.h>
#include <stdlib.h>
// 二叉树队列的节点，链式存储
typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 链队列的结点
typedef struct LinkNode {
    BiTree * data; // 存储的是指针，这样大大减小空间的占用
    struct LinkNode *next;
} LinkNode;
// 初始化队列
void InitQueue(LinkNode *&Q) {
    Q = (LinkNode *) malloc(sizeof(LinkNode));
    Q->next = NULL;
}

// 判断队列是否为空
bool QueueEmpty(LinkNode *Q) {
    return Q->next == NULL;
}

// 入队操作
void EnQueue(LinkNode *&Q, BiTree e) {
    LinkNode *p = (LinkNode *) malloc(sizeof(LinkNode));
    p->data = e;
    p->next = NULL;
    // 尾插法
    LinkNode *last = Q;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = p;
}

// 出队操作
bool DeQueue(LinkNode *&Q, BiTree &e) {
    if (Q->next == NULL) {
        return false;
    }
    LinkNode *p = Q->next;
    e = p->data;
    Q->next = p->next;
    free(p);
    return true;
}


// 层序遍历
void LevelOrder(BiTree T) {
    // 定义一个队列
    LinkNode *Q;
    // 初始化队列
    InitQueue(Q);
    // 根节点入队
    EnQueue(Q, T);
    // 队列不为空
    while (!QueueEmpty(Q)) {
        // 取出队头元素
        BiTree p;
        DeQueue(Q, p);
        // 访问队头元素
        printf("%d", p->data);
        // 如果左子树不为空，左子树入队
        if (p->lchild != NULL) {
            EnQueue(Q, p->lchild);
        }
        // 如果右子树不为空，右子树入队
        if (p->rchild != NULL) {
            EnQueue(Q, p->rchild);
        }
    }
}


