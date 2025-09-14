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

static int idx = -1;

Node* buildTree(vector<int>& nodes) { //O(n)
    idx++;
    if (idx >= nodes.size() || nodes[idx] == -1) {
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);   // left subtree
    currNode->right = buildTree(nodes);  // right subtree

    return currNode;
}

void preorder(Node* root) { //O(n)
    if (root == NULL) return;

    cout << root->data << " ";  // print root
    preorder(root->left);       // left subtree
    preorder(root->right);      // right subtree
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1,
                         3, -1, 6, -1, -1};
    
    Node* root = buildTree(nodes);

    preorder(root);
    cout << endl;

    return 0;
}
