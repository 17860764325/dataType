//
// Created by lihaoran on 2024/1/16.
//

#ifndef UNTITLED1_FLOYD佛洛依德算法求最短路径_H
#define UNTITLED1_FLOYD佛洛依德算法求最短路径_H
#define MAX_LENGTH 10

class floyd佛洛依德算法求最短路径 {
private:
    int A[MAX_LENGTH][MAX_LENGTH];
    int path[MAX_LENGTH][MAX_LENGTH];
public:
    void Floyd(int n);
};


#endif//UNTITLED1_FLOYD佛洛依德算法求最短路径_H
