#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> bamboo(n);
    unordered_set<int> s(n);
    for(int i = 0; i < n; i++){
        cin >> bamboo[i];
        s.insert(bamboo[i]);
    }
    
    sort(bamboo.begin(), bamboo.end());

    int max = INT_MIN;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int diff = bamboo[j] - bamboo[i];
            int count = 2;
            int next = bamboo[j] + diff;
            while(s.find(next) != s.end()){
                count++;
                next += diff;
            }
            if(count > max){
                max = count;
            }
        }
    }
    cout << max << endl;
    return 0;
}