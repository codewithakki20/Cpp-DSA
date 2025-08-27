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

class List {
    Node* head;
    Node* tail;

public:
    List() {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Insert at given position (0-based index)
    void insert(int val, int pos) {
        Node* newNode = new Node(val);

        // insert at head
        if (pos == 0) {
            newNode->next = head;
            head = newNode;
            if (tail == NULL) tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            if (temp == NULL) {
                cout << "Position is INVALID\n";
                return;
            }
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position is INVALID\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        if (newNode->next == NULL) {
            tail = newNode;
        }
    }
};

int main() {
    List ll;

    ll.push_back(5);
    ll.push_back(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1); // 1->2->3->4->5

    cout << "Original List: ";
    ll.printList();

    ll.insert(100, 2); // insert 100 at index 2
    cout << "After inserting 100 at pos 2: ";
    ll.printList();

    ll.insert(200, 0); // insert 200 at head
    cout << "After inserting 200 at pos 0: ";
    ll.printList();

    ll.insert(300, 6); // insert 300 at last
    cout << "After inserting 300 at last: ";
    ll.printList();

    return 0;
}
