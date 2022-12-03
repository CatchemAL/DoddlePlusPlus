#include "YieldCurve.h"
using std::vector;

YieldCurve::YieldCurve(vector<double> tenors, vector<double> rates) 
	: tenors(tenors), rates(rates)
{
}

int YieldCurve::getSum() const
{
	return 42;
}

double YieldCurve::getDiscountFactor(double tenor) const
{
	return this->rates[0];
}



