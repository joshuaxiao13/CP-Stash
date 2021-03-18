// Credits: KevinWan

#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define f  first
#define s  second

using ll = long long;
using vi = vector<int>;

const int MOD = 1e9;

stack<ll> factor;
ll w, h;

void solve() {
	w = h = 0;
	factor.push(1);
	string cmd;
	cin >> cmd;
	int N = cmd.size();
	for(int i = 0; i < N; ++i) {
		if(cmd[i] == '(') continue;
		else if(cmd[i] == ')') factor.pop();
		else if(cmd[i] == 'N') (h -= factor.top()) %= MOD;
		else if(cmd[i] == 'S') (h += factor.top()) %= MOD;
		else if(cmd[i] == 'E') (w += factor.top()) %= MOD;
		else if(cmd[i] == 'W') (w -= factor.top()) %= MOD;
		else factor.push((factor.top() * (cmd[i]-'0')) % MOD);
	}
	if(w < 0) w += MOD;
	if(h < 0) h += MOD;
	while(!factor.empty()) factor.pop();
}

int main() {
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for(int tc = 1; tc <= T; ++tc) {
    	solve();
        cout << "Case #" << tc << ": " << w + 1 << " " << h + 1 << '\n';
    }
	
	return 0;
}
