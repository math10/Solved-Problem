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

const int64 INF = 1e8;
const int MX = 1000+2;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
int coins[] = { 5 , 10 , 20 , 50 , 100 , 200 };
int freq[7];
int dp[1010][7];
bool flag ;
int call(int wh,int pos) {
    if(wh == 0) return  0;
    if(pos == 6) return INF;
    int &ret = dp[wh][pos];
    if(ret != -1) return ret;
    ret = INF;
    if(flag)freq[pos] = wh / coins[pos];
    rep(i,freq[pos]+1) {
        if(wh - coins[pos]*i >= 0)
            ret = min(ret,call(wh - coins[pos]*i,pos+1)+i);
        else break;
    }
    return ret;
}

int A[1010],G[1010];

int main() {
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    flag = true;
    memo(dp,-1);
    rep(i,MX) {
        G[i] = call(i,0);
    }
    while(true) {
        int tmp = 0;
        rep(i,6) {
            freq[i] = II;
            tmp += freq[i];
        }
        if(tmp==0) return 0;
        int wh = 0;
        string st;
        cin >> st;
        int len = st.size();
        bool f = true;
        rep(i,len) {
            if(st[i] == '.') {
                f =false;
                For(j,2) {
                    if(i+j>=len) wh *=10;
                    else wh = wh*10 + (st[i+j]-'0');
                }
                break;
            }
            else wh = wh*10 + (st[i]-'0');
        }
        if(f) wh *=100;
        flag = false;
        memo(dp,-1);
        rep(i,MX) {
            A[i] = call(i,0);
        }
        int ans = INF,id;
        rep(i,MX) {
            if(wh+i < MX && ans > G[i] + A[wh+i]) {
                ans = G[i] + A[wh+i];
                id = i;
            }
        }
        printf("%3d\n",ans);
    }
}
