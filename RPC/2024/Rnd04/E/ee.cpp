/**
 *   author:  josuerom
 *   created: 04/05/24 21:42:25
**/
#include <bits/stdc++.h>
using namespace std;

#define ll  unsigned long long
#define br  '\n'

ll n, k, sum;
multimap<ll, int> ans;
map<ll, vector<ll>> mpvl;

void solve() {
   cin >> n >> k;
   vector<ll> a(n);
   for (int i = 0, h = 0; i < n; i++) {
      cin >> a[i];
      for (ll j = 1; j <= k; j++) {
         mpvl[a[i]].push_back(j * a[i]);
      }
      if (i >= k - 1) {
         sum = 0LL;
         for (int j = 0, g = h; j < k && g < n; j++, g++) {
            sum += mpvl[a[g]][j];
         }
         ans.insert({sum, ++h});
      }
   }
   for (auto &[f, s] : ans) {
      cout << s << " " << f << br;
   }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int tt = 1;
   // cin >> tt;
#ifdef LOCAL
   int nc = 1;
   while (tt--) {
      cout << "Case #" << nc++ << ":\n";
      solve();
   }
#else
   while (tt--) solve();
#endif
   return 0;
}