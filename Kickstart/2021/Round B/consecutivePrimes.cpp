#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define f  first
#define s  second

using ll = long long;
using vi = vector<int>;

bool prime(ll n) {
	if(n % 2 == 0) return false;
	for(ll f = 3; f * f <= n; f += 2) {
		if(n % f == 0) return false;
	}
	return true;
}

void solve() {
	ll Z; cin >> Z;
	ll sq = sqrt(Z);
	ll prev = 1, ans = 6;
	for(ll i = sq + 500; i >= 2 ; --i) {
		if(prime(i)) {
			if(prev != 1 && prev * i <= Z) {
				ans = prev * i;
				break;
			}
			prev = i;
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
