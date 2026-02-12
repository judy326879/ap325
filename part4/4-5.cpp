#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;
long long a1, b1;
double c1;
int main(){
    int n;
    cin >> n;
    vector<tuple<double, long long, long long>>vec(n);
    vector<long long> a(n), b(n);
    for(int i=0;i<n;++i) cin >> a[i];
    for(int i=0;i<n;++i) cin >> b[i];
    for(int i=0;i<n;++i){
        vec[i] = {(double)b[i]/a[i], a[i], b[i]};
    }
    sort(vec.begin(), vec.end());
    long long k = 0, sum = 0;
    for(int i=n-1;i>=0;--i){
        tie(c1, a1, b1) = vec[i];
        k += a1;
        sum += k*b1;
    }
    cout << sum << endl;
}
