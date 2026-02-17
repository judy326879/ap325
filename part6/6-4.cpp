#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int main(){
    LL k, n;
    cin >> n >> k;
    vector<pair<LL, LL>> p(n);
    cin >> p[0].first >> p[0].second;
    LL k1 = abs(p[0].first-k), k2 = abs(p[0].second-k);
    for(int i=1;i<n;++i){
        LL q1 = 0, q2 = 0;
        cin >> p[i].first >> p[i].second;
        if(k1+abs(p[i].first-p[i-1].first)<k2+abs(p[i].first-p[i-1].second)) q1 = (k1+abs(p[i].first-p[i-1].first));
        else if(k1+abs(p[i].first-p[i-1].first)==k2+abs(p[i].first-p[i-1].second)) q1 = k1 + abs(p[i].first-p[i-1].first);
        else q1 = (k2+abs(p[i].first-p[i-1].second));

        if(k1+abs(p[i].second-p[i-1].first)<k2+abs(p[i].second-p[i-1].second)) q2 = (k1+abs(p[i].second-p[i-1].first));
        else if(k1+abs(p[i].second-p[i-1].first)==k2+abs(p[i].second-p[i-1].second)) q2 = k1 + abs(p[i].second-p[i-1].first);
        else q2 = (k2+abs(p[i].second-p[i-1].second));
        k1 = q1;
        k2 = q2;
    }
    cout << min(k1, k2);
}
