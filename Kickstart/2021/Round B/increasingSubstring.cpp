#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define f  first
#define s  second

using ll = long long;
using vi = vector<int>;

void solve() {
	int N;
	string s;
	cin >> N >> s;
	int ans = 1;
	cout << 1 << " ";
	for(int i = 1; i < N; ++i) {
		if(s[i] > s[i-1]) ++ans;
		else ans = 1;
		cout << ans << " ";
	}
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
