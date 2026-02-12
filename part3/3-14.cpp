#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
pair<long long, long long> f1[100001];
long long c[50001];
long long sum = 0;
stack<double> X;
stack<pair<long long, long long>> f;
int main(){
    long long n, m;
    cin >> n >> m;
    for(int i=0;i<n;++i){
        cin >> f1[i].first >> f1[i].second;
    }
    for(int i=0;i<m;++i) cin >> c[i];
    sort(f1, f1+n);
    sort(c, c+m);
    f.push({f1[0].first, f1[0].second});
    f.push({f1[1].first, f1[1].second});
    X.push((double)(f1[1].second-f1[0].second)/(f1[0].first-f1[1].first));
    for(int i=2;i<n;++i){
        long long x = f1[i].first, y = f1[i].second;
        long long x1 = f.top().first, y1 = f.top().second;
        while((!X.empty()&&X.top()>=(double)(y1-y)/(x-x1))||(!f.empty()&&x1 == x)){
            X.pop();
            f.pop();
            x1 = f.top().first;
            y1 = f.top().second;
        }
        X.push((double)(y1-y)/(x-x1));
        f.push({x, y});
    }
    for(int i=m-1;i>=0;--i){
        while(!X.empty()&&c[i]<X.top()){
            X.pop();
            f.pop();
        }
        sum += f.top().first*c[i] + f.top().second;
    }
    cout << sum << endl;
}
