/**
 *   █▀█  █▀▀▄ ─▀─ ▀▀█▀▀ █▀▀ ▄▀ ▀▄
 *   ─▄▀  █▀▀▄ ▀█▀ ──█── ▀▀█ █─ ─█
 *   █▄▄  ▀▀▀─ ▀▀▀ ──▀── ▀▀▀ ▀▄ ▄▀
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
char a[N], b[N];
int n;

void solve() {
   cin >> n;
   for (int i = 0; i < n; i++)
      cin >> a[i];
   for (int i = 0; i < n; i++)
      cin >> b[i];
   int ans = 0;
   for (int i = 0; i < n; i++) {
      int cr = abs(a[i] - b[i]), cl = -1;
      if (a[i] < b[i]) {
         for (char j = a[i]; true; j--) {
            cl++;
            if (j == b[i]) break;
            if (j == 65) j = 91;
         }
      } else {
         for (char j = a[i]; true; j++) {
            cl++;
            if (j == b[i]) break;
            if (j == 90) j = 64;
         }
      }
      ans += min(cl, cr);
   }
   cout << ans << '\n';
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   solve();
   return 0;
}
