#include <iostream>
#include <set>
using namespace std;
int a, m, n, k, ans = 0;
multiset<long long> s1, s2;
int main(){
    cin >> m >> n >> k;
    for(int i=0;i<m;++i){
        cin >> a;
        s1.insert(a);
    }
    for(int i=0;i<n;++i){
        cin >> a;
        if(s1.find(k-a)!=s1.end()){
            ans++;
        }
    }
    cout << ans << endl;
}
