#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long a;
    priority_queue<long long> pq;
    for(int i=0;i<n;++i){
        cin >> a;
        pq.push(-a);
    }
    long long sum = 0;
    while(pq.size()>1){
        long long k = pq.top();
        pq.pop();
        k += pq.top();
        pq.pop();
        sum += k;
        pq.push(k);
    }
    cout << -1*pq.top() << '\n'<< -1*sum << endl;
}
