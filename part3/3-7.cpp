#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
long long n, k;
int main(){
    cin >> n >> k;
    vector<long long> a(n);
    for(int i=0;i<n;++i) cin >> a[i];
    int sum = 0, k1 = 0;
    int q = 0;
    int ans = 0;
    long long Min = 0;
    for(int i=0;i<n;++i){
        k1+=a[i];
        while(k1>k){
            k1 -= a[q];
            ++q;
        }
        if(Min < k1){
            ans = k1;
            Min = k1;
            sum = 0;
        }
        if(Min == k1){
            sum++;
        }
    }
    cout << Min << '\n' << sum;
}
