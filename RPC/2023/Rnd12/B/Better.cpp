/**
 *   █▀█  █▀▀▄ ─▀─ ▀▀█▀▀ █▀▀ ▄▀ ▀▄
 *   ─▄▀  █▀▀▄ ▀█▀ ──█── ▀▀█ █─ ─█
 *   █▄▄  ▀▀▀─ ▀▀▀ ──▀── ▀▀▀ ▀▄ ▄▀
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 100;
int a[N], b[N], n;

void solve() {
   cin >> n;
   for (int i = 0; i < n; i++)
      cin >> a[i];
   for (int i = 0; i < n; i++)
      cin >> b[i];
   sort(a, a + n);
   sort(b, b + n);
   int ca = 0, cb = 0;
   for (int i = 0; i < n; i++) {
      if (a[i] > b[i]) ca++;
      else if (a[i] < b[i]) cb++;
   }
   if (ca > cb) cout << "first\n";
   else if (cb > ca) cout << "second\n";
   else cout << "tie\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   solve();
   return 0;
}