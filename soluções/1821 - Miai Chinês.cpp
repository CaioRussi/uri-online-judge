#include <bits/stdc++.h>
#define fr first
#define sc second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz(a) int((a).size())
#define present(c,x) ((c).find(x) != (c).end())
using namespace std;

int n,m;
int match[205], vis[101];
vector<int> adj[101];
int mat[101][101];

int Aug(int l) {
    if (vis[l])
        return 0;
    vis[l] = 1;
    for (int j = 0; j < sz(adj[l]); j++) {
        int r = adj[l][j];
        if (match[r] == -1 || Aug(match[r])) {
            match[r] = l;
            return 1; // Encontrou
        }
    }
    return 0;
}

int main()
{
	int a,b,c=1;
	//freopen("entrada.txt","r",stdin);
	//freopen("saida.txt","w",stdout);
	while(scanf("%d%d",&n,&m) and n or m){
		memset(mat,0,sizeof mat);
		for(int i = 0; i < n; i++){
			adj[i].clear();
			match[i]=-1;
			match[n+i]=-1;
		}
		for(int i = 0; i < m; i++){
			scanf("%d%d",&a,&b);
			mat[a-1][b-1] = 1;
		}
		int V = n + n;//conjunto1 + conjuto2
        int VLeft = n;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(!mat[i][j])
					adj[i].pb(n+j);
			}
		}
		int MCBM = 0;
        for (int l = 0; l < VLeft; l++) {
            memset(vis,0,sizeof vis);
            MCBM += Aug(l);
        }
        printf("Instancia %d\n%s\n\n",c++,MCBM==n?"possivel":"impossivel");
	}
    return 0;
}