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
int arr[505];
vector<int>V[505];
int main(){
    int t = II;
    For(cs,t){
        rep(i,505) V[i].clear();
        int n = II,k = II;
         int64 low = 0,high = 0,mid;
        rep(i,n) {
            arr[i] = II;
            high += arr[i];
        }

        int64 ans;
        while(low<=high){
            mid = (low+high)>>1;
            int cnt = 0;
            int64 now = 0;
            rep(i,n){
                if(cnt > k) break;
                if(now+arr[i]<=mid) now += arr[i];
                else{
                    cnt++;
                    now = 0;
                    i--;
                }
            }
            if(now)
                cnt++;
            if(cnt<=k) {
                high = mid - 1;
                ans = mid;
            }
            else low = mid+1;
        }
        int cnt = 0;
        int64 tmp = 0;
        reverse(arr,arr+n);
        bool flag = false;
        rep(i,n){
            if(flag){
                V[cnt++].pb(arr[i]);
                 //printf("%d\n",arr[i]);
            }
            else if(tmp+arr[i]<=ans){
                tmp += arr[i];
                V[cnt].pb(arr[i]);
                if(n-i-1==k-cnt-1){
                    //printf("%d\n",tmp);
                    cnt++;
                    flag = true;
                }
            }
            else{
              cnt++;
              //printf("%d\n",tmp);
              i--;
              tmp = 0;
              if(n-i-1==k-cnt)
                flag = true;
            }
        }
        cnt = V[k-1].size();
        printf("%d",V[k-1][cnt-1]);
        rofba(i,0,cnt-2) printf(" %d",V[k-1][i]);
        per(i,k-1){
            printf(" /");
            cnt = V[i].size();
             rofba(j,0,cnt-1) printf(" %d",V[i][j]);
        }
        NL;
    }
}
