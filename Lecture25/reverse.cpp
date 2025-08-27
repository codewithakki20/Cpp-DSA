#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node * next;

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
    head  = NULL;
    tail =  NULL;
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
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
   }

   void reverse() {
    Node* curr = head;
    Node* prev = NULL;
    tail = head; // head to tail 

    while (curr != NULL) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    head = prev; // New  head
   }
};

int main() {
    List ll;

    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1); // 1->2->3->4->5->NULL

    ll.printList();

    ll.reverse(); //5->4->3->2->1->NULL
    ll.printList();
    return 0;
}
