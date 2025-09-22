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

// Function to calculate height
int height(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHt = height(root->left);
    int rightHt = height(root->right);

    return max(leftHt, rightHt) + 1;
}

// O(n^2) Diameter
int diameter1(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHt = height(root->left);
    int rightHt = height(root->right);
    int currDiam = leftHt + rightHt + 1;

    int leftDiam = diameter1(root->left);
    int rightDiam = diameter1(root->right);

    return max(currDiam, max(leftDiam, rightDiam));
}

// O(n) Diameter (returns {diameter, height})
pair<int, int> diameter2(Node* root) {
    if (root == NULL) {
        return {0, 0}; // {diameter, height}
    }

    pair<int, int> leftInfo = diameter2(root->left); // LD, LH
    pair<int, int> rightInfo = diameter2(root->right); // RD, RH

    int currDiam = leftInfo.second + rightInfo.second + 1;
    int finalDiam = max(currDiam, max(leftInfo.first, rightInfo.first));
    int finalHt = max(leftInfo.second, rightInfo.second) + 1;

    return {finalDiam, finalHt};
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1,
                         3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    cout << "Height of tree: " << height(root) << endl;
    cout << "Diameter (O(n^2)): " << diameter1(root) << endl;
    cout << "Diameter (O(n)): " << diameter2(root).first << endl;

    return 0;
}
