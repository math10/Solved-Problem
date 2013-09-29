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
int arr[6000];

int main() {
    int t = II;

    while(t--) {
        int n = II;
        rep(i,n) arr[i] = II;
        sort(arr,arr+n);

        int ans = 0,i;
        for(i = n-1; i>=3; i-=2) {
            int t1 = arr[0]*2 + arr[i-1] + arr[i];
            int t2 = arr[0] + arr[1]*2 + arr[i];
            ans += min(t1,t2);
        }
        if(i==2) ans += arr[0]+arr[1]+arr[2];
        else if(i==1) ans += arr[1];
        else ans += arr[0];
        printf("%d\n",ans);
        for(i = n-1; i>=3; i-=2) {
            int t1 = arr[0]*2 + arr[i-1] + arr[i];
            int t2 = arr[0] + arr[1]*2 + arr[i];
            if(t1<t2){
                printf("%d %d\n",arr[0],arr[i]);
                printf("%d\n",arr[0]);
                printf("%d %d\n",arr[0],arr[i-1]);
                printf("%d\n",arr[0]);
            }
            else{
                printf("%d %d\n",arr[0],arr[1]);
                printf("%d\n",arr[0]);
                printf("%d %d\n",arr[i],arr[i-1]);
                printf("%d\n",arr[1]);
            }
        }
        if(i==2) {
            printf("%d %d\n",arr[0],arr[1]);
            printf("%d\n",arr[0]);
            printf("%d %d\n",arr[0],arr[2]);
        }
        else if(i==1) {
            printf("%d %d\n",arr[0],arr[1]);
        }
        else {
            printf("%d\n",arr[0]);
        }
        if(t) NL;
    }
    return 0;
}
