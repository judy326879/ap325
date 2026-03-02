//bottom-up
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<LL> parent(n), len(n);
    vector<LL> deg(n), num(n);
    for(int i=1;i<n;++i){
        cin >> parent[i] >> len[i];
        deg[parent[i]]+=1;
    }
    parent[0] = -1;//根節點
    //中位數
    LL median = -1, total = 0;
    queue<LL> q;
    for(int i=1;i<n;++i)
        if(deg[i]==0) q.push(i);

    while(!q.empty()){
        int v = q.front();
        q.pop();
        num[v]++;
        if(median<0&&num[v]>=n/2) median = v;

        total += min(num[v], n-num[v])*len[v];

        if(parent[v]<0) break;
        num[parent[v]] += num[v];
        if(--deg[parent[v]]==0) q.push(parent[v]);
    }
    cout << median << '\n' << total;
}
