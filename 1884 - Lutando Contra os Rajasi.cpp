#include <bits/stdc++.h>
using namespace std;
 
#define inf 0x3f3f3f3f
 
int main() {
    int n,h,k,t,x[2001],y[2001],pos;
    bool vis[2001],ok;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&h,&k);
        memset(vis,false,sizeof vis);
        for(int i = 0; i < n; i++){
            scanf("%d%d",&x[i],&y[i]);
        }
        ok = true;
        for(int i = 0; i < n-k; i++){
            int melhor = -inf;
            pos = -1;
            for(int j = 0; j < n; j++){
                if(!vis[j] and h > x[j] and melhor < abs(y[j]-x[j])){
                    melhor = abs(y[j]-x[j]);
                    pos = j;
                }
            }
            if(pos == -1){
                ok = false;
                break;
            }
            vis[pos] = true;
            h += melhor;
        }
        printf("%c\n",ok?'Y':'N');
    }
    return 0;
}