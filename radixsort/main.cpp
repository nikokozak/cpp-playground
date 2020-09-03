#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

int GetNumDigits (int num) {
    int digits = 0;
    if (num < 0) digits = 1;
    while (num) {
        num /= 10;
        digits++;
    }
    return digits;
}

int GetDigit (int pos, int &num) {
    return (int)(num / pow(10, pos)) % 10;
}

int GetMaxDigits (vector<int> &lat) {
    int maxdigits = 0;
    for (int i : lat) {
        int digits = GetNumDigits(i);
        if (digits > maxdigits) maxdigits = digits;
    }
    return maxdigits;
}

void PopulateBuckets (int digitPlace, vector<int> &lat) {
    vector<int> buckets[10]{};
    for (auto i = 0; i < lat.size(); i++) {
        int digit = GetDigit(digitPlace, lat[i]);
        buckets[digit].push_back(lat[i]);
    }
    vector<int> result{};
    for (auto i = 0; i < 10; i++) {
        result.insert(result.end(), buckets[i].begin(), buckets[i].end());
    }
    lat = result;
}

int main() {

    vector<int> lat{ 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 10, 20, 30 };
    const int MAX_DIGITS = GetMaxDigits(lat);

    for (auto i = 0; i < MAX_DIGITS; i++) {
        PopulateBuckets(i, lat);
    }

    for (auto i : lat) {
        std::cout << i << std::endl;
    }
    return 0;
}