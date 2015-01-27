/*
Author :: MD. Musfiqur Rahman Sanim
Aust cse 28th Batch
ID:11.02.04.097
*/


//{ Template
using namespace std;
//{ headers
#include<bits/stdc++.h>
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
#define eb emplace_back
#define pii pair<int ,int >
#define NL puts("")
#define ff first
#define ss second
//{
//Intput_Output
#define gc getchar
#define II ({ int a; read(a); a;})
#define IL ({ int64 a; read(a);  a;})
#define ID ({ db a; scanf("%lf",&a);  a;})
#define IC ({ char a; scanf("%c",&a);  a;})
#define IS ({ string a; cin >> a;  a;})
#define OC printf("Case %d:",cs);
//}
//}
#define _stl(x) {__stl_print__(x);}
#define __(args...) {dbg,args; cerr<<endl;}
template<class T>inline bool read(T &x){int c=gc();int sgn=1;while(~c&&c<'0'|c>'9'){if(c=='-')sgn=-1;c=gc();}for(x=0;~c&&'0'<=c&&c<='9';c=gc())x=x*10+c-'0';x*=sgn;return ~c;}
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"    "; return *this; }}dbg;
template <class T> void __stl_print__ (T &x) { // for all STL containers
    cerr << "["; forstl (i, x) cerr << (i != x.begin () ? ", " : "") << *i; cerr << "]" << endl;
}
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
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
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
int n,m;
int dp[1<<20][12];
int path[1<<20][12];
int arr[22];
int a[22];
vector<pii >v[22];

int cal(int mask,int id){

    int num = arr[id];
    forstl(it,v[id]){
        if((mask&(*it).ff) ==(1<<id)) continue;
           num -= (*it).ss;
    }
    return num;
}

int call(int mask,int take){
    if(take == m){
        return 0;
    }
    int &ret  = dp[mask][take];
    if(ret != -1) return ret;
    ret = 0;
    rep(i,n){
        if(mask&(1<<i)) continue;
        int x = cal(mask|(1<<i),i);
        int tmp = call(mask|(1<<i),take+1) + x;
        if(ret < tmp){
            ret = tmp;
            path[mask][take] = i;
        }
    }
    return ret;
}

void path_print(int mask,int take){
    if(take == m) return;
    int x = path[mask][take];
    cout << x+1  ;
    if(take+1 < m) cout << " ";
    else cout << endl;
    path_print(mask|(1<<x),take+1);
}

int main() {
#ifdef Sanim
	//geting WA check int64 & int64u
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    int cs = 0;
    while(true){
        n = II,m = II;
        if(!(n+m)) break;
        rep(i,n) {
            arr[i] = II;
            v[i].clear();
        }
        int t = II;
        rep(i,t){
            int tt = II;
            int msk = 0;
            rep(j,tt){
                a[j] = II-1;
                msk |= (1<<a[j]);
            }
            int x = II;
            rep(j,tt){
                v[a[j]].pb(pii(msk,x));
            }
        }
        memo(dp,-1);
        printf("Case Number  %d\nNumber of Customers: ",++cs);
        cout << call(0,0) << endl;
        printf("Locations recommended: ");
        path_print(0,0);
        cout << endl;
    }
}
