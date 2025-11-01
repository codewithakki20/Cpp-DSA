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

    bool search(string key)
    {
        Node *temp = root;
        for (int i=0; i<key.size(); i++)
        {
            if(temp->children.count(key[i])) {
                temp = temp->children[key[i]];
            } else {
                return false;
            }
        }
        return temp->endOfWord;
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

    cout << (trie.search("the") ? "Found" : "Not Found") << endl;
    cout << (trie.search("these") ? "Found" : "Not Found") << endl;
    cout << (trie.search("their") ? "Found" : "Not Found") << endl;
    cout << (trie.search("thaw") ? "Found" : "Not Found") << endl;

    return 0;
}
