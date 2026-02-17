#include <bits/stdc++.h>
using namespace std;
int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.size(), n2 = s2.size();
    int lcs[2][505] = {}, to = 1, from = 0;
    int sum = 0;
    for(int i=1;i<=n1;++i){
        for(int j=1;j<=n2;++j){
            if(s1[i-1]==s2[j-1]){
                lcs[to][j] = lcs[from][j-1]+8;
                sum = max(sum, lcs[to][j]);
            }
            else{
                int sk1 = max(0, lcs[to][j-1]-3);//skip
                int sk2 = max(0, lcs[from][j]-3);//skip
                int br = max(0, lcs[from][j-1]-5);
                lcs[to][j] = max(max(sk1, sk2), br);
            }
        }
        swap(from, to);
    }
    cout << sum << endl;
}
