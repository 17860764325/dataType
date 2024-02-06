//
// Created by lihaoran on 2024/2/6.
//

#ifndef UNTITLED1_第8章3节综合题1_H
#define UNTITLED1_第8章3节综合题1_H
#include "所有的数据结构.h"


class 第8章3节综合题 {
public:

    void move(int A[],int len);
    int kth_elem(int A[],int low,int high,int k);

    typedef enum {RED,WHITE,BLUE} color;
    void Flag_Arrange(color A[],int n );

    int setPartition(int a[],int n );
};


#endif//UNTITLED1_第8章3节综合题1_H
