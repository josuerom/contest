#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <functional>
#include <string>
#include <cstring>
#include <cassert>
#include <numeric>
#include <complex.h>
#include <complex>
#include <cmath>
#include <iomanip>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define forn1(i, n) for(int i = 1; i <= (int)(n); i++)
#define rforn(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define rforn1(i, n) for(int i = (int)(n); i >= 1; i--)
#define fort(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a, b) for(int i = (int)(a); i <= (int)(b); i++)
#define rfort(i, a, b) for(int i = (int)(b) - 1; i >= (int)(a); i--)
#define rrep(i, a, b) for(int i = (int)(b); i >= (int)(a); i--)
#define trav(x, a) for(auto &x : a)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define decimal(x) cout.setf(ios::fixed, ios::floatfield); cout.precision(x);

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int N = 6e5 + 5;
const ll oo = 2e18;
const ll mod = 1e9 + 7;
const double eps = 1e-5;
#define double long double
typedef complex<double> point;
 
double area(vector<point> p){
	double res = 0;
	int n = p.size();
	p.push_back(p[0]);
	for(int i = 0 ;i  < n; ++i){
		res += (p[i].real() - p[i + 1].real())*(p[i].imag() + p[i + 1].imag());
	}
	return abs(res)/2;
}
 
double dis2(const point& a, const point& b){
	return (a.real() - b.real())*(a.real() - b.real()) + (a.imag() - b.imag())*(a.imag() - b.imag());
}
 
double calc(const point& a, const point& b, const point& c){
	double da2 = dis2(b, c);
	double db2 = dis2(c, a);
	double dc2 = dis2(a, b);
	vector<double> d = {da2, db2, dc2};
	sort(d.begin(), d.end());
	if(d[2] >= d[1] + d[0] + sqrt(d[1])*sqrt(d[0])){
		return sqrt(d[0]) + sqrt(d[1]);
	}
	return sqrt((da2 + db2 + dc2 + 4*sqrt(3)*area({a, b, c}))/2);
}
 
point x[3];
 
double getAns(const point& p){
	double v[3];
	for(int i = 0; i < 3; ++i){
		v[i] = calc(p, x[i], x[(i + 1)%3]);
	}
	//cout << v[0] << " " << v[1] << " " << v[2] << "\n";
	return max({v[0], v[1], v[2]});
}
 
double getY(double x){
	double l = -1e9, r = 1e9;
	while(r - l > eps){
		double m1 = (r + 2*l)/3;
		double m2 = (l + 2*r)/3;
		double v1 = getAns({x, m1}), v2 = getAns({x, m2});
		if(v1 < v2) r = m2;
		else l = m1;
	}
	return l;
}
 
 
 
void solve() {
	for(int i = 0 ; i < 3; ++i){
		double a, b;
		cin >> a >> b;
		x[i] = {a, b};
	}
	
	double l = -1e9, r = 1e9;
	while(r - l > eps){
		double x1 = (r + 2*l)/3;
		double x2 = (l + 2*r)/3;
		double y1 = getY(x1), y2 = getY(x2);
		if(getAns({x1, y1}) < getAns({x2, y2})) r = x2;
		else l = x1;
	}
	//cout << area({x[0], x[1], x[2]}) << "\n";
	//cout << l << " " << getY(l) << "\n";
	//cout << eps << "\n";
	//cout << getAns({2.3842,0.4151}) << "\n";
	cout << fixed << setprecision(4);
	cout << getAns({l, getY(l)});
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tc = 1;
	//cin >> tc;
	while (tc--)
	{
		solve();
	}
}