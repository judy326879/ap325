#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    vector<pair<int, int>> Map(n);
    for(int i=0;i<n;++i) cin >> x[i];
    for(int i=0;i<n;++i) cin >> y[i];
    for(int i=0;i<n;++i){
        Map[i] = {x[i], y[i]};
    }
    sort(Map.begin(), Map.end());
    int sum = 1;
    int h = Map[n-1].second;
    int k = 0;
    for(int i=n-2;i>=0;--i){
        if(Map[i].second>h){
            h = Map[i].second;
            sum++;
        }
    }
    cout << sum << endl;
}
