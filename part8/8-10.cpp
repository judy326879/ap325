#include <bits/stdc++.h>
#define N 100005
using namespace std;
int n, sum = 0;
vector<int> deg(N, 0), parent(N), mark(N, 0);
queue<int> q;
int main(){
    cin >> n;
    for(int i=1;i<n;++i){
        cin >> parent[i];
        deg[parent[i]]++;
    }
    for(int i=0;i<n;++i){
        if(deg[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(mark[parent[v]]==2){
            mark[v] = 1;
        }
        if(mark[v]==0&&mark[parent[v]]!=2){
            mark[parent[v]] = 2;
            sum++;
        }
        if(--deg[parent[v]] == 0&&parent[v]!=0){
            q.push(parent[v]);
        }
    }
    cout << sum << endl;
}
