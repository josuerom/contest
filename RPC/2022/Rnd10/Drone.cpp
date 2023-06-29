#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
const int mxn = 1510;
int mat[mxn][mxn], n;
 
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin>>n;
    vector<pair<int, pair<int, int> > > val;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>mat[i][j];
            val.push_back(make_pair(mat[i][j], make_pair(i, j)));
        }
    }
    sort(begin(val), end(val));
    map<int, int> col, row;
 
    long long ans = 0;
 
    for(auto [x, y] : val) {
        auto [i, j] = y;
        ans += 1ll * row[i] * (n-1-col[j]) + 1ll * col[j] * (n-1-row[i]);
        row[i]++; col[j]++;
    }
 
    ans /= 2;
    cout << ans << '\n';
 
    return 0;
}