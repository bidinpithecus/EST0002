#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>

#define FLOOR 0
#define CEIL 1

using namespace std;
typedef std::pair<long double, std::size_t> MapEntry;

long double mean(vector<long double> vec) {
    long double result = 0.0;
    for (long double num : vec) {
        result += num;
    }
    return result / vec.size();
}

long double median(vector<long double> vec) {
    sort(vec.begin(), vec.end());

    // odd
    if (vec.size() % 2) {
        return vec.at(vec.size() / 2);
    }
    // even
    return (vec.at((vec.size() / 2) - 1) + vec.at(vec.size() / 2)) / 2.0;
}

long double mode(vector<long double>& vec) {
    // A map to store frequency count of each unique element in vector
    unordered_map<long double, size_t> freqMap;
    // Populate the map with freq count of each element
    for_each(
            vec.begin(),
            vec.end(),
            [&](long double& elem){
                freqMap[elem]++;
            });
    // Get the map element with maximum frequency count
    auto result = max_element(
                        freqMap.begin(),
                        freqMap.end(),
                        [](MapEntry left, MapEntry right) {
                            return left.second < right.second;
                        });
    return result->first;
}

long double mediumPoint(vector<long double> vec) {
    sort(vec.begin(), vec.end());

    return (vec.at(0) + vec.at(vec.size() - 1)) / 2.0;
}

long double truncatedMean(vector<long double> vec, long double percentage, int decision) {
    sort(vec.begin(), vec.end());
    long unsigned int removedNum = vec.size() * percentage;
    long double result = 0.0;

    for (long unsigned int i = removedNum, j = 0; i < vec.size() - removedNum; i++) {
        result += vec.at(i);
    }

    return result / (vec.size() - (2 * (removedNum)));
}

long double harmonicMean(vector<long double> vec) {
    long double result = 0.0;
    for (long double num : vec) {
        result += (1 / num);
    }

    return vec.size() / result;
}

long double geometricMean(vector<long double> vec) {
    long double result = 1.0;
    for (long double num : vec) {
        num /= 100.0;
        result *= num;
    }

    return pow(result, 1 / vec.size());
}

long double quadraticMean(vector<long double> vec) {
    long double result = 0.0;
    for (long double num : vec) {
        result += pow(num, 2);
    }

    return sqrt(result / vec.size());
}
