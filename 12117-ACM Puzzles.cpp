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
#define EPS 1e-6
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
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

int arr[22][22] = { 1,2,6,12,14,18,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    1,2,6,12,14,18,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    1,2,6,12,14,18,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    5,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    1,2,6,12,14,18,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    19,21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    15,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    19,21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    15,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    19,21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    1,2,6,12,14,18,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    4,10,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    1,2,6,12,14,18,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    11,13,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    1,2,6,12,14,18,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    4,10,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    11,13,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    15,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                    };
int flag[] = {0,1,0,1,1,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0};
int len[] = {0,1,2,1,1,2,2,1,1,1,1,1,2,1,2,1,2,2,2,1,2,2,2};
int st[] = {1,2,6,12,14,18,22};
int l[] = {1,2,2,2,2,2,2};
int64u dp[2010][23],n;
bool vis[2010][23];
int64 ans[2010];
const int64u Mod = 1e12;
int64u call(int pos,int prev){
    if(pos > n) return 0;
    if(pos == n){
        return flag[prev];
    }
    int64u &ret = dp[pos][prev];
    if(vis[pos][prev]) return ret;
    vis[pos][prev] = true;
    ret = 0;
    rep(i,22){
        if(arr[prev-1][i]){
            ret = (ret + call(pos+len[arr[prev-1][i]],arr[prev-1][i]))%Mod;
            if(ret<0) ret += Mod;
        }
        else break;
    }
    return ret;
}

int main(){
    memo(ans,-1);
    int cs = 0;
    while(true){
        cs++;
        n = II;
        if(n==0) return 0;
        OC;
        if(ans[n] != -1){
            cout << " " << ans[n] << endl;
            continue;
        }
        memo(vis,false);
        ans[n] = 0;
        rep(i,7){
            ans[n] = (ans[n] + call(l[i],st[i]))%Mod;
        }
        cout << " " << ans[n] << endl;
    }
}
