#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int main(){
    int n, x, y;
    cin >> n >> x >> y;
    vector<pair<int, int>> p(n);
    for(int i=0;i<n;++i) cin >> p[i].first >> p[i].second;
    sort(p.begin(), p.end());
    int end = x, j = 0;
    int sum = 0;
    while(end<y){
        int lastend = end;
        while(j<n&&p[j].first<=end){
            if(p[j].second>lastend){
                lastend = p[j].second;
            }
            ++j;
        }
        if(lastend == end){
            cout << -1 << endl;
            return 0;
        }
        end = lastend;
        sum++;
    }
    cout << sum << endl;
}
