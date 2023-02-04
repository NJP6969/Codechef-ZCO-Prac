#include <bits/stdc++.h>
using namespace std;

int minCost(vector<int> v){
    vector<pair<int,int>> dp(v.size());
    dp[0].first = 0;
    dp[0].second = v[0];
    for(int i = 1; i < v.size(); i++){
        dp[i].first = dp[i-1].second;
        dp[i].second = v[i] + min(dp[i-1].first,dp[i-1].second);

    }
    int ans = min(dp[v.size()-1].first, dp[v.size()-1].second);
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<int> v1(v.begin()+1,v.end());
    vector<int> v2(v.begin(),v.end()-1);

    int ans = min(minCost(v1)+v[0],minCost(v2)+v[n-1]);
    cout << ans << endl;
}