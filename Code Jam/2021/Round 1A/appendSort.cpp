#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define f  first
#define s  second

using ll = long long;
using vi = vector<int>;

bool good(string a, string b) {
	if(a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

void solve() {
	ll ans = 0;
	int N; cin >> N;
	vector<string> v(N);
	for(int i = 0; i < N; ++i) cin >> v[i];
	for(int i = 1; i < N; ++i) {
		string &a = v[i-1];
		string &b = v[i];
		if(good(a, b)) continue;
		if(a.size() == b.size()) b += "0", ++ans;
		else {

			bool same = true;
			for(int j = 0; j < b.size(); ++j) {
				if(a[j] != b[j]) {
					same = false;
					break;
				}
			}
			if(same) {
				int idx = -1;
				for(int j = a.size() - 1; j >= b.size(); --j) {
					if(a[j] < '9') {
						idx = j;
						break;
					}
				}
				if(idx == -1) {
					while(!good(a, b)) b += "0", ++ans;
				}
				else {
					while(b.size() < idx) b += a[b.size()], ++ans;
					b += char(a[idx] + 1), ++ans;
					while(!good(a, b)) b += "0", ++ans;
				}
			}
			else {
				while(!good(a, b)) b += "0", ++ans;
			}
		}
		assert(good(a,b));
	}
	cout << ans << '\n';
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
