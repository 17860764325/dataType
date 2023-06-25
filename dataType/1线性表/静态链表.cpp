//
//  静态链表.cpp
//  dataType
//
//  Created by lihaoran on 2023/2/28.
//

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10        //静态链表的最大长度
struct Node{            //静态链表结构类型的定义
    int data;            //存储数据元素
    int next;            //下一个元素的数组下标
};
typedef struct{            //静态链表结构类型的定义
    int data;            //存储数据元素
    int next;            //下一个元素的数组下标
}SLinkList[MaxSize];

//void testSLinkList(){
//    struct Node x;
//    printf("size=%d\n",sizeof(x));
//
//    struct Node a[MaxSize];
//    printf("size=%d\n",sizeof(a));
//    
//    SLinkList b;
//    printf("size=%d\n",sizeof(b));
//}

/*
 初始化静态链表：把 a[0] 的 next 设为 -1
 如何判断结点是否为空？
 可让 next 为某个特殊值，如 -2
 插入位序为 i 的结点：
 ①找到一个空的结点，存入数据元素
 ②从头结点出发找到位序为 i-1 的结点
 ③修改新结点的 next
 ④修改 i-1 号结点的 next
 删除某个结点：
 ①从头结点出发找到前驱结点
 ②修改前驱结点的游标
 ③被删除结点 next 设为 -2
 静态链表：用数组的方式实现的链表
 （1）优点：增、删 操作不需要大量移动元素
 （2）缺点：不能随机存取，只能从头结点开始依次往后查找；容量固定不可变
 （3）适用场景：①不支持指针的低级语言；②数据元素数量固定不变的场景（如操作系统的文件分配表FAT）
 */
