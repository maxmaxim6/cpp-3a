#include "doctest.h"
#include "solver.hpp"
#include <complex>
#include <iostream>
using namespace solver;
using namespace std;

RealVariable x;
ComplexVariable z;

TEST_CASE("quadratic root")
{
    CHECK(solve(6*(x^2)+6*x+4 == 4*(x^2)+2*x+4) == 0 );
    CHECK(solve(3*(x^2)+22*x+57 == (x^2)-3) == -5 );
    CHECK(solve(-(x^2)+6*x-4 == -2*(x^2)-4) == 0 );
    CHECK(solve(-(x^2)+22*x+56 == -3*(x^2)-4) == -5 );
    CHECK(solve(2*(x^2)+4*x-21 == -4*x+3) == 2 );
    CHECK(solve(2*(x^2)+14*x+15 == 3) == -1 );
    CHECK(solve((x^2)+5*x+7 == -x-1) == -2 );
    CHECK(solve((x^2)+6*x+9 == 1) == -2);
    CHECK(solve(2*(x^2)-15*x+34 == x+4) == 5 );
    CHECK(solve((x^2)-x-5 == 1) == 3);
    CHECK(solve(-2*(x^2)+14*x+28 == -4*(x^2)-2*x-2) == -3 );
    CHECK(solve((x^2)+5*x-3 == x-3) == 0);
    CHECK(solve(2*(x^2)-7*x-26 == -3*x+4) == 5);
    CHECK(solve(2*(x^2)-5 == 3) == 2);
    CHECK(solve(2*(x^2)+4*x+1 == -1) == -1);
    CHECK(solve(2*(x^2)-17*x+35 == x-1) == 6);
    CHECK(solve(-3*(x^2)-9*x == -4*(x^2)-3*x) == 6);
    CHECK(solve((x^2)+2*x-26 == -2) == 4);
    CHECK(solve(2*(x^2)+8*x+9 == 1) == -2);
    CHECK(solve(-2*(x^2)+4*x+1 == -3*(x^2)-x-3) == -1);
    CHECK_THROWS(solve(-2*(x^4)+4*x+1 == -3*(x^2)-x-3));
}
TEST_CASE("simple equations")
{
    CHECK(solve(x+15 == -8) == -23);
    CHECK(solve(1+x == -2-2*x) == -1);
    CHECK(solve(2*x+7-5*x-12 == -8*x+3) == 1.6);
    CHECK(solve(-x+1 == -8-10*x) == -1);
    CHECK(solve(19*x == 0) == 0);
    CHECK(solve(3*x == 1) == 1.0/3.0);
    CHECK(solve(-x == 5) == -5);
    CHECK(solve(3*x-21 == 8*x) == -4.2);
    CHECK(solve(2*x+8 == 16*x-48) == 4);
    CHECK(solve(2+x == 7*x+26-6+3*x) == -2);
    CHECK(solve(20-4*x-4*x-8 == 10-9*x) == -2);
    CHECK(solve(x/3 == 54) == 162);
    CHECK(solve(1+x == 0.2) == -0.8);
    CHECK(solve(-7*x-10 == 2-3*x) == -3);
    CHECK(solve(35-13*x == 19-5*x) == 2);
    CHECK(solve(-17*x+8 == x+44) == -2);
    CHECK(solve(-10*x+5+x == 6*x-9+29) == -1);
    CHECK(solve(22+6*x+2 == 3*x+14+5*x) == 5);
    CHECK(solve(-45*x+30+31*x == 32+16*x+28) == -1);
    CHECK(solve(7*x+2-14*x == -5*x+26-x) == -24);
    CHECK(solve(-115*x+44-x+21 == -4+13*x+8-9*x+1) == 0.5);
}
TEST_CASE("quadratic with no roots")
{
    CHECK_THROWS(solve(6*(x^2)+2*x+7 == 0));
    CHECK_THROWS(solve(4*(x^2)-5*x+2 == 0) );
    CHECK_THROWS(solve((x^2)+1 == 0) );
    CHECK_THROWS(solve((x^2)+x+1 == 0));
    CHECK_THROWS(solve((x^2)+x+1 == (x^2)+x));
}
TEST_CASE("simple equation with no solution")
{
    CHECK_THROWS(solve(1+x == 0.2 +x));
    CHECK_THROWS(solve(4*x+-7*x-10 == 2-3*x));
    CHECK_THROWS(solve(35-13*x+10*x == 19-5*x+2*x));
    CHECK_THROWS(solve(x+44 == x+44));
}
TEST_CASE("quadratic equation with complex roots")
{
    complex<double> t(3,4);
    ComplexVariable y;
    CHECK(solve(y+y-2 == 10) == complex(6.0,0.0));
    CHECK(solve(4*y-8 == 10*y+complex(4.0, -12.0)) == complex(-2.0,2.0));
    CHECK(solve(3*y*7+21 == 0*y+complex(0.0, -21.0)) == complex(-1.0,-1.0));
    CHECK(solve(7+5-4*3*y == 18) == complex(-0.5,0.0));
    CHECK(solve(y+13 == 7) == complex(-6.0,0.0));
    CHECK(solve(2*y-y*3 == 15) == complex(-15.0,0.0));
    CHECK(solve(y+2-y-2 == y) == complex(0.0,0.0));
    CHECK(solve(56*y+8 == 0*y+complex(8.0, -56.0)) == complex(0.0,-1.0));
    CHECK(solve(5*y == 6*y) == complex(0.0,0.0));
    CHECK(solve(4*y+12 == 0) == complex(-3.0,0.0));

    CHECK((solve((z^2) +2*z +1== 1) == complex(0.0,0.0) || solve((z^2) +2*z +1== 1) == complex(-2.0,0.0)));
    CHECK((solve(5*(z^2) -8*z +5 == 0) == complex(0.8,0.6) || solve(5*(z^2) -8*z +5 == 0) == complex(0.8,-0.6)));
    CHECK((solve((z^2) +9 == 0) == complex(0.0,3.0) || solve((z^2) +9 == 0) == complex(0.0,-3.0)));
    CHECK((solve((z^2) +4*z +7 == 0) == complex(-2.0,-sqrt(3)) || solve((z^2) +4*z +7 == 0) == complex(-2.0,sqrt(3))));
    CHECK((solve(5*(z^2) +6*z +3 == 0) == complex(-0.6,sqrt(6)/5) || solve(5*(z^2) +6*z +3 == 0) == complex(-0.6,-sqrt(6)/5)));
    CHECK((solve(0*(z^2) +3*z +27 == 0) == complex(-9.0,0.0) ));
    CHECK((solve((z^2)/2 +z +14 == 0) == complex(-1.0,3*sqrt(3)) || solve((z^2)/2 +z +14 == 0) == complex(-1.0,-3*sqrt(3))));
    CHECK((solve((z^2)*8 +56*z +16 == 0) == complex(-(7+sqrt(41))/2,0.0) || solve((z^2)*8 +56*z +16 == 0) == complex((-7+sqrt(41))/2,0.0)));
    CHECK((solve(2*(z^2) +4*z +9== 8+2/2) == complex(0.0,0.0) || solve((z^2) +2*z +1== 1) == complex(-2.0,0.0)));
    CHECK((solve(6*(z^2)/2 +2*z*3 +90== 90) == complex(0.0,0.0) || solve((z^2) +2*z +1== 1) == complex(-2.0,0.0)));
    CHECK((solve((z^2)*2-(z^2) +2*z*8- 14*z +1== 1) == complex(0.0,0.0) || solve((z^2) +2*z +1== 1) == complex(-2.0,0.0)));
}
TEST_CASE("quadratic equation with complex roots")
{
    ComplexVariable y;
    CHECK((solve((z^2) +2*z +1== 1) == complex(0.0,0.0) || solve((z^2) +2*z +1== 1) == complex(-2.0,0.0)));
    CHECK((solve(5*(z^2) -8*z +5 == 0) == complex(0.8,0.6) || solve(5*(z^2) -8*z +5 == 0) == complex(0.8,-0.6)));
    CHECK((solve((z^2) +9 == 0) == complex(0.0,3.0) || solve((z^2) +9 == 0) == complex(0.0,-3.0)));
    CHECK((solve((z^2) +4*z +7 == 0) == complex(-2.0,-sqrt(3)) || solve((z^2) +4*z +7 == 0) == complex(-2.0,sqrt(3))));
    CHECK((solve(5*(z^2) +6*z +3 == 0) == complex(-0.6,sqrt(6)/5) || solve(5*(z^2) +6*z +3 == 0) == complex(-0.6,-sqrt(6)/5)));
    CHECK((solve((y^2)==-4)== complex(0.0,2.0) || solve((y^2)==-4) == complex(0.0,-2.0) ));
    CHECK((solve((y^2)+100==0) == complex(0.0,10.0) ||solve((y^2)+100 == 0) == complex(0.0,-10.0) ));
    CHECK((solve((y^2)+4*y+5==0) == complex(-2.0,1.0) || solve((y^2)+4*y+5 == 0) == complex(-2.0,-1.0) ));
    CHECK(solve(2*(y^2)-6*y+5==0) == complex(1.5,-0.5) );
    CHECK(solve((y^2)+y+6 == 4 )== complex(-0.5,sqrt(7)/2.0));
    CHECK(solve(2*(y^2) + 3*y + 2 == 0 )== complex(-0.75,sqrt(7)/4.0));
    CHECK(solve((y^2) + 3*y + 6 == -(y^2)+2*y-1 ) == complex(-1.0/4.0, sqrt(55)/4.0));
    CHECK(solve((y^2)+2*y + 21 == 18 )== complex(-1.0,sqrt(2)));
    CHECK(solve(3*(y^2)+y+5 == -3*y ) == complex(-2.0/3.0,sqrt(11)/3.0));
    CHECK(solve((y^2)+y+6 == 4 )== complex(-0.5,sqrt(7)/2.0));
    CHECK(solve(8*y+19 == -(y^2) )== complex(-4.0,sqrt(3)));
    CHECK(solve(7*(y^2)+15*y+30 == 4 )== complex(-15.0/14.0,sqrt(503)/14.0));
}
TEST_CASE("demo.cpp tests")
{
       RealVariable x;

    CHECK((solve(8*(x^2)+10*x-2 == 2*(x^2)-8*x-9) - (-0.4591670003))<=0.00001);  
    CHECK(solve(2*x-4 == 10) == 7);  
    CHECK(solve((x^2) == 16) == 4);   
    CHECK_THROWS(solve((x^2) == -16));
    CHECK(solve((x^2) + 2*x + 4.0 == 20 + 6.0*x/2 - x) == 4);   
    CHECK(solve(2*x-4.0 == 10.0) == 7);   
    ComplexVariable y;
    CHECK(solve(2*y-4 == 10) == complex(7.0, 0.0));  
    CHECK(solve((y^2) == 16) == complex(4.0, 0.0));   
    CHECK(solve((y^2) == -16) == complex(0.0, 4.0));  
    CHECK(solve((y^2) + 2*y + 4 == 20 + 6*y/2 - y) == complex(4.0, 0.0));   
    CHECK(solve(y+5i == 2*y+3i) == complex(0.0, 2.0));   
}