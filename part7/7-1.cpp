#include <bits/stdc++.h>
using namespace std;
int n, m, s1;
int d[110] = {};
int main(){
    cin >> n >> m >> s1;
    vector<int> vec[110];
    int a, b;
    for(int i=0;i<m;++i){
        cin >> a >> b;
        vec[a].push_back(b);
    }
    int visit[110] = {};
    int len = 0, count = 0;
    queue<int> q;
    q.push(s1);
    visit[s1] = 1;
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for(int a:vec[k]){
            if(!visit[a]){
                q.push(a);
                visit[a] = 1;
                d[a] = d[k] + 1;
                count++;
                len += d[a];
            }
        }
    }
    cout << count << '\n' << len;
}
