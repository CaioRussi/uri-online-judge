#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,ii> iiii;
char grid[101][105];
int dx[]={1,0,-1,0}; 
int dy[]={0,1,0,-1};
int vis[101][101][150],n,m;

int bfs(int a, int b){
	queue<iiii> fila;
	fila.push(iiii(ii(a,b),ii(0,0)));
	iiii v;
	int cord_x, cord_y, tempo, mask, x, y, z;
	while(!fila.empty()){
		v = fila.front(); fila.pop();
		cord_x = v.first.first; cord_y = v.first.second;
		tempo = v.second.first; mask = v.second.second;
		if(grid[cord_x][cord_y]=='*'){
			return tempo;
		}
		if(vis[cord_x][cord_y][mask]) continue;
		vis[cord_x][cord_y][mask] = 1;
		for(int i = 0; i < 4; i++){
			x = cord_x + dx[i];
			y = cord_y + dy[i];
			z = mask;
			if(x >= 0 and x < n and y >= 0 and y < m){
				if(grid[x][y]=='#') continue;
				if(isupper(grid[x][y])){
					if(!(mask&(1<<(grid[x][y]-'A')))) continue;
				}
				if(islower(grid[x][y]))
				   z |= 1<<(grid[x][y]-'a');
				fila.push(iiii(ii(x,y),ii(tempo+1,z)));
			}
		}
	}
	return -1;
}

int main(void)
{
	int x,y;
	//freopen("entrada.txt", "r", stdin);
	n = 0;
	for(int i = 0; gets(grid[i])!=NULL; i++, n++);//Leitura
	memset(vis,0,sizeof vis);
	m = 0;
	for(int i = 0; grid[0][i] != '\0'; i++){
		m++;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j]=='@'){
				x = i;
				y = j;
			}
		}
	}
	int ret = bfs(x,y);
	if(ret==-1){
		puts("--");
	}else{
		printf("%d\n",ret);
	}
    return 0;
}