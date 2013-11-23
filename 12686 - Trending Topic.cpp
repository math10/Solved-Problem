#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define mp make_pair
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

//const int INF = 1 << 29 ;


char str[1000000];
map <string, int> m[10], total;
vector< pair<int ,string> >V;
bool comp( pair<int, string> a, pair<int, string> b)
{
    if( a.first == b.first ) return a.second > b.second;
    else return a.first < b.first;
}

int main(){
    #ifdef Sanim
        freopen ("in.txt", "r", stdin);
        freopen("output.txt","w",stdout);
    #endif
    string st;
    int day = 0;
    while(cin >> st){
        if(st == "<text>") {
            day = (day+1)%7;
            forstl(it,m[day]){
                total[(*it).first] -= (*it).second;
            }
            m[day].clear();
            while(cin >> st){
                if(st == "</text>") break;
                if(st.size() <= 3) continue;
                m[day][st]++;
                total[st]++;
            }
        }
        else if(st == "<top" ){
            V.clear();
            int num = II,len,cnt;
            cin >> st;
            forstl(it,total){
                if((*it).second == 0)continue;
                V.pb(mp((*it).second,(*it).first));
            }
            sort(all(V),comp);
            len = V.size(),cnt = 1;
            printf("<top %d>\n",num);
            if(len) cout << V[len-1].second << " " << V[len-1].first << endl;
            rofba(i,0,len-2){
                if(V[i].first < V[i+1].first){
                    if(cnt >= num) break;
                }
                cnt++;
                cout << V[i].second << " " << V[i].first << endl;
            }
            printf("</top>\n");
        }
    }
}
