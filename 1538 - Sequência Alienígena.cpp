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

int main()
{
    int r,q,tl;
    char ans[20];
    long long n;
    while(scanf("%lld",&n) and n)
    {
       tl = 0;
       n *= n;
       while(n >= 4)
       {
          ans[tl++] = (n % 4) + 65;
          n /= 4;
       }
       ans[tl++] = n + 65;
       ans[tl] = '\0';
       reverse(ans,ans+tl);
       puts(ans);
    }
    return 0;
}
