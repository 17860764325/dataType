//
// Created by lihaoran on 2024/1/9.
//

#include<stdio.h>
#include<stdlib.h>

#include "../../headSpace/dataTypeWork/树森林的遍历和转换至二叉树.h"

#define MAX 100

typedef char Elemtype;
//树 (孩子兄弟表示法)
typedef struct CSNode{

  Elemtype data;
  struct CSNode *firstchild;      //第一个孩子
  struct CSNode *nextsibling;     //下一个兄弟

}CSNode, *CSTree;


//二叉树 结构体
typedef struct BiNode{

  Elemtype data;
  struct BiNode *leftchild;       //左儿子
  struct BiNode *rightchild;      //右儿子

}BiNode, *BinaryTree;


//森林 结构体
typedef struct {

  CSTree ct[MAX];
  int n;   //树的个数

}forest, *Forest;



/*—————————————————————————————————————————————————————————————————————————————————————*/
//创建 树
CSTree Create_CSTree(){
  Elemtype data;
  CSTree T;
  scanf("%c", &data);                       //输入节点数据
  getchar();

  if(data == '#')        //输入 - 以停止创建子树
    return NULL;
  T = (CSTree)malloc(sizeof(CSNode));
  T->data = data;

  printf("输入 %c 的第一个孩子数据(#停止): ", data);  //递归创建
  T->firstchild = Create_CSTree();
  printf("输入 %c 的下一个兄弟数据(#停止): ", data);
  T->nextsibling = Create_CSTree();

  return T;
}



/*—————————————————————————————————————————————————————————————————————————————————————*/
//树 转化为 二叉树
BinaryTree CSTree_Transform_to_BinaryTree(CSTree ct){
  if(!ct) return NULL;

  BinaryTree T = (BinaryTree)malloc(sizeof(BiNode));
  T->data = ct->data;
  //相当于将left变为firstchild, 将right变为nextsibling 本质的形态没有改变
  T->leftchild = CSTree_Transform_to_BinaryTree(ct->firstchild);
  T->rightchild = CSTree_Transform_to_BinaryTree(ct->nextsibling);

  return T;
}


//二叉树 转化 为树
CSTree BinaryTree_Transform_to_CSTree(BinaryTree bt){
  if(!bt)	return NULL;

  CSTree T = (CSTree)malloc(sizeof(CSNode));
  T->data = bt->data;
  //相当于将firstchild变为left, 将nextsibling变为right 本质的形态没有改变
  T->firstchild = BinaryTree_Transform_to_CSTree(bt->leftchild);
  T->nextsibling = BinaryTree_Transform_to_CSTree(bt->rightchild);

  return T;
}


//森林 转化为 二叉树
BinaryTree Forest_Transform_to_BinaryTree(CSTree ct[], int low, int high){
  if(low > high)	return NULL;

  //每个树变成二叉树
  BinaryTree T = CSTree_Transform_to_BinaryTree(ct[low]);
  //通过rightchild连接每一个二叉树的根节点
  T->rightchild = Forest_Transform_to_BinaryTree(ct, low + 1, high);

  return T;
}


//二叉树 转化为 森林
Forest BinaryTree_Transform_to_Forest(BinaryTree bt){
  Forest F = (Forest)malloc(sizeof(forest));
  BinaryTree p = bt;
  BinaryTree q = NULL;

  int count = 0;
  while(p){
    q = p->rightchild;    //q指向要切断连接的下一个节点(即其右儿子)
    p->rightchild = NULL; //切断连接 形成单独的树

    F->ct[count++] = BinaryTree_Transform_to_CSTree(p);//二叉树 转化为 树存到森林中
    p = q;    //p指向下一个节点 重复操作
  }

  F->n = count; //记录森林中 树的个数
  return F;
}



/*—————————————————————————————————————————————————————————————————————————————————————*/
//前序 递归遍历二叉树
void BinaryTree_Show_Pre_Order(BinaryTree T){
  if(T == NULL)
    return;

  printf("%c ", T->data);
  BinaryTree_Show_Pre_Order(T->leftchild);
  BinaryTree_Show_Pre_Order(T->rightchild);
}


//中序 递归遍历二叉树
void BinaryTree_Show_Infix_Order(BinaryTree T){
  if(T == NULL)
    return;

  BinaryTree_Show_Infix_Order(T->leftchild);
  printf("%c ", T->data);
  BinaryTree_Show_Infix_Order(T->rightchild);
}


//后序 递归遍历二叉树
void BinaryTree_Show_Post_Order(BinaryTree T){
  if(T == NULL)
    return;

  BinaryTree_Show_Post_Order(T->leftchild);
  BinaryTree_Show_Post_Order(T->rightchild);
  printf("%c ", T->data);
}



/*—————————————————————————————————————————————————————————————————————————————————————*/
//树的先根遍历  (相当于将firstchild当做left, 将nextsibling当做right)
void CSTree_Show_Pre_Order(CSTree T){
  if(T == NULL)
    return;

  printf("%c ", T->data);
  CSTree_Show_Pre_Order(T->firstchild);
  CSTree_Show_Pre_Order(T->nextsibling);
}


//树的后根遍历 写法和二叉树的中序遍历一样(相当于将firstchild当做left, 将nextsibling当做right)
void CSTree_Show_Post_Order(CSTree T){
  if(T == NULL)
    return;

  CSTree_Show_Post_Order(T->firstchild);
  printf("%c ", T->data);
  CSTree_Show_Post_Order(T->nextsibling);
}



/*—————————————————————————————————————————————————————————————————————————————————————*/
//森林的先序遍历
void Forest_Show_Pre_Order(Forest F){
  for(int i = 0; i < F->n; i++)
    CSTree_Show_Pre_Order(F->ct[i]);
}


//森林的中序遍历
void Forest_Show_Post_Order(Forest F){
  for(int i = 0; i < F->n; i++)
    CSTree_Show_Post_Order(F->ct[i]);
}



/*—————————————————————————————————————————————————————————————————————————————————————*/
void  树森林的遍历和转换至二叉树::test(){
  CSTree F[3];
  for(int i = 0; i < 3; i++){
    printf("创建第 %d 棵树 输入根节点(注意根节点无兄弟):\n", i + 1);
    F[i] = Create_CSTree();
    printf("\n");
  }

  printf("第一棵普通树后根遍历: \n");
  CSTree_Show_Post_Order(F[0]);
  printf("\n");

  printf("第二棵普通树先根遍历: \n");
  CSTree_Show_Pre_Order(F[1]);
  printf("\n");

  printf("三棵树组成的森林转化为二叉树之后中序遍历: \n");
  //如果是一个Forset结构体指针F  Foresr_Transform_to_BinaryTree(F->ct, 0, (F->n) - 1)
  BinaryTree bt = Forest_Transform_to_BinaryTree(F, 0, 2);
  BinaryTree_Show_Infix_Order(bt);
  printf("\n");

  printf("二叉树再次转换为森林之后先根遍历: \n");
  Forest backF = BinaryTree_Transform_to_Forest(bt);
  Forest_Show_Pre_Order(backF);
  printf("\n");
}
