#include "solver.hpp"
#include <math.h>
#include <stdexcept>
#include <iostream>
using namespace std;
namespace solver
{

/*-------------Real()Varabile implementation--------------*/
    RealVariable operator+(const RealVariable& rv, const double d)
    {
        RealVariable t(rv.a, rv.b, rv.c + d);
        return t;
    }
    RealVariable operator+(const double d, const RealVariable& rv)
    {
        RealVariable t(rv.a, rv.b, rv.c + d);
        return t;
    }
    RealVariable operator+(const RealVariable& rv1, const RealVariable& rv2)
    {
        RealVariable t(rv1.a + rv2.a, rv1.b + rv2.b, rv1.c + rv2.c);
        return t;
    }
    /*--------*/
    RealVariable operator-(const RealVariable& rv, const double d)
    {
        RealVariable t(rv.a, rv.b, rv.c - d);
        return t;
    }
    RealVariable operator-(const double d, const RealVariable& rv)
    {
        RealVariable t(-rv.a, -rv.b, d - rv.c);
        return t;
    }
    RealVariable operator-(const RealVariable& rv1, const RealVariable& rv2)
    {
        RealVariable t(rv1.a - rv2.a, rv1.b - rv2.b, rv1.c - rv2.c);
        return t;
    }
    RealVariable operator-(const RealVariable& rv)
    {
        RealVariable t(-rv.a, -rv.b, -rv.c);
        return t;
    }
    /*---------*/
    RealVariable operator*(const RealVariable& rv, const double d)
    {
        RealVariable t(rv.a * d, rv.b * d, rv.c * d);
        return t;
    }
    RealVariable operator*(const double d, const RealVariable& rv)
    {
        RealVariable t(rv.a * d, rv.b * d, rv.c * d);
        return t;    
    }
    RealVariable operator*(const RealVariable& rv1, const RealVariable& rv2)
    {
        RealVariable t(rv1.a * rv2.a, rv1.b * rv2.b, rv1.c * rv2.c);
        return t;
    }/*--------*/
    RealVariable operator/(const RealVariable& rv, const double d)
    {
        if(d == 0)throw std::runtime_error("you cannot divide by zero!\n");
        RealVariable t(rv.a / d, rv.b / d, rv.c / d);
        return t;
    }
    RealVariable operator^(const RealVariable& rv, const double d)
    {
        if(d == 0)
            return RealVariable(0, 0, 1);
        if(d == 1)
            return RealVariable(0, 1, 0);
        if(d == 2)
            return RealVariable(1, 0, 0);
        throw std::runtime_error("invalid power input\n");
    }
    RealVariable operator==(const RealVariable& rv, const double d)
    {
        return rv - d;
    }
    RealVariable operator==(const double d, const RealVariable& rv)
    {
        return d - rv;
    }
    RealVariable operator==(const RealVariable& rv1, const RealVariable& rv2)
    {
        return rv1 - rv2;
    }
    
    double solve(const RealVariable& rv)
    {
        double a = rv.getA(), b = rv.getB(), c = rv.getC();
        if(a == 0)
        {
            if(b != 0)return -c/b;

            throw std::runtime_error("this equation does not have real roots\n");
        }
        double d = b*b -4*a*c;
        if(d >= 0)
        {
            return (-b + sqrt(d))/(2*a);
        }
        else
            throw std::runtime_error("this equation does not have real roots\n");
    }
    /*-------------ComplexVarabile implementation--------------*/

    ComplexVariable operator+(const ComplexVariable& cv1, const ComplexVariable& cv2)
    {
        ComplexVariable t(cv1.a + cv2.a, cv1.b + cv2.b, cv1.c + cv2.c);
        return t;
    }
    ComplexVariable operator+(int i, const ComplexVariable& cv)
    {
        complex<double> a(i + cv.a.real(), cv.a.imag());
        complex<double> b(i + cv.b.real(), cv.b.imag());
        complex<double> c(i + cv.c.real(), cv.c.imag());
        ComplexVariable t(cv.a, cv.b, c);
        return t;
    }
    ComplexVariable operator+(const ComplexVariable& cv, int i)
    { 
        complex<double> a(cv.a.real() + i, cv.a.imag());
        complex<double> b(cv.b.real() + i, cv.b.imag());
        complex<double> c(cv.c.real() + i, cv.c.imag());
        ComplexVariable t(cv.a, cv.b, c);
        return t;
    }
    ComplexVariable operator+(const ComplexVariable& cv, const complex<double> c)
    {
        ComplexVariable t(cv.a, cv.b, cv.c + c);
        return t;
    }
    ComplexVariable operator+(const complex<double> c, const ComplexVariable& cv)
    {
        ComplexVariable t(cv.a, cv.b, cv.c + c);
        return t;
    }
    /*----------*/
    ComplexVariable operator-(const ComplexVariable& cv1, const ComplexVariable& cv2)
    {
        ComplexVariable t(cv1.a - cv2.a, cv1.b - cv2.b, cv1.c - cv2.c);
        return t;
    }
    ComplexVariable operator-(int i, const ComplexVariable& cv)
    {
        complex<double> a(-cv.a.real(), -cv.a.imag());
        complex<double> b(-cv.b.real(), -cv.b.imag());
        complex<double> c(i - cv.c.real(), -cv.c.imag());
        ComplexVariable t(a, b, c);
        return t;
    }
    ComplexVariable operator-(const ComplexVariable& cv, int i)
    {
        complex<double> a(cv.a.real() , cv.a.imag());
        complex<double> b(cv.b.real() - i, cv.b.imag());
        complex<double> c(cv.c.real() - i, cv.c.imag());
        ComplexVariable t(cv.a, cv.b, c);
        return t;
    }
    ComplexVariable operator-(const ComplexVariable& cv)
    {
        ComplexVariable t(-cv.getA(), -cv.getB(), -cv.getC());
        return t;
    }

