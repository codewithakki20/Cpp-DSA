#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }

    ~Node() {
        cout << "Destructor of Node: " << data << "\n";
        if(next != NULL) {
            delete next;  // recursively delete remaining nodes
            next = NULL;
        }
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

    ~List() {
        cout << "Destructor of List\n";
        if(head != NULL) {
            delete head;  // triggers recursive deletion of all nodes
            head = NULL;
            tail = NULL;
        }
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {  
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {  
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    {
        List ll;

        ll.push_back(5);
        ll.push_back(4);
        ll.push_front(3);
        ll.push_front(2);
        ll.push_front(1); // 1->2->3->4->5

        cout << "Linked List: ";
        ll.printList();

    } // <-- scope ends, destructor is called automatically here

    cout << "List deleted successfully.\n";

    return 0;
}
