#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
bool k1(pair<int, int> c, pair<int, int> v){
    if(c.first == v.first) return c.second < v.second;
    else return c.first < v.first;
}
bool k2(pair<int, int> c, pair<int, int> v){
    if(c.second == v.second) return c.first < v.first;
    else return c.second < v.second;
}
int main(){
    int n;
    cin >> n;
    pair<int, int> p[100010];
    for(int i=0;i<n;++i) cin >> p[i].first >> p[i].second;
    int Min = 200000001;
    sort(p, p+n, k1);
    for(int i=1;i<n;++i) Min = min(Min, abs(p[i].first-p[i-1].first)+abs(p[i].second-p[i-1].second));
    sort(p, p+n, k2);
    for(int i=1;i<n;++i) Min = min(Min, abs(p[i].first-p[i-1].first)+abs(p[i].second-p[i-1].second));
    cout << Min << endl;
}
