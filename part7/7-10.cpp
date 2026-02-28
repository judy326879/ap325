#include <bits/stdc++.h>
#define N 501
using namespace std;
//parent
vector<int> p((N+2)*(N+2));
vector<int> a((N+2)*(N+2));
int narea = 0, maxarea = 0;
int n, m, k;
int di[4] = {1, -1};
int rfind(int u){
    if(p[u]<0) return u;
    return p[u] = rfind(p[u]);
}
void combine(int u, int v){
    int r1 = rfind(u), r2 = rfind(v);
    if(r1 == r2) return ;//同root
    maxarea = max(maxarea, -p[r1]-p[r2]);
    narea--;
    if(p[r1]<p[r2]){
        p[r1] += p[r2];
        p[r2] = r1;
    }
    else{
        p[r2] += p[r1];
        p[r1] = r2;
    }
    return ;
}
int main(){
    cin >> n >> m >> k;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j) p[i*(m+2)+j] = -1;//一維
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j) cin >> a[i*(m+2)+j];
    }
    m+=2;
    di[2] = m, di[3] = -m;
    int mn = m*n + m;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m-2;++j) {
            int v = i*m+j;
            if (a[v] == 1){
                narea++;
                //只要檢查左邊和上面
                if (a[v-1]==1) combine(v,v-1);
                if (a[v-m]==1) combine(v,v-m);
                if (1 > maxarea) maxarea = 1;
                int root = rfind(v);
                if (-p[root] > maxarea) maxarea = -p[root];
            }
        }
    }
    long long totaln = narea, totalm = maxarea;
    while(k--){
        int i, j, v;
        cin >> i >> j;
        v = i*m+j;
        if(a[v] == 1) continue;
        a[v] = 1;
        narea++;
        maxarea = max(maxarea, 1);

        for(i=0;i<4;++i){
            if(a[v+di[i]] == 0) continue;//周圍非水坑
            combine(v, v+di[i]);
        }
        totaln += narea;
        totalm += maxarea;
    }
    cout << totalm << '\n' << totaln;
}
