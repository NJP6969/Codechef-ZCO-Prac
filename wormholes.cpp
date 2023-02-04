#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,x,y;
    cin>>n>>x>>y;
    
    vector<pair<int,int>> t(n);
    for(int i = 0; i < n; i++){
        cin>>t[i].first>>t[i].second;
    }
    set<int> vWormHole, wWormHole;
    for(int i = 0; i < x; i++){
        int x;
        cin>>x;
        vWormHole.insert(x);
    }
    for(int i = 0; i < y; i++){
        int x;
        cin>>x;
        wWormHole.insert(x);
    }
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        int t1, t2;
        auto itr = vWormHole.upper_bound(t[i].first);
        if(itr!=vWormHole.begin()){
            itr--;
            t1 = *itr;
        }else{
            continue;
        }
        itr = wWormHole.lower_bound(t[i].second);
        if(itr!=wWormHole.end()){
            t2 = *itr;
        }else{
            continue; 
        }
        ans = min(ans,(t2-t1)+1);
    }
    cout<<ans;
    return 0;
}