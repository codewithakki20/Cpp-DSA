#include <iostream>
#include <vector>
using namespace std;

vector<int> pairSum(vector<int> nums, int target){
    int st = 0, end = nums.size()-1;
    int currSum = 0;
    vector<int> ans;

    while (st < end)
    {
        currSum = nums[st] + nums[end];
        if(currSum == target) {
            ans.push_back(st);
            ans.push_back(end);
            break; 
        } else if (currSum > target)
        {
            end--;
        } else 
        {
            st++;
        }
        
    }
    return ans;
    
}

int main() {
    vector<int>  vec ={2, 7, 11, 15};
    int target = 9;
    vector<int> ans = pairSum(vec, target);
    cout << ans[0] << " , " << ans[1] << endl;
    return 0;
}