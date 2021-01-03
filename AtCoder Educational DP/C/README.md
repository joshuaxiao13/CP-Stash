# C - Vacation

In this problem, Taro needs to build a ```N``` day schedule where he can do one of three activites each day. We want to maximize his happiness.

> As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.

In other words, Taro cannot swim in the sea today, and swim in the sea again tomorrow. He must do different activites on consecutive days. Let ```dp[day][i]``` equal the maximum happiness Taro can have at the end of day ```day``` if he chooses to do activity ```i``` on day ```day```. Since there are only three activites, they will be represented by ```i = 0```, ```i = 1```, and ```i = 2```. Then, ```dp[day][i]``` is equal to the sum of the happiness Taro gets from doing activity ```i``` on day ```day``` and the maximum happiness at the end of the previous day from doing either of the two activites not equal to ```i```. Let ```happiness[i][day]``` equal the happiness Taro recieves from doing activity ```i``` on day ```day``` (these values are given to us).

### DP Statement

```cpp
dp[day][i] = max(dp[day-1][j], dp[day-1][k]) + happiness[i][day];
```

where ```j``` and ```k``` are the other 2 activties, not equal to ```i```. 

Return the ```max({dp[N-1][0], dp[N-1][1], dp[N-1][2]})```, the maximum happiness Taro gains after ```N``` days.

###### Code
```cpp
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
	
	cout << max({dp[N-1][0], dp[N-1][1], dp[N-1][2]})<< '\n';
	
	return 0;
}
```
