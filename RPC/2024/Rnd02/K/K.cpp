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
   static const int N = 2 + 1e6;
   char s[N], d[N];
   int n;
   list<int> pzeros;
   vector<pair<int, int>> ptwos;

   void Solution() {
      cin >> s;
      n = strlen(s);
      for (int i = n - 1; i >= 0; i--) {
         if (s[i] == '0') pzeros.push_front(i + 1);
         else if (s[i] == '2') ptwos.push_back({i + 1, pzeros.size()});
      }
      strcpy(d, s);
      sort(d, d + n);
      if (strcmp(s, d) == 0) {
         cout << "0\n";
         return;
      }
      int stop = pzeros.size();
      ll ans = 0;
      for (int i = 0, l = 1; i < stop; i++, l++) {
         int curr = pzeros. front();
         ans += (ll) curr - l;
         pzeros.pop_front();
      }
      for (int i = ptwos.size() - 1, r = n; i >= 0; i--, r--) {
         int curr = ptwos[i].first + ptwos[i].second;
         ans += (ll) r - curr;
      }
      cout << ans << br;
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
   RPCProblemSolver sol;
   // sol.TC();
   sol.Solution();
   return 0;
}
