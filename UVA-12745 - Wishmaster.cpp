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
#include <list>
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

const int64 INF = (1ll)<<50;
const int mx = 1e5 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}

#define MAX 200007
vector<int> g[MAX],gt[MAX];
list<int> L;
bool vi[MAX];
int num[MAX];
int giveNode(int x,char ch){
	x <<=1;
	if(ch=='-') return x+1;
	return x;
}
void dfs1(int x){
	vi[x] = 1;
	int i,sz = g[x].size(),y;
	for(i = 0;i<sz;i++){
		y = g[x][i];
		if(!vi[y])	dfs1(y);
	}
	L.push_front(x);
}
void dfs2(int x,int cnt){
	num[x] = cnt;
	int i,sz = gt[x].size(),y;
	for(i = 0;i<sz;i++){
		y = gt[x][i];
		if(num[y]==-1) dfs2(y,cnt);
	}
}
int main(){
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
	list<int>::iterator it;
	vector<int> v;
	int i,x,y,n,m,t,cs = 1;
	char ch1,ch2;

	t = II;
	For(cs,t){
		n = II,m = II;
		for(i = 0;i<2*n;i++)
			g[i].clear(),gt[i].clear(),num[i] = -1,vi[i] = 0;

		for(i = 0;i<m;i++){
			x = II,y = II;
			if(x>=0) ch1 = '+';
			else {x = abs(x);ch1 = '-';}
			if(y>=0) ch2 = '+';
			else {y = abs(y);ch2 = '-';}
			x = giveNode(x-1,ch1);
			y = giveNode(y-1,ch2);
			g[x^1].pb(y);
			g[y^1].pb(x);

			gt[y].pb(x^1);
			gt[x].pb(y^1);
		}
		L.clear();
		for(i = 0;i<2*n;i++){
			if(!vi[i]) dfs1(i);
		}
		int cnt = 0;
		for(it=L.begin();it!=L.end();it++){
			if(num[*it]==-1)
				dfs2(*it,cnt++);
		}
		v.clear();
		OC;
		for(i = 0;i<2*n;i+=2){
			if(num[i]==num[i^1]){
				break;
			}
		}
		if(i<2*n){
			puts(" No");
		}
		else
		printf(" Yes\n");
		//for(i = 0;i<v.size();i++) printf(" %d",v[i]+1);
		//puts("");
	}
	return 0;
}
