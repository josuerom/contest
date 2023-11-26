/**
 *   █▀█  █▀▀▄ ─▀─ ▀▀█▀▀ █▀▀ ▄▀ ▀▄
 *   ─▄▀  █▀▀▄ ▀█▀ ──█── ▀▀█ █─ ─█
 *   █▄▄  ▀▀▀─ ▀▀▀ ──▀── ▀▀▀ ▀▄ ▄▀
**/
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "../debug.h"
#else
#define debug(...) 42
#endif

#define ll long long
#define br '\n'

const int N = 1e1 + 50;
int a[N], n;

class RPCProblemSolver {
public:
   void solve() {
   }

   void TC() {
      int tt = 1, nc = 0;
      cin >> tt;
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
   ios::sync_with_stdio(false);
   cin.tie(0);
   RPCProblemSolver solver;
   solver.TC();
   return 0;
}