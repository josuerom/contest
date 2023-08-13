/**
 *  █▀█  █▀▀▄ ─▀─ ▀▀█▀▀ █▀▀ ▄▀ ▀▄
 *  ─▄▀  █▀▀▄ ▀█▀ ──█── ▀▀█ █─ ─█
 *  █▄▄  ▀▀▀─ ▀▀▀ ──▀── ▀▀▀ ▀▄ ▄▀
 *  created: 12/08/23 15:35:22
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
   vector<pair<int, string>> s;
   for (int i = 1; i <= n; i++) {
      string a;
      cin >> a;
      s.push_back(make_pair(i, a));
   }
   vector<pair<string, string>> c;
   for (int i = 0; i < q; i++) {
      string a, b;
      cin >> a >> b;
      c.push_back(make_pair(a, b));
   }
   sort(s.begin(), s.end());
   for (int i = 0; i < q; i++) {
      auto it1 = find_if(s.begin(), s.end(), [f = c[i].first](const pair<int, string>& e) { return e.second == f; });
      auto it2 = find_if(s.begin(), s.end(), [s = c[i].second](const pair<int, string>& e) { return e.second == s; });
      int l = (it1 - s.begin());
      int j = (it2 - s.begin());
      cout << abs(l - j) - 1 << '\n';
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