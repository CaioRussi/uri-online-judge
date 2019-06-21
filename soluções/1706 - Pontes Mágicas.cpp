#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <string.h>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
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
#define tr(c,i) for(typeof(c).begin() i = (c).begin(); i != (c).end(); i++) 
#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
using namespace std;
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
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

int n,m,cont,a,b;
vi adj[1001];
char notas[2005], nota[1001];
bool vis[1001];

void dfs(int v)
{
    if(nota[v-1] == 'B')
       cont--;
    vis[v]=true;
    for(int i = 0; i < sz(adj[v]); i++){
       if(!vis[adj[v][i]])
          dfs(adj[v][i]);
    }       
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
       getchar();
       gets(notas);
       cont = 0;
       for(int i = 0; i < n; i++){
          nota[i] = notas[2*i];
          if(nota[i] == 'B')
             cont++;
          adj[i+1].clear();
          vis[i+1] = false;
       }
       for(int i = 0; i < m; i++){
          scanf("%d%d",&a,&b);
          adj[a].pb(b);
          adj[b].pb(a);
       }
       if(cont==0){
          puts("Y");
          continue;
       }
       if(cont%2==0){
          dfs(1);
          printf("%c\n",cont?'N':'Y');
       }
       else
          puts("N");
    }
    return 0;
}
