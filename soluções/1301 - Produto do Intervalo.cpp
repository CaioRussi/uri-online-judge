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
 
int tree[100001],treez[100001],val[100001],n;
 
int read(int idx){
    int sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
 
void update(int idx ,int val){
    while (idx <= n){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
 
int readz(int idx){
    int sum = 0;
    while (idx > 0){
        sum += treez[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
 
void updatez(int idx ,int val){
    while (idx <= n){
        treez[idx] += val;
        idx += (idx & -idx);
    }
}
 
int main()
{
    //freopen("entrada.in", "r", stdin);
    //freopen("saida.txt", "w", stdout);
    int k,a,b,aux,zero,neg,t;
    char c;
    while(scanf("%d%d",&n,&k)!=EOF){
       for(int i = 1; i <= n; i++){
          tree[i] = 0;
          treez[i] = 0;
       }
       for(int i = 1; i <= n; i++){
          scanf("%d",&a);
          if(a<0) update(i,1);
          if(a==0) updatez(i,1);
          val[i] = a;
       }
       while(k--){
          scanf(" %c%d%d",&c,&a,&b);
          if(c == 'P'){
             neg = read(b) - read(a-1);
             zero = readz(b) - readz(a-1);
             if(zero) printf("0");
             else printf("%c",neg%2?'-':'+');
          }
          else{
             if(val[a] == 0 and b != 0)
                updatez(a,-(readz(a)-readz(a-1)));
             if(b == 0)
                updatez(a,1);
             val[a] = b;
             if(b>=0)
                update(a,-(read(a)-read(a-1)));
             else
                update(a,-(read(a)-read(a-1))+1);
          }
       }
       puts("");
    }
    //system("PAUSE");
    return 0;
}