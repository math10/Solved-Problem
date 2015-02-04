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
char str1 [82], str2 [82];

int visit [82][82],c;
int cache [82][82];
int len1, len2;

set<string> words;

int lcs (int i, int j) {
    if (i == len1 || j == len2) return cache[i][j]=0;
    int &ret = cache [i][j];
    if (visit [i][j] == c) return ret;
    visit [i][j] = c;

    ret = 0;
    if (str1 [i] == str2 [j]) ret = lcs (i + 1, j + 1) + 1;
    ret = max(ret,max (lcs (i + 1, j), lcs (i, j + 1)));

    return ret;
}
int solve;
string ans;
int cnt = 0;
/*
TLE
void path_print (int i, int j) {
    if (cnt == solve) {
        words.insert (ans);
        return;
    }
    if(cache [i][j] == solve-cnt){
        if (str1 [i] == str2 [j] && cache [i+1][j+1] == solve-cnt-1) {
            ans[cnt++] = str1[i];
            path_print (i + 1, j + 1);
            cnt--;
        }
        if (cache [i + 1][j] == solve-cnt) path_print (i + 1, j);
        if (cache [i][j-1] == solve-cnt) path_print (i, j + 1);
    }
}
*/
void path_print (int i, int j) {
    if (cnt == solve) {
        words.insert (ans);
        return;
    }
    forab(k,i,len1-1){
        forab(l,j,len2-1){
            if(str1[k] == str2[l] && cache[k][l] == solve-cnt){
                ans[cnt++] = str1[k];
                path_print(k+1,l+1);
                cnt--;
            }
        }
    }
}
int main(){
#ifdef Sanim
    //geting WA check int64 & int64u
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    int t;
    scanf ("%d", &t);

    for (int kase = 1; kase <= t; kase++) {
        scanf ("%s %s",&str1, &str2);
        c++;
        len1 = strlen (str1);
        len2 = strlen (str2);
        solve = lcs (0, 0);
        ans.resize(solve);
        cnt = 0;
        path_print (0, 0);
        forstl(it,words)
            printf("%s\n",(*it).c_str());

        words.clear ();
        ans.clear ();
        if (kase != t) puts("");
    }

    return 0;
}
