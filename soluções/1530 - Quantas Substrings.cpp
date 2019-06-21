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
#include <algorithm>
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

struct state
{
    int len, link;
    int next[27];
};
 
state st[1234567];
int tam, last, ind;
ll ret;
 
void init()
{
     tam = 1;
     last = 0;
     st[0].len = 0;
     st[0].link = -1;
     for(int i = 0; i < 27; i++) st[0].next[i]=0;
}
 
void sa_extend(int c)
{
     int cur = tam++;
     st[cur].len = st[last].len + 1;
     for(int i = 0; i < 27; i++) st[cur].next[i]=0;
     int p;
     for(p = last; p != -1 and !st[p].next[c]; p = st[p].link){
        st[p].next[c] = cur;
     }
     if(p == -1)
        st[cur].link = 0;
     else{
        int q = st[p].next[c];
        if(st[p].len + 1 == st[q].len)
           st[cur].link = q;
        else{
           int clone = tam++;
           st[clone].len = st[p].len + 1;
           for(int i = 0; i < 27; i++) st[clone].next[i] = st[q].next[i];
           st[clone].link = st[q].link;
           for(; p != -1 and st[p].next[c] == q; p = st[p].link)
              st[p].next[c] = clone;
           //
           ret -= st[q].len - st[st[q].link].len;
           //
           st[q].link = st[cur].link = clone;
           //
           ret += st[q].len - st[st[q].link].len;
           //
           ret += st[clone].len - st[st[clone].link].len;
        }
     }
     last = cur;
     ret += st[cur].len - st[st[cur].link].len;
}
 
int main(void)
{
    char str[200005];
    while(gets(str)!=NULL){
       init();
       ind = 1;
       ret = 0;
       for(int i = 0; str[i] != '\0'; i++)
          if(str[i] == '?')
             printf("%lld\n", ret);
          else
             sa_extend(str[i]-'a');
    }
    return 0;
}
