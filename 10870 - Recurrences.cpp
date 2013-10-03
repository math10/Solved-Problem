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
#define EPS 1e-10
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2 * acos (0.0)
//}
typedef long long int64;
typedef unsigned long long int64u;
#define memo(a,v) memset(a,v,sizeof(a))
#define all(a) a.begin(),a.end()
#define INF 1<<29
#define db double
#define pb push_back
#define pii pair<int ,int >
#define NL puts("")
#define mx 100005
//{
//Intput_Output
#define II ({ int a; scanf("%d",&a); a;})
#define IL ({ int64 a; scanf("%lld",&a);  a;})
#define ID ({ db a; scanf("%lf",&a);  a;})
#define IC ({ char a; scanf("%c",&a);  a;})
#define IS ({ string a; cin >> a;  a;})
#define ICA(n) ({ char a[n]; scanf("%s",&a);  a;})
#define OC printf("Case %d:",cs);
#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);
//}
//}
template <class T, class U> inline T max (T &a, U &b) { return a > b ? a : b; }
template <class T, class U> inline T min (T &a, U &b) { return a < b ? a : b; }
template <class T, class U> inline T swap (T &a, U &b) { a ^= b ; b = a ^ b ; a ^= b; }
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction
int M,SZ = 20;

struct Matrix{
    int64 mat[20][20];
};
Matrix matMul(Matrix A,Matrix B)
{
    Matrix C;
    for(int i = 0 ; i < SZ ; i++)
        for(int j = 0 ;j < SZ ;j++)
        {
            C.mat[i][j] = 0 ;
            for(int k = 0 ; k < SZ ;k++){
                C.mat[i][j]=((C.mat[i][j]%M)+(((A.mat[i][k]%M)*(B.mat[k][j]%M))%M))%M;
            }
        }
    return C;
}

void Copy(Matrix &A,Matrix &B)
{
    for(int i = 0 ; i < SZ ; i++)
        for(int j = 0 ; j < SZ ; j++)
            B.mat[i][j]= A.mat[i][j];
}

Matrix matExpo(Matrix BASE,int p) // X^p
{
    if(p==1)return BASE;
    Matrix R = matExpo(BASE, p >> 1 );
    R = matMul(R,R);
    if(p&1) R = matMul(R,BASE);
    return R;
}

void Zero(Matrix &A)
{
    for(int i = 0 ; i < SZ; i++)
        for(int j = 0 ; j < SZ ; j++)
            A.mat[i][j]=0;
}
void Identity(Matrix &A)
{
    for(int i = 0 ;i < SZ ; i++)
        for(int j = 0 ; j < SZ; j++)
            A.mat[i][j]= i == j ? 1 : 0 ;
}

int main(){
    int64 d,n,m;
    Matrix Base;
    while(cin >>d >> n >> m){
        if(d==0 && n==0 && m==0) return 0;
        SZ = d;
        M = m;
        int fib[20];
        memo(Base.mat,0);
        rep(i,d) {
            cin >> Base.mat[0][i];
            if(i) Base.mat[i][i-1] = 1;
        }
        rep(i,d) cin >> fib[i];
        if(n<=d) cout << fib[n-1] << endl;
        else{

            Matrix ret = matExpo(Base,n-d);
            int64 ans = 0;
          /* rep(i,d) {
                rep(j,d) cout << ret.mat[i][j] << " ";
                puts("");
            }*/
            rep(i,d) ans = (ans + ret.mat[0][i]*fib[d - i - 1])%M;
            cout << ans << endl;
        }
    }
}
