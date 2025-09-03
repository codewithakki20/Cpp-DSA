#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = NULL;
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

    void removeCycle(Node* head) {
        Node* slow = head;
        Node* fast = head;
        bool isCycle = false;

        // Step 1: Detect cycle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {   
                cout << "Cycle exists\n";
                isCycle = true;
                break;
            }
        }

        if (!isCycle) {
            cout << "No cycle\n";
            return;
        }

        // Step 2: Remove cycle
        slow = head;
        if (slow == fast) {
            // special case: cycle starts at head
            while (fast->next != slow) {
                fast = fast->next;
            }
            fast->next = NULL;
        } else {
            Node* prev = NULL;
            while (slow != fast) {
                prev = fast;
                slow = slow->next;
                fast = fast->next;
            }
            prev->next = NULL;  // cut cycle
        }
    }
};

int main() {
    List ll;

    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1); // 1->2->3->4

    // create cycle: tail->next = head
    // ll.tail->next = ll.head;

    ll.removeCycle(ll.head);

    ll.printList();  // expected: 1->2->3->4->NULL

    return 0;
}
