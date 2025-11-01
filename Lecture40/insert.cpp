#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    unordered_map<char, Node *> children; 
    bool endOfWord;

    Node()
    {
        endOfWord = false;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string key)
    {
        Node *temp = root;

        for (int i = 0; i < key.size(); i++)
        {
            char ch = key[i];
            if (temp->children.count(ch) == 0)
            {
                temp->children[ch] = new Node();
            }
            temp = temp->children[ch];
        }
        temp->endOfWord = true; 
    }
};

int main()
{
    vector<string> words = {"the", "a", "there", "their", "any", "thee"};
    Trie trie;

    for (int i = 0; i < words.size(); i++)
    {
        trie.insert(words[i]);
    }

    return 0;
}
