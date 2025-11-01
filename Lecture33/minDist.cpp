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
    currNode->left = buildTree(nodes);  
    currNode->right = buildTree(nodes); 

    return currNode;
}

// Find path from root to given node
bool findPath(Node* root, int n, vector<int> &path) {
    if(root == NULL) {
        return false;
    }

    path.push_back(root->data);

    if(root->data == n) {
        return true;
    }

    if(findPath(root->left, n, path) || findPath(root->right, n, path)) {
        return true;
    }

    path.pop_back();
    return false;
}

// Optimized LCA
Node* LCA(Node* root, int n1, int n2) {
    if(root == NULL) {
        return NULL;
    }

    if(root->data == n1 || root->data == n2) {
        return root;
    }

    Node* leftLCA = LCA(root->left, n1, n2);
    Node* rightLCA = LCA(root->right, n1, n2);

    if(leftLCA != NULL && rightLCA != NULL) {
        return root;
    }

    return leftLCA == NULL ? rightLCA : leftLCA;
}

int dist(Node* root, int n) {
    if(root == NULL) {
        return -1;
    }

    if(root->data == n) {
        return 0;
    }

    int leftDist = dist(root->left, n);
    if(leftDist != -1) {
        return leftDist + 1;
    }

    int rightDist = dist(root->right, n);
    if(rightDist != -1) {
        return rightDist + 1;
    }


    return -1;


}

int minDist(Node* root, int n1, int n2) {
    Node* lca = LCA(root, n1, n2);

    int dist1 = dist(lca, n1);
    int dist2 = dist(lca, n2);

    return dist1 + dist2;


}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1,
                         3, -1, 6, -1, -1};

    idx = -1; // reset before building tree
    Node* root = buildTree(nodes);

    int n1 = 4, n2 = 5;
    Node* lcaNode = LCA(root, n1, n2);
    cout << "LCA(" << n1 << "," << n2 << ") = " << (lcaNode ? lcaNode->data : -1) << endl;


    return 0;
}