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
//}
//}
template <class T, class U> inline T max (T &a, U &b) {
    return a > b ? a : b;
}
template <class T, class U> inline T min (T &a, U &b) {
    return a < b ? a : b;
}
template <class T, class U> inline T swap (T &a, U &b) {
    T tmp = a;
    a = b;
    b = tmp;
}
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

struct Cube {
    string dice;
    Cube() {
        dice = "136425";
    }
    int show( int i ) {
        return dice[ i ] - '0';
    }
    void left() {
        char temp = dice[ 0 ];
        dice[ 0 ] = dice[ 3 ];
        dice[ 3 ] = dice[ 2 ];
        dice[ 2 ] = dice[ 1 ];
        dice[ 1 ] = temp;
    }
    void down() {
        char temp = dice[ 0 ];
        dice[ 0 ] = dice[ 5 ];
        dice[ 5 ] = dice[ 2 ];
        dice[ 2 ] = dice[ 4 ];
        dice[ 4 ] = temp;
    }
    void right() {
        char temp = dice[ 0 ];
        dice[ 0 ] = dice[ 1 ];
        dice[ 1 ] = dice[ 2 ];
        dice[ 2 ] = dice[ 3 ];
        dice[ 3 ] = temp;
    };
    void up(){
        char temp = dice[ 0 ];
        dice[ 0 ] = dice[ 4 ];
        dice[ 4 ] = dice[ 2 ];
        dice[ 2 ] = dice[ 5 ];
        dice[ 5 ] = temp;
    }
    void rL(){
        char tmp = dice[4];
        dice[4] = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[1];
        dice[1] = tmp;
    }
    void rR(){
        char tmp = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[3];
        dice[3] = tmp;
    }
};
map<pair<string , int > ,bool>m;
string T;
bool call(Cube c,int prev){
    if(c.dice == T) {
        //cout << c.dice << endl;
        return true;
    }
    if(m.find(make_pair(c.dice,prev)) != m.end()) return false;
    m[make_pair(c.dice,prev)] = true;
    Cube tmp = c;
    tmp.down();
    if(prev != 4 && call(tmp,1)) return true;

    tmp = c;
    tmp.left();
    if(prev != 3 && call(tmp,2)) return true;

    tmp = c;
    tmp.right();
    if(prev != 2 && call(tmp,3)) return true;

    tmp = c;
    tmp.up();
    if(prev != 1 && call(tmp,4)) return true;

    tmp = c;
    tmp.rL();
    if(prev != 6 && call(tmp,5)) return true;

    tmp = c;
    tmp.rR();
    if(prev != 5 && call(tmp,6)) return true;


    return false;
}

int main() {
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    string st;
    while(cin >> st){
        m.clear();
        Cube c = Cube();
        rep(i,6){
            c.dice[i] = st[c.dice[i]-'1'];
        }
        Cube tmp = Cube();
        forab(i,6,11) tmp.dice[i-6] = st[tmp.dice[i-6] - '1' + 6];
        T = tmp.dice;
        if(call(c,0)) cout << "TRUE" << endl;
        else cout << "FALSE" << endl;

    }
}
