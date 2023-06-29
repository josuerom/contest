/**
 *  author:  josuerom
 *  created: 6/05/23 15:41:08
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   vector<char> s1{'a','b','c','d','e','f','g','q','r','s','t','v','w','x','z'};
   vector<char> s2{'h','i','j','k','l','m','n','o','p','u','y'};
   string s;
   cin >> s;
   int n = (int) s.size();
   int ans = 1;
   if (binary_search(s1.begin(), s1.end(), s[0])) {
   	for (int i = 1; i < n; i++) {
   		if (i%2==0) {
   			if (binary_search(s1.begin(), s1.end(), s[i])) ans++;
   		} else {
   			if (binary_search(s2.begin(), s2.end(), s[i])) ans++;
   		}
   	}
   } else {
   	for (int j = 1; j < n; j++) {
   		if (j%2==1) {
   			if (binary_search(s1.begin(), s1.end(), s[j])) ans++;
   		} else {
   			if (binary_search(s2.begin(), s2.end(), s[j])) ans++;
   		}
   	}
   }
   cout << (ans==n ? "yes" : "no") << '\n';
   return 0;
}