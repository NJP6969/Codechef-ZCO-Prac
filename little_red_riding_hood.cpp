#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> safe(502, vector<bool>(502));
int dp[502][502] = {INT_MIN}; 

vector<vector<int>> v(502, vector<int>(502));
int n, m;
void isSafe(int x, int y, int k){
    for(int i = max(1, x-k); i <= min(n, x+k); i++){
        for(int j = max(1, y-k); j <= min(n, y+k); j++){
            if((abs(x-i) + abs(y-j)) <= k){
                safe[i][j] = true;
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>v[i][j];
        }
    }
    for(int i = 1; i <= m; i++){
        int x,y,k;
        cin>>x>>y>>k;
        isSafe(x, y, k);
    }
    
    safe[0][1] = safe[1][0] = true;
    dp[0][1] = dp[1][0] = 0;

    if(safe[1][1] == false){
        cout<<"NO\n";
        return 0;
    }
    for(int i = 1; i <= n; i++){ 
        for(int j = 1; j <= n; j++){
            if(safe[i][j]){
                if(safe[i-1][j] && safe[i][j-1]){
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + v[i][j];
                }
                else if(safe[i-1][j]){
                    dp[i][j] = dp[i-1][j] + v[i][j];
                }
                else if(safe[i][j-1]){
                    dp[i][j] = dp[i][j-1] + v[i][j];
                }
            }
        }
    }
    if(dp[n][n] == INT_MIN){
        cout<<"NO";
    }else{
        cout<<"YES\n"<<dp[n][n];
    }
    return 0;
}