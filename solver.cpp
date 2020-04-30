#include <iostream>
#include <complex>
#include "solver.hpp"
using namespace std;

double solver::solve(solver::RealVariable& x){
    return x.getReal();
}

complex<double> solver::solve(solver::ComplexVariable& x){
    return complex<double>(x.getReal(),x.getImg());
}

// *** real ***
solver::RealVariable& solver::operator^(solver::RealVariable& x, double num){
    return x;
}
solver::RealVariable& solver::operator*(solver::RealVariable& x, double num){
    return x;
}
solver::RealVariable& solver::operator/(solver::RealVariable& x, double num){
    return x;
}
solver::RealVariable& solver::operator+(solver::RealVariable& x, double num){
    return x;
}
solver::RealVariable& solver::operator-(solver::RealVariable& x, double num){
    return x;
}
solver::RealVariable& solver::operator==(solver::RealVariable& x, double num){
    return x;
}

solver::RealVariable& solver::operator^(double num, solver::RealVariable& x){
    return x;
}
solver::RealVariable& solver::operator*(double num, solver::RealVariable& x){
    return x;
}
solver::RealVariable& solver::operator/(double num, solver::RealVariable& x){
    return x;
}
solver::RealVariable& solver::operator+(double num, solver::RealVariable& x){
    return x;
}
solver::RealVariable& solver::operator-(double num, solver::RealVariable& x){
    return x;
}
solver::RealVariable& solver::operator==(double num, solver::RealVariable& x){
    return x;
}

solver::RealVariable& solver::operator^(solver::RealVariable& x1, solver::RealVariable& x2){
    return x1;
}
solver::RealVariable& solver::operator*(solver::RealVariable& x1, solver::RealVariable& x2){
    return x1;
}
solver::RealVariable& solver::operator/(solver::RealVariable& x1, solver::RealVariable& x2){
    return x1;
}
solver::RealVariable& solver::operator+(solver::RealVariable& x1, solver::RealVariable& x2){
    return x1;
}
solver::RealVariable& solver::operator-(solver::RealVariable& x1, solver::RealVariable& x2){
    return x1;
}
solver::RealVariable& solver::operator==(solver::RealVariable& x1, solver::RealVariable& x2){
    return x1;
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