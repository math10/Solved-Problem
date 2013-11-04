#include <bits/stdc++.h>
#define pb push_back
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-6
#define INF 10000000000
#define all(X) X.begin() , X.end()
using namespace std;
typedef long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b) for( __typeof(b) i = a ; i <= (b) ; i++ )
#define forba(i,b,a) for( __typeof(b) i = b ; i >= (a) ; i-- )

const double pi = 2*acos(0.0);


int EQ(double d)
{
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}

struct point
{
    double x,y;
    point()
    {
        x = y = 0;
    }
    point(double x, double y) : x(x), y(y) {}
    void input()
    {
        scanf("%lf %lf",&x,&y);
    }
    point (const point &p)
    {
        x = p.x, y = p.y;
    }
    void translate(double tx, double ty)
    {
        x += tx;
        y += ty;
    }
    point translate(point t)
    {
        x += t.x;
        y += t.y;
    }
    point operator+(point k)
    {
        return point(x + k.x , y + k.y );
    }
    point operator-(point k)
    {
        return point(x - k.x , y - k.y );
    }
    point operator*(double k)
    {
        return point(k * x , k * y );
    }
    point operator/(double k)
    {
        return point(x / k , y/k );
    }
    point rotleft()
    {
        return point(-y,x);
    }
    point rotright()
    {
        return point(y,-x);
    }
    point rotate(point p,double angle)
    {
        point v(x - p.x , y-p.y );
        double c = cos(angle) , s = sin(angle);
        return point(p.x + v.x*c - v.y*s , p.y + v.x*s + v.y*c );
    }
#define sqr(x) ((x)*(x))
    double sqrdis(const point &b)const
    {
        return sqr(x - b.x) + sqr(y - b.y);
    }
    double dis(const point &b)const
    {
        return sqrt(sqrdis(b));
    }
    bool operator ==(const point &p)const
    {
        return (fabs(x-p.x)<EPS && fabs(y-p.y)<EPS);
    }
    bool collinear(const point &p1, const point &p2)const
    {
        return (p1.y - y) * (p2.x - x) == (p2.y - y) * (p1.x - x);
    }
    double cross(const point &i)const
    {
        return x*i.y-y*i.x;
    }
    double dot(const point &i)const
    {
        return x*i.x+y*i.y;
    }
    // মূলবিন্দু (0,0)  থেকে r দুরত্তে  নতুন একটি বিন্দু তৈরী করে যা (০,০) এবং বর্তমান বিন্দুর সাথে co-linear
    point trunc(double r)
    {
        double l = hypot(x,y);
        if ( !EQ(l) )return *this;
        r /= l ;
        return point(x*r,y*r);
    }
    bool in_box(const point &a, const point &b) const   // rectangle : a = leftDown , b = rightTop
    {
        double lox = min(a.x, b.x), hix = max(a.x, b.x);
        double loy = min(a.y, b.y), hiy = max(a.y, b.y);
        return x >= lox && x <= hix && y >= loy && y <= hiy; // remove = (eq) if strictly in box need
    }

    bool operator <(const point &p) const
    {
        return x < p.x || (x == p.x && y < p.y);
    } // sorting angle by x axis
    /*
    bool operator <(const point &p) const {
                 return y < p.y || (y == p.y && x < p.x);
    } // sorting angle by y axis
    */
    friend ostream& operator<<(ostream& out, const point& p)
    {
        return out << '(' << p.x << ',' << p.y << ')' << endl;
    }
};

int turn( point O , point A , point B){
    double res = (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
    if( res < 0 ) return -1 ; // O->A->B is a right turn
    if( res > 0 ) return  1 ; // O->A->B is a left turn
    return 0; // O->A->B is a straight line / co-linear
}

inline bool onsegment(const point &p1, const point &p2, const point &p3) {
    point pmn, pmx;
    pmn.x = min(p1.x, p2.x), pmn.y = min(p1.y, p2.y);
    pmx.x = max(p1.x, p2.x), pmx.y = max(p1.y, p2.y);
    return pmn.x <= p3.x && p3.x <= pmx.x && pmn.y <= p3.y && p3.y <= pmx.y;
}

inline bool Intersect(const point &p1, const point &p2, const point &p3, const point &p4, bool &on) {
    ll d1, d2, d3, d4;
    d1 = turn(p3, p4, p1);
    d2 = turn(p3, p4, p2);
    d3 = turn(p1, p2, p3);
    d4 = turn(p1, p2, p4);
    on = false;
    if(((d1 < 0 && d2 > 0) || (d1 > 0 && d2 < 0)) && ((d3 < 0 && d4 > 0) || (d3 > 0 && d4 < 0))) return true;
    if( !d3 && onsegment(p1, p2, p3)) { on = true; return true; }
    if( !d4 && onsegment(p1, p2, p4)) return true;
    if( !d1 && onsegment(p3, p4, p1)) return true;
    if( !d2 && onsegment(p3, p4, p2)) return true;
    return false;
}

struct line{
    point a,b;
};
line l[110];
bool flag[110];
int main(){
    #ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    int t = II;
    while(t--){
        ms(flag,false);
        int n = II;
        rep(i,n){
            l[i].a.input(),l[i].b.input();
        }
        int cnt = 0;
        bool f;
        rep(i,n) forab(j,i+1,n-1){
            if(Intersect(l[i].a,l[i].b,l[j].a,l[j].b,f)) {
                flag[i] = flag[j] = true;
            }
        }
        rep(i,n) if(!flag[i]) cnt++;
        cout << cnt << endl;
    }
}
