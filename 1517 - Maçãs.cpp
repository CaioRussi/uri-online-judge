#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K, memo[2001];
vector<pair<int, int> > macas;
int tempo[2001];

int abs(int a)
{
    if(a<0)
       return -a;
    return a;
}

bool adj(int i, int j)
{
    return tempo[j]-tempo[i] >= max(abs(macas[i].first-macas[j].first), abs(macas[i].second-macas[j].second));
}

int dp()
{
    for(int i = K; i >= 0; i--)
    {
       memo[i] = 1;
       for(int j = i+1; j <= K; j++)
          if(adj(i,j))
             memo[i] = max(memo[i], memo[j]+1);
    }
    return memo[0]-1;
}

int main(void)
{
    while(scanf("%d %d %d", &N, &M, &K) && N)
    {
       macas.clear();
       int a, b, i = 1;
       tempo[0] = 0;
       macas.push_back(make_pair(0, 0));
       for(int j = 0; j < K; j++)
       {
          scanf("%d %d %d", &a, &b, &tempo[i++]);
          macas.push_back(make_pair(--a, --b));
       }
       scanf("%d %d", &a, &b);
       macas[0].first = --a;
       macas[0].second = --b;
       printf("%d\n", dp());
    }
    return 0;
}
