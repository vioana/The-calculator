#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <sstream>
#include "EquationSolver.h"
#include "Calculator.h"


const int EquationSolver::MAX_EQUATION_LENGTH;

EquationSolver::EquationSolver() {
	equation = nullptr;
}

EquationSolver::EquationSolver(double a, double b, double c) : a(a), b(b), c(c) {
	buildEquation();
}


EquationSolver::~EquationSolver() {
	delete[] equation;
}

EquationSolver::EquationSolver(const EquationSolver& other) : a(other.a), b(other.b), c(other.c) {
	buildEquation();
}

EquationSolver& EquationSolver::operator=(const EquationSolver& other) {
	if (this != &other) {
		a = other.a;
		b = other.b;
		c = other.c;

		buildEquation();
	}
	return *this;
}
EquationSolver EquationSolver::operator+(const EquationSolver& other) const {

	return EquationSolver(a + other.a, b + other.b, c + other.c);
}

EquationSolver EquationSolver::operator-(const EquationSolver& other) const {

	return EquationSolver(a - other.a, b - other.b, c - other.c);
}

void EquationSolver::solveLinearEquation(double a, double b) {
	if (a == 0) {
		cout << "Invalid: This is not a linear equation." << endl;
		return;
	}

	double solution = -b / a;
	cout << "Linear equation solution: x = " << solution << endl;
}

void EquationSolver::solveQuadraticEquation(double a, double b, double c) {
	Calculator calculator;
	double discriminant = b * b - 4 * a * c;
	if (discriminant > 0) {
		double root1 = (-b + calculator.customRoot(discriminant, 2)) / (2 * a);
		double root2 = (-b - calculator.customRoot(discriminant, 2)) / (2 * a);
		cout << "Quadratic equation solutions: x1 = " << root1 << ", x2 = " << root2 << endl;
	}
	else if (discriminant == 0) {
		double root = -b / (2 * a);
		cout << "Quadratic equation has a repeated solution: x = " << root << endl;
	}
	else {
		double realPart = -b / (2 * a);
		double imaginaryPart = calculator.customRoot(-discriminant, 2) / (2 * a);
		cout << "Quadratic equation solutions: x1 = " << realPart << " + " << imaginaryPart << "i, "
			<< "x2 = " << realPart << " - " << imaginaryPart << "i" << endl;
	}
}

void EquationSolver::buildEquation() {
	ostringstream equationStream;
	equationStream << a << "x^2 + " << b << "x + " << c << " = 0";

	equation = new char[MAX_EQUATION_LENGTH];
	strncpy(equation, equationStream.str().c_str(), MAX_EQUATION_LENGTH - 1);
	equation[MAX_EQUATION_LENGTH - 1] = '\0';
}

const char* EquationSolver::getEquation() const {
	return equation;
}

ostream& operator<<(ostream& os, const EquationSolver& equationSolver) {
	os << equationSolver.getEquation();
	return os;
}

istream& operator>>(istream& is, EquationSolver& equationSolver) {
	cout << "Enter coefficients for the equation:" << endl;
	cout << "a:";
	is >> equationSolver.a;
	cout << "b:";
	is >> equationSolver.b;
	cout << "c:";
	is >> equationSolver.c;

	equationSolver.buildEquation();
	return is;
}
