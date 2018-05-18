#include <bits/stdc++.h>
#define fr first
#define sc second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz(a) int((a).size())
#define present(c,x) ((c).find(x) != (c).end())
using namespace std;

int m,n;
int pd[105][1005],ans;
char a[105],b[1005];

int dp(int i, int j){
	if(i==m) return 1;
	if(j==n) return 0;
	int &ret = pd[i][j];
	if(ret) return ret;
	if(a[i]==b[j])
	   ret = dp(i+1,j+1);
	ret += dp(i,j+1);
	return ret;
}

int main(void)
{
	int t=1;
	//freopen("entrada.txt","r",stdin);
	//freopen("saida.txt","w",stdout);
	while(scanf("%d%d",&m,&n) and m or n){
		scanf("%s%s",&a,&b);
		memset(pd,0,sizeof pd);
		//dp(0,0);
		for(int i = 0; i <= n; i++){
			pd[m][i]=1;
		}
		for(int i = m-1; i >= 0; i--){
			for(int j = n-1; j >= 0; j--){
				pd[i][j] = pd[i][j+1];//Passando para as próximas letras.
				if(a[i]==b[j])
				   pd[i][j] += pd[i+1][j+1];//letras iguais.
				//printf("***DEBUG***%d\n",pd[i][j]);
			}
		}
		printf("Instancia %d\n%d\n\n",t++,pd[0][0]);
	}
    return 0;
}