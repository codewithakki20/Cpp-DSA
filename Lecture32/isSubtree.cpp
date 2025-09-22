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

bool isIdentical(Node* root1, Node* root2) {
    if(root1 == NULL && root2 == NULL) {
        return true;
    } else if (root1 == NULL || root2 == NULL) {
        return false;
    }

    if(root1->data != root2->data) {
        return false;
    }

    return isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

bool isSubtree(Node* root, Node* subRoot) {
    if (subRoot == NULL) return true;   // empty tree is subtree
    if (root == NULL) return false;

    if (root->data == subRoot->data) {
        if (isIdentical(root, subRoot)) {
            return true;
        }
    }

    return isSubtree(root->left, subRoot) || 
           isSubtree(root->right, subRoot);
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1,
                         3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    Node* subRoot1 =  new Node(2);
    subRoot1->left = new Node(4);
    subRoot1->right = new Node(5);

    cout << isSubtree(root, subRoot1) << endl;  // should print 1 (true)

    Node* subRoot2 =  new Node(3);
    subRoot2->right = new Node(6);

    cout << isSubtree(root, subRoot2) << endl;  // should print 1 (true)

    Node* subRoot3 =  new Node(2);
    subRoot3->left = new Node(4);
    subRoot3->right = new Node(6);

    cout << isSubtree(root, subRoot3) << endl;  // should print 0 (false)

    return 0;
}
