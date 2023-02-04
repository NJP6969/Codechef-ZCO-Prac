#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int seq_1 = 0;
    int seq_2 = 0;
    int max_seq_1 = 0;
    int max_seq_2 = 0;

    vector<pair<int,int>> v;
    string s = "";
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        if(c == 1) {
            s += "(";
            v.push_back(make_pair(c,i));
        }

        else if(c == 2) {
            s += ")";
            pair<int,int> p = v.back();
            v.pop_back();
            
            seq_1 = i - p.second + 1;
            if(seq_1 > max_seq_1){
                max_seq_1 = seq_1;
            }
        }

        else if(c == 3) {
            s += "[";
            v.push_back(make_pair(c,i));
        }
        else{
            s += "]";
            pair<int,int> p = v.back();
            v.pop_back();
            seq_2 = i - p.second + 1;
            if(seq_2 > max_seq_2){
                max_seq_2 = seq_2;
            }
        }
    }

    stack<pair<char, int>> stk;
    vector<int> closingP(n, -1);
    vector<int> closingSq(n, -1);
    
    int currAltD = 0, maxAltD = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '(' || s[i] == '['){
            if(stk.empty() || stk.top().first != s[i]){ // checking if the before opening bracket is different then the curr opening bracket
                currAltD++;
            }
            maxAltD = max(maxAltD, currAltD);
            stk.push({s[i], i});
        }else if(s[i] == ')'){
            closingP[stk.top().second] = i;
            stk.pop();
            if(stk.empty() || stk.top().first == '['){
                currAltD--;
            }
            
        }else if(s[i] == ']'){
            closingSq[stk.top().second] = i;
            stk.pop();
            if(stk.empty() || stk.top().first == '('){
                currAltD--;
            }
        }
    }
    cout << maxAltD << " " << max_seq_1 << " " << max_seq_2 << "\n";
}