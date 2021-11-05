#include"Lattice.h"
//#include"Data.h"
template<class Data, class I, int Type>
Lattice<Data, I, Type>::Lattice() {
	rows = 0;
	cols = 0;
	vec.resize(rows);//rows
	for (int i = 0; i < vec.size(); i++) {
		vec[i].resize(cols);//cols
	}
}

template<class Data, class I, int Type>
Lattice<Data, I, Type>::Lattice(I dept_, Data val) {
	int c = Col_Size(dept_);//get column number
	vec.resize(dept_ + 1);//rows
	for (int i = 0; i < vec.size(); i++) {
		vec[i].resize(c);//cols
	}
	rows = dept_ + 1;
	cols = c;
	dept = dept_;
	type = Type;
	this->input(dept_, val);

}

template<class Data, class I, int Type>
void  Lattice<Data, I, Type>::operator=(const Lattice& l) {
	this->vec = l.vec;
	this->rows = l.rows;
	this->cols = l.cols;
	this->dept = l.dept;
	this->type = l.type;
}


template<class Data, class I, int Type>
I Lattice<Data, I, Type>::get_row() {
	return this->rows;
}

template<class Data, class I, int Type>
I Lattice<Data, I, Type>::get_cols() {
	return this->cols;
}

template<class Data, class I, int Type>
Lattice<Data, I, Type>::Lattice(const Lattice& l) {//deep copy
	this->vec = l.vec;
	this->rows = l.rows;
	this->cols = l.cols;
	this->dept = l.dept;
	this->type = l.type;
}

template<class Data, class I, int Type>
I Lattice<Data, I, Type>::get_dept() {
	return this->dept;
}



template<class Data, class I, int Type>
Lattice<Data, I, Type>::~Lattice() {//destructor
}

template<class Data, class I, int Type>
I Lattice<Data, I, Type>::Col_Size(I dept_) {
	type = Type;
	int root = 1; int result = 0; int count = 1; int c = 1;
	result = type - root;
	do {
		c = result + c;
		//for (int i = 0; i < c; i++) {
		//}
		//cout << endl;
		count++;
	} while (count < dept_ + 1);
	this->cols = c;
	return c;
}

template<class Data, class I, int Type>
void Lattice<Data, I, Type>::input(I dept_, Data val) {
	type = Type;
	int root = 1; int result = 0; int count = 1; int c = 1;
	result = type - root;
	this->vec[0][0].set(val.getStock(), val.getOption());
	do {
		c = result + c;
		for (int i = 0; i < c; i++) {
			this->vec[count][i].set(val.getStock(), val.getOption());
		}
		count++;
	} while (count < dept_ + 1);
}


