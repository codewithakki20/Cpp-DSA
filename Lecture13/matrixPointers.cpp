#include <iostream>
using namespace std;

void func(int matrix[][4], int n, int m) {
    cout << "0th row ptr " << matrix << endl;        // matrix == &matrix[0]
    cout << "1st row ptr " << matrix + 1 << endl;    // == &matrix[1]
    cout << "2nd row ptr " << matrix + 2 << endl;    // == &matrix[2]

    cout << "0th row first element " << *matrix << endl;         // == matrix[0] == &matrix[0][0]
    cout << "1st row first element " << *(matrix + 1) << endl;   // == matrix[1] == &matrix[1][0]
    cout << "2nd row first element " << *(matrix + 2) << endl;   // == matrix[2] == &matrix[2][0]
}


void func2(int matrix[][4], int n,  int m) {
    cout << *((*matrix + 2) + 2) << endl;
}
  

int main() {
   int matrix[4][4] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12},
        {13,14, 15, 16}
    };
    
    // cout << matrix << " = " << &matrix[0][0] << endl;
    // cout << matrix + 1 << " != " << &matrix[0][1] << endl;
    // cout << matrix + 1 << " = " << &matrix[1][0] << endl;

    func2(matrix, 4, 4);
    return 0;
}