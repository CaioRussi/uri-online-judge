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
#define PI 2*acos (0.0)
#define rep(k, n) for(int (k) = 0; (k) < (int)(n); (k)++)
#define Rep(k, n) for(int (k) = 1; (k) <= (int)(n); (k)++) 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define rall(c) (c).rbegin(),(c).rend() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef vector<ii> vii; 
typedef map<string, int> si;
typedef map<int, string> is;

struct Edge
{
   int o,d,p;
};
 
bool comp(Edge a, Edge b)
{
     return a.p < b.p;
}
 
int n;
int pset[50001];
int resp[50001];
ii query[50001];
vector<vi> conj;
   
void initSet(int _size) 
{  
     for(int i = 0; i <= _size; i++) 
        pset[i] = i; 
}
int findSet(int i) 
{ 
    return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); 
}
 
bool isSameSet(int i, int j) 
{ 
     return findSet(i) == findSet(j); 
}
 
void join(int a, int b, int val)
{
     int i = findSet(a);
     int j = findSet(b);
     if(i!=j)
     {
        if(sz(conj[i]) < sz(conj[j]))
           swap(i,j);
        pset[j] = i;
        for(int k = 0; k < sz(conj[j]); k++)
        {
           if(resp[conj[j][k]]==-1)
              if(findSet(query[conj[j][k]].first)==findSet(query[conj[j][k]].second))
                 resp[conj[j][k]] = val;
           conj[i].pb(conj[j][k]);
        }
        conj[j].clear();
     }
}
 
vector<Edge> aresta;
 
void kruskal()
{
     for(vector<Edge>::iterator it = aresta.begin(); it != aresta.end(); it++)
         if (!isSameSet((*it).o, (*it).d)) 
            join((*it).o, (*it).d, (*it).p); 
}
 
int main() 
{
    int m,s,a,b,inst=1;
    Edge e;
    while(scanf("%d%d",&n,&m) and n or m)
    {
       aresta.clear();
       rep(i,m)
       {
          scanf("%d%d%d",&e.o,&e.d,&e.p);
          aresta.pb(e);
       }
       sort(all(aresta),comp);
       initSet(n);
       conj = vector<vi>(n+1,vi());
       scanf("%d",&s);
       rep(i,s)
       {
          scanf("%d%d",&a,&b);
          conj[a].pb(i);
          conj[b].pb(i);
          query[i].first = a;
          query[i].second = b;
          resp[i] = a==b?0:-1;
       }
       kruskal();
       printf("Instancia %d\n", inst++);
       rep(i,s)
          printf("%d\n", resp[i]);
       putchar('\n');
    }
    return 0;
}
