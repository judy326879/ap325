#include <bits/stdc++.h>
using namespace std;
int dp[200005] = {};
int  main(){
    int n, m, s, total = 0;
    cin >> n >> m >> s;
    vector<int> f(m);
    for(int i=0;i<n;++i){
        cin >> f[i];
        total += f[i];
    }
    int lack = total+s-m;
    if(lack<=0){
        cout << 0 << endl;
        return 0;
    }
    for(int i=0;i<n;++i){
        for(int j=m;j>=0;--j){//大到小
            if(j-f[i]>=0) dp[j] = max(dp[j], dp[j-f[i]]+f[i]);
        }
    }
    //cout << lack << endl;
    //for(int i=0;i<m;++i) cout << dp[i] << " ";
    //cout << endl;
    for(int i=0;i<=m;++i){
        if(dp[i]>=lack){
            cout << dp[i] << endl;
            return 0;
        }
    }
}
