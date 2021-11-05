#ifndef BinomialMethod_H
#define BinomialMethod_H
#include"BinomialLatticeStrategy.h"
#include"Lattice.h"
#include"option.h"
#include<vector>
class BinomialMethod {
private:
	BinomialLatticeStrategy* bs;
	Lattice<Data, int, 2> lat1;
	option op;
	char c;
public:
	BinomialMethod();
	~BinomialMethod();
	void Interface(double S_, double K_, double R_, double T_, double V_, int branch, char optType, char ty);
	double put_Payoff(double st, double k);
	void ForwardInduction();
	void print();
	double max(double a, double b);
	void BackwardInduction();

};
#endif


