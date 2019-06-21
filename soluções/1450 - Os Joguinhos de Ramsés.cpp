#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
#include <bitset>
#define NP next_permutation
#define PP prev_permutation
#define mp make_pair
#define abs(x) (((x) < 0) ? - (x) : (x))
#define PI 2*acos (0.0)
#define rep(k, n) for(int (k) = 0; (k) < (int)(n); (k)++)
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef map<string, int> si;
typedef map<int, string> is;
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

int pd[15][3][32769],n;

struct Bloco
{
   int x,y,z;
   int pos;
};
Bloco b[15];

bool possivel(int atual, int bloco)
{
     int x,y,X,Y;
     if(b[atual].pos == 0){
        x = b[atual].y;
        y = b[atual].z;
     }
     else
     if(b[atual].pos == 1){
        x = b[atual].x;
        y = b[atual].z;
     }
     else
     {
        x = b[atual].x;
        y = b[atual].y;
     }
     if(b[bloco].pos == 0){
        X = b[bloco].y;
        Y = b[bloco].z;
     }
     else
     if(b[bloco].pos == 1){
        X = b[bloco].x;
        Y = b[bloco].z;
     }
     else
     {
        X = b[bloco].x;
        Y = b[bloco].y;
     }
     if((x >= X and y >= Y) or (x >= Y and y >= X))
        return true;
     return false;
}

int dp(int bloco, int pos, int mask)
{
    if(pd[bloco][pos][mask]!=-1)
       return pd[bloco][pos][mask];
    int alt = 0, a;
    rep(i,n)
       if(!(mask&(1<<i)))
          rep(j,3)
          {
             if(j==0) a = b[i].x;
             if(j==1) a = b[i].y;
             if(j==2) a = b[i].z;
             b[i].pos = j;
             if(possivel(bloco,i))
                alt = max(alt, dp(i,j,mask|(1<<i))+a);
          }
    return pd[bloco][pos][mask] = alt;
}

int main()
{
    int t,a,total;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d",&n);
       rep(i,n)
          scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].z);
       rep(i,n)
          rep(j,3)
             rep(k,32769)
                pd[i][j][k] = -1;
       total = 0;
       rep(i,n)
          rep(j,3){
             if(j==0) a = b[i].x;
             if(j==1) a = b[i].y;
             if(j==2) a = b[i].z;
             b[i].pos = j;
             total = max(total,dp(i,j,(1<<i))+a);
          }
       printf("%d\n", total);
    }
    return 0;
}

