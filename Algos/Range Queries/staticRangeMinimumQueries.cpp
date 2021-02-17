#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;		// mxN = maximum number of elements in array
const int K = 17;		// floor(log(2e5)/log(2)), in general K = floor(log(mxN)/log(2))

int a[mxN];
int st[mxN][K + 1];		// K + 1 because the highest power of 2 less than or equal to mxN is 2^K
int LOG2[mxN + 1];		// mxN + 1 because the largest interval size of a query will be mxN

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N, Q;
	cin >> N >> Q;
	
	// Very helpful link: https://cp-algorithms.com/data_structures/sparse-table.html
	
	LOG2[1] = 0;
	
	for(int i = 2; i <= mxN; ++i) {
		LOG2[i] = LOG2[i/2] + 1;
	}
	
	for(int i = 0; i < N; ++i) {
		cin >> a[i];
		st[i][0] = a[i];
	}
	
	for(int j = 1; j <= K; ++j) {
		for(int i = 0; i + (1<<j) - 1 < N; ++i) {
			st[i][j] = min(st[i][j-1], st[i + (1<<(j-1))][j-1]);
		}
	}
	
	while(Q--) {
		int L, R;
		cin >> L >> R, --L, --R;
		int j = LOG2[R - L + 1];
		cout << min(st[L][j], st[R - (1<<j) + 1][j]) << '\n';
	}
	
	return 0;
}
