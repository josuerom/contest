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
   static const int N = 30 + 1e1;
   int a[N], n;

   void Solution() {
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
   RPCProblemSolver cp;
   // cp.TC();
   cp.Solution();
   system("pause");
   return 0;
}