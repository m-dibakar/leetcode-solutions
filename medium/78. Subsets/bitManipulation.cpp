#include <iostream>
#include <vector>
using namespace std;
 
// ─────────────────────────────────────────
//  Approach 2 : Bit Manipulation
// ─────────────────────────────────────────
class SolutionBit {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total = 1 << n;         // 2^n subsets
        vector<vector<int>> res;
 
        for (int mask = 0; mask < total; mask++) {
            vector<int> subset;
            for (int i = 0; i < n; i++)
                if (mask & (1 << i))
                    subset.push_back(nums[i]);
            res.push_back(subset);
        }
        return res;
    }
};

// ─────────────────────────────────────────
//  Helper : print all subsets
// ─────────────────────────────────────────
void printResult(const vector<vector<int>>& res) {
    cout << "[\n";
    for (const auto& subset : res) {
        cout << "  [";
        for (int i = 0; i < (int)subset.size(); i++) {
            cout << subset[i];
            if (i + 1 < (int)subset.size()) cout << ", ";
        }
        cout << "]\n";
    }
    cout << "]\n";
}
 
// ─────────────────────────────────────────
//  Main
// ─────────────────────────────────────────
int main() {
    // ── Test case 1 ──
    vector<int> nums1 = {1, 2, 3};
 
    cout << "Input: [1, 2, 3]\n\n";
 
    SolutionBit solB;
    cout << "\nApproach 2 (Bit Manipulation):\n";
    printResult(solB.subsets(nums1));
 
    // ── Test case 2 ──
    vector<int> nums2 = {0};
 
    cout << "\n─────────────────────\n";
    cout << "Input: [0]\n\n";
 
    cout << "\nApproach 2 (Bit Manipulation):\n";
    printResult(solB.subsets(nums2));
 
    return 0;
}