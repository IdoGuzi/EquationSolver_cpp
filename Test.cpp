#include <iostream>
#include "doctest.h"
#include "solver.hpp"
using namespace std;
using namespace solver;

TEST_CASE("basic real"){
    RealVariable x;
    CHECK(solve(x==3)==3);
    CHECK(solve(2*x==2)==1);
    CHECK(solve(x*3+1-1==3)==1);
    CHECK(solve(x==2)==2);
    CHECK(solve(2*x+1==3)==1);
    CHECK((solve(4*(x^2)-2==14)==4 || solve(4*(x^2)-2==14)==-4));
    CHECK(solve(2==x*2)==1);
    CHECK(solve(6-x*3==0)==2);
    CHECK(solve((x^2)+2*x+1==0)==-1);
    CHECK(solve(x==1)==1);
    CHECK(solve(2*x/2==1)==1);
    CHECK(solve(x/2==2)==4);
    CHECK(solve(3+x-2+5==2-x+x+2)==-2);
    CHECK(solve(4*x+1==3)==1/2);
    CHECK(solve(2/x==1)==2);
    CHECK(solve(x==1)==1);
    CHECK(solve(x+x==2)==1);
    CHECK(solve(2*x+x==3)==1);
    CHECK(solve(x*4==3)==3/4);
    CHECK_NOTHROW(solve(x-x==0)); //true for all x real number
}

TEST_CASE("more real trinoms"){
    RealVariable x;
    CHECK(solve(4*(x^2)-4*x+1==0)==0.5);
    CHECK(solve(9*(x^2)+6*x+1==0)==-1/3);
    CHECK((solve((x^2)==1)==1 || solve((x^2)==1)==-1));
    CHECK((solve((x^2)==4)==2 || solve((x^2)==4)==-2));
    CHECK(solve((x^2)+4*x+4==0)==-2);
    CHECK((solve((x^2)-4*x+4==0)==-2 || solve((x^2)-4*x+4==0)==2));
    CHECK(solve((x^2)+6*x+6==-3)==-3);
    CHECK(solve(4*(x^2)+12*x+9==0)==-3/2);
    CHECK((solve(2*(x^2)+6*x+4==0)==-1 || solve(2*(x^2)+6*x+4==0)==-2));
    CHECK((solve(2*(x^2)+9*x+4==0)==-1/2 || solve(2*(x^2)+9*x+4==0)==-4));
    CHECK((solve(3*(x^2)+13*x==0)==0 || solve(3*(x^2)+13*x==0)==-13/3));
    CHECK((solve(3*(x^2)+13*x+10==0)==-1 || solve(3*(x^2)+13*x+10==0)==-10/3));
}

TEST_CASE("more real..."){
    RealVariable x;
    CHECK(solve(x+x+x+x==4)==1);
    CHECK((solve(x*x==1)==1 || solve(x*x==1)==-1));
    CHECK((solve((x+x+x+x)*x==4)==1 || solve((x+x+x+x)*x==4)==-1));
    CHECK(solve(x/x+x==2)==1);
    CHECK(solve(x-x+x==x-x+1)==1);
    CHECK((solve(x*x*(x/x)==1)==1 || solve(x*x*(x/x)==1)==-1));
    CHECK(solve(x*x/x==1)==1);
    CHECK(solve(1+1+1+1+x==0)==-4);
    CHECK(solve(x+x+4*x==6)==1);
}

TEST_CASE("real throws"){
    RealVariable x;
    CHECK_THROWS(solve((x^2)==-5));
    CHECK_THROWS(solve((x^2)==-25));
    CHECK_THROWS(solve((x^2)==-4));
    CHECK_THROWS(solve((2^x==2))); // can't solve exponantial equations
    CHECK_THROWS(solve(x*x==-1));
    CHECK_THROWS(solve(x*x*x*x==1));
    CHECK_THROWS(solve(x^-1));
    CHECK_THROWS(solve(x/0==1));
    CHECK_THROWS(solve(x*0==1));
    CHECK_THROWS(solve((x^2)-8*x+25==0));
}

