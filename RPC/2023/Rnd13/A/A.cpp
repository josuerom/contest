/**
 *   █▀█  █▀▀▄ ─▀─ ▀▀█▀▀ █▀▀ ▄▀ ▀▄
 *   ─▄▀  █▀▀▄ ▀█▀ ──█── ▀▀█ █─ ─█
 *   █▄▄  ▀▀▀─ ▀▀▀ ──▀── ▀▀▀ ▀▄ ▄▀
**/
#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define br  '\n'

string x, y, z;
vector<string> str(6);

class RPCProblemSolver {
public:
   void solve() {
      cin >> x >> y >> z;
      str[0] = x + y + z;
      str[1] = x + z + y;
      str[2] = y + x + z;
      str[3] = y + z + x;
      str[4] = z + x + y;
      str[5] = z + y + x;
      cout << *max_element(str.begin(), str.end()) << br;
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
