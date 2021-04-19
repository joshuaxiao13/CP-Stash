#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define f  first
#define s  second

using ll = long long;
using vi = vector<int>;

void solve() {
	ll sum = 0;
	int M; cin >> M;
	vector<pair<ll,ll>> p(M);
	for(auto &[prime, cnt] : p) {
		cin >> prime >> cnt;
		sum += prime * cnt;
	}
	for(ll goal = sum; goal >= max(1LL, sum - 60 * 499); --goal) {
		ll x = goal;
		ll cur = 0;
		for(auto [prime, cnt] : p) {
			while(x % prime == 0 && cnt > 0) {
				--cnt;
				x /= prime;
			}
			cur += 1LL * prime * cnt;
		}
		if(x == 1 && cur == goal) {
			cout << goal;
			return;
		}
	}
	cout << "0";
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
