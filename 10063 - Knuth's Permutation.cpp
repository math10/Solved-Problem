#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef vector<ll>vl;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

int N;
string Str;
bool flag[12];
void call(int pos,string st)
{
    if(pos == N)
    {
        cout << st << endl;
        return;
    }
    rep(i,(int)st.size()+1){
        string tmp = st;
        tmp.insert(tmp.begin()+i,Str[pos]);
        call(pos+1,tmp);
    }

}

int main()
{
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
#endif
    bool flag = false;
    while( cin >> Str )
    {
        if(flag) puts("");
        N = Str.size() ;
        string tmp;
        tmp += Str[0];
        call(1,tmp);
       flag = true;
    }
}
