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
#define mp make_pair
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
#define Insert 1
#define Delete 2
#define Change 3

char s1[101],s2[101];
int len1,len2;
int dp[101][101],s[101][101];
int ins, del, cnt;
void call(){
    memo(dp,0),memo(s,0);
    For(i,len1) dp[i][0] = i,s[i][0] = Delete;
    For(i,len2) dp[0][i] = i,s[0][i] = Insert;

    For(i,len1)For(j,len2){
        int m = min(dp[i - 1][j - 1] + (s1[i-1] != s2[j-1]), min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
        dp[i][j] = m;
		if (m == dp[i - 1][j] + 1) {
          s[i][j] = Delete;
        } else if (m == dp[i][j - 1] + 1) {
          s[i][j] = Insert;
        } else {
          s[i][j] = (s1[i-1] != s2[j-1]) ? Change : 0;
        }
    }

}

void print(int i, int j) {
  switch (s[i][j]) {
    case 0:
      print(i - 1, j - 1);
      break;
    case Change:
      print(i - 1, j - 1);
      printf("%d Replace %d,%c\n", ++cnt, i + ins - del, s2[j-1]);
      break;
    case Delete:
      print(i - 1, j);
      printf("%d Delete %d\n", ++cnt, i + ins - del);
      del++;
      break;
    case Insert:
      print(i, j - 1);
      printf("%d Insert %d,%c\n", ++cnt, j, s2[j-1]);
      ins++;
      break;
  }
}

int main(){
    bool f = false;
    while(gets(s1)){
        gets(s2);
        len1 = strlen(s1) , len2 = strlen(s2);
        call();
        if(f) NL;
        f = true;
        cout << dp[len1][len2] << endl;
        ins = del = cnt = 0;
        print(len1,len2);
    }
}
