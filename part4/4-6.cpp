#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long f1, m1;
    double d;
    vector<long long> f(n), m(n);
    vector<tuple<double, long long, long long>> a(n);
    for(int i=0;i<n;++i) cin >> m[i];
    for(int i=0;i<n;++i) cin >> f[i];
    for(int i=0;i<n;++i) a[i] = {(double)m[i]/f[i] , m[i], f[i]};
    sort(a.begin(), a.end());
    long long k = 0;
    long long sum = 0;
    for(int i=0;i<n;++i){
        tie(d, m1, f1) = a[i];
        sum += f1*k;
        k+=m1;
    }
    cout << sum << endl;
}
