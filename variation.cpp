#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int N;
    cin >> N;
    ll K; 
    cin >> K;
    ll arr[N];

    int score = 0;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr,arr + N);

    int k = 1;
    for(int i = 0; i < N; i++){
        for(int j = k; j < N; j++){
            int diff = abs(arr[j] - arr[i]);
            if(diff >= K){
                score += (N-j);
                k = j;
                break;
            }
        }
    }
    cout << score << "\n";
}