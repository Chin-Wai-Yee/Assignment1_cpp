#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void) {
	
	double a3, a2, a1, a0, b2, b1, b0, delta, x1, x2, y1, y2, r, s, m, t;
	int num_solution;

	bool proceed = false;

	while (!proceed) {
		cout << "Cubic Equation calculator" << endl;
		cout << "Geral cubic equation form: ax^3 + bx^2 +cx +d = 0" << endl;
		cout << "Please enter the value of a :";
		cin >> a3;
		cout << "Please enter the value of b :";
		cin >> a2;
		cout << "Please enter the value of c :";
		cin >> a1;
		cout << "Please enter the value of d :";
		cin >> a0;
		if (a3 != 0) {
			proceed = true;
		}
		else {
			cout << "Invalid input!" << endl;
			system("pause");
			system("cls");
		}
	}


	b2 = 3 * a3;
	b1 = 2 * a2;
	b0 = a1;

	delta = pow(b1, 2) - (4 * b2 * b0);

	if (delta < 0) {
		num_solution = 1;
	}
	else {
		x1 = (-b1 - pow(delta, 0.5)) / (2 * b2);
		x2 = (-b1 + pow(delta, 0.5)) / (2 * b2);
		y1 = a3 * pow(x1, 3) + a2 * pow(x1, 2) + a1 * x1 + a0;
		y2 = a3 * pow(x2, 3) + a2 * pow(x2, 2) + a1 * x2 + a0;

		if (y1 >= 0 && y2 >= 0) {
			num_solution = 1;
		}
		else if (y1 < 0 && y2 < 0) {
			num_solution = 1;
		}
		else if (y1 == 0 || y2 == 0) {
			num_solution = 2;
		}
		else if (y1 == 0 && y2 == 0) {
			cout << "Precision error";
		}
		else if (y1 >= 0 && y2 < 0) {
			num_solution = 3;
		}
		else if (y1 < 0 && y2 >= 0) {
			num_solution = 3;
		}
	}

	cout << "The number of solution is :" << num_solution << endl;

	if (num_solution == 1) {
		s = 1;
		while (a3 * pow(s, 3) + a2 * pow(s, 2) + a1 * s + a0 <= 0) {
			s *= 2;
		}
		r = -1;
		while (a3 * pow(r, 3) + a2 * pow(r, 2) + a1 * r + a0 >= 0) {
			r *= 2;
		}

		bool stop = false;
		while (!stop) {
			m = (r + s) / 2;
			double y_m;
			y_m = a3 * pow(m, 3) + a2 * pow(m, 2) + a1 * m + a0;
			if (y_m == 0 || abs(s - r) < 0.000001) {
				t = m;
				cout << "The solution is :" << t << endl;
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

	return 0;
}