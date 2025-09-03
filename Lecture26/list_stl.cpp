#include<bits/stdc++.h>

using namespace std;

void printList(list<int> ll) {
    list<int>:: iterator itr;
    for(itr = ll.begin(); itr != ll.end(); itr++) {
        cout << (*itr) << "->";
    }
    cout << "NULL" << endl;
}

int main() {
    list<int> ll;

    ll.push_front(2);
    ll.push_front(1);//1->2

    ll.push_back(3);//1->2->3
    ll.push_back(4);//1->2->3->4->NULL
    

    printList(ll); 
    cout << ll.size() << endl;

    
    cout << "head : " << ll.front() <<"\n";
    cout << "tail : " << ll.back() <<"\n";

    ll.pop_front();
    printList(ll);

    ll.pop_back();
    printList(ll);

    return 0;
}

//Notes this my home work inerator (3parmetr)