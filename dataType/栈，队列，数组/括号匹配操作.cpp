//
//  括号匹配操作.cpp
//  dataType
//
//  Created by lihaoran on 2023/3/15.
//

#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10// 定义栈栈中元素最大个数

typedef struct {
    char data[MaxSize]; // 静态数组存放栈中元素
    int top; // 栈顶指针
} SqStack1;

// 初始化栈
void InitStack(SqStack1 &S){
    S.top = -1; //初始化顶指针
    printf("初始化栈！");
    printf("\n");
}
// 判断栈是否为空
bool IsEmpty(SqStack1 S){
    if (S.top == -1) {
        printf("栈为空");
        printf("\n");
        return true;
    }
    printf("栈不为空");
    printf("\n");
    return false;
}
// 新元素入栈
bool Push(SqStack1 &S,char x){
    printf("进栈操作%d:",x);
    printf("\n");
    if (S.top == MaxSize -1) {
        printf("栈满不能进栈了");
        printf("\n");
        return false; // 判断栈是否已满
    }
//    S.top += 1;
//    S.data[S.top] = x;
    S.data[++S.top] = x; // 先加加再取值
    return true;
}
// 栈顶元素出栈，用X返回
bool Delete(SqStack1 &S,char &x){
    // 看是否是栈底元素，如果已经到了栈底元素那就不能再删除了
    if (S.top == -1) {
        printf("栈为空不能出栈");
        printf("\n");
        return false ;// 到栈底了，不可以再进行删除了
    }
//    x = S.data[S.top];
//    S.top -= S.top;
    x = S.data[S.top--]; // 先取值再减减
    printf("出栈操作:%d",x);
    printf("\n");
    return true;
}


// 算法实现

bool bracketCheck(char str[],int length){
    SqStack1 S;
    InitStack(S); // 初始化栈
    // 对括号进行循环操作
    for (int i = 0; i < length; i++) {
        if (str[i]=='(' || str[i] == '[' || str[i] == '{') {
            Push(S, str[i]);
        }else{
            if (IsEmpty(S)) { // 扫描到有括号并且栈为空，也就是栈里面没有与之相匹配的左括号
                return false; // 匹配失败
            }
            // 如果栈不为空的话那就进行对比，看是否对比正确
            char topElem; // 出栈的栈顶左括号数据
            Delete(S, topElem);
            
            if(str[i]==')'&&topElem != '(')
                return false;
            if(str[i]==']'&&topElem != '[')
                return false;
            if(str[i]=='}'&&topElem != '{')
                return false; 
        }
    }
    return IsEmpty(S);
}

int main(){
    char str[10] = {'{','{','(',')','}','}','{','{','}','}'};
    printf("%d",bracketCheck(str,10));
    if(bracketCheck(str,10)){
        printf("符合规范");
    }else {
        printf("不符合规范");
    }
    printf("\n");
}
