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

	for(int R = 0; R < K; ++R) {
		if(!dp[R]) {
			for(auto x : stones) {
				if(R + x <= K) {
					dp[R + x] = true;
         			}
     			 }
		}
	}

	cout << (dp[K] ? "First" : "Second") << '\n';

	return 0;
}
