#include <bits/stdc++.h>
using namespace std;
int dp[2][100005] = {}, p[100005], Min = 1000;
int n, k;
int main(){
    cin >> n >> k;
    int from = 0, to = 1;
    for(int i=1;i<=n;++i) cin >> p[i];
    for(int i=1;i<=k;++i){
        int max_diff = -p[1];
        for(int j=1;j<=n;++j){
            dp[to][j] = max(dp[to][j-1], p[j]+max_diff);

            max_diff = max(max_diff, dp[from][j-1] - p[j]);
        }
        swap(to, from);
    }
    cout << dp[from][n] << endl;
}
/*
//n^2
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, si, len = 0;
    cin >> n;
    vector<int> p(n);
    for(int i=0;i<n;++i){
        int r = 0;
        cin >> si;
        while(r<len&&p[r]<si)++r;
        p[r] = si;
        if(r == len) len++;
    }
    cout << len << endl;
}
*/
