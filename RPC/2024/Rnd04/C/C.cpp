/**
 *   █▀█  █▀▀▄ ─▀─ ▀▀█▀▀ █▀▀ ▄▀ ▀▄
 *   ─▄▀  █▀▀▄ ▀█▀ ──█── ▀▀█ █─ ─█
 *   █▄▄  ▀▀▀─ ▀▀▀ ──▀── ▀▀▀ ▀▄ ▄▀
**/
#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define br  '\n'

class RPCProblemC {
public:
   static const int N = int(1e1) + 30;
   int a[N], n, ans, cnt;

   void solveOne() {
      cin >> n;
      ans = 1, cnt = 1;
      for (int i = 0; i < n; i++) {
         cin >> a[i];
         if (i > 0 && a[i - 1] < a[i]) {
            cnt++;
            ans = max(ans, cnt);
         } else cnt = 1;
         ans = max(ans, cnt);
      }
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
   RPCProblemC me;
   // me.tcReading();
   me.solveOne();
   system("pause");
   return 0;
}