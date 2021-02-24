#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll P = 9973, M = 1e9 + 9;       // can change these constants

ll p[1000001], hsh[1000001];          // p[i] = P^i, hsh[i] = hash value of the prefix s[0...i]
string s, t;
int n, m;                             //n = size of s, m = size of t

void poly_hash() {
	p[0] = 1;
	hsh[0] = s[0];
	for(int i = 1; i < n; ++i) {
		p[i] = (p[i-1] * P) % M;
		hsh[i] = ((hsh[i-1] * P) % M + s[i]) % M;
	}
}

ll get_hash(int a, int b) {
	if(a == 0) return hsh[b];                                     // to avoid a - 1 < 0 in the line below
	return (hsh[b] - (hsh[a - 1] * p[b - a + 1]) % M + M) % M;    // add M because hsh[b] - (hsh[a - 1] * p[b - a + 1]) might be negative, we want hash values to be non-negative
}

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> s >> t;
	n = s.size();
	m = t.size();
	
	poly_hash();
	
	return 0;
}
