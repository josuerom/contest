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
   static const int N = 20 + 1e3;
   char s[N][N];
   int n, m;

   void Solution() {
      cin >> n >> m;
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++)
            cin >> s[i][j];
      }
      for (int i = 0; i < m; i++) {
         string ans = "";
         int mx = 0;
         map<char, int> mp;
         for (int j = 0; j < n; j++) {
            mp[s[j][i]] += 1;
         }
         for (auto &e : mp) {
            if (e.second > mx) {
               mx = e.second, ans = e.first;
            }
         }
         cout << ans;
      }
      cout << br;
   }

   void TC() {
      int tt = 1, nc = 1;
      cin >> tt;
      while (tt--) {
      #ifdef LOCAL
         cout << "Case #" << nc++ << ":\n";
         Solution();
      #else
         Solution();
      #endif
      }
   }
};

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   RPCProblemSolver sol;
   // sol.TC();
   sol.Solution();
   return 0;
}
