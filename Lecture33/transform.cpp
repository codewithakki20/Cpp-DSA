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


int transform(Node* root) { //O(n)
    if (root == NULL) {
        return 0;
    }

    int leftOld = transform(root->left);
    int rightOld = transform(root->right);
    int currOld = root->data;

    int leftData = (root->left != NULL) ? root->left->data : 0;
    int rightData = (root->right != NULL) ? root->right->data : 0;

    root->data = leftOld + rightOld;

    if(root->left != NULL) {
        root->data += root->left->data;
    }

     if(root->right != NULL) {
        root->data += root->right->data;
    }


    return currOld;
}



int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

  

    transform(root);

    return 0;
}
