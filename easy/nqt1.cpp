#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> arr(5);
    for(int i=0; i<arr.size();i++) {
        cin>>arr[i];
    }
    int count = 0;
    for(int i=0; i<arr.size();i++) {
        if(arr[i]>=n) {
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}