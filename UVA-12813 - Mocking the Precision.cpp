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
const int mx = 1e5 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
string st;
int64 powOften[18],nine[18];
int main() {
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    powOften[0] = 1;
    nine[0] = 1;
    For(i,17) powOften[i] = powOften[i-1]*10 ;
    nine[1] = 9;
    forab(i,2,17)nine[i] = nine[i-1]*10 + 9;
    while(cin >> st){
        bool sign = false;
        int64 a = 0,b = 0,c = 0,d = 0;
        int i = 0;
        int len = st.size();
        if(st[0] == '-') sign = 1,i++;
        while(i<len && st[i]!='.'){
            a = a*10 + (st[i]-'0');
            i++;
        }
        i++;
        int64 a1,a2,a3;
        a1 = a;
        a = 0;
        while(i<len){
            if(st[i] == '('){
                b = a;
                i++;
                while(i<len && st[i] != ')'){
                    a = a*10 + (st[i]-'0');
                    c++;
                    i++;
                }
                break;
            }
            a = a*10 + (st[i]-'0');
            d++;
            i++;
        }
        a -= b;
        b = nine[c] * powOften[d];
        //__(a,b)
        a2 = a;
        a3 = b;
        int64 g = __gcd(a2,a3);
        a2 /= g;a3 /= g;
        if(a2 == a3) a1++,a2 = 0;
        if(a1) {
            if(sign) cout << '-';
            cout << a1 ;
        }
        if(a2){
            if(a1) cout << ' ';
            else{
                if(sign) cout << '-';
            }
            cout << a2 << "/" << a3;
        }
        if(a1 == 0 && a2 == 0) cout << 0 ;
        NL;
    }
}
