#ifndef NUMBER_H_INCLUDED
#define NUMBER_H_INCLUDED

#include <bits/stdc++.h>

using namespace std;

struct Number {
public:

    long long num;
    long long den;

    Number() {
        num = 0;
        den = 1;
    }

    Number(const long long& n) {
        num = n;
        den = 1;
    }

    Number(const long long& n, const long long& d) {
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

    Number operator + (const Number& o) {
        return Number(num*o.den + den*o.num, den*o.den);
    }

    Number operator + (const long long& o) {
        return Number(num + o*den, den);
    }

    Number operator - (const Number& o) {
        Number n(-o.num, o.den);
        return *this + n;
    }

    Number operator * (const Number& o) {
        return Number(num * o.num, den * o.den);
    }

private:
    void reduce() {
        int _gcd = gcd(num, den);
        num /= _gcd;
        den /= _gcd;
    }

    int gcd(long long a, long long b) {
        a = abs(a);
        b = abs(b);
        
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    int lcm(long long& a, long long& b) {
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