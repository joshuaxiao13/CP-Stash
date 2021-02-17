#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mxN = 2e5;				// mxN = number of elements in original array

int N, Q;					// Remember: Binary Indexed Trees are always 1-indexed
ll tree[mxN + 1];				// long long to avoid integer overflow

ll sum(int k) {
	ll ret = 0;
	while(k >= 1) {
		ret += tree[k];
		k -= k & -k; 
	}
	return ret;
}

void add(int k, ll delta) {
	while(k <= N) {
		tree[k] += delta;
		k += k & -k;
	}
}

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> Q;
	
	// processing the elements in array and constructing the Fenwick Tree
	
	for(int i = 1; i <= N; ++i) {
		int x;
		cin >> x;
		add(i, x);
	}
	
	while(Q--) {
		// process queries here
	}
	
	return 0;
}
