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
    
    // ~Node() {
    //     cout << "Destructor of Node: " << data << "\n";
    //     if(next != NULL) {
    //         delete next;
    //         next = NULL;
    //     }
    // }
};

class List {
    Node* head;
    Node* tail;

public: 
   List() {
    head  = NULL;
    tail =  NULL;
   }

//    ~List() {
//     cout << "Destructor of List\n";
//     if(head != NULL) {
//         delete head;
//         head = NULL;
//     }
//    }

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

   int size() {
    int sz = 0;
    Node* temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        sz++;
    }
    return sz;
   }

  void removeNth(int n) {
    int sz = size();

    if(n <= 0 || n > sz) {
        cout << "Invalid position\n";
        return;
    }

    // Case 1: delete head
    if(n == sz) {
        Node* toDel = head;
        head = head->next;
        if(head == NULL) tail = NULL; // if list became empty
        toDel->next = NULL;
        delete toDel;
        return;
    }

    // Case 2: delete middle or last
    Node* prev = head;
    for(int i = 1; i < (sz - n); i++) {
        prev = prev->next;
    }

    Node* toDel = prev->next;
    cout << "Going to delete : " << toDel->data << endl;

    prev->next = toDel->next;
    if(toDel == tail) tail = prev; // update tail if needed

    toDel->next = NULL;
    delete toDel;
}

};

int main() {
    List ll;

    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1); // 1->2->3->4->5

    ll.printList();

    ll.removeNth(2);

    ll.printList(); // 1->2->3->5
    

    return 0;
}
