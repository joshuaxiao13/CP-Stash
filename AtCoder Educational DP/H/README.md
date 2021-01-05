# H - Grid 1

We have a *H x W* grid where empty and non-empty squares are denoted by `.` and `#` respectively.

> Taro will start from Square (1, 1) and reach (*H*, *W*) by repeatedly moving **right** or **down** to an adjacent empty square.

Notice that to land on square (*j*, *i*), Taro must've previously been on squares (*j* - 1, *i*) or (*j*, *i* - 1). This is because Taro is restricted to only moving right and down. Thus, the total number of paths to a certain square is equal to the sum of the number of paths to get to the west and north squares, relative to square (*j*, *i*). We can use this recursive relationship to form our dp statement. 

Let `dp[j][i]` equal the number of paths from square (1, 1) to (*j*, *i*). Thus, `dp[j][i] = dp[j-1][i] + dp[j][i-1]` if and only if square (*j*, *i*) is empty. There are zero possible paths for Taro to land on an non-empty square. Return `dp[H-1][W-1]`, the total number of paths to land on the bottom-right square.

### DP Statement
```cpp 
if(square (j, i) is empty) dp[j][i] = dp[j-1][i] + dp[j][i-1]
```

We preset all dp values to zero, because there are initially zero paths to each square. Return `dp[H-1][W-1]`, the total number of paths to land on the bottom-right square.

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
