#include <iostream>
#include <string>
#include "Calculator.h"
#include "Shunting_Yard.h"

using namespace std;

Calculator::Calculator() {
	this->expresie = '\0';
	this->rezultat = '\0';
}

Calculator::Calculator(string expresie) {
	this->expresie = expresie;
	rezultat = '\0';
}

bool Calculator::operator!()
{
	return this->rezultat.empty();
}

char Calculator::operator[](int index)
{
	if (index >= 0 && index < static_cast<int>(rezultat.length())) {
		return rezultat[index];
	}
	else {
		cout << "Invalid index or result is empty." << endl;
		return '\0';
	}
}


void Calculator::setExpresie(string expresie) {
	string expressionWithoutSpaces;
	for (char c : expresie) {
		if (!isspace(c)) {
			expressionWithoutSpaces += c;
		}
	}

	this->expresie = expressionWithoutSpaces;
}

string Calculator::getExpresie() {
	return expresie;
}

void Calculator::calculeaza() {

	Shunting_Yard z;
	z.setExpresie(expresie);
	rezultat = z.calculeaza();

}

string Calculator::getRezultat() {
	return this->rezultat;
}



double parseNumber(const string& rpn, size_t& pos) {
	size_t start = pos;
	while (isdigit(rpn[pos]) || rpn[pos] == '.' || (rpn[pos] == '-' && isdigit(rpn[pos + 1]))) {
		pos++;
	}
	return stod(rpn.substr(start, pos - start));
}

string Calculator::evalRPN(string rpn) {
	Stack operandStack;

	size_t pos = 0;
	while (pos < rpn.length()) {
		if (isdigit(rpn[pos]) || (rpn[pos] == '-' && isdigit(rpn[pos + 1]))) {
			double parsedNumber = parseNumber(rpn, pos);
			operandStack.push(parsedNumber);
		}
		else if (rpn[pos] == ' ') {
			pos++;
		}
		else {
			double operand2 = operandStack.getLastElement();
			operandStack.pop();
			double operand1 = operandStack.getLastElement();
			operandStack.pop();

			switch (rpn[pos]) {
			case '+':
				operandStack.push(operand1 + operand2);
				break;
			case '-':
				operandStack.push(operand1 - operand2);
				break;
			case '*':
				operandStack.push(operand1 * operand2);
				break;
			case '/':
				if (operand2 == 0) {
					return "Error: Division by zero";
				}
				operandStack.push(operand1 / operand2);
				break;
			case '^':
				operandStack.push(customPow(operand1, operand2));
				break;
			case '#':
				operandStack.push(customRoot(operand1, operand2));
				break;
			}
			pos++;
		}
	}

	if (operandStack.getSize() == 1) {
		return to_string(operandStack.getLastElement());
	}
	else {
		return "Error: Invalid expression";
	}
}


double Calculator::customPow(double base, double exponent) {
	if (exponent == 0) {
		return 1.0;
	}

	double result = 1.0;
	bool isNegativeExponent = exponent < 0;

	for (int i = 0; i < abs(exponent); ++i) {
		result *= base;
	}

	return isNegativeExponent ? 1.0 / result : result;
}

double Calculator::customRoot(double base, double exponent) {
	if (base < 0 && static_cast<int>(exponent) % 2 == 0) {
		throw std::domain_error("Error: Even root of a negative number");
	}

	double result = base;

	if (result == 0.0) {
		return 0.0;
	}

	double epsilon = 1e-10;
	double prevResult = 0.0;

	while (abs(result - prevResult) > epsilon) {
		prevResult = result;
		result = ((exponent - 1.0) * result + base / customPow(result, exponent - 1)) / exponent;
	}

	return result;
}


ostream& operator << (ostream& out, Calculator c)
{
	out << "Expresie: " << c.getExpresie() << endl;
	c.calculeaza();
	out << "Rezultat Converie RPN: " << c.getRezultat() << endl;

	out << "Evaluated RPN: " << c.evalRPN(c.getRezultat()) << endl;
	out << endl;

	return out;
}

istream& operator>>(istream& in, Calculator& c) {
	cout << "Expresia:";
	in >> c.expresie;

	return in;
}
