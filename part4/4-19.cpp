#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<tuple<int, int, int>> f(n);
    for(int i=0;i<n;++i){
        int m, s, t;
        cin >> m >> s >> t;
        f[i] = {s, t, m};
    }
    sort(f.begin(), f.end());
    int m, s, t;
    tie(s, t, m) = f[0];
    int temp = m;
    int Max = temp;
    priority_queue<pair<int, int>> q;
    q.push({-t, m});
    for(int i=1;i<n;++i){
        tie(s, t, m) = f[i];
        int t1, m1;
        if(!q.empty()) t1 = -q.top().first, m1 = q.top().second;
        while(t1<s&&!q.empty()){
            q.pop();
            temp -= m1;
            if(!q.empty()){
                t1 = -q.top().first;
                m1 = q.top().second;
            }
        }
        temp += m;
        q.push({-t, m});
        Max = max(Max, temp);
    }
    cout << Max << endl;
}
