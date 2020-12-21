/*
Resources: 	CSA: https://csacademy.com/lesson/disjoint_data_sets/
       	 	CSES: Minimum Spanning Trees - Problem: Road Preparation - https://cses.fi/paste/74a651438454d31515707e/
*/

const int mxN = 1e5;
int root[mxN], depth[mxN];

void init(int n) {
	for(int i = 0; i < n; ++i)
		root[i] = i;
}

int find(int a) {
	if(root[a] == a) return a;
	return root[a] = find(root[a]);
  	// path compression - used to flatten the structure of the tree
  	// idea is that each node in a tree may as well be attached to 
  	// the root, as that is the representative of the component
}

bool same(int a, int b) {return root[a] == root[b];}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if(depth[a] < depth[b]) swap(a, b);
	root[b] = a;
	depth[a] = max(depth[a], depth[b] + 1);
}

