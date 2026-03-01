#include <bits/stdc++.h>
#define N 100005
using namespace std;
int n, k, narea = N, maxarea = 0, root;
multiset<int> comp;
vector<int> adj(N), parent(N), sz(N);
int find(int u){
    if(parent[u]<0) return u;
    return parent[u] = find(parent[u]);
}
void combine(int u, int v){
    int f1 = find(u), f2 = find(v);
    if(f1 == f2) return ;
    comp.erase(comp.find(-parent[f1]));
    comp.erase(comp.find(-parent[f2]));
    if(parent[f1]<parent[f2]){
        parent[f1] += parent[f2];
        parent[f2] = f1;
        comp.insert(-parent[f1]);
    }
    else{
        parent[f2] += parent[f1];
        parent[f1] = f2;
        comp.insert(-parent[f2]);
    }
    return ;
}
int main(){
    cin >> n >> k;
    for(int i=1;i<=n;++i){
        cin >> adj[i];
        if(adj[i] == 1) comp.insert(1);
    }
    adj[0] = 0;
    adj[n+1] = 0;
    for(int i=1;i<=n;++i) parent[i] = -1;
    for(int i=1;i<n;++i){
        if(adj[i] == 1){
            if(adj[i+1] == adj[i]) combine(i, i+1);
            maxarea = max(maxarea, 1);
            root = find(i);
            if(-parent[root]>maxarea) maxarea = -parent[root];
        }
    }
    int totaln = 0, totalm = maxarea;
    if(!comp.empty()) totaln += *comp.begin();
    while(k--){
        int v;
        cin >> v;
        if(adj[v] == 0){
            adj[v] = 1;
            comp.insert(1);
            if(adj[v+1]==1) combine(v, v+1);
            if(adj[v-1]==1) combine(v, v-1);
            root = find(v);
            if(-parent[root]>maxarea) maxarea = -parent[root];
        }
        if(!comp.empty()) totaln += *comp.begin();
        totalm += maxarea;
    }
    cout << totalm << '\n' << totaln;
}
