/**
   ░░█ █▀█ █▀ █░█ █▀▀ █▀█ █▀█ █▀▄▀█
   █▄█ █▄█ ▄█ █▄█ ██▄ █▀▄ █▄█ █░▀░█
**/
#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define br  '\n'

const int N = 42;
int n;
bool dp[N][N], flag;

void solve() {
   cin >> n;
   flag = 0;
   for (int i = 1; i < 2 * n; ) {
      bool control = 1;
      for (int j = 1; j < 2 * n; ) {
         if (!flag) {
            if (control) {
               dp[i - 1][j - 1] = 1;
               dp[i - 1][j] = 1;
               dp[i][j - 1] = 1;
               dp[i][j] = 1;
            }
            control = !control;
         } else {
            if (!control) {
               dp[i - 1][j - 1] = 1;
               dp[i - 1][j] = 1;
               dp[i][j - 1] = 1;
               dp[i][j] = 1;
            }
            control = !control;
         }
         j += 2;
      }
      flag = !flag;
      i += 2;
   }
   for (int i = 0; i < 2 * n; i++) {
      for (int j = 0; j < 2 * n; j++) {
         cout << (dp[i][j] ? "#" : ".");
      }
      cout << br;
   }
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
