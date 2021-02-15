#include <bits/stdc++.h>
using namespace std;

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N, K;
	cin >> N >> K;

	vector<int> stones(N);

	for(int&x : stones)
		cin >> x;

	vector<bool> dp(K + 1, false);

	for(int i = 0; i < K; ++i) {
		if(!dp[i]) {
			for(auto x : stones) {
				if(i + x <= K) {
					dp[i+x] = true;
				}
			}
		}
	}

	cout << (dp[K] ? "First" : "Second") << '\n';

	return 0;
}
