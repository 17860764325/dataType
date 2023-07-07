//
// Created by lihaoran on 7/3/23.
//
#define MaxSize 100
struct TreeNode{
    int data;
    bool isEmpty;
};

void init(TreeNode T[]){
    for (int i = 0; i < MaxSize; ++i) {
        T[i].isEmpty = true;
    }
}