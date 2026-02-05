#include <iostream>
#include <climits>
#include <cmath>
using namespace std;
long long p, ans = INT_MAX, k;
int n, a[26];
void rec(int i, int prod){
    if(i>=n){
        if(prod<=p&&p-prod<ans){
            ans = p-prod;
            k = prod;
        }
        return ;
    }
    rec(i+1, prod);
    rec(i+1, prod+a[i]);
    return ;
}
int main(){
    cin >> n >> p;
    for(int i=0;i<n;++i) cin >> a[i];
    rec(0, 0);
    cout << k << endl;
}
