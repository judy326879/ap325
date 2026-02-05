#include <iostream>
#include <stack>
#include <map>
using namespace std;
map<long long, long long> mp;//mp[height] = place
int h[200005], p[200005];
int main(){
    int n;
    long long sum = 0;
    cin >> n;
    for(int i=0;i<n;++i) cin >> h[i];
    for(int i=0;i<n;++i) cin >> p[i];

    mp[h[0]] = 0;//first person

    for(int i=1;i<n;++i){
        auto it = mp.upper_bound(h[i] + p[i]);//大於h[i]+p[i]Min之位址
        if(it == mp.end()) sum+=i;
        else{
            sum+=i-it->second-1;
        }
        it = mp.upper_bound(h[i]);
        mp.erase(mp.begin(), it);//會把前面矮的人擋住

        mp[h[i]] = i;
    }
    cout << sum << endl;
}
