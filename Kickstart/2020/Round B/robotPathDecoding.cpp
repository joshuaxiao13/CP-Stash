#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define f  first
#define s  second

using ll = long long;
using vi = vector<int>;

const int MOD = 1e9;
int w, h;

bool isInteger(char x) {return x >= '2' && x <= '9';}

stack<pair<ll,ll>> stk[1005];
stack<int> nums;

void solve() {
	w = h = 0;
	string cmd;
	cin >> cmd;
	int N = cmd.size();
	int depth = 0;
	for(int i = 0; i < N; ++i) {
		if(cmd[i] == '(') ++depth;
		else if(cmd[i] == ')') {
			ll dx = 0, dy = 0;
			while(!stk[depth].empty()) {
				(dx += stk[depth].top().f) %= MOD;
				(dy += stk[depth].top().s) %= MOD;
				stk[depth].pop();
			}
			(dx *= nums.top()) %= MOD;
			(dy *= nums.top()) %= MOD;
			nums.pop();
			--depth;
			stk[depth].push({dx, dy});
		}
		else if(isInteger(cmd[i])) nums.push(cmd[i]-'0');
		else {
			ll dx = 0, dy = 0;
			if(cmd[i] == 'N') --dy;
			else if(cmd[i] == 'S') ++dy;
			else if(cmd[i] == 'E') ++dx;
			else if(cmd[i] == 'W') --dx;
			stk[depth].push({dx, dy});
		}
	}

	// fails if I use int instead of long long, so use long long
	assert(depth == 0);
	assert(nums.empty());
	for(int i = 1; i <= 1000; ++i) assert(stk[i].empty());

	ll dx = 0, dy = 0;
	while(!stk[0].empty()) {
		(dx += stk[0].top().f) %= MOD;
		(dy += stk[0].top().s) %= MOD;
		stk[0].pop();
	}

	if(dx < 0) dx += MOD;
	if(dy < 0) dy += MOD;
	w = dx;
	h = dy;
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
