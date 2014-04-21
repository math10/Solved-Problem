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
const int mx = 1e5 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
int arr[mx];

struct node{
    int Max,Lnum,Rnum,Lcnt,Rcnt;
    node(){
        Max = Lnum = Rnum = Lcnt = Rcnt = 0;
    }
    node(int _Max,int _Lnum,int _Rnum,int _Lcnt,int _Rcnt){
        Max = _Max;
        Lnum = _Lnum;
        Rnum = _Rnum;
        Lcnt = _Lcnt;
        Rcnt = _Rcnt;
    }
};

node e[mx<<2];

void build(int lf,int rt,int idx){
    if(lf == rt){
        e[idx] = node(1,arr[lf],arr[rt],1,1);
        return;
    }
    int mid = (lf+rt)>>1;
    build(lf,mid,idx*2);
    build(mid+1,rt,idx*2+1);
    e[idx].Max = max(e[idx*2].Max,e[idx*2+1].Max);
    e[idx].Lnum = e[idx*2].Lnum;
    e[idx].Rnum = e[idx*2+1].Rnum;
    if(e[idx*2].Rnum == e[idx*2+1].Lnum) e[idx].Max = max(e[idx].Max,e[idx*2].Rcnt+e[idx*2+1].Lcnt);
    if(e[idx*2].Lnum == e[idx*2+1].Lnum) e[idx].Lcnt = e[idx*2].Lcnt + e[idx*2+1].Lcnt;
    else e[idx].Lcnt = e[idx*2].Lcnt;
    if(e[idx*2].Rnum == e[idx*2+1].Rnum) e[idx].Rcnt = e[idx*2].Rcnt + e[idx*2+1].Rcnt;
    else e[idx].Rcnt = e[idx*2+1].Rcnt;
}

node query(int lf,int rt,int idx,int x,int y){
    if(lf>=x && rt<=y){
        return e[idx];
    }
    node ret,a,b;
    int mid = (lf+rt)>>1;
    if(y<=mid){
        return query(lf,mid,idx*2,x,y);
    }
    else if(x>mid){
        return query(mid+1,rt,idx*2+1,x,y);
    }
    else{
        a = query(lf,mid,idx*2,x,y);
        b = query(mid+1,rt,idx*2+1,x,y);
        ret.Max = max(a.Max,b.Max);
        ret.Lnum = a.Lnum;
        ret.Rnum = b.Rnum;
        if(a.Rnum == b.Lnum) ret.Max = max(ret.Max,a.Rcnt+b.Lcnt);
        if(a.Lnum == b.Lnum) ret.Lcnt = a.Lcnt+b.Lcnt;
        else ret.Lcnt = a.Lcnt;
        if(a.Rnum == b.Rnum) ret.Rcnt = a.Rcnt+b.Rcnt;
        else ret.Rcnt = b.Rcnt;
        return ret;
    }
}

int main() {
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    int n;
    while(cin >> n && n){
        int q = II;
        rep(i,n) arr[i] = II;
        build(0,n-1,1);
        while(q--){
            int x = II-1,y = II-1;
            printf("%d\n",query(0,n-1,1,x,y).Max);
        }
    }
}
