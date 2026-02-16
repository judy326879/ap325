#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<LL> c(n), dp(n);
    if(n==1){
        cin >> c[0];
        cout << c[0];
        return 0;
    }
    else if(n==2){
        cin >> c[0] >> c[1];
        cout << min(c[0], c[1]);
        return 0;
    }
    cin >> c[0] >> c[1] >> c[2];
    dp[0] = c[0], dp[1] = c[1], dp[2] = c[2]+min(dp[0], dp[1]);
    for(int i=3;i<n;++i){
        cin >> c[i];
        dp[i] = c[i] + min(dp[i-1], min(dp[i-2], dp[i-3]));
    }
    cout << min(dp[n-2], dp[n-1]) << endl;
}
