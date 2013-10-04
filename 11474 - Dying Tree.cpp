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
//(x/a)^2 + (y/b)^2 = 1;
struct point {
#define Type double
    Type x,y;
    point() {
        x = y = 0;
    }
    point(Type x, Type y) : x(x), y(y) {}
    point (const point &p) {
        x = p.x, y = p.y;
    }
    void translate(Type tx, Type ty) {
        x += tx;
        y += ty;
    }
    point translate(point t) {
        x += t.x;
        y += t.y;
    }
    point operator+(const point  &k)const {
        return point(x + k.x , y + k.y );
    }
    point operator-(const point  &k)const {
        return point(x - k.x , y - k.y );
    }
    point operator*(const double k) {
        return point(k * x , k * y );
    }

    point rotate(point p,double angle) {
        point v(x - p.x , y-p.y );
        double c = cos(angle) , s = sin(angle);
        return point(p.x + v.x*c - v.y*s , p.y + v.x*s + v.y*c );
    }
#define sqr(x) ((x)*(x))
    Type sqrdis(const point &b)const {
        return sqr(x - b.x) + sqr(y - b.y);
    }
    double dis(const point &b)const {
        return sqrt(sqrdis(b));
    }
    bool operator ==(const point &p)const {
        return ((x==p.x) && (y==p.y));
    }
    bool collinear(const point &p1, const point &p2)const  {
        return (p1.y - y) * (p2.x - x) == (p2.y - y) * (p1.x - x);
    }

    inline double cross(const point &i)const {
        return x*i.y-y*i.x;
    }
    inline double dot(const point &i)const {
        return x*i.x+y*i.y;
    }

    bool operator <(const point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    } // sorting angle by x axis
    /*
    bool operator <(const point &p) const {
                 return y < p.y || (y == p.y && x < p.x);
    } // sorting angle by y axis
    */
    friend istream& operator>>(istream& inp, point& p) {
        inp >> p.x >> p.y;
        return inp;
    }
    friend ostream& operator<<(ostream& out, const point& p) {
        return out << '(' << p.x << ',' << p.y << ')' << endl;
    }
};
vector<point >Doctor,tree[110];
int graph[120][120],n,m,k,d;
bool flag[120];
void dfs(int a){
    flag[a] = true;
    rep(i,n+m) if(a != i && graph[a][i] == 1 && !flag[i]) dfs(i);
}

int main(){
    int t = II;
    while(t--){
        n = II,m =II,k =II,d = II;
        k *= k, d *= d;
        rep(i,m){
            point tmp;
            cin >> tmp;
            Doctor.pb(tmp);
        }
        rep(i,n){
            int b = II;
            rep(j,b){
                point tmp;
                cin >> tmp;
                tree[i].pb(tmp);
            }
        }
        memo(graph,0); memo(flag,false);
        rep(i,n)rep(j,n){
            if(i!=j){
                forstl(it,tree[i])forstl(iit,tree[j]) if((*it).sqrdis(*iit) <= k) {
                    graph[i][j] = 1;
                    graph[j][i] = 1;
                    break;
                }
            }
        }
        rep(i,m)rep(j,n){
            forstl(it,tree[j]) if((*it).sqrdis(Doctor[i]) <= d){
                graph[n+i][j] = 1;
                graph[j][n+i] = 1;
                break;
            }
        }
        dfs(0);
        bool f = false;
        rep(i,m) if(flag[n+i]) f = true;
        if(f) cout << "Tree can be saved :)\n";
        else cout << "Tree can't be saved :(\n";
        rep(i,n) tree[i].clear();
        Doctor.clear();
    }
}
