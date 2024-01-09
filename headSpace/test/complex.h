#pragma once
#ifndef _complex_H_
#define _complex_H_
 
class complex {
private:
  double real, imag;
public:
  complex();//空的构造函数
  complex(double,double);//默认参数的构造函数
  void set(double,double);//设置函数
  double getReal();//获取实部函数
  double getImag();//获取虚部函数
  double module();//获取复数模的函数
 
  //复数加减乘除函数
  complex add(complex);
  complex decrease(complex);
  complex multiply(complex);
  complex divide(complex);
  //复数显示函数
  void show();
};
 
#endif // !_complex_H_