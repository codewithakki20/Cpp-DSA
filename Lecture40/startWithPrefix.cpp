#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfWord;

    Node() {
        endOfWord = false;
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    // Insert a word into the Trie
    void insert(string key) {
        Node* temp = root;
        for (char ch : key) {
            if (temp->children.count(ch) == 0) {
                temp->children[ch] = new Node();
            }
            temp = temp->children[ch];
        }
        temp->endOfWord = true;
    }

    // Check if any word starts with the given prefix
    bool startsWith(string prefix) {
        Node* temp = root;
        for (char ch : prefix) {
            if (temp->children.count(ch) == 0)
                return false;
            temp = temp->children[ch];
        }
        return true;
    }
};

int main() {
    vector<string> words = {"apple", "app", "mango", "man", "woman"};

    Trie trie;
    for (auto &word : words) {
        trie.insert(word);
    }
    cout << trie.startsWith("woe") << endl;

    return 0;
}
