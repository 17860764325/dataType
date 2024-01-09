//
// Created by lihaoran on 2024/1/8.
//

#include <iostream>
typedef int ElemType;
/// 数组长度
#define  MAX_TREE_SIZE 100

/// 双亲表示法：顺序存储
// 每个元素
typedef struct{
  // 父节点的下标识
  int parent;
  // 节点本身值
  ElemType data;
} PTNode;

/// 整个线性表
typedef struct {
  PTNode node[MAX_TREE_SIZE];
  int length;
} PTree;


/// 孩子表示法（顺序 + 链式存储）
// 定义第一个孩子节点存储类型
 struct FirstNode {
  ElemType node;
  struct FirstNode *next; // 下一个孩子
}FirstNode;

// 定义一个线性表的每个节点
typedef struct {
  ElemType node;
  struct FirstNode *FirstChild; // 第一个孩子
} NBox;

// 定义整个线性表
typedef struct {
    NBox all[MAX_TREE_SIZE];
    int n,r; // 节点数和根的位置
};

/// 孩子兄弟表示法（链表存储结构）
typedef struct CSNode {
    ElemType node;
    struct CSNode *firstNode,*nextNode; // 第一个孩子节点 和 右兄弟指针
} CSNode,*CSTree;
