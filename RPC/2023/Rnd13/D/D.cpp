/**
 *   █▀█  █▀▀▄ ─▀─ ▀▀█▀▀ █▀▀ ▄▀ ▀▄
 *   ─▄▀  █▀▀▄ ▀█▀ ──█── ▀▀█ █─ ─█
 *   █▄▄  ▀▀▀─ ▀▀▀ ──▀── ▀▀▀ ▀▄ ▄▀
**/
#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define br  '\n'

vector<string> s;
vector<char> c;
vector<pair<string, string>> pw;
string str, w1, w2;
int n, q;
// int dp[];

class RPCProblemSolver {
public:
   void solve() {
      cin >> n >> q;
      for (int i = 0; i < n; i++) {
         cin >> str;
         s.push_back(str);
         c.push_back(str[0]);
      }
      sort(s.begin(), s.end());
      sort(c.begin(), c.end());
      for (int i = 0; i < q; i++) {
         cin >> w1 >> w2;
         pw.push_back({w1, w2});
      }
      for (int i = 0; i < q; i++) {
         int ans = 0, d = 0, h = 0;
         auto fr = lower_bound(c.begin(), c.end(), pw[i].first[0]);
         auto ls = upper_bound(c.begin(), c.end(), pw[i].second[0]);
         if (ls == c.end()) --ls;
         if (fr == c.end()) {
            auto fr = upper_bound(c.begin(), c.end(), pw[i].first[0]);
            d = distance(c.begin(), fr);
            h = distance(c.begin(), ls);
            for (int j = d; j <= h; j++) {
               ans += (lexicographical_compare(pw[i].first.begin(), pw[i].first.end(), s[j].begin(), s[j].end())
                     && lexicographical_compare(s[j].begin(), s[j].end(), pw[i].second.begin(), pw[i].second.end()))
                     || s[j] == pw[i].first
                     || s[j] == pw[i].second;
            }
         } else {
            d = distance(c.begin(), fr);
            h = distance(c.begin(), ls);
            for (int j = d; j <= h; j++) {
               ans += (lexicographical_compare(pw[i].first.begin(), pw[i].first.end(), s[j].begin(), s[j].end())
                     && lexicographical_compare(s[j].begin(), s[j].end(), pw[i].second.begin(), pw[i].second.end()))
                     || s[j] == pw[i].first
                     || s[j] == pw[i].second;
            }
         }
         cout << ans << br;
      }
   }

   void TC() {
      ios::sync_with_stdio(false);
      cin.tie(0);
      int tt = 1, nc = 0;
      // cin >> tt;
      while (tt--) {
      #ifdef LOCAL
         cout << "Case #" << ++nc << ":\n";
         solve();
      #else
         solve();
      #endif
      }
   }
};

int main() {
   RPCProblemSolver solver;
   solver.TC();
   return 0;
}
