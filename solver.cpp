#include <iostream>
#include <complex>
#include <cmath>
#include "solver.hpp"
using namespace std;
using namespace solver;

double solve(RealVariable& x){
    if (x.getB()*x.getB()<4*x.getA()*x.getC()) throw invalid_argument("function is complex");
    double x1,x2;
    x1= (-x.getB()+sqrt(x.getB()*x.getB()-4*x.getA()*x.getC()))/2*x.getA();
    x2= (-x.getB()-sqrt(x.getB()*x.getB()-4*x.getA()*x.getC()))/2*x.getA();
    return x1;
}

complex<double> solve(ComplexVariable& x){
    return complex<double>(x.getReal(),x.getImg());
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

const RealVariable operator*(double num, RealVariable& x){
    return x*num;
}



const RealVariable RealVariable::operator/(const double num) const{//maybe
    if (num==0) throw invalid_argument("divide by zero exception");
    return RealVariable(this->a/num,this->b/num,this->c/num);
}

const RealVariable RealVariable::operator/(const RealVariable& x) const{
    if (x.a==0 && x.b==0 && x.c!=0) {
        return RealVariable(this->a/x.c,this->b/x.c,this->c/x.c);
    }
    throw runtime_error("condtion for division isn't correct");
}

const RealVariable operator/(RealVariable& x, double num){
    return RealVariable(x.getA()/num,x.getB()/num,x.getC()/num);
}

const RealVariable operator/(double num, RealVariable& x){
    if (x.getA()==0 || x.getB()==0 || x.getC()==0) throw runtime_error("divide by zero");
    return RealVariable(num/x.getA(),num/x.getB(),num/x.getC());
}




const RealVariable RealVariable::operator+(const double num) const{
    return RealVariable(this->a,this->b,this->c+num);
}
const RealVariable RealVariable::operator+(const RealVariable& x) const{
    return RealVariable(this->a+x.a,this->b+x.b,this->c+x.c);
}

const RealVariable operator+(double num, RealVariable& x){
    return RealVariable(x.getA(),x.getB(),x.getC()+num);
}


const RealVariable RealVariable::operator-(const double num) const{
    return RealVariable(this->a,this->b,this->c-num);
}

const RealVariable RealVariable::operator-(const RealVariable& x) const{
    return RealVariable(this->a-x.a,this->b-x.b,this->c-x.c);
}

const RealVariable operator-(double num, RealVariable& x){
    return num + (-1)*x;
}

const RealVariable RealVariable::operator==(const double num) const{
    return RealVariable(this->a,this->b,this->c-num);
}
const RealVariable RealVariable::operator==(const RealVariable& x) const{
    return RealVariable(this->a-x.a,this->b-x.b,this->c-x.c);
}


// *** complex ***
solver::ComplexVariable& solver::operator^(solver::ComplexVariable& x, double num){
    return x;
}
solver::ComplexVariable& solver::operator*(solver::ComplexVariable& x, double num){
    return x;
}
solver::ComplexVariable& solver::operator/(solver::ComplexVariable& x, double num){
    return x;
}
solver::ComplexVariable& solver::operator+(solver::ComplexVariable& x, double num){
    return x;
}
solver::ComplexVariable& solver::operator-(solver::ComplexVariable& x, double num){
    return x;
}
solver::ComplexVariable& solver::operator==(solver::ComplexVariable& x, double num){
    return x;
}

solver::ComplexVariable& solver::operator^(double num, solver::ComplexVariable& x){
    return x;
}
solver::ComplexVariable& solver::operator*(double num, solver::ComplexVariable& x){
    return x;
}
solver::ComplexVariable& solver::operator/(double num, solver::ComplexVariable& x){
    return x;
}
solver::ComplexVariable& solver::operator+(double num, solver::ComplexVariable& x){
    return x;
}
solver::ComplexVariable& solver::operator-(double num, solver::ComplexVariable& x){
    return x;
}
solver::ComplexVariable& solver::operator==(double num, solver::ComplexVariable& x){
    return x;
}

solver::ComplexVariable& solver::operator^(solver::ComplexVariable& x1, solver::ComplexVariable& x2){
    return x1;
}
solver::ComplexVariable& solver::operator*(solver::ComplexVariable& x1, solver::ComplexVariable& x2){
    return x1;
}
solver::ComplexVariable& solver::operator/(solver::ComplexVariable& x1, solver::ComplexVariable& x2){
    return x1;
}
solver::ComplexVariable& solver::operator+(solver::ComplexVariable& x1, solver::ComplexVariable& x2){
    return x1;
}
solver::ComplexVariable& solver::operator-(solver::ComplexVariable& x1, solver::ComplexVariable& x2){
    return x1;
}
solver::ComplexVariable& solver::operator==(solver::ComplexVariable& x1, solver::ComplexVariable& x2){
    return x1;
}

solver::ComplexVariable& solver::operator^(solver::ComplexVariable& x1, complex<double> x2){
    return x1;
}
solver::ComplexVariable& solver::operator*(solver::ComplexVariable& x1, complex<double> x2){
    return x1;
}
solver::ComplexVariable& solver::operator/(solver::ComplexVariable& x1, complex<double> x2){
    return x1;
}
solver::ComplexVariable& solver::operator+(solver::ComplexVariable& x1, complex<double> x2){
    return x1;
}
solver::ComplexVariable& solver::operator-(solver::ComplexVariable& x1, complex<double> x2){
    return x1;
}
solver::ComplexVariable& solver::operator==(solver::ComplexVariable& x1, complex<double> x2){
    return x1;
}

solver::ComplexVariable& solver::operator^(complex<double> x1, solver::ComplexVariable& x2){
    return x2;
}
solver::ComplexVariable& solver::operator*(complex<double> x1, solver::ComplexVariable& x2){
    return x2;
}
solver::ComplexVariable& solver::operator/(complex<double> x1, solver::ComplexVariable& x2){
    return x2;
}
solver::ComplexVariable& solver::operator+(complex<double> x1, solver::ComplexVariable& x2){
    return x2;
}
solver::ComplexVariable& solver::operator-(complex<double> x1, solver::ComplexVariable& x2){
    return x2;
}
solver::ComplexVariable& solver::operator==(complex<double> x1, solver::ComplexVariable& x2){
    return x2;
}