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
#define db long double
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

int64 f[15];
int N;
bool one()
{
    int64 a = (db)f[N-1]/f[N-2];
    For(i,N-1)
    {
        if(f[i-1]*a != f[i]) return false;
    }
    cout << f[N-1]*a << endl;
    return true;
}

bool two()
{
    int det = f[1]*f[1] - f[2]*f[0];
    if(det == 0 ) return false;
    int a1 = f[1]*f[2] - f[0]*f[3];
    int a2 = f[1]*f[3] - f[2]*f[2];
    a1 /= det;
    a2 /= det;

    bool flag = true;
    forab(i,2,N-1)
    {
        int tmp = f[i-1]*a1 + f[i-2]*a2;
        if(tmp != f[i])
        {
            flag = false;
            break;
        }
    }

    if(flag)
    {
        int tmp = f[N-1]*a1 + f[N-2]*a2;
        cout << tmp << endl;
        return true;
    }



    return false;
}

bool three()
{
    int a = f[2],b = f[1],c = f[0],d = -f[3];
    int l = f[3],m = f[2] ,n = f[1] ,k = -f[4] ;
    int p = f[4], q = f[3] ,r = f[2],s = -f[5];
    int D = (a*m*r+b*p*n+c*l*q)-(a*n*q+b*l*r+c*m*p);
    if(D == 0) return false;
    int a1 = ((b*r*k+c*m*s+d*n*q)-(b*n*s+c*q*k+d*m*r))/D;
    int a2 = ((a*n*s+c*p*k+d*l*r)-(a*r*k+c*l*s+d*n*p))/D;
    int a3 = ((a*q*k+b*l*s+d*m*p)-(a*m*s+b*p*k+d*l*q))/D;

    bool flag = true;
    forab(i,3,N-1)
    {
        int tmp = f[i-1]*a1 + f[i-2]*a2 + f[i-3]*a3;
        if(tmp != f[i])
        {
            flag = false;
            break;
        }
    }
    if(flag)
    {
        int tmp = f[N-1]*a1 + f[N-2]*a2 + f[N-3]*a3;
        cout << tmp << endl;
        return true;
    }

    return false;
}

int main()
{
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    int t = II;
    For(cs,t)
    {
        N = II;
        rep(i,N) f[i] = IL;
        if(one()) continue;
        else if(two()) continue;
        else if(three()) continue;
    }
}
