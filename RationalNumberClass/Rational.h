#pragma once

#include <iostream>

class RationalNumber
{
public:
	RationalNumber();
	RationalNumber(int num, int denom);

    // Overloading
    RationalNumber operator+(RationalNumber &other);
    RationalNumber operator+(int num);
    
	RationalNumber operator-(RationalNumber &other);
	RationalNumber operator-(int num);

	RationalNumber operator*(RationalNumber &other);
	RationalNumber operator*(int num);

	RationalNumber operator/(RationalNumber &other);
	RationalNumber operator/(int num);

	// friend functions

	friend RationalNumber operator+(int num, RationalNumber &other);
	friend RationalNumber operator-(int num, RationalNumber &other);
	friend RationalNumber operator*(int num, RationalNumber &other);
	friend RationalNumber operator/(int num, RationalNumber &other);

	friend std::ostream& operator<<(std::ostream& os,  RationalNumber& fraction);

	// Accessors
	int getNumerator();
	int getDenominator();
	// Mutators
	void setNumerator(int num);
	void setDenominator(int num);


private:
	
	void reduce();

private:
	int numerator;
	int denominator;
};

