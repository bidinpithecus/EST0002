#include <iostream>
#include <cmath>

using namespace std;

unsigned int fact(unsigned int n) {
    unsigned int res = 1;
    for (unsigned int i = 2; i <= n; i++)
        res *= i;
    return res;
}

long double binomial(long double x, int n, long double p, long double q) {
    return (fact(n) * pow(p, x) * pow(q, n - x)) / (fact(n - x) * fact(x));
}

/*
	'p' is the probability of success;
	'x' is where I want my first success.
*/
long double geometric(long double x, long double p) {
    return p * pow(1 - p, x - 1);
}

/*
	Depends on previous probabilities
	'a' is the amount of things chosen
	'b' is the amount of things that I didn't choose, (total - a)
	'n' is the amount of proofs
	'x'	is the amount of success I need
*/
long double hyperGeometric(int a, int b, int n, int x) {
	long double A = (long double) fact(a) / (fact(a - x) * fact(x));
	cout << endl << "A: " << A << endl;
	cout << fact(b);
	long double B = (long double) fact(b) / (fact(b - n + x) * fact(n - x));
	cout << "B: " << B << endl;
	long double AB = (long double) fact(a + b) / (fact(a + b - n) * fact(n));
	cout << "A+B: " << AB << endl;
    return (A * B) / AB;
}

long double multinomial(int n, long double x1, long double x2, long double x3) {
    return  (long double) fact(n) / (fact(x1) * fact(x2) * fact(x3));
}

long double poisson(int x, long double mi) {
    return (pow(mi, x) * pow(M_E, -mi)) / (fact(x));
}
