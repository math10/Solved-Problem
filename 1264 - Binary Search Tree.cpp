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
template <class T, class U> inline T max (T &a, U &b) {
    return a > b ? a : b;
}
template <class T, class U> inline T min (T &a, U &b) {
    return a < b ? a : b;
}
template <class T, class U> inline T swap (T &a, U &b) {
    T tmp = a;
    a = b;
    b = tmp;
}
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

const int64 INF = (1ll)<<50;
const int mx = 1e6 + 7;
const int mod = 9999991 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
struct st{
    int num,l,r;
}p[22];
int64 dp[22],nCr[22][22],cnt[22];
int n;
int c ;

void insert(int num,int pos){

    if(p[pos].num < num){
        if(p[pos].l == 0){
            p[pos].l = c++;
            p[p[pos].l].num = num;
        }
        else insert(num,p[pos].l);
    }
    else{
        if(p[pos].r == 0){
            p[pos].r = c++;
            p[p[pos].r].num = num;
        }
        else insert(num,p[pos].r);
    }
}

int call(int pos){
    if(pos == 0){
        return dp[pos] = 1ll;
    }
    cnt[pos] = 1ll;
    dp[pos] = (call(p[pos].l)*call(p[pos].r))%mod;
    cnt[pos] += cnt[p[pos].l] + cnt[p[pos].r];
    dp[pos] = dp[pos]*nCr[cnt[pos]-1][cnt[p[pos].l]];
    dp[pos] %= mod;
    return dp[pos];
}


int main() {
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    rep(i,21) {
        nCr[i][0] = 1ll;
        For(j,20)
            nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % mod;
    }
    int t = II;
    For(cs,t) {
        rep(i,21)p[i].l=p[i].r=0;
        n = II;
        p[1].num = II;
        c = 2;
        rep(i,n-1) {
            int x = II;
            insert(x,1);
        }
        memo(dp,-1);
        memo(cnt,0);
        int64 ans = call(1);
        cout << ans << endl;
    }

}
