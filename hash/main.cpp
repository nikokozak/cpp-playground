#include <iostream>
#include <cstring>
#include <vector>
#include <tuple>

using std::vector;

class HashMap {
public:
    vector<std::tuple<const char*, int>> store[13];

    int hash (const char* lat, int target_len) const {
       int result{};
       for (auto i = 0; i < strlen(lat) - 1; i++) {
           result += (int)lat[i];
       }
       result *= 31;
       result %= target_len;
       return result;
    }

    int operator[](const char* name){
        return get(name);
    }

    bool add (const char* name, int value) {
        int index = hash(name, 13);
        if (exists(index, name)) { return false; }
        store[index].push_back(std::tuple<const char*, int>(name, value));
    }

    int get (const char* name) {
        int index = hash(name, 13);
        if (!exists(index, name)) { return -1; }
        for (auto i : store[index]) {
            if (name == std::get<0>(i)) {
                std::cout << std::get<1>(i) << std::endl;
                return std::get<1>(i);
            }
        }
    }

    vector<const char*> keys () {
        vector<const char*> result{};
        for (auto i : store) {
            for (auto j : i) {
                result.push_back(std::get<0>(j));
                std::cout << std::get<0>(j) << std::endl;
            }
        }
        return result;
    }

    vector<int> values () {
        vector<int> result {};
        for (auto i : store) {
            for (auto j : i) {
                result.push_back(std::get<1>(j));
                std::cout << std::get<1>(j) << std::endl;
            }
        }
        return result;
    }

    void log () {
        for (auto i : store) {
            for (auto j : i) {
                std::cout << std::get<0>(j) << ": " << std::get<1>(j) << std::endl;
            }
        }
    }

private:
    bool exists (int index, const char* name) {
        for (auto i : store[index]) {
            if (name == std::get<0>(i)) { return true; }
        }
        return false;
    }

};

int main() {

    HashMap hash;
    hash.add("pink", 25);
    hash.add("purple", 33);
    hash.add("blue", 35);
    hash.add("orange", 15);

    hash.log();

    hash["pink"];
    hash["purple"];
    hash["blue"];
    hash["sweet"];

    hash.keys();
    hash.values();

}


