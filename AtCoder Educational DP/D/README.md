# D - Knapsack 1

This is a classic 0-1 knapsack problem, where we want to maximize the value of our knapsack with items that have a total weight less than or equal to the maximum
capacity of the knapsack. Let ```dp[w]``` equal the maximum value of a knapsack with weights totaling to **exactly** ```w```. The answer is then the maximum dp value
across all possible exact total weights ```w``` that we can make with the ```N``` items. 

The idea is to take each item, and build off on top of the possible total weights that the previous items could total to. It doesn't matter what order we take out 
the items, but say if there are multiple groups of items that sum up to a weight of ```x```, we want to take the group that has the maximum combined value. We don't
really care what those items are, we are more concerned with the maximum value for a total weight ```w```. Thus ```dp[sumW + w[k]] = max(dp[sumW] + value[k])```, for all ```k``` , where ```w[k]``` and ```value[k]``` is the weight and value of item ```k```, and ```sumW``` is the sum of weights for some group of items, excluding item ```k```.

For more information on Knapsack Problems, read from page 72 of this [book](https://cses.fi/book/book.pdf).

### DP Statemet

```cpp
dp[sumW + w[k]] = max(dp[sumW] + value[k])
```

for all ```k```, where ```w[k]``` and ```value[k]``` is the weight and value of item ```k```, and ```sumW``` is the sum of weights for 
some group of items, excluding item ```k```. We can preset all dp values to -1 and ```dp[0] = 0``` since a knapsack of total weight 0 will have a maximum value of 0. 
If ```dp[w] = -1```, it is impossible to make a total sum of ```w``` with the given items.

Return the maximum value of ```dp[w]``` for all valid weight-sums ```w```. We'll using a 64-bit integer to avoid overflow (due to the constraints of the problem).


###### Code 

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, mxW;
	cin >> N >> mxW;
	
	// first element  --> weight of item
	// second element --> value of item
	vector<pair<int,ll>> item(N);
	
	for(int i = 0; i < N; ++i)
		cin >> item[i].first >> item[i].second;
		
	vector<ll> dp(mxW + 1, -1);
	dp[0] = 0;
	
	ll ans = 0;
		
	for(auto x : item) {
		int weight;
		ll val;
		tie(weight, val) = x;
		for(int w = mxW - weight; w >= 0; --w) {
			if(dp[w] != -1) {
				dp[w + weight] = max(dp[w + weight], dp[w] + val);
				ans = max(ans, dp[w + weight]);
			}
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
```
