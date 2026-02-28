#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
LL n, lmax, lmax1, lmax2, cur, Max = 0;
int main(){
    cin >> n;
    vector<LL> h(n), v(n), dp(n);
    for(int i=0;i<n;++i) cin >> h[i];
    for(int i=0;i<n;++i) cin >> v[i];
    
    stack<tuple<LL, LL, LL>> s;
    // i , i左側最大dp, 再左側最大dp
    for(int i=0;i<n;++i){
        lmax = 0;
        //挖井的左邊該格一定比較大
        while(s.size() && h[get<0>(s.top())]<h[i]){
            tie(cur, lmax1, lmax2) = s.top();
            lmax = max({lmax, lmax1, dp[cur]});
            s.pop();
        }
        if(s.size()){
            tie(cur, lmax1, lmax2) = s.top();

            if(h[cur] == h[i]){//兩點都不能挖井
                //該點不行 找左側(lmax2)
                dp[i] = lmax2 + v[i];
                if(dp[i]>dp[cur]) s.push(make_tuple(i, max(lmax1, lmax), lmax2));
                else s.push(make_tuple(cur, max(lmax1, lmax), lmax2));
            }
            else{
                dp[i] = max(lmax1, lmax2) + v[i];
                s.push(make_tuple(i, lmax, max(lmax1, lmax2)));
            }
        }
        else{
            dp[i] = v[i];
            s.push(make_tuple(i, lmax, 0));//s = empty
        }
        Max = max(Max, dp[i]);
    }
    cout << Max << endl;
}
