/**
 *  █▀█  █▀▀▄ ─▀─ ▀▀█▀▀ █▀▀ ▄▀ ▀▄
 *  ─▄▀  █▀▀▄ ▀█▀ ──█── ▀▀█ █─ ─█
 *  █▄▄  ▀▀▀─ ▀▀▀ ──▀── ▀▀▀ ▀▄ ▄▀
 *  created: 26/08/23 16:31:14
**/
#include <bits/stdc++.h>
using namespace std;

#ifdef _2BITS
#include "../debug.h"
#else
#define debug(...) 42
#endif

clock_t startTime;
double getCurrentTime() {
   return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

long long n, k;

void solveProblemJ() {
   cin >> n >> k;
   if (n == 1 || k == 1) {
      cout << 1 << endl;
      return;
   }
   long long pos = 63LL;
   while ((k & (1LL << pos)) == 0)
      pos--;
   cout << (1LL << pos) << endl;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr); cout.tie(nullptr);
   int tt = 1;
   // cin >> tt;
   for (int nc = 1; nc <= tt; nc++) {
#ifdef _2BITS
      cout << "------ Case #" << nc << " ------\n";
      solveProblemJ();
      cout << "time: " << setprecision(5) << getCurrentTime() << " ms\n";
#else
   solveProblemJ();
#endif
   }
   return 0;
}