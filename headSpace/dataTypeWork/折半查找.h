//
// Created by lihaoran on 2024/1/25.
//

#ifndef UNTITLED1_折半查找_H
#define UNTITLED1_折半查找_H


class 折半查找 {
private:
    typedef int ElemType;
    typedef struct {
        ElemType * elem; /// 动态数组基址
        int TableLen;/// 数组长度
    } SSTable;
public:
    int  Binary_Search(SSTable L,ElemType key);

};


#endif//UNTITLED1_折半查找_H
