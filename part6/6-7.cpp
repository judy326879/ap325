#include <bits/stdc++.h>
using namespace std;
int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.size(), n2 = s2.size();
    int lcs[2][505] = {}, to = 1, from = 0;
    for(int i=0;i<n2;++i){
        lcs[to][0] = 0;
        for(int j=1;j<=n1;++j){
            lcs[to][j] = (s2[i]==s1[j-1])?lcs[from][j-1]+1:max(lcs[to][j-1], lcs[from][j]);
        }
        swap(from, to);
    }
    cout << lcs[from][n1];
}
