#include <iostream>
#include <vector>
using namespace std;
long long n, m, total = 0;
long long p[100005];
bool enough(long long r){
    long long m1 = m;
    long long r1 = r;
    for(int i=0;i<n;++i){
        if(p[i]>r1){
            if(m1==0||r<p[i]) return false;
            --m1;
            r1 = r;
        }
        r1 -= p[i];
    }
    return true;
}
int main(){
    cin >> n >> m;
    for(int i=0;i<n;++i){
        cin >> p[i];
        total+=p[i];
    }
    long long len = 0;
    for(long long jump=total/2;jump>0;jump/=2){
        while(len+jump<total&&!enough(len+jump)) len+=jump;
    }
    cout << len+1 << endl;
}
