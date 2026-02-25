#include <bits/stdc++.h>
#define N 250000
using namespace std;
int main() {
    int n;
    cin >> n;
    multimap<int, int> m;
    for(int i=0;i<n;++i){
        int s, t;
        cin >> s >> t;
        auto it = m.upper_bound(t);// <
        if(it!=m.end()){
            m.erase(it);
        }
        m.insert({s, t});
    }
    cout << m.size() << endl;
}
