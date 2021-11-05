#ifndef DATA_H
#define DATA_H
class Data {
protected:
	double stock;//stock price data
	double option;//option price data
public:
	Data();
	~Data();
	Data(double st, double op);
	void set(double st, double op);
	double getStock();
	double getOption();

};
#endif

