#include "dispersion.cpp"

long double zScore(vector<long double> vec, long double z) {
    return (z - mean(vec) / standardDeviation(vec));
}
