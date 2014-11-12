/*
Author :: MD. Musfiqur Rahman Sanim
Aust cse 28th Batch
ID:11.02.04.097
*/


//{ Template
using namespace std;
//{ headers
#include<bits/stdc++.h>
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
#define ff first
#define ss second
//{
//Intput_Output
#define gc getchar
template<class T>inline bool read(T &x){int c=gc();int sgn=1;while(~c&&c<'0'|c>'9'){if(c=='-')sgn=-1;c=gc();}for(x=0;~c&&'0'<=c&&c<='9';c=gc())x=x*10+c-'0';x*=sgn;return ~c;}
#define II ({ int a; read(a); a;})
#define IL ({ int64 a; read(a);  a;})
#define ID ({ db a; scanf("%lf",&a);  a;})
#define IC ({ char a; scanf("%c",&a);  a;})
#define IS ({ string a; cin >> a;  a;})
#define OC printf("Case %d:",cs);
//}
//}
#define __(args...) {dbg,args; cerr<<endl;}
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"    "; return *this; }}dbg;
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
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

const int64 INF = (1ll)<<50;
const int mx = 1e6 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}

inline double sqr(double x) {
    return x*x;
}

struct point {
    double x,y;
    point() {}
    point(double _x,double _y):
        x(_x),y(_y) {};
    void input() {
        scanf("%lf%lf",&x,&y);
    }
    void output() {
        printf("%.2f %.2f\n",x,y);
    }
    bool operator==(point a)const {
        return EQ(a.x-x)==0&&EQ(a.y-y)==0;
    }
    bool operator<(point a)const {
        return EQ(a.x-x)==0?EQ(y-a.y)<0:x<a.x;
    }
    double len() {
        return hypot(x,y);
    }
    double len2() {
        return x*x+y*y;
    }
    double distance(point p) {
        return hypot(x-p.x,y-p.y);
    }
    point add(point p) {
        return point(x+p.x,y+p.y);
    }
    point sub(point p) {
        return point(x-p.x,y-p.y);
    }
    point mul(double b) {
        return point(x*b,y*b);
    }
    point div(double b) {
        return point(x/b,y/b);
    }
    double dot(point p) {
        return x*p.x+y*p.y;
    }
    double cross(point p) {
        return x*p.y-y*p.x;
    }
    double rad(point a,point b) {
        point p=*this;
        return fabs(atan2(fabs(a.sub(p).cross(b.sub(p))),a.sub(p).dot(b.sub(p))));
    }
    point trunc(double r) { // মূলবিন্দু (0,0)  থেকে r দুরত্তে  নতুন একটি বিন্দু তৈরী করে যা (০,০) এবং বর্তমান বিন্দুর সাথে co-linear
        double l=len();
        if (!EQ(l))return *this;
        r/=l;
        return point(x*r,y*r);
    }
    point rotate(point p,double angle) { //rotate this point counter clockwise on the besis of point p
        point v=this->sub(p);
        double c=cos(angle),s=sin(angle);
        return point(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
    }
    point rotleft() {
        return point(-y,x);
    }
    point rotright() {
        return point(y,-x);
    }
    bool in_box(point a,point b) { // rectangle : a = leftDown , b = rightTop , c is in the rectangle or not
        point c = *this;
        double lox = min(a.x, b.x), hix = max(a.x, b.x);
        double loy = min(a.y, b.y), hiy = max(a.y, b.y);
        return c.x >= lox && c.x <= hix && c.y >= loy && c.y <= hiy; // remove = (eq) if strictly in box need
    }
};

struct triangle {
    double a,b,c;
    point p,q,r; // if point is availble means triangle make by three point
    triangle(point p,point q,point r): p(p),q(q),r(r) {
        a = q.distance(r);
        b= p.distance(r);
        c = p.distance(q);
    }
    triangle(double a,double b,double c) : a(a) ,b(b) ,c(c) {}

    double thetaA() {
        return acos((sqr(b) + sqr(c) - sqr(a)) / (2*b*c));
    }

    double thetaB() {
        return acos((sqr(a) + sqr(c) - sqr(b)) / (2*a*c));
    }

    double thetaC() {
        return acos((sqr(b) + sqr(a) - sqr(c)) / (2*a*b));
    }

    void thetaAll(double A[]) {
        A[0] = thetaA();
        A[1] = thetaB();
        A[2] = thetaC();
    }

    double area() {
        double s = (a+b+c)/2;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
    point center() {
        point P = point( (p.x + q.x + r.x) / 3.0 , (p.y + q.y + r.y) / 3.0 );
        return P;
    }
    void rotate(double angle) {
        point P = center();
        p = p.rotate(P,angle);
        q = q.rotate(P,angle);
        r = r.rotate(P,angle);
    }


#define TRI_NONE    0
#define TRI_ACUTE   1
#define TRI_RIGHT   2
#define TRI_OBTUSE  3
    int cross(const point &O, const point &A, const point &B) {
        return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
    }
    int findTriangleType() {
        point arr[] = {p,q,r};
        double res = cross(arr[0],arr[1],arr[2]);
        if(fabs(res) < EPS)  return TRI_RIGHT;
        else if(res < 0) return TRI_OBTUSE;

        res = cross(arr[1],arr[0],arr[2]);
        if(res < EPS) {
            swap(arr[0],arr[1]);
            if(fabs(res) < EPS)    return TRI_RIGHT;
            return TRI_OBTUSE;
        }

        res = cross(arr[2],arr[0],arr[1]);
        if(res < EPS) {
            swap(arr[0],arr[1]);
            if(fabs(res) < EPS)  return TRI_RIGHT;
            return TRI_OBTUSE;
        }
        return TRI_ACUTE;
    }

};

int turn( point O , point A , point B) { //
    double res = (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
    if( res < 0 ) return -1 ; // O->A->B is a right turn
    if( res > 0 ) return  1 ; // O->A->B is a left turn
    return 0; // O->A->B is a straight line / co-linear
}

double getY(double x,point a,point b){
    double tmp = (x - a.x)/(a.x - b.x);
    tmp *= (a.y - b.y);
    tmp += a.y;
    return tmp;
}

int main() {
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    cout << setprecision(8) << fixed;
    int t = II;

    For(cs,t){
        double a = ID,b = ID,c = ID;
        point p1 = point(0,0);
        point p2 = point(c,0);
        triangle tri = triangle(a,b,c);
        double theta = tri.thetaA();
        point p3 = point(b,0);
        p3 = p3.rotate(p1,theta);
        double low = 0,high = p3.y;
        double theta2 = pi/2. - tri.thetaB();
        while(fabs(low-high) > EPS){
            double mid = (low+high)/2.;
            double tmp = getY(mid,p1,p3);
            tmp = a*tmp/c;
            point p = point(mid+tmp,0).rotate(point(mid,0),theta2);
            if(turn(p2,p,p3) >= 0) high = mid;
            else low = mid;
        }
        cout << (c-low) << endl;

    }
}
