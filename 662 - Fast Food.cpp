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
#define EPS 1e-10
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2 * acos (0.0)
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
    a ^= b ;
    b = a ^ b ;
    a ^= b;
}
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction
int arr[202],n,k;
int dp[202][35];
pii p[202][35];

int call(int pos,int give) {
    if( give == k) return ((pos==(n+1))?0:INF);
    if(pos == (n+1)) return ((give == k)?0:INF);
    int &ret = dp[pos][give];
    if(ret != -1) return ret;
    ret = INF;
    int x = 0;
    int f[202] = {0},cnt = 1;
    forab(i,pos,n) {
        f[cnt++] = arr[i] - arr[pos-1];
        int low = (cnt)/2;
        int d = f[low] - f[low-1];
        int tmp = 0;
        forab(j,1,cnt-1) tmp += abs(f[j] - f[j-1] - d);
        if(ret>call(i+1,give+1)+tmp) {
            ret = call(i+1,give+1)+tmp;
            p[pos][give] = pii(i,low + pos - 1);
        }
    }
    return ret;
}

void print(int pos,int give) {
    if(give == k) return;
    if(p[pos][give].first == pos) printf("Depot %d at restaurant %d serves restaurant %d\n",give+1,pos,pos);
    else printf("Depot %d at restaurant %d serves restaurants %d to %d\n",give+1,p[pos][give].second,pos,p[pos][give].first);
    print(p[pos][give].first+1,give+1);
}

int main() {
#ifdef Sanim
   freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    int cs = 1;
    while(true) {
        n = II,k = II;
        if(n==0 && k==0) return 0;
        For(i,n) {
            arr[i] = II;
            arr[i] += arr[i-1];
        }
        memo(dp,-1);
        printf("Chain %d\n",cs++);
        int ans = call(1,0);
        print(1,0);
        printf("Total distance sum = %d\n\n",ans);
    }
}
