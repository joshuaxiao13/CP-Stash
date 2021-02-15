###### A work in progress...

# AtCoder Educational DP


The AtCoder Educational DP is a collection of 26 standard dynamic programming (DP) problems. 
It's a great resource for those who are starting DP, and for those who are brushing up on their skills.
Here, **you can find my code (in C++) and explainations** for each one of the problems. For the full list of problems,
click [here](https://atcoder.jp/contests/dp/tasks).

Problem | Editorial + Code
------- | ----------------
A - [Frog 1](https://atcoder.jp/contests/dp/tasks/dp_a)| [Explaination](#a---frog-1) 
B - [Frog 2](https://atcoder.jp/contests/dp/tasks/dp_b)| [Explaination](#b---frog-2)
C - [Vacation](https://atcoder.jp/contests/dp/tasks/dp_c) | [Explaination](#c---vacation)
D - [Knapsack 1](https://atcoder.jp/contests/dp/tasks/dp_d) | [Explaination](#d---knapsack-1)
E - [Knapsack 2](https://atcoder.jp/contests/dp/tasks/dp_e) | [Explaination](#e---knapsack-2)
F - [LSC (Longest Common Subsequence)](https://atcoder.jp/contests/dp/tasks/dp_f) | [Explaination](#f---lcs-longest-common-subsequence)
G - [Longest Path](https://atcoder.jp/contests/dp/tasks/dp_g) | [Explaination](#g---longest-path)
H - [Grid 1](https://atcoder.jp/contests/dp/tasks/dp_h) | [Explaination](#h---grid-1)
I - [Coins](https://atcoder.jp/contests/dp/tasks/dp_i) | [Explaination](#i---coins)
J - [Sushi](https://atcoder.jp/contests/dp/tasks/dp_j) | ???
K - [Stones](https://atcoder.jp/contests/dp/tasks/dp_k) | [Explaination](#k---stones)
L - [Deque](https://atcoder.jp/contests/dp/tasks/dp_l) |
M - [Candies](https://atcoder.jp/contests/dp/tasks/dp_m) | 
N - [Slimes](https://atcoder.jp/contests/dp/tasks/dp_n) | 
O - [Matching](https://atcoder.jp/contests/dp/tasks/dp_o) | 
P - [Independent Set](https://atcoder.jp/contests/dp/tasks/dp_p) | 



# A - Frog 1

> If the frog is currently on Stone `i`, jump to Stone `i+1` or Stone `i+2`.

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

##### [Go to top of page](#atcoder-educational-dp)


# B - Frog 2

This problem is very similar to problem A - Frog 1, except in problem B, the frog is not limited to jumping a maximum of 2 stones ahead.
Instead, we are are given a positive integer ```K```, which represents the maximum number of stones the frog can jump ahead from its current stone.
We can modify our code from problem A, by running two for-loops. Similar to problem A, let ```dp[i]``` equal the minimum cost to land on stone ```i```. 
Then ```dp[i]``` is equal to the minimum total cost of jumping from any stone a maximum distance of ```K``` behind. Keep in mind that
we don't want the frog to jump out of bounds, so if the frog is currently at stone ```i``` it could've previously been at any stone a maximum distance
of ```min(i, K)``` behind.

### DP statement
```cpp
dp[i] = min(dp[i-j] + abs(h[i] - h[i-j]))
```
for all positive ```j``` less than or equal to ```min(i, K)```. We preset all dp values to a large enough value, and ```dp[0] = 0``` because it costs zero to land on the first stone (we start off on stone 0).

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

##### [Go to top of page](#atcoder-educational-dp)


# C - Vacation

In this problem, Taro needs to build a ```N``` day schedule where he can do one of three activites each day. We want to maximize his happiness.

> As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.

In other words, Taro cannot swim in the sea today, and swim in the sea again tomorrow. He must do different activites on consecutive days. Let ```dp[day][i]``` equal the maximum happiness Taro can have at the end of day ```day``` if he chooses to do activity ```i``` on day ```day```. Since there are only three activites, they will be represented by ```i = 0```, ```i = 1```, and ```i = 2```. 

Then, ```dp[day][i]``` is equal to the sum of the happiness Taro gets from doing activity ```i``` on day ```day``` and the maximum happiness at the end of the previous day from doing either of the two activites not equal to ```i```. Let ```happiness[i][day]``` equal the happiness Taro recieves from doing activity ```i``` on day ```day``` (these values are given to us).

### DP Statement

```cpp
dp[day][i] = max(dp[day-1][j], dp[day-1][k]) + happiness[i][day];
```

where ```j``` and ```k``` are the other 2 activities, not equal to ```i```. 

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
	
	cout << max({dp[N-1][0], dp[N-1][1], dp[N-1][2]}) << '\n';
	
	return 0;
}
```

##### [Go to top of page](#atcoder-educational-dp)


# D - Knapsack 1

This is a classic 0-1 knapsack problem, where we want to maximize the value of our knapsack with items that have a total weight less than or equal to the maximum
capacity of the knapsack. Let ```dp[w]``` equal the maximum value of a knapsack with weights totaling to **exactly** ```w```. The answer is then the maximum dp value
across all possible exact total weights ```w``` that we can make with the ```N``` items. 

The idea is to take each item, and build off on top of the possible total weights that the previous items could total to. It doesn't matter what order we take out 
the items, but say if there are multiple groups of items that sum up to a weight of ```x```, we want to take the group that has the maximum combined value. We don't
really care what those items are, we are more concerned with the maximum value for a total weight ```w```. Thus ```dp[sumW + w[k]] = max(dp[sumW] + value[k])```, for all ```k``` , where ```w[k]``` and ```value[k]``` is the weight and value of item ```k```, and ```sumW``` is the sum of weights for some group of items, excluding item ```k```.

For more information on Knapsack Problems, read from page 72 of this [book](https://cses.fi/book/book.pdf).

### DP Statement

```cpp
dp[sumW + w[k]] = max(dp[sumW] + value[k])
```

for all ```k```, where ```w[k]``` and ```value[k]``` is the weight and value of item ```k```, and ```sumW``` is the sum of weights for 
some group of items, excluding item ```k```. We can preset all dp values to -1, and ```dp[0] = 0``` since a knapsack of total weight 0 will have a maximum value of 0.
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

##### [Go to top of page](#atcoder-educational-dp)

# E - Knapsack 2

This problem is extremely similar to problem D - Knapsack 1. Again, we want to find the maximum value of items we can put inside our knapsack.

The difference between problem D and E are their **constraints**. In both problems, we have at most 100 items, but in problem D, the capacity of the knapsack is at most ```1e5``` whereas in problem E, the capacity is at most ```1e9```. This is a ***huge*** difference, because it means we can't use the exact same approach in problem D. 
We can't possibly store a billion dp values in array. So, we need to modify our approach.

If we look at the constraint on the value of each item, we see that this number is no greater than ```1e3```. Since there are at most 100 items, the maximum value of items
we can possibly get is at ```1e5```, not accounting for the weight capacity. It is perfectly fine to have an array of ```1e5``` elements. Thus, we will work in terms of the value of a group of items, instead of its total weight-sum as in problem D.

As in the previous problem, our knapsack is limited to a maximum capacity. Let ```dp[v]``` equal the minimum weight-sum of a group of objects with values totaling to exactly ```v```. We want the minimum weight-sum for a given total value ```v``` because we want to be able to build on top of this total value ```v``` by adding more items in order to 
increase the total value of our knapsack. The only thing we need to watch out for is that ```dp[v]``` does not pass the maximum capicity of the knapsack. The answer is simply the maximum value ```v``` for all possible ways to fill up the knapsack. The code for this problem is very similar to problem D.

### DP Statement

`dp[v]` = minimum weight-sum to make a knapsack worth ```v```.

Preset all dp values to ```1e18```, or any number large enough. ```dp[0] = 0``` since a bag of zero weight is worth 0. Return the maximum ```v``` such that we can build a knapsack worth ```v```.

If ```dp[k] = 1e18```, there is no possible way to build a knapsack with a total value of ```k``` from the given items. We'll use a 64-bit integer to avoid overflow
(maximum sum of weights is ```1e11```).

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

##### [Go to top of page](#atcoder-educational-dp)


# F - LCS (Longest Common Subsequence)

In this problem, we need to find the longest subsequence shared by strings ```s``` and ```t```. First, we'll deal with the length of the LCS. Let ```dp[j][i]``` equal the length of the LCS between the prefix of ```s``` of length ```j``` and the prefix of ```t``` of length ```i```. If ```s[j]``` equals ```t[i]```, then ```dp[j][i] = dp[j-1][i-1] + 1```. Else, ```dp[j][i] = max(dp[j-1][i], dp[j][i-1])```. This is because if the characters at the back of each prefix are equal, we can include that character in our LCS, and find the LCS for the remainder of the prefixes. Else, we want to find the LCS by removing one character from the back of either prefix, amd find the LCS of the remainder of the prefixes. The LCS of the two strings is thus ```dp[n][m]``` where ```n``` and ```m``` are the lengths of ```s``` and ```t``` respectively.

Now the challenge is to find the subsequence, not just the length. We can keep track, for each dp state, whether it is optimal to 

1. take the back character common to both prefixes and add it to the LCS
2. or throw away the back character from the prefix of ```s```
2. or throw away the back character from the prefix of ```t```. 

Let ```choice[j][i]``` represent the optimal choice we can make when we have prefixes of ```s``` and ```t``` as described above. ```choice[j][i] = 0``` if we include the back character in our LCS, ```choice[j][i] = 1``` if we throw away the back letter of the prefix of ```s```, and ```choice[j][i] = 2``` if we throw away the back letter of the prefix of ```t```.

### DP Statement

```cpp
if(s[j] == t[i]) dp[j][i] = dp[j-1][i-1] + 1
else dp[j][i] = max(dp[j-1][i], dp[j][i-1])
```

We preset all dp values to ```0```. ```dp[n][m]``` will be the length of the LCS, where ```n``` and ```m``` are the lengths of ```s``` and ```t``` respectively.
We can use the 2-D arary ```choice``` to trace back the optimal choices.

###### Code
```cpp
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
```

##### [Go to top of page](#atcoder-educational-dp)


# G - Longest Path

> *G* does not contain directed cycles

We're given a **directed acyclic graph** (DAG) that does not contain any cycles. We want to find the longest directed path in the DAG, so we can try finding the longest path ending at every vertex ```v```, and take the longest path out of all paths. Let ```dp[v]``` equal the longest path ending at vertex ```v```. In order to calculate ```dp[v]```, we need to somehow find the dp values for the vertices that are directed towards node ```v```, since any path to vertex ```v``` can start from a vertex that is directed towards ```v```. This can be acheived with a [topological sort](https://csacademy.com/lesson/topological_sorting/) of the vertices. Since we are told that the graph is acylic, there exists a valid topological sort.

After we perform the toplogical sort, we can calculate the dp values using the fact that the longest path to vertex ```v``` can be used to calculate the longest path to the directed vertices from ```v```, which we can call ```u```. Thus, for every vertex ```u```, ```dp[u] = max(dp[v] + 1)```, for all vertices ```v``` where ```u``` is directed from ```v```. Return the maximum dp value we encounter.

### DP Statement

```cpp
dp[u] = max(dp[v] + 1)
```
for all vertices ```v``` where ```u``` is a directed vertex from ```v```. Preset all dp values to 0 since the length of a vertex to itself is 0. Return the maximum dp value encountered.

###### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;

vector<int> adj[mxN];
bool vis[mxN];
vector<int> topoSort;

void dfs(int u) {
	vis[u] = true;
	for(auto v : adj[u]) {
		if(!vis[v]) dfs(v);
	}	
	topoSort.push_back(u);
}

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	
	while(M--) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
	}
	
	for(int i = 0; i < N; ++i) {
		if(!vis[i]) dfs(i);
	}
	
	reverse(topoSort.begin(), topoSort.end());
	
	vector<int> dp(N, 0);
	
	int ans = 0;
	
	for(int i = 0; i < N; ++i) {
		int u = topoSort[i];
		for(auto v : adj[u]) {
			dp[v] = max(dp[v], dp[u] + 1); 
			ans = max(ans, dp[v]);
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
```

##### [Go to top of page](#atcoder-educational-dp)


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

##### [Go to top of page](#atcoder-educational-dp)


# I - Coins

In this problem, Taro has `N` coins, each with their own probability of landing on heads. We want to find the probability that Taro flips more heads than tails after flipping all coins.

> Let *N* be a positive odd number

Since `N` is odd, we want to find the probability of flipping greater than or equal to `ceil(N/2)` coins because `ceil(N/2)` heads is the minimum number for there to be more heads than tails. This total probabilty is equal to the sum of probabilties of flipping exactly `ceil(N/2)`, `ceil(N/2) + 1`, ..., `N` heads. Let `dp[i][h]` equal the probability that Taro flips exactly `h` heads with the first `i` coins. Then, using [complementary counting](https://artofproblemsolving.com/wiki/index.php/Complementary_counting) the answer is equal to 1 minus the probability that there are more tails than heads. This is equal to 1 minus to the sum of probabilities of flipping 0, 1, ..., `floor(N/2)` heads. 

Notice that to get `h` heads after flipping `i` coins, we must've flipped `h` or `h-1` coins after flipping the first `i-1` coins. Thus, `dp[i][h] = dp[i-1][h] + (1-p[i]) + dp[i-1][h-1] * p[i]` where `p[i]` is the probability of flipping heads with coin `i`.

### DP Statement

```cpp
dp[i][h] = dp[i-1][h] + (1-p[i]) + dp[i-1][h-1] * p[i]
```
where `p[i]` is the probability of flipping heads with coin `i`. Preset `dp[0][0] = 1` since the probability of flipping 0 heads with the first 0 coins is always equal to 1 - there are 0 heads to begin with. We either arrive at the answer by summing all probabilities of rolling greater than or equal to `ceil(N/2)` heads with the `N` coins, or use complementary counting.

###### Code 
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	
	vector<double> p(N);
	for(auto&x : p) cin >> x;
	
	vector<vector<double>> dp(N + 1, vector<double>(N + 1, 0));
	dp[0][0] = 1;
	
	for(int i = 1; i <= N; ++i) {
		for(int h = 0; h <= N; ++h) {
			dp[i][h] = dp[i-1][h] * (1 - p[i-1]);
			if(h > 0) dp[i][h] += dp[i-1][h-1] * p[i-1]; 
		}
	}
	
	double ans = 0;
  
	for(int h = 0; h <= N/2 ; ++h)
		ans += dp[N][h];
	
	ans = 1 - ans;
	
	cout << setprecision(10) << fixed << ans << '\n';
	
	return 0;
}
```

### More Memory-Efficient Solution

The idea is to use a 1D dp array, where `dp[h]` equals the probability that Taro flips `h` heads so far, as we go through the list of coins from left to right. Notice that the probability for flipping `h` heads is dependent on the probability of flipping `h` and `h-1` heads from the previous move. Thus, we calculate the dp values for larger values of `h` first. By updating the probabilities for larger `h` first, we make sure all probabilities are calculated correctly.

###### code
```cpp
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
```

##### [Go to top of page](#atcoder-educational-dp)



# K - Stones

In this problem, Taro and Jiro have a pile of `K` stones and they each take turns removing some number of stones from the pile.

> Choose an element `x` in `A` (the set of stones to choose from), and remove exactly `x` stones from the pile. A player loses when he becomes unable to play.

We want to find which player will win if they both play optimally. Suppose we have `R` stones remaining, but we somehow know ahead of time that the player whose turn it is to remove from these `R` remaining stones will eventually lose. 

It follows that if a player is presented with the same set of stones, `A`, and must remove from a pile of `R + x` stones, where `x` is any element in `A`, then `R + x` stones is a winning pile. It isn't hard to convince yourself why this is true. 

If we remove `x` stones from a pile of `R + x` stones, and we know `R` remaining stones is a losing pile, then `R + x` stones must be a winning pile because we can always remove `x` stones to force a losing hand for the opponent.

We can come up with our dp statement using this observation.

### DP Statement

```cpp 
if(dp[R] == false) dp[R + x] = true
```

for all elements `x` in `A`, the set of stones . Preset all dp values equal to zero. If `dp[K]` is true, then the first player will win. Else, the second player will win.

##### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N, K;
	cin >> N >> K;

	vector<int> stones(N);

	for(int&x : stones)
		cin >> x;

	vector<bool> dp(K + 1, false);

	for(int R = 0; R < K; ++R) {
		if(!dp[R]) {
			for(auto x : stones) {
				if(R + x <= K) {
					dp[R + x] = true;
         			}
     			 }
		}
	}

	cout << (dp[K] ? "First" : "Second") << '\n';

	return 0;
}
```


##### [Go to top of page](#atcoder-educational-dp)
