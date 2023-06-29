#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int n;
vector<ll> pre;
 
ll f(double s, double e) {
    ll res = 0;
    for (double i = 0.5+s; i <= -0.5+e; i += 0.5) {
        double mid1 = (i+s)/2, mid2 = (i+e)/2;
        int idx1 = mid1/100, idx2 = mid2/100;
        if (mid2 == (int)mid2 && (int)mid2%100 == 0) idx2 = mid2/100 - 1;
        else idx2 = mid2/100;
        idx1 = min(idx1, n); idx2 = min(idx2, n);
        res = max(res, pre[idx2] - pre[idx1]);
    }
    return res;
}
 
void solve() {
    int m, x; cin >> n >> m;
    vector<ll> arr;
    pre = vector<ll>(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> x;
        pre[i] = x + pre[i-1];
    }
    for (int i = 0; i < m; i++) {
        cin >> x;
        arr.push_back(x+100);
    }
    sort(arr.begin(), arr.end());
 
    vector<ll> new_arr;
    int L = 0;
    for(; L < arr.size(); L++) {
        if (arr[L] <= 100*n) new_arr.push_back(arr[L]);
        else {
            if (arr[L] < 2*(100*n+1)) new_arr.push_back(arr[L]);
            break;
        }
    }
    L = new_arr.size();
    if (L == 0) {
        cout << pre[n];
        return;
    }
    ll res = 0;
    if (new_arr[0] != 100) res = pre[min((new_arr[0]-1)/100, 1LL*n)];
    else if (L == 1) {
        cout << pre[n] - pre[1];
        return;
    }
    if (new_arr[L-1] < 100*n) res = max(res, pre[n] - pre[new_arr[L-1]/100]);
 
    for (int i = 0; i < L-1; i++) {
        res = max(res, f(new_arr[i], new_arr[i+1]));
    }
    cout << res;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    while (tc--) {
        solve();
    }
    return 0;
}