/**
   ░░█ █▀█ █▀ █░█ █▀▀ █▀█ █▀█ █▀▄▀█
   █▄█ █▄█ ▄█ █▄█ ██▄ █▀▄ █▄█ █░▀░█
**/
#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define br  '\n'

int a, b, c;

void solve() {
   cin >> a >> b >> c;
   if (a < b && b < c) cout << "STAIR\n";
   else if (a < b && b > c) cout << "PEAK\n";
   else cout << "NONE\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int tt = 1, nc = 1;
   cin >> tt;
   while (tt--) {
#ifdef LOCAL
      cout << "Case #" << nc++ << ":\n";
      solve();
#else
      solve();
#endif
   }
   return 0;
}