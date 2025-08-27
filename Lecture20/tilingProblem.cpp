#include <iostream>
#include <vector>
using namespace std;

int tilingProblem1(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    //vertically
    int ans1 = tilingProblem1(n-1); // 2xn-1

    //horizontally
    int ans2 = tilingProblem1(n-2); //2xn-2

    return ans1 + ans2;


}

int tilingProblem2(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    return tilingProblem2(n-1) + tilingProblem2(n-2);

}

int main() {
    int n = 4;
    cout << tilingProblem2(n) << endl;// Note :-  home work 2x5 ans = 8
    return 0;
}