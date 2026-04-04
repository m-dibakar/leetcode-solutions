// 219. Contains Duplicate II

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++) {
            if(m.count(nums[i])) {
                if(i - m[nums[i]] <= k) {
                    return true;
                }
            }
            m[nums[i]] = i;
        }
        return false;
    }
};

int main() {
    // Test case 1:
    // vector<int> nums = {1,2,3,1};
    // int k = 3;
    // Solution s;
    // cout<<s.containsNearbyDuplicate(nums, k)<<endl;

    // Test case 2:
    vector<int> nums = {1,0,1,1};
    int k = 1;
    Solution s;
    cout<<s.containsNearbyDuplicate(nums, k)<<endl;

    // Test case 3:
    // vector<int> nums = {1,2,3,1,2,3};
    // int k = 2;
    // Solution s;
    // cout<<s.containsNearbyDuplicate(nums, k)<<endl;
    return 0;
}