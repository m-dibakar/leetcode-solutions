#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        vector<int> result(nums.size());
        int k = nums.size()-1;
        while(l<=r) {
            if(nums[l]*nums[l]>nums[r]*nums[r]) {
                result[k--] = nums[l]*nums[l];
                l++;
            } else {
                result[k--] = nums[r]*nums[r];
                r--;
            }
        }
        return result;
    }
};

void printVec(vector<int> v) {
    for(int i=0; i<v.size(); i++) {
        cout<<v[i]<<" ";
    }cout<<endl;
}

int main() {
    Solution s;
    //Test case 1:
    // vector<int> nums = {-4,-1,0,3,10};
    // printVec(nums);
    // vector<int> res;
    // res = s.sortedSquares(nums);
    // printVec(res);

    // Test case 2:
    vector<int> nums = {-7,-3,2,3,11};
    printVec(nums);
    vector<int> res;
    res = s.sortedSquares(nums);
    printVec(res);
    return 0;
}