/**
   ░░█ █▀█ █▀ █░█ █▀▀ █▀█ █▀█ █▀▄▀█
   █▄█ █▄█ ▄█ █▄█ ██▄ █▀▄ █▄█ █░▀░█
**/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 42
#endif

#define ll  long long
#define br  '\n'

const int N = 20 + 1e1;

void solve() {
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