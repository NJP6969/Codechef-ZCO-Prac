#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(int i, int j, vector<int> v){
    while(i <= j){
        if(v[i] == v[j]){
            i++;
            j--;
        }else{
            return false;
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> v(n),  dp(n, n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    dp[n-1] = 1;
    for(int i = n-2; i >= 0; i--){
        for(int j = n-1; j >= i; j--){
        
            if(isPalindrome(i, j, v)){
                if(j == n-1){ 
                    dp[i] = 1; 
                }
                else{ 
                    dp[i] = min(dp[i], dp[j+1]+1);
                }
            }
        }
    }
    cout<<dp[0];
    return 0;
}