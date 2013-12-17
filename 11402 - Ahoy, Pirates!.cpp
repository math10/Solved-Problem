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
#define OC printf("Case %d:\n",cs);
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
const int mx = 1024000 + 7;
const db pi = PI;
int EQ(double d){
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
char st[mx],ch[100];
int A[mx<<2],lazy[mx<<2];

void propagate(int lf,int rt,int idx){
    int mid = (lf+rt)>>1;
    if(lazy[idx] == 1){
        A[idx*2] = mid - lf + 1;
        A[idx*2+1] = rt - mid;
        lazy[idx*2] = lazy[idx*2+1]  = 1;
    }
    else if(lazy[idx] == 2){
        A[idx*2] = 0;
        A[idx*2+1] = 0;
        lazy[idx*2] = lazy[idx*2+1]  = 2;
    }
    else{
        A[idx*2] = (mid - lf + 1 - A[idx*2]);
        A[idx*2+1] = (rt - mid  - A[idx*2+1]);
        lazy[idx*2] = (lazy[idx*2]==0)?3:(lazy[idx*2]==3)?0:(lazy[idx*2]==1)?2:1;
        lazy[idx*2+1] = (lazy[idx*2+1]==0)?3:(lazy[idx*2+1]==3)?0:(lazy[idx*2+1]==1)?2:1;
    }
    lazy[idx] = 0;
}


void update(int lf,int rt,int idx,int x,int y,int val){
    if(lf>=x && rt<=y){
        if(val == 1 ){
            lazy[idx] = 1;
            A[idx] = (rt - lf + 1);
        }
        else if(val == 2 ){
            lazy[idx] = 2;
            A[idx] = 0;
        }
        else{
            lazy[idx] = (lazy[idx]==0)?3:(lazy[idx]==3)?0:(lazy[idx]==1)?2:1;
            A[idx] = (rt - lf + 1 - A[idx]);
        }
        return;
    }
    if(lazy[idx]) propagate(lf,rt,idx);
    int mid = (lf+rt)>>1;
    if(x<=mid) update(lf,mid,idx*2,x,y,val);
    if(y>mid) update(mid+1,rt,idx*2+1,x,y,val);
     A[idx] = A[idx*2]+A[idx*2+1];
}

int query(int lf,int rt,int idx,int x,int y){
    if(lf>=x && rt<=y) return A[idx];
    if(lazy[idx]) propagate(lf,rt,idx);
    int mid = (lf+rt)>>1,ret = 0;
    if(x<=mid) ret += query(lf,mid,idx*2,x,y);
    if(y>mid) ret += query(mid+1,rt,idx*2+1,x,y);

    return ret;
}

void build(int lf,int rt,int idx){
    lazy[idx] = 0;
    A[idx] = 0;
    if(lf == rt){
        if(st[lf] == '1')
            A[idx] = 1;
        return;
    }
    int mid = (lf+rt)>>1;
    build(lf,mid,idx*2);
    build(mid+1,rt,idx*2+1);
    A[idx] = A[idx*2]+A[idx*2+1];

}

int main(){
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
#endif
    int t = II;
    For(cs,t){
        int n = II;
        int cnt = 0;
        rep(i,n){
            int tmp = II;
            scanf("%s",ch);
            int len = strlen(ch);
            rep(j,tmp) {
                rep(k,len){
                    st[cnt++] = ch[k];
                }
            }
        }
        n = cnt;
        build(0,n-1,1);
        int q = II;
        OC;
        cnt = 0;
        while(q--){
            int x,y;
            scanf("%s %d %d",ch,&x,&y);
            if(ch[0] == 'F'){
                update(0,n-1,1,x,y,1);
            }
            else if(ch[0] == 'E'){
                update(0,n-1,1,x,y,2);
            }
            else if(ch[0] == 'I'){
                update(0,n-1,1,x,y,3);
            }
            else{
                printf("Q%d: %d\n",++cnt,query(0,n-1,1,x,y));
            }
        }
    }
}
