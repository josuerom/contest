/**
   ░░█ █▀█ █▀ █░█ █▀▀ █▀█ █▀█ █▀▄▀█
   █▄█ █▄█ ▄█ █▄█ ██▄ █▀▄ █▄█ █░▀░█
**/
#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define br  '\n'

string m;
int x;

void solve() {
   cin >> x >> m;
   if (x >= 0 && x <= 11) {
      if (x == 0) cout << "12" << m << " AM\n";
      else if (x < 10) cout << "0" << x << m << " AM\n";
      else cout << x << m << " AM\n";
   } else {
      if (x == 12) cout << x << m << " PM\n";
      else if ((x - 12) < 10) cout << "0" << (x - 12) << m << " PM\n"; 
      else cout << x - 12 << m << " PM\n";
   }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int tt = 1, nc = 1;
   cin >> tt;
   while (tt--) solve();
   return 0;
}
