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

    ~Node() {
        if(next != NULL) {
            delete next;
            next = NULL;
        }
    }
};

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
    }

    ~List() {
        if(head != NULL) {
            delete head;
            head = NULL;
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

    void printList(Node* head) {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Splitting list into two halves
Node* splitAtMid(Node* head) {
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while(fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if(prev != NULL) {
        prev->next = NULL; // split at mid
    }

    return slow; // right head
}

// Merge two sorted lists
Node* merge(Node* left, Node* right) {
    if(left == NULL) return right;
    if(right == NULL) return left;

    Node* result;
    if(left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

// Merge Sort function
Node* mergeSort(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* rightHead = splitAtMid(head);
    Node* left = mergeSort(head);
    Node* right = mergeSort(rightHead);

    return merge(left, right);
}

int main() {
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);

    cout << "Original List: ";
    ll.printList(ll.head);// 5->4->3->2->1->NULl

    ll.head = mergeSort(ll.head);

    cout << "Sorted List: ";
    ll.printList(ll.head);// 1->2->3->4->5->NULL

    return 0;
}
