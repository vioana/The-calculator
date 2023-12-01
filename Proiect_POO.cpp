#include <iostream>
#include <string>
#include "Calculator.h"
#include "EquationSolver.h"
#include "Shunting_Yard.h"

using namespace std;

int main() {
	string input;
	Calculator c;

	while (true) {
		cout << "Calculator Menu:" << endl;
		cout << "1. Perform a normal calculation" << endl;
		cout << "2. Solve an equation" << endl;
		cout << "3. Exit" << endl;
		cout << "Choose an option (1, 2, or 3): ";
		getline(cin, input);

		if (input == "3" || input == "exit") {
			break;
		}
		else if (input == "1") {
			cout << "Enter expression:";
			getline(cin, input);
			c.setExpresie(input);
			c.calculeaza();
			cout << "Result:\n" << c << endl;
		}
		else if (input == "2") {
			cout << "Enter coefficients for the equation:" << endl;
			cout << "a:";
			double a;
			cin >> a;
			cout << "b:";
			double b;
			cin >> b;
			cout << "c:";
			double cVal;
			cin >> cVal;

			if (a == 0) {
				EquationSolver::solveLinearEquation(b, cVal);
			}
			else {
				EquationSolver::solveQuadraticEquation(a, b, cVal);
			}

			cin.ignore(); 
		}
		else {
			cout << "Invalid option. Please choose 1, 2, or 3." << endl;
		}
	}
	return 0;
}
