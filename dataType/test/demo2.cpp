//
// Created by lihaoran on 2023/11/30.
//

#include <iostream>
using namespace std;

int fun(char *s);
//int main(){
//    std::cout<<fun("hello   ");
//    return 0;
//}
int fun(char *s){
    printf(s);
    char *t = s;
    while(*t != '\0')
        t++;
    return (t-s);
}
