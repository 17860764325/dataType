//
//  中缀表达式转换后缀表达式.cpp
//  dataType
//
//  Created by lihaoran on 2023/3/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MaxSize 30

typedef struct {
    char data[MaxSize];
    int top;
} stock;

typedef struct {
    int data[MaxSize];
    int top;
} stockNumber;



// 初始化栈
void initStock (stock &s){
    s.top = -1;
}


// 判断栈是否为空
bool isEmpty(stock s){
    if (s. top == -1)
        return true;
    return false;
}

// 判断栈是否满了
bool isFull(stock s){
    if (s. top == MaxSize -1)
        return true;
    return false;

}

// 基本操作--顺序表的入栈
bool push(stock &s, char x){
    if(isFull(s)== true)
        return false;
    s.data[++s.top] = x;
    return true;
}

// 基本操作--顺序表出栈
bool pop(stock &s, char &c){
    if(isEmpty(s)== true)
        return  false;
    c = s. data[s. top--];
    return true;
}

// 基本操作--取出栈顶元素
bool getTop(stock s, char &c){
    if(isEmpty(s)== true)
        return  false;
    c = s.data[s.top];
    return true;
}

// 判断优先级 a: 要比较的运算符,b:当前的运算符
bool priority(char a, char b, stock s){
    if (((a == '+' || a == '-')  && (b == '*' || b == '/'))|| (a=='('||isEmpty(s))) {
        return false;
    }else {
        return true;
    }
}


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
void calculateNumber(char str[],int length){
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

void calculate(char str[],int lenght){
    stock s ;
    initStock(s);
    char strResult[30]; // 后缀表达式
    int resultLength = 0; // 后缀表达式长度
    // 循环中缀表达式
    for (int i = 0; i < lenght; i++) {
        // 分为三种情况
        if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){
            // 运算符--判断符号栈,里面如果栈空或者上一个符号为(则直接把本符号压入栈)
            // 依次弹出同级或者高级的运算符放到后缀表达式。
            char a;
            getTop(s, a);
            while (priority(a, str[i],s)) {
                    char item;
                    pop(s, item);
                    strResult[resultLength] = item;
                    resultLength++;
                    getTop(s, a);
            }
            push(s, str[i]);
        }else if(str[i]=='(' || str[i]==')'){
            // 界限符号 遇到 ( 则压入栈,遇到)则将所有运算符弹出,直到(
            if(str[i]=='(') {
                push(s, str[i]);
            }else {
                char a;
                getTop(s, a);
                bool flag = true;
                while (flag) {
                    if (a == '(') {
                        pop(s, a);
                        flag = false;
                    } else {
                        char item;
                        pop(s, item);
                        strResult[resultLength] = item;
                        resultLength++;
                        getTop(s, a);
                    }
                }
            }
            
        }else {
            // 操作数--直接加到后缀表达式上面
            strResult[resultLength] = str[i];
            resultLength++;
        }
    }
    // 将所有弹出家在表达式后边
    char p;
    while (!isEmpty(s)) {
            char item;
            pop(s, item);
            strResult[resultLength] = item;
            resultLength++;
            getTop(s, p);
    }
    // 打印后缀表达式
    for (int j = 0; j < resultLength; j++) {
        printf("%c", strResult[j]);
    }
    printf("\n");

// 将后缀表达式进行计算
    calculateNumber(strResult, resultLength);
    }


//int main(){
//    char str[30] = "((5/(7-(1+1)))*1)-(2+(1+1))";
//    calculate(str, 27);
//}
