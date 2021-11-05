#ifndef CRRStrategy_H
#define CRRStrategy_H
#include<iostream>
#include"BinomialLatticeStrategy.h"
using namespace std;

class CRRStrategy :public BinomialLatticeStrategy {
private:
	double Qu, Qd;
public:
	CRRStrategy();
	~CRRStrategy();
	CRRStrategy(double S_, double K_, double R_, double T_, double V_);

};

#endif

