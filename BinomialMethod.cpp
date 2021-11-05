#include "BinomialMethod.h"
#include<iostream>
#include"Lattice.cpp"
#include"Lattice.h"
#include"CRRStrategy.h"
#include<iomanip>
#include<math.h>
using namespace std;

BinomialMethod::BinomialMethod() {
	Lattice<Data, int, 2> lat2(4, Data(0.0, 0.0));
	bs = new BinomialLatticeStrategy();
	lat1 = lat2;
	op = option();
	c = ' ';

}

void BinomialMethod::Interface(double S_, double K_, double R_, double T_, double V_, int branch, char optType, char ty) {

	bs = new CRRStrategy(S_, K_, R_, T_, V_);
	lat1 = Lattice<Data, int, 2>(branch, Data(S_, K_));
	op = option(0.0, 0.0, optType);
	c = ty;
}

BinomialMethod::~BinomialMethod() {
	delete bs;
}

void BinomialMethod::ForwardInduction() {
	double d1, d2;
	int t = 2;;//type binomial
	int root = 1; int result = 0; int count = 1; int c = 1;
	result = t - root;
	int row = 0;
	int col = 0;
	lat1.vec[row][col].set(bs->get_StockPrice(), 0.0);
	do {
		row++;
		c = result + c;
		for (int i = 0; i < c; i++) {
			if (i == 0) {
				d1 = round(lat1.vec[row - 1][i].getStock() * bs->D_() * 100.0) / 100.0;
				lat1.vec[row][i].set(d1, 0.0);
				if (row == lat1.get_dept()) {
					d1 = round(lat1.vec[row - 1][i].getStock() * bs->D_() * 100.0) / 100.0;
					d2 = bs->get_StrikePrice();
					lat1.vec[row][i].set(d1, op.get_payoff(d1, d2));
				}
			}
			else {
				d1 = round(lat1.vec[row - 1][i - 1].getStock() * bs->U_() * 100.0) / 100.0;
				lat1.vec[row][i].set(d1, 0.0);
				if (row == lat1.get_dept()) {
					d1 = round(lat1.vec[row - 1][i - 1].getStock() * bs->U_() * 100) / 100.0;
					d2 = bs->get_StrikePrice();
					lat1.vec[row][i].set(d1, op.get_payoff(d1, d2));
				}

			}
		}
		count++;
	} while (count < lat1.get_dept() + 1);
}

void BinomialMethod::print() {
	cout <<endl;
	for (int i = 0; i < lat1.get_row(); i++) {
		for (int j = 0; j < lat1.get_cols(); j++) {
			cout << lat1.vec[i][j].getStock() << "," << lat1.vec[i][j].getOption() << "  ";
		}
		cout <<endl;
	}
}
double BinomialMethod::max(double a, double b) {
	return a > b ? a : b;
}
void BinomialMethod::BackwardInduction() {
	int count = 0;
	for (int i = lat1.get_dept() - 1; i >= 0; i--) {
		count++;
		for (int j = 0; j < lat1.get_cols() - count; j++) {
			if (c == 'E') {
				double op = round(exp(-1 * bs->get_RiskFreeRate() * bs->get_Time()) * ((lat1.vec[i + 1][j].getOption() * (1 - bs->q_())) + (lat1.vec[i + 1][j + 1].getOption() * (bs->q_()))) * 100.0) / 100.0;
				lat1.vec[i][j].set(lat1.vec[i][j].getStock(), op);
			}
			if (c == 'A') {
				//put/call option
				double o = round(exp(-1 * bs->get_RiskFreeRate() * bs->get_Time()) * ((lat1.vec[i + 1][j].getOption() * (1 - bs->q_())) + (lat1.vec[i + 1][j + 1].getOption() * (bs->q_()))) * 100.0) / 100.0;
				double a1 = op.get_payoff(lat1.vec[i][j].getStock(), bs->get_StrikePrice());
				lat1.vec[i][j].set(lat1.vec[i][j].getStock(), max(a1, o));
			}
		}
	}

}

