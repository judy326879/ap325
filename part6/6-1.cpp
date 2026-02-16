#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<long long> step(n);
    for(int i=0;i<n;++i) cin >> step[i];
    for(int i=2;i<n;++i) step[i] += min(step[i-1], step[i-2]);
    cout << step[n-1] << endl;
}
