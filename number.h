#ifndef NUMBER_H_INCLUDED
#define NUMBER_H_INCLUDED

#include <bits/stdc++.h>

using namespace std;

struct Number {
public:
	int num;
	int den;

	Number() {
		num = 0;
		den = 1;
	}

	Number(const int& n) {
		num = n;
		den = 1;
	}

	Number(const int& n, const int& d) {
		if (d == 0) {
			cout << "Error: Division by zero at initialization. Denominator can not be zero\n";
			exit(1);
		}
		num = n;
		den = d;
	}

	double normal() {
		return (double) num / den;
	}

private:
	int gcd(int a, int b) {
		while (b) {
			a %= b;
			swap(a, b);
		}
		return a;
	}

	int lcm(int& a, int& b) {
		return a * b / gcd(a, b);
	}
};

ostream& operator << (ostream& cout, Number& n) {
	if (n.den == 1) {
		cout << n.num;
	} else {
		cout << n.num << "/" << n.den;
	}
	return cout;
}

#endif