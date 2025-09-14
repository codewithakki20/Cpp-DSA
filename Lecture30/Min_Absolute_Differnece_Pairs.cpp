#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> A = {4, 1, 8, 7};// o(n)
    vector<int> B = {2, 3, 5, 6};

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int absDiff = 0;

    for(int i=0; i<A.size(); i++) {
        absDiff += abs(A[i] - B[i]);
    }

    cout << "min abs diff = " << absDiff << endl;
    return 0;
}