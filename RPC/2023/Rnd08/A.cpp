/**
 *   author:  josuerom
 *   created: 15/07/23 23:06:00
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

int a[3];

void solve() {
   for (int i = 0; i < 3; i++)
      cin >> a[i];
   sort(a, a + 3);
   if (a[0] + a[1] == a[2])
      cout << "1\n";
   else if (a[0] * a[1] == a[2])
      cout << "2\n";
   else
      cout << "3\n";
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