#include <iostream>
#include <vector>
using namespace std;

void printNum(int n) {
    if(n == 0) {
        return;
    }
    cout << n << " ";//kaam
    printNum(n - 1);//faith next call
   
}

int main() {
    printNum(5);
    return 0;
}