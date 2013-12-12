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

const int INF = 1e9 + 7LL;
const int mx = 1e6 + 7;
const int64 mod = 1e13 + 7;
const db pi = PI;
int EQ(double d){
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
int arr[12][112],n,m;
int path[112][12];
int dp[112][12];

int call(int pos,int i){
    if(pos == m) return 0;
    int &ret = dp[pos][i];
    if(ret != -1) return ret;
    ret = call(pos+1,(i+1)%n)+arr[(i+1)%n][pos] ;
    path[pos][i] = (i+1)%n;
    if(ret > call(pos+1,i)+arr[i][pos] || (ret == call(pos+1,i)+arr[i][pos] && path[pos][i] > i )){
        ret = call(pos+1,i)+arr[i][pos];
        path[pos][i] = i;
    }
    if(ret > call(pos+1,(i-1+n)%n)+arr[(i-1+n)%n][pos] || (ret == call(pos+1,(i-1+n)%n)+arr[(i-1+n)%n][pos] && path[pos][i] > (i-1+n)%n )){
        ret = call(pos+1,(i-1+n)%n)+arr[(i-1+n)%n][pos];
        path[pos][i] = (i-1+n)%n;
    }

    return ret;
}

void print_path(int pos,int a){
    if(pos == m) return;
    cout << " " << a+1;
    print_path(pos+1,path[pos+1][a]);
}

int main(){
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif


    while(cin >> n >> m){
        memo(dp,-1);
        rep(i,n)rep(j,m) arr[i][j] = II;
        int ans = INF,id;
        rep(i,n){
            if(ans > call(1,i)+arr[i][0]){
                ans = call(1,i)+arr[i][0];
                id = i;
            }
        }
        cout << id+1;
        print_path(1,path[1][id]);
        NL;
        cout << ans << endl;
    }
}

