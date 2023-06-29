/**
 *  author:  josuerom
 *  created: 25/02/23 13:39:25
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
#define ll unsigned long long
#define endl '\n'

int main() {
   ios::sync_with_stdio(false); cin.tie(0);
   string s;
   cin >> s;
   int n = s.length();
   int l = 0, aux = 0, prev = -1;
   for (int i = l; i <= n-1; i++) {
      if (s[i] == '1') {
         if (prev == -1 || i - prev > 1) {
            aux++;
            prev = i;
         }
      }
   }
   //dbg(prev, aux);
   int ans = (prev-1) / aux;
   cout << ans << endl;
   return 0;
}