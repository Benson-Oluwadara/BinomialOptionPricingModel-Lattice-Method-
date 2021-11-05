#include "option.h"
option::option() {
	stock = 0.0;
	strike = 0.0;
	type = ' ';
}
option::option(double st, double k, char c) {
	stock = st;
	strike = k;
	type = c;
}
double option::get_payoff(double st, double k) {
	if (type == 'c') {

		return st > k ? st - k : 0.0;
	}
	else if (type == 'p') {
		return st < k ? -(st - k) : 0.0;
	}
	return 0.0;
}
option::~option() {
}

