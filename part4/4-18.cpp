#include <iostream>
#include <queue>
using namespace std;
long long n, m;
long long a[100001];
bool enough(long long r){
    priority_queue<long long> pq;
    for(int i=0;i<n;++i){
        if(pq.size() == r){
            long long a1 = pq.top();
            pq.pop();
            a1 += a[i];
            pq.push(a1);
        }
        else pq.push(a[i]);
    }
    long long a1;
    while(!pq.empty()){
        a1 = pq.top();
        pq.pop();
    }
    if(-a1>m) return false;
    else return true;
}
int main(){
    cin >> n >> m;
    priority_queue<long long> pq;
    for(int i=0;i<n;++i){
        cin >> a[i];
        a[i]*=-1;
    }
    long long t = 0;
    for(long long jump=n/2;jump>0;jump/=2){
        while(t+jump<=n&&!enough(t+jump)) t += jump;
    }
    cout << t+1 << endl;
}
