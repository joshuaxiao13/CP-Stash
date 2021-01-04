###### A work in progress...

# AtCoder Educational DP


The AtCoder Educational DP is a problem set consisting of 26 standard dynamic programming (DP) problems. 
It's a great resource for those who are starting DP, and for those who are brushing up on their skills.
Here, **you can find my code (in C++) and explainations** for each one of the problems.

#### Problems - Click [here](https://atcoder.jp/contests/dp/tasks) for the full list of tasks

Problem | Editorial + Code
------- | ----------------
A - [Frog 1](https://atcoder.jp/contests/dp/tasks/dp_a)| [Explaination](#a---frog-1) 
B - [Frog 2](https://atcoder.jp/contests/dp/tasks/dp_b)| [Explaination](#b---frog-2)
C - [Vacation](https://atcoder.jp/contests/dp/tasks/dp_c) | [Explaination](#c---vacation)
D - [Knapsack 1](https://atcoder.jp/contests/dp/tasks/dp_d) | [Explaination](#d---knapsack-1)
E - [Knapsack 2](https://atcoder.jp/contests/dp/tasks/dp_e) | [Explaination](#e---knapsack-2)


# A - Frog 1

The frog can only jump 1 or 2 stones ahead from the stone that the frog is currently on. Thus, to jump to stone ```i```, 
the frog must've previously been on stone ```i-1``` or ```i-2```. Let ```dp[i]``` equal the minimum cost to jump to stone ```i```, and 
```cost(a, b)``` equal the cost to jump from stone ```a``` to stone ```b```. Then, 
```dp[i] = min(dp[i-1] + cost(i-1, i) , dp[i-2] + cost(i-2, i))```. We are told from the problem
that the cost to jump from stone ```a``` to stone ```b``` is the absolute value of the difference of their heights. Thus,

### DP Statement

```cpp 
dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]))
```
Return ```dp[N-1]```, the minimum cost to jump to the last stone.

###### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	
	vector<int> h(N);
	for(int&x : h) cin >> x;
	
	vector<int> dp(N, 0);
	
	for(int i = 1; i < N; ++i) {
		dp[i] = dp[i-1] + abs(h[i] - h[i-1]);
		if(i - 2 >= 0) dp[i] = min(dp[i], dp[i-2] + abs(h[i] - h[i-2]));
	}
	
	cout << dp[N-1] << '\n';
	
	return 0;
}
```



# B - Frog 2

This problem is very similar to problem A - Frog 1, except in problem B, the frog is not limited to jumping a maximum of 2 stones ahead.
Instead, we are are given a positive integer ```K```, which represents the maximum number of stones the frog can jump ahead from its current stone.
We can modify our code from problem A, by running two for-loops. Similar to problem A, let ```dp[i]``` equal the minimum cost to land on stone ```i```. 
Then ```dp[i]``` is equal to the minimum total cost of jumping from any stone a maximum distance of ```K``` behind. Keep in mind that
we don't want the frog to jump out of bounds, so if the frog is currently at stone ```i``` it could've previously been at any stone a maximum distance
of ```min(i, K)``` behind.

### DP statement
```cpp
dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]))
```
for all positive ```j``` less than or equal to ```min(i, K)```. We preset all DP values to a large enough value, and ```dp[0] = 0``` because it costs zero to land on the first stone (we start off on stone 0).

Return ```dp[N-1]```, the minimum cost to jump to the last stone.

###### Code
```cpp
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
```




# C - Vacation

In this problem, Taro needs to build a ```N``` day schedule where he can do one of three activites each day. We want to maximize his happiness.

> As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.

In other words, Taro cannot swim in the sea today, and swim in the sea again tomorrow. He must do different activites on consecutive days. Let ```dp[day][i]``` equal the maximum happiness Taro can have at the end of day ```day``` if he chooses to do activity ```i``` on day ```day```. Since there are only three activites, they will be represented by ```i = 0```, ```i = 1```, and ```i = 2```. 

Then, ```dp[day][i]``` is equal to the sum of the happiness Taro gets from doing activity ```i``` on day ```day``` and the maximum happiness at the end of the previous day from doing either of the two activites not equal to ```i```. Let ```happiness[i][day]``` equal the happiness Taro recieves from doing activity ```i``` on day ```day``` (these values are given to us).

### DP Statement

```cpp
dp[day][i] = max(dp[day-1][j], dp[day-1][k]) + happiness[i][day];
```

where ```j``` and ```k``` are the other 2 activties, not equal to ```i```. 

Return ```max(dp[N-1][0], dp[N-1][1], dp[N-1][2])```, the maximum happiness Taro gains after ```N``` days.

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
some group of items, excluding item ```k```. We can preset all dp values to -1. If ```dp[w] = -1```, it is impossible to make a total sum of ```w``` with the given items.

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



# E - Knapsack 2

This problem is extremely similar to problem D - Knapsack 2. So similar in fact, I thought it was the same exact problem, so I submitted the code from the previous
problem, and got WA. Again, we want to find the maximum value of items we can put inside our knapsack.

The difference between problem D and E are their **constraints**. In both problems, we have at most 100 items, but in problem D, the capacity of the knapsack is at most ```1e5``` whereas in problem E, the capacity is at most ```1e9```. This is a ***huge*** difference, because it means we can't use the exact same approach in problem D. 
We can't possibly store a billion dp values in array. So, we need to modify our approach.

If we look at the constraint on the value of each item, we see that this number is no greater than ```1e3```. Since there are at most 100 items, the maximum value of items
we can possibly get is at ```1e5```, not accounting for the weight capacity. It is perfectly fine to have an array of ```1e5``` elements. Thus, we will work in terms of the value of a group of items, instead of it's total weight-sum as in problem D.

As in the previous problem, our knapsack is limited to a maximum capacity. Let ```dp[v]``` equal the minimum weight-sum of a group of objects with values totaling to ```v```.
We want the minimum weight-sum for a given total value ```v```` because we want to be able to build on top of this total value ```v``` by adding more items in order to 
increase the total value of our knapsack. The only thing we need to watch out for is that ```dp[v]``` does not pass the maximum capicity of the knapsack. The answer is simply the maximum value ```v``` for all possible ways to fill up the knapsack. The code for this problem is very similar to problem D.

### DP Statement

`dp[v]` = minimum weight-sum to make a knapsack worth ```v```

Preset all dp values to ```1e18``` or any number large enough. ```dp[0] = 0``` since a bag of zero weight is worth 0.

Return the maximum ```v``` such that we can build a knapsack worth ```v```.

If ```dp[k] = 0```, that means there is no possible way to build a knapsack with a total value of ```k``` from the given items.

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
