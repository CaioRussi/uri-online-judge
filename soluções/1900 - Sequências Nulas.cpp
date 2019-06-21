#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
  
int main(void)
{
    ll num, sum, ans;
    map<ll, int> cnt;
    int n;
    scanf("%d",&n);
    ans = sum = 0LL;
    cnt[0LL] = 1;
    for(int i = 0; i < n; i++){
        scanf("%lld",&num);
        sum += num;
        ans += (ll)cnt[sum];
        cnt[sum]++;
    }
    printf("%lld\n",ans);
    return 0;
}