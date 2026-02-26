#include <bits/stdc++.h>
using namespace std;
int p[101][101];
pair<int, int> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int main(){
    int n, m, i1 = 0, j1 = 0, Min = 100001;
    cin >> n >> m;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j){
            cin >> p[i][j];
            if(Min>p[i][j]){
                Min = p[i][j];
                i1 = i;
                j1 = j;
            }
        }
    int sum = 0;
    int visit[101][101] = {};
    while(1){
        sum += p[i1][j1];
        visit[i1][j1] = 1;
        int v, c;
        int q = 100001;
        for(int i=0;i<4;++i){
            int i2 = i1 + dir[i].first, j2 = j1 + dir[i].second;
            if(i2>=0&&i2<n&&j2>=0&&j2<m&&!visit[i2][j2]){
                if(p[i2][j2]<q){
                    q = p[i2][j2];
                    v = i2;
                    c = j2;
                }
            }
        }
        if(q == 100001) break;
        i1 = v;
        j1 = c;
    }
    cout << sum << endl;
}
