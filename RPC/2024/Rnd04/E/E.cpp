/**
 *   █▀█  █▀▀▄ ─▀─ ▀▀█▀▀ █▀▀ ▄▀ ▀▄
 *   ─▄▀  █▀▀▄ ▀█▀ ──█── ▀▀█ █─ ─█
 *   █▄▄  ▀▀▀─ ▀▀▀ ──▀── ▀▀▀ ▀▄ ▄▀
**/
#include <bits/stdc++.h>
using namespace std;

#define ull  unsigned long long int
#define br  '\n'

class RPCProblemE {
public:
   void solveOne() {
      ull n, k;
      cin >> n >> k;
      vector<ull> a(n);
      multimap<ull, int> ans;
      map<ull, vector<ull>> mpvl;
      for (ull i = 0; i < n; i++) {
         cin >> a[i];
         vector<ull> vll;
         for (ull m = 1; m <= k; m++) {
            vll.push_back(m * a[i]);
         }
         mpvl[a[i]] = vll;
      }
      ull sum;
      for (ull i = 0; i <= n - k; i++) {
         sum = 0ULL;
         for (ull j = 0, g = i; j < k && g < n; j++, g++) {
            sum += mpvl[a[g]][j];
         }
         ans.insert({sum, i + 1});
      }
      for (auto &e : ans) {
         cout << e.second << " " << e.first << br;
      }
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
   RPCProblemE me;
   // me.tcReading();
   me.solveOne();
   system("pause");
   return 0;
}