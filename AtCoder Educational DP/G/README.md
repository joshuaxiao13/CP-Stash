# G - Longest Path

We're given a directed acyclic graph (DAG) that does not contain any cycles. We want to find the longest directed path in the DAG, so we can try finding the longest path ending at every vertex ```v```, and take the longest path out of all paths. Let ```dp[v]``` equal the longest path ending at vertex ```v```. We need to somehow find the dp values for the vertices that are directed towards node ```v```, since any path to vertex ```v``` can start from a vertex that is directed towards ```v```. This can be acheived with a [topological sort](https://csacademy.com/lesson/topological_sorting/) of the vertices.

After we perform the toplogical sort, we can calculate the dp values using the fact that the longest path to vertex ```v``` can be used to calculate the longest path to the directed vertices from ```v```. Thus, for every vertex ```v``` directed from ```u```, ```dp[v] = max(dp[u] + 1)```. We return the maximum dp value we encounter.

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
