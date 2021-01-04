#include <bits/stdc++.h>
using namespace std;

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	
	vector<vector<int>> happiness(3, vector<int>(N));
	
	for(int day = 0; day < N; ++day) {
		for(int i = 0; i < 3; ++i) {
			cin >> happiness[i][day];
		}
	}
	
	vector<vector<int>> dp(N, vector<int>(3));
	
	for(int i = 0; i < 3; ++i)
		dp[0][i] = happiness[i][0];
	
	for(int day = 1; day < N; ++day) {
		for(int i = 0; i < 3; ++i) {
			for(int j = 0; j < 3; ++j) {
				if(j == i) continue;
				dp[day][i] = max(dp[day][i], dp[day-1][j] + happiness[i][day]);
			}
		}
	}
	
	cout << max({dp[N-1][0], dp[N-1][1], dp[N-1][2]}) << '\n';
	
	return 0;
}
