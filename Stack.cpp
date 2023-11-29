#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

Stack::Stack() {
	array = nullptr;
	nrLungime = 0;
}

Stack::Stack(double* array, int nrLungime) {
	if (array != nullptr) {
		this->array = new double[nrLungime];
		for (int i = 0; i < nrLungime; i++) {
			this->array[i] = array[i];
		}
	}

	this->nrLungime = nrLungime;
}

Stack::~Stack() {
	if (array != nullptr) {
		delete[] array;
		array = nullptr;
	}
}

Stack::Stack(const Stack& s) {
	if (s.array != nullptr && s.nrLungime > 0) {
		nrLungime = s.nrLungime;
		array = new double[nrLungime];
		for (int i = 0; i < nrLungime; i++) {
			array[i] = s.array[i];
		}
	}
	else {
		array = nullptr;
		nrLungime = 0;
	}
}

Stack& Stack::operator=(const Stack& s) {
	if (this != &s) {
		if (array != nullptr) {
			delete[] array;
			array = nullptr;
		}

		if (s.array != nullptr && s.nrLungime > 0) {
			array = new double[s.nrLungime];
			for (int i = 0; i < s.nrLungime; i++) {
				array[i] = s.array[i];
			}
			nrLungime = s.nrLungime;
		}
	}
	return *this;
}



Stack Stack::operator+(const Stack& s) {
	Stack copie;
	copie.nrLungime = this->nrLungime + s.nrLungime;

	copie.array = new double[copie.nrLungime];

	for (int i = 0; i < this->nrLungime; i++) {
		copie.array[i] = this->array[i];
	}

	for (int i = 0; i < s.nrLungime; i++) {
		copie.array[this->nrLungime + i] = s.array[i];
	}

	return copie;
}


void Stack::push(double element) {
	double* temp = new double[nrLungime];
	for (int i = 0; i < nrLungime; i++) {
		temp[i] = array[i];
	}
	delete[] array;

	nrLungime++;
	array = new double[nrLungime];
	for (int i = 0; i < nrLungime - 1; i++) {
		array[i] = temp[i];
	}
	delete[] temp;

	array[nrLungime - 1] = element;
	size++;
}

void Stack::pop() {
	if (!isEmpty()) {
		double* temp = new double[nrLungime];
		for (int i = 0; i < nrLungime; i++) {
			temp[i] = array[i];
		}
		delete[] array;

		nrLungime--;
		array = new double[nrLungime];

		for (int i = 0; i < nrLungime; i++) {
			array[i] = temp[i];
		}
		delete[] temp;
		size--;
	}
}

bool Stack::isEmpty() {
	return nrLungime == 0;
}

void Stack::getArray() {
	if (nrLungime != 0) {
		cout << nrLungime << endl << endl;
		for (int i = 0; i < nrLungime; i++) {
			cout << array[i] << " " << endl;
		}
	}
	else {
		cout << "Array-ul nu contine elemente!" << endl;
	}
}

double Stack::getLastElement() {
	return (nrLungime > 0) ? array[nrLungime - 1] : 0.0;
}

int Stack::getSize() {
	return size;
}

void Stack::setArray(double* array, int nrLungime) {
	if (array != nullptr && nrLungime > 0) {
		if (this->array != nullptr) {
			delete[] this->array;
		}

		this->array = new double[nrLungime];
		this->nrLungime = nrLungime;
		for (int i = 0; i < nrLungime; i++) {
			this->array[i] = array[i];
		}
	}
}

ostream& operator<<(ostream& out, Stack& s) {
	out << "Lungimea:" << s.nrLungime << endl;

	for (int i = 0; i < s.nrLungime; i++) {
		out << s.array[i] << " ";
	}

	out << endl;
	return out;
}

istream& operator>>(istream& in, Stack& s) {
	cout << "Lungime:";
	int nr;
	in >> nr;
	cout << endl;

	double* arrayCitire = new double[s.nrLungime];
	for (int i = 0; i < s.nrLungime; i++) {
		cout << "array[" << i << "]=";
		in >> arrayCitire[i];
	}

	s.setArray(arrayCitire, nr);
	delete[] arrayCitire;
	return in;
}
