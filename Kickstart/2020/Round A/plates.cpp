#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define f  first
#define s  second

using ll = long long;
using vi = vector<int>;

int solve() {
	int N, K, P;
	cin >> N >> K >> P;
	vector<vi> psum(N, vi(K));
	for(int j = 0; j < N; ++j) {
		for(int i = 0; i < K; ++i) {
			cin >> psum[j][i];
			if(i > 0) psum[j][i] += psum[j][i-1];
		}
	}

	// dp[i][r] = max beauty so far after selecting 0 or 
	// more plates from stack 'i' with 'r' remaining plates

	vector<vi> dp(N, vi(P + 1, 0));
	for(int take = 1; take <= K; ++take) {
		for(int R = P - take; R >= 0; --R) {
			dp[0][R] = max(dp[0][R], psum[0][take-1]);
		}
	}

	int ans = dp[0][0];

	for(int i = 1; i < N; ++i) {
		for(int take = 1; take <= K; ++take) {
			for(int R = P - take; R >= 0; --R) {
				dp[i][R] = max({dp[i][R], dp[i-1][R], dp[i-1][R+take] + psum[i][take-1]});
				if(R == 0) ans = max(ans, dp[i][R]);
			}
		}
	}

	return ans;
}

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i)
		cout << "Case #" << i << ": " << solve() << '\n';
	return 0;
}	
