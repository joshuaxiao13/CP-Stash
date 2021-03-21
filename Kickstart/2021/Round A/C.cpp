#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define f  first
#define s  second

using ll = long long;
using vi = vector<int>;

int N, M;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool valid(int j, int i) {return j >= 0 && i >= 0 && j < N && i < M;}

void solve() {
	cin >> N >> M;

	priority_queue<tuple<ll,int,int>> pq;
	vector<vector<ll>> g(N, vector<ll>(M));
	
	for(int j = 0; j < N; ++j) {
		for(int i = 0; i < M; ++i) {
			cin >> g[j][i];
			pq.push(make_tuple(g[j][i], j, i));
		}
	}

	ll ans = 0;

	while(!pq.empty()) {
		ll a;
		int j, i;
		tie(a, j, i) = pq.top(); pq.pop();
		for(int k = 0; k < 4; ++k) {
			int J = j + dy[k];
			int I = i + dx[k];
			if(valid(J, I) && g[J][I] < a - 1) {
				ans += a - g[J][I] - 1;
				g[J][I] = a - 1;
				pq.push(make_tuple(a - 1, J, I));
			}
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
