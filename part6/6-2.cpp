#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<LL> vec(n);
    cin >> vec[0];
    for(int i=1;i<n;++i){
        cin >> vec[i];
        if(i>=2) vec[i] = max(vec[i-2]+vec[i], max(vec[i], vec[i-1]));
        else vec[i] = max(vec[i], vec[i-1]);
    }
    cout << vec[n-1] << endl;
}
