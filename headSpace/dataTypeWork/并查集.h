//
// Created by lihaoran on 2024/1/10.
//

#ifndef DATATYPENEW_并查集_H
#define DATATYPENEW_并查集_H
#define SIZE 13

class 并查集 {
private:
    int S[SIZE];
public:
    /// 初始化并查集
    void initial(int S[]);
    /// 查操作
    int Find(int s[],int x);
    /// 并操作
    /// 参数root1是第一个集合根节点 下标
    /// 参数root2是第二个集合的根节点 下标
    void Union(int S[],int root1,int root2);
    /// 并操作优化，小树合并到大树
    void UnionNew(int S[],int root1,int root2);
    /// find终极优化
    int FindFinal(int S[],int x);
};


#endif//DATATYPENEW_并查集_H
