#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> LL;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
 
string s[2];
int cnt[2][3];
vector<int> p[2];
 
bool solve() {
	memset(cnt, 0, sizeof cnt);
	for (int i = 0; i < 2; i++) {	
		p[i].clear();
				
		cin >> s[i];
		for (char c : s[i])
			cnt[i][c - 'A']++;
	}
	
	for (int i = 0; i < 3; i++)
		if (cnt[0][i] % 2 != cnt[1][i] % 2) {
			return false;
		}
	
	for (int i = 0; i < 2; i++) {		
		int type = -1, cnt = 1;		
		for (char c : s[i]) {
			if (c == 'B') continue;
			if (c - 'A' != type) {
				if (cnt % 2 == 1) 
					p[i].push_back(type);
				else if (p[i].back() != -1) {
					cnt = 0;
					p[i].pop_back();
				} else cnt = 1;
			} else cnt++;
			type = c - 'A';
		}
		if (cnt % 2 == 1) p[i].push_back(type);
	}
	return (p[0] == p[1]);
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--) {
		if (solve()) cout << "YES\n";
		else cout << "NO\n";		
	}
	return 0;
}