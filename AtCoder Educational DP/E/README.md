# E - Knapsack 2

This problem is extremely similar to problem D - Knapsack 2. So similar in fact, that I thought it was the same exact problem. The difference between problem
D and E are their **constraints**. In both problems, we have at most 100 items, but in problem D, the capacity of the knapsack is at most ```1e5``` whereas in
problem E, the capacity is at most ```1e9```. This is a ***huge*** difference.

###### Code
```cpp
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
```
