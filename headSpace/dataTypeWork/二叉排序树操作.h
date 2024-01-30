//
// Created by lihaoran on 2024/1/29.
//

#ifndef UNTITLED1_二叉排序树查找_H
#define UNTITLED1_二叉排序树查找_H


class 二叉排序树查找 {
private:
    typedef struct BSTNode{
        int key;
        struct BSTNode *lchild,*rchild;
    } BSTNode,*BSTree;
public:
    /// 普通查找方式
    BSTNode * BST_Search(BSTree T,int key);

    /// 递归查找方式
    BSTNode *BSTSearch(BSTree T,int key);

    /// 递归插入方式
    int BST_insert(BSTree &T,int k);

    /// 循环插入方式
    int BSTinsert(BSTree T,int k);

    /// 构造二叉树
    void Create_BST(BSTree &t, int str[],int n);
};


#endif//UNTITLED1_二叉排序树查找_H
