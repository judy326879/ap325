#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, l, p[600], cost[600][600];
    cin >> n >> l;
    for(int i=1;i<=n;++i) cin >> p[i];
    p[0] = 0, p[n+1] = l;
    //只有一段
    for(int i=0;i<=n;++i) cost[i][i+1] = 0;
    //len = j-1
    //len = 2 -> 兩小段(中間一個切點)
    //until涵蓋整個長度
    for(int len=2;len<=n+1;len++){
        //i = left
        for(int i=0;i+len<=n+1;++i){
            //j = right
            int j=i+len;
            int mcost = 100000000;
            //切點k
            //total cost = left cost + right cost + length
            for(int k=i+1;k<j;++k)
                mcost = min(mcost, cost[i][k]+cost[k][j]);
            cost[i][j] = mcost + p[j] - p[i];
        }
    }
    cout << cost[0][n+1] << endl;
}
