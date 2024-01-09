#include "headSpace/test/complex.h"
#include "headSpace/dataTypeWork/普通树的遍历.h"
#include <iostream>

int main() {
    complex A;//验证默认构造函数
    printf("A为:");
    A.show();
    printf("\n");

    complex B(2, -1);//验证两个参数构造函数
    printf("B为：");
    B.show();
    printf("\n");

    // 树的先根和后根遍历
    basTree a;
    a.putogshudebianli();
}
