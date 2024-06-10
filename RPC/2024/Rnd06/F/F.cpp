/**
 *   █▀█  █▀▀▄ ─▀─ ▀▀█▀▀ █▀▀ ▄▀ ▀▄
 *   ─▄▀  █▀▀▄ ▀█▀ ──█── ▀▀█ █─ ─█
 *   █▄▄  ▀▀▀─ ▀▀▀ ──▀── ▀▀▀ ▀▄ ▄▀
**/
#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define br  '\n'

class RPCProblemF {
public:
   void solveOne() {
      int n, p;
      cin >> n >> p;
      vector<int> a(n);
      bool flag = 0;
      for (int i = 0; i < n; i++) {
         cin >> a[i];
         if (a[i] == p) flag = 1;
      }
      if (flag) {
         cout << p << br;
         return;
      }
      sort(a.begin(), a.end());
      if (a[0] > p) {
         cout << "0\n";
         return;
      }
      if (a[n - 1] < p) {
         cout << a[n - 1] << br;
         return;
      }
      int ans = 0;
      for (int i = 1; i < n - 1; i++) {
         if (a[i] > p) {
            ans = i - 1;
            break;
         }
      }
      cout << a[ans] << br;
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
	RPCProblemF me;
   me.solveOne();
   return 0;
}