// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cin>>n;

//     int arr[2] = {0};
//     arr[0] = n;

//     for(int i=0; i<4; i++) {
//         int a = arr[0];
//         int b = arr[1];
//         arr[0] = a*0.3+b*0.5;
//         arr[1] = b*0.5+a*0.7;
//     }

//     cout<<arr[0]<<" "<<arr[1];
//     return 0;
// }


#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int n;
    cin>>n;

    double arr[2] = {0};   // use double to preserve precision during iteration
    arr[0] = n;

    for(int i=0; i<4; i++) {
        double a = arr[0];
        double b = arr[1];
        arr[0] = a*0.3 + b*0.5;
        arr[1] = b*0.5 + a*0.7;
    }

    cout << (int)round(arr[0]) << " " << (int)round(arr[1]);
    return 0;
}