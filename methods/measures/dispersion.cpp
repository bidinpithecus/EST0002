#include "central.cpp"

long double range(vector<long double> vec) {
    sort(vec.begin(), vec.end());

    return fabs(vec.at(0) - vec.at(vec.size() - 1)) ;
}

long double meanDeviation(vector<long double> vec) {
	long double vecMean = mean(vec);
	long double result = 0.0;

	for (auto num : vec) {
		result += abs(num - vecMean);
	}

	return result / vec.size();
}

long double standardDeviation(vector<long double> vec) {
    long double vecMean = mean(vec);
    long double result = 0.0;

    for (long double num : vec) {
        result += pow(num - vecMean, 2);
    }

    return sqrt(result / vec.size());
}

long double variance(vector<long double> vec) {
    return standardDeviation(vec) * standardDeviation(vec);
}

long double coefficientOfVariation(vector<long double> vec) {
    return standardDeviation(vec) / mean(vec);
}