TEST_CASE("basic complex"){
    ComplexVariable x;
    CHECK(solve(x+3i==1)==complex<double>(1,-3));
    CHECK(solve(x+1i==4)==complex<double>(4,-1));
    CHECK(solve(3*x-4i*3i==1)==complex<double>(1/3,4));
    CHECK(solve(x*3-5i==2)==complex<double>(2/3,5));
    CHECK(solve(x*2-2==2i)==complex<double>(1,1));
    CHECK(solve(x*3-2+x*5+4==3i-2i+5i)==complex<double>(-1/4,3/4));
    CHECK(solve(1+2+3+4+2*x==4i)==complex<double>(5,2));
    CHECK(solve(-3.5i+x==2)==complex<double>(2,3.5));
    CHECK(solve(3==x-1i)==complex<double>(3,1));
    CHECK(solve(3i+x+3==6i)==complex<double>(-3,3)); 
    CHECK(solve(3-x+2i)==complex<double>(3,2));
    CHECK(solve(x==1i)==complex<double>(0,1));
    CHECK(solve(-3+x-2i==0)==complex<double>(3,2));
    CHECK(solve(3.0+2i-1i==x-2i)==3.0+3i);
    CHECK(solve(4i+2.0-x==0)==4i+2.0);
    CHECK(solve(x*4==4.0+4i)==1.0+1i);
}

TEST_CASE("complex trinom"){
    ComplexVariable x;
    CHECK((solve((x^2)+4*x+5==0)==complex<double>(2,-1) || solve((x^2)+4*x+5==0)==complex<double>(-2,-1)));
    CHECK((solve((x^2)+2*x+2==0)==complex<double>(1,-1) || solve((x^2)+2*x+2==0)==complex<double>(-1,-1)));
    CHECK((solve((x^2)-2*x+2==0)==complex<double>(-1,-1) || solve((x^2)-2*x+2==0)==complex<double>(1,-1)));
    CHECK(solve((x^2)+16==0)==complex<double>(0,-4));
    CHECK((solve((x^2)+2*x+2==0)==complex<double>(1,-1) || solve((x^2)+2*x+2==0)==complex<double>(-1,-1)));
    CHECK(solve(4*(x^2)+4==0)==complex<double>(0,-1));
    CHECK(solve(4*(x^2)+9==0)==complex<double>(0,-3/2));
    CHECK((solve(2*(x^2)+2*x+13==0)==complex<double>(1/2,-5/2) || solve(2*(x^2)+2*x+13==0)==complex<double>(-1/2,-5/2)));
    CHECK((solve(-4*(x^2)-8*x-8==0)==complex<double>(1,1) || solve(-4*(x^2)-8*x-8==0)==complex<double>(-1,1)));
    CHECK((solve(-1*(x^2)+6*x-10==0)==complex<double>(-3,1) || solve(-1*(x^2)+6*x-10==0)==complex<double>(3,1)));
    CHECK((solve(5*(x^2)+4*x+8==0)==complex<double>(2/5,-6/5) || solve(5*(x^2)+4*x+8==0)==complex<double>(-2/5,-6/5)));

}

TEST_CASE("complex throws/notthrow"){
    ComplexVariable x;
    CHECK_THROWS(solve((x^3)==1));
    CHECK_THROWS(solve(x*x*x==1));
    CHECK_THROWS(solve(x+x+x+(x^-3)==3));
    CHECK_NOTHROW(solve(x*x*x*x*x/(x^3)==1));
    CHECK_NOTHROW(solve(x/(x^2)==1)); //maybe going to work
    CHECK_THROWS(solve(0-x-x-x-x/0));
    CHECK_THROWS(solve(0*x==1));
    CHECK_THROWS(solve(x*0+2));
    CHECK_THROWS(solve(x^(2/-8)));
    CHECK_THROWS(solve(x*0i));
    CHECK_THROWS(solve(x^3i));
}

TEST_CASE("more"){
    ComplexVariable x;
    CHECK(solve(x*4==4)==complex<double>(1,0));
    CHECK(solve(x*2+2==0)==complex<double>(-1,0));
    CHECK(solve(x==0)==complex<double>(0,0));
    CHECK((solve((x^2)+2*x)==0.0 || solve((x^2)+2*x)==-2.0));
    CHECK(solve(x==2)==2.0);
    CHECK(solve(-2+3==x)==1.0+0i);
    CHECK(solve(x==9i)==9i);
    CHECK(solve(3i-3.0==x)==-3.0+3i);
    CHECK(solve(x*2+4i)==2i);
    CHECK(solve(3.0+2i+3i==x)==3.0+5i);
    CHECK(solve(x+x==2i)==1i);
}