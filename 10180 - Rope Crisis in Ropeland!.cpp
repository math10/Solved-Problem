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

    bool operator ==(const point &p)const
    {
        return ((x==p.x) && (y==p.y));
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

double cross(point a,point b)
{
    return a.x*b.y-a.y*b.x;
}
double dot(point a,point b)
{
    return a.x*b.x+a.y*b.y;
}
// মূলবিন্দু (0,0)  থেকে r দুরত্তে  নতুন একটি বিন্দু তৈরী করে যা (০,০) এবং a বিন্দুর সাথে co-linear
point trunc(point a,double r)
{
    double l = hypot(a.x,a.y);
    if ( !EQ(l) )return a;
    r /= l ;
    return point(a.x*r,a.y*r);
}
point rotate(point a,point p,double angle) // p er sapekkhe a ke clock wise rotate kore
{
    point v(a.x - p.x , a.y-p.y );
    double c = cos(angle) , s = sin(angle);
    return point(p.x + v.x*c - v.y*s , p.y + v.x*s + v.y*c );
}
bool in_box(point a,point b,point c)  // rectangle : a = leftDown , b = rightTop , c ab rectangle er vitore ase kina
{
    double lox = min(a.x, b.x), hix = max(a.x, b.x);
    double loy = min(a.y, b.y), hiy = max(a.y, b.y);
    return c.x >= lox && c.x <= hix && c.y >= loy && c.y <= hiy; // remove = (eq) if strictly in box need
}
bool collinear(point p1,point p2,point p3) // p1 ,p2,p3 ekoi sorolrekhay ase kina || p1p2 line er upor p3 ase kina
{
    return (p1.y - p3.y) * (p2.x - p3.x) == (p2.y - p3.y) * (p1.x - p3.x);
}
#define sqr(x) ((x)*(x))
double sqrdis(point a,point b)
{
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}
double dis(point a,point b)
{
    return sqrt(sqrdis(a,b));
}
void translate(point a,double tx, double ty)
{
    a.x += tx;
    a.y += ty;
}
void translate(point a,point t)
{
    a.x += t.x;
    a.y += t.y;
}

const double pi = 2*acos(0.0);


int turn( point O , point A , point B)   //
{
    double res = (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
    if( res < 0 ) return -1 ; // O->A->B is a right turn
    if( res > 0 ) return  1 ; // O->A->B is a left turn
    return 0; // O->A->B is a straight line / co-linear
}

// find angle of <ABC
// angle find in degree for radiant use x*180/PI
double find_angle(point A, point B, point C)
{
    double x = dis(B,C);
    double y = dis(C,A);
    double z = dis(A,B);
    return acos((z*z + x*x - y*y)/(2*z*x));
}

struct line
{
    point a , b ;
    line(point _a , point _b )
    {
        a = _a , b = _b ;
    }
    line() {}
    // ** ভুমির সাথে  থিটা কোণে  নতুন রেখা উৎপন্ন  করে এবং থিটা রেডিয়ান  এ হতে হবে .
    line(point p,double theta)
    {
        a = p;
        if ( EQ( theta - pi/2.00 ) == 0 ) b = a + point(0,1);
        else b= a + point( 1 , tan( theta ) );
    }
    //ax+by+c=0 ,a,b,c দেয়া আছে তার জন্য রেখার দুইটা বিন্দু তৈরি করে
    line(double _a,double _b,double _c)
    {
        if ( EQ( _a ) == 0)
        {
            a = point(0,-_c/_b);
            b = point(1,-_c/_b);
        }
        else if (EQ(_b)==0)
        {
            a = point(-_c/_a,0);
            b = point(-_c/_a,1);
        }
        else
        {
            a = point(0,-_c/_b);
            b = point(1,(-_c-_a)/_b);
        }
    }
    void input()
    {
        a.input() ;
        b.input();
    }
};
// dont know the usage :p
point lineprog(line l,point p)
{
    double d = (l.b - l.a).x * (l.b - l.a).x + (l.b - l.a).y * (l.b - l.a).y ;
    return l.a + ((l.b-l.a)*(dot((l.b-l.a),(p-l.a))/d) );
}
//প্রতিবিম্ব বিন্দু /  Shadow point
point symmetrypoint(line l,point p)
{
    point q = lineprog(l,p);
    return point(2 * q.x - p.x , 2 * q.y - p.y );
}
// p বিন্দুটা  l segment এর উপর আছে কিনা
bool pointonseg(line l,point p)
{
    return EQ(cross((p - l.a),l.b - l.a))==0&&EQ(dot((p - l.a),p - l.b))<=0;
}
// একটি বিন্দু থেকে লাইন এর লম্বদূরত্ব
double dispointtoline(line l,point p)
{
    return fabs(cross((p-l.a),(l.b-l.a)))/dis(l.a,l.b);
}
//ভুমির সাথে কত ডিগ্রী কোনে রেখাটি  অবস্থিত
// return করতেছে রেডিয়ানে  //   angle 0 <= angle < pi
double angle(line l)
{
    double k = atan2(l.b.y-l.a.y,l.b.x-l.a.x);
    if (EQ(k) < 0)k += pi;
    if (EQ(k-pi) == 0)k -= pi;
    return k;
}
// project point c onto line through a and b
// assuming a != b
point ProjectPointLine(point a, point b, point c)
{
    return a + (b-a)*dot((c-a),b-a) / dot((b-a),b-a);
}


// project point c onto line segment through a and b
point ProjectPointSegment(point a, point b, point c)
{
    double r = dot((b-a),b-a);
    if (fabs(r) < EPS) return a;
    r = dot((c-a),b-a)/r;
    if (r < 0) return a;
    if (r > 1) return b;
    return a + (b-a)*r;
}

// compute distance from c to segment between a and b
double DistancePointSegment(point a, point b, point c)
{
    return dis(c,ProjectPointSegment(a, b, c) ); // global
}
// determine if lines from a to b and c to d are parallel or collinear
bool LinesParallel(point a, point b, point c, point d)
{
    return fabs( cross((b-a),c-d)) < EPS;
}

bool LinesCollinear(point a, point b, point c, point d)
{
    return LinesParallel(a, b, c, d) // global
           && fabs( cross((a-b), a-c) ) < EPS
           && fabs( cross((c-d),c-a) ) < EPS;
}
// compute intersection of line passing through a and b
// with line passing through c and d, assuming that unique
// intersection exists; for segment intersection, check if segments intersect first
// **use LinesParallel and LinesColliner to detect wether they intersect
bool ComputeLineIntersection(point a, point b, point c, point d,point &p)
{
    if(LinesCollinear(a,b,c,d) || LinesParallel(a,b,c,d)) return false;
    b = b - a ;
    d = c - d ;
    c = c - a ;
    //assert( dot(b,b) > EPS && dot(d,d) > EPS);
    p = a + b* cross(c,d) / cross(b,d) ;
    return true;
}


// compute center of circle given three points
point ComputeCircleCenter(point a, point b, point c)
{
    b=(a+b)/2;
    c=(a+c)/2;
    point p;
    ComputeLineIntersection(b, b+(a-b).rotright(), c, c+(a-c).rotright(),p); // global
    return p;
}

struct circle
{
    point p ;  //  বৃত্তের কেন্দ্র
    double r ; // বৃত্তের  ব্যাসার্ধ
    circle() {}
    circle(point _p, double _r)
    {
        p = _p , r = _r ;
    }
    circle(point a,point b,point c)
    {
        p = ComputeCircleCenter(a,b,c); // global
        r = dis(p,a); // point.h
    }
    bool operator ==(circle v)
    {
        return (( p == v.p ) && EQ( r - v.r ) == 0 );
    }
    bool operator <(circle v)const
    {
        return ((p < v.p )||(p == v.p) && EQ( r - v.r ) < 0 );
    }
    double area() //  বৃত্তের  ক্ষেত্রফল
    {
        return pi*r*r;
    }
    double circumference() //বৃত্তের  পরিধি
    {
        return 2*pi*r;
    }
    // 5 way off / are away from
    // 4 circumscribed /outer cutting
    // 3 intersect
    // 2-cut inside/inscribed
    // 1 contains / includes
    int relationcircle(circle v)
    {
        double d = dis(p,v.p); // point
        if ( EQ( d - r - v.r ) >  0 ) return 5;
        if ( EQ( d - r - v.r ) == 0 ) return 4;
        double l = fabs( r - v.r );
        if ( EQ( d - r - v.r ) < 0 && EQ( d - l ) > 0 ) return 3;
        if ( EQ( d - l ) == 0) return 2;
        if ( EQ( d - l ) <  0) return 1;
    }
    // 0    __ বৃত্তের বাইরে
    // 1 __ বৃত্তের  উপরে অবস্থিত
    // 2 __  বৃত্তের ভিতরে
    int relation(point b) // বৃত্ত  ও   একটি বিন্দুর সম্পর্ক
    {
        double dst = dis(b,p); // point
        if ( EQ( dst - r ) < 0 ) return 2;
        if ( EQ( dst - r ) == 0 ) return 1;
        return 0;
    }
    void input()
    {
        p.input();
        scanf("%lf",&r);
    }
};
//যদি  ABC ত্রিভুজ গঠন করতে পারে তাহলে ABC এর  বহিবৃত্ত উৎপন্ন করে এমন Circle তৈরী করে ।
circle Circum_circle(point a,point b,point c)
{
    point center = ComputeCircleCenter(a,b,c); // global
    double  radius = dis(center,a); // point.h
    return circle(center,radius); // circle
}
//যদি  ABC ত্রিভুজ গঠন করতে পারে তাহলে ABC এর  অন্তবৃত্ত  উৎপন্ন করে এমন Circle তৈরী করে ।
circle Inscribed_circle(point a,point b,point c)
{
    line u , v ;
    double m = atan2( b.y - a.y , b.x - a.x ) , n = atan2( c.y - a.y , c.x - a.x );
    u.a = a ;
    u.b = u.a + ( point( cos((n+m)/2) , sin((n+m)/2) ) ); // point
    v.a = b ;
    m = atan2( a.y - b.y , a.x - b.x ) , n = atan2( c.y - b.y , c.x - b.x );
    v.b = v.a + ( point( cos( (n+m)/2 ) , sin( (n+m)/2) ) ); // point
    point center;
    ComputeLineIntersection(u.a,u.b,v.a,v.b,center); // global
    double radius = DistancePointSegment(a,b,center); // global
    return circle(center,radius); // circle
}
// দুইটা circle নিজেদের ছেদ করলে তাদের ছেদ বিন্দু return করে
int pointcrosscircle(circle a, circle v , point &p1 , point &p2 )
{
    int rel = a.relationcircle(v); // own
    if (rel == 1 || rel == 5) return 0;
    double d = dis(a.p,v.p); // point
    double l = ( d + ( a.r*a.r - v.r * v.r )/d )/2.00;
    double h = sqrt( a.r*a.r- l*l );
    p1 = a.p +  ( trunc((v.p - a.p),l) ) + ( trunc((v.p - a.p).rotleft(),h) ) ; // point
    p2 = a.p +  ( trunc((v.p - a.p),l) ) + ( trunc((v.p - a.p).rotright(),h)) ; // point
    if (rel == 2 || rel == 4)
    {
        return 1;
    }
    return 2;
}
// compute intersection of line through points a and b with
// circle centered at c with radius r > 0
vector<point> CircleLineIntersection(point a, point b, point c, double r)
{
    vector<point> ret;
    b = b-a;
    a = a-c;
    double A = dot(b,b) , B = dot(a,b) , C = dot(a,a) - r*r;
    double D = B*B - A*C;
    if (D < -EPS) return ret;
    ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);
    if (D > EPS)
        ret.push_back(c+a+b*(-B-sqrt(D))/A);
    return ret;
}

// compute intersection of circle centered at a with radius r
// with circle centered at b with radius R
vector<point> CircleCircleIntersection(point a, point b, double r, double R)
{
    vector<point> ret;
    double d = dis(a,b);
    if (d > r+R || d+min(r, R) < max(r, R)) return ret;
    double x = (d*d-R*R+r*r)/(2*d);
    double y = sqrt(r*r-x*x);
    point v = (b-a)/d;
    ret.push_back(a+v*x + (v.rotleft())*y);
    if (y > 0)
        ret.push_back(a+v*x -(v.rotleft())*y);
    return ret;
}
// circle এর বাহিরের কোন বিন্দু q থেকে circle এর উপর স্পর্শক লাইন(u,v) return করে
int tangentline(circle c,point q , line &u , line &v )
{
    int x = c.relation(q); // own
    if (x == 2 ) return 0;
    if (x == 1 )
    {
        u = line( q , q + ( (q-c.p).rotleft() )  ); // point,line
        v = u;
        return 1;
    }
    double d = dis(c.p,q); // point
    double l = (c.r*c.r)/d;
    double h = sqrt( c.r*c.r - l*l );
    u = line( q , c.p +  ( trunc((q-c.p),l) ) + ( trunc((q-c.p).rotleft(),h) ) ); // point
    v = line( q , c.p +  ( trunc((q-c.p),l) ) + ( trunc((q-c.p).rotright(),h)) ); // point
    return 2 ;
}




int main()
{
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    cout << setprecision(3) << fixed;
    int n = II;

    rep(i,n)
    {
        point a,b;
        a.input(),b.input();
        circle c;
        c.p = point(0,0);
        cin >> c.r;
        vector<point >ret = CircleLineIntersection(a,b,c.p,c.r);
        db D = dis(a,b);

        if(ret.size() == 2 && pointonseg(line(a,b),ret[0]) && pointonseg(line(a,b),ret[1]) )
        {
            db t1 = dis(a,c.p);
            t1 = acos(c.r/t1);
            db t2 = dis(b,c.p);
            t2 = acos(c.r/t2);
            db t3 = find_angle(a,c.p,b);
            if(t3 < PI) t3 = 2*PI - t3;
            db ang = 2*PI - t1 - t2 - t3;
            db ans = ang*c.r + c.r*tan(t1) + c.r*tan(t2);
            cout << ans << endl;
        }
        else cout << dis(a,b) << endl;
    }

}
