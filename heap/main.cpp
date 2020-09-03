#include <cstdio>
#include <vector>

using std::vector;

// CHILDREN ARE 2N + 1, 2N + 2 - PARENT N - 1 / 2;

void swap (int from, int to, vector<int>& lat) {
    int store = lat[from];
    lat[from] = lat[to];
    lat[to] = store;
};

class MaxHeap {
public:
    vector<int> store;
    MaxHeap (int val) : store { val } {}

    void log () {
        for (auto i : store) {
            printf("%d, ", i);
        }
        printf("\n");
    }

    void add (int val) {
        store.push_back(val);
        int len = store.size() - 1;
        int my_index = len;
        int parent = (len - 1) / 2;

        while (store[my_index] > store[parent]) {
            swap(my_index, parent, store);
            my_index = parent;
            parent = (my_index - 1) / 2;
        }
    }

    int pop () {
        int result = store.front();
        swap(0, store.size() - 1, store);
        store.erase(store.end() - 1);
        int my_index = 0;
        int child_1 = 1 > store.size() - 1 ? 0 : 1;
        int child_2 = 2 > store.size() - 2 ? 0 : 2;

        while (store[my_index] < store[child_1] || store[my_index] < store [child_2]) {
            int to_switch = store[child_1] > store[child_2] ? child_1 : child_2;
            swap(my_index, to_switch, store);
            my_index = to_switch;
            child_1 = (2 * my_index + 1);
            child_2 = child_1 + 1;
            child_1 = child_1 > store.size() - 1 ? my_index : child_1;
            child_2 = child_2 > store.size() - 1 ? my_index : child_2;
        }
        return result;
    }
};

class MinHeap {
public:
    vector<int> store;
    MinHeap(int val) : store{val} {}

    void log() {
        for (auto i : store) {
            printf("%d, ", i);
        }
        printf("\n");
    }

    void add(int val) {
        store.push_back(val);
        int len = store.size() - 1;
        int my_index = len;
        int parent_index = (len - 1) / 2;

        while (store[my_index] < store[parent_index]) {
            swap(my_index, parent_index, store);
            my_index = parent_index;
            parent_index = (my_index - 1) / 2;
        }
    }

    int pop() {
        int result = store.front();
        swap(0, store.size() - 1, store);
        store.erase(store.end() - 1);
        int my_index = 0;
        int child_1 = 1 > store.size() - 1 ? 0 : 1;
        int child_2 = 2 > store.size() - 1 ? 0 : 2;

        while (store[my_index] > store[child_1] || store[my_index] > store[child_2]) {
            int to_switch = store[child_1] < store[child_2] ? child_1 : child_2;
            swap(my_index, to_switch, store);
            my_index = to_switch;
            child_1 = (2 * my_index + 1);
            child_2 = child_1 + 1;
            child_1 = child_1 > store.size() - 1 ? my_index : child_1;
            child_2 = child_2 > store.size() - 1 ? my_index : child_2;
        }

        return result;
    }
};

int main () {
    MinHeap heep{10};
    heep.add(5);
    heep.add(15);
    heep.add(20);
    heep.add(25);
    heep.add(43);
    heep.add(3);
    heep.add(7);
    heep.add(12);
    heep.log(); heep.pop(); heep.log();
    heep.pop();
    heep.log();

    MaxHeap heep2{20};
    heep2.add(10);
    heep2.add(15);
    heep2.add(12);
    heep2.add(13);
    heep2.add(35);
    heep2.add(35);
    heep2.add(36);
    heep2.add(72);
    heep2.add(14);
    heep2.add(9);
    heep2.log();
    heep2.pop();
    heep2.log();
    heep2.pop();
    heep2.log();
}
