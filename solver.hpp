#include <complex>
using namespace std;
namespace solver 
{
    class RealVariable
    {
        double a,b,c;
        public:
        
        RealVariable():a(0), b(1), c(0){};
        RealVariable(double z):a(0), b(0), c(z){};
        RealVariable(double x, double y, double z):a(x), b(y), c(z){};
        friend RealVariable operator+(const RealVariable&, const double);
        friend RealVariable operator+(const double, const RealVariable&);
        friend RealVariable operator+(const RealVariable&, const RealVariable&);

        friend RealVariable operator-(const RealVariable&, const double);
        friend RealVariable operator-(const double, const RealVariable&);
        friend RealVariable operator-(const RealVariable&, const RealVariable&);
        friend RealVariable operator-(const RealVariable& rv);


        friend RealVariable operator*(const RealVariable&, const double);
        friend RealVariable operator*(const double, const RealVariable&);
        friend RealVariable operator*(const RealVariable&, const RealVariable&);

        friend RealVariable operator/(const RealVariable&, const double);

        friend RealVariable operator^(const RealVariable&, const double);

        friend RealVariable operator==(const RealVariable&, const double);
        friend RealVariable operator==(const double, const RealVariable&);
        friend RealVariable operator==(const RealVariable&, const RealVariable&);
        double getA() const
        {
            return this->a;
        }
        double getB() const
        {
            return this->b;
        }
        double getC() const
        {
            return this->c;
        }


    };

    class ComplexVariable
    {
        complex<double> a,b,c;
        public:
        ComplexVariable():a(0,0),b(1,0), c(0,0){};
        ComplexVariable(complex<double> x, complex<double> y, complex<double> z):a(x),b(y), c(z){};

        friend ComplexVariable operator+(const ComplexVariable&, const ComplexVariable&);
        friend ComplexVariable operator+(int, const ComplexVariable&);
        friend ComplexVariable operator+(const ComplexVariable&, int);
        friend ComplexVariable operator+(const ComplexVariable& cv, const complex<double> c);
        friend ComplexVariable operator+(const complex<double> c, const ComplexVariable& cv);



        friend ComplexVariable operator-(const ComplexVariable&, const ComplexVariable&);
        friend ComplexVariable operator-(int, const ComplexVariable&);
        friend ComplexVariable operator-(const ComplexVariable&, int);
        friend ComplexVariable operator-(const ComplexVariable& rv);

        friend ComplexVariable operator*(const ComplexVariable&, const ComplexVariable&);
        friend ComplexVariable operator*(int, const ComplexVariable&);
        friend ComplexVariable operator*(const ComplexVariable&, int);
        friend ComplexVariable operator*(const complex<double> c, const ComplexVariable& cv);

        friend ComplexVariable operator/(const ComplexVariable&, const ComplexVariable&);
        friend ComplexVariable operator/(const ComplexVariable&, int);

        friend ComplexVariable operator==(const ComplexVariable&, const ComplexVariable&);        
        friend ComplexVariable operator==(int, const ComplexVariable&);
        friend ComplexVariable operator==(const ComplexVariable&, int);

        friend ComplexVariable operator^(const ComplexVariable&, int);

        complex<double> getA() const
        {
            return this->a;
        }
        complex<double> getB() const
        {
            return this->b;
        }
        complex<double> getC() const
        {
            return this->c;
        }



    };
    double solve(const RealVariable&);
    complex<double> solve(const ComplexVariable&);
};