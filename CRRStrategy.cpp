#include "CRRStrategy.h"

#include<iostream>
#include"CRRStrategy.h"
#include<math.h>
#include<iomanip>
using namespace std;

CRRStrategy::CRRStrategy() :BinomialLatticeStrategy() {
	this->Qu = 0.0;
	this->Qd = 0.0;
}
CRRStrategy::CRRStrategy(double S_, double K_, double R_, double T_, double V_) : BinomialLatticeStrategy(S_, K_, R_, T_, V_) {
	Qu = exp(this->get_VOlatility() * sqrt(this->get_Time()));
	Qd = exp(-1 * this->get_VOlatility() * sqrt(this->get_Time()));
	double a = exp(this->get_RiskFreeRate() * this->get_Time());
	this->U = round(Qu * 10000.0) / 10000.0;
	this->D = round(Qd * 10000.0) / 10000.0;
	double num = a - this->D_();
	double denum = this->U_() - this->D_();
	this->q = round((a - this->D) / (this->U - this->D) * 10000.0) / 10000.0;
}
CRRStrategy::~CRRStrategy() {

}

