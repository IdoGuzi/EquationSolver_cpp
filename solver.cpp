#include <iostream>
#include <complex>
#include <cmath>
#include "solver.hpp"
using namespace std;
using namespace solver;

double solver::solve(const RealVariable& x){
    if (x.getA()==0 && x.getB()==0 && x.getC()!=0) throw runtime_error("not equal 0");
    if (x.getA()!=0){
        if (x.getB()*x.getB()<4*x.getA()*x.getC()) throw invalid_argument("There is no real solution");
        double x1,x2,sq,div;
        sq = sqrt(x.getB()*x.getB()-4*x.getA()*x.getC());
        div = 2*x.getA();
        x1= (-x.getB()+sq)/div;
        x2= (-x.getB()-sq)/div;
        return x1;
    }
    return -x.getC()/x.getB();
}

complex<double> solver::solve(const ComplexVariable& x){
    if (x.getA()==0.0 && x.getB()==0.0 && x.getC()!=0.0) throw runtime_error("not equal 0");
    if (x.getA()!=0.0) {
        complex<double> x1,x2;
        x1 = (-x.getB()+sqrt(x.getB()*x.getB()-4.0*x.getA()*x.getC()))/(2.0*x.getA());
        x2 = (-x.getB()-sqrt(x.getB()*x.getB()-4.0*x.getA()*x.getC()))/(2.0*x.getA());
        return x1;
    }
    return -x.getC()/x.getB();
}

// *** real ***
const RealVariable RealVariable::operator^(const double num) const{
    if (this->a==0 && this->b==0) return RealVariable(this->a,this->b,pow(this->c,num));
    if (num>2 || num<0) throw invalid_argument("invalid input");
    if (this->a==0){
        if (num==2) return RealVariable(this->b*this->b,2*this->b*this->c,this->c*this->c);
    }else{
        if (num>1) throw invalid_argument("invalid input");
    }
    if (num==1) return RealVariable(this->a,this->b,this->c);
    if (num==0) return RealVariable(0,0,1);
    throw runtime_error("something went wrong");
}

const RealVariable RealVariable::operator*(const double num) const{
    return RealVariable(this->a*num,this->b*num,this->c*num);
}

const RealVariable RealVariable::operator*(const RealVariable& x) const{
    if ((this->a!=0 && x.a!=0) || (this->a!=0 && x.b!=0) ||(this->b!=0 && x.a!=0)){
        throw invalid_argument("power will be greater than 2");
    }
    if (this->a==0 and x.a==0) {
        return RealVariable(this->b*x.b,this->b*x.c+this->c*x.b,this->c*x.c);
    }
    if (this->a==0) return RealVariable(this->c*x.a,this->c*x.b,this->c*x.c);
    if (x.a==0) return RealVariable(x.c*this->a,x.c*this->b,x.c*this->c);
    throw runtime_error("condtion wasn't met");
}

RealVariable solver::operator*(const double num, const RealVariable& x){
    return RealVariable(x.getA()*num,x.getB()*num,x.getC()*num);
}


const RealVariable RealVariable::operator/(const double num) const{
    if (num==0) throw invalid_argument("divide by zero exception");
    return RealVariable(this->a/num,this->b/num,this->c/num);
}

const RealVariable RealVariable::operator/(const RealVariable& x) const{
    if (x.a==0 && x.b==0 && x.c!=0) {
        return RealVariable(this->a/x.c,this->b/x.c,this->c/x.c);
    }
    if (this->a==x.a && this->b==x.b && this->c==x.c) return RealVariable(0,0,1);
    if (this->c==0 && x.a==0 && x.c==0) return RealVariable(0,this->a/x.b,this->b/x.b); 
    throw runtime_error("condtion for division isn't correct");
}

RealVariable solver::operator/(const double num, const RealVariable& x){
    if (x.getA()==0 || x.getB()==0 || x.getC()==0) throw runtime_error("divide by zero");
    return RealVariable(num/x.getA(),num/x.getB(),num/x.getC());
}




const RealVariable RealVariable::operator+(const double num) const{
    return RealVariable(this->a,this->b,this->c+num);
}

const RealVariable RealVariable::operator+(const RealVariable& x) const{
    return RealVariable(this->a+x.a,this->b+x.b,this->c+x.c);
}

RealVariable solver::operator+(const double num, const RealVariable& x){
    return RealVariable(x.getA(),x.getB(),x.getC()+num);
}



const RealVariable RealVariable::operator-(const double num) const{
    return RealVariable(this->a,this->b,this->c-num);
}

