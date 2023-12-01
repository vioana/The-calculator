#ifndef SCIENTIFIC_CALCULATOR_STACK_H
#define SCIENTIFIC_CALCULATOR_STACK_H

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
	double* array;
	int nrLungime;
	int size;

public:
	Stack();
	Stack(double* array, int nrLungime);
	~Stack();
	Stack(const Stack& s);
	Stack& operator=(const Stack& s);
	Stack operator+(const Stack& s);
	void push(double element);
	void pop();
	bool isEmpty();
	void getArray();
	double getLastElement();
	int getSize();
	void setArray(double* array, int nrLungime);
	friend ostream& operator<<(ostream& out, Stack& s);
	friend istream& operator>>(istream& in, Stack& s);
};

ostream& operator<<(ostream& out, Stack& s);
istream& operator>>(istream& in, Stack& s);

#endif 
