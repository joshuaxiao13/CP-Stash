#include <bits/stdc++.h>
using namespace std;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	for(int tt = 1; tt <= t; ++tt) {
		int N;
		string s;
		cin >> N >> s;
		vector<int> psum(N + 1, 0);
		for(int i = 0; i < N; ++i) {
			psum[i+1] = s[i] - '0';
			psum[i+1] += psum[i];
		}

		int ans = 0;

		// fix first section painted, then calculate guranteed range
		// essentially calculates sum of every subarray of size ceil(N/2)

		for(int i = 1; i <= N; ++i) {
			int L, R;
			R = (i + 1 + N + 1)/2 - 1;
			L = (1 + i - 1)/2 + 1;
			ans = max(ans, psum[R] - psum[L-1]);
		}

		cout << "Case #" << tt << ": " << ans << '\n';
	}

    return 0;
}
