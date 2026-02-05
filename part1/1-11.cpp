#include <iostream>
#include <climits>
#include <cmath>
using namespace std;
int n, m, a[13][13];
int ans = INT_MAX, Min = INT_MAX;
void count(int a1, int u, int v, int u1, int v1, int ans){//a = 0上1下2左3右
    int c1 = 0, c2 = 0;
    if(u1 == u|| v1 == v){
        Min = min(Min, ans);
        ans = 0;
        return ;
    }
    if(a1 == 0){
        for(int i=v;i<=v1;++i){
            if(a[u][i] == 0) c1++;
            if(a[u][i] == 1) c2++;
        }
        ++u;
    }
    else if(a1 == 1){
        for(int i=v;i<=v1;++i){
            if(a[u1][i] == 0) c1++;
            if(a[u1][i] == 1) c2++;
        }
        --u1;
    }
    else if(a1 == 2){
        for(int i=u;i<=u1;++i){
            if(a[i][v] == 0) c1++;
            if(a[i][v] == 1) c2++;
        }
        ++v;
    }
    else{
        for(int i=u;i<=u1;++i){
            if(a[i][v1] == 0) c1++;
            if(a[i][v1] == 1) c2++;
        }
        --v1;
    }
    ans += min(c1, c2);
    count(0, u, v, u1, v1, ans);
    count(1, u, v, u1, v1, ans);
    count(2, u, v, u1, v1, ans);
    count(3, u, v, u1, v1, ans);
    return ;
}
int main(){
    cin >> n >> m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j) cin >> a[i][j];
    }
    count(0, 0, 0, n-1, m-1, 0);
    count(1, 0, 0, n-1, m-1, 0);
    count(2, 0, 0, n-1, m-1, 0);
    count(3, 0, 0, n-1, m-1, 0);
    cout << Min << endl;
}
