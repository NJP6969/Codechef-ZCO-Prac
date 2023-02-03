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
    long long int score = 0;
    for(int i = n-1; i >= 0; i--){
        score += i*arr[i] - (n-i-1)*arr[i];
    }
    cout << score << "\n";
}