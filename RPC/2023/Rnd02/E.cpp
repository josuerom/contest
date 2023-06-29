/**
 *  author:  josuerom
 *  created: 11/03/23 22:07:17
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
   double N, r, p;
   cin >> N;
   r = sqrt(N/M_PI);
   p = 2*M_PI*r;
   cout << fixed << setprecision(9) << p << endl;
   return 0;
}
