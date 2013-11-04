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

set<point>p;
int main(){
    int t = II;
    while(t--){
        int n = II;
        rep(i,n) {
            point tmp;
            tmp.input();
            p.insert(tmp);
        }
        point ans(0,0);
        forstl(it,p){
            ans.x += it->x;
            ans.y += it->y;
        }
        ans.x /= n;
        ans.y /= n;
        bool flag = true;
        forstl(it,p){
            point tmp = point(2*ans.x - it->x,2*ans.y - it->y);
            if(p.find(tmp) == p.end()) {
                flag = false;
                cout << "no" << endl;
                break;
            }
        }
        if(flag) cout << "yes" << endl;
        p.clear();
    }
}
