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
#define INF 1<<29
#define db double
#define pb push_back
#define pii pair<int ,int >
#define NL puts("")
#define mx 100005
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
int EQ(double d)
{
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}

int R,C,M,N,W;
bool water[102][102];
bool flag[102][102];
int cal[102][102];
int dxx[10],dyy[10];
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

bool valid(int x,int y){
    return (x>=0 && x<R && y>=0 && y<C && !water[x][y]);
}

void dfs(int x,int y){
    flag[x][y] = true;
    set<pii>S;
    S.clear();
    rep(i,8){
        int u = x + dxx[i],v = y + dyy[i];
        if(valid(u,v)){
            S.insert(pii(u,v));
            if(!flag[u][v]) {
                dfs(u,v);
            }
        }
    }
    cal[x][y] = S.size();

}

int main()
{
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    int t = II;
    For(cs,t){
        memo(water,false);
        memo(flag,false);
        memo(cal,0);
        cin >> R >> C >> M >> N >> W;
        rep(i,8){
            if(dx[i] == 1) dxx[i] = N;
            else if(dx[i] == -1) dxx[i] = -N;
            else if(dx[i] == 2) dxx[i] = M;
            else if(dx[i] == -2) dxx[i] = -M;
            if(dy[i] == 1) dyy[i] = N;
            else if(dy[i] == -1) dyy[i] = -N;
            else if(dy[i] == 2) dyy[i] = M;
            else if(dy[i] == -2) dyy[i] = -M;
        }
        rep(i,W){
            int x = II,y = II;
            water[x][y] = true;
        }
        dfs(0,0);
        int even = 0,odd = 0;
        rep(i,R){
            rep(j,C){
                if(!water[i][j] && flag[i][j] ){
                    if(cal[i][j]%2) odd++;
                    else even++;
                }
            }
        }
        OC;
        cout << " " << even << " " << odd << endl;
    }
}
