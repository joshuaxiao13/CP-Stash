#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define f  first
#define s  second

using ll = long long;
using vi = vector<int>;

void solve() {
	int N, ans = 0;
	cin >> N;
	vector<vi> A(N, vi(N)), B(N, vi(N));

	for(int j = 0; j < N; ++j) {
		for(int i = 0; i < N; ++i) {
			cin >> A[j][i];
		}
	}

	for(int j = 0; j < N; ++j) {
		for(int i = 0; i < N; ++i) {
			cin >> B[j][i];
			ans += B[j][i];
		}
	}

	int x;
	for(int i = 0; i < 2*N; ++i) cin >> x;

	vector<vi> cost(N, vi(2, 0));
	vector<vector<bool>> used(N, vector<bool>(2, false));

	for(int k = 0; k < 2*N; ++k) {
		int a = -1, b = -1;
		for(int i = 0; i < N; ++i) {
			if(!used[i][0]) {
				if((a == -1 && b == -1) || cost[i][0] > cost[a][b]) a = i, b = 0;
			}
			if(!used[i][1]) {
				if((a == -1 && b == -1) || cost[i][1] > cost[a][b]) a = i, b = 1;
			}
		}

		used[a][b] = true;
		ans -= cost[a][b];
		for(int i = 0; i < N; ++i) {
			if(b == 0) cost[i][1] = max(cost[i][1], B[i][a]);
			else cost[i][0] = max(cost[i][0], B[a][i]);
		}
	}
	
	cout << ans << '\n';
	// clear memory
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
