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
#define tr(c,i) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define present(c,x) ((c).find(x) != (c).end()) 
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

int n,m,mat[1001][1001];
int dp[1001][1001][6], ans;
char c;
bool primo[1001][1001];

int pd(int i, int j, int k)
{
    int &ret = dp[i][j][k];
    if(ret != 1)
       return ret;
    if(c=='N'){
       if(i-1 >= 0 and mat[i-1][j] < mat[i][j])
          ret = pd(i-1,j,k)+1;
       if(j+1 < m and mat[i][j+1] < mat[i][j])
          ret = max(ret, pd(i,j+1,k)+1);
    }
    else{
       if(i+1 < n and mat[i+1][j] < mat[i][j])
          ret = pd(i+1,j,k)+1;
       if(j-1 >= 0 and mat[i][j-1] < mat[i][j])
          ret = max(ret, pd(i,j-1,k)+1);
    }
    
    if(primo[i][j] and k)
       if(c=='N'){
          if(i-1 >= 0)
             ret = max(ret, pd(i-1,j,k-1)+1);
          if(j+1 < m)
             ret = max(ret, pd(i,j+1,k-1)+1);
       }
       else{
          if(i+1 < n)
             ret = max(ret, pd(i+1,j,k-1)+1);
          if(j-1 >= 0)
             ret = max(ret, pd(i,j-1,k-1)+1);
       }
    return ret;
}

bool ehPrimo(int num) 
{
    if(num==2) 
       return true;
    if(num<=1 || num%2 == 0) 
       return false;
    for(int i=3; i*i <= num; i+=2)
       if(num%i == 0)
          return false;
    return true;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int k;
    while(scanf("%d%d%d",&n,&m,&k) and n){
       getchar();scanf("%c",&c);
       for(int i = 0; i < n; i++)
          for(int j = 0; j < m; j++){
             scanf("%d",&mat[i][j]);
             primo[i][j] = ehPrimo(mat[i][j]);
             for(int z = 0; z <= k; z++)
                dp[i][j][z] = 1;
          }
       ans = 0;
       for(int i = 0; i < n; i++)
          for(int j = 0; j < m; j++)
             ans = max(ans, pd(i,j,k));
       printf("%d\n", ans);
    }
    //system("PAUSE");
    return 0;
}
