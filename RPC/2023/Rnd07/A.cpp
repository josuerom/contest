/**
 *   author:  josuerom
 *   created: 24/06/23 13:02:10
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
   string n;
   cin >> n;
   sort(rall(n));
   cout << n << '\n';
   return 0;
}