/**
 *   █▀█  █▀▀▄ ─▀─ ▀▀█▀▀ █▀▀ ▄▀ ▀▄
 *   ─▄▀  █▀▀▄ ▀█▀ ──█── ▀▀█ █─ ─█
 *   █▄▄  ▀▀▀─ ▀▀▀ ──▀── ▀▀▀ ▀▄ ▄▀
**/
#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define br  '\n'

class RPCProblemSolver {
public:
   vector<int> KMP(string s) {
      int n = s.size();
      vector<int> in(n, 0);
      for (int i = 1; i < n; i++) {
         int j = in[i - 1];
         while (j > 0 && s[i] != s[j])
            j = in[j - 1];
         if (s[i] == s[j]) j++;
         in[i] = j;
      }
      return in;
   }

   void solve() {
      string s;
      cin >> s;
      vector<int> a = KMP(s);
      for (auto &e : a)
         cout << e << " ";
      cout << br;
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