# F - LCS (Longest Common Subsequence)

This is another standard problem. In this problem, we need to find the longest subsequence that is shared by strings ```s``` and ```t```. First, we'll deal with the length of the LCS. Let ```dp[j][i]``` equal the length of the LCS between the prefix of ```s``` of length ```j``` and the prefix of ```t``` of length ```i```. If ```s[j]``` equals ```t[i]```, then ```dp[j][i] = dp[j-1][i-1] + 1```. Else, ```dp[j][i] = max(dp[j-1][i], dp[j][i-1])```. This is because if the characters at the back of each prefix is the same, we can include that character in our LCS, and find the LCS for the remainder of the prefix. Else, we want to find the LCS by removing one character from the back of either prefix, amd find the LCS of the remainder of the prefixes. The LCS of the two strings is thus ```dp[n][m]``` where ```n``` and ```m``` are the lengths of ```s``` and ```t``` respectively.

Now the challenge is to find the subsequence, not just the length. We can keep track, for each dp state, whether it is optimal to 

1. take the back character common to both prefixes
2. or throw away the back character from the prefix of ```s```
2. or throw away the back character from the prefix of ```t```. 

Let ```trace[j][i]``` represent what we do with the given prefixes as described earlier. ```trace[j][i] = 0``` if we want to include the back character in our LCS, ```trace[j][i] = 1``` if we throw away the back letter of the prefix of ```s```, and ```trace[j][i] = 2``` if we throw away the back letter of the prefix of ```t```.

### DP Statement

```
if(s[j] == t[i]) dp[j][i] = dp[j-1][i-1] + 1
else dp[j][i] = max(dp[j-1][i], dp[j][i-1])
```

We preset all dp values to ```0```. 

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
	vector<vector<int>> trace(n + 1, vector<int>(m + 1, -1));
	
	for(int j = 1; j <= n; ++j) {
		for(int i = 1; i <= m; ++i) {
			if(s[j-1] == t[i-1]) {
				dp[j][i] = dp[j-1][i-1] + 1;
				trace[j][i] = 0;
			}
			else if(dp[j-1][i] > dp[j][i-1]){
				dp[j][i] = dp[j-1][i];
				trace[j][i] = 1;
			}
			else {
				dp[j][i] = dp[j][i-1];
				trace[j][i] = 2;
			}
		}
	}
	
	string ans = "";
	
	while(dp[n][m]--) {
		while(trace[n][m] != 0) {
			if(trace[n][m] == 1) --n;
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
