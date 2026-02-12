#include <iostream>
#include <algorithm>
using namespace std;
int a[100010], b[100010];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;++i) cin >> a[i];
    for(int i=0;i<n;++i) cin >> b[i];
    sort(a, a+n);
    sort(b, b+n);
    int sum = 0, k = 0;
    for(int i=0;i<n;++i){
        while(a[i]>=b[k]&&k<n){
            ++k;
        }
        if(k == n) break;
        sum++;
        ++k;
    }
    cout << sum << endl;
}
