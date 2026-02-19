#include <bits/stdc++.h>
using namespace std;
int n, k, c[200005], p[200005];//p[]最小累積成本
int minq[200005], front = 0, back = 0;
//minq -> index
int main(){
    cin >> n >> k;
    for(int i=1;i<=n;++i) cin >> c[i];
    p[1] = c[1];
    minq[back++] = 1;//push_back (minq[1])
    for(int i=2;i<=n;++i){
        if(i<=k+1) p[i] = c[i];//前面不到k個 直接push_back
        else{
            //check if out of window
            if(minq[front]<i-2*k-1) front++;
            p[i] = p[minq[front]] + c[i];
        }
        //新進來的p[i]比對列尾小 -> delete
        while(front<back&&p[minq[back-1]]>=p[i]) back--;
        minq[back++] = i;//直接覆蓋
    }
    int ans = p[n-k];
    //for(int i=1;i<=n;++i) cout << p[i] << " ";
    //cout << endl;
    for(int i=n-k+1;i<=n;++i)
        if(p[i]<ans) ans = p[i];
    cout << ans << endl;
}
