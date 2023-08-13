/**
 *   author:  josuerom
 *   created: 17/07/23 17:30:24
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
   string s1, s2;
   cin >> s1 >> s2;
   int n1 = s1.size();
   int n2 = s2.size();
   int m = max(n1, n2);
   int d = abs(n1 - n2);
   if (d != 0) {
      string a = "";
      if (n1 != m) {
         for (int i = 0; i < d; i++)
            a += "0";
         s1 = a + s1;
      } else {
         for (int i = 0; i < d; i++)
            a += "0";
         s2 = a + s2;
      }
   }
   string ans = "";
   for (int i = 0; i < m; i++) {
      int x = s1[i] - '0', y = s2[i] - '0';
      if ((x <= 2 && y <= 2) || (x >= 7 && y >= 7)) ans += "0";
      else ans += "9";
   }
   cout << ans << '\n';
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