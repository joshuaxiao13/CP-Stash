# L - Deque

In this problem, Taro and Jiro take turns removing elements from the beginning or end of some sequence, `a`, until the sequence is empty. They sum up the values of the elements they choose to get their score.

> Let `X` and `Y` be Taro's and Jiro's total score at the end of the game, respectively. Taro tries to maximize `X − Y`, while Jiro tries to minimize `X − Y`.

Note that Jiro is trying to minimize `X - Y`, which is equivalent to maximizing `Y - X`. 

Suppose Taro and Jiro have already removed some elements from the beginning and end of the sequence and they are now left with some subarray of the original sequence. Let this subarray be the elements from the original sequence in the interval [`L`, `R`]. The player whose turn it is now has two choices, which are to remove from the beginning or remove from the end of this subarray. Formally, the current player can 

1. remove `a[L]` or 
2. remove `a[R]`

Let `dp[L][R]` equal the maximum value of the difference of scores (score of current player choosing minus score of opponent) where the current player is choosing from the remaining subarray [`L`, `R`] as defined above. Each player wants to maximize this dp value when it gets to their turn because this is how they can optimally increase their scores. It follows that

```cpp
dp[L][R] = max(a[L] - dp[L+1][R], a[R] - dp[L][R-1])
```

Let's try to understand what this expression really means.

#### Case 1: Current Player Removes From the Beginning of the Sequence

This is represented by:
```cpp
a[L] - dp[L+1][R]
```
If the current player removes from the beginning, the remaining sequence is the interval [`L+1`, `R`]. Note `dp[L+1][R]` is equal to the maximum difference of scores that the opponent can get working with the sequence remaining after `a[L]` is removed. Algebraically, `a[L] - dp[L+1][R]` is the maximum difference of scores for the current player if he decides to remove from the beginning.

#### Case 2: Current Player Removes From the End of the Sequence

This is represented by:
```cpp
a[R] - dp[L][R-1]
```
If the current player removes from the end, the remaining sequence is the interval [`L`, `R-1`]. Note `dp[L][R-1]` is equal to the maximum difference of scores that the opponent can get working with the sequence remaining after `a[R]` is removed. Algebraically, `a[R] - dp[L][R-1]` is the maximum difference of scores for the current player if he decides to remove from the end.

### DP Statement

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
