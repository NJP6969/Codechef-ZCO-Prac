#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i].first>>v[i].second;
    }
    stack<pair<int,int>> stk;
    vector<int> lb(n), rb(n);
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        while(!stk.empty() && stk.top().second >= v[i].second){ 
            stk.pop();
        }
        if(stk.empty()){ 
            lb[i] = 0;
        }else{ 
            lb[i] = stk.top().first;
        }
        stk.push(v[i]);
    }
    while(!stk.empty()){ 
        stk.pop();
    }
    for(int i = n-1; i > 0; i--){ 
        while(!stk.empty() && stk.top().second >= v[i].second){  
            stk.pop();
        }
        if(stk.empty()){ 
            rb[i] = 1e5;
        }else{ 
            rb[i] = stk.top().first;
        }
        stk.push(v[i]);
    }
    int maxArea = max(v[0].first, 100000-v[n-1].first)*500;
    
    for(int i = 0; i < n; i++){
        int len = rb[i]-lb[i]; 
        maxArea = max(maxArea, len*v[i].second); 
    }
    for(int i = 1; i < n; i++){ 
        maxArea = max(maxArea, (v[i].first-v[i-1].first)*500); 
    }
    cout<<maxArea<<'\n';
    return 0;
}