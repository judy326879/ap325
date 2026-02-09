#include <iostream>
#include <deque>
#define N 200010
using namespace std;
long long n, l;
int seq[N], Max = 0;
deque<int> max_q, min_q;
void put_max(int i){
    while(!max_q.empty() && seq[max_q.back()]<=seq[i])
        max_q.pop_back();
    max_q.push_back(i);
}
void put_min(int i){
    while(!min_q.empty() && seq[min_q.back()]>=seq[i])
        min_q.pop_back();
    min_q.push_back(i);
}

int main(){
    cin >> n >> l;
    for(int i=0;i<n;++i) cin >> seq[i];
    put_max(0);
    put_min(0);
    for(int i=1;i<n;++i){
        if(max_q.front()<=i-l)
            max_q.pop_front();
        put_max(i);
        if(min_q.front()<=i-l)
            min_q.pop_front();
        put_min(i);

        int diff = seq[max_q.front()] - seq[min_q.front()];
        Max = max(diff, Max);
    }
    cout << Max << endl;
}
