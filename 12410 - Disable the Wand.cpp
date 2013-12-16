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

const int INF = 1e9 + 7LL;
const int mx = 1e6 + 7;
const int mod = 1e6;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}

string itob(int64 num){
    string st = "";
    while(num){
        st += '0' + (num%2);
        num/=2;
    }
    int64 dif = 32 - st.size();
    rep(i,dif) st += '0';
    reverse(all(st));
    return st;
}
int64 dp[35][35][35][2][21];
int64 sum[35][35][35][2][21];
int64 start, end, Maxone, Ideal_Number, k;
string idl,m;
int64 call(int64 pos,int64 mis_match,int64 noOne,bool isSmal,int64 mod){
    if(pos == 32) return (mis_match<=k && noOne<=Maxone && mod%3==0 && mod%7!=0);
    int64 &ret = dp[pos][mis_match][noOne][isSmal][mod];
    int64 &s = sum[pos][mis_match][noOne][isSmal][mod];
    if(ret != -1) return ret;
    ret = 0;
    if(isSmal){
        int64 tmp = mod * 2 + 1 ;
        tmp %= 21;
        ret = call(pos+1,mis_match+('1'!=idl[pos]),noOne+1,true,tmp) + call(pos+1,mis_match+('0'!=idl[pos]),noOne,true,(mod*2)%21);
        s += call(pos+1,mis_match+('1'!=idl[pos]),noOne+1,true,tmp)*(1ll<<(32-pos-1)) + sum[pos+1][mis_match+('1'!=idl[pos])][noOne+1][true][tmp]+sum[pos+1][mis_match+('0'!=idl[pos])][noOne][true][(mod*2)%21];
    }
    else{
        if(m[pos] == '0'){
            ret = call(pos+1,mis_match+('0'!=idl[pos]),noOne,isSmal,(mod*2)%21);
            s += sum[pos+1][mis_match+('0'!=idl[pos])][noOne][isSmal][(mod*2)%21];
        }
        else{
            int64 tmp = mod * 2 + 1 ;
            tmp %= 21;
            ret = call(pos+1,mis_match+('1'!=idl[pos]),noOne+1,isSmal,tmp) + call(pos+1,mis_match+('0'!=idl[pos]),noOne,true,(mod*2)%21);
            s += call(pos+1,mis_match+('1'!=idl[pos]),noOne+1,isSmal,tmp)*(1ll<<(32-pos-1)) + sum[pos+1][mis_match+('1'!=idl[pos])][noOne+1][isSmal][tmp]+sum[pos+1][mis_match+('0'!=idl[pos])][noOne][true][(mod*2)%21];
        }
    }
    return ret;
}


int main() {
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif

    int t = II;
    For(cs,t) {
        start = II, end = II, Maxone = II, Ideal_Number = II, k = II;
        idl = itob(Ideal_Number);
        int64 ans = 0;
        if(start > 0){
            start--;
            m = itob(start);
            memo(dp,-1);memo(sum,0);
            call(0,0,0,0,0);
            ans = sum[0][0][0][0][0];
        }
        //cout << ans << endl;
        m = itob(end);
        memo(dp,-1);memo(sum,0);
        call(0,0,0,0,0);
        ans = sum[0][0][0][0][0] - ans;
        OC;
        cout << " " << ans << endl;
    }
}
