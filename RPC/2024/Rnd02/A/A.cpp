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
   static const int N = 20 + 1e5;
   int n, m, k;
   ll a[N];
   double sumT, sumP, ans;
   
   void Solution() {
      cin >> n >> m >> k;
      for (int i = 0; i < n; i++) {
         cin >> a[i];
         sumT += a[i];
      }
      sort(a, a + n, greater<ll>());
      for (int i = 0; i < m + k; i++)
         sumP += a[i];
      ans = (sumP / sumT) * 100;
      cout << fixed << setprecision(4) << ans << br;
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
   ios::sync_with_stdio(false);
   cin.tie(0);
   RPCProblemSolver sol;
   // sol.TC();
   sol.Solution();
   return 0;
}
