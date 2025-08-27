#include <iostream>
#include <cstring>
using namespace std;

int main() {
    //creation & output
    // char work1[] = "code";
    // char work2[5] = "code";
    // char work3[] = {'c', 'o', 'd', 'e', '\0'};
    // char work4[50] = {'c', 'o', 'd', 'e', '\0'};
    // cout << strlen(work4) << endl;

    //cin getline
    //    char word[30];
    //    cin >> word; // ignrore whitespace
    //    cout << "your word was : " << word << endl;
    //    cout << "length : " << strlen(word) << endl;

        char sentence[30];
       cin.getline(sentence, 30, '*'); //print the whitespace
       cout << "your word was : " << sentence << endl;
       cout << "length : " << strlen(sentence) << endl;
     

    

    return 0;
}