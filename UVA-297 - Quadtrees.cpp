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

const int64 INF = (1ll)<<50;
const int mx = 1e5 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
#define parent 0
#define black 1
#define white 2
int arr[33][33];

struct Qtree{
    bool leaf;
    Qtree *a[5];
    int value;
    Qtree(bool _leaf){
        leaf = _leaf;
        a[0] = NULL;
        a[1] = NULL;
        a[2] = NULL;
        a[3] = NULL;
        value = 0;
    }
};
int cnt = 0;
void make_tree(Qtree *node,string s){
    if(s[cnt] == 'p'){
        node->leaf = false;
        cnt++;
        node->a[0] = new Qtree(false);make_tree(node->a[0],s);
        node->a[1] = new Qtree(false);make_tree(node->a[1],s);
        node->a[2] = new Qtree(false);make_tree(node->a[2],s);
        node->a[3] = new Qtree(false);make_tree(node->a[3],s);
    }
    else{
        node->leaf = true;
        if(s[cnt] == 'f') node->value = black;
        else node->value = white;
        cnt++;
    }
}

void marge(Qtree *node,Qtree *t1,Qtree *t2){
    if(t1->leaf && t2->leaf){
        node->leaf = true;
        node->value = ((t1->value==black)||(t2->value==black));
    }
    else if(t1->leaf){
        if(t1->value == black){
            node->leaf = true;
            node->value = black;
            return;
        }
        node->leaf = false;
        node->a[0] = t2->a[0];
        node->a[1] = t2->a[1];
        node->a[2] = t2->a[2];
        node->a[3] = t2->a[3];
    }
    else if(t2->leaf){
        if(t2->value == black){
            node->leaf = true;
            node->value = black;
            return;
        }
        node->leaf = false;
        node->a[0] = t1->a[0];
        node->a[1] = t1->a[1];
        node->a[2] = t1->a[2];
        node->a[3] = t1->a[3];
    }
    else{
        node->leaf = false;
        node->a[0] = new Qtree(false);
        node->a[1] = new Qtree(false);
        node->a[2] = new Qtree(false);
        node->a[3] = new Qtree(false);
        marge(node->a[0],t1->a[0],t2->a[0]);
        marge(node->a[1],t1->a[1],t2->a[1]);
        marge(node->a[2],t1->a[2],t2->a[2]);
        marge(node->a[3],t1->a[3],t2->a[3]);
    }
}

int cal(Qtree *node,int num){
    if(node->leaf){
        if(node->value == black) return num;
        return 0;
    }
    int ret = 0;
    ret += cal(node->a[0],num/4);
    ret += cal(node->a[1],num/4);
    ret += cal(node->a[2],num/4);
    ret += cal(node->a[3],num/4);
    return ret;
}

void cut(Qtree *node){
    if(node->leaf) return;
    if(node->a[0] != NULL){
        cut(node->a[0]);
        delete node->a[0];
        node->a[0] = NULL;
    }
    if(node->a[1] != NULL){
        cut(node->a[1]);
        delete node->a[1];
        node->a[1] = NULL;
    }
    if(node->a[2] != NULL){
        cut(node->a[2]);
        delete node->a[2];
        node->a[2] = NULL;
    }
    if(node->a[3] != NULL){
        cut(node->a[3]);
        delete node->a[3];
        node->a[3] = NULL;
    }
}

int main() {
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    int t = II;
    For(cs,t){
        memo(arr,0);
        string s;
        Qtree *t1,*t2,*t3;
        cin >> s;
        t1 = new Qtree(true);
        cnt = 0;
        make_tree(t1,s);
        cin >> s;
        t2 = new Qtree(true);
        cnt = 0;
        make_tree(t2,s);
        t3 = new Qtree(true);
        marge(t3,t1,t2);
        printf("There are %d black pixels.\n",cal(t3,1024));
        cut(t1);
        delete t1;
        t1 = NULL;
        cut(t2);
        delete t2;
        t2 = NULL;
        //cut(t3);
        //delete t3;
        //t3 = NULL;
    }
}


