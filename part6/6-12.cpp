#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
LL n, k, Max = 0;
LL m[100005] = {};
LL dp[100005];
int main(){
    cin >> n >> k;
    for(int i=1;i<=n;++i) cin >> m[i];
    for(int i=1;i<=n;++i){
        LL skip = dp[i-1];
        LL take = m[i];
        if(i-k-1>=1) take += dp[i-k-1];
        dp[i] = max(take, skip);
    }
    cout << dp[n] << endl;
}
