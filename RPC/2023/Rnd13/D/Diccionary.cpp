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
