#include "methods/probability/discrete.cpp"
#include "methods/measures/position.cpp"

using namespace std;

void printArr(vector<long double> arr) {
	cout << "{ ";
	for (long unsigned int i = 0; i < arr.size(); i++) {
		if (i == arr.size() - 1) {
			cout << arr[i] << " ";
		} else {
			cout << arr[i] << ", ";
		}
	}
	cout << "}";
}

void centralMeasures(vector<long double> arr) {
	printArr(arr);
	cout << " {" << endl;
	cout << "\tMean: " << mean(arr) << endl;
	cout << "\tMedian: " << median(arr) << endl;
	cout << "\tMode: " << mode(arr) << endl;
	cout << "\tMedium point: " << mediumPoint(arr) << endl;
	cout << "\tTruncated Mean (10%): " << truncatedMean(arr, 0.1) << endl;
	cout << "\tTruncated Mean (20%): " << truncatedMean(arr, 0.2) << endl;
	cout << "\tHarmonic Mean: " << harmonicMean(arr) << endl;
	cout << "\tQuadratic Mean: " << quadraticMean(arr) << endl;
	cout << "}" << endl;
}

void dispersionMeasures(vector<long double> arr) {
	printArr(arr);
	cout << " {" << endl;
	cout << "\tRange: " << range(arr) << endl;
	cout << "\tMean deviation: " << meanDeviation(arr) << endl;
	cout << "\tstandardDeviation: " << standardDeviation(arr) << endl;
	cout << "\tVariance: " << variance(arr) << endl;
	cout << "\tcoefficientOfVariation: " << coefficientOfVariation(arr) * 100 << "%"<< endl;
	cout << "}" << endl;
}

void positionMeasure(vector<long double> arr, float z) {
	long double arithMean = 7.15;
	long double stdDev = 0.45;
	cout << "Score Z(" << z << ") given array: ";
	printArr(arr);
	cout << ": " << zScore(arr, 6.5);
	cout << endl;
	cout << "Score Z(" << z << ") given Mean(" << arithMean << "), Standard Deviation(" << stdDev << ") = " << zScore(arithMean, stdDev, z) << endl;
}

void measures(long double z) {
	vector<long double> arr = {6.5, 6.6, 6.7, 6.8, 7.1, 7.3, 7.4, 7.7, 7.7, 7.7};
	centralMeasures(arr);
	cout << endl;
	dispersionMeasures(arr);
	cout << endl;
	positionMeasure(arr, z);
	cout << endl;
}

void probability(void) {
	cout << "Geometric: {\n\t" << geometric(7, 0.2) << endl << "}" << endl;
	cout << endl;
	cout << "Hyper-Geometric: {\n\tAll 6 of them: " << hyperGeometric(6, 48, 6, 6) << endl;
	cout << "\tJust 5 of them: " << hyperGeometric(6, 48, 6, 5) << endl;
	cout << "\tJust 3 of them: " << hyperGeometric(6, 48, 6, 3) << endl;
	cout << "\tNone of them: " << hyperGeometric(6, 48, 6, 0) << endl << "}" << endl;
	cout << endl;
	cout << "Multinomial: {\n\t" << multinomial(20, vector<pair<int, double>> {make_pair(5, (float) 1 / 6), make_pair(4, (float) 1 / 6), make_pair(3, (float) 1 / 6), make_pair(2, (float) 1 / 6), make_pair(3, (float) 1 / 6), make_pair(3, (float) 1 / 6)}) << endl << "}" << endl;
	cout << endl;
	cout << "Poisson (Mean: 93 / 100) {\n\t0: " << poisson(0, 93 / 100.0) << endl;
	cout << "\t1: " << poisson(1, 93 / 100.0) << endl;
	cout << "\tUntil 2: " << poisson(0, 93 / 100.0) + poisson(1, 93 / 100.0) + poisson(2, 93 / 100.0) << endl;
	cout << "\tAbove 3: " << 1.0 - (poisson(0, 93 / 100.0) + poisson(1, 93 / 100.0) + poisson(2, 93 / 100.0) + poisson(3, 93 / 100.0)) << endl << "}" << endl;
	cout << endl;
	cout << "Poisson (Mean: 116 / 365) {\n\t0: " << poisson(0,  116 / 365.0) << endl;
	cout << "\t1: " << poisson(1,  116 / 365.0) << endl;
	cout << "\tAbove 1: " << 1.0 - (poisson(0,  116 / 365.0) + poisson(1,  116 / 365.0)) << endl << "}" << endl;
	cout << endl;
}

int main(void) {
	cout << "~~ ~~ MEASURES ~~ ~~ " << endl << endl;
	measures(6.5);
	cout << endl;
	cout << "~~ ~~ PROBABILITIES ~~ ~~ " << endl << endl;
	probability();
	return 0;
}
