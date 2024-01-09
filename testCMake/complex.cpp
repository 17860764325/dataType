//
// Created by lihaoran on 2024/1/9.
//

#include "../headSpace/test/complex.h"

#include<stdio.h>
#include<cmath>
complex::complex()
{
  real = 0;
  imag = 0;
}

complex::complex(double a, double b) {
  real = a;
  imag = b;
}

void complex::set(double a,double b) {
  real = a;
  imag = b;
}

double complex::getReal() {
  return real;
}

double complex::getImag() {
  return imag;
}

complex complex::add(complex a) {
  double real = this->real + a.getReal();
  double imag = this->imag + a.getImag();
  return complex(real,imag);
}

void complex::show()
{
  if (imag >= 0)
  {
    printf("%.2f+%.2fi", real, imag);
  }
  else
  {
    printf("%.2f%.2fi", real, imag);
  }
  return;
}
