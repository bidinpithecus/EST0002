#include "dispersion.cpp"

long double zScore(vector<long double> vec, long double z) {
    return (z - mean(vec)) / standardDeviation(vec);
}

long double zScore(long double arithMean, long double stdDev, long double z) {
    return (z - arithMean) / stdDev;
}
