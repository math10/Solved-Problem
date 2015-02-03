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
#define pii pair<int ,int >
#define NL puts("")
#define ff first
#define ss second
//{
//Intput_Output
#define gc getchar
template<class T>inline bool read(T &x){int c=gc();int sgn=1;while(~c&&c<'0'|c>'9'){if(c=='-')sgn=-1;c=gc();}for(x=0;~c&&'0'<=c&&c<='9';c=gc())x=x*10+c-'0';x*=sgn;return ~c;}
#define II ({ int a; read(a); a;})
#define IL ({ int64 a; read(a);  a;})
#define ID ({ db a; scanf("%lf",&a);  a;})
#define IC ({ char a; scanf("%c",&a);  a;})
#define IS ({ string a; cin >> a;  a;})
#define OC printf("Case %d:",cs);
//}
//}
#define __(args...) {dbg,args; cerr<<endl;}
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"    "; return *this; }}dbg;
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
const int mx = 1e7 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}

#define MM mx

#define PrimeLIMIT mx
#define MAX_TOTAL 664583

unsigned int prime[PrimeLIMIT / 64], pr[MAX_TOTAL], prlen;
#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))
void sieve() {
	unsigned int i,j,sqrtN,i2;
	memset( prime, -1, sizeof( prime ) );
	sqrtN = (int64) sqrt ( ( double ) PrimeLIMIT ) + 1;
	for( i = 3; i < sqrtN; i += 2 ) if( gP( i ) )
		for( j = i * i, i2 = i << 1; j < PrimeLIMIT; j += i2 ) rP( j );
	pr[prlen++] = 2;
	for( i = 3; i < PrimeLIMIT; i += 2 ) if( gP( i ) ) pr[prlen++] = i;
}

int cnt[mx];
int main() {
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    sieve();

    int st = 0;
    For(i,mx-7){
        cnt[i] = cnt[i-1];
        if(pr[st] == i)cnt[i]++,st++;
    }
    int a,b;
    while(scanf("%d %d",&a,&b) ){
        if(a==0 && b==0) break;
        int64 ans = 0;
        a--;
        For(i,prlen-1){
            if(pr[i] > a/2) break;
            int num = a - pr[i];
            if(num < pr[i]) break;
            ans = ans + cnt[num] - cnt[pr[i]];
        }
        ans = -ans;
        For(i,prlen-1){
            if(pr[i] > b/2) break;
            int num = b - pr[i];
            if(num < pr[i]) break;
            ans = ans + cnt[num] - cnt[pr[i]];
        }
        printf("%lld\n",ans);
    }
}
