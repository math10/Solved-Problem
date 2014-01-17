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
const int MX = 50000 + 7;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}


//all are 1 indexed Graph


vector<int > adj[MX],Radj[MX],order,Comp,size;
bool used[MX];
int newCompId[MX],dp[MX];
int N , M , scc;

void dfs1(int u) {
    used[u] = true ;
    forstl(it,adj[u]) if( !used[ *it ] ) dfs1( *it );
    order.pb(u);
}

void dfs2(int u , int scc ) {
    newCompId[u] = scc ;
    used[u] =  true ;
    Comp.pb(u);
    forstl(it,Radj[u]) if( !used[ *it ] ) dfs2( *it , scc );
}

void Reset() {
    For(i,N) {
        adj[i].clear();
        Radj[i].clear();
    }
    memo(newCompId,0);
    memo(used,false);
    memo(dp,-1);
    size.clear();
    order.clear();
}

void Input() {
    cin >> N ;
    M = N;
    rep(i,M) {
        int u = II , v = II ;
        adj[u].pb(v);
        Radj[v].pb(u);
    }
}

void Zip() {
    reverse(all(order));
    scc = 0 ;
    forstl(it,order) {
        int v = *it ;
        if( !used[ v ] ) {
            scc++;
            Comp.clear();
            dfs2(v,scc);
            size.pb(Comp.size());
            //printf("No.%d SCC components are ->  ",scc);
            //forstl(u,Comp) printf(" %d",*u);
            //puts("");
        }
    }
}

void Kosaraju() {
    For(i,N) if( !used[i] ) dfs1(i);
    memo(used,false);
    Zip();
}


int call(int pos){
    int &ret = dp[pos];
    if(ret != -1) return ret;
    ret = size[newCompId[pos]-1];
    forstl(it,adj[pos]){
        if(newCompId[pos] != newCompId[*it]){
            ret += call(*it);
        }
    }
    return ret;
}

int main() {
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif

    int t = II;
    memo(dp,-1);
    For(cs,t) {
        Input();
        Kosaraju();
        int ans = 0,id;
        For(i,N){
            int tmp = call(i) ;
            //cout << tmp << endl;
            if(tmp > ans){
                ans = tmp;
                id = i;
            }
        }
        OC;
        printf(" %d\n",id);
        Reset();
    }
}
