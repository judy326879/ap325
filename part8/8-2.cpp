#include <iostream>
#include <vector>
#include <algorithm>
#define N 100010
using namespace std;
vector<int> child[N];
int parent[N], leng[N];
int main(){
    int n;
    cin >> n;
    for(int i=1;i<n;++i){
        int v, w;
        cin >> v >> w;
        parent[i] = v;
        leng[i] = w;
        child[v].push_back(i);
    }
    vector<int> que;
    int d[N] = {}, step[N] = {}, head = 0;
    int Max = 0, max_step = 0;
    que.push_back(0);
    while(head < que.size()){
        int v = que[head++];
        for(int ch:child[v]){
            que.push_back(ch);
            d[ch] = d[v] + leng[ch];
            Max = max(Max, d[ch]);
            step[ch] = step[v]+1;
            max_step = max(max_step, step[ch]);
        }
    }
    cout << Max << "\n" << max_step;
}
