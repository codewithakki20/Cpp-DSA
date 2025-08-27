#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> vec;
   cout << "size : " << vec.size() << endl; // 4
   cout << "capacity : " << vec.capacity() << endl; //4

   vec.push_back(4);
   cout << "size : " << vec.size() << endl; //5
   cout << "capacity : " << vec.capacity() << endl; //8

   vec.pop_back();
      cout << "size : " << vec.size() << endl;
   cout << "capacity : " << vec.capacity() << endl;
   return 0;
}