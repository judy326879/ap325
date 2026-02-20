#include <bits/stdc++.h>
using namespace std;
//binary search
int search(int s[], int n, int x){
    if(n==0 || s[0]>=x) return 0;
    int po = 0;
    for(int jump=n/2;jump>0;jump/=2)
        while(po+jump<n && s[po+jump]<x)
            po+=jump;
    return po+1;
}
int main(){
    int n, si;
    cin >> n;
    int p[200010], len = 0;
    for(int i=0;i<n;++i){
        cin >> si;
        int r = search(p, len, si);

        p[r] = si;
        if(r==len) len++;
    }
    cout << len << endl;
}
