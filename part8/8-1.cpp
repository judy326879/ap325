#include <iostream>
#include <vector>
#include <algorithm>
#define N 100010
using namespace std;
vector<int> adj[N];//neighbor
vector<int> child[N];
vector<int> tour;

void root(int p, int v){
    for(int u:adj[v]){
        if(u!=p){
            child[v].push_back(u);
            root(v, u);
        }
    }
}
void tsp(int v){
    tour.push_back(v);
    for(int ch:child[v]){
        tsp(ch);
        tour.push_back(v);
    }
}
int main(){
    int n, total = 0;
    cin >> n;
    for(int i=0;i<n-1;++i){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        total+=w;
    }
    root(-1, 0);
    for(int i=0;i<n;++i){
        sort(child[i].begin(), child[i].end());
    }
    tsp(0);
    cout << total*2 << endl;
    int len = tour.size();
    for(int i=0;i<len;++i){
        cout << tour[i] << " ";
    }
}
