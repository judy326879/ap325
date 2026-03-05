#include <bits/stdc++.h>
#define N 100010
using namespace std;
vector<int> f0(N, 0), f1(N, 0), w(N, 0), child[N];
void dfs(int r){
    f0[r] = 0;
    f1[r] = w[r];
    for(int c:child[r]){
        dfs(c);
        f0[r] += max(f0[c], f1[c]);
        f1[r] += f0[c];
    }
    return ;
}
int main(){
    int parent, n;
    cin >> n >> w[1];
    for(int i=2;i<=n;++i){
        cin >> parent >> w[i];
        child[parent].push_back(i);
    }
    dfs(1);
    cout << max(f1[1], f0[1]);
}
