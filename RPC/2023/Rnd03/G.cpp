/**
 *  author:  josuerom
 *  created: 25/03/23 16:35:54
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n, i, j;
   string s;
   cin >> n >> s;
   int maxA = (int)sqrt(n), out, ans = 0;
   char C = 'O';
   for (i = 3; i <= maxA; i++) {
      int in = out = 0, m = i * i;
      for (j = 0; j < m; j++) {
         if (s[j] == C) in++;
         else out++;
      }
      for (j = 0; j < n - m; j++) {
         if (in == (i - 2) * (i - 2) && in + out == m) ans++;
         if (out == (i-2)*(i-2) && in + out == m) ans++;
         if (s[j] == C) in--;
         else out--;
         if (s[j + m] == C) in++;
         else out++;
      }
      if ((in==(i-2)*(i-2) && in+out==m) || (out==(i-2)*(i-2) && in+out==m)) ans++;
   }
   cout << ans << '\n';
   return 0;
}