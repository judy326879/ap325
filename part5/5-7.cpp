#include <bits/stdc++.h>
#define N 100010
typedef long long LL;
using namespace std;
LL h[N];
LL rect(int s, int t){
    if(s>=t) return 0;
    if(s+1 == t) return h[s];
    int m = (s+t)/2;
    LL Max = max(rect(s, m), rect(m+1, t));
    LL i=m, j=m, height = h[m], largest = 0;//m start
    while(i>=s||j<t){
        if(i<s) height = h[j];
        else if(j>=t) height = h[i];
        else height = max(h[i], h[j]);
        while(i>=s && h[i]>=height) i--;
        while(j<t && h[j]>=height) ++j;
        largest = max(largest, (j-i-1)*height);
    }
    return max(Max, largest);
}
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;++i) cin >> h[i];
    cout << rect(0, n) << endl;
}
