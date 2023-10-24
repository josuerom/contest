/**
 *   █▀█  █▀▀▄ ─▀─ ▀▀█▀▀ █▀▀ ▄▀ ▀▄
 *   ─▄▀  █▀▀▄ ▀█▀ ──█── ▀▀█ █─ ─█
 *   █▄▄  ▀▀▀─ ▀▀▀ ──▀── ▀▀▀ ▀▄ ▄▀
**/
#include <bits/stdc++.h>

using namespace std;

void solve() {
   int k;
   cin >> k;
   vector<pair<int, int>> keeps(k);
   for (int i = 0; i < k; ++i) {
      cin >> keeps[i].first >> keeps[i].second;
   }
   double ans = numeric_limits<double>::max();
   for (int i = 0; i < k; i++) {
      double td = 0.0;
      for (int j = 0; j < k; j++) {
         if (i != j) {
            double d = hypot(keeps[i].first - keeps[j].first, keeps[i].second - keeps[j].second);
            td += d;
         }
      }
      double pd = td / (k - 1);
      ans = min(ans, pd);
   }
   /// EA 10^⁻6 --> solo 7 decimales
   cout << fixed << setprecision(10) << ans << '\n';
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   solve();
   return 0;
}