#include <bits/stdc++.h>
#define N 200010
using namespace std;
int n, m, w[N] = {}, lc[N], rc[N], in[110], v;
int findw(int v){
    if(v>=n) return w[v];
    w[v] = findw(lc[v]) + findw(rc[v]);
    return w[v];
}
int main(){
    cin >> n >> m;
    for(int i=n;i<2*n;++i) cin >> w[i];
    for(int i=0;i<m;++i) cin >> in[i];
    for(int i=0;i<n-1;++i){
        cin >> v;
        cin >> lc[v] >> rc[v];
    }
    w[1] = findw(1);
    for(int i=0;i<m;++i){
        int v = 1;
        while(v<n){
            if(w[lc[v]]<=w[rc[v]]) v = lc[v];
            else v = rc[v];
            w[v] += in[i];
        }
        if(i>0) cout << " ";
        cout << v;
    }
}
