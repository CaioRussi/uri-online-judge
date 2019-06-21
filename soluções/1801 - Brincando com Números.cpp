#include <bits/stdc++.h>
using namespace std;

int dx[10];

bool is_perm(long long y) {
	int dy[10], i;
	for (i=0; i<10; i++) dy[i] = 0;
	while (y){ dy[y%10LL]++; y /= 10LL; }
	for (i=0; i<10; i++) if (dy[i] != dx[i]) return false;
	return true;
}

long long func(long long x){
	long long d[15];
	int tl = 0;
	for (int i=0; i<10; i++) dx[i] = 0;
	while(x){
		d[tl++] = x%10LL;
		dx[x%10LL]++;
		x /= 10LL;
	}
	sort(d,d+tl);
	long long ret = 0LL;
	for(int i = tl-1; i >= 0; i--){
		ret = ret*10LL+d[i];
	}
	return ret;
}

int main(){
   long long x, lo, hi, y;
   scanf("%lld",&x);
   y=func(x);
   lo = (long long)ceil(sqrt((double)x));
   hi = (long long)ceil(sqrt((double)(x+y)));
   //printf("%lld %lld\n",lo,hi);
   int ans= 0;
   for(long long i = lo; i <= hi; i++){
	   if(is_perm(i*i-x))
	      ans++;
   }
   printf("%d\n",ans);
   return 0;
}