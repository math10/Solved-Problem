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
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
#define memo(a,v) memset(a,v,sizeof(a))
#define all(a) a.begin(),a.end()
#define INF 1<<29
#define ll long long
#define db double
#define pb push_back
#define pii pair<int ,int >
#define NL puts("")
#define mx 100005
//{
//Intput_Output
#define II ({ int a; scanf("%d",&a); a;})
#define IL ({ ll a; scanf("%lld",&a);  a;})
#define ID ({ db a; scanf("%lf",&a);  a;})
#define IC ({ char a; scanf("%c",&a);  a;})
#define IS ({ string a; cin >> a;  a;})
#define ICA(n) ({ char a[n]; scanf("%s",&a);  a;})
#define OC printf("CASE %d:",cs);
#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);
//}
//}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction
vector<int >V[22];
int cnt = 0,arr[22];
bool flag[22];
int n;
void call(int pos){
    int u = arr[pos];
    if(u == n){
        cnt++;
        printf("1");
        For(i,pos){
            printf(" %d",arr[i]);
        }
        NL;
        return ;
    }
    int len = V[u].size();
    rep(i,len){
        if(!flag[V[u][i]]){
            flag[V[u][i]] = true;
            arr[pos+1] = V[u][i];
            call(pos+1);
            flag[V[u][i]] = false;
        }
    }
}

bool bfs(){
    queue<int >Q;
    Q.push(1);
    flag[1] = true;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        if(u==n) return true;
        int len = V[u].size();
        rep(i,len){
            if(!flag[V[u][i]]){
                Q.push(V[u][i]);
                flag[V[u][i]] = true;
            }
        }
    }
    return false;
}

int main(){
    int cs = 1;
    while(cin >> n){
        rep(i,21) V[i].clear();
        int u,v;
        while(true){
            u = II;
            v = II;
            if(u==0 && v==0) break;
            V[u].pb(v);
            V[v].pb(u);
        }
        cnt = 0;
        memo(flag,false);
        if(bfs()){
            memo(flag,false);
            flag[1] = true;
            arr[0] = 1;
            For(i,n) sort(all(V[i]));
            call(0);
        }
        OC;
        NL;
        printf("There are %d routes from the firestation to streetcorner %d.\n",cnt,n);
        cs++;
    }
}
