#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, mxW;
	cin >> N >> mxW;
	
	// first element  --> weight of item
	// second element --> value of item
	vector<pair<int,ll>> item(N);
	
	for(int i = 0; i < N; ++i)
		cin >> item[i].first >> item[i].second;
		
		
	vector<ll> dp(mxW + 1, -1);
	dp[0] = 0;
	
	ll ans = 0;
		
	for(auto x : item) {
		int weight;
		ll val;
		tie(weight, val) = x;
		for(int w = mxW - weight; w >= 0; --w) {
			if(dp[w] != -1) {
				dp[w + weight] = max(dp[w + weight], dp[w] + val);
				ans = max(ans, dp[w + weight]);
			}
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
