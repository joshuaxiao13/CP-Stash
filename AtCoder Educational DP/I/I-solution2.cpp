#include <bits/stdc++.h>
using namespace std;

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	
	vector<double> p(N);
	for(auto&x : p) cin >> x;
	
	vector<double> dp(N + 1, 0);
	dp[0] = 1;
	
	for(int i = 1; i <= N; ++i) {
		for(int h = N; h >= 0; --h) {
			dp[h] = dp[h] * (1 - p[i-1]);
			if(h > 0) dp[h] += dp[h-1] * p[i-1]; 
		}
	}
	
	double ans = 0;
	
	for(int h = 0; h <= N/2 ; ++h)
		ans += dp[h];
	
	ans = 1 - ans;
	
	cout << setprecision(10) << fixed << ans << '\n';
	
	return 0;
}
