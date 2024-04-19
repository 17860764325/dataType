//
// Created by lihaoran on 2024/1/31.
//

#include "../../headSpace/dataTypeWork/求指定节点在二叉排序树中的层次.h"

int 求指定节点在二叉排序树中的层次::function(BSTree bsTree,int key) {
    int item = 0; /// 计数器
    bool flag = false; /// 查找成功标志
    while (bsTree != NULL && !flag){
        /// 记录在第几层。
        item ++;
        if( key == bsTree->key ){
            /// 查找成功退出
            flag = true;
        }else if(key > bsTree->key){
            /// 大于就往右找
            bsTree = bsTree->rchild;
        }else{
            /// 小于往左找
            bsTree = bsTree -> lchild;
        }
    }
    /// 返回层数 0 为未找到
    return item;

}