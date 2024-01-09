//
// Created by lihaoran on 2024/1/3.
//

#ifndef DATATYPE_THREADNODE_H
#define DATATYPE_THREADNODE_H
#include "string"
using namespace  std;

typedef struct ThreadNode {
  int data;
  struct ThreadNode *lchild, *rchild;
  // 标志位，0 表示左孩子，1 表示前驱
  int ltag, rtag;
} ThreadNode, *ThreadTree;


typedef int ElemType;
/// 孩子兄弟存储结构
typedef struct CSNode {
  string node;
  int flag; // 判断是否被访问过
  struct CSNode *firstNode,*nextNode; // 第一个孩子节点 和 右兄弟指针
} CSNode,*CSTree;

#endif // DATATYPE_THREADNODE_H
