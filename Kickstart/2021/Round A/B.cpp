#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define f  first
#define s  second

using ll = long long;
using vi = vector<int>;

const int mxN = 1005;
int g[mxN][mxN];
int U[mxN][mxN], L[mxN][mxN], R[mxN][mxN], D[mxN][mxN];
int N, M;

void solve() {
	
	cin >> N >> M;
	for(int j = 0; j < N; ++j) {
		for(int i = 0; i < M; ++i) {
			cin >> g[j][i];
		}
	}

	for(int j = 0; j < N; ++j) {
		for(int i = 0; i < M; ++i) {
			if(g[j][i] == 0) continue;
			U[j][i] = L[j][i] = 1;
			if(j - 1 >= 0) U[j][i] += U[j-1][i];
			if(i - 1 >= 0) L[j][i] += L[j][i-1];
		}
	}

	for(int j = N - 1; j >= 0; --j) {
		for(int i = M - 1; i >= 0; --i) {
			if(g[j][i] == 0) continue;
			R[j][i] = D[j][i] = 1;
			if(j + 1 < N) D[j][i] += D[j+1][i];
			if(i + 1 < M) R[j][i] += R[j][i+1];
		}
	}

	ll ans = 0;

	for(int j = 0; j < N; ++j) {
		for(int i = 0; i < M; ++i) {
			if(g[j][i] == 0) continue;
			if(R[j][i] >= 2) {
				if(U[j][i] >= 4) ans += min(U[j][i]/2, R[j][i]) - 1;
				if(D[j][i] >= 4) ans += min(D[j][i]/2, R[j][i]) - 1;
			}
			if(L[j][i] >= 2) {
				if(U[j][i] >= 4) ans += min(U[j][i]/2, L[j][i]) - 1;
				if(D[j][i] >= 4) ans += min(D[j][i]/2, L[j][i]) - 1;
			}
			if(U[j][i] >= 2) {
				if(R[j][i] >= 4) ans += min(R[j][i]/2, U[j][i]) - 1;
				if(L[j][i] >= 4) ans += min(L[j][i]/2, U[j][i]) - 1;
			}
			if(D[j][i] >= 2) {
				if(R[j][i] >= 4) ans += min(R[j][i]/2, D[j][i]) - 1;
				if(L[j][i] >= 4) ans += min(L[j][i]/2, D[j][i]) - 1;
			}
		}
	}

	cout << ans << '\n';
	
	// clear memory
	for(int j = 0; j < N; ++j) {
		for(int i = 0; i < M; ++i) {
			U[j][i] = D[j][i] = R[j][i] = L[j][i] = 0;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for(int t = 1; t <= tc; ++t) {
		cout << "Case #" << t << ": ";
		solve();
	}

	return 0;
}
