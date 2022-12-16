#include "Rational.h"



RationalNumber operator+(int num, RationalNumber &other)
{
    RationalNumber current(num, 1);
    return current + other;
}

RationalNumber operator*(int num, RationalNumber &other)
{
    RationalNumber current(num, 1);
    return current * other;
}


RationalNumber operator-(int num, RationalNumber &other)
{
    RationalNumber current(num, 1);
    return current - other;
}


RationalNumber operator/(int num, RationalNumber &other)
{
    RationalNumber current(num, 1);
    return current / other;
}

std::ostream& operator<<(std::ostream & os,  RationalNumber& fraction)
{

    if(fraction.getDenominator() == 0)
    {
        os << "Error : Divide by zero\n";
        exit(0);
    }
    else if(fraction.getNumerator() == 0)
    {
        os << "0\n";
    }
    else
    {
	    os << fraction.getNumerator() << "/" << fraction.getDenominator() << "\n"; 
    }

	return os;
}