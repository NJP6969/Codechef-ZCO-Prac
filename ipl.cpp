#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<int> dp(n);
    dp[0] = v[0];
    dp[1] = v[0] + v[1];
    dp[2] = max(v[0] + v[1], max(v[0] + v[2], v[1] + v[2]));

    for(int i = 3; i < n; i++){
        dp[i] = max(dp[i-1],max(dp[i-2] + v[i], dp[i-3] + v[i-1] + v[i]));
    }
    cout << dp[n-1] << "\n";
}