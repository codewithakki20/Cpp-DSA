#include <iostream>
#include <string>
using namespace std;

// Node class for Linked List
class Node {
public:
    string key;
    int val;
    Node* next;

    Node(string key, int val) {
        this->key = key;
        this->val = val;
        this->next = NULL;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};

// Hash Table class
class HashTable {
    int totSize;
    int curSize;
    Node** table;

    // Simple hash function
    int hashFunction(string key) {
        int idx = 0;
        for (int i = 0; i < key.size(); i++) {
            idx = (idx + (key[i] * key[i])) % totSize;
        }
        return idx;
    }

    // Rehash function (doubles table size)
    void rehash() {
        Node** oldTable = table;
        int oldSize = totSize;

        totSize = 2 * totSize;
        curSize = 0;
        table = new Node*[totSize];
        for (int i = 0; i < totSize; i++) {
            table[i] = NULL;
        }

        // reinsert old data
        for (int i = 0; i < oldSize; i++) {
            Node* temp = oldTable[i];
            while (temp != NULL) {
                insert(temp->key, temp->val);
                temp = temp->next;
            }

            // delete old chain
            if (oldTable[i] != NULL) {
                delete oldTable[i];
            }
        }

        delete[] oldTable;
    }

public:
    HashTable(int size) {
        totSize = size;
        curSize = 0;
        table = new Node*[totSize];
        for (int i = 0; i < totSize; i++) {
            table[i] = NULL;
        }
    }

    // Insert key–value pair
    void insert(string key, int val) {
        int idx = hashFunction(key);

        // check if key already exists → update value
        Node* temp = table[idx];
        while (temp != NULL) {
            if (temp->key == key) {
                temp->val = val;
                return;
            }
            temp = temp->next;
        }

        // otherwise, insert new node at head
        Node* newNode = new Node(key, val);
        newNode->next = table[idx];
        table[idx] = newNode;
        curSize++;

        double lambda = (double)curSize / totSize;
        if (lambda > 1.0) {
            cout << "\n[Rehashing triggered...]\n";
            rehash();
        }
    }

    // Check if key exists
    bool exists(string key) {
        int idx = hashFunction(key);
        Node* temp = table[idx];
        while (temp != NULL) {
            if (temp->key == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Search key
    int search(string key) {
        int idx = hashFunction(key);
        Node* temp = table[idx];
        while (temp != NULL) {
            if (temp->key == key) {
                return temp->val;
            }
            temp = temp->next;
        }
        return -1;
    }

    // delete node
    void remove(string key) {
        int idx = hashFunction(key);

        Node* temp = table[idx];
        Node* prev = temp;
        while(temp != NULL){
            if(temp->key == key) {
                table[idx]  = temp->next;
            } else {
                prev->next = temp->next;
            }
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    // Print hash table
    void print() {
        cout << "\n--- Hash Table ---\n";
        for (int i = 0; i < totSize; i++) {
            cout << "idx " << i << " -> ";
            Node* temp = table[i];
            while (temp != NULL) {
                cout << "(" << temp->key << ", " << temp->val << ") -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
        cout << "-------------------\n";
    }
};

int main() {
    HashTable ht(5);

    ht.insert("Ankit", 90);
    ht.insert("Ravi", 85);
    ht.insert("Amit", 75);
    ht.insert("Priya", 95);
    ht.insert("Vivek", 88);
    ht.insert("Rahul", 92);

    // ht.remove("Ankit");

    ht.print();

    // cout << "\nSearch 'Priya': " << ht.search("Priya") << endl;
    // cout << "Exists 'Ravi'? " << (ht.exists("Ravi") ? "Yes" : "No") << endl;
    // cout << "Exists 'Manoj'? " << (ht.exists("Manoj") ? "Yes" : "No") << endl;

    return 0;
}
