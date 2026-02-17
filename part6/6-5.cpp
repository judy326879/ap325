#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
LL Map[201][201] = {}, Max;
int n, m;
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin >> Map[i][j]; 
            Map[i][j] += Map[i-1][j];//2D壓縮1D
        }
    }
    for(int i=1;i<=n;++i){
        for(int i1=i;i1<=n;++i1){
            LL cur = 0;
            for(int j=1;j<=m;++j){
                cur = max(cur, (LL)0) + (Map[i1][j] - Map[i-1][j]);
                Max = max(Max, cur);
            }
         }
    }
    cout << Max << endl;
}
