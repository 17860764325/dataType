//
// Created by lihaoran on 2024/2/8.
//

#include "../../headSpace/dataTypeWork/第8章4节课后题.h"

/// 使用单链表实现简单选择排序
void 第8章4节课后题::selectSort(LinkList &L) {
    LNode *h = L,*p,*q,*r,*s;
    L = NULL;
    while (h != NULL){ /// 持续扫描原链表
        p=s=h;q=r=NULL;
        /// 指针S，r记忆最大节点和其前驱；p为工作指针，q为其前驱
        while(p!= NULL){ /// 扫描原链表找最大节点s
            if (p ->data > s->data){ /// 找到更大的记忆它的前驱
                s=p;
                r=q;
            }
            q=p;p=p->next; /// 继续寻找
        }
        if (s == h){
            h = h->next;/// 最大节点在原链表前端
        }else{
            r->next = s->next;/// 最大节点在原链表表内
        };
        s->next = L; /// 结点s插入结果链的前端
        L = s;
    }
}

/// 判断一个顺序表是否是一个小根堆
bool 第8章4节课后题::IsMinHeap(int *A, int len) {
    if (len%2 == 0){ /// len为偶数，又一个单分支节点
        if (A[len/2] > A[len]) return false;/// 判断分支节点
        for (int i = len/2-1; i >= 1; i--) {/// 判断所有的双分支节点
            if (A[i]>A[2*i] || A[i] > A[2*i + 1]) return false;
        }
    }else { /// len为奇数，没有单分支节点
        for (int i = len/2; i >= 1; i--) { /// 判断所有双分支结点
            if (A[i] > A[2*i] || A[i] > A[2*i + 1]) return false;
        }
    }
    return true;
}