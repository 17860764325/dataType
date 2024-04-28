//
// Created by lihaoran on 2024-04-22.
//

#include "../../headSpace/dataTypeWork/二叉树的叶子结点链接到一起左到右.h"
#include "../../headSpace/dataTypeWork/二叉树的叶子结点链接到一起左到右.h"
LNode *head = (LNode *)malloc(sizeof(LNode));
LNode *item = head;

// 实现后插操作，在某一个节点后插入一个
bool InsertNextNode(LNode *p, int e ){
    if (p == NULL) {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) {
        return false;// 内存不足
    }
    s->data = e; // 保存e数据
    s->next = p->next;
    p->next = s; // 将节点s保存到p节点后
    return true;
}

void 二叉树的叶子结点链接到一起左到右::fun(BSTree T) {
    if (T != NULL) {
        fun(T->lchild);
        fun(T->rchild);
        if (T->lchild == NULL && T->rchild == NULL) {
            InsertNextNode(item,T->key);
                item = item->next;
        }
    }
}



void createTree(BSTNode **T)  //传入一个Btree的指针的地址
{
    int data;
    scanf("%d", &data);

    if(data == -1) {    //-1代表终端节点值
        *T = NULL;
    } else {
        *T = (BSTNode *)malloc(sizeof(struct BSTNode));
        (*T)->key = data;
        printf("请输入%d的左孩子节点：", data);
        createTree(&((*T)->lchild));
        printf("请输入%d的右孩子节点：", data);
        createTree(&((*T)->rchild));
    }
}

int main() {
    head->data = 0;
    二叉树的叶子结点链接到一起左到右 a;
    BSTNode *T = (BSTNode *) malloc(sizeof(LNode));
    T->key = 1;
    createTree(&T);
    a.fun(T);

    LNode *test = head;
    while (test != NULL){
        cout<< test->data << endl;
        test = test->next;
    }
}
