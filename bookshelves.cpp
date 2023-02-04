#include <bits/stdc++.h>
using namespace std;

int skew(vector<int> a, vector<int> b, int k){
    int n = a.size();
    for(int i = 0; i < k; i++){
        if(a[n-1] > b[0]){
            swap(a[n-1], b[0]);
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
        }
    }
    return a[n-1] + b[n-1];
}
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> v1(N);
    vector<int> v2(N);
    for (int i = 0; i < N; i++) {
        cin >> v1[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> v2[i];
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int shelf1 = skew(v1, v2, K);
    int shelf2 = skew(v2, v1, K);
    cout << min(shelf1,shelf2) << "\n";
}