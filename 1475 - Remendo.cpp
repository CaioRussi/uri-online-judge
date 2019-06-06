#include <stdio.h>
#include <algorithm>
using namespace std;
 
int N, C, T1, T2, f[1001], pd[1001][2], dist[1001];
 
int PD(int i)
{
    if(f[i]-f[1] <= T1)
        pd[i][0] = T1;
    else
    {
        int j = i, soma;
        soma = dist[j];
        while(soma<=T1 && j > 1)
           soma += dist[--j];
        if(pd[i][0]==0)
           pd[i][0] = PD(j-1) + T1;
    }
    if(f[i]-f[1] <= T2)
        pd[i][1] = T2;
    else
    {
        int j = i, soma;
        soma = dist[j];
        while(soma<=T2 && j > 1)
           soma += dist[--j];
        if(pd[i][1]==0)
           pd[i][1] = PD(j-1) + T2;
    }
    return min(pd[i][0], pd[i][1]);
}
 
int main(void)
{
    while(scanf("%d %d %d %d", &N, &C, &T1, &T2)!=EOF)
    {
       f[0] = 0;
       for(int i = 1; i <= N; i++)
       {
          pd[i][0] = pd[i][1] = 0;
          scanf("%d", &f[i]);
          dist[i] = f[i]-f[i-1];
       }
       printf("%d\n", PD(N));
    }
    return 0;
}
