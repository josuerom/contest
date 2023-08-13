/**
 *   author:  josuerom
 *   created: 16/07/23 16:32:29
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

const int MAX = 37;
char s[MAX];
char vocal[] = {'a','e','i','o','u'};

bool Vocal(char c) {
   for (int l = 0; l < 5; l++) if (c == vocal[l]) {
      return 1;
   }
   return 0;
}

bool Consonant(char c) {
   for (int l = 0; l < 5; l++) if (c == vocal[l]) {
      return 0;
   }
   return 1;
}

void solve() {
   scanf("%s", s);
   int n = strlen(s);
   if(n > 1) {
      bool is_vocal = 0;
      for (int i = 0; i < 5; i++) if (s[0] == vocal[i]) {
         is_vocal = 1;
      }
      int ans = 1;
      for (int i = 1; i < n; i++) {
         if (is_vocal && Consonant(s[i])) ans++;
         if (!is_vocal && Vocal(s[i])) ans++;
         is_vocal = (is_vocal) ? 0 : 1;
      }
      cout << (ans == n ? 1 : 0) << '\n';
   } else cout << "1\n";
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