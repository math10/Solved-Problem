/*
Author :: MD. Musfiqur Rahman Sanim
Aust cse 28th Batch
ID:11.02.04.097
*/


//{ Template
using namespace std;
//{ C-headers
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cassert>
#include <ctime>
//}
//{ C++-headers
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <utility>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
//}
//{ Loops
#define forab(i,a,b) for (__typeof(b) i = (a); i <= (b); ++i)
#define rep(i,n) forab (i, 0, (n) - 1)
#define For(i,n) forab (i, 1, n)
#define rofba(i,a,b) for (__typeof(b) i = (b); i >= (a); --i)
#define per(i,n) rofba (i, 0, (n) - 1)
#define rof(i,n) rofba (i, 1, n)
#define forstl(i,s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
//}
//{ Floating-points
#define EPS 1e-7
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2*acos (0.0)
//}
typedef long long int64;
typedef unsigned long long int64u;
#define memo(a,v) memset(a,v,sizeof(a))
#define all(a) a.begin(),a.end()
#define db double
#define pb push_back
#define pii pair<int ,int >
#define NL puts("")
//{
//Intput_Output
#define II ({ int a; scanf("%d",&a); a;})
#define IL ({ int64 a; scanf("%lld",&a);  a;})
#define ID ({ db a; scanf("%lf",&a);  a;})
#define IC ({ char a; scanf("%c",&a);  a;})
#define IS ({ string a; cin >> a;  a;})
#define ICA(n) ({ char a[n]; scanf("%s",&a);  a;})
#define OC printf("Case %d:",cs);
//}
//}
template <class T, class U> inline T max (T &a, U &b)
{
    return a > b ? a : b;
}
template <class T, class U> inline T min (T &a, U &b)
{
    return a < b ? a : b;
}
template <class T, class U> inline T swap (T &a, U &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

const int64 INF = (500000LL * 1000000000LL) + 7LL;
const int mx = 20000 + 7;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
map<string ,int >m;
vector<int >adj[202];
int dp[202][2];
bool take[202][2];
vector<int >V;
int call(int node,bool prev) {

    int &ret = dp[node][prev];
    if( ret != -1) return ret;

    ret = 0;
    if(prev) {
        forstl(it,adj[node]) ret += call(*it,false);
        take[node][prev] = false;
    }
    else {
        int tmp = 0;
        forstl(it,adj[node]) tmp += call(*it,true);
        tmp++;
        ret = tmp;
        tmp = 0;
        forstl(it,adj[node]) tmp += call(*it,false);
        if(ret >= tmp) {
            take[node][prev] = true;
        } else {
            ret = tmp;
            take[node][prev] = false;
        }
    }
    return ret;
}

void path(int node,bool prev) {
    if(take[node][prev]) {
        V.pb(node);
    }
    forstl(it,adj[node]) path(*it,take[node][prev]);
}
int dp2[202][2][202];
int call2(int node,bool prev,int notTake) {
    int &ret = dp2[node][prev][notTake];
    if(ret != -1) return ret;
    ret = 0;
    if(prev || node == notTake) {
        forstl(it,adj[node]) ret += call2(*it,false,notTake);
    }
    else {
        int tmp = 0;
        forstl(it,adj[node]) tmp += call2(*it,true,notTake);
        tmp++;
        ret = tmp;
        tmp = 0;
        forstl(it,adj[node]) tmp += call2(*it,false,notTake);
        ret = max(ret,tmp);
    }

    return ret;
}

int main() {
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    int n ;
    while(cin >> n && n) {
        memo(dp,-1);
        memo(dp2,-1);
        m.clear();
        string a,b;
        int cnt = 0;
        cin >> a;
        m[a] = cnt++;
        rep(j,n-1) {
            cin >> a >> b;
            if(m.find(a) == m.end()) m[a] = cnt++;
            if(m.find(b) == m.end()) m[b] = cnt++;
            adj[m[b]].pb(m[a]);
        }
        int ans = 0;
        forstl(it,adj[0]) ans += call(*it,false);
        int tmp = 0;
        forstl(it,adj[0]) tmp += call(*it,true);
        tmp++;
        V.clear();
        if(ans > tmp) {
            forstl(it,adj[0]) path(*it,false);
        }
        else {
            V.pb(0);
            forstl(it,adj[0]) path(*it,true);
        }
        ans = max(ans,tmp);
        bool flag = true;
        forstl(it,V) {
            //cout << *it << " ";
            tmp = 0;
            forstl(iit,adj[0]) tmp += call2(*iit,false,*it);
            if(tmp == ans) {
                flag = false;
                break;
            }

            if(*it != 0) {
                tmp = 0;
                forstl(iit,adj[0]) tmp += call2(*iit,true,*it);
                tmp++;
                if(tmp == ans) {
                    flag = false;
                    break;
                }
            }

        }
        if(flag) cout << ans << " Yes\n";
        else cout << ans << " No\n";
        rep(i,cnt) adj[i].clear();
    }
}
