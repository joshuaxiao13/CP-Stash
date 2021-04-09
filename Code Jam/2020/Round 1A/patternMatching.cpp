#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define f  first
#define s  second

using ll = long long;
using vi = vector<int>;

void solve() {
	bool valid = true;
	string left = "", mid = "", right = "";
	int N; cin >> N;

	while(N--) {
		string s; cin >> s;
		int n = s.size();
		for(int i = 0; i < n; ++i) {
			if(s[i] == '*') continue;
			int j = i;
			while(j < n && s[j] != '*') ++j;
			string temp = string(s.begin() + i, s.begin() + j);
			if(i == 0) {
				for(int k = 0; k < min(left.size(), temp.size()); ++k) {
					if(left[k] != temp[k]) {
						valid = false;
						break;
					}
				}
				if(temp.size() > left.size()) left = temp;
			}
			else if(j == n) {
				reverse(temp.begin(), temp.end());
				for(int k = 0; k < min(right.size(), temp.size()); ++k) {
					if(right[k] != temp[k]) {
						valid = false;
						break;
					}
				}
				if(temp.size() > right.size()) right = temp;
			}
			else mid += temp;
			i = j;
		}
	}

	if(!valid) {
		cout << '*';
		return;
	}

	reverse(right.begin(), right.end());
	cout << left << mid << right;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int TC; cin >> TC;
	for(int t = 1; t <= TC; ++t) {
		cout << "Case #" << t << ": ";
		solve();
		cout << '\n';
	}

	return 0;
}

/*
* use long long when dealing with MOD 1e9 + 7
* clear memory after testcases
*/
