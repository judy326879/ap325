#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> Map(n);
    for(int i=0;i< n;++i) cin >> Map[i].first >> Map[i].second;
    sort(Map.begin(), Map.end());
    int len = 0, end = Map[0].second, begin = Map[0].first;
    for(int i=1;i<n;++i){
        if(Map[i].first<=end&&Map[i].second>end) end = Map[i].second;
        else if(Map[i].first<=end&&Map[i].second<=end) continue;
        else{
            len += end - begin;
            begin = Map[i].first;
            end = Map[i].second;
        }
    }
    len += end - begin;
    cout << len << endl;
}
