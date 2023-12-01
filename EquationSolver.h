#ifndef EQUATIONSOLVER_H
#define EQUATIONSOLVER_H
#pragma once
#include <iostream>
using namespace std;

class EquationSolver {
private:
	static const int MAX_EQUATION_LENGTH = 100;
	double a, b, c;
	char* equation;

	void buildEquation();

public:
	EquationSolver();
	EquationSolver(double a, double b, double c);
	~EquationSolver();

	EquationSolver(const EquationSolver& other);
	EquationSolver& operator=(const EquationSolver& other);

	EquationSolver operator+(const EquationSolver& other) const;
	EquationSolver operator-(const EquationSolver& other) const;
	static void solveLinearEquation(double a, double b);
	static void solveQuadraticEquation(double a, double b, double c);

	const char* getEquation() const;

	friend ostream& operator<<(ostream& os, const EquationSolver& equationSolver);

	friend istream& operator>>(istream& is, EquationSolver& equationSolver);
};
ostream& operator<<(ostream& os, const EquationSolver& equationSolver);
istream& operator>>(istream& is, EquationSolver& equationSolver);

#endif
