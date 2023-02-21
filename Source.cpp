#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void) {
	
	/// declaration of vaiables
	double a3, a2, a1, a0, b2, b1, b0, delta, x1, x2, y1, y2, r, s, m, t;
	int num_solution;
	bool stop;

	/// display the title of calculator
	cout << "Cubic Equation calculator" << endl;
	cout << "Geral cubic equation form: ax^3 + bx^2 +cx +d = 0" << endl;

	/// ask for user input for a3, a2, a1, and a0
	cout << "Please enter the value of a :";
	cin >> a3;
	cout << "Please enter the value of b :";
	cin >> a2;
	cout << "Please enter the value of c :";
	cin >> a1;
	cout << "Please enter the value of d :";
	cin >> a0;

	/// if a3 is no greater than 0, terminate
	if (a3 <= 0) {
		cout << "Invalid input!" << endl;
		system("pause");
		return 1;
	}

	/// differentiation of the cubic function
	b2 = 3 * a3;
	b1 = 2 * a2;
	b0 = a1;

	delta = pow(b1, 2) - (4 * b2 * b0);

	/// check for number of solution for each case
	if (delta < 0) {
		num_solution = 1;
	}
	else {
		/// finding solution for turning point(s)
		x1 = (-b1 - pow(delta, 0.5)) / (2 * b2);
		x2 = (-b1 + pow(delta, 0.5)) / (2 * b2);
		y1 = a3 * pow(x1, 3) + a2 * pow(x1, 2) + a1 * x1 + a0;
		y2 = a3 * pow(x2, 3) + a2 * pow(x2, 2) + a1 * x2 + a0;

		/// determine the number of solution
		if (y1 >= 0 && y2 >= 0) {
			num_solution = 1;
		}
		if (y1 < 0 && y2 < 0) {
			num_solution = 1;
		}
		if (y1 == 0 || y2 == 0) {
			num_solution = 2;
		}
		if (y1 == 0 && y2 == 0) {
			cout << "Precision error";
		}
		if (y1 >= 0 && y2 < 0) {
			num_solution = 3;
		}
		if (y1 < 0 && y2 >= 0) {
			num_solution = 3;
		}
	}

	/// display the number of solution
	cout << "The number of solution is :" << num_solution << endl;

	/// if there are only 1 solution, calculate value of the solution
	if (num_solution == 1) {

		/// extended binary search
		s = 1;
		while (a3 * pow(s, 3) + a2 * pow(s, 2) + a1 * s + a0 <= 0) {
			s *= 2;
		}
		r = -1;
		while (a3 * pow(r, 3) + a2 * pow(r, 2) + a1 * r + a0 >= 0) {
			r *= 2;
		}

		/// calculate the value
		stop = false;
		while (!stop) {
			m = (r + s) / 2;
			double y_m;
			y_m = a3 * pow(m, 3) + a2 * pow(m, 2) + a1 * m + a0;
			if (y_m == 0 || abs(s - r) < 0.000001) {
				t = m;
				/// display the value of solution
				cout << "The solution is :" << fixed << setprecision(6) << t << endl;
				stop = true;
			}
			else if (y_m > 0) {
				s = m;
			}
			else if (y_m < 0) {
				r = m;
			}
		}
	}

	system("pause");

	/// program ended, terminate
	return 0;
}