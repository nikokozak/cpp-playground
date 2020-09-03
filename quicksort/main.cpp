#include <iostream>
#include <vector>

using std::vector;

void swap (int a, int b, vector<int> &lat) {

    int store = lat[a];
    lat[a] = lat[b];
    lat[b] = store;

}

int partition (int lo, int hi, vector<int> &lat) {
    int pivot = lat[(hi + lo) / 2];

    while (true) {

        while (lat[lo] < pivot) {
            ++lo;
        }
        while (lat[hi] > pivot) {
            --hi;
        }
        if (lo >= hi) {
            return hi;
        }
        swap(lo, hi, lat);
        ++lo;
        --hi;

    }
}

void quicksort (int lo, int hi, vector<int> &lat) {
    if (lo < hi) {
        int boundary = partition(lo, hi, lat);
        quicksort(lo, boundary, lat);
        quicksort(boundary + 1, hi, lat);
    }
}

int main () {
    vector<int> lat{9, 8, 7, 5, 4, 2, 3, 4, 5, 7, 8, 9, 10};
    quicksort(0, lat.size() - 1, lat);
    for (auto i : lat) {
        std::cout << i << std::endl;
    }
}
