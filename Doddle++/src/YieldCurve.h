#pragma once
#include <vector>

class YieldCurve
{
public:
	YieldCurve(const std::vector<double>& tenors, const std::vector<double>& rates);

	int getSum() const;

	double getDiscountFactor(double tenor) const;


private:
	std::vector<double> tenors;
	std::vector<double> rates;
};
