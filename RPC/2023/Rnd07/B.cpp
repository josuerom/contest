/**
    █▀█ 　 █▀▀▄ ─▀─ ▀▀█▀▀ █▀▀ 　 ▄▀ ▀▄
    ─▄▀ 　 █▀▀▄ ▀█▀ ──█── ▀▀█ 　 █─ ─█
    █▄▄ 　 ▀▀▀─ ▀▀▀ ──▀── ▀▀▀ 　 ▀▄ ▄▀
    created: 24/06/23 14:11:30
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef josuerom
#include "debug.h"
#else
#define debug(...) 42
#endif

#define rall(x) (x).rbegin(),(x).rend()
#define all(x) (x).begin(),(x).end()
#define ull unsigned long long int
#define len(x) (int) (x).size()
#define ll long long int
#define pb push_back
#define mp make_pair
#define se second
#define fi first

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr); cout.tie(nullptr);
   int d, m, y, n, di, mi, yi;
   cin >> d >> m >> y >> n >> di >> mi >> yi;
   int i = 0, xj = m, yj = d;
   while (true) {
      if (n == 7) n = 0;
      if (d == 30) {
         d = 0;
         if (m == 12) m = 0;
         m++;
      }
      n++; d++; i++;
      // debug(d, m, i, n);
      if (d == di && m == mi) break;
   }
   cout << (abs(xj - mi)==0 && yj < di ? n : n - 1) << '\n';
   return 0;
}
/* TEST CASES i: 360
20 10 1999 5
15 4 2002
4

20 4 1000 5
15 4 2999
2

20 11 2021 7
29 11 2021
2

20 11 2021 7
27 11 2021
7
*/