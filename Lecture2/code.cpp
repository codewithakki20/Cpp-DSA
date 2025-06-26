#include <iostream>
using namespace std;

int main() {
    int numbar;

    cout<<"enter the integer : ";
    cin>>numbar;

//  if(numbar > 0) {
//     cout<<"the is positive"<<endl;
 
//   } else if (numbar < 0) {
//     cout<<"the is negative"<<endl;

//   }else {
//     cout<<"the is zore"<<endl;
//   }


    (numbar > 0)? cout <<"positive" : (numbar < 0)? cout<<"negative" : cout<<"zore";

    return 0;
}
