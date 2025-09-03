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

    return slow; // right half head
}

// Reverse linked list
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev; // new head
}

// Zig-Zag merge
Node* zigZagLL(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    // Step 1: Split at mid
    Node* rightHead = splitAtMid(head);

    // Step 2: Reverse second half
    Node* rightHeadRev = reverse(rightHead);

    // Step 3: Alternate merge
    Node* left = head;
    Node* right = rightHeadRev;

    while(left != NULL && right != NULL) {
        Node* nextLeft = left->next;
        Node* nextRight = right->next;

        left->next = right;
        if(nextLeft == NULL) break; // if odd size
        right->next = nextLeft;

        left = nextLeft;
        right = nextRight;
    }

    return head;
}

int main() {
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);

    cout << "Original List: ";
    ll.printList(ll.head);  // 5->4->3->2->1->NULL

    ll.head = zigZagLL(ll.head);

    cout << "ZigZag List: ";
    ll.printList(ll.head);  // 5->1->4->2->3->NULL

    return 0;
}
