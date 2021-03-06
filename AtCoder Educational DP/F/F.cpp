#include <bits/stdc++.h>
using namespace std;

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s, t;
	cin >> s >> t;
	
	int n = s.size();
	int m = t.size();
	
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>> choice(n + 1, vector<int>(m + 1, -1));
	
	for(int j = 1; j <= n; ++j) {
		for(int i = 1; i <= m; ++i) {
			if(s[j-1] == t[i-1]) {
				dp[j][i] = dp[j-1][i-1] + 1;
				choice[j][i] = 0;
			}
			else if(dp[j-1][i] > dp[j][i-1]){
				dp[j][i] = dp[j-1][i];
				choice[j][i] = 1;
			}
			else {
				dp[j][i] = dp[j][i-1];
				choice[j][i] = 2;
			}
		}
	}
	
	string ans = "";
	
	while(dp[n][m]--) {
		while(choice[n][m] != 0) {
			if(choice[n][m] == 1) --n;
			else --m; 
		}
		ans += s[n-1];
		--n, --m;
	}

	reverse(ans.begin(), ans.end());
	
	cout << ans << '\n';
	
	return 0;
}
