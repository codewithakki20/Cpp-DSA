#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList() {
        head = NULL;
        size = 0;
    }

    // Insert element at end
    void push_back(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    // Remove last element
    void pop_back() {
        if (head == NULL) {  // list empty
            cout << "List is empty, nothing to delete.\n";
            return;
        }

        if (head->next == NULL) { // only 1 element
            cout << "Deleting: " << head->data << endl;
            delete head;
            head = NULL;
        } else {
            Node* prev = head;
            while (prev->next->next != NULL) { 
                prev = prev->next; 
            }
            cout << "Deleting: " << prev->next->data << endl;
            delete prev->next;
            prev->next = NULL;
        }
        size--;
    }

    // Display list
    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);

    cout << "Original List: ";
    list.printList();

    list.pop_back(); // remove 40
    cout << "After pop_back: ";
    list.printList();

    list.pop_back(); // remove 30
    cout << "After another pop_back: ";
    list.printList();

    return 0;
}
