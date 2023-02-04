#include <bits/stdc++.h>
using namespace std;

int main() {
    int testcases;
    cin >> testcases;
    while(testcases--){
        int n;
        cin >> n;
        vector<pair<int,int>> low, high;
        for(int i = 0; i < n; i++){
            int l, h;
            cin >> l >> h;
            low.push_back(make_pair(l,i));
            high.push_back(make_pair(h,i));
        }
        sort(low.begin(), low.end());
        sort(high.rbegin(), high.rend());
        vector<int> score(n);

        for(int i = 0; i < n; i++){
            score[low[i].second] += (n-i)-1;
            score[high[i].second] += (n-i)-1;
        }
        for(auto c: score){
            cout << c << " ";
        }
        cout << "\n";
    }
}