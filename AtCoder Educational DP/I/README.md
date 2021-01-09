# I - Coins

In this problem, Taro has `N` coins, each with their own probability of landing on heads. We want to find the probability that Taro flips more heads than tails after flipping all coins.

> Let *N* be a positive odd number

Since `N` is odd, we want to find the probability of flipping greater than or equal to `ceil(N/2)` coins because `ceil(N/2)` heads is the minimum number for there to be more heads than tails. This total probabilty is equal to the sum of probabilties of flipping exactly `ceil(N/2)`, `ceil(N/2) + 1`, ..., `N` heads. Let `dp[i][h]` equal the probability that Taro flips exactly `h` heads with the first `i` coins. Then, using complementary counting the answer is equal to 1 minus the probability that there are more tails than heads. This is equal to 1 minus to the sum of probabilities of flipping 0, 1, ..., `floor(N/2)` heads. 

Notice that to get `h` heads after flipping `i` coins, we must've flipped `h` or `h-1` coins after flipping the first `i-1` coins. Thus, `dp[i][h] = dp[i-1][h] + (1-p[i]) + dp[i-1][h-1] * p[i]` where `p[i]` is the probability of flipping heads with coin `i`.

### DP Statement

```cpp
dp[i][h] = dp[i-1][h] + (1-p[i]) + dp[i-1][h-1] * p[i]
```
where `p[i]` is the probability of flipping heads with coin `i`. Preset `dp[0][0] = 1` since the probability of flipping 0 heads with the first 0 coins is always equal to 1 - there are 0 heads to begin with. We either arrive at the answer by summing all probabilities of rolling greater than or equal to `ceil(N/2)` heads with the `N` coins, or use complementary counting.

###### Code 
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	
	vector<double> p(N);
	for(auto&x : p) cin >> x;
	
	vector<vector<double>> dp(N + 1, vector<double>(N + 1, 0));
	dp[0][0] = 1;
	
	for(int i = 1; i <= N; ++i) {
		for(int h = 0; h <= N; ++h) {
			dp[i][h] = dp[i-1][h] * (1 - p[i-1]);
			if(h > 0) dp[i][h] += dp[i-1][h-1] * p[i-1]; 
		}
	}
	
	double ans = 0;
  
	for(int h = 0; h <= N/2 ; ++h)
		ans += dp[N][h];
	
	ans = 1 - ans;
	
	cout << setprecision(10) << fixed << ans << '\n';
	
	return 0;
}
```
