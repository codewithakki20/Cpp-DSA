#include <bits/stdc++.h>
using namespace std;

class Node {
public: 
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if(root == NULL) {
        return new Node(val);
    }

    if(val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;  
}

Node* buildBST(int arr[], int n) {
    Node* root = NULL;
    for(int i=0; i<n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool search(Node* root, int key) { // O(height); avg => O(logn)
    if(root == NULL) return false;

    if(root->data == key) return true;  

    if(root->data > key) return search(root->left, key);
    return search(root->right, key);
}

int main() {
    int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node* root = buildBST(arr, 9);

    cout << search(root, 14) << endl; 

    return 0;
}
