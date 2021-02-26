#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mxN = 2e5;				// mxN = maximum number of elements in array (refer to constraints of problem)

int N, Q;					// Remember: Binary Indexed Trees are always 1-indexed
ll tree[mxN + 1];				// long long to avoid integer overflow

ll sum(int k) {					// returns sum of elements in the interval [1, k]
	ll ret = 0;
	while(k >= 1) {
		ret += tree[k];
		k -= k & -k; 
	}
	return ret;
}

void add(int k, ll delta) {			// increases the kth element of the array by delta
	while(k <= N) {
		tree[k] += delta;
		k += k & -k;
	}
}
