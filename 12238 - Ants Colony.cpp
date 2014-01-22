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
#define pii pair<int64 ,int64 >
#define NL puts("")
#define ff first
#define ss second
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

const int64 INF = 1ll<<60;
const int mx = 20000 + 7;
const db pi = PI;
const int mod = 1e9 + 7;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}

const int MX = 1e5 + 7 ;
const int MXLG = 22 ;
vector<pii>edge[MX] ;
int64 N , P[MX][MXLG] , L[MX] , T[MX];
int64 minE[MX][MXLG] , maxE[MX][MXLG] , dist[MX];
pii res;
bool Vis[MX];
void dfs(int64 u , int64 p , int64 d){
    Vis[u] = true ;
    T[u] = p ; /** T holds only the parent of node , make sure T is initialized **/
    L[u] = d ; /** L denotes nodes are in which Level ? **/
    forstl(i,edge[u]){
        int64 v = i->ff , w = i->ss;
        if( Vis[v] ) continue;
        P[v][0] = u ; /** make sure P[v][0] is initialized , it is the 2^0 means 1st parent of v **/
        minE[v][0] = maxE[v][0] = w ;
        dist[v] = dist[u] + w ;
        dfs(v,u,d+1);
    }
}
void preprocess() {
    for( int64 i = 1 ; i < N ; i++ ) {
        for( int64 j = 0 ; (1 << j) < N ; j++ ) {
            P[i][j] = -1 ;
            maxE[i][j] = -INF;
            minE[i][j] = +INF;
        }
    }
    dfs(0,-1,0); /** if input tree contains 0 as root call u = 0 else 1 **/
    for( int64 j = 1 ; (1 << j) < N ; j++ ) {
        for( int64 i = 1 ; i < N ; i++ ) {
            if( P[i][j - 1] == -1 ) continue ;
            P[i][j] = P[ P[i][j - 1] ][j - 1];
            maxE[i][j] = max( maxE[i][j - 1] , maxE[ P[i][j - 1] ][j - 1] );
            minE[i][j] = min( minE[i][j - 1] , minE[ P[i][j - 1] ][j - 1] );
        }
    }
}
void Reset(){
    for( int64 i = 0 ; i <=  N ; i++ ){
        edge[i].clear();
        Vis[i] = false ;
        dist[i] = -1;
    }
    dist[0] = 0 ;/** 0 is root of  the tree **/
}
int64 lca(int64 p , int64 q) {
    if(L[p] < L[q] ) swap(p,q);
    res.ff = +INF , res.ss = -INF ; int64 lg ;
    for( lg = 1 ; (1 << lg) <= L[p] ; ++lg ); lg--;
    for( int64 i = lg ; i >= 0 ; i--){
        if( L[p] - (1 << i) >= L[q] ){
            res.ff = min( res.ff , minE[p][i] );
            res.ss = max( res.ss , maxE[p][i] );
            p = P[p][i];
        }
    }
    if( p == q ) return p ;
    for( int64 i = lg ; i >= 0 ; i-- ){
        if( P[p][i] != -1 && P[p][i] != P[q][i]){
            res.ff = min(res.ff , min( minE[p][i] , minE[q][i]));
            res.ss = max(res.ss , max( maxE[p][i] , maxE[q][i]));
            p = P[p][i];
            q = P[q][i];
        }
    }
    res.ff = min(res.ff , min( minE[p][0] , minE[q][0]));
    res.ss = max(res.ss , max( maxE[p][0] , maxE[q][0]));
    return P[p][0]; // T[p]
}
void Input(){
    Reset();
    For(i,N-1) {
        int64 v = II, w = II ;
        edge[i].pb(pii(v,w));
        edge[v].pb(pii(i,w));
    }
}
int64 getDistance(int64 x , int64 y){ /** find distance of path x to y **/
    int64 a = lca(x,y);
    int64 Ans = dist[x] + dist[y] - 2 * dist[a] ;
    return Ans;
}
int main(){
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    while( scanf("%d",&N) && N ) {
        Input();
        preprocess();
        int64 q = II;
        while(q--){
            int64 u = II,v = II;
            printf("%lld",getDistance(u,v));
            if(q) printf(" ");
        }
        NL;
    }
}
