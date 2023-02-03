#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr,arr + n);
    long long int max = 0;
    for(int i = 0; i < n; i++){
        if(arr[i]*(n-i) > max){
            max = arr[i]*(n-i);
        }
    }
    cout << max << "\n";
}