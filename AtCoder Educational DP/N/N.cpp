#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e18;

int main() {
    
  cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	vector<ll> a(N);
	
	// construct a prefix sum
	for(int i = 0; i < N; ++i) {
		cin >> a[i];
		if(i > 0) a[i] += a[i-1];
	}
	
	vector<vector<ll>> dp(N, vector<ll>(N, INF));
	
	// dp[L][R] = minimum cost to combine all elements in interval [L, R]
	// dp[L][R] = min(dp[L][i] + dp[i+1][R] + sum(L, R)) for all L <= i <= R
	
	for(int i = 0; i < N; ++i) {
		dp[i][i] = 0;
	}
	
	for(int W = 1; W <= N; ++W) {
		for(int L = 0; L + W - 1 < N; ++L) {
			for(int i = L; i < L + W - 1; ++i) {
				ll val = a[L+W-1] - (L > 0 ? a[L-1] : 0) + dp[L][i] + dp[i+1][L+W-1];
				dp[L][L+W-1] = min(dp[L][L+W-1], val); 
			}
		}
	}
	
	cout << dp[0][N-1] << '\n';
	
    	return 0;
}
