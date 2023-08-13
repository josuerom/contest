#include <bits/stdc++.h>             //          ██╗░█████╗░░██████╗██╗░░░██╗███████╗██████╗░░█████╗░███╗░░░███╗
using namespace std;                 //          ██║██╔══██╗██╔════╝██║░░░██║██╔════╝██╔══██╗██╔══██╗████╗░████║
                                     //          ██║██║░░██║╚█████╗░██║░░░██║█████╗░░██████╔╝██║░░██║██╔████╔██║
#ifdef josuerom                      //     ██╗░░██║██║░░██║░╚═══██╗██║░░░██║██╔══╝░░██╔══██╗██║░░██║██║╚██╔╝██║
#include "../debug.h"                   //     ╚█████╔╝╚█████╔╝██████╔╝╚██████╔╝███████╗██║░░██║╚█████╔╝██║░╚═╝░██║
#else                                //      ╚════╝░░╚════╝░╚═════╝░░╚═════╝░╚══════╝╚═╝░░╚═╝░╚════╝░╚═╝░░░░░╚═╝
#define debug(...) 42                //                         created: 12/08/23 17:35:50
#endif

#define IO_SPEED            ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define decimals(n)         cout.setf(ios::fixed, ios::floatfield); cout.precision(n);
#define uniq(v)             sort(all(v)); (v).erase(unique(all(v)),(v).end())
#define forr(i, v)          for(int (i) = (int)(v).size()-1; (i) >= 0; (i)--)
#define mod(a, b)           ((((a) % (MOD)) + ((b) % (MOD))) % (MOD))
#define VEREDICT(cond)      cout << ((cond) ? "YES" : "NO") << '\n'
#define fori(i, b, n)       for(int (i) = (b); (i) < (n); (i)++)
#define binary_search(v, k) sort(v); binary_search(all(v), (k))
#define mcm(a, b)           ((a) * (b)) / gcd((a), (b))
#define memset(ar, n)       memset((ar),(n),sizeof(ar))
#define rall(v)             (v).rbegin(),(v).rend()
#define PI                  3.14159265358979323846L
#define EULER               2.71828182845904523536L
#define count_bits(n)       __builtin_popcountll(n)
#define lbd(v, n)           lower_bound(all(v), (n))
#define ubd(v, n)           upper_bound(all(v), (n))
#define ull                 unsigned long long int
#define all(v)              (v).begin(),(v).end()
#define fore(e, va)         for (auto &(e): (va))
#define mxe(v)              max_element(all(v))
#define mne(v)              min_element(all(v))
#define log(n)              __builtin_clzll(n)
#define is_ordered(v)       is_sorted(all(v))
#define lowbit(x)           ((x) & ((-x)))
#define rsort(v)            sort(rall(v))
#define mcd(a, b)           gcd((a), (b))
#define ll                  long long int
#define sort(v)             sort(all(v))
#define eb                  emplace_back
#define sbl(a, b)           ((a) << (b))
#define sbr(a, b)           ((a) >> (b))
#define pf                  push_front
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define se                  second
#define fi                  first
#define br                  '\n'

int ds, ys, dm, ym;

void solveProblemJ() {
   cin >> ds >> ys >> dm >> ym;
   int m = mcm(ys, ym);
   int x = max(ds, dm);
   while ((x % m != ds % m) || (x % ym != dm % ym))
      x++;
   cout << (m - ds) << '\n';
}

int main() {
   IO_SPEED;
   int tt = 1;
   // cin >> tt;
   for (int nc = 1; nc <= tt; nc++) {
#ifdef josuerom
      cout << "------ Case #" << nc << " ------\n";
      solveProblemJ();
#else
      solveProblemJ();
#endif
   }
   return 0;
}