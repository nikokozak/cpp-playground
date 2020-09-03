#include <cstdio>
#include <queue>
#include <vector>

using std::vector;

class Node {
public:
    Node* right;
    Node* left;
    int value;

    explicit Node (int val) : value {val}, right{nullptr}, left{nullptr} {}

    bool has_left() const { return left != nullptr; }
    bool has_right() const { return right != nullptr; }
};

class BST {
public:
    Node* root;

    explicit BST (int val) : root{new Node{val}} {}

    bool add(int value) {
        Node* current = root;
        while (current -> value != value) {
            if (value > current -> value && current -> has_right()) { current = current -> right; }
            else if (value > current -> value) { current -> right = new Node{value}; current = current -> right; break; }
            if (value < current -> value && current -> has_left()) { current = current -> left; }
            else if (value < current -> value) { current -> left = new Node{value}; current = current -> left; break; }
        }
        return true;
    }

    bool has(int value) const {
        Node* current = root;
        while (current -> value != value) {
            if (value > current -> value && current -> has_right()) { current = current -> right; }
            else if (value > current -> value && !(current -> has_right())) { return false; }
            if (value < current -> value && current -> has_left()) { current = current -> left; }
            else if (value < current -> value && !(current -> has_left())) { return false; }
        }
        return true;
    }

    vector<int> bft () {
       Node* current = root;
       std::deque<Node*> queue {};
       vector<int> result{};

       bftiter(current, queue, result);
       return result;
    }

    vector<int> df_pre () const {
        Node* current = root;
        vector<int> result{};

        df_pre_iter(current, result);
        return result;
    }

    vector<int> df_post () const {
        Node* current = root;
        vector<int> result{};

        df_post_iter(current, result);
        return result;
    }

    vector<int> df_ordered() const {
        Node* current = root;
        vector<int> result{};

        df_ordered_iter(current, result);

        return result;
    }

private:

    void bftiter (Node* current, std::deque<Node*>& queue, vector<int>& result) {
        result.push_back(current -> value);
        if (current->has_left()) queue.push_back(current -> left);
        if (current->has_right()) queue.push_back(current -> right);
        if (queue.empty()) { return; }
        Node* next = queue.front();
        queue.pop_front();
        bftiter(next, queue, result);
    }

    void df_pre_iter (Node* current, vector<int>& result) const {
        if (current == nullptr) { return; }
        result.push_back(current -> value);
        df_pre_iter(current -> left, result);
        df_pre_iter(current -> right, result);
    }

    void df_post_iter (Node* current, vector<int>& result) const {
        if (current == nullptr) { return; }
        df_post_iter(current -> left, result);
        df_post_iter(current -> right, result);
        result.push_back(current -> value);
    }

    void df_ordered_iter (Node* current, vector<int>& result) const {
        if (current == nullptr) { return; }
        if (current -> has_left()) { df_ordered_iter( current -> left, result ); }
        result.push_back(current -> value);
        df_ordered_iter( current -> right, result);
    }

};

int main() {

   BST tree { 20 };
   tree.add(10);
   tree.add(15);
   tree.add(30);
   tree.add(22);
   tree.add(45);
   tree.add(18);
   tree.add(6);

   printf("Val: %d - val right: %d, val left: %d\n", tree.root -> value, tree.root -> right -> value, tree.root -> left -> value);
   printf("Val: %d - val right: %d\n", tree.root -> left -> value, tree.root -> left -> right -> value);

   vector<int> result = tree.bft();
   vector<int> result_df = tree.df_pre();
   vector<int> result_df_post = tree.df_post();
   vector<int> result_ord = tree.df_ordered();

   for (auto i : result_ord){
       printf("%d, ", i);
   }
   printf("\n");

}
