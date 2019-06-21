#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <string.h>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <vector>
//#include <algorithm>
#include <bitset>
#include <list>
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define INFL 0x3FFFFFFFFFFFFFFFLL
#define NP next_permutation
#define PP prev_permutation
#define mp make_pair
#define abs(x) (((x) < 0) ? - (x) : (x))
#define pi 3.1415926535897932384626433832795
#define rep(k, n) for(int (k) = 0; (k) < (int)(n); (k)++)
#define Rep(k, n) for(int (k) = 1; (k) <= (int)(n); (k)++) 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
using namespace std;
int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef vector<ii> vii; 
typedef map<string, int> si;
typedef map<int, string> is;
typedef map<string,string> ss;

typedef pair<ll, int> lli;

ll max(ll a, ll b)
{
   return a < b ? b : a;
}

int main()
{
    int n,pos;
    stack<lli> p;
    lli topo;
    ll h,ans;
    while(scanf("%d",&n) and n){
       p = stack<lli>();
       ans = topo.first = topo.second = 0;
       for(int i = 0; i < n; i++){
          scanf("%lld",&h);
          if(h==0){
             while(!p.empty()){
                topo = p.top();
                ans = max(ans, (i-topo.second) * topo.first);
                p.pop();
             }
             continue;
          }
          if(!p.empty())
             topo = p.top();
          if(h > topo.first)
             p.push(lli(h,i));
          else{
             while(!p.empty()){
                topo = p.top();
                if(h >= topo.first)
                    break;
                ans = max(ans, (i-topo.second) * topo.first);
                pos = topo.second;
                p.pop();
             }
             if(h != topo.first)
                p.push(lli(h,pos));
          }
       }
       while(!p.empty()){
          topo = p.top();
          ans = max(ans, (n-topo.second) * topo.first);
          p.pop();
       }
       printf("%lld\n", ans);
    }
    return 0;
}
