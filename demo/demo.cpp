////
//// Created by lihaoran on 2023/12/14.
////
//#include<iostream>
//using namespace std;
//
//class A{
//public:
//  A(int i):x(i){}
//  A(){
//    x=0;
//  }
//  friend A operator ++(A a);
//  friend A operator --(A &a);
//  void print();
//private:
//  int x;
//};
//
//A operator++(A a){
//  ++a.x;
//  return a;
//}
//
//A operator--(A &a){
//  --a.x;
//  return a;
//}
//
//int main(){
//  A a(7);
//  cout << a << endl;
//  --a;
//  cout << a << endl;
//  return 0;
//}