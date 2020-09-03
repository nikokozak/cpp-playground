#include <iostream>

class Node {
public:
    int value;
    Node* right;
    Node* left;

    Node (int val) : value{val}, right{nullptr}, left{nullptr} {
        printf("Node created with value %d\n", value);
    };

    bool has_right() {
        return right != nullptr;
    }

    bool has_left() {
        return left != nullptr;
    }

    bool is_leaf () {
        return left == nullptr && right == nullptr;
    }
};

class BST {
public:
    Node* root;

    BST (int value) : root{new Node{value}} { };

    bool insert (int value) {
        Node* current = root;
        while (current -> value != value) {
            if ( value > current -> value ) {
                if ( current -> has_right() ) current = current -> right;
                else {
                    current -> right = new Node{value};
                    return true;
                }
            } else if ( value < current -> value ) {
                if (current -> has_left() ) current = current -> left;
                else {
                    current -> left = new Node{value};
                    return true;
                }
            }
        }
        return true;
    };

    bool has_value (int value) {
        Node* current = root;
        while (current -> value != value) {
            if (value > current -> value && current -> has_right()) {
                current = current -> right;
                continue;
            } else if (value < current -> value && current -> has_left()) {
                current = current -> left;
                continue;
            }
            printf("value %d not found\n", value);
            return false;
        }
        printf("value %d found\n", value);
        return true;
    }

    bool delete_value (int value) {

    }
};

int main () {
    BST tree {20};
    tree.insert(10);
    tree.insert(25);
    tree.insert(30);
    tree.has_value(10);
    tree.has_value(30);
    tree.has_value(15);

}