#ifndef LATTICE_H
#define LATTICE_H
#include<vector>
#include"Data.h"
#include<iostream>
using namespace std;

template<class Data, class I, int Type>
class Lattice {//generic lattice structure
public:
	vector<vector<Data>> vec;//vector branch
	I rows;//rows in vector
	I cols;//columns in vector
	I dept;//dept of branch
	int type;//type of tree(Binomial/trinomial etc)

public:
	Lattice();//constructor
	Lattice(const Lattice& l);//deep copy constructor

	Lattice(I dept_, Data val);
	~Lattice();//destructor

	I Col_Size(I dept_);//calculates column size
	I get_row();//return row size
	I get_cols();//return column size
	I get_dept();//return number of branches
	void input(I dept_, Data val);//set default value
	void print();
	void operator=(const Lattice& l);


};
#endif

