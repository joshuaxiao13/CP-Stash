# B - Frog 2

This problem is very similar to problem A - Frog 1, except in problem B, the frog is not limited to jumping a maximum of 2 stones ahead.
Instead, we are are given a positive integer ```K```, which represents the maximum number of stones the frog can jump ahead from its current stone.
We can modify our code from problem A, by running two for-loops. Similar to problem A, let ```dp[i]``` equal the minimum cost to land on stone ```i```. 
Then ```dp[i]``` is equal to the minimum total cost of jumping from any stone a maximum distance of ```K``` behind. Keep in mind that
we don't want the frog to jump out of bounds, so if the frog is currently at stone ```i``` it could've previously been at any stone a maximum distance
of ```min(i, K)``` behind.

### DP statement
```cpp
dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]))
```
for all positive ```j``` less than or equal to ```min(i, K)```. We preset all DP values to a large enough value, and ```dp[0] = 0``` because it costs zero to land on the first stone (we start off on stone 0).

Return ```dp[N-1]```, the minimum cost to jump to the last stone.

###### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	
	vector<int> h(N);
	for(int&x : h) cin >> x;
	
	vector<int> dp(N, INT_MAX);
	dp[0] = 0;
	
	for(int i = 1; i < N; ++i) {
		for(int j = 1; j <= min(i, K); ++j) {
			dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
		}
	}
	
	cout << dp[N-1] << '\n';
	
	return 0;
}
```
