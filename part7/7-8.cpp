#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, a, b;
        cin >> n >> m;
        vector<int> Dot(n, -1);
        vector<int> adj[n];
        for(int i=0;i<m;++i){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int k = 1;
        for(int i=0;i<n;++i){
            if(Dot[i] == -1){
                queue<int> q;
                q.push(i);
                Dot[i] = 0;

                while(!q.empty()){
                    int a = q.front();
                    q.pop();
                    for(int b:adj[a]){
                        if(Dot[b] == -1){
                            Dot[b] = 1-Dot[a];
                            q.push(b);
                        }
                        else if(Dot[a] == Dot[b]){
                            k = 0;
                            break;
                        }
                    }
                }
            }
            if(k == 0) break;
        }
        if(k == 1) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
