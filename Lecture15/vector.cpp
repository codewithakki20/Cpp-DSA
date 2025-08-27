#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec1;
    vector<int> vec2 = {1, 2, 3, 4};
    vector<int> vec3(5, -1);

    // cout << vec3.size() << "\n";
    for(int i=0; i<vec3.size(); i++){
        cout << vec3[i] << " ";
    }
    cout << endl;
    return 0;
}