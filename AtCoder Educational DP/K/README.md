# K - Stones

In this problem, Taro and Jiro have a pile of `K` stones and they each take turns removing some number of stones.

> Choose an element `x` in `A` (the set of stones to choose from), and remove exactly `x` stones from the pile. A player loses when he becomes unable to play.

We want to find which player will win if they both play optimally. Suppose we have `R` stones remaining, but we somehow know ahead of time that the player whose turn it is to remove from these `R` remaining stones will eventually lose. 

It follows that if a player is presented with the same set of stones, `A`, and must remove from a pile of `R + x` stones, where `x` is any element in `A`, then `R + x` stones is a winning pile. It isn't hard to convince yourself why this is true. 

If we remove `x` stones from a pile of `R + x` stones, and we know `R` remaining stones is a losing pile, then `R + x` stones must be a winning pile because we can always remove `x` stones to force a losing hand for the opponent.

Using this observation, we can now write our dp statement.

### DP Statement

```cpp 
if(dp[R] == false) dp[R + x] = true
```

for all elements `x` in `A`, the set of stones . Preset `dp[0] = false` since it is impossible to remove any stones from a pile of 0 stones. Thus, 0 stones is a losing pile.

If `dp[K]` is true, then the first player will win. Else, the second player will win.

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
					dp[R+x] = true;
         			}
     			 }
		}
	}

	cout << (dp[K] ? "First" : "Second") << '\n';

	return 0;
}

```
