#include <iostream>
#include <vector>
using namespace std;
 
// ─────────────────────────────────────────
//  Approach 1 : Recursion
// ─────────────────────────────────────────
class SolutionRecursive {
    void solve(vector<int> nums, vector<vector<int>>& res, vector<int> subset) {
        if (nums.empty()) {
            res.push_back(subset);
            return;
        }
        int n = nums.back();
        nums.pop_back();
 
        subset.push_back(n);        // include n
        solve(nums, res, subset);
 
        subset.pop_back();          // exclude n
        solve(nums, res, subset);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        solve(nums, res, subset);
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
 
    SolutionRecursive solR;
    cout << "Approach 1 (Recursive):\n";
    printResult(solR.subsets(nums1));
 
    // SolutionBit solB;
    // cout << "\nApproach 2 (Bit Manipulation):\n";
    // printResult(solB.subsets(nums1));
 
    // ── Test case 2 ──
    vector<int> nums2 = {0};
 
    cout << "\n─────────────────────\n";
    cout << "Input: [0]\n\n";
 
    cout << "Approach 1 (Recursive):\n";
    printResult(solR.subsets(nums2));
 
    // cout << "\nApproach 2 (Bit Manipulation):\n";
    // printResult(solB.subsets(nums2));
 
    return 0;
}