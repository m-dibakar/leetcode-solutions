// 49. Group Anagrams

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(int i=0; i<strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(), key.end());
            m[key].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(const auto& pair: m) { // referencing helps to save time from unnecessary copy creation
            ans.push_back(pair.second);
        }
        return ans;
    }
};

int main() {
    // Test case 1:
    vector<string> v = {"eat","tea","tan","ate","nat","bat"};
    Solution s;
    vector<vector<string>> ans;
    ans = s.groupAnagrams(v);
    for (auto& group : ans) {
        for (auto& word : group) {
            cout << word << " ";
        }
        cout << "\n";  // newline after each group
    }
    return 0;
}