//
//  中缀表达式转后缀和前缀表达式（栈模拟）.cpp
//
//  dataType
//
//  Created by lihaoran on 2023/3/18.
//
//
#include <stdio.h>
#include <stdlib.h>



// 逻辑思路---后缀表达式的计算(栈模拟)
// 先生成一个数组,里面存放的是一个后缀表达式,然后声明称一个栈来计算和存储;
#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int top;
} stockNumber;


// 初始化栈
void initstockNumber (stockNumber &s){
    s.top = -1;
}


// 判断栈是否为空
bool isEmpty(stockNumber s){
    if (s. top == -1)
        return true;
    return false;
}

// 判断栈是否满了
bool isFull(stockNumber s){
    if (s. top == MaxSize -1)
        return true;
    return false;

}

// 基本操作--顺序表的入栈
bool push(stockNumber &s, char x){
    if(isFull(s)== true)
        return false;
    s.data[++s.top] = x;
    return true;
}

// 基本操作--顺序表出栈
bool pop(stockNumber &s, int &c){
    if(isEmpty(s)== true)
        return  false;
    c = s. data[s. top--];
    return true;
}

// 基本操作--取出栈顶元素
bool getTop(stockNumber s, int &c){
    if(isEmpty(s)== true)
        return  false;
    c = s.data[s.top];
    return true;
}

// 判断是否是操作符号
bool isSign(char c){
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return  true;
    return false;
}

// 操作步骤
void handle(int b, int a, char sign, int &ss){
    if (sign == '+')
        ss= (b + a);
    else if (sign == '-' )
        ss= (b-a) ;
    else if ( sign == '*')
        ss= (b* a);
    else if ( sign == '/')
        ss= (b/a);
    else
        ss= 0;
}

// 后缀表达式的计算
// 后缀表达式字符串,字符串长度,计算结果
void calculate(char str[],int length){
    stockNumber s ;
    int result;
    initstockNumber(s);
    // 首先进行循环,判断每一个字符串是数字还是操作符号
    for (int i = 0; i < length; i ++) {
        if(isSign(str[i])){
            // 是符号 出栈两次然后进行操作符计算
            int a, b;
            pop(s, a);// 出栈操作1
            pop(s, b);// 出栈操作2
            int ss ;
            handle(b, a, str[i],ss); // 计算操作
            push(s, ss );
        }else {
            // 是数字 就入栈
            push(s, str[i]-'0');
        }
    }
    // 取出栈顶元素,即为最后的结果
    getTop(s, result);
    printf("%d", result);
    printf("\n");
}

//int main(){
//    char str[20] = "63/2+5*32*3/2--";
//    calculate(str,15);
//}
