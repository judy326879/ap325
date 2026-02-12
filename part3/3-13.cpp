#include <iostream>
#include <algorithm>
#include <cmath>
#include <deque>
using namespace std;
pair<int, int>Map[200010];
int ans = 0;
deque<int> Max, Min;
void de_max(int i){
    while(!Max.empty() && Map[Max.back()].second<=Map[i].second){
        Max.pop_back();
    }
    Max.push_back(i);
}
void de_min(int i){
    while(!Min.empty() && Map[Min.back()].second>=Map[i].second){
        Min.pop_back();
    }
    Min.push_back(i);
}
int main(){
    int n, L;
    cin >> n >> L;
    for(int i=0;i<n;++i) cin >> Map[i].first;
    for(int i=0;i<n;++i) cin >> Map[i].second;
    sort(Map, Map+n);
    de_max(0);
    de_min(0);
    for(int i=1;i<n;++i){
        if(Map[i].first - Map[Max.front()].first>L)
            Max.pop_front();
        de_max(i);
        if(Map[i].first - Map[Min.front()].first>L)
            Min.pop_front();
        de_min(i);
        if(abs(Map[Max.front()].first-Map[Min.front()].first)<=L) ans = max(ans, Map[Max.front()].second - Map[Min.front()].second);
    }
    cout << ans << endl;
}
