#include <iostream>
#include <vector>

using std::vector;

vector<int> split(int lo, int hi, vector<int> &lat) {
    auto locut = lat.begin() + lo;
    auto hicut = lat.begin() + hi;
    vector<int> sublat (locut, hicut);
    return sublat;
}

vector<int> merge (vector<int> &a, vector<int> &b) {
    vector<int> result{};
    int i, j;
    i = j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            result.push_back(a[i]);
            ++i;
        } else {
            result.push_back(b[j]);
            ++j;
        }
    }
    while (i < a.size()) {
        result.push_back(a[i]);
        ++i;
    }
    while (j < b.size()) {
        result.push_back(b[j]);
        ++j;
    }
    return result;
}

vector<int> mergesort (vector<int> &lat) {
    if (lat.size() > 1) {
        int mid = lat.size() / 2;
        vector<int> left = split(0, mid, lat);
        vector<int> right = split(mid, lat.size(), lat);

        left = mergesort(left);
        right = mergesort(right);

        return merge(left, right);
    }
    return lat;
}

int main() {
    vector<int> lat{ 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    vector<int> sorted = mergesort(lat);
    for (auto i : sorted) {
        std::cout << i << std::endl;
    }
}