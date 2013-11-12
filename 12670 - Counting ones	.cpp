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
#define EPS 1e-6
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2*acos (0.0)
#define pi 2*acos (0.0)
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

int EQ(double d)
{
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

//convert Integer to Binary
string i2b(int64u a) {
    string s ;
    do { s += (a&1) + '0' ,  a >>= 1; }while(a);
    reverse(all(s));
    return s;
}

string st;

int64u dp[70][2][2],len;

int64u sum(int pos,bool isSmall){
    if(isSmall) return (1LLU<<(len - pos - 1));
    else{
        int64u num = 0,cnt= 0;
        rofba(i,pos+1,len-1){
            num += (st[i] - '0')*(1LLU<<cnt);
            cnt++;
        }
        return num+1LLU;
    }
}

int64u call(int pos,bool prev,bool isSmall){
    if(pos == len) return 0;
    int64u &ret = dp[pos][prev][isSmall];
    if( ret != -1) return ret;
    ret = 0;
    if(isSmall){
        ret = call(pos+1,1,isSmall) + call(pos+1,0,isSmall) + sum(pos,isSmall);
    }
    else{
        if(st[pos] == '0') ret = call(pos+1,0,false);
        else ret = call(pos+1,0,true) + call(pos+1,1,false) + sum(pos,false);
    }

    return ret;
}

int main(){
#ifdef Sanim
	freopen ("in.txt", "r", stdin);
	// freopen ("output.txt", "w", stdout);
#endif
    int64u a,b;
    while(cin >> a >> b){
        int64u ans = 0;
        if(a > 1){
            a--;
            st = i2b(a);
            len = st.size();
            memo(dp,-1);
            ans = call(0,0,0);
            //cout << ans << endl;
        }
        st = i2b(b);
        len = st.size();
        memo(dp,-1);
        ans = call(0,0,0) - ans;
        cout << ans << endl;
    }
}
