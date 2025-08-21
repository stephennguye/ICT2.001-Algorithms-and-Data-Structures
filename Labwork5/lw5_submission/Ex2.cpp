#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node* parent;

    Node(int v = 0) : value(v), left(nullptr), right(nullptr), parent(nullptr) {}
};

vector<int> generateRandomArray(int n, int maxVal = 100) {
    srand(time(0));
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % maxVal;
    }
    return arr;
}

class MinTournamentTree {
private:
    Node* root;
    int E; // sentinel value
    int n; // number of real data elements
    vector<Node*> leaves; // store leaves for easy access

    // Build tree recursively
    Node* buildTree(vector<int>& values, int start, int end) {
        if (start == end) {
            Node* leaf = new Node(values[start]);
            leaves.push_back(leaf);
            return leaf;
        }
        int mid = (start + end) / 2;
        Node* node = new Node();
        node->left = buildTree(values, start, mid);
        node->right = buildTree(values, mid + 1, end);
        node->left->parent = node;
        node->right->parent = node;
        node->value = min(node->left->value, node->right->value);
        return node;
    }

public:
    MinTournamentTree(vector<int>& arr) {
        n = arr.size();
        E = *max_element(arr.begin(), arr.end()) + 1;
        int size = pow(2, ceil(log2(n))); // round to power of 2
        vector<int> extended(size, E);
        for (int i = 0; i < n; i++) extended[i] = arr[i];
        leaves.clear();
        root = buildTree(extended, 0, size - 1);
    }

    Node* getRoot() { return root; }

    void display(Node* node, int depth = 0) {
        if (!node) return;
        for (int i = 0; i < depth; i++) cout << "   ";
        cout << node->value << endl;
        display(node->left, depth + 1);
        display(node->right, depth + 1);
    }

    void displayTree() {
        cout << "Tree structure:\n";
        display(root, 0);
    }

    Node* search(Node* node, int target) {
        if (!node) return nullptr;
        if (node->value == target) return node;
        Node* leftSearch = search(node->left, target);
        if (leftSearch) return leftSearch;
        return search(node->right, target);
    }

    void displaySubtree(Node* node, int depth = 0) {
        if (!node) return;
        for (int i = 0; i < depth; i++) cout << "   ";
        cout << node->value << endl;
        displaySubtree(node->left, depth + 1);
        displaySubtree(node->right, depth + 1);
    }

    void searchAndDisplay(int target) {
        Node* found = search(root, target);
        if (found) {
            cout << "Subtree rooted at " << target << ":\n";
            displaySubtree(found, 0);
        } else {
            cout << "Value " << target << " not found (-1).\n";
        }
    }

    void updateUpwards(Node* node) {
        while (node->parent) {
            node->parent->value = min(node->parent->left->value,
                                      node->parent->right->value);
            node = node->parent;
        }
    }

    void insert(int value) {
        for (Node* leaf : leaves) {
            if (leaf->value == E) {
                leaf->value = value;
                updateUpwards(leaf);
                cout << "Inserted " << value << " into tree.\n";
                return;
            }
        }
        cout << "No empty leaf available for insertion.\n";
    }

    void removeValue(int value) {
        for (Node* leaf : leaves) {
            if (leaf->value == value) {
                leaf->value = E;
                updateUpwards(leaf);
                cout << "Removed " << value << " from tree.\n";
                return;
            }
        }
        cout << "Value " << value << " not found in leaves.\n";
    }
};

int main() {
    int n = 5;
    vector<int> arr = {8, 20, 41, 7, 2};

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    MinTournamentTree tree(arr);
    tree.displayTree();

    cout << "\nSearching value 7...\n";
    tree.searchAndDisplay(7);

    cout << "\nInserting 15...\n";
    tree.insert(15);
    tree.displayTree();

    cout << "\nRemoving 20...\n";
    tree.removeValue(20);
    tree.displayTree();

    return 0;
}
