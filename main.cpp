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

int main(void) {
	vector<long double> arr = {6.5, 6.6, 6.7, 6.8, 7.1, 7.3, 7.4, 7.7, 7.7, 7.7};
	centralMeasures(arr);
	cout << endl;
	dispersionMeasures(arr);
}
