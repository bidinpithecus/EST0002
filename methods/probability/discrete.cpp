#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

unsigned int binomialCoeffs(int n, int k) {
	return (k == 0 || n == k) ? 1 : binomialCoeffs(n - 1, k - 1) + binomialCoeffs(n - 1, k);
}

unsigned long int fact(unsigned long int n) {
    return (n <= 1) ? 1 : n * exp(lgamma(n));
}

long double divFact(unsigned int n, unsigned int k) {
    return ((long double) n / k) * exp(lgamma(n) - lgamma(k));
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
double hyperGeometric(int a, int b, int n, int x) {
	int A = binomialCoeffs(a, x);
	int B = binomialCoeffs(b, n - x);
	int AB = binomialCoeffs(a + b, n)	;
    return (double) (A * B) / AB;
}

long double multinomial(int n, vector<pair<int, double>> xp) {
	unsigned long int nFact = fact(n);
	long double factors = 1;
	unsigned long int facts = 1;

	for (auto pair : xp) {
		factors *= powf(pair.second, pair.first);
		facts *= fact(pair.first);
	}

	return (long double) nFact * factors / facts;
}

long double poisson(int x, long double mi) {
    return (pow(mi, x) * pow(M_E, -mi)) / (fact(x));
}
