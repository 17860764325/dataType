//
// Created by lihaoran on 2024/1/3.
//

#ifndef DATATYPE_THREADNODE_H
#define DATATYPE_THREADNODE_H

typedef struct ThreadNode {
  int data;
  struct ThreadNode *lchild, *rchild;
  // 标志位，0 表示左孩子，1 表示前驱
  int ltag, rtag;
} ThreadNode, *ThreadTree;

#endif // DATATYPE_THREADNODE_H
