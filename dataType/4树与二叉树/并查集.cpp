//
// Created by lihaoran on 2024/1/10.
//

#include "../../headSpace/dataTypeWork/并查集.h"


/// 初始化并查集
void 并查集::initial(int S[]){
    for (int i = 0; i < SIZE; ++i) {
        S[i] = -1;
    }
}

/// find操作。找x的所属集合（返回X的根节点）
int 并查集::Find(int s[],int x){
    // 一直循环递归的找根节点
    while(S[x] >=0) x=S[x];
    // 找到了返回根节点,父节点小于0
    return x;
}

/// union操作，将两个结合合并为一个集合
/// 参数root1是第一个集合根节点 下标
/// 参数root2是第二个集合的根节点 下标
void 并查集::Union(int S[],int root1,int root2){
    // 首先判断两个根节点不是相同的
    if(root1==root2) return;
    // 将root2的父节点指向root1
    S[root2]=root1;
}


/// 并查集优化，将小树合并到大树
void 并查集::UnionNew(int *S, int root1, int root2) {
    // 首先判断两个根节点不是相同的
    if(root1==root2) return;
    // 判断两棵树的节点大小
    if(S[root1]>S[root2]){
        // 如果1>2 则 1的节点数少，2的节点数多 需要将1 合并到2
        // 先将大树2的节点数算出来新的节点数
        S[root2] += S[root1];
        // 将小树1的根节点指向小树2
        S[root1] = root2;
    }else{
        // 与上述情况相反，1<2 1的节点数多，2的节点数少 将2 合并到1
        // 先将大树1的节点数算出来新的节点数
        S[root1] += S[root2];
        // 将小树2的根节点指向小树1
        S[root2] = root1;
    }
}

///  并查集终极优化，压缩路径
int 并查集::FindFinal(int *s, int x) {
    int root = x;
    // 一直循环递归的找根节点
    while(S[root] >=0) x=S[root];
    // 到这一步的时候，root已经到根节点的位置了，开始压缩路径
    while(x != root) {
        // 记录路径节点原先的父节点，用于，找寻上一层的父节点
        int t = s[x];
        // 让当前的路径节点的父指针指向根节点
        s[x] = root;
        // 让 x = t; 继续压缩下一个节点（当前节点的父节点）的路径
        x = t;
    }
    // 找到了返回根节点,父节点小于0
    return x;
}