//
// Created by lihaoran on 2024/1/8.
//

#include "../../headSpace/dataTypeWork/普通树的遍历.h"
#include "iostream"
#include "stdio.h"
using namespace std;

//树 (孩子兄弟表示法)
typedef struct CSNode {
  string node;
  int flag; // 判断是否被访问过
  struct CSNode *firstNode,*nextNode; // 第一个孩子节点 和 右兄弟指针
} CSNode,*CSTree;

// 通用访问方法
void visit(CSNode *T) {
  if (T != NULL) {
    cout << T->node << endl;
  }
}

/// 树的先根遍历--传入根节点
void pre(CSNode *T) {
    if(T == NULL)
      return;

    visit(T);
    pre(T->firstNode);
    pre(T->nextNode);
}

/// 树的后根遍历
/// 树的先根遍历--传入根节点
void pos(CSNode *T) {
    if(T == NULL)
      return;
    pos(T->firstNode);
    visit(T);
    pos(T->nextNode);
}


void 普通树遍历::putogshudebianli() {
    CSNode a;
    CSNode b;
    CSNode c;
    CSNode d;
    CSNode e;
    CSNode f;

    a.node = "A";
    a.firstNode = &b;
    a.nextNode = NULL;
    a.flag = 0;
    b.node = "B";
    b.firstNode = &e;
    b.nextNode = &c;
    b.flag = 0;
    c.node = "C";
    c.firstNode = NULL;
    c.nextNode = &d;
    c.flag = 0;
    d.node = "D";
    d.firstNode = NULL;
    d.nextNode = NULL;
    d.flag = 0;
    e.node = "E";
    e.firstNode = NULL;
    e.nextNode = &f;
    e.flag = 0;
    f.node = "F";
    f.firstNode = NULL;
    f.nextNode = NULL;
    f.flag = 0;

    pre(&a);
    cout << "--------------------\n"<< endl;
    pos(&a);
}