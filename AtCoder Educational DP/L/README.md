# L - Deque

In this problem, Taro and Jiro take turns removing elements from the beginning or end of some sequence, `a`, of size `N` until the sequence is empty. They sum up the values of the elements they choose to get their final scores.

> Let `X` and `Y` be Taro's and Jiro's total score at the end of the game, respectively. Taro tries to maximize `X − Y`, while Jiro tries to minimize `X − Y`.

Note that Jiro is trying to minimize `X - Y`, which is equivalent to maximizing `Y - X`. 

Suppose Taro and Jiro have already removed some elements from the beginning and end of the sequence and they are now left with some subarray of the original sequence. Let this subarray be the elements from the original sequence in the interval [`L`, `R`]. The player whose turn it is now has two choices, which are to remove from the beginning or remove from the end of the subarray. Formally, the current player can 

1. remove `a[L]` or 
2. remove `a[R]`

Let `dp[L][R]` equal the maximum value of the difference of scores (score of current player choosing minus score of opponent) if the players were playing the game with the subarray [`L`, `R`] as defined above, not the necessarily the original sequence. It follows that

```cpp
dp[L][R] = max(a[L] - dp[L+1][R], a[R] - dp[L][R-1])
```

Let's try to understand what this expression really means.
\
#### Case 1: Current Player Removes From the Beginning of the Sequence

This is represented by:
```cpp
a[L] - dp[L+1][R]
```
If the current player removes from the beginning, the remaining sequence is the interval [`L+1`, `R`]. Note `dp[L+1][R]` is equal to the maximum difference of scores that the opponent can get working with the sequence remaining after `a[L]` is removed. Algebraically, `a[L] - dp[L+1][R]` is the maximum difference of scores for the current player if he decides to remove from the beginning. Use some algebra to convince yourself why.
\
#### Case 2: Current Player Removes From the End of the Sequence

This is represented by:
```cpp
a[R] - dp[L][R-1]
```
If the current player removes from the end, the remaining sequence is the interval [`L`, `R-1`]. Note `dp[L][R-1]` is equal to the maximum difference of scores that the opponent can get working with the sequence remaining after `a[R]` is removed. Algebraically, `a[R] - dp[L][R-1]` is the maximum difference of scores for the current player if he decides to remove from the end. Use some algebra to convince yourself why.
\
\
\
`dp[L][R]` is the maximum value from both cases because each player is playing optimally and wishes to maximize the difference between their final score and their opponents final score. We should also consider that dp values where `L` is strictly greater than `R` have no significance, and thus should be equal to zero.

### DP Statement

```cpp
dp[L][R] = max(a[L] - dp[L+1][R], a[R] - dp[L][R-1])
```

for all 0 <= `L` <= `R` < N. If there is one element remaining in the sequence, `L` will equal `R`, and the dp value is simply the value of `a[L]` or `a[R]` (they will be equal). This is because after taking the final element, the game ends, and the players cannot increase their scores anymore.

Return `dp[0][N-1]`, the maximum difference of the final scores of the first and second player if they both play optimally.

##### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	vector<ll> a(N);
	
	for(ll&x : a)
		cin >> x;
		
	vector<vector<ll>> dp(N, vector<ll>(N, 0));
	
	for(int L = N - 1; L >= 0; --L) {
		dp[L][L] = a[L];
		for(int R = L + 1; R < N; ++R) {
			if(L + 1 < N) dp[L][R] = a[L] - dp[L+1][R];
			if(R - 1 >= 0) dp[L][R] = max(dp[L][R], a[R] - dp[L][R-1]);
		}
	}
	
	cout << dp[0][N-1];
	
	return 0;
}
```
