#ifndef option_H
#define option_H
class option {
private:
	double stock;
	double strike;
	char type;
public:
	option();//constructor
	~option();//destructor
	option(double st, double k, char c);//double argument
	double get_payoff(double st, double k);//claculates payoff at bottom node


};

#endif
