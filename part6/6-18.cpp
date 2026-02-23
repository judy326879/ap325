#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, p[601], dp[601][601] = {};
    cin >> n;
    for(int i=0;i<=n;++i) cin >> p[i];
    for(int len=2;len<=n;++len){
        for(int i=0;i+len<=n;++i){
            int j=i+len-1;
            int mcost = 100000000;
            for(int k=i;k<j;++k){
                mcost = min(mcost, dp[i][k]+dp[k+1][j]+p[i]*p[j+1]*p[k+1]);
            }
            dp[i][j] = mcost;
        }
    }
    cout << dp[0][n-1] << endl;
}
