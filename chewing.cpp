#include <bits/stdc++.h>
using namespace std;


int main() {
    int n,k;
    cin >> n >> k;
    vector<int> gums;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if(temp < k)
            gums.push_back(temp);
    }
    sort(gums.begin(),gums.end());
    int score = 0;
    int i = 0, j = gums.size()-1;
    int size = gums.size();
    for(; i < size; i++){
        while(k-gums[i] < gums[j]){
            j--;
        }
        if(i >= j){
            break;
        }
        score += (j-i);
    }
    
    cout << score << "\n";
}