// complexity (N K) ~ worst case: 1e7 operations

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1000000007;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for(int& x : a) cin >> x;

    vector<vector<ll>> dp(N + 1, vector<ll>(K + 1, 0));
    dp[0][K] = 1;

    for(int i = 1; i <= N; ++i) {
        for(int rem = 0; rem <= K; ++rem) {
            dp[i][rem] = dp[i-1][min(rem + a[i-1], K)] - (rem - 1 >= 0 ? dp[i-1][rem-1] : 0);
            dp[i][rem] %= MOD;
        }
        for(int rem = 1; rem <= K; ++rem) (dp[i][rem] += dp[i][rem-1]) %= MOD;
    }

    cout << (dp[N][0] + MOD) % MOD << '\n';

    return 0;
}

