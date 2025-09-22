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

// Build tree from preorder array (-1 = NULL)
Node* buildTree(vector<int>& nodes) {
    idx++;
    if (idx >= nodes.size() || nodes[idx] == -1) {
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);   // build left subtree
    currNode->right = buildTree(nodes);  // build right subtree

    return currNode;
}

void topView(Node* root) {
    queue<pair<Node* , int>> Q; // (node, HD)
    map<int, int> m; //(HD, node->data)
}


int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1,
                         3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);


    return 0;
}
