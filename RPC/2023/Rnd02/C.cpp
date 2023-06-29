/**
 *  author:  josuerom
 *  created: 11/03/23 22:01:04
**/
#pragma GCC optimize("03,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cout << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define sz(vec) (int) vec.size()
#define ll long long
#define endl '\n'

int main() {
   ios::sync_with_stdio(false); cin.tie(0);
   int n, k, d, s;
   cin >> n >> k >> d >> s;
   double ans = (double) ((n*d)-(k*s)) / (n-k);
   if (ans<0 || ans>100) {
      cout << "impossible" << endl;
   } else if (ans == (int) ans) {
      cout << fixed << setprecision(1) << ans << "0" << endl;
   } else {
      cout << fixed << setprecision(7) << ans << endl;
   }
   return 0;
}