#include<bits/stdc++.h>
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

Node* buildTree(vector<int>& nodes) { // O(n)
    idx++;
    if (idx >= nodes.size() || nodes[idx] == -1) {
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);   // left subtree
    currNode->right = buildTree(nodes);  // right subtree

    return currNode;
}

void levelOrder(Node* root) { // O(n)
    if(root == NULL) {
        return;
    }

    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL);

    while (!Q.empty())
    {
        Node* curr = Q.front();
        Q.pop();

        if(curr == NULL) {
            cout << endl;
            if(Q.empty()) {
                break;
            }
            Q.push(NULL);// to track next line
        }  else {
            cout << curr->data << " ";

        if(curr->left != NULL) {
            Q.push(curr->left);   // push left child
        }

        if(curr->right != NULL) {
            Q.push(curr->right);  // push right child
        }
        }
    }
}


int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1,
                         3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    levelOrder(root);


    return 0;
}