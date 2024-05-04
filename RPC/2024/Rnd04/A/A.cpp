/**
 *   █▀█  █▀▀▄ ─▀─ ▀▀█▀▀ █▀▀ ▄▀ ▀▄
 *   ─▄▀  █▀▀▄ ▀█▀ ──█── ▀▀█ █─ ─█
 *   █▄▄  ▀▀▀─ ▀▀▀ ──▀── ▀▀▀ ▀▄ ▄▀
**/
#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define br  '\n'

class RPCProblemA {
public:
   int f, s;

   void solveOne() {
      cin >> f >> s;
      cout << (f >= s - f ? "E" : "H") << br;
   }

   void tcReading() {
      ios::sync_with_stdio(false);
      cin.tie(0); cout.tie(0);
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
   RPCProblemA me;
   // me.tcReading();
   me.solveOne();
   system("pause");
   return 0;
}