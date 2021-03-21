#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define f  first
#define s  second

using ll = long long;
using vi = vector<int>;

void solve() {
	int N, K;
	string s;
	cin >> N >> K >> s;
	int cnt = 0;
	for(int i = 0; i < N - 1 - i; ++i) {
		if(s[i] != s[N-1-i]) ++cnt;
	}

	cout << abs(cnt - K) << '\n';

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
