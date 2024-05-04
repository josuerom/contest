/**
 *   █▀█  █▀▀▄ ─▀─ ▀▀█▀▀ █▀▀ ▄▀ ▀▄
 *   ─▄▀  █▀▀▄ ▀█▀ ──█── ▀▀█ █─ ─█
 *   █▄▄  ▀▀▀─ ▀▀▀ ──▀── ▀▀▀ ▀▄ ▄▀
**/
#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define br  '\n'

class RPCProblemE {
public:
   static const int N = int(2e5) + 10;
   ll a[N], n, k;

   void solveOne() {
      cin >> n >> k;
      multimap<ll, int> ans;
      map<ll, vector<ll>> mpll;
      ll curr = 0LL;
      for (int i = 0, h = 0; i < n; i++) {
         cin >> a[i];
         auto it = mpll.find(a[i]);
         if (it == mpll.end()) {
            vector<ll> vll;
            for (int m = 1; m <= k; m++) {
               vll.push_back(m * a[i]);
            }
            mpll[a[i]] = vll;
         }
         if (i >= k - 1) {
            ll sum = 0LL;
            // for (int j = h, l = 1; j <= i; j++, l++) sum += l * a[j];
            for (int l = 0, g = h; l < k; l++, g++) {
               sum += mpll[a[g]][l];
            }
            ans.insert({sum, h + 1});
            h++;
         }
      }
      for (auto &[f, s] : ans)
         cout << s << " " << f << br;
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
   RPCProblemE me;
   // me.tcReading();
   me.solveOne();
   system("pause");
   return 0;
}