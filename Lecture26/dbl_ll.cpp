#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList {
public:
    Node* head;
    Node* tail;

    DoublyList() {
        head = tail = NULL;
    }

    // Insert at front
    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Delete from front
    void pop_front() {
        if (head == NULL) return; // empty list

        Node* temp = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL; // list became empty
        }

        temp->next = NULL;
        delete temp;
    }

    // Print the list
    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyList dbll;

    dbll.push_front(4);
    dbll.push_front(3);
    dbll.push_front(2);
    dbll.push_front(1);

    cout << "List after pushes: ";
    dbll.printList();   // 1 <=> 2 <=> 3 <=> 4 <=> NULL

    dbll.pop_front();

    cout << "List after pop_front: ";
    dbll.printList();   // 2 <=> 3 <=> 4 <=> NULL

    dbll.push_front(10);

    cout << "List after push_front(10): ";
    dbll.printList();   // 10 <=> 2 <=> 3 <=> 4 <=> NULL

    return 0;
}
