# L - Deque

### DP Statement

##### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	vector<ll> a(N);
	
	for(ll&x : a)
		cin >> x;
		
	vector<vector<ll>> dp(N, vector<ll>(N, 0));
	
	for(int L = N - 1; L >= 0; --L) {
		dp[L][L] = a[L];
		for(int R = L + 1; R < N; ++R) {
			if(L + 1 < N) dp[L][R] = a[L] - dp[L+1][R];
			if(R - 1 >= 0) dp[L][R] = max(dp[L][R], a[R] - dp[L][R-1]);
		}
	}
	
	cout << dp[0][N-1];
	
	return 0;
}
```
