/**
 *   █▀█  █▀▀▄ ─▀─ ▀▀█▀▀ █▀▀ ▄▀ ▀▄
 *   ─▄▀  █▀▀▄ ▀█▀ ──█── ▀▀█ █─ ─█
 *   █▄▄  ▀▀▀─ ▀▀▀ ──▀── ▀▀▀ ▀▄ ▄▀
**/
#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define br  '\n'

ll n, d;

class RPCProblemSolver {
public:
   void solve() {
      cin >> n >> d;
      ll ans = n + 1;
      while (ans % 10 != d) ans++;
      cout << ans << br;
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
