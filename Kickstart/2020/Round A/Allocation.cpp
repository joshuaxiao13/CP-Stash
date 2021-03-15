#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define f  first
#define s  second

using ll = long long;
using vi = vector<int>;

int solve() {
	int N, B, ans = 0;
	cin >> N >> B;
	vi A(N); for(int& x : A) cin >> x;
	sort(A.begin(), A.end());
	for(int i = 0; i < N; ++i) {
		if(B - A[i] >= 0) ++ans, B -= A[i];
		else break; 
	}
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
