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

int n , m ,sc,snk;
vector<int >v;
bool graph[30][30];
bool dp[1<<16][16];
stack<int >s;
bool call(int mask,int pre){
    if(mask == (1<<n)-1) return (pre == snk);
    if(dp[mask][pre]) return false;
    dp[mask][pre] = true;
    rep(i,n){
        if(mask & (1<<i)) continue;
        if(graph[pre][i] && call(mask|(1<<i),i)) {
                s.push(i);
                return true;
        }
    }

    return false;
}

int main() {

#ifdef Sanim
	//geting WA check int64 & int64u
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    int T = II ;
    For(cs,T){
        n = II ;
        m = II;
        char ch1[2],ch2[2];
        v.clear();
        rep(i,n){
            scanf("%s",ch1);
            v.pb(ch1[0]-'A');
        }
        sc  = v[0];
        snk = v[n-1];
        sort(all(v));
        int cnt = 0;
        sc = lower_bound(all(v),sc) - v.begin();
        snk = lower_bound(all(v),snk) - v.begin();
        memo(graph,0);
        rep(i,m){
            scanf("%s %s",ch1,ch2);
            int a = lower_bound(all(v),ch1[0]-'A') - v.begin();
            int b = lower_bound(all(v),ch2[0]-'A') - v.begin();
            graph[a][b] = graph[b][a] = 1;
        }
        printf("Case %d: ",cs);
        memo(dp,0);
        if(call(1<<sc,sc)){
                s.push(sc);
                while(!s.empty()){
                    printf("%c",v[s.top()]+'A');
                    s.pop();
                }
                puts("");
        }else printf("impossible\n");
        while(!s.empty()) s.pop();

    }
}
