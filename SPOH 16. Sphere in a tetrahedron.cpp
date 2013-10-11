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
template <class T, class U> inline T max (T &a, U &b) {
    return a > b ? a : b;
}
template <class T, class U> inline T min (T &a, U &b) {
    return a < b ? a : b;
}
template <class T, class U> inline T swap (T &a, U &b) {
    a ^= b ;
    b = a ^ b ;
    a ^= b;
}
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction
//(x/a)^2 + (y/b)^2 = 1;


int main() {
    int t = II;
    For(cs,t) {
        db u,v,w,U,V,W;
        db Volume = 0,area = 0;
        cin >> u >> v >> w >> W >> V >> U;

        //Volume of a tetrahedron start
        Volume = 4*u*u*v*v*w*w;
        Volume -= u*u*pow(v*v+w*w-U*U,2);
        Volume -= v*v*pow(w*w+u*u-V*V,2);
        Volume -= w*w*pow(u*u+v*v-W*W,2);
        Volume += (v*v+w*w-U*U)*(w*w+u*u-V*V)*(u*u+v*v-W*W);
        Volume = sqrt(Volume);
        Volume /= 12;
        //Volume of tetrahedron end

        //area of a tetrahedron start
        double s1 = (double) ((U + V + W) / 2);
        double s2 = (double) ((u + v + W) / 2);
        double s3 = (double) ((u + V + w) / 2);
        double s4 = (double) ((U + v + w) / 2);

        double L1 = sqrt(s1*(s1-U)*(s1-V)*(s1-W));
        double L2 = sqrt(s2*(s2-u)*(s2-v)*(s2-W));
        double L3 = sqrt(s3*(s3-u)*(s3-V)*(s3-w));
        double L4 = sqrt(s4*(s4-U)*(s4-v)*(s4-w));

        area = L1 + L2 + L3 + L4;
        //area of a tetrahedron end

        //the radius of a sphere inscribed in the given tetrahedron.
        double R = (Volume*3.0)/(area);

        printf ("%.4lf\n",R);
    }
}
