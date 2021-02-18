/*
Resources: 	CSA: https://csacademy.com/lesson/disjoint_data_sets/
       	 	CSES: Minimum Spanning Trees & DSU - Problem: Road Preparation - https://cses.fi/paste/74a651438454d31515707e/
*/

const int mxN = 1e5;
int root[mxN], depth[mxN];

void init(int n) {
	for(int i = 0; i < n; ++i)
		root[i] = i;
}

int find(int u) {
	if(root[u] == u) return u;
	return root[u] = find(root[u]);
  	// path compression - used to flatten the structure of the tree idea is that each node in 
	// a tree may as well be attached to the root, as that is the representative of the component
}

bool same(int u, int v) {
	return find(u) == find(v);
}

void unite(int u, int v) {
	u = find(u);
	v = find(v);
	if(depth[u] < depth[v]) swap(u, v);
	root[v] = u;
	depth[u] = max(depth[u], depth[v] + 1);
}
