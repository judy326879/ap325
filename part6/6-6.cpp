#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int n, m;
int Map[201][201] = {};
int main(){
    cin >> n >> m;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j) cin >> Map[i][j];
    int c = 0, v = 0;
    for(int i=1;i<n;++i) Map[i][0] += Map[i-1][0];
    for(int i=1;i<m;++i) Map[0][i] += Map[0][i-1];

    for(int i=1;i<n;++i){
        for(int j=1;j<m;++j) Map[i][j] += max(Map[i-1][j], Map[i][j-1]);
    }
    cout << Map[n-1][m-1] << endl;
}
