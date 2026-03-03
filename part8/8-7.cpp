#include <bits/stdc++.h>
#define N 200005
using namespace std;
int n, ans = 0, s, t;
vector<int> child[N], c(N), counter(N, 0);
map<int, int> d;//color, id
void dfs(int v){
    int cc = d[c[v]];//找color對應id
    counter[cc]++;
    ans = max(ans, counter[cc]);
    for(int u:child[v])
        dfs(u);
    counter[cc]--;
    return ;
}
int main(){
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> c[i];
        d.insert({c[i], 0});// 0 -> 尚未走訪
    }
    for(int i=0;i<n-1;++i){
        cin >> s >> t;
        child[s].push_back(t);
    }
    int cnt = 0;
    for(auto &v:d){
        v.second = cnt;
        cnt++;
    }
    dfs(0);
    cout << ans << endl;
}
