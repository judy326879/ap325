#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> t(n), d(n);
        vector<pair<long long, long long>> f(n);
        for(int i=0;i<n;++i) cin >> f[i].second;
        for(int i=0;i<n;++i) cin >> f[i].first;
        sort(f.begin(), f.end());
        long long k = 0, a = 1;
        for(int i=0;i<n;++i){
            k += f[i].second;
            if(k>f[i].first){
                cout << "no" << endl;
                a = 0;
                break;
            }
        }
        if(a == 1) cout << "yes" << endl;
    }
}
