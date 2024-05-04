/**
 *   █▀█  █▀▀▄ ─▀─ ▀▀█▀▀ █▀▀ ▄▀ ▀▄
 *   ─▄▀  █▀▀▄ ▀█▀ ──█── ▀▀█ █─ ─█
 *   █▄▄  ▀▀▀─ ▀▀▀ ──▀── ▀▀▀ ▀▄ ▄▀
**/
#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define br  '\n'

class RPCProblemB {
public:
   int a, b, c, curr;

   void solveOne() {
      cin >> a >> b >> c;
      bool flag = 0;
      for (int j = 1; b * j < a; j++) {
         curr = 0;
         for (int k = 1; curr < a; k++) {
            curr = b * j + c * k;
            // cout << curr << br;
            if (curr == a) {
               flag = 1;
               break;
            }
         }
         if (flag) {
            cout << "1\n";
            return;
         }
      }
      for (int j = 1; c * j < a; j++) {
         curr = 0;
         for (int k = 2; curr < a; k++) {
            curr = b * k + c * j;
            // cout << curr << br;
            if (curr == a) {
               flag = 1;
               break;
            }
         }
         if (flag) {
            cout << "1\n";
            return;
         }
      }
      cout << "0\n";
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
   cin.tie(0); cout.tie(0);
   RPCProblemB me;
   // me.tcReading();
   me.solveOne();
   system("pause");
   return 0;
}