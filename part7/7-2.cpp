#include <bits/stdc++.h>
using namespace std;
int n, m, s;
vector<int> p[500005], value(400005);
vector<int> visited(400005, 0);
int dfs(int s){
    int sum = value[s];
    visited[s] = 1;
    for(int a:p[s]){
        if(!visited[a]){
            sum += dfs(a); // = while !q.empty()
        }
    }
    return sum;
}
int main(){
    cin >> n >> m;
    for(int i=0;i<n;++i) cin >> value[i];
    int a, b;
    for(int i=0;i<m;++i){
        cin >> a >> b;
        p[a].push_back(b);
        p[b].push_back(a);
    }
    int Max = 0;
    for(int i=0;i<n;++i){
        //區塊一個一個檢查 不用每次都跑
        if(!visited[i]) Max = max(Max, dfs(i));
    }
    cout << Max << endl;
}
