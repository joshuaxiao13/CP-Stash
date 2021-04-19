#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define f  first
#define s  second

using ll = long long;
using vi = vector<int>;

void solve() {
	int N; cin >> N;
	vi v(N); for(auto &x : v) cin >> x;
	vi l(N), r(N);
	l[0] = 1;
	l[1] = 2;
	int ans = 2;
	for(int i = 2; i < N; ++i) {
		if(v[i] - v[i-1] == v[i-1] - v[i-2]) l[i] = l[i-1] + 1;
		else l[i] = 2;
		ans = max(ans, l[i]);
	}
	r[N-1] = 1;
	r[N-2] = 2;
	for(int i = N - 3; i >= 0; --i) {
		if(v[i+1] - v[i] == v[i+2] - v[i+1]) r[i] = r[i+1] + 1;
		else r[i] = 2;
	}

	for(int i = 0; i < N; ++i) {
		if(i - 2 >= 0) {
			int temp = l[i-1] + 1;
			int d = v[i-1] - v[i-2];
			int a = v[i-1] + d;
			if(i + 1 < N && v[i+1] - a == d) {
				if(i + 2 < N && v[i+2] - v[i+1] == d) temp += r[i+1];
				else ++temp;
			}
			ans = max(ans, temp);
		}
		if(i + 2 < N) {
			int temp = r[i+1] + 1;
			int d = v[i+2] - v[i+1];
			int a = v[i+1] - d;
			if(i - 1 >= 0 && a - v[i-1] == d) {
				if(i - 2 >= 0 && v[i-1] - v[i-2] == d) temp += l[i-1];
				else ++temp;
			}
			ans = max(ans, temp);
		}
	}

	cout << ans;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int TC; cin >> TC;
	for(int t = 1; t <= TC; ++t) {
		cout << "Case #" << t << ": ";
		solve();
		cout << '\n';
	}

	return 0;
}
