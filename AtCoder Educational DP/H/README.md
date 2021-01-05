# H - Grid 1

We have a *H x W* grid where empty and non-empty squares are denoted by `.` and `#` respectively

> Taro will start from Square (1, 1) and reach (*H*, *W*) by repeatedly moving **right** or **down** to an adjacent empty square.

### DP Statement

###### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int H, W;
	cin >> H >> W;
	
	vector<vector<bool>> grid(H, vector<bool>(W));
	
	for(int j = 0; j < H; ++j) {
		for(int i = 0; i < W; ++i) {
			char a;
			cin >> a;
			grid[j][i] = (a == '.');
		}
	}
	
	vector<vector<int>> dp(H, vector<int>(W, 0));
	
	dp[0][0] = 1;
	
	for(int j = 0; j < H; ++j) {
		for(int i = 0; i < W; ++i) {
			if(!grid[j][i]) continue;
			if(j - 1 >= 0) dp[j][i] = (dp[j][i] + dp[j-1][i]) % MOD;
			if(i - 1 >= 0) dp[j][i] = (dp[j][i] + dp[j][i-1]) % MOD;
		}
	}
	
	cout << dp[H-1][W-1] << '\n';
	
	return 0;
}
```
