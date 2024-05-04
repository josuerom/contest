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
   static const int N = int(1e5) + 30;
   int a[N], n;

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
   // me.tcReading();
   // me.solveOne();
   system("pause");
   return 0;
}
