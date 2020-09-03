#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <tuple>
#include <stdexcept>

template <typename T, typename X> // T defines names, X is weight values.
class Graph {
private:
    std::unordered_map<T, std::unordered_map<T, X>> store;

public:
    void add_node (T name) {
        if (store.find(name) == store.end()) {
            store[name];
        }
    }

    void add_edges (T target, std::vector<T> names, std::vector<X> weights) {
        if (names.size() != weights.size()) { throw std::domain_error("There must be an equal number of weights and edges!"); }
        if (store.find(target) != store.end()) {
            for (auto i = 0; i < names.size(); i++) {
                if (store.find(names[i]) != store.end()) {
                    store[target][names[i]] = weights[i];
                    store[names[i]][target] = weights[i];
                }
            }
        }
    }

    void log () {
        for (auto i = store.begin(); i != store.end(); i++) {
            std::cout << i -> first << ": ";
            for (auto j = (i -> second).begin(); j != (i -> second).end(); j++) {
                std::cout << j -> first << "{" << j-> second << "}" << ", ";
            }
            std::cout<<std::endl;
        }
    }
};

void swap_heap (int from, int to, std::vector<std::tuple<const char*, int>>& lat) {
    std::tuple store = lat[from];
    lat[from] = lat [to];
    lat[to] = store;
}

class MinHeap {

    std::vector<std::tuple<const char*, int>> store;

public:

    MinHeap () : store {} {}

    void insert (const char* name, int weight) {
       store.push_back(std::tuple<const char*, int>{ name, weight });
       int my_index = store.size() - 1;
       int parent_index = (my_index - 1) / 2;
       while (std::get<1>(store[my_index]) < std::get<1>(store[parent_index])) {
            swap_heap(my_index, parent_index, store);
            my_index = parent_index;
            parent_index = (my_index - 1) / 2;
       }
    }

    std::tuple<const char*, int> pop () {
        std::tuple<const char*, int> result = store.front();
        swap_heap(0, store.size() - 1, store);
        store.erase(store.end() - 1);
        int my_index = 0;
        int child_1 = 1 > store.size() - 1 ? 0 : 1;
        int child_2 = 2 > store.size() - 1 ? 0 : 2;
        while (std::get<1>(store[my_index]) > std::get<1>(store[child_1]) || std::get<1>(store[my_index]) > std::get<1>(store[child_2])) {
            int toswitch = std::get<1>(store[child_1]) < std::get<1>(store[child_2]) ? child_1 : child_2;
            swap_heap(my_index, toswitch, store);
            my_index = toswitch;
            child_1 = (2 * my_index) + 1;
            child_2 = child_1 + 1;
            child_1 = child_1 > store.size() - 1 ? my_index : child_1;
            child_2 = child_2 > store.size() - 1 ? my_index : child_2;
        }
        return result;
    }

    void log() {
        for (auto i : store) {
            std::cout << std::get<0>(i) << ": " << std::get<1>(i) << std::endl;
        }
        std::cout<<std::endl;
    }


};

template <typename T>
std::vector<T> dirjkstra (Graph<T, int>& store, T root, T target) {
    std::unordered_map<T, int> distance;
    MinHeap q;
    std::unordered_map<T, int> unvisited;
    std::unordered_map<T, T> parent;
    std::vector<T> shortest_path;

    for (auto i = store.begin(); i != store.end(); i++) {
        distance[i->first] = INT16_MAX;
        parent[i->first];

    }

}

int main () {

    MinHeap mini;
    mini.insert("A", 2);
    mini.insert("B", 10);
    mini.insert("C", 1);
    mini.insert("D", 5);
    mini.insert("E", 7);
    mini.insert("F", 3);
    mini.insert("G", 0);
    mini.insert("H", 46);
    mini.log();
    mini.pop();
    mini.pop();
    mini.log();



   Graph<const char*, int> g;
   g.add_node("A");
   g.add_node("B");
   g.add_node("C");
   g.add_node("D");
   g.add_edges("A", {"B", "C"}, {2, 3});
   g.add_edges("B", {"D"}, {4});
   g.log();


}