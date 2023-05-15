#include "methods/probability/discrete.cpp"

int main(void) {
    long double mi = 6;

    long double a = poisson(0, mi);
    long double b = poisson(1, mi);
    long double c = poisson(2, mi) + a + b;
    long double d = poisson(3, mi) - c;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
}
