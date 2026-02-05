#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
long long n, L, Max = 0, sum = 0;
stack<int> s;
int main(){
    cin >> n >> L;
    vector<long long> c(n), h(n);
    for(int i=0;i<n;++i) cin >> c[i];
    for(int i=0;i<n;++i) cin >> h[i];
    for(int i=0;i<n;++i){
        while(!s.empty()){
            int cur = s.top();
            s.pop();
            if(h[cur]<=c[i]-c[cur]){
                if(Max<h[cur]) Max = h[cur];
            }
            else{
                s.push(cur);
                if(h[i]<=c[i]-c[cur]){
                    if(Max<h[i]) Max = h[i];
                }
                else{
                    s.push(i);
                }
                break;
            }
        }
        if(s.empty()){
            if(h[i]<=c[i]){
                if(Max<h[i]) Max = h[i];
            }
            else{
                s.push(i);
            }
        }
    }
    while(!s.empty()){
        int cur = s.top();
        s.pop();
        if(L-c[cur]>=h[cur]){
            if(Max<h[cur]) Max = h[cur];
        }
        else{
            s.push(cur);
            break;
        }
    }
    cout << n-s.size() << '\n' << Max;
}
