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
#define infll 0x3FFFFFFFFFFFFFFFLL
#define np next_permutation
#define pp prev_permutation
#define mp make_pair
#define abs(x) (((x) < 0) ? - (x) : (x))
#define pi 3.1415926535897932384626433832795
#define sz(a) int((a).size()) 
#define fr first
#define sc second
#define pb push_back 
#define fors(i, s) for(int i = 0; i < sz(s); i++)
#define all(c) (c).begin(),(c).end() 
#define rall(c) (c).rbegin(),(c).rend() 
#define tr(c,i) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define present(c,x) ((c).find(x) != (c).end()) 
using namespace std;
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonanivel Direction
typedef vector<string> vs;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
typedef pair<ii,int> iii; 
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef map<string, int> si;
typedef map<int, string> is;
 
int tree[1001][1001],n,m,p;
 
void update(int x, int y, int v){
   for(int i=x; i <= n; i += (i&-i)) 
      for(int j=y; j <= m; j += (j&-j))
         tree[i][j] += v; 
}
 
int sum(int x, int y){                   
   int sum = 0; 
   for(int i=x; i; i -= (i&-i))
      for(int j=y; j; j -= (j&-j))
         sum += tree[i][j];
   return sum; 
}
 
int read(int x1, int y1, int x2, int y2){            
   return sum(x2, y2) - sum(x2, y1-1) - sum(x1-1, y2) + sum(x1-1, y1-1); 
}
 
int main()
{
    //freopen("entrada.in", "r", stdin);
    //freopen("saida.txt", "w", stdout);
    int q,sch,x1,x2,y1,y2;
    char c;
    while(scanf("%d%d%d",&n,&m,&p) and n or m or p){
       memset(tree,0,sizeof tree);
       scanf("%d",&q);
       while(q--){
          scanf(" %c",&c);
          if(c == 'A'){
             scanf("%d%d%d",&sch,&x1,&y1);
             update(x1+1,y1+1,sch);
          }
          else{
             scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
             if(x1 > x2)
                swap(x1,x2);
             if(y1 > y2)
                swap(y1,y2);
             printf("%d\n", read(x1+1,y1+1,x2+1,y2+1)*p);    
          }
       }
       puts("");
    }
    //system("PAUSE");
    return 0;
}