const RealVariable RealVariable::operator-(const RealVariable& x) const{
    return RealVariable(this->a-x.a,this->b-x.b,this->c-x.c);
}

RealVariable solver::operator-(const double num, const RealVariable& x){
    return (-1)*x+num;
}

const RealVariable RealVariable::operator==(const double num) const{
    return RealVariable(this->a,this->b,this->c-num);
}
const RealVariable RealVariable::operator==(const RealVariable& x) const{
    return RealVariable(this->a-x.a,this->b-x.b,this->c-x.c);
}
RealVariable solver::operator==(const double num, const RealVariable& x){
    return x-num;
}

// *** complex ***
const ComplexVariable ComplexVariable::operator^(const complex<double> num) const{
    if (num.imag()!=0) throw invalid_argument("power can't be imaginary");
    double real=num.real();
    if (this->a==0.0 && this->b==0.0) {return ComplexVariable(this->a,this->b,pow(this->c,num));}
    if (real>2.0 || real<0.0) throw invalid_argument("power not in range");
    if (this->a==0.0) {
        if (num==2.0) {
            return ComplexVariable(this->b*this->b,(this->b*this->c)+(this->b*this->c),this->c*this->c);
        }
    }else {
        if (real==2) throw invalid_argument("power not in range");
    }
    if (real==1) return ComplexVariable(this->a,this->b,this->c);
    if (real==0) return ComplexVariable(0.0,0.0,1.0+0i);
    throw runtime_error("power denied");
}

const ComplexVariable ComplexVariable::operator*(const ComplexVariable& x) const{
    if ((this->a!=0.0 && x.a!=0.0) || (this->a!=0.0 && x.b!=0.0) ||(this->b!=0.0 && x.a!=0.0)){
        throw invalid_argument("power will be greater than 2");
    }
    if (this->a==0.0 && x.a==0.0) return ComplexVariable(this->b*x.b,this->b*x.c+this->c*x.b,this->c*x.c);
    if (this->a==0.0) return ComplexVariable(this->c*x.a,this->c*x.b,this->c*x.c);
    if (x.a==0.0) return ComplexVariable(this->a*x.c,this->b*x.c,this->c*x.c);
    throw runtime_error("error multipling");

}
const ComplexVariable ComplexVariable::operator*(const complex<double> x) const{
    return ComplexVariable(this->a*x,this->b*x,this->c*x);
}
ComplexVariable solver::operator*(const complex<double> num, const ComplexVariable& x){
    return ComplexVariable(x.getA()*num,x.getB()*num,x.getC()*num);
}

const ComplexVariable ComplexVariable::operator/(const ComplexVariable& x) const{
    if (x.a!=0.0 && x.b==0.0 && x.c==0.0) return ComplexVariable(0.0,0.0,this->a/x.a);
    if (x.a==0.0 && x.b!=0.0 && x.c==0.0) return ComplexVariable(0.0,this->a/x.b,this->b/x.b);
    if (x.a==0.0 && x.b==0.0 && x.c!=0.0) return ComplexVariable(this->a/x.c,this->b/x.c,this->c/x.c);
    throw runtime_error("didn't divide");
}
const ComplexVariable ComplexVariable::operator/(const complex<double> x) const{
    if (x==0.0) throw invalid_argument("divide by zero");
    return ComplexVariable(this->a/x,this->b/x,this->c/x);
}

const ComplexVariable ComplexVariable::operator+(const ComplexVariable& x) const{
    return ComplexVariable(this->a+x.a,this->b+x.b,this->c+x.c);
}
const ComplexVariable ComplexVariable::operator+(const complex<double> x) const{
    return ComplexVariable(this->a,this->b,this->c+x);
}
ComplexVariable solver::operator+(const complex<double> num, const ComplexVariable& x){
    return x+num;
}

const ComplexVariable ComplexVariable::operator-(const ComplexVariable& x) const{
    return ComplexVariable(this->a-x.a,this->b-x.b,this->c-x.c);
}
const ComplexVariable ComplexVariable::operator-(const complex<double> x) const{
    return ComplexVariable(this->a,this->b,this->c-x);
}
ComplexVariable solver::operator-(const complex<double> num, const ComplexVariable& x){
    return (-1)*x+num;
}

const ComplexVariable ComplexVariable::operator==(const complex<double> x) const{
    return ComplexVariable(this->a,this->b,this->c-x);
}
const ComplexVariable ComplexVariable::operator==(const ComplexVariable& x) const{
    return ComplexVariable(this->a-x.a,this->b-x.b,this->c-x.c);
}
ComplexVariable solver::operator==(const complex<double> num, const ComplexVariable& x){
    return x-num;
}