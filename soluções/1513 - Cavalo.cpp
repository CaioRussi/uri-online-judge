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
int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
typedef pair<ii,int> iii; 
typedef vector<ii> vii;
typedef map<string, int> si;
typedef map<int, string> is;
 
int n,m,k,cav_x,cav_y;
int adj[20][20];
char tab[105][105];
int pd[20][(1<<16)+1];
 
bool possivel(int x, int y)
{
     return x >= 0 and x < n and y >= 0 and y < m and tab[x][y] != '#';
}
 
void bfs(int i, int j)
{
     int d,x,y,cont=k;
     ii v;
     bool vis[110][110];
     for(int u = 0; u < n; u++)
        for(int l = 0; l < m; l++)
           vis[u][l] = false;
     queue<iii> q;
     q.push(iii(ii(i,j),0));
     vis[i][j] = true;
     while(!q.empty()){
        v = q.front().first;
        d = q.front().second;
        q.pop();
        if(d!=0 and tab[v.first][v.second] != '.')
           adj[tab[i][j]-'A'][tab[v.first][v.second]-'A'] = d;
        for(int u = 0; u < 8; u++){
           x = dx[u]+v.first;
           y = dy[u]+v.second;
           if(possivel(x,y) and !vis[x][y]){
              q.push(iii(ii(x,y),d+1));
              vis[x][y] = true;
           }
        }
     }
}
 
int dp(int v, int bitmask){
   if(bitmask == (1<<(k+1))-1)
      return adj[v][0];//distancia de volta para o cavalo.
   if(pd[v][bitmask]!=-1)
      return pd[v][bitmask];
    
   int ans = INF;
   for(int i = 1; i <= k; i++)
      if(!(bitmask&(1<<i)))
         ans = min(ans, dp(i, bitmask|(1<<i)) + adj[v][i]);
   return pd[v][bitmask] = ans;
}
 
int main()
{
    int cont;
    while(scanf("%d%d%d",&n,&m,&k) and n){
       getchar();
       for(int i = 0; i < n; i++)
          gets(tab[i]);
       cont=1;
       for(int i = 0; i < n; i++)
          for(int j = 0; tab[i][j] != '\0'; j++)
             if(tab[i][j] == 'C')
                tab[i][j] = 'A';
             else
             if(tab[i][j] == 'P'){
                tab[i][j] = 'A'+cont;
                cont++;
             }         
       for(int i = 0; i <= k; i++)
          for(int j = 0; j <= k; j++)
             adj[i][j] = 0;
       for(int i = 0; i <= k; i++)
          memset(pd[i], -1, sizeof(pd[i]));
       //Calculando a distancia entre as peças.
       for(int i = 0; i < n; i++)
          for(int j = 0; j < m; j++)
             if(tab[i][j] != '#' and tab[i][j] != '.')
                bfs(i,j);
        
       printf("%d\n", dp(0,1));
    }
    return 0;
}
