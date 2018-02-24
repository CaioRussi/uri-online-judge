#include <bits/stdc++.h>
using namespace std;
 
int atk[21], def[21], hab[21];
int n,a,d,h,aa,dd,hh,cnt;
 
bool func(int i, int A, int D, int H, int cnt){
    if(cnt>1 and A==a and D==d and H==h) return true;
    if(i==n) return false;
    return (func(i+1, A+atk[i], D+def[i], H+hab[i], cnt+1) or func(i+1, A, D, H, cnt));
}
 
int main(void)
{
    bool ok=false;
    scanf("%d%d%d%d",&n,&a,&d,&h);
    for(int i = 0; i < n; i++){
        scanf("%d%d%d",&atk[i],&def[i],&hab[i]);
    }
    printf("%c\n",func(0,0,0,0,0)?'Y':'N');
    return 0;
}