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
