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
template<class T>inline bool read(T &x) {
    int c=gc();
    int sgn=1;
    while(~c&&c<'0'|c>'9') {
        if(c=='-')sgn=-1;
        c=gc();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=gc())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}
#define II ({ int a; read(a); a;})
#define IL ({ int64 a; read(a);  a;})
#define ID ({ db a; scanf("%lf",&a);  a;})
#define IC ({ char a; scanf("%c",&a);  a;})
#define IS ({ string a; cin >> a;  a;})
#define OC printf("Case %d:",cs);
//}
//}
#define __(args...) {dbg,args; cerr<<endl;}
struct debugger {
    template<typename T> debugger& operator , (const T& v) {
        cerr<<v<<"    ";
        return *this;
    }
} dbg;
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
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

const int64 INF = (1ll)<<50;
const int mx = 3e5 + 7;
const int mod = 20071027 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}

int get(char ch) {
    return (ch-'a');
}


struct node {
    int val;
    node *next[30];
    node() {
        val=0;
        int i;
        for(i=0; i<30; i++)
            next[i]=NULL;
    }
};
node *root=new node();
int tot;
void insert(char *str) {
    node *curr=root;
    int i;
    for(i=0; str[i]; i++) {
        if(curr->next[get(str[i])]==NULL) {
            curr->next[get(str[i])]=new node();
        }
        curr=curr->next[get(str[i])];
    }
    curr->val++;
}

void traverse(node *p) {
    int i;
    for(i=0; i<30; i++) {
        if(p->next[i]!=NULL) {
            traverse(p->next[i]);
            delete p->next[i];
            p->next[i] = NULL;
        }
    }
}
char st[mx],s[110];
int dp[mx];
int vis[mx],c;

int call(int pos){
    //__(pos)
    if(st[pos] == 0) return 1;
    int &ret = dp[pos];
    if(vis[pos] == c) return ret;
    vis[pos] = c;
    ret = 0;
    node *curr=root;
    int i;
    for(i=pos; st[i]; i++) {
        if(curr->next[get(st[i])]==NULL) {
            break;
        }
        curr=curr->next[get(st[i])];
        if(curr->val) ret = (ret + call(i+1))%mod;
    }

    return ret;

}




int main() {
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    while(gets(st)) {
        int n = II;

        rep(i,n) {
            gets(s);
            insert(s);
        }
        c++;
        printf("Case %d: %d\n",c,call(0));
        traverse(root);
    }
}
