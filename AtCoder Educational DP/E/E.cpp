#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, mxW, mxVal = 0;
	cin >> N >> mxW;
	
	// first element  --> weight of item
	// second element --> value of item
	vector<pair<ll,int>> item(N);
	
	for(int i = 0; i < N; ++i) {
		cin >> item[i].first >> item[i].second;
		mxVal += item[i].second;
	}
	
	vector<ll> dp(mxVal + 1, INF);
	dp[0] = 0;
	
	int ans = 0;
		
	for(auto x : item) {
		ll weight;
		int val;
		tie(weight, val) = x;
		for(int v = mxVal - val; v >= 0; --v) {
			if(dp[v] != INF && dp[v] + weight <= mxW) {
				dp[v + val] = min(dp[v + val], dp[v] + weight);
				ans = max(ans, v + val);
			}
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
