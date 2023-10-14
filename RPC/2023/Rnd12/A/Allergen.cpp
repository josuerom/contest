/**
 *   █▀█  █▀▀▄ ─▀─ ▀▀█▀▀ █▀▀ ▄▀ ▀▄
 *   ─▄▀  █▀▀▄ ▀█▀ ──█── ▀▀█ █─ ─█
 *   █▄▄  ▀▀▀─ ▀▀▀ ──▀── ▀▀▀ ▀▄ ▄▀
**/
#include <bits/stdc++.h>

using namespace std;

#define ll  long long

ll n, d, ans;

void solve() {
   cin >> n >> d;
   ans = static_cast<ll>(ceil(log2(n + 1)));
   cout << min(ans, d + 1) << '\n';
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int tt;
   cin >> tt;
   while (tt--) {
      solve();
   }
   return 0;
}