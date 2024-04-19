//
// Created by lihaoran on 2024/1/29.
//

#include "../../headSpace/dataTypeWork/二叉排序树操作.h"
#include "stdio.h"
#include "stdlib.h"

/// 普通查找方式  空间复杂度O(1)
二叉排序树查找::BSTNode *二叉排序树查找::BST_Search(二叉排序树查找::BSTree T, int key) {
    while (T != NULL && key != T->key) {
        if (key < T->key) {
            T = T->lchild;
        } else {
            T = T->rchild;
        }
    }
    return T;
}

/// 递归查找方式 空间复杂度O(h)
二叉排序树查找::BSTNode *二叉排序树查找::BSTSearch(二叉排序树查找::BSTree T, int key) {
    if (T == NULL) {
        return NULL;
    }
    if (key == T->key) {
        return T;
    } else if (key > T->key) {
        BSTSearch(T->rchild, key);
    } else {
        BSTSearch(T->lchild, key);
    }
}

/// 递归方式实现插入
int 二叉排序树查找::BST_insert(二叉排序树查找::BSTree &T, int k) {
    if (T == NULL) {
        T = (BSTree) malloc(sizeof(BSTNode));
        T->key = k;
        T->lchild = T->rchild = NULL;
        return 1;
    } else if (k == T->key) {
        return 0;
    } else if (k < T->key) {
        return BST_insert(T->lchild, k);
    } else {
        return BST_insert(T->rchild, k);
    }
}

/// 循环插入实现方式
int 二叉排序树查找::BSTinsert(二叉排序树查找::BSTree T, int key) {
    while(key){
        if (T == NULL) {
            T = (BSTree) malloc(sizeof(BSTNode));
            T->key = key;
            T->lchild = T->rchild = NULL;
            return 1;
        }else if (key = T->key) {
            return 0;
        } else if (key < T->key) {
            T = T->lchild;
        } else {
            T = T->rchild;
        }
    }
}


void 二叉排序树查找::Create_BST(二叉排序树查找::BSTree &t, int *str, int n) {
    t = NULL;
    int i =0;
    while (i < n){
        BST_insert(t,str[i]);
        i++;
    }
}
