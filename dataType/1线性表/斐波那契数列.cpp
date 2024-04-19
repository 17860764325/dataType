//
// Created by lihaoran on 2024/2/28.
//

#include "../../headSpace/dataTypeWork/斐波那契数列.h"
int 斐波那契数列::fun(int n) {
    if (n == 0){
        return 0;
    }
    if (n == 1){
        return 1;
    }
    if (n > 1){
        return fun(n-1) + fun(n-2);
    }
    return 0;
}

void 斐波那契数列::test() {
    cout << fun(5) << endl;
}

 int main() {
     斐波那契数列 a;
   a.test();
}
