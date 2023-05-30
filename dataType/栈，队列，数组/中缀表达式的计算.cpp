//
//  中缀表达式的计算.cpp
//  dataType
//
//  Created by lihaoran on 2023/3/27.
//
/*
 逻辑就是,先执行中缀表达式转后缀表达式,然后将后缀表达式进行计算。
 */
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

// 判断是否为数字
bool isNumber(const string& str) {
    stringstream sin(str);
    double d;
    char c;
    if (!(sin >> d)) return false;
    if (sin >> c) return false;
    return true;
}

// 判断运算符优先级
int priority(const char& c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

// 中缀表达式转后缀表达式
string infixToPostfix(const string& infix) {
    stack<char> s;
    stringstream sin(infix);
    string postfix = "";
    string token;
    while (sin >> token) {
        if (isNumber(token)) {
            postfix += token;
            postfix += " ";
        } else if (token == "(") {
            s.push('(');
        } else if (token == ")") {
            while (s.top() != '(') {
                postfix += s.top();
                postfix += " ";
                s.pop();
            }
            s.pop();
        } else {
            while (!s.empty() && priority(token[0]) <= priority(s.top())) {
                postfix += s.top();
                postfix += " ";
                s.pop();
            }
            s.push(token[0]);
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        postfix += " ";
        s.pop();
    }
    return postfix;
}

// 计算后缀表达式
double calculatePostfix(const string& postfix) {
    stack<double> s;
    stringstream sin(postfix);
    string token;
    while (sin >> token) {
        if (isNumber(token)) {
            s.push(stod(token));
        } else {
            double operand2 = s.top();
            s.pop();
            double operand1 = s.top();
            s.pop();
            if (token == "+") {
                s.push(operand1 + operand2);
            } else if (token == "-") {
                s.push(operand1 - operand2);
            } else if (token == "*") {
                s.push(operand1 * operand2);
            } else if (token == "/") {
                s.push(operand1 / operand2);
            } else if (token == "^") {
                s.push(pow(operand1, operand2));
            }
        }
    }
    return s.top();
}
//int main() {
//    string infix = "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3";
//    string postfix = infixToPostfix(infix);
//    cout << "Infix expression: " << infix << endl;
//    cout << "Postfix expression: " << postfix << endl;
//    double result = calculatePostfix(postfix);
//    cout << "Result: " << result << endl;
//    return 0;
//}


                
