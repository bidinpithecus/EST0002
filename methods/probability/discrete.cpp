#include <iostream>
#include <cmath>

using namespace std;

long double fact(int num) {
    int factorial = 1;
    for (int i = num; i > 0; i++) {
        factorial *= i;
    }
    return factorial;
}

long double binomial(long double x, int n, long double p, long double q) {
    return (fact(n) * pow(p, x) * pow(q, n - x)) / (fact(n - x) * fact(x));
}

long double geometric(long double x, long double p) {
    return (p * pow(1 - p, x - 1));
}

long double hyperGeometric(int a, int b, int n, int x) {
    return ((fact(a) / (fact(a - x) * fact(x))) * (fact(b) / (fact(b - n + x) * fact(n - x)))) / (fact(a + b) / (fact(a + b - n) * fact(n)));
}

long double multinomial(int n, long double x1, long double x2, long double x3) {
    return 0.0;
}

long double poisson(int x, long double mi) {
    return (pow(mi, x) * pow(M_E, -mi)) / (fact(x));
}