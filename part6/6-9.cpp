#include <bits/stdc++.h>
using namespace std;
int d[101][100005] = {};
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> w(n+1), p(n+1);
    for(int i=1;i<=n;++i) cin >> w[i];
    for(int i=1;i<=n;++i) cin >> p[i];

    for(int i=1;i<=n;++i){
        for(int j=0;j<w[i];++j){
            d[i][j] = d[i-1][j];    
        }
        for(int j=w[i];j<=m;++j){
            d[i][j] = max(d[i-1][j-w[i]]+p[i], d[i-1][j]);//weight max = m
            //p = prize
            //j -> max = weight max
        }
    }
    cout << d[n][m] << endl;
}
