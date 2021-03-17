#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define f  first
#define s  second

using ll = long long;
using vi = vector<int>;

ll solve() {
  int N;
  ll D;
  cin >> N >> D;
  vector<ll> X(N); for(ll& x : X) cin >> x;
  for(int i = N - 1; i >= 0; --i) {
  	D = (D/X[i])*X[i];
  }
  assert(D > 0);
  return D;
}

int main() {
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for(int tc = 1; tc <= T; ++tc) {
        cout << "Case #" << tc << ": " << solve() << '\n';
    }
	
	return 0;
}
