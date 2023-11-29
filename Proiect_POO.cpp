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

			cin.ignore(); // Ignore the newline character in the input buffer
		}
		else {
			cout << "Invalid option. Please choose 1, 2, or 3." << endl;
		}
	}

	/*EquationSolver eq1(2, 3, 4);
	EquationSolver eq2(1, 2, 1);

	EquationSolver sum = eq1 + eq2;
	EquationSolver difference = eq1 - eq2;

	cout << "Sum: " << sum << endl;
	cout << "Difference: " << difference << endl;

	Stack stack1, stack2;

	stack1.push(1.1);
	stack1.push(2.2);
	stack1.push(3.3);

	stack2.push(4.4);
	stack2.push(5.5);
	stack2.push(6.6);

	// Use the overloaded + operator to add the two stacks
	Stack sumStack = stack1 + stack2;

	cout << "Stack 1:" << endl << stack1;
	cout << "Stack 2:" << endl << stack2;
	cout << "Sum of Stack 1 and Stack 2:" << endl << sumStack;

	// Use the overloaded = operator to assign one stack to another
	Stack assignedStack;
	assignedStack = stack1;

	cout << "Original Stack 1:" << endl << stack1;
	cout << "Assigned Stack:" << endl << assignedStack;


	// Test operator() and operator string()
	Shunting_Yard shuntingYard;
	shuntingYard("3+5*(2+6)");
	Shunting_Yard sy2("3+5*(2+6)");

	// Print the original expression and the result
	cout << "Original Expression: " << shuntingYard.getExpresie() << endl;

	if (shuntingYard == sy2) {
		cout << "The expressions are equal." << endl;
	} else {
		cout << "The expressions are not equal." << endl;
	}


	Calculator calc;

	calc.setExpresie("3+5*(2-6)");

	calc.calculeaza();

	// Check the ! operator
	if (!calc) {
		cout << "The result is empty." << endl;
	} else {
		cout << "The result is not empty." << endl;
	}

	// Check the [] operator for characters
	char charAtIndex = calc[0];
	if (charAtIndex != '\0') {
		cout << "Character at index 0: " << charAtIndex << endl;
	} else {
		cout << "Invalid index or result is empty." << endl;
	}


	cout << "Original Expression: " << calc.getExpresie() << endl;
	cout << "Result: " << calc.evalRPN(calc.getRezultat()) << endl;*/

	return 0;
}
