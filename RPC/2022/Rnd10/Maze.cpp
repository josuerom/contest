#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#define DEBUG "BUG!!!!\n"
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp> 
 
//using namespace __gnu_pbds;
using namespace std;
 
const long long inf = 1e18;
const long long Nmax = 1e5+5;
const long long MOD = 998244353;
const long double eps = 1e-18;
 
//typedef tree<long long,null_type,less<long long32_t>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
long long ab(long long a)
{
    if(a<0)return -a;else return a;
}
long double ab(long double a)
{
    if(a+eps<0)return -a;else return a;
}
long long POW(long long x,long long t)
{
    if(t==0)return 1;
    long long tmp=POW(x,t/2);
    if(t%2)return tmp*tmp%MOD*x%MOD;else return tmp*tmp%MOD;
}
long long gcd(long long a,long long b)
{
    if(b)return gcd(b,a%b);else return a;
}
pair<int,int>p[]={{1,0},{0,-1},{0,1},{-1,0}};
bool d[21][360];
bool adj[21][360][4];
void dfs(int r,int deg)
{
    //cout<<r<<" "<<deg<<endl;
    d[r][deg]=1;
    if(r==20)return;
    for(int i=0;i<4;i++)
    {
        int newr=r+p[i].first,newdeg=(deg+p[i].second+360)%360;
        if(r<0)continue;
        if(!adj[r][deg][i])continue;
        if(d[newr][newdeg])continue;
        dfs(newr,newdeg);
    }
}
main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input","r",stdin);
    int T=1;
    cin>>T;
    while(T--)
    {
        for(int i=0;i<=20;i++)
        {
            for(int j=0;j<360;j++)
            {
                d[i][j]=0;
                for(int k=0;k<4;k++)
                    adj[i][j][k]=1;
            }
        }
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            char ch;
            cin>>ch;
            if(ch=='C')
            {
                int r,deg1,deg2;
                cin>>r>>deg1>>deg2;
                while(deg1!=deg2)
                {
                    adj[r-1][deg1][0]=0;
                    adj[r][deg1][3]=0;
                    (deg1+=1)%=360;
                }
            }else
            {
                int r1,r2,deg;
                cin>>r1>>r2>>deg;
                int pre=(deg-1+360)%360;
                while(r1!=r2)
                {
                    adj[r1][deg][1]=0;
                    adj[r1][pre][2]=0;
                    r1++;
                }
            }
        }
        for(int deg=0;deg<360;deg++)
        {
            dfs(0,deg);
        }
        bool ans=0;
        for(int deg=0;deg<360;deg++)ans|=d[20][deg];
        if(ans)cout<<"YES"<<endl;else cout<<"NO"<<endl;
    }
}