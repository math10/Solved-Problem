/*
Author :: MD. Musfiqur Rahman Sanim
Aust cse 28th Batch
ID:11.02.04.097
*/
/** Chinese postman problem (you have to find the “cost” of the shortest route that starts and ends on the same vertex after visiting every edge at least once.)

    If the graph is a Eulerian circuit(all the node has even degree) then it has a optimal solution which is the sum of all edge cost;
    If not, then we have to make the graph Eulerian by adding some dammy edge optimally

**/

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
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

const int INF = (1<<30);
const int mx = 1e5 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
int n,m;
int64 dis[16][16],deg[16],tmpNode[16],tdis[16][16];
int64 dp[1<<15];
/** chossing the dummay edges dynamically which will minimum the cost **/
int64 call(int mask){
    if(mask == (1<<n)-1) return 0;
    int64 &ret = dp[mask];
    if(ret != -1) return ret;
    ret = INF;
    /** taking two nodes & gives them a edge & make them even degree nodes **/
    rep(i,n)rep(j,n){
        if(i == j) continue;
        if(mask&(1<<i)) continue;
        if(mask&(1<<j)) continue;
        int m = mask|(1<<i);
        m = (m|(1<<j));
        ret = min(ret,call(m)+tdis[i][j]);
    }
    return ret;
}


int main() {
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif

    while(cin >> n && n){
        m = II;
        rep(i,n){
            rep(j,n){
                dis[i][j] = INF;
            }
            dis[i][i] = 0;
        }
        memo(dp,-1);
        int64 ans = 0;
        For(i,m){
            int x  = II-1,y = II-1,w = II;
            dis[x][y] = min(dis[x][y],w);
            dis[y][x] = min(dis[y][x],w);
            deg[x]++;
            deg[y]++;
            ans += w;
        }
        /** Floyd-Warshall for minimum distance **/
        rep(k,n)rep(i,n)rep(j,n){
            if(dis[i][j] > dis[i][k] + dis[k][j] ){
                dis[i][j] = dis[i][k] + dis[k][j] ;
            }
        }
        int tn = 0;
        /** select the odd degree nodes & make a new graph with them using Floyd-Warshall **/
        rep(i,n)if(deg[i]%2==1)tmpNode[tn++] = i;
        rep(i,tn)rep(j,tn){
            tdis[i][j] = dis[tmpNode[i]][tmpNode[j]];
        }
        n = tn;
        cout << ans+call(0) << endl;
        rep(i,16)deg[i] = 0;

    }
}
