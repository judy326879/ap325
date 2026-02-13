#include <iostream>
#include <algorithm>
#define N 50010
using namespace std;
int p[N], n, k;
bool enough(int r){
    int nesg = k, endline = -1;
    for(int i=0;i<n;++i){
        if(p[i]<=endline) continue;
        if(nesg == 0) return false;

        nesg--;
        endline = p[i] + r;
    }
    return true;
}
int main(){
    cin >> n >> k;
    for(int i=0;i<n;++i) cin >> p[i];
    sort(p, p+n);
    int len = 0, l = p[n-1] - p[0];
    for(int jump=l/2;jump>0;jump/=2){
        while(len+jump<l&&!enough(len+jump)) len += jump;
    }
    cout << len+1 << endl;
}
