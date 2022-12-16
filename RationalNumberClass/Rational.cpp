#include "Rational.h"


RationalNumber::RationalNumber()
{
    setNumerator(0);
    setDenominator(0);
}

RationalNumber::RationalNumber(int num, int denom)
{
    setNumerator(num);
    setDenominator(denom);
    reduce();
}

void RationalNumber::reduce()
{

    int num = this->getNumerator();
    int dnum = this->getDenominator();
    int tmp = 0;

    if(num == 0 && dnum == 0) return;

    while (dnum != 0)
    {
        tmp = dnum;
        dnum = num % dnum;
        num = tmp;
    }

    int reducedNum = this->getNumerator() / num;
    int reducedDenum = this->getDenominator() / num;
    
    this->setNumerator(reducedNum);
    this->setDenominator(reducedDenum);
}

RationalNumber RationalNumber::operator+(RationalNumber &other)
{

    int currentA = this->getNumerator();
    int currentB = this->getDenominator();

    int otherA = other.getNumerator();
    int otherB = other.getDenominator();
    

    int numerator = (currentA * otherB) + (otherA * currentB); 
    int denominator = currentB * otherB;

    return RationalNumber(numerator, denominator);
}

RationalNumber RationalNumber::operator+(int num)
{
    RationalNumber current = *this;
    RationalNumber tmp(num, 1);
    return current + tmp;
}

RationalNumber RationalNumber::operator-(RationalNumber &other)
{
    int currentA = this->getNumerator();
    int currentB = this->getDenominator();

    int otherA = other.getNumerator();
    int otherB = other.getDenominator();

    int numerator = (currentA * otherB) - (currentB * otherA);
    int denominator = (currentB * otherB); 

    return RationalNumber(numerator, denominator);
}



RationalNumber RationalNumber::operator-(int num)
{
    RationalNumber current = *this;
    RationalNumber tmp(num, 1);
    return current - tmp; 
}


RationalNumber RationalNumber::operator*(RationalNumber &other)
{
    int currentA = this->getNumerator();
    int currentB = this->getDenominator();

    int otherA = other.getNumerator();
    int otherB = other.getDenominator();

    int numerator = currentA * otherA;
    int denominator = currentB * otherB;

    return RationalNumber(numerator, denominator); 
}

RationalNumber RationalNumber::operator*(int num)
{
    RationalNumber current = *this;
    RationalNumber tmp(num, 1);
    return current * tmp; 
}


RationalNumber RationalNumber::operator/(RationalNumber &other)
{
    int currentA = this->getNumerator();
    int currentB = this->getDenominator();

    int otherA = other.getNumerator();
    int otherB = other.getDenominator();

    int numerator = currentA * otherB;
    int denominator = currentB * otherA;

    return RationalNumber(numerator, denominator); 
}

RationalNumber RationalNumber::operator/(int num)
{
    RationalNumber current = *this;
    RationalNumber tmp(num, 1);
    return current / tmp; 
}


int RationalNumber::getNumerator()
{
    return numerator;
}

int RationalNumber::getDenominator()
{
    return denominator;
}


void RationalNumber::setNumerator(int num)
{
    numerator = num;
}

void RationalNumber::setDenominator(int num)
{
    denominator = num;
}