/**
 *  █▀█  █▀▀▄ ─▀─ ▀▀█▀▀ █▀▀ ▄▀ ▀▄
 *  ─▄▀  █▀▀▄ ▀█▀ ──█── ▀▀█ █─ ─█
 *  █▄▄  ▀▀▀─ ▀▀▀ ──▀── ▀▀▀ ▀▄ ▄▀
 *  created: 20/08/23 19:33:54
**/
#include <bits/stdc++.h>
using namespace std;

#ifdef _2BITS
#include "../debug.h"
#else
#define debug(...) 42
#endif

clock_t startTime;
double getCurrentTime() {
   return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

void solutionI() {
   int n, q;
   cin >> n >> q;
   unordered_map<string, int> s;
   for (int i = 1; i <= n; i++) {
      string a;
      cin >> a;
      s[a] = i;
   }
   for (int i = 0; i < q; i++) {
      string a, b;
      cin >> a >> b;
      cout << abs(s[a] - s[b]) - 1 << '\n';
   }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr); cout.tie(nullptr);
   int tt = 1;
   // cin >> tt;
   for (int nc = 1; nc <= tt; nc++) {
#ifdef _2BITS
      cout << "------ Case #" << nc << " ------\n";
      solutionI();
      cout << "time: " << setprecision(5) << getCurrentTime() << " ms\n";
#else
   solutionI();
#endif
   }
   return 0;
}