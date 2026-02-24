#include <bits/stdc++.h>
using namespace std;
int dp[60][60][60][60], p[30][30];
int rc(int it, int left, int right){
    int sum = 0;
    for(int i=left;i<=right;++i){
        sum += p[it][i];
    }
    if(sum<=(right-left+1)/2) return sum;
    else return right-left+1-sum;
}
int cc(int it, int top, int down){
    int sum = 0;
    for(int i=top;i<=down;++i){
        sum += p[i][it];
    }
    if(sum<=(down-top+1)/2) return sum;
    else return down-top+1-sum;
}

int main(){
    int m, n, count = 0;
    cin >> m >> n;
    for(int i=0;i<m;++i)
        for(int j=0;j<n;++j) cin >> p[i][j];
    int h, w, top, left;
    for(h=1;h<=m;++h){  //length
        for(w=1;w<=n;++w){//length
            for(top=0;top+h<=m;top++){
                for(left=0;left+w<=n;left++){
                    if(w==1||h==1){
                        dp[h][w][top][left] = 0;
                        continue;
                    }
                    int mcost, cost;
                    //top
                    mcost = dp[h-1][w][top+1][left] + rc(top, left, left+w-1);
                    //bottom
                    cost = dp[h-1][w][top][left] + rc(top+h-1, left, left+w-1);
                    mcost = min(cost, mcost);
                    //left
                    cost = dp[h][w-1][top][left+1] + cc(left, top, top+h-1);
                    mcost = min(cost, mcost);
                    //right
                    cost = dp[h][w-1][top][left] + cc(left+w-1, top, top+h-1);
                    mcost = min(cost, mcost);
                    dp[h][w][top][left] = mcost;
                }
            }
        }
    }
    cout << dp[m][n][0][0] << endl;
}
