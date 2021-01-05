# G - Longest Path

### DP Statement

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
