#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<long long> t(n);
    long long d;
    long long sum = 0;
    for(int i=0;i<n;++i) cin >> t[i];
    for(int i=0;i<n;++i){
        cin >> d;
        sum += d;
    }
    sort(t.begin(), t.end());
    for(int i=1;i<n;++i){
        t[i] += t[i-1];
    }
    for(int i=1;i<n;++i){
        t[i] += t[i-1];
    }
    cout << sum - t[n-1] << endl;
}
