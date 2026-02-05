#include <iostream>
#include <queue>
#define N 100010
using namespace std;
int main(){
    int parent[N] = {};
    int h[N] = {};//height
    int deg[N] = {};//子數量
    queue<int> q;
    int n, total = 0, Max = 0, ch, root;
    cin >> n;
    for(int i=1;i<=n;++i){
        cin >> deg[i];
        if(deg[i] == 0){
            q.push(i);
            continue;
        }
        for(int j=0;j<deg[i];++j){
            cin >> ch;
            parent[ch] = i;
        }
    }
    while(1){
        int k = q.front();
        q.pop();
        total += h[k];
        Max = max(h[k], Max);
        int p = parent[k];
        if(p == 0){
            root = k;
            break;
        }
        h[p] = max(h[p], h[k]+1);
        if(--deg[p] == 0) q.push(p);
    }
    cout << root << "\n" << total << endl;

}
