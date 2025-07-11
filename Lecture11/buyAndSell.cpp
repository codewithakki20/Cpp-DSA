#include <iostream>  
#include <climits> 
using namespace std;

void maxProfit(int *prices, int n){
    int bestBuy[10000];
    bestBuy[0] = INT_MAX;
    for(int i=1; i<n; i++){
        bestBuy[i] =min(bestBuy[i-1], prices[i-1]);
    }
    int maxProfit = 0;
    for(int i=0; i<n; i++){
        int currProfit = prices[i] - bestBuy[i];
        maxProfit = max(maxProfit, currProfit);
    }
  //T.C = 0(n + n) = 0(2n) = 0(n)
    cout << "max Profit" << maxProfit<< endl;
}

int main() {  
   int prices[6] = {7, 1, 6, 3, 6, 4};
   int n = sizeof(prices) / sizeof(int);

   maxProfit(prices, n);

    return 0;
}
