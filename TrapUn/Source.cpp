#include "Twin.h"

typedef std::vector<double> vec;

vec gvec(Twin&);
void dvec(Twin&, const vec&);
double trapun(const int&, const vec&, const vec&);

int main() {

	Twin t("Uneven Trapezoidal Rule");

	vec x, y;
	int n;

	t.println("Enter number of subintervals n.");
	t.display();
	std::cin >> n;
	std::cin.ignore(1000, '\n');
	std::cin.clear();

	while (true) {

		t.println("Enter the first element of Vector x.");
		t.println("Example: 2.3");
		t.display();

		double el;
		std::cin >> el;
		std::cin.ignore(1000, '\n');
		std::cin.clear();
		x.push_back(el);

		for (int i = 1; i < n + 1; i++) {
			t.println("Vector x:");
			t.println();
			dvec(t, x);
			t.println("Enter the next element.");
			t.display();

			std::cin >> el;
			std::cin.ignore(1000, '\n');
			std::cin.clear();
			x.push_back(el);
		}

		t.println("Vector x:");
		t.println();
		dvec(t, x);
		t.println("Enter 'x' to save and continue.");
		t.display();

		char in;
		std::cin >> in;
		std::cin.ignore(1000, '\n');
		std::cin.clear();
		if (in == 'x' || in == 'X') break;
		else x.clear();

	}

	while (true) {

		t.println("Enter the first element of Vector y.");
		t.println("Example: 2.3");
		t.display();

		double el;
		std::cin >> el;
		std::cin.ignore(1000, '\n');
		std::cin.clear();
		y.push_back(el);

		for (int i = 1; i < n + 1; i++) {
			t.println("Vector y:");
			t.println();
			dvec(t, y);
			t.println("Enter the next element.");
			t.display();

			std::cin >> el;
			std::cin.ignore(1000, '\n');
			std::cin.clear();
			y.push_back(el);
		}

		t.println("Vector y:");
		t.println();
		dvec(t, y);
		t.println("Enter 'x' to save and continue.");
		t.display();

		char in;
		std::cin >> in;
		std::cin.ignore(1000, '\n');
		std::cin.clear();
		if (in == 'x' || in == 'X') break;
		else y.clear();

	}

	double answer = trapun(n, x, y);

	t.println("Integral = ");
	t.print(answer);
	t.println();
	t.println("Press enter to exit. . .");
	t.display();

	std::cin.ignore(1000, '\n');
	std::cin.clear();

	return EXIT_SUCCESS;
}

double trapun(const int& n, const vec& x, const vec& y) {

	double sum = 0;

	for (int i = 1; i < n + 1; i++)
		sum += (x[i] - x[i - 1]) * (y[i - 1] + y[i]) / 2;

	return sum;
}

vec gvec(Twin& t) {

	vec b;
	double in;
	std::string input;

	std::getline(std::cin, input);
	std::stringstream iss(input);
	iss >> in;
	b.push_back(in);

	while (true) {

		t.println("Vector:");
		t.println();
		dvec(t, b);
		t.println("Enter the next element.");
		t.println("Enter 'x' to save and continue.");
		t.display();

		std::getline(std::cin, input);
		std::stringstream iss(input);
		iss >> in;

		if (input == "x" || input == "X") return b;
		else b.push_back(in);

	}
}

void dvec(Twin& t, const vec& vec) {

	for (auto&& i : vec) {
		t.println("[ ");
		t.print(i);
		t.print(" ]");
	}

	t.println();
}