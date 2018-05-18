#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>
#include <iostream>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
#include <bitset>
#define ll long long
#define ull unsigned long long
#define inf 0x3f3f3f3f
#define infl 0x3FFFFFFFFFFFFFFFLL
#define np next_permutation
#define pp prev_permutation
#define mp make_pair
#define abs(x) (((x) < 0) ? - (x) : (x))
#define pi 3.1415926535897932384626433832795
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof(c).begin() i = (c).begin(); i != (c).end(); i++) 
#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
using namespace std;
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
typedef vector<string> vs;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
typedef pair<ii,int> iii; 
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef map<string, int> si;
typedef map<int, string> is;

struct edge
{
   int a,b,c;
};
 
bool cmp(edge a, edge b)
{
    return a.c < b.c;
}

int p[100001],ran[100001],n,tl,tot,peso;
int tl1,tl2;
ii cons[100001];
vector<edge> Edge;
ll ans,ans2,resp[100001],par[100001],pairs[100001];
  
void make_set(int x)
{
     p[x] = x;
     ran[x] = 0;
}
   
int find(int x)
{
    if( x!= p[x] )
      p[x] = find(p[x]);
    return p[x];
}
   
void link(int x,int y)
{    
     bool entrou = false;
     if(par[x] > 1 and par[y] > 1){
        ans = ans - pairs[x] - pairs[y];
        tot = tot - par[x] - par[y];
        entrou = true;
     }
     if(ran[x] > ran[y])
     {
        p[y] = x;
        if(!entrou and par[x] > 1)
           tot -= par[x];
        par[x] += par[y];
        tot += par[x];
        if(!entrou)
           ans -= pairs[x];
        pairs[x] = par[x]*(par[x]+1)/2;
        ans += pairs[x];
     }
     else
     {
        p[x] = y;
        if(!entrou and par[y] > 1)
           tot -= par[y];
        par[y] += par[x];
        tot += par[y];
        if(!entrou)
           ans -= pairs[y];
        pairs[y] = par[y]*(par[y]+1)/2;
        ans += pairs[y];
        
        if(ran[x]==ran[y])
           ran[y]++;
     }
}
 
void une(int x,int y)
{
    link(find(x), find(y));
}

void solve(int lim)
{
    while(tl1 < sz(Edge) and Edge[tl1].c <= lim){
       une(Edge[tl1].a, Edge[tl1].b);
       tl1++;
    }
    if(tl1 < sz(Edge))
       peso = Edge[tl1].c;
    else
       peso = inf;
    ans2 = ans + n - tot;
}

int main()
{
    int t,caso=1,q,peso;
    edge e;
    scanf("%d",&t);
    while(t--){
       scanf("%d",&n);
       Edge.clear();
       for(int i = 1; i < n; i++){
          scanf("%d%d%d",&e.a,&e.b,&e.c);
          Edge.pb(e);
          make_set(i);
          par[i] = 1;
          pairs[i] = 0;
       }
       make_set(n);
       par[n] = 1;
       pairs[n] = 0;
       sort(all(Edge),cmp);
       scanf("%d",&q);
       for(int i = 0; i < q; i++){
          scanf("%d",&cons[i].first);
          cons[i].second = i;
       }
       sort(cons,cons+q);
       tl1=tl2=0;
       ans = tot = 0;
       solve(cons[0].first);
       if(sz(Edge))
          peso = Edge[0].c;
       else
          peso = inf;
       while(tl2 < q){
          while(tl2 < q and cons[tl2].first < peso){
             resp[cons[tl2].second] = ans2;
             tl2++;
          }
          if(tl2 < q){
             solve(cons[tl2].first);
             resp[cons[tl2].second] = ans2;
             tl2++;
          }
       }
       printf("Caso #%d:",caso++);
       for(int i = 0; i < q; i++)
          printf(" %lld", resp[i]);
       putchar('\n');
    }
    return 0;
}
