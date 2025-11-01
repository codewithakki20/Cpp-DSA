#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* BSTFromSortedVec(vector<int> &arr, int st, int ed) {
    if (st > ed) {
        return NULL;
    }

    int mid = st + (ed - st) / 2;
    Node* curr = new Node(arr[mid]);

    curr->left = BSTFromSortedVec(arr, st, mid - 1);
    curr->right = BSTFromSortedVec(arr, mid + 1, ed);

    return curr;
}

void preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void getInorder(Node* root, vector<int> &nodes) {
    if (root == NULL) {
        return;
    }
    getInorder(root->left, nodes);
    nodes.push_back(root->data);
    getInorder(root->right, nodes);
}

Node* balanceBST(Node* root) {
    vector<int> nodes;
    getInorder(root, nodes);
    return BSTFromSortedVec(nodes, 0, nodes.size() - 1);
}

int main() {
    // Skewed BST
    Node* root = new Node(6);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);

    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);

    root = balanceBST(root);

    cout << "Preorder of Balanced BST: ";
    preorder(root);
    cout << endl;

    return 0;
}
