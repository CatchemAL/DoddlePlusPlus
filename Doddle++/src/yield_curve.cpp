#include "YieldCurve.h"
using std::vector;

YieldCurve::YieldCurve(const vector<double>& tenors, const vector<double>& rates) 
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



