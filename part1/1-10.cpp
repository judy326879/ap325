#include<bits/stdc++.h>
using namespace std;
int Max = -1, q[15][15], n;
void nqr(int k, int p[]) {
    if (k>=n){
        int sum = 0;
        for(int i=0;i<n;++i){
            if(p[i] == -1) continue;
            sum+=q[i][p[i]];
        }
        Max = max(Max, sum);
        return ;
    }
    for(int i=0;i<n;i++){
        bool valid = true;
        for(int j=0;j<k;j++){
            if(p[j] == -1) continue;
            if (p[j]==i || abs(i-p[j])==k-j){
                valid=false;
                break;
            }
        }
        if (!valid) continue;
        p[k]=i;
        nqr(k+1,p);
        p[k] = -1;
    }
    p[k] = -1;
    nqr(k+1, p);
}
int main() {
    int p[15];
    for(int i=0;i<15;++i) p[i] = -1;
    cin >> n;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j) cin >> q[i][j];
    }
    nqr(0, p);
    printf("%d", Max);
    return 0;
}
