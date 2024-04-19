//
// Created by lihaoran on 2024/1/25.
//

#include "../../headSpace/dataTypeWork/折半查找.h"

int 折半查找::Binary_Search(折半查找::SSTable L, 折半查找::ElemType key) {
    int low=0,high = L.TableLen,mid ;
    while(low<=high){
        mid=(low+high)/2;/// 取中间位置数值
        if (L.elem[mid] == key){
            return mid; /// 查找成功返回下标
        }
        else if (L.elem[mid] < key){
            low = mid + 1; /// 从后半部分继续查找
        }else {
            low = high -1; /// 从前半部分继续查找
        }
    }
    return -1; /// 查找失败返回-1
}