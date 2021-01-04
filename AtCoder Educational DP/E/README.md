# E - Knapsack 2

This problem is extremely similar to problem D - Knapsack 2. So similar in fact, I thought it was the same exact problem, so I submitted the code from the previous
problem, and got WA. Again, we want to find the maximum value of items we can put inside our knapsack.

The difference between problem D and E are their **constraints**. In both problems, we have at most 100 items, but in problem D, the capacity of the knapsack is at most ```1e5``` whereas in problem E, the capacity is at most ```1e9```. This is a ***huge*** difference, because it means we can't use the exact same approach in problem D. 
We can't possible store a billion dp values in array. So, we need to modify our approach.

If we look at the constraint on the value of each item, we see that this number is no greater than ```1e3```. Since there are at most 100 items, the maximum value of items
we can get is ```1e5```. It is perfectly fine to have an array of ```1e5``` elements. Thus, we will work in terms of the value of a group of items, instead of it's total weight-sum as in problem D.

As in the previous problem, our knapsack is limited to a maximum capacity. Let ```dp[v]``` equal the minimum weight-sum of a group of objects with a values totaling to ```v```.
We want the minimum weight-sum because we want to be able to build on top of this total value ```v``` by adding more items, in order to increase the total value of items. The
only thing we need to watch out for is that ```dp[v]``` does not pass the maximum capicity of the knapsack. The answer is simply the maximum value ```v``` for all valid ```dp[v]```.

### DP Statement

`dp[v]` = minimum weight-sum to make a knapsack worth ```v```

Preset all dp values to ```INF = 1e18``` or any number large enough and ```dp[0] = 0``` since a bag of zero weight is worth 0.

Return the maximum ```v``` such that we can build a knapsack worth ```v```.

If ```dp[k] = 0```, that means there is no possible way to build a knapsack with a total value ```k``` from the given items.

###### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, mxW, mxVal = 0;
	cin >> N >> mxW;
	
	// first element  --> weight of item
	// second element --> value of item
	vector<pair<ll,int>> item(N);
	
	for(int i = 0; i < N; ++i) {
		cin >> item[i].first >> item[i].second;
		mxVal += item[i].second;
	}
	
	vector<ll> dp(mxVal + 1, INF);
	dp[0] = 0;
	
	int ans = 0;
		
	for(auto x : item) {
		ll weight;
		int val;
		tie(weight, val) = x;
		for(int v = mxVal - val; v >= 0; --v) {
			if(dp[v] != INF && dp[v] + weight <= mxW) {
				dp[v + val] = min(dp[v + val], dp[v] + weight);
				ans = max(ans, v + val);
			}
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
```
