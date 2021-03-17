#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define f  first
#define s  second

using ll = long long;
using vi = vector<int>;

int solve() {
    int N;
    cin >> N;
    vi h(N); for(int& x : h) cin >> x;
    int ans = 0;
    for(int i = 1; i < N - 1; ++i)
        ans += (h[i] > h[i-1] && h[i] > h[i+1]);
    return ans;
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
