#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int n;
vi adj[6005],adj2[6005];
vi topsort;
bool vis[6005];

void dfs(int u){
	vis[u] = true;
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(!vis[v]){
			dfs(v);
			adj2[v].push_back(u);
			//printf("%d - %d\n",v,u);
		}
	}
	topsort.push_back(u);
}

int main(){
	int t,a,b,v;
	scanf("%d",&t);
	while(t--){
		v = 0;
		scanf("%d",&n);
		for(int i = 0; i < n; i++){
			adj[i].clear();
			adj2[i].clear();
			vis[i] = false;
		}
		for(int i = 1; i < n; i++){
			scanf("%d%d",&a,&b);a--;b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		topsort.clear();
		dfs(0);
		memset(vis,false,sizeof vis);
		int ans = 0;
		for(int i = 0; i < n; i++){
			int v = topsort[i];
			if(!vis[v]){
				ans++;
				if(v!=0)
					vis[adj2[v][0]] = true;
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}