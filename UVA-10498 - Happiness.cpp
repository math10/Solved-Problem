// Two-phase simplex algorithm for solving linear programs of the form
//
//     maximize     c^T x
//     subject to   Ax <= b
//                  x >= 0
//
// INPUT: A -- an m x n matrix
//        b -- an m-dimensional vector
//        c -- an n-dimensional vector
//        x -- a vector where the optimal solution will be stored
//
// OUTPUT: value of the optimal solution (infinity if unbounded
//         above, nan if infeasible)
//
// To use this code, create an LPSolver object with A, b, and c as
// arguments.  Then, call Solve(x).

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

typedef long double DOUBLE;
typedef vector<DOUBLE> VD;
typedef vector<VD> VVD;
typedef vector<int> VI;



struct LPSolver {
  int m, n;
  VI B, N;
  VVD D;

  LPSolver(const VVD &A, const VD &b, const VD &c) :
    m(b.size()), n(c.size()), N(n+1), B(m), D(m+2, VD(n+2)) {
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) D[i][j] = A[i][j];
    for (int i = 0; i < m; i++) { B[i] = n+i; D[i][n] = -1; D[i][n+1] = b[i]; }
    for (int j = 0; j < n; j++) { N[j] = j; D[m][j] = -c[j]; }
    N[n] = -1; D[m+1][n] = 1;
  }

  void Pivot(int r, int s) {
    for (int i = 0; i < m+2; i++) if (i != r)
      for (int j = 0; j < n+2; j++) if (j != s)
	D[i][j] -= D[r][j] * D[i][s] / D[r][s];
    for (int j = 0; j < n+2; j++) if (j != s) D[r][j] /= D[r][s];
    for (int i = 0; i < m+2; i++) if (i != r) D[i][s] /= -D[r][s];
    D[r][s] = 1.0 / D[r][s];
    swap(B[r], N[s]);
  }

  bool Simplex(int phase) {
    int x = phase == 1 ? m+1 : m;
    while (true) {
      int s = -1;
      for (int j = 0; j <= n; j++) {
	if (phase == 2 && N[j] == -1) continue;
	if (s == -1 || D[x][j] < D[x][s] || D[x][j] == D[x][s] && N[j] < N[s]) s = j;
      }
      if (D[x][s] >= -EPS) return true;
      int r = -1;
      for (int i = 0; i < m; i++) {
	if (D[i][s] <= 0) continue;
	if (r == -1 || D[i][n+1] / D[i][s] < D[r][n+1] / D[r][s] ||
	    D[i][n+1] / D[i][s] == D[r][n+1] / D[r][s] && B[i] < B[r]) r = i;
      }
      if (r == -1) return false;
      Pivot(r, s);
    }
  }

  DOUBLE Solve(VD &x) {
    int r = 0;
    for (int i = 1; i < m; i++) if (D[i][n+1] < D[r][n+1]) r = i;
    if (D[r][n+1] <= -EPS) {
      Pivot(r, n);
      if (!Simplex(1) || D[m+1][n+1] < -EPS) return -numeric_limits<DOUBLE>::infinity();
      for (int i = 0; i < m; i++) if (B[i] == -1) {
	int s = -1;
	for (int j = 0; j <= n; j++)
	  if (s == -1 || D[i][j] < D[i][s] || D[i][j] == D[i][s] && N[j] < N[s]) s = j;
	Pivot(i, s);
      }
    }
    if (!Simplex(2)) return numeric_limits<DOUBLE>::infinity();
    x = VD(n);
    for (int i = 0; i < m; i++) if (B[i] < n) x[B[i]] = D[i][n+1];
    return D[m][n+1];
  }
};

int main() {
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    int n,m;
    while(cin >> n >> m){
        VD b,c;
        VD a[22];
        VD x;
        rep(i,n)c.pb(ID);
        rep(i,m){
            rep(j,n)a[i].pb(ID);
            b.pb(ID);
        }
        VVD A(m);
        rep(i,m)A[i] = VD(all(a[i]));
        LPSolver ret = LPSolver(A,b,c);
        double aa = ret.Solve(x);
        double ans = 0;
        rep(i,n){
            ans += x[i]*m*c[i];
        }
        ans = ans + .5;
        printf("Nasa can spend %.0lf taka.\n",ans);
    }
}
