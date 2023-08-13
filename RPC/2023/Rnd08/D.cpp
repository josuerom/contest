/**
 *   author:  josuerom
 *   created: 17/07/23 19:13:28
**/
#include <bits/stdc++.h>
using namespace std;

#ifdef josuerom
#include "debug.h"
#else
#define debug(...) 42
#endif

#define rall(x) (x).rbegin(),(x).rend()
#define all(x)  (x).begin(),(x).end()
#define ull     unsigned long long int
#define ll      long long int
#define mp      make_pair
#define se      second
#define fi      first

void solve() {
   int s, n;
   cin >> s >> n;
   vector<pair<int, int>> f;
   for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      f.push_back(mp(x, y));
   }
   sort(all(f));
   int maxsx = 0, maxsy = 0;
   int st = 0;
   for (int i = 0, l = 0; i < n; i++, l++) {
      int x = f[i].fi;
      int m = x + s;
      int sx = 0;
      for (int j = i; j < n; j++) {
         if (x == f[j].fi)
            i = j + 1;
         if (f[j].fi <= m)
            sx++;
         else
            st = f[j].fi;
      }
      maxsx = max(maxsx, sx);
      int y = f[l].se;
      int b = y + s;
      int sy = 0;
      for (int j = l; j < n; j++) {
         if (f[j].fi == st)
            break;
         if (y == f[j].se)
            l = j + 1;
         if (f[j].se <= b)
            sy++;
      }
      maxsy = max(maxsy, sy);
   }
   cout << min(maxsx, maxsy) << '\n';
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr); cout.tie(nullptr);
   int tt = 1;
   // cin >> tt;
#ifdef josuerom
   for (int nc = 1; nc <= tt; nc++) {
      cout << "----- Case #" << nc << " -----\n";
      solve();
   }
#else
   while (tt--)
      solve();
#endif
   return 0;
}