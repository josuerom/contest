/**
 *   █▀█  █▀▀▄ ─▀─ ▀▀█▀▀ █▀▀ ▄▀ ▀▄
 *   ─▄▀  █▀▀▄ ▀█▀ ──█── ▀▀█ █─ ─█
 *   █▄▄  ▀▀▀─ ▀▀▀ ──▀── ▀▀▀ ▀▄ ▄▀
**/
#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define br  '\n'

class RPCProblem {
public:
   void solveOne() {
   }

   void tcReading() {
      int tt;
      cin >> tt;
#ifdef LOCAL
      int nc = 1;
      while (tt--) {
         cout << "Case #" << nc++ << ":\n";
         solveOne();
      }
#else
      while (tt--) solveOne();
#endif
   }
};

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   RPCProblem me;
   me.();
   return 0;
}