#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define f  first
#define s  second

using ll = long long;
using vi = vector<int>;

int N, K;
int M[100005];

bool valid(int d) {
	int cnt = 0;
	for(int i = 1; i < N; ++i) {
		cnt += (M[i] - M[i-1] + d - 1)/d - 1;
		if(cnt > K) break;
	}
	return cnt <= K;
}

int solve() {
	int mx = 0;
	cin >> N >> K;
	for(int i = 0; i < N; ++i) {
		cin >> M[i];
		if(i > 0) mx = max(mx, M[i] - M[i-1]);
	}

	int ans = 0;
	for(int k = mx; k > 0; k /= 2)
		while(ans + k < mx && !valid(ans + k))
			ans += k;

	++ans;
	return ans;
}

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i)
		cout << "Case #" << i << ": " << solve() << '\n';
	return 0;
}	
