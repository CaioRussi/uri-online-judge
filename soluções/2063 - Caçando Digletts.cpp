#include <bits/stdc++.h>
using namespace std;

int n, v[101]; 
bool vis[101];

int func(int i, int tam = 0){
	if(vis[i]) return tam;
	vis[i] = true;
	return func(v[i]-1, tam+1);
}

int main (void){
	memset(vis, false, sizeof vis);
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&v[i]);
	}
	int ans = 1;
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			int tam = func(i);
			ans = ans/__gcd(ans,tam)*tam;
		}
	}
	printf("%d\n",ans);
	return 0;
}