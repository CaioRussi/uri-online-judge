#include <bits/stdc++.h>
using namespace std;

int main(){
	long long a,b;
	scanf("%lld%lld",&a,&b);
	a = a*(a-1LL)/2LL; 
	b = b*(b+1LL)/2LL;
	printf("%lld\n",b-a);
	return 0;
} 