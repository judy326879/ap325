#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<pair<long long, long long>>a(n);
    for(int i=0;i<n;++i) cin >> a[i].second >> a[i].first;
    sort(a.begin(), a.end());
    int end = a[0].first;
    int sum = 1;
    for(int i=1;i<n;++i){
        if(a[i].second<=end) continue;
        end = a[i].first;
        sum++;
    }
    cout << sum << endl;
}
