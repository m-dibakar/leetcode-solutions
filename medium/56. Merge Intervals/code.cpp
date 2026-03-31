#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][0]<=result.back()[1]) {
                result.back()[1] = max(intervals[i][1],result.back()[1]);
            }else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};

void print2Dvec(vector<vector<int>>& v) {
    for(const auto& i: v) {
        cout<<"{"<<i[0]<<","<<i[1]<<"}";
    }cout<<endl;
}

int main() {
    Solution s;
    //Test case 1:
    // vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    // print2Dvec(intervals);
    // vector<vector<int>> res = s.merge(intervals);
    // print2Dvec(res);

    // Test case 2:
    // vector<vector<int>> intervals = {{1,4},{4,5}};
    // print2Dvec(intervals);
    // vector<vector<int>> res = s.merge(intervals);
    // print2Dvec(res);

    // Test case 3:
    vector<vector<int>> intervals = {{4,7},{1,4}};
    print2Dvec(intervals);
    vector<vector<int>> res = s.merge(intervals);
    print2Dvec(res);
    return 0;
}