/**
 *  author:  josuerom
 *  created: 25/03/23 16:24:18
**/
#include <bits/stdc++.h>
using namespace std;

unsigned int solve(std::string& input) {
   auto s = input.begin();
   unsigned int flipCnt = 0u;
   while (s != input.end()) {
      char last = *s;
      char curr = *(++s);
      bool found = false;
      while (s != input.end()) {
         if (curr == last) {
         found = true;
         break;
         }
         last = curr;
         curr = *(++s);
      }
      if (!found)
      break;
      char matched = curr;
      char toFind = (matched == '+') ? '-' : '+';
      auto e = s;
      last = *e;
      curr = *(++e);

      while (e != input.end()) {
         if (curr == last && curr == toFind)
         break;
         last = curr;
         curr = *(++e);
      }
      reverse(s, e);
      ++flipCnt;
   }
   return flipCnt;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   string input;
   cin >> input;
   cout << solve(input) << '\n';
   return 0;
}