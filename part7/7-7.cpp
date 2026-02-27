#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int main(){
    LL n, m, u, v;
    cin >> n >> m;
    vector<LL> w(n+1), indeg(n+1, 0);
    vector<LL> adj[n+1];
    vector<LL> earlist(n+1, 0), last(n+1);
    queue<LL> q;
    vector<LL> topo;
    for(int i=1;i<=n;++i) cin >> w[i];
    for(int i=0;i<m;++i){
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    for(int i=1;i<=n;++i){
        if(indeg[i] == 0) q.push(i);
    }
    LL ttime = 0;
    while(!q.empty()){
        LL k = q.front();
        q.pop();
        topo.push_back(k);

        ttime = max(ttime, earlist[k] + w[k]);
        for(LL a:adj[k]){
            if(earlist[a]<earlist[k]+w[k]){
                earlist[a] = earlist[k]+w[k];
            }
            if(--indeg[a] == 0) q.push(a);
        }
    }
    cout << ttime << endl;
    for(int i=1;i<=n;++i) last[i] = ttime;
    vector<LL> crit;
    for(int i=topo.size()-1;i>=0;--i){
        int k = topo[i];
        for(int a:adj[k]){
            last[k] = min(last[k], last[a]-w[a]);
        }
    }
    for(int i=1;i<=n;++i){
        if(earlist[i]+w[i] == last[i]) crit.push_back(i);
    }
    for(LL a:crit) cout << a << " ";
}
