#include <bits/stdc++.h>
using namespace std;

#define times(n) for (int i=0;i<n;i++)
typedef std::vector<long> vi;

int main(){
    long long n;
    long long k;
    long long temp; 
    vector<long long int> v;
    cin >> n >> k;    
    
    while(n--){
        cin >> temp;
        if (temp < k){
            v.push_back(temp);
        }
    }
    
    sort(v.begin(),v.end()); 
    
    long long score =0;
    n=v.size();
    temp=n-1;
    
    for(int i = 0; i < n; i++){
        while (k-v[i]<= v[temp]){
            temp--;
        }
        if (i>=temp){
            break;
        }
        score += (temp-i);
    }
    
    
    cout << score << "\n";
    return 0;
}