    ComplexVariable operator*(const ComplexVariable& cv1, const ComplexVariable& cv2) //(a+xi)(b+yi) = ab-xy+(ay+bx)i
    {
        ComplexVariable t(cv1.a * cv2.a, cv1.b * cv2.b, cv1.c * cv2.c);
        return t;
    }
    ComplexVariable operator*(int i, const ComplexVariable& cv)
    {
        complex<double> a(i * cv.a.real(), i * cv.a.imag());
        complex<double> b(i * cv.b.real(), i * cv.b.imag());
        complex<double> c(i * cv.c.real(), i * cv.c.imag());
        ComplexVariable t(a, b, c);
        return t;
    }
    ComplexVariable operator*(const ComplexVariable& cv, int i)
    {
        complex<double> a(cv.a.real() * i, cv.a.imag() * i);
        complex<double> b(cv.b.real() * i, cv.b.imag() * i);
        complex<double> c(cv.c.real() * i, cv.c.imag() * i);
        ComplexVariable t(a, b, c);
        return t;
    }
    ComplexVariable operator*(const complex<double> c, const ComplexVariable& cv)
    {
        ComplexVariable t(cv.getA()*c, cv.getA()*c, cv.getA()*c);
        return t;
    }

    ComplexVariable operator/(const ComplexVariable& cv, int i)
    {
        complex<double> a(cv.a.real() / i, cv.a.imag() / i);
        complex<double> b(cv.b.real() / i, cv.b.imag() / i);
        complex<double> c(cv.c.real() / i, cv.c.imag() / i);
        ComplexVariable t(a, b, c);
        return t;

    }
    // ComplexVariable operator/(ComplexVariable& cv1, ComplexVariable& cv2)
    // {
    //     complex<double> a(cv1.a.real() / cv2.a.real(), cv1.a.imag() / cv2.a.imag());
    //     complex<double> b(cv1.b.real() / cv2.b.real(), cv1.b.imag() / cv2.b.imag());
    //     complex<double> c(cv1.c.real() / cv2.c.real(), cv1.c.imag() / cv2.c.imag());
    //     ComplexVariable t(a, b, c);
    //     return t;
    // }
    ComplexVariable operator==(const ComplexVariable& cv1, const ComplexVariable& cv2)
    {
        return cv1 - cv2;
    }        
    ComplexVariable operator==(int i, const ComplexVariable& cv)
    {
        return i -cv;
    }
    ComplexVariable operator==(const ComplexVariable& cv, int i)
    {
        return cv - i;
    }

    ComplexVariable operator^(const ComplexVariable& cv, int i)
    {
        if(i == 0)
            return ComplexVariable(complex<double>(0,0), complex<double>(0,0), complex<double>(1,0)); 
        if(i == 1)
            return ComplexVariable(complex<double>(0,0), complex<double>(1,0), complex<double>(0,0)); ;
        if(i == 2)
            return ComplexVariable(complex<double>(1,0), complex<double>(0,0), complex<double>(0,0)); ;
        throw std::runtime_error("invalid power input\n");
    }
    bool operator!(const complex<double>& c)
    {
        return c.real() == 0 && c.imag() == 0;
    }
    bool operator!=(const complex<double>& c, int i)
    {
        return c.real() != i || c.imag() != i;
    }
    bool operator>=(const complex<double>& c, int i)
    {
        return c.real() >= i || c.imag() >= i;
    }
    complex<double> operator*(int i, complex<double>& c)
    {
        return complex<double>(c.real() * i, c.imag() * i);
    }

    complex<double> solve(const ComplexVariable& cv)
    {
        complex<double> a = cv.getA(), b = cv.getB(), c = cv.getC();
        if(!a)
        {
            if(b != 0)
            {
                complex<double> t = -c/b;
                return t;
            }
            throw std::runtime_error("this equation does not have real roots\n");
        }
        complex<double> d = b*b -4*a*c;
        if(d >= 0)
        {
            complex<double> t((-b + sqrt(d))/(2*a));
            return t;
        }
        else
            throw std::runtime_error("this equation does not have real roots\n");

    }
}