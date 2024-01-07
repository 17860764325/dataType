//
// Created by lihaoran on 2024/1/3.
//
/*
 * 中序二叉树找中序后继
 */

#include <stdio.h>

// 引入节点
#include "ThreadNode.h"

// ========================================== 中序 ==========================================

// ============================== 找后继（右孩子的最左节点） ==============================

//找到以 p 为根的子树中，第一个被中序遍历的节点
ThreadNode *Firstnode(ThreadNode *p){
  // 循环找到最左下的节点（不一定是叶子节点）
  while(p->ltag == 0) p = p->lchild;
  // 找到后将 p 返回
  return p;
}

// 在中序二叉树中找到节点 p 的后继节点
ThreadNode *Nextnode(ThreadNode *p){
  // 右子树中最左下的节点
  if(p->rtag == 0 ) return Firstnode(p->rchild);
  // 如果 rtag 为 1 直接返回后继节点
  else return p->rchild;
}

// 对中序线索二叉树进行中遍历（利用线索实现非递归算法调用，空间复杂度 O(1)）
void Inorder(ThreadNode *T){
  // 中序循环后继
  for (ThreadNode *p = Firstnode(T); p!=NULL; p = Nextnode(p)) {
    // 节点打印。。。。
  }
}


// ============================== 找前驱（左孩子的最右节点） ============================== 同理只不过是将找后继给反过来

//找到以 p 为根的子树中，第一个被中序遍历的节点
ThreadNode *Lastnode(ThreadNode *p){
  while(p->rtag == 0) p = p->rchild;
  return p;
}

// 在中序二叉树中找到节点 p 的后继节点
ThreadNode *Prenode(ThreadNode *p){
  if(p->ltag == 0 ) return Firstnode(p->lchild);
  else return p->lchild;
}

// 对中序线索二叉树进行中遍历（利用线索实现非递归算法调用，空间复杂度 O(1)）
void RevInorder(ThreadNode *T){
  for (ThreadNode *p = Firstnode(T); p!=NULL; p = Nextnode(p)) {
  }
}

// ========================================== 先序 ==========================================
// ============================== 找后继 ==============================
// 在先序二叉树中找到节点 p 的后继节点
ThreadNode *xianPrenode(ThreadNode *p){
  // 如果 ltag==0 证明有左孩子，则 p 节点的先序后继就是做左孩子
  // 其他的化就是右孩子
  if(p->ltag == 0 ) return p->lchild;
  else return p->rchild;
}
// ============================== 找前驱 ============================== 同理只不过是将找后继给反过来


// ========================================== 后序 ==========================================
// ============================== 找后继 ==============================
// ============================== 找前驱 ============================== 同理只不过是将找后继给反过来
ThreadNode *houPrenode(ThreadNode *p){
  // 如果 rtag==0 证明有左孩子，有右孩子根据左右根的顺序，则p 的后续前驱就是右孩子，如果没有右节点
  // 则 p 节点的左孩子就是p 的后序前驱
  if(p->rtag == 0 ) return p->rchild;
  else return p->lchild;
}


