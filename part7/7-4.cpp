#include <bits/stdc++.h>
using namespace std;
char p[505][505];
pair<int, int> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m;
int main(){
    cin >> n >> m;
    for(int i=0;i<=m+1;++i){
        p[0][i] = '1';
        p[n+1][i] = '1';
    }
    for(int i=0;i<=n+1;++i){
        p[i][0] = '1';
        p[i][m+1] = '1';
    }
    int dis[505][505] = {};
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            cin >> p[i][j];
            dis[i][j] = -1;
        }
    dis[1][1] = 0;
    queue<pair<int, int>> q;
    q.push({1, 1});
    while(!q.empty()&&dis[n][m]<0){
        int i1 = q.front().first, j1 = q.front().second;
        q.pop();
        for(int i=0;i<4;++i){
            int i2 = i1 + dir[i].first, j2 = j1 + dir[i].second;
            while(p[i2][j2]=='0'){  //直衝
                if(dis[i2][j2]==-1){//碰到牆壁
                    dis[i2][j2] = dis[i1][j1]+1;
                    q.push({i2, j2});
                }
                i2 += dir[i].first;
                j2 += dir[i].second;
            }
        }
    }
    if(dis[n][m]>0) dis[n][m]--;
    cout << dis[n][m] << endl;
}
