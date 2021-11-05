#include "BinomialLatticeStrategy.h"
#include<iostream>
#include<math.h>
using namespace std;
BinomialLatticeStrategy::BinomialLatticeStrategy() {
	this->S = 0.0;
	this->K = 0.0;
	this->R = 0.0;
	this->T = 0.0;
	this->V = 0.0;

	this->U = 0.0;
	this->D = 0.0;
	this->q = 0.0;
	this->disc = 0.0;
}
BinomialLatticeStrategy::~BinomialLatticeStrategy() {
}

BinomialLatticeStrategy::BinomialLatticeStrategy(double S_, double K_, double R_, double T_, double V_) {
	this->S = S_;
	this->K = K_;
	this->R = R_;
	this->T = T_;
	this->V = V_;
}

BinomialLatticeStrategy::BinomialLatticeStrategy(const BinomialLatticeStrategy& b) {
	this->S = b.S;
	this->K = b.K;
	this->R = b.R;
	this->T = b.T;
	this->V = b.V;
}

double BinomialLatticeStrategy::get_StockPrice() {
	return this->S;
}
double BinomialLatticeStrategy::get_StrikePrice() {
	return this->K;
}
double BinomialLatticeStrategy::get_RiskFreeRate() {
	return this->R;
}
double BinomialLatticeStrategy::get_Time() {
	return this->T;
}
double BinomialLatticeStrategy::get_VOlatility() {
	return this->V;
}
double BinomialLatticeStrategy::U_() {
	return this->U;
}
double BinomialLatticeStrategy::D_() {
	return this->D;
}
double BinomialLatticeStrategy::q_() {
	return this->q;
}
double BinomialLatticeStrategy::get_discount() {
	return exp(-1 * this->get_RiskFreeRate() * this->get_Time());
}

