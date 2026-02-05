#include <iostream>
using namespace std;
int p = 10009, n, a[27], ans = 0;
void rec(int i, int prod){
    if(i>=n){
        if(prod == 1) ans++;
        return ;
    }
    rec(i+1, (prod*a[i])%p);
    rec(i+1, prod);
    return ;
}
int main(){
    cin >> n;
    for(int i=0;i<n;++i) cin >> a[i];
    rec(0, 1);
    cout << ans-1 << endl;
}
