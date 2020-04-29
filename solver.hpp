#pragma once

#include <iostream>
#include <complex>
using namespace std;

namespace solver{
    class RealVariable{
      private:
        double real;
      public:
        // *** ctor & dtor ***
        RealVariable() : real(1){}
        RealVariable(double real) {this->real=real;}
        ~RealVariable(){}

        // *** methods ***
        double getReal() {return this->real;}
        void setReal(double real) {this->real=real;}
        
        //*** operators ***
        friend RealVariable& operator^(RealVariable& x, double num);
        friend RealVariable& operator*(RealVariable& x, double num);
        friend RealVariable& operator/(RealVariable& x, double num);
        friend RealVariable& operator+(RealVariable& x, double num);
        friend RealVariable& operator-(RealVariable& x, double num);
        friend RealVariable& operator==(RealVariable& x, double num);

        friend RealVariable& operator^(double num, RealVariable& x);
        friend RealVariable& operator*(double num, RealVariable& x);
        friend RealVariable& operator/(double num, RealVariable& x);
        friend RealVariable& operator+(double num, RealVariable& x);
        friend RealVariable& operator-(double num, RealVariable& x);
        friend RealVariable& operator==(double num, RealVariable& x);

        friend RealVariable& operator^(RealVariable& x1, RealVariable& x2);
        friend RealVariable& operator*(RealVariable& x1, RealVariable& x2);
        friend RealVariable& operator/(RealVariable& x1, RealVariable& x2);
        friend RealVariable& operator+(RealVariable& x1, RealVariable& x2);
        friend RealVariable& operator-(RealVariable& x1, RealVariable& x2);
        friend RealVariable& operator==(RealVariable& x1, RealVariable& x2);
    };
    class ComplexVariable{
      private:
        double real, img;
      public:
        ComplexVariable() : real(1),img(1) {}
        ComplexVariable(double real, double img){this->real=real;this->img=img;}
        ~ComplexVariable(){}

        // *** methods ***
        double getReal(){return this->real;}
        double getImg() {return this->img;}
        void setReal(double real) {this->real=real;}
        void setImg(double img)   {this->img=img;}

        // *** operators ***
        friend ComplexVariable& operator^(ComplexVariable& x, double num);
        friend ComplexVariable& operator*(ComplexVariable& x, double num);
        friend ComplexVariable& operator/(ComplexVariable& x, double num);
        friend ComplexVariable& operator+(ComplexVariable& x, double num);
        friend ComplexVariable& operator-(ComplexVariable& x, double num);
        friend ComplexVariable& operator==(ComplexVariable& x, double num);

        friend ComplexVariable& operator^(double num, ComplexVariable& x);
        friend ComplexVariable& operator*(double num, ComplexVariable& x);
        friend ComplexVariable& operator/(double num, ComplexVariable& x);
        friend ComplexVariable& operator+(double num, ComplexVariable& x);
        friend ComplexVariable& operator-(double num, ComplexVariable& x);
        friend ComplexVariable& operator==(double num, ComplexVariable& x);

        friend ComplexVariable& operator^(ComplexVariable& x1, ComplexVariable& x2);
        friend ComplexVariable& operator*(ComplexVariable& x1, ComplexVariable& x2);
        friend ComplexVariable& operator/(ComplexVariable& x1, ComplexVariable& x2);
        friend ComplexVariable& operator+(ComplexVariable& x1, ComplexVariable& x2);
        friend ComplexVariable& operator-(ComplexVariable& x1, ComplexVariable& x2);
        friend ComplexVariable& operator==(ComplexVariable& x1, ComplexVariable& x2);

        friend ComplexVariable& operator^(ComplexVariable& x1, complex<double> x2);
        friend ComplexVariable& operator*(ComplexVariable& x1, complex<double> x2);
        friend ComplexVariable& operator/(ComplexVariable& x1, complex<double> x2);
        friend ComplexVariable& operator+(ComplexVariable& x1, complex<double> x2);
        friend ComplexVariable& operator-(ComplexVariable& x1, complex<double> x2);
        friend ComplexVariable& operator==(ComplexVariable& x1, complex<double> x2);
    };

    double solve(RealVariable& x);
    complex<double> solve(ComplexVariable& x);
};
