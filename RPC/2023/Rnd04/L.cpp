/**
 *  author:  josuerom
 *  created: 15/04/23 17:05:34
**/
#pragma GCC optimize("03,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

#define ld long double

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n;
   cin >> n;
   vector<ld> c(n);
   ld volumen = 0.0f;
   for (int i = 0; i < n; i++) {
      cin >> c[i];
      volumen += pow(c[i], 3);
   }
   // raíz cúbica de la suma de los lados al cubo
   ld ans = (ld) cbrt(volumen);
   cout << fixed << setprecision(15);
   cout << ans << '\n';
   return 0;
}