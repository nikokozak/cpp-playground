#include <iostream>
#include <vector>

using std::vector;

vector<int> merge(vector<int> &a, vector<int> &b) {

    int j, i;
    i = j = 0;

    vector<int> merged{};

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
           merged.push_back(a[i]);
           ++i;
        } else {
            merged.push_back(b[j]);
            ++j;
        }
    }

    while (i < a.size()) {
        merged.push_back(a[i]);
        ++i;
    }

    while (j < b.size()) {
        merged.push_back(b[j]);
        ++j;
    }

    return merged;

}

vector<int> split(int start, int end, vector<int> &lat){

    auto first = lat.begin() + start;
    auto second = lat.begin() + end;

    vector<int> result(first, second);

    return result;

}

vector<int> MergeSort(vector<int> &lat) {

   if (lat.size() > 1) {

      int middle = lat.size() / 2;
      vector<int> left = split(0, middle, lat);
      vector<int> right = split(middle, lat.size(), lat);

      left = MergeSort(left);
      right = MergeSort(right);

      return merge(left, right);

   }

   return lat;

}

int main() {

    vector<int> lat { 8, 6, 3, 8, 3, 2, 1, 7, 8, 9 };

    lat = MergeSort(lat);

    for (auto i : lat) {
        std::cout << i << std::endl;
    }

    return 0;
}
