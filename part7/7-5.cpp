#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, p, l, r;
    cin >> n >> p >> l >> r;
    vector<int> vec(n), step(n, 1000001);
    for(int i=0;i<n;++i){
        cin >> vec[i];
        if(vec[i]>=n||vec[i]<0) vec[i] = n;
    }
    queue<int> q;
    q.push(0);
    step[0] = 0;
    vector<int> visit(n, -1);
    while(!q.empty()&&visit[p] == -1){
        int k = q.front();
        q.pop();
        if(k+r<n){
            if(vec[k+r]!=n&&visit[vec[k+r]]==-1){
                step[vec[k+r]] = 1+step[k];
                q.push(vec[k+r]);
                visit[vec[k+r]] = 1;
            }
        }
        if(k-l>=0){
            if(vec[k-l]!=n&&visit[vec[k-l]]==-1){
                step[vec[k-l]] = 1+step[k];
                q.push(vec[k-l]);
                visit[vec[k-l]] = 1;
            }
        }
    }
    cout << step[p] << endl;
}
