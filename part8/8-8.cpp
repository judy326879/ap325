//greedy bottom-up
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
        //把葉子放進queue
    }
    int i = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        ++i;
        if(v == 0) break;
        if(mark[v] == 0){
            sum++;
            mark[parent[v]] = 1;
        }
        //父節點的子節點全數處理完 -> 父節點丟進queue
        if(--deg[parent[v]] == 0){
            q.push(parent[v]);
        }
    }
    if(mark[0] == 0) sum++;
    cout << sum << endl;
}
