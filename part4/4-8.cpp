#include <iostream>
#include <queue>
using namespace std;
int main(){
    long long n, m;
    cin >> n >> m;
    priority_queue<long long> pq;
    long long a;
    for(int i=0;i<n;++i){
        cin >> a;
        a*=-1;
        if(pq.size() == m){
            long long k = pq.top();
            pq.pop();
            a += k;
            pq.push(a);
        }
        else pq.push(a);
    }
    long long t;
    while(!pq.empty()){
        t = pq.top();
        pq.pop();
    }
    cout << -t << endl;
}
