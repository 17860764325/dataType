//
// Created by lihaoran on 6/12/23.
// 串的存储结构
#include <stdlib.h>
// 定长的数据存储
#define MAXLEN 255 // 串的最大长度
typedef struct {
    char ch[MAXLEN]; // 每个分量存储一个字符
    int length; // 串的实际长度
} SString;

// 使用动态数组模拟串的存储结构--在初始化的时候进行分配内存
typedef struct {
    char *ch; // 指示动态分配数组的指针
    int length; // 串的长度
} HString;

void init(){
    HString s;
    /** 使用malloc分配内存空间 */
    s.ch = (char *)malloc(MAXLEN * sizeof(char));
    s.length = 0;
    /** 如果想释放这片内存空间，需要手动进行回收*/
}

/** 使用链式结构存储串*/
typedef struct StringNode{
    char ch; // 没次节点只能存储一个字符
    struct StringNode * next;
}StringNode, * String;

typedef struct StringNode1{
    char ch[4]; // 没次节点可以存储四  个字符
    struct StringNode * next;
}StringNode1, * String1;


