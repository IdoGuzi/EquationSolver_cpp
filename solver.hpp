#pragma once

#include <iostream>
#include <complex>
using namespace std;

namespace solver{

    class RealVariable{
      private:
        double a,b,c;
      public:
        // *** ctor & dtor ***
        RealVariable() : a(0),b(1),c(0){}
        RealVariable(double a,double b,double c) {this->a=a;this->b=b;this->c=c;}
        ~RealVariable(){}

        // *** methods ***
        double getA() const{return a;}
        double getB() const{return b;}
        double getC() const{return c;}
        
        //*** operators ***
        const RealVariable operator^(const double num) const;

        const RealVariable operator*(const double num) const;
        const RealVariable operator*(const RealVariable& x) const;
        friend RealVariable operator*(const double num, const RealVariable& x);

        const RealVariable operator/(const double num) const;
        const RealVariable operator/(const RealVariable& x) const;
        friend RealVariable operator/(const double num, const RealVariable& x);


        const RealVariable operator+(const double num) const;
        const RealVariable operator+(const RealVariable& x) const;
        friend RealVariable operator+(const double num, const RealVariable& x);

        const RealVariable operator-(const double num) const;
        const RealVariable operator-(const RealVariable& x) const;
        friend RealVariable operator-(const double num, const RealVariable& x);

        const RealVariable operator==(const double num) const;
        const RealVariable operator==(const RealVariable& x) const;

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

        friend ComplexVariable& operator^(complex<double> x1, ComplexVariable& x2);
        friend ComplexVariable& operator*(complex<double> x1, ComplexVariable& x2);
        friend ComplexVariable& operator/(complex<double> x1, ComplexVariable& x2);
        friend ComplexVariable& operator+(complex<double> x1, ComplexVariable& x2);
        friend ComplexVariable& operator-(complex<double> x1, ComplexVariable& x2);
        friend ComplexVariable& operator==(complex<double> x1, ComplexVariable& x2);
    };
    double solve(const RealVariable& x);

    complex<double> solve(ComplexVariable& x);
};
