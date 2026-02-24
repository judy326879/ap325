#include <bits/stdc++.h>
using namespace std;
struct it{
    int p, m, c;
};
it q[100010];
bool sor(it &x, it &y){
    if(x.c!=y.c) return x.c > y.c;//優先排(大->小)
    return x.m < y.m;
}
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;++i) cin >> q[i].p;
    for(int i=0;i<n;++i) cin >> q[i].c;
    for(int i=0;i<n;++i) cin >> q[i].m;
    sort(q, q+n, sor);
    map<int, int> M;
    //m大w大(單調遞增)
    int ans = 0;
    M.insert({-1, 0});
    for(int i=0;i<n;++i){
        auto it = M.upper_bound(q[i].m);//大於q[i]之min place
        it--;
        //在all條件(m<=q[i].m)找到價值最大
        int w = it->second + q[i].p;
        ans = max(ans, w);
        it = M.insert(it, {q[i].m, w});
        if(it->second < w) it->second = w;
        ++it;
        while(it!=M.end() && it->second<=w)
            it = M.erase(it);
    }
    cout << ans << endl;
}
