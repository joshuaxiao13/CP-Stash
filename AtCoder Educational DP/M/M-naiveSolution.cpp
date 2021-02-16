#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N, K;
	cin >> N >> K;
	
	vector<int> a(N);
	for(int&x : a)
		cin >> x;
	
	vector<vector<ll>> dp(N + 1, vector<ll>(K + 1, 0));
	
	dp[0][K] = 1;
	
	for(int i = 1; i <= N; ++i) {
		for(int R = 0; R <= K; ++R) {
			for(int take = 0; take <= min(a[i-1], K - R); ++take) {
				(dp[i][R] += dp[i-1][R + take]) %= MOD;
			}
		}
	}
	
	cout << dp[N][0] << '\n';
	
	return 0;
}
