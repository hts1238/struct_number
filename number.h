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

        reduce();
    }

    double norm() {
        return (double) num / den;
    }

    Number operator + (Number& o) {
        return Number(num*o.den + den*o.num, den*o.den);
    }

    Number operator - (Number& o) {
        Number n(-o.num, o.den);
        return *this + n;
    }

    Number operator * (Number& o) {
        
    }

private:
    void reduce() {
        int _gcd = gcd(num, den);
        num /= _gcd;
        den /= _gcd;
    }

    int gcd(int a, int b) {
        a = abs(a);
        b = abs(b);
        
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

ostream& operator << (ostream& cout, const Number& n) {
    if (n.den == 1) {
        cout << n.num;
    } else {
        cout << n.num << "/" << n.den;
    }
    return cout;
}

istream& operator >> (istream& cin, Number& n) {
    int val;
    cin >> val;
    n = Number(val);
}

#endif