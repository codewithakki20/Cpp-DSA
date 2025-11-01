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

class Info {
public:
    bool isBST;
    int mn;
    int mx;
    int sz;

    Info(bool isBST, int mn, int mx, int sz) {
        this->isBST = isBST;
        this->mn = mn;
        this->mx = mx;
        this->sz = sz;
    }
};

int maxSize = 0;

Info* largestBST(Node* root) {
    if (root == NULL) {
        return new Info(true, INT_MAX, INT_MIN, 0);
    }

    Info* leftInfo = largestBST(root->left);
    Info* rightInfo = largestBST(root->right);

    int currMin = min(root->data, min(leftInfo->mn, rightInfo->mn));
    int currMax = max(root->data, max(leftInfo->mx, rightInfo->mx));
    int currSz = leftInfo->sz + rightInfo->sz + 1;

    if (leftInfo->isBST && rightInfo->isBST &&
        root->data > leftInfo->mx && root->data < rightInfo->mn) {
        maxSize = max(maxSize, currSz);
        return new Info(true, currMin, currMax, currSz);
    }

    return new Info(false, currMin, currMax, currSz);
}

int main() {
    // Construct binary tree
    Node* root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right = new Node(60);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    largestBST(root);
    cout << "Max Size of BST in the Binary Tree: " << maxSize << endl;

    return 0;
}
