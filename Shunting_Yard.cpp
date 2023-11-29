#include <iostream>
#include <string>
#include "Shunting_Yard.h"
using namespace std;

Shunting_Yard::Shunting_Yard() : expresie(""), rezultat(""), operatorStack() {}

Shunting_Yard::Shunting_Yard(string expresie) : expresie(expresie), rezultat(""), operatorStack() {}

void Shunting_Yard::operator()(string expresie) {
	this->expresie = expresie;
}

bool Shunting_Yard::operator==(const Shunting_Yard& other) {
	return this->expresie == other.expresie && this->rezultat == other.rezultat;
}

int Shunting_Yard::validareTip(char op) {
	if (isdigit(op) || op == '.') {
		return 0;
	}
	else if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^' || op == '#') {
		return 1;
	}
	else if (op == '(' || op == '[') {
		return 2;
	}
	else if (op == ')' || op == ']') {
		return 3;
	}
	else {
		return 10;
	}
}

int Shunting_Yard::prioritate(char op) {
	if (op == '+' || op == '-') {
		return 1;
	}
	else if (op == '*' || op == '/') {
		return 2;
	}
	else if (op == '^' || op == '#') {
		return 3;
	}
	else {
		return -1;
	}
}

string Shunting_Yard::calculeaza() {
	while (!expresie.empty()) {
		if (validareTip(expresie[0]) == 0) {
			rezultat += expresie[0];
			expresie.erase(0, 1);
		}
		else if (validareTip(expresie[0]) == 1) {
			rezultat += " ";
			while (validareTip(operatorStack.getLastElement()) != 2 &&
				prioritate(expresie[0]) <= prioritate(operatorStack.getLastElement())) {
				rezultat += operatorStack.getLastElement();
				rezultat += " ";
				operatorStack.pop();
			}
			operatorStack.push(expresie[0]);
			expresie.erase(0, 1);
		}
		else if (validareTip(expresie[0]) == 2) {
			operatorStack.push(expresie[0]);
			expresie.erase(0, 1);
		}
		else if (validareTip(expresie[0]) == 3) {
			while (validareTip(operatorStack.getLastElement()) != 2) {
				rezultat += operatorStack.getLastElement();
				rezultat += " ";
				operatorStack.pop();

				if (validareTip(operatorStack.getLastElement()) == 2) {
					operatorStack.pop();
					break;
				}
			}
			expresie.erase(0, 1);
		}
	}

	while (!operatorStack.isEmpty()) {
		if (validareTip(operatorStack.getLastElement()) == 2 ||
			validareTip(operatorStack.getLastElement()) == 3) {
			exit(404);
		}
		rezultat += operatorStack.getLastElement();
		rezultat += " ";
		operatorStack.pop();
	}

	return rezultat;
}

string Shunting_Yard::getRezultat() {
	return rezultat;
}

void Shunting_Yard::setExpresie(string expresie) {
	this->expresie = expresie;
}

string Shunting_Yard::getExpresie() {
	return expresie;
}

ostream& operator<<(ostream& out, Shunting_Yard& sy) {
	out << "Expresia: " << sy.getExpresie() << endl;
	sy.calculeaza();
	out << "Rezultat: " << sy.getRezultat() << endl;
	out << endl;
	return out;
}

istream& operator>>(istream& in, Shunting_Yard& sy) {
	cout << "Expresia: ";
	in >> sy.expresie;
	return in;
}
