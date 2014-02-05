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
const int mx = 20000 + 7;
const db pi = PI;
const int mod = 10056;
int EQ(double d){
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
int dp[102][102][102],n,d;
bool flag[102];
pii arr[102];
int call(int now,int prev,int poss){
    if(now == n+1){
        if(arr[prev].first == 1)
            return (d - arr[prev].second);
        else return max(d - arr[prev].second , d - arr[poss].second);
    }
    int &ret = dp[now][prev][poss];
    if(ret != -1) return ret;
    int r1 = INF,r2 = INF;
    if(arr[now].first == 1){
        r1 = max(max(call(now+1,now,now),arr[now].second - arr[prev].second),arr[now].second - arr[poss].second);
        ret = min(r1,r2);
    }
    else{
        r1 = max(call(now+1,now,poss),arr[now].second - arr[prev].second);
        r2 = max(call(now+1,prev,now),arr[now].second - arr[poss].second);
        ret = min(r1,r2);
    }

    return ret;

}

int main(){
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    int t = II;
    For(cs,t){
        n = II,d = II;
        arr[0] = pii(1,0);
        For(i,n){
            string st;
            cin >> st;
            int num = 0,len=st.size()-1;
            forab(i,2,len) num = num * 10 + (st[i]-'0');
            if(st[0] == 'B'){
                arr[i] = pii(1,num);
            }
            else arr[i] = pii(2,num);
        }
        memo(dp,-1);
        OC;
        cout << " " << call(1,0,0) << endl;

    }
}
