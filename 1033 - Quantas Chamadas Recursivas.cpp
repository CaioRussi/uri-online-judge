#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <math.h>
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
#define INF 0x3f3f3f3f
#define NP next_permutation
#define PP prev_permutation
#define mp make_pair
#define abs(x) (((x) < 0) ? - (x) : (x))
#define PI 2*acos (0.0)
#define loop(k, n) for(int (k) = 0; (k) < (int)(n); (k)++) //for
#define sz(a) int((a).size()) //size
#define pb push_back //push_back
#define all(c) (c).begin(),(c).end() //vector
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) //for com iterator set,map,vector
#define present(c,x) ((c).find(x) != (c).end()) //find set,map
#define cpresent(c,x) (find(all(c),x) != (c).end()) //find vector
using namespace std;
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef map<string, int> si;
typedef map<int, string> is;
typedef unsigned long long int lli;
unsigned long long N, mod;
  
unsigned long long Fib(unsigned long long n)
{
   unsigned long long i = n - 1, a = 1, b = 0, c = 0, d = 1, t;
   if (n <= 0)
     return 0;
   while (i > 0){
     if (i % 2 == 1){
       t = (d*(b + a) + c*b)%mod;
       a = (d*b + c*a)%mod;
       b = t;
     }
     t = (d*(2*c + d))%mod;
     c = (c*c + d*d)%mod;
     d = t;
     i = i / 2;
   }
   return a + b;
 }
  
int main()
{
    int caso = 1;
    while(scanf("%llu %llu",&N,&mod) and N or mod)
    {
       if(N == 0)
          printf("Case %d: %llu %llu 1\n",caso++,N,mod);
       else
          printf("Case %d: %llu %llu %llu\n",caso++,N,mod,(Fib(N+1)*2-1)%mod);
    }
    return 0;
}
