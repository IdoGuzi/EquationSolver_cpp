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
        friend RealVariable operator==(const double num, const RealVariable& x);

    };
    class ComplexVariable{
      private:
        complex<double> a,b,c;
      public:
        ComplexVariable() : a(0,0),b(1,0),c(0,0) {}
        ComplexVariable(complex<double> a, complex<double> b, complex<double> c) {
          this->a=a;this->b=b;this->c=c;
        }
        ~ComplexVariable(){}

        // *** methods ***
        complex<double> getA() const{return this->a;}
        complex<double> getB() const{return this->b;}
        complex<double> getC() const{return this->c;}

        // *** operators ***
        const ComplexVariable operator^(const complex<double> num) const;

        const ComplexVariable operator*(const ComplexVariable& x) const;
        const ComplexVariable operator*(const complex<double> x) const;
        friend ComplexVariable operator*(const complex<double> num, const ComplexVariable& x);

        const ComplexVariable operator/(const ComplexVariable& x) const;
        const ComplexVariable operator/(const complex<double> x) const;

        const ComplexVariable operator+(const ComplexVariable& x) const;
        const ComplexVariable operator+(const complex<double> x) const;
        friend ComplexVariable operator+(const complex<double> num, const ComplexVariable& x);

        const ComplexVariable operator-(const ComplexVariable& x) const;
        const ComplexVariable operator-(const complex<double> x) const;
        friend ComplexVariable operator-(const complex<double> num, const ComplexVariable& x);

        const ComplexVariable operator==(const complex<double> x) const;
        const ComplexVariable operator==(const ComplexVariable& x) const;
        friend ComplexVariable operator==(const complex<double> num, const ComplexVariable& x);
    };
    double solve(const RealVariable& x);

    complex<double> solve(const ComplexVariable& x);
};
