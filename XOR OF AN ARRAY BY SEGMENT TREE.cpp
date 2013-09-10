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
#define Update 1
#define Query 2
//}
//}
template <class T, class U> inline T max (T &a, U &b) { return a > b ? a : b; }
template <class T, class U> inline T min (T &a, U &b) { return a < b ? a : b; }
template <class T, class U> inline T swap (T &a, U &b) { a ^= b ; b = a ^ b ; a ^= b; }
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

int arr[mx],A[mx<<2],lazy[mx<<2];

void propagate(int lf,int rt,int idx){
     int mid = (lf+rt)/2;
     lazy[2*idx] = lazy[idx];
     lazy[2*idx+1] = lazy[idx];
     if( (mid-lf+1)%2==0 )
            A[2*idx] = 0;
     else A[2*idx] = lazy[idx];

     if( (rt-mid)%2==0 )
            A[2*idx+1] = 0;
     else A[2*idx+1] = lazy[idx];

     lazy[idx]=0;
 }

void update(int lf,int rt,int idx,int x,int y,int val){
     if( lf>=x && rt<=y ){
           int cal = (rt-lf+1);

           if( cal%2==0 )
            A[idx] = 0;
           else
            A[idx] = val;

           lazy[idx]=val;

           return ;
       }
     if(lazy[idx]) propagate(lf,rt,idx);

     int mid = (lf+rt)/2;

     if( x<=mid )
            update( lf,mid,2*idx,x,y,val );
     if( y>mid )
            update( mid+1,rt,2*idx+1,x,y,val );

     A[idx] = A[2*idx]^A[2*idx+1];
 }

int query( int lf,int rt,int idx,int x,int y ){
     if( lf>=x && rt<=y ){
            return A[idx];
        }

     if(lazy[idx]) propagate( lf,rt,idx );

     int mid=(lf+rt)/2,ret=0;

     if( x<=mid )
            ret = ret^query( lf,mid,2*idx,x,y );

     if(y>mid)
            ret = ret^query( mid+1,rt,2*idx+1,x,y );

     return ret;
 }


void build(int lf,int rt,int idx){
     lazy[idx] = 0;
     if( lf==rt ){
          A[idx] = arr[lf];
          return ;
      }

     int mid = (lf+rt)/2;

     build( lf,mid,2*idx );
     build( mid+1,rt,2*idx+1 );

     A[idx] = A[2*idx]^A[2*idx+1];
 }

int main(){
     long n;

     cin >> n;

     rep(i,n)
      cin >> arr[i];

     build(0,n-1,1);

    int q;
    cin >> q;
    rep(i,q){
         int choice;
         cin >> choice;

         if( choice==Update ){
              int lf,rt,val;

              cin >> lf >> rt >>val;  // 0 based index

              update( 0,n-1,1,lf,rt,val );
          }

        else if( choice==Query ){
             int lf,rt;

             cin >> lf >> rt;

             cout << query( 0,n-1,1,lf,rt ) << endl;
         }
     }
    return 0;
 }
