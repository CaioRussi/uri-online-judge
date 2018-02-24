#include <bits/stdc++.h>
using namespace std;
 
#define inf 0x3f3f3f3f
 
int n,x,y,z,w,v[201],maximo;
int pd[201][55];
 
int dp(int s, int f){
	//demitir todos
    if(s==n){
        return f*y;
    }
    int &ret = pd[s][f];
    if(ret!=inf) return ret;

    //contratar
    int ans;
    for(int i = max(f,v[s]); i <= maximo; i++){
        ans = dp(s+1,i)+(v[s]*z)+((i-f)*x)+((i-v[s])*w);
        ret = min(ret, ans);
    }
	
    //demitir
    for(int i = f; i >= v[s]; i--){
        ans = dp(s+1,i)+(v[s]*z)+((f-i)*y)+((i-v[s])*w);
        ret = min(ret, ans);
    }
    return ret;
}
 
int main(void)
{
    int t=1;
    while(scanf("%d",&n) and n){
        maximo=0;
        for(int i = 0; i < n; i++){
            scanf("%d",&v[i]);
            maximo = max(maximo,v[i]);
        }
        scanf("%d%d%d%d",&x,&y,&z,&w);
        memset(pd,inf,sizeof pd);
        printf("Instancia %d\n%d\n\n",t++,dp(0,v[0])+(v[0]*x));
    }
    return 0;
}