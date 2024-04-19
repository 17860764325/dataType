//
// Created by lihaoran on 2024/1/31.
//

#include "../../headSpace/dataTypeWork/判断一个树是不是二叉排序树.h"

int 判断一个树是不是二叉排序树::function(判断一个树是不是二叉排序树::BiTree bt) {
    int b1,b2; /// b1 做接受左子树使用,b2 做接受右子树返回值
    if(bt == NULL){
        return 1;
    }else{
        b1 = function(bt -> lchild);
        /// 上一个子树并没有破坏递增，并且上一个值小于当前值
        if (b1 == 0 || predt >= bt->data){
            return 0;
        }
        /// 赋值当前值
        predt = bt -> data;
        /// 右子树的值
        b2 = function(bt -> rchild);
        /// 返回当前树最大值
        return b2;
    }
}