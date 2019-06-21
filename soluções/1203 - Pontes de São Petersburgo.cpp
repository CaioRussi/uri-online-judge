#include <stdio.h>
 
int R, K, v[101], ok[4951];
 
bool pd()
{
     int i, j;
     for(i = 1; i <= K; i++)
        ok[i] = 0;
     ok[0] = 1;
     for(i = 1; i <= R; i++)
     {
        for(j = K; j >= v[i]; j--)
           if(ok[j-v[i]]==1)
              ok[j] = 1;
     }
     return ok[K]==1;   
}
 
int main(void)
{
    while(scanf("%d %d", &R, &K)!=EOF)
    {
       for(int i = 1; i <= R; i++)
          v[i] = 0;
       int A, B;
       for(int i = 0; i < K; i++)
       {
          scanf("%d %d", &A, &B);
          v[A]++;
          v[B]++;
       }
       if(pd())
          puts("S");
       else
          puts("N");
    }
    return 0;
}
