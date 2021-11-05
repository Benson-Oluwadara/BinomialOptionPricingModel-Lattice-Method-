#ifndef BINOMIALLATTICESTRATEGY_H
#define BINOMIALLATTICESTRATEGY_H
class BinomialLatticeStrategy {
protected:
	double S;//stock price
	double K;//strike price
	double R;//Risk free rate
	double T;//time in years
	double V;//volatility
	double disc;//discounting

	double U;//up state
	double D;//down state
	double q;//probablilty

public:
	BinomialLatticeStrategy();
	~BinomialLatticeStrategy();
	BinomialLatticeStrategy(double S_, double K_, double R_, double T_, double V_);
	BinomialLatticeStrategy(const BinomialLatticeStrategy& b);
	double get_StockPrice();
	double get_StrikePrice();
	double get_RiskFreeRate();
	double get_Time();
	double get_VOlatility();
	double U_();
	double D_();
	double q_();
	double get_discount();


};
#endif


