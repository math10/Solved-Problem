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

const int64 INF = (500000LL * 1000000000LL) + 7LL;
const int mx = 20000 + 7;
const db pi = PI;
int EQ(double d){
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}

int64 call(int64 mid){
    int64 cnt = 0;
    if(mid >= 100){
        cnt += (100*2);
    }else{
        cnt += mid*2;
        return cnt;
    }
    if(mid >= 10000){
        cnt += 9900*3;
    }else{
        cnt += (mid - 100)*3;
        return cnt;
    }
    if(mid >= 1000000){
        cnt += (1000000 - 10000)*5;
    }else{
        cnt += (mid - 10000)*5;
        return cnt;
    }
    cnt += (mid - 1000000)*7;

    return cnt;
}

int main(){
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    int64 a,b;
    while(cin >> a >> b){
        if(a == 0 && b == 0) return 0;
        int64 low = 0,high = a,tot = -1;
        while(low<=high){
            int64 mid = (low+high)>>1;
            int64 cnt = call(mid);
            if(cnt == a) {
                tot = mid;
                break;
            }else if(cnt < a){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        low = 0,high = tot;
        while(low<=high){
            int64 mid = (low + high)>>1;
            int64 cnt = call(tot - mid) - call(mid);
            //cout << low << " " << high << " " << mid << endl;
            if(cnt == b){
                cout << call(mid) << endl;
                break;
            }
            else if(cnt > b){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
}
