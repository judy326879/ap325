#include <iostream>
#define N 200010
using namespace std;
int a[N], num[N] = {};
int n, L, Max = 0, c = 0;
int main(){
    cin >> n >> L;
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    int l = 0;
    for(int i=0;i<L;++i){
        num[a[i]]++;
        if(num[a[i]]==1) ++c;
        Max = max(c, Max);
    }
    for(int r=L;r<n;++r){
        num[a[l]]--;
        if(num[a[l]] == 0) --c;
        num[a[r]]++;
        if(num[a[r]] == 1) ++c;
        Max = max(c, Max);
        ++l;
    }
    cout << Max << endl;
}
