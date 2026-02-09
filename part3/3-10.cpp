#include <iostream>
#include <algorithm>
#include <map>
#define N 1000010
using namespace std;
int seq[N], cnt[N] = {};
map<int, int> dic;
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> seq[i];
        dic[seq[i]] = 0;
    }
    int nc = 0;
    for(auto &p:dic){//& -> 可修改dic(把0以遞增修改)
        p.second = nc++;//0 ~ n-1
    }
    int left = 0, right = 0, wc = 0, shortest = n;
    while(right<n){
        int color = dic[seq[right]];
        cnt[color]++;
        if(cnt[color] == 1) wc++;//total
        right++;
        while(1){
            color = dic[seq[left]];
            if(cnt[color] == 1) break;
            cnt[color]--;
            left++;
        }
        if(wc == nc){
            shortest = min(shortest, right-left);
        }
    }
    cout << shortest << endl;
}
