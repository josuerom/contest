/**
 *   █▀█  █▀▀▄ ─▀─ ▀▀█▀▀ █▀▀ ▄▀ ▀▄
 *   ─▄▀  █▀▀▄ ▀█▀ ──█── ▀▀█ █─ ─█
 *   █▄▄  ▀▀▀─ ▀▀▀ ──▀── ▀▀▀ ▀▄ ▄▀
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
int a[N], n, mn;

void solve() {
   cin >> n;
   for (int i = 0; i < n; i++)
      cin >> a[i];
   sort(a, a + n);
   cout << a[0] + a[1] << '\n';
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   solve();
   return 0;
}