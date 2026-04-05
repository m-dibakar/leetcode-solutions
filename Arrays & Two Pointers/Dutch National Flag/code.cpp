// 75. Sort Colors
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, m = 0, r = nums.size()-1;
        while(m <= r) {
            if(nums[m] == 2) {
                swap(nums[m],nums[r--]);
            }else if(nums[m] == 0) {
                swap(nums[m++],nums[l++]);
            }else{
                m++;
            }
        }
    }
};

void printVec(vector<int>& nums) {
    for(int i=0; i<nums.size(); i++) {
        cout<<nums[i]<<" ";
    }cout<<endl;
}

int main() {
    Solution s;

    //Test case 1:
    // vector<int> nums = {2,0,2,1,1,0};
    // printVec(nums);
    // s.sortColors(nums);
    // printVec(nums);

    //Test case 2:
    vector<int> nums = {2,0,1};
    printVec(nums);
    s.sortColors(nums);
    printVec(nums);
    return 0;
}