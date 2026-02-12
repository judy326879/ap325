#include <iostream>
#include <algorithm>
using namespace std;
long long sum = 0;
long long n, a[100010];
int main(){
    cin >> n;
    for(int i=0;i<n;++i) cin >> a[i];
    sort(a, a+n);
    for(int i=0;i<n;++i){
        sum += (n-i)*a[i];
    }
    cout << sum << endl;
}
