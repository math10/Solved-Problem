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

const int INF = 1e9;
const int mx = 20000 + 7;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
int dx[] = {0,0,1};
int dy[] = {-1,1,0};
int dp[80][80][7][5],K,N;
int arr[80][80];
bool vis[80][80][7][5];
bool flag ;
//int path[80][80][7][5];
int call(int x,int y,int k,int dir){
    if(k>K) return -INF;
    if(x == N-1 && y == N-1) {
        flag = true;
        return 0;
    }
    int &ret = dp[x][y][k][dir];
    if(vis[x][y][k][dir]) return ret;
    vis[x][y][k][dir] = true;
    ret = -INF;
    rep(i,3){
        //int tmp = ret;
        int u = x + dx[i];
        int v = y + dy[i];
        if(u>=0 && v>=0 && u<N && v<N ){
            if(i == 0 && (dir == 0 || dir == 2)){
                ret = max(ret,call(u,v,k+(arr[u][v]<0),i)+arr[u][v]);
               // if(ret != tmp) path[x][y][k][dir] = i;
            }
            else if( i == 1 && (dir == 1 || dir == 2)){
                ret = max(ret,call(u,v,k+(arr[u][v]<0),i)+arr[u][v]);
                //if(ret != tmp) path[x][y][k][dir] = i;
            }
            else if(i == 2){
                ret = max(ret,call(u,v,k+(arr[u][v]<0),i)+arr[u][v]);
               // if(ret != tmp) path[x][y][k][dir] = i;
            }
        }
    }
    return ret;
}

/*void print_path(int x,int y,int k,int dir){
    cout << path[x][y][k][dir] << endl;
    if( x == N-1 && y == N-1) return;
    int u = x + dx[path[x][y][k][dir]],v = y + dy[path[x][y][k][dir]];
    print_path(u,v,k+(arr[u][v]<0),path[x][y][k][dir]);
}
*/
int main() {
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    int cs = 0;
    while(cin >> N >> K){
        if(N == 0 && K == 0 ) return 0;
        cs++;
        memo(vis,0);
        rep(i,N)rep(j,N)arr[i][j] = II;
        flag = false;
        int ans = call(0,0,arr[0][0]<0,2)+arr[0][0];
        OC;
        if(flag)
            cout << " " << ans << endl;
        else cout << " impossible\n";
        //print_path(0,0,arr[0][0]<0,2);
    }

}
