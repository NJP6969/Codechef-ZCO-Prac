#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long

int main() {
	ll t, n;
	cin>>n>>t;
	vector<ll> nums(n);
	vector<ll> pairs(t+1);

	rep(i, 0, n) {
		cin>>nums[i];
		// fr[nums[i]] += 1;
	}

	if(n < 4) {
		cout<<0<<endl;
		return 0;
	}

	ll tsum = nums[0] + nums[1];
	if(tsum <= t) {
		pairs[tsum] = 1;
	}

	ll result = 0;
	ll x = 0;

	rep(i, 2, n-1) {
		rep(j, i+1, n) {
			x = nums[i] + nums[j];
			if(x > t) continue;
			result += pairs[t - x];
		}

		rep(j, 0, i) {
			x = nums[i] + nums[j];
			if(x <= t) {
				pairs[x] += 1;
			}
		}
	}

	cout<<result<<endl;
}