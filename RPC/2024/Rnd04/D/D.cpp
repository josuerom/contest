/**
 *   █▀█  █▀▀▄ ─▀─ ▀▀█▀▀ █▀▀ ▄▀ ▀▄
 *   ─▄▀  █▀▀▄ ▀█▀ ──█── ▀▀█ █─ ─█
 *   █▄▄  ▀▀▀─ ▀▀▀ ──▀── ▀▀▀ ▀▄ ▄▀
**/
#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define br  '\n'

class RPCProblemD {
public:
   void solveOne() {
      string a, b;
      int ai = 0, bi = 0;
      cin >> a >> b;
      bool v1 = 0, v2 = 0;
      for (int i = 1; i < a.size(); i++) {
         if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') {
            ai = i;
            v1 = 1;
            break;
         }
      }
      for (int i = b.size() - 2; i >= 0; i--) {
         if (b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' || b[i] == 'u') {
            bi = i;
            v2 = 1;
            break;
         }
      }
      string ans = "";
      if (v1 && v2)
         ans = a.substr(0, ai) + b.substr(bi);
      else if (v2)
         ans = a + b.substr(bi);
      else if (v1)
         ans = a.substr(0, ai + 1) + b; 
      else
         ans = a + 'o' + b;
      cout << ans << br;
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
   RPCProblemD me;
   // me.tcReading();
   me.solveOne();
   system("pause");
   return 0;
}