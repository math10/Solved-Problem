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

const int64 INF = (1ll)<<50;
const int mx = 200000 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
int arr[mx],A[mx<<2];

void build(int lf,int rt,int idx){
    if(lf == rt){
        A[idx] = arr[lf];
        return;
    }
    int mid = (lf+rt)>>1;
    build(lf,mid,idx*2);
    build(mid+1,rt,idx*2+1);
    A[idx] = A[idx*2] + A[idx*2+1];
}

void update(int lf,int rt,int idx,int x,int val){
    if(lf == x && rt == x){
        A[idx] = val;
        return;
    }
    int mid = (lf+rt)>>1;
    if(x<=mid) update(lf,mid,idx*2,x,val);
    else update(mid+1,rt,idx*2+1,x,val);
    A[idx] = A[idx*2] + A[idx*2+1];
}

int query(int lf,int rt,int idx,int x,int y){
    if(lf>=x && rt<=y){
        return A[idx];
    }
    int ret = 0,mid = (lf+rt)>>1;
    if(x<=mid) ret = query(lf,mid,idx*2,x,y);
    if(y>mid)  ret += query(mid+1,rt,idx*2+1,x,y);
    return ret;
}

int main() {
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    int n ;
    int cs = 0;
    while(cin >> n && n){
        if(cs) NL;
        cs++;
        rep(i,n) arr[i] = II;
        build(0,n-1,1);
        char ch[10];
        OC;NL;
        while(true){
            scanf("%s",ch);
            if(strcmp(ch,"END") == 0) break;
            int x = II,y = II;
            if(ch[0] == 'M') printf("%d\n",query(0,n-1,1,x-1,y-1));
            else update(0,n-1,1,x-1,y);
        }
    }
}
