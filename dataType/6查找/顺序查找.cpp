//
// Created by lihaoran on 2024/1/24.
//

#include "dataTypeWork/顺序查找.h"

int 顺序查找::Search_Seq(顺序查找::SSTable ST, 顺序查找::ElemType key) {
    ST.elem[0] = key; /// 哨兵
    int i ; ///
    for (i = ST.TableLen;ST.elem[i]!=key;i--);/// 从后往前找
    return i; /// 查找成功，则返回下标元素，查找失败则返回 0；
}