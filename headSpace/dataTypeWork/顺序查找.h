//
// Created by lihaoran on 2024/1/24.
//

#ifndef UNTITLED1_顺序查找_H
#define UNTITLED1_顺序查找_H


class 顺序查找 {
private:
    typedef int ElemType;
    /// 查找表的数据结构
    typedef struct {
        ElemType *elem; /// 动态数组的基址
        int TableLen;/// 表的长度
    } SSTable;
public:
    int Search_Seq(SSTable ST,ElemType key);

};


#endif//UNTITLED1_顺序查找_H
