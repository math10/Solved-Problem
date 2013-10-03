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
const int SZ = 100010 ;
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

point a[SZ];
double minDist;
int N ;

bool cmp_x( point a , point b){
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cmp_y( point a , point b){
	return a.y < b.y;
}

void Update( point a , point b) {
	double dist = a.dis(b) ;
	if (dist < minDist) minDist = dist ;
}

void solve (int l, int r) {
	if(r - l <= 3 ){
        	forab(i,l,r) forab(j,i+1,r) Update( a[i] , a[j]);
		sort (a+l, a+r+1,cmp_y);
		return;
	}
	int m = (l + r) >> 1;
	double midX = a[m].x;
	solve (l, m),  solve (m+1, r);
	static point t[SZ];
	merge (a+l, a+m+1, a+m+1, a+r+1, t,cmp_y);
	copy (t, t+r-l+1, a+l);
	int tsz = 0;
	forab(i,l,r){
		if ( fabs ( a[i].x - midX ) < minDist) {
			for ( int j = tsz-1 ; j >= 0 && a[i].y - t[j].y < minDist ; j--) Update(a[i], t[j]);
			t[tsz++] = a[i];
		}
	}
}

void Closest_Pair(){
    sort(a,a+N,cmp_x);
    minDist = 1E20 ;
    solve(0,N-1);
}


int main(){
    while(cin >> N && N){
        rep(i,N) cin >> a[i];
        Closest_Pair();
        if(minDist>=10000) cout << "INFINITY" << endl;
        else printf("%.4lf\n",minDist);
    }
}
