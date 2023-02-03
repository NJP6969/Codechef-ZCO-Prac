#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int depth = 0;
    int max_depth = 0;
    int pos_max = 0;
    int seq = 0;
    int max_seq = 0;
    int pos_seq = 0;
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        if(c == 1){
            v.push_back(make_pair(c,i));
            depth++;
            if(depth > max_depth){
                max_depth = depth;
                pos_max = i;
            }
        }
        else{
            pair<int,int> p = v.back();
            v.pop_back();
            
            seq = i - p.second + 1;
            if(seq > max_seq){
                max_seq = seq;
                pos_seq = p.second;
            }
            depth--;
        }
    }
    cout << max_depth << " " << pos_max + 1 << " " << max_seq << " " << pos_seq + 1 << "\n";